#ifndef TYPES_H
#define TYPES_H

//TODO: В структурах должны храниться указатели

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
    ScreenLogFactory factory;
} fix_screen_log_factory_t;

typedef struct fix_file_log_factory_t {
    FileLogFactory factory;
} fix_file_log_factory_t;

typedef struct fix_file_store_factory_t {
    FileStoreFactory factory;
} fix_file_store_factory_t;

typedef struct fix_memory_store_factory_t {
    MemoryStoreFactory factory;
} fix_memory_store_factory_t;

typedef struct fix_application_t {
    void *internal;
} fix_application_t;

typedef struct fix_field_base_t {
    FieldBase *field_base;
} fix_field_base_t;

typedef struct fix_message_t {
    Message message;
} fix_message_t;

typedef struct fix_header_t {
    Header header;
} fix_header_t;

typedef struct fix_socket_initiator_t {
    SocketInitiator *initiator;
} fix_socket_initiator_t;

typedef struct fix_ssl_socket_initiator_t {
    SSLSocketInitiator *initiator;
} fix_ssl_socket_initiator_t;

#endif // TYPES_H