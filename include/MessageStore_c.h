#ifndef MESSAGESTORE_C_H
#define MESSAGESTORE_C_H

fix_memory_store_factory_t *fix_memorystore_factory_create();
void fix_memorystore_factory_destroy(fix_memory_store_factory_t *factory);

// fix_message_store_t *fix_memorystore_create(fix_memory_store_factory_t *factory, fix_utc_timestamp_t *timestamp, fix_session_id_t *session);
// void fix_memorystore_destroy(fix_memory_store_factory_t *factory, fix_message_store_t *store);

#endif // MESSAGESTORE_C_H