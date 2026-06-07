#!/bin/bash
set -e
compile() {
  # If building manually just replace SHA with your own text.
  APP_NAME=$(basename "$PWD")
  BANNERTOOLAPP=bannertool
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

  make -j
  $BANNERTOOLAPP makebanner -i ./banner.png -a ./audio.wav -o ./banner.bnr
  $BANNERTOOLAPP makesmdh -s "Majora's Mask 3D Randomizer" -l "A Randomized Majoras Mask Experience" -p "Z3DR Team" -i icon.png -o ./icon.icn
  3dstool -cvtf romfs ./romfs.bin --romfs-dir ./romfs
  makerom -f cia -o ${APP_NAME}.cia -DAPP_ENCRYPTED=false -target t -exefslogo -elf ./${APP_NAME}.elf -icon ./icon.icn -banner ./banner.bnr -rsf ./mmrando.rsf -romfs ./romfs.bin -major 1 -minor 0 -micro 0
}

clean_up() {
  rm -rf bannertool* makerom* 3dstool* icon.icn ext_key.txt ignore_3dstool.txt banner.bnr romfs.bin
}

compile
clean_up