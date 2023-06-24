// Copyright (c) 2020 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=c930140791b9e7d4238110e24fe17b9566a34ec9$
//

#ifndef CEF_INCLUDE_CAPI_CEF_FILE_UTIL_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_FILE_UTIL_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Creates a directory and all parent directories if they don't already exist.
// Returns true (1) on successful creation or if the directory already exists.
// The directory is only readable by the current user. Calling this function on
// the browser process UI or IO threads is not allowed.
///
CEF_EXPORT int cef_create_directory(const cef_string_t* full_path);

///
// Get the temporary directory provided by the system.
//
// WARNING: In general, you should use the temp directory variants below instead
// of this function. Those variants will ensure that the proper permissions are
// set so that other users on the system can't edit them while they're open
// (which could lead to security issues).
///
CEF_EXPORT int cef_get_temp_directory(cef_string_t* temp_dir);

///
// Creates a new directory. On Windows if |prefix| is provided the new directory
// name is in the format of "prefixyyyy". Returns true (1) on success and sets
// |new_temp_path| to the full path of the directory that was created. The
// directory is only readable by the current user. Calling this function on the
// browser process UI or IO threads is not allowed.
///
CEF_EXPORT int cef_create_new_temp_directory(const cef_string_t* prefix,
                                             cef_string_t* new_temp_path);

///
// Creates a directory within another directory. Extra characters will be
// appended to |prefix| to ensure that the new directory does not have the same
// name as an existing directory. Returns true (1) on success and sets |new_dir|
// to the full path of the directory that was created. The directory is only
// readable by the current user. Calling this function on the browser process UI
// or IO threads is not allowed.
///
CEF_EXPORT int cef_create_temp_directory_in_directory(
    const cef_string_t* base_dir,
    const cef_string_t* prefix,
    cef_string_t* new_dir);

///
// Returns true (1) if the given path exists and is a directory. Calling this
// function on the browser process UI or IO threads is not allowed.
///
CEF_EXPORT int cef_directory_exists(const cef_string_t* path);

///
// Deletes the given path whether it's a file or a directory. If |path| is a
// directory all contents will be deleted.  If |recursive| is true (1) any sub-
// directories and their contents will also be deleted (equivalent to executing
// "rm -rf", so use with caution). On POSIX environments if |path| is a symbolic
// link then only the symlink will be deleted. Returns true (1) on successful
// deletion or if |path| does not exist. Calling this function on the browser
// process UI or IO threads is not allowed.
///
CEF_EXPORT int cef_delete_file(const cef_string_t* path, int recursive);

///
// Writes the contents of |src_dir| into a zip archive at |dest_file|. If
// |include_hidden_files| is true (1) files starting with "." will be included.
// Returns true (1) on success.  Calling this function on the browser process UI
// or IO threads is not allowed.
///
CEF_EXPORT int cef_zip_directory(const cef_string_t* src_dir,
                                 const cef_string_t* dest_file,
                                 int include_hidden_files);

///
// Loads the existing "Certificate Revocation Lists" file that is managed by
// Google Chrome. This file can generally be found in Chrome's User Data
// directory (e.g. "C:\Users\[User]\AppData\Local\Google\Chrome\User Data\" on
// Windows) and is updated periodically by Chrome's component updater service.
// Must be called in the browser process after the context has been initialized.
// See https://dev.chromium.org/Home/chromium-security/crlsets for background.
///
CEF_EXPORT void cef_load_crlsets_file(const cef_string_t* path);

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_FILE_UTIL_CAPI_H_
