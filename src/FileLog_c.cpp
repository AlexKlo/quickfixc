#include "quickfixc.h"

using namespace FIX;

fix_file_log_factory_t* fix_file_log_factory_create_from_settings(fix_session_settings_t* settings) {
    return new fix_file_log_factory_t{FileLogFactory(settings->settings)};
}

fix_file_log_factory_t* fix_file_log_factory_create_from_path(const char* path) {
    return new fix_file_log_factory_t{FileLogFactory(path)};
}

fix_file_log_factory_t* fix_file_log_factory_create_from_paths(const char* path, const char* backup_path) {
    return new fix_file_log_factory_t{FileLogFactory(path, backup_path)};
}

void fix_file_log_factory_destroy(fix_file_log_factory_t* factory) {
    delete factory;
}

// fix_log_t* fix_file_log_factory_create_log(fix_file_log_factory_t* factory) {
//     return reinterpret_cast<fix_log_t*>(factory->factory.create());
// }

// fix_log_t* fix_file_log_factory_create_log_for_session(fix_file_log_factory_t* factory, fix_session_id_t* session) {
//     return reinterpret_cast<fix_log_t*>(factory->factory.create(session->id));
// }

// void fix_file_log_factory_destroy_log(fix_file_log_factory_t* factory, fix_log_t* log) {
//     factory->factory.destroy(reinterpret_cast<Log*>(log));
// }