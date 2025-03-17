#ifndef TYPES_H
#define TYPES_H

typedef struct fix_error_t {
    char* message;
} fix_error_t;

typedef struct fix_dictionary_t {
    Dictionary dict;
} fix_dictionary_t;

struct fix_session_id_t {
    SessionID id;

    fix_session_id_t(
        const std::string& beginString, 
        const std::string& senderCompID, 
        const std::string& targetCompID, 
        const std::string& sessionQualifier
    ) : id(beginString, senderCompID, targetCompID, sessionQualifier) {}
};

typedef struct fix_session_settings_t {
    SessionSettings settings;
} fix_session_settings_t;

typedef struct fix_screen_log_factory_t {
    FIX::ScreenLogFactory factory;
} fix_screen_log_factory_t;

// typedef struct fix_log_t fix_log_t;

typedef struct fix_file_log_factory_t {
    FIX::FileLogFactory factory;
} fix_file_log_factory_t;

typedef struct fix_file_store_factory_t {
    FIX::FileStoreFactory *factory;
} fix_file_store_factory_t;

// typedef struct fix_message_store_t {
//     FIX::MessageStore *store;
// } fix_message_store_t;

typedef struct fix_memory_store_factory_t {
    FIX::MemoryStoreFactory *factory;
} fix_memory_store_factory_t;

#endif // TYPES_H