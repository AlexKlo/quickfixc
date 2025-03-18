#include "quickfixc.h"

fix_memory_store_factory_t *fix_memorystore_factory_create() {
    return new fix_memory_store_factory_t{MemoryStoreFactory()};
}

void fix_memorystore_factory_destroy(fix_memory_store_factory_t *factory) {
    if (factory) {
        delete factory;
    }
}

// fix_message_store_t *fix_memorystore_create(fix_memory_store_factory_t *factory, fix_utc_timestamp_t *timestamp, fix_session_id_t *session) {
//     if (!factory || !session) return nullptr;
//     return new fix_message_store_t{factory->factory->create(timestamp->timestamp, session->id)};
// }

// void fix_memorystore_destroy(fix_memory_store_factory_t *factory, fix_message_store_t *store) {
//     if (factory && store) {
//         factory->factory->destroy(store->store);
//         delete store;
//     }
// }