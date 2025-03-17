#ifndef LOG_C_H
#define LOG_C_H

fix_screen_log_factory_t* fix_screen_log_factory_create_with_settings(fix_session_settings_t* settings);
fix_screen_log_factory_t* fix_screen_log_factory_create(bool incoming, bool outgoing, bool event);
void fix_screen_log_factory_destroy(fix_screen_log_factory_t* factory);

// fix_log_t* fix_screen_log_factory_create_log(fix_screen_log_factory_t* factory);
// fix_log_t* fix_screen_log_factory_create_log_for_session(fix_screen_log_factory_t* factory, fix_session_id_t* session_id);
// void fix_screen_log_factory_destroy_log(fix_screen_log_factory_t* factory, fix_log_t* log);

#endif // LOG_C_H
