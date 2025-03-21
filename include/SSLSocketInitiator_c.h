#ifndef SSLSOCKETINITIATOR_C_H
#define SSLSOCKETINITIATOR_C_H

fix_ssl_socket_initiator_t* fix_ssl_socket_initiator_create(fix_application_t *app, void *store, fix_session_settings_t *settings, void *log, fix_error_t *error);
void fix_ssl_socket_initiator_destroy(fix_ssl_socket_initiator_t *initiator);
void fix_ssl_socket_initiator_start(fix_ssl_socket_initiator_t *initiator, fix_error_t *error);
void fix_ssl_socket_initiator_block(fix_ssl_socket_initiator_t *initiator, fix_error_t *error);
bool fix_ssl_socket_initiator_poll(fix_ssl_socket_initiator_t *initiator, fix_error_t *error);
void fix_ssl_socket_initiator_stop(fix_ssl_socket_initiator_t *initiator, bool force);
bool fix_ssl_socket_initiator_isLoggedOn(fix_ssl_socket_initiator_t *initiator);
bool fix_ssl_socket_initiator_has(fix_ssl_socket_initiator_t *initiator, fix_session_id_t *session);
bool fix_ssl_socket_initiator_isStopped(fix_ssl_socket_initiator_t *initiator);

//TODO: Add getSession, getSessions, getSessionSettings, setPassword, setCertAndKey, passwordHandleCallback, passwordHandleCB



#endif // SSLSOCKETINITIATOR_C_H