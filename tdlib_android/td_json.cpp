//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2020
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include <td/telegram/td_json_client.h>

#define EXPORT __attribute__ ((visibility ("default")))

// int 	td_create_client_id ()
 
// void 	td_send(int client_id, const char *request)
 
// const char * 	td_receive (double timeout)
 
// const char * 	td_execute (const char *request)
 
// void 	td_set_log_message_callback (int max_verbosity_level, td_log_message_callback_ptr callback)
 
// void * 	td_json_client_create ()
 
// void 	td_json_client_send (void *client, const char *request)
 
// const char * 	td_json_client_receive (void *client, double timeout)
 
// const char * 	td_json_client_execute (void *client, const char *request)
 
// void 	td_json_client_destroy (void *client)

extern "C" {

  EXPORT int _td_create_client_id() {
    
    return td_create_client_id(); 
  }

  EXPORT const char* _td_receive(double timeout) {
    return td_receive(timeout);
  }
  EXPORT void* _td_json_client_create() {
    return td_json_client_create();
  }

  EXPORT void _td_send(int client_id, const char* request) {
    return td_send(client_id, request);
  }
  EXPORT void _td_json_client_send(void* client, const char* request) {
    return td_json_client_send(client, request);
  }

  EXPORT const char* _td_json_client_receive(void* client, double timeout) {
    return td_json_client_receive(client, timeout);
  }

  EXPORT const char* _td_execute(const char* request) {
    return td_execute(request);
  }
  EXPORT const char* _td_json_client_execute(void* client, const char* request) {
    return td_json_client_execute(client, request);
  }

  EXPORT void _td_json_client_destroy(void* client) {
    return td_json_client_destroy(client);
  }

}