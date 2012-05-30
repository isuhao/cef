// Copyright (c) 2012 Marshall A. Greenblatt. All rights reserved.
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

#ifndef CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"


///
// Structure used to represent a browser window. When used in the browser
// process the functions of this structure may be called on any thread unless
// otherwise indicated in the comments. When used in the render process the
// functions of this structure may only be called on the main thread.
///
typedef struct _cef_browser_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns the browser host object. This function can only be called in the
  // browser process.
  ///
  struct _cef_browser_host_t* (CEF_CALLBACK *get_host)(
      struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser can navigate backwards.
  ///
  int (CEF_CALLBACK *can_go_back)(struct _cef_browser_t* self);

  ///
  // Navigate backwards.
  ///
  void (CEF_CALLBACK *go_back)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser can navigate forwards.
  ///
  int (CEF_CALLBACK *can_go_forward)(struct _cef_browser_t* self);

  ///
  // Navigate forwards.
  ///
  void (CEF_CALLBACK *go_forward)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser is currently loading.
  ///
  int (CEF_CALLBACK *is_loading)(struct _cef_browser_t* self);

  ///
  // Reload the current page.
  ///
  void (CEF_CALLBACK *reload)(struct _cef_browser_t* self);

  ///
  // Reload the current page ignoring any cached data.
  ///
  void (CEF_CALLBACK *reload_ignore_cache)(struct _cef_browser_t* self);

  ///
  // Stop loading the page.
  ///
  void (CEF_CALLBACK *stop_load)(struct _cef_browser_t* self);

  ///
  // Returns the globally unique identifier for this browser.
  ///
  int (CEF_CALLBACK *get_identifier)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the window is a popup window.
  ///
  int (CEF_CALLBACK *is_popup)(struct _cef_browser_t* self);

  // Returns true (1) if a document has been loaded in the browser.
  int (CEF_CALLBACK *has_document)(struct _cef_browser_t* self);

  ///
  // Returns the main (top-level) frame for the browser window.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_main_frame)(
      struct _cef_browser_t* self);

  ///
  // Returns the focused frame for the browser window.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_focused_frame)(
      struct _cef_browser_t* self);

  ///
  // Returns the frame with the specified identifier, or NULL if not found.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_frame_byident)(
      struct _cef_browser_t* self, int64 identifier);

  ///
  // Returns the frame with the specified name, or NULL if not found.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_frame)(struct _cef_browser_t* self,
      const cef_string_t* name);

  ///
  // Returns the number of frames that currently exist.
  ///
  size_t (CEF_CALLBACK *get_frame_count)(struct _cef_browser_t* self);

  ///
  // Returns the identifiers of all existing frames.
  ///
  void (CEF_CALLBACK *get_frame_identifiers)(struct _cef_browser_t* self,
      size_t* identifiersCount, int64* identifiers);

  ///
  // Returns the names of all existing frames.
  ///
  void (CEF_CALLBACK *get_frame_names)(struct _cef_browser_t* self,
      cef_string_list_t names);

  //
  // Send a message to the specified |target_process|. Returns true (1) if the
  // message was sent successfully.
  ///
  int (CEF_CALLBACK *send_process_message)(struct _cef_browser_t* self,
      enum cef_process_id_t target_process,
      struct _cef_process_message_t* message);
} cef_browser_t;


///
// Structure used to represent the browser process aspects of a browser window.
// The functions of this structure can only be called in the browser process.
///
typedef struct _cef_browser_host_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Returns the hosted browser object.
  ///
  struct _cef_browser_t* (CEF_CALLBACK *get_browser)(
      struct _cef_browser_host_t* self);

  ///
  // Call this function before destroying a contained browser window. This
  // function performs any internal cleanup that may be needed before the
  // browser window is destroyed.
  ///
  void (CEF_CALLBACK *parent_window_will_close)(
      struct _cef_browser_host_t* self);

  ///
  // Closes this browser window.
  ///
  void (CEF_CALLBACK *close_browser)(struct _cef_browser_host_t* self);

  ///
  // Set focus for the browser window. If |enable| is true (1) focus will be set
  // to the window. Otherwise, focus will be removed.
  ///
  void (CEF_CALLBACK *set_focus)(struct _cef_browser_host_t* self, int enable);

  ///
  // Retrieve the window handle for this browser.
  ///
  cef_window_handle_t (CEF_CALLBACK *get_window_handle)(
      struct _cef_browser_host_t* self);

  ///
  // Retrieve the window handle of the browser that opened this browser. Will
  // return NULL for non-popup windows. This function can be used in combination
  // with custom handling of modal windows.
  ///
  cef_window_handle_t (CEF_CALLBACK *get_opener_window_handle)(
      struct _cef_browser_host_t* self);

  ///
  // Returns the client for this browser.
  ///
  struct _cef_client_t* (CEF_CALLBACK *get_client)(
      struct _cef_browser_host_t* self);

  ///
  // Returns the DevTools URL for this browser. If |http_scheme| is true (1) the
  // returned URL will use the http scheme instead of the chrome-devtools
  // scheme. Remote debugging can be enabled by specifying the "remote-
  // debugging-port" command-line flag or by setting the
  // CefSettings.remote_debugging_port value. If remote debugging is not enabled
  // this function will return an NULL string.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t (CEF_CALLBACK *get_dev_tools_url)(
      struct _cef_browser_host_t* self, int http_scheme);
} cef_browser_host_t;


///
// Create a new browser window using the window parameters specified by
// |windowInfo|. All values will be copied internally and the actual window will
// be created on the UI thread. This function can be called on any browser
// process thread and will not block.
///
CEF_EXPORT int cef_browser_host_create_browser(
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const cef_string_t* url, const struct _cef_browser_settings_t* settings);

///
// Create a new browser window using the window parameters specified by
// |windowInfo|. This function can only be called on the browser process UI
// thread.
///
CEF_EXPORT cef_browser_t* cef_browser_host_create_browser_sync(
    const cef_window_info_t* windowInfo, struct _cef_client_t* client,
    const cef_string_t* url, const struct _cef_browser_settings_t* settings);


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_