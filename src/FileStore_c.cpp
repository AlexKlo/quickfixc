#include "quickfixc.h"

fix_file_store_factory_t *fix_filestore_factory_create_from_settings(fix_session_settings_t *settings) {
    return new fix_file_store_factory_t{new FileStoreFactory(*settings->ptr)};
}

fix_file_store_factory_t *fix_filestore_factory_create_from_path(const char *path) {
    return new fix_file_store_factory_t{new FileStoreFactory(std::string(path))};
}

void fix_filestore_factory_destroy(fix_file_store_factory_t *factory) {
    delete factory->ptr;
    delete factory;
}