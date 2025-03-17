#ifndef FILELOG_C_H
#define FILELOG_C_H

fix_file_log_factory_t* fix_file_log_factory_create_from_settings(fix_session_settings_t* settings);
fix_file_log_factory_t* fix_file_log_factory_create_from_path(const char* path);
fix_file_log_factory_t* fix_file_log_factory_create_with_backup(const char* path, const char* backup_path);
void fix_file_log_factory_destroy(fix_file_log_factory_t* factory);

// fix_log_t* fix_file_log_factory_create_log(fix_file_log_factory_t* factory);
// fix_log_t* fix_file_log_factory_create_log_for_session(fix_file_log_factory_t* factory, fix_session_id_t* session);
// void fix_file_log_factory_destroy_log(fix_file_log_factory_t* factory, fix_log_t* log);

#endif // FILELOG_C_H