#include "quickfixc.h"

using namespace FIX;

fix_file_log_factory_t* fix_file_log_factory_create_from_settings(fix_session_settings_t* settings) {
    return new fix_file_log_factory_t{new FileLogFactory(*settings->ptr)};
}

fix_file_log_factory_t* fix_file_log_factory_create_from_path(const char* path) {
    return new fix_file_log_factory_t{new FileLogFactory(path)};
}

fix_file_log_factory_t* fix_file_log_factory_create_from_paths(const char* path, const char* backup_path) {
    return new fix_file_log_factory_t{new FileLogFactory(path, backup_path)};
}

void fix_file_log_factory_destroy(fix_file_log_factory_t* factory) {
    delete factory->ptr;
    delete factory;
}