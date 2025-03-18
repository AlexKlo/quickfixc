#ifndef APPLICATION_C_H
#define APPLICATION_C_H

// Callbacks
typedef void (*fix_on_create_t)(void *user_data, const fix_session_id_t *);
typedef void (*fix_on_logon_t)(void *user_data, const fix_session_id_t *);
typedef void (*fix_on_logout_t)(void *user_data, const fix_session_id_t *);
typedef void (*fix_to_admin_t)(void *user_data, fix_message_t *, const fix_session_id_t *);
typedef void (*fix_to_app_t)(void *user_data, fix_message_t *, const fix_session_id_t *);
typedef void (*fix_from_admin_t)(void *user_data, const fix_message_t *, const fix_session_id_t *);
typedef void (*fix_from_app_t)(void *user_data, const fix_message_t *, const fix_session_id_t *);

typedef struct {
    fix_on_create_t on_create;
    fix_on_logon_t on_logon;
    fix_on_logout_t on_logout;
    fix_to_admin_t to_admin;
    fix_to_app_t to_app;
    fix_from_admin_t from_admin;
    fix_from_app_t from_app;
    void *user_data;
} fix_application_callbacks_t;

fix_application_t *fix_application_create(fix_application_callbacks_t *callbacks);
void fix_application_destroy(fix_application_t *app);
const char* fix_application_get_error(fix_application_t *app);

#endif // APPLICATION_C_H