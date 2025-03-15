#ifndef SESSIONSETTINGS_C_H
#define SESSIONSETTINGS_C_H

fix_session_settings_t* fix_session_settings_create();
fix_session_settings_t* fix_session_settings_create_from_file(const char* file, fix_error_t* err);
void fix_session_settings_destroy(fix_session_settings_t* settings);

bool fix_session_settings_has(fix_session_settings_t* settings, const fix_session_id_t* session);
fix_dictionary_t* fix_session_settings_get(fix_session_settings_t* settings, const fix_session_id_t* session, fix_error_t* err);
void fix_session_settings_set(fix_session_settings_t* settings, const fix_session_id_t* session, const fix_dictionary_t* dict, fix_error_t* err);

fix_dictionary_t* fix_session_settings_get_defaults(fix_session_settings_t* settings);
void fix_session_settings_set_defaults(fix_session_settings_t* settings, const fix_dictionary_t* defaults, fix_error_t* err);

size_t fix_session_settings_size(fix_session_settings_t* settings);

fix_session_id_t** fix_session_settings_getSessions(fix_session_settings_t* settings);
void fix_session_settings_freeSessions(fix_session_id_t** sessions, size_t count);

#endif // SESSIONSETTINGS_C_H