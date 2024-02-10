#!/bin/bash

compile() {
  # If building manually just replace SHA with your own text.
  APP_NAME=$(basename "$PWD")
  BANNERTOOLAPP=bannertool
  IS_GH_ACTIONS=true
  if [ -n "$GITHUB_SHA" ]; then
    echo "Building on Github Actions..."
  else
    echo "GITHUB_SHA is empty, building locally."
    IS_GH_ACTIONS=false
    GITHUB_SHA=$(echo $(git rev-parse --short HEAD))
  fi
  if ! command -v bannertoolexec &> /dev/null; then
      if ! command -v bannertool &> /dev/null; then
        echo "Bannertool not found in PATH. Please ensure it is in your path before continuing."
        exit 1
      fi
      echo "Bannertoolexec not found, using bannertool..."
      BANNERTOOLAPP=bannertool
  else
    echo "Bannertool not found, using bannertoolexec..."
    BANNERTOOLAPP=bannertoolexec
  fi

  if ! command -v 3dstool &> /dev/null; then
    echo "3dstool not found in PATH. Please ensure it is in your path before continuing."
    exit 1
  fi

  if ! command -v makerom &> /dev/null; then
    echo "makerom not found in PATH. Please ensure it is in your path before continuing."
    exit 1
  fi

  export commitHashShort=$(echo ${GITHUB_SHA::6})
  sed -i "s/develop/${commitHashShort:-develop}/" ./source/include/version.hpp
  make -j debug_app=1
  sed -i "s/${commitHashShort}/develop/" ./source/include/version.hpp
  $BANNERTOOLAPP makebanner -i ./banner.png -a ./audio.wav -o ./banner.bnr
  $BANNERTOOLAPP makesmdh -s "Majora's Mask 3D Randomizer" -l "A Randomized Majoras Mask Experience" -p "Z3DR Team" -i icon.png -o ./icon.icn
  3dstool -cvtf romfs ./romfs.bin --romfs-dir ./romfs
  makerom -f cia -o ${APP_NAME}.cia -DAPP_ENCRYPTED=false -target t -exefslogo -elf ./${APP_NAME}.elf -icon ./icon.icn -banner ./banner.bnr -rsf ./mmrando.rsf -romfs ./romfs.bin -major 1 -minor 0 -micro 0
  if $IS_GH_ACTIONS; then
    if [ -n "$url_tag" ]; then
      qrencode -ocia.png https://github.com/$GITHUB_REPOSITORY/releases/download/$url_tag/${APP_NAME}.cia
      qrencode -o3dsx.png https://github.com/$GITHUB_REPOSITORY/releases/download/$url_tag/${APP_NAME}.3dsx
    else
      qrencode -ocia.png https://github.com/$GITHUB_REPOSITORY/releases/download/Nightly-$commitHashShort/${APP_NAME}.cia
      qrencode -o3dsx.png https://github.com/$GITHUB_REPOSITORY/releases/download/Nightly-$commitHashShort/${APP_NAME}.3dsx
    fi
  fi
}

clean_up() {
  rm -rf bannertool* makerom* 3dstool* icon.icn ext_key.txt ignore_3dstool.txt banner.bnr romfs.bin
}

compile
clean_up