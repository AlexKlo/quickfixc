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

#endif // TYPES_H