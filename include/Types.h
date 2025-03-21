#ifndef TYPES_H
#define TYPES_H

//TODO: В структурах должны храниться указатели

typedef struct fix_error_t {
    char* message;
} fix_error_t;

typedef struct fix_dictionary_t {
    Dictionary *ptr;
} fix_dictionary_t;

typedef struct fix_session_id_t {
    SessionID *ptr;
} fix_session_id_t;

typedef struct fix_session_settings_t {
    SessionSettings *ptr;
} fix_session_settings_t;

typedef struct fix_screen_log_factory_t {
    ScreenLogFactory *ptr;
} fix_screen_log_factory_t;

typedef struct fix_file_log_factory_t {
    FileLogFactory *ptr;
} fix_file_log_factory_t;

typedef struct fix_file_store_factory_t {
    FileStoreFactory *ptr;
} fix_file_store_factory_t;

typedef struct fix_memory_store_factory_t {
    MemoryStoreFactory *ptr;
} fix_memory_store_factory_t;

typedef struct fix_application_t {
    void *ptr;
} fix_application_t;

typedef struct fix_field_base_t {
    FieldBase *ptr;
} fix_field_base_t;

typedef struct fix_message_t {
    Message *ptr;
} fix_message_t;

typedef struct fix_header_t {
    Header *ptr;
} fix_header_t;

typedef struct fix_group_t {
    Group *ptr;
} fix_group_t;

typedef struct fix_socket_initiator_t {
    SocketInitiator *ptr;
} fix_socket_initiator_t;

typedef struct fix_ssl_socket_initiator_t {
    SSLSocketInitiator *ptr;
} fix_ssl_socket_initiator_t;

#endif // TYPES_H