#pragma once

#include <cstdio>
#include <memory>
#include <string>
#include <3ds.h>

using FILEPtr = std::unique_ptr<FILE, decltype(&std::fclose)>;

/// Returns a new string with:
/// - Leading spaces removed.
/// - Line breaks replaced with spaces.
/// - Consecutive spaces removed.
std::string SanitizedString(std::string s);

bool CopyFile(FS_Archive sdmcArchive, const char* dst, const char* src);

/// Copies src (a stdio path) to dst on the SD archive in fixed-size chunks, so large files never
/// have to fit in memory. Returns false and removes dst if anything goes wrong.
bool CopyFileChunked(FS_Archive sdmcArchive, const char* dst, const char* src);

