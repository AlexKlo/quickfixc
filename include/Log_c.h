#ifndef LOG_C_H
#define LOG_C_H

fix_screen_log_factory_t* fix_screen_log_factory_create_with_settings(fix_session_settings_t* settings);
fix_screen_log_factory_t* fix_screen_log_factory_create(bool incoming, bool outgoing, bool event);
void fix_screen_log_factory_destroy(fix_screen_log_factory_t* factory);

#endif // LOG_C_H
