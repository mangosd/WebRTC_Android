// Copyright (c) 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_BASE_PATHS_FUCHSIA_H_
#define BASE_BASE_PATHS_FUCHSIA_H_

#include "base/base_export.h"
#include "base/files/file_path.h"

namespace base {

// These can be used with the PathService to access various special
// directories and files.
enum {
  PATH_FUCHSIA_START = 1200,

  // Path to the directory which contains application libraries and resources.
  DIR_FUCHSIA_RESOURCES,

  PATH_FUCHSIA_END,
};

// If running inside a package, returns a FilePath of the root path
// of the currently deployed package.
// Otherwise returns an empty FilePath.
BASE_EXPORT base::FilePath GetPackageRoot();

}  // namespace base

#endif  // BASE_BASE_PATHS_FUCHSIA_H_
