#include "quickfixc.h"

fix_memory_store_factory_t *fix_memorystore_factory_create() {
    return new fix_memory_store_factory_t{new MemoryStoreFactory()};
}

void fix_memorystore_factory_destroy(fix_memory_store_factory_t *factory) {
    delete factory->ptr;
    delete factory;
}