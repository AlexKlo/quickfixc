#include "quickfixc.h"

fix_file_store_factory_t *fix_filestore_factory_create_from_settings(fix_session_settings_t *settings) {
    return new fix_file_store_factory_t{FileStoreFactory(settings->settings)};
}

fix_file_store_factory_t *fix_filestore_factory_create_from_path(const char *path) {
    return new fix_file_store_factory_t{FileStoreFactory(std::string(path))};
}

void fix_filestore_factory_destroy(fix_file_store_factory_t *factory) {
    if (factory) {
        delete factory;
    }
}

// fix_message_store_t *fix_filestore_create(fix_file_store_factory_t *factory, fix_utc_timestamp_t *timestamp, fix_session_id_t *session) {
//     if (!factory || !session) return nullptr;
//     return new fix_message_store_t{factory->factory->create(timestamp->timestamp, session->id)};
// }

// void fix_filestore_destroy(fix_file_store_factory_t *factory, fix_message_store_t *store) {
//     if (factory && store) {
//         factory->factory->destroy(store->store);
//         delete store;
//     }
// }