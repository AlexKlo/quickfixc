#ifndef FILESTORE_C_H
#define FILESTORE_C_H

fix_file_store_factory_t *fix_filestore_factory_create_from_settings(fix_session_settings_t *settings);
fix_file_store_factory_t *fix_filestore_factory_create_from_path(const char *path);
void fix_filestore_factory_destroy(fix_file_store_factory_t *factory);

// fix_message_store_t *fix_filestore_create(fix_file_store_factory_t *factory, fix_utc_timestamp_t *timestamp, fix_session_id_t *session);
// void fix_filestore_destroy(fix_file_store_factory_t *factory, fix_message_store_t *store);

#endif // FILESTORE_C_H