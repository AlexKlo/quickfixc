#ifndef SOCKETINITIATOR_C_H
#define SOCKETINITIATOR_C_H

fix_socket_initiator_t* fix_socket_initiator_create(fix_application_t *app, void *store, fix_session_settings_t *settings, void *log, fix_error_t *error);
void fix_socket_initiator_destroy(fix_socket_initiator_t *initiator);
void fix_socket_initiator_start(fix_socket_initiator_t *initiator, fix_error_t *error);
void fix_socket_initiator_block(fix_socket_initiator_t *initiator, fix_error_t *error);
bool fix_socket_initiator_poll(fix_socket_initiator_t *initiator, fix_error_t *error);
void fix_socket_initiator_stop(fix_socket_initiator_t *initiator, bool force);
bool fix_socket_initiator_isLoggedOn(fix_socket_initiator_t *initiator);
bool fix_socket_initiator_has(fix_socket_initiator_t *initiator, fix_session_id_t *session);
bool fix_socket_initiator_isStopped(fix_socket_initiator_t *initiator);

//TODO: Add getSession, getSessions, getSessionSettings



#endif // SOCKETINITIATOR_C_H