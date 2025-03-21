#ifndef FILESTORE_C_H
#define FILESTORE_C_H

fix_file_store_factory_t *fix_filestore_factory_create_from_settings(fix_session_settings_t *settings);
fix_file_store_factory_t *fix_filestore_factory_create_from_path(const char *path);
void fix_filestore_factory_destroy(fix_file_store_factory_t *factory);

#endif // FILESTORE_C_H