#ifndef SESSIONID_C_H
#define SESSIONID_C_H

#ifdef __cplusplus
extern "C" {
#endif

fix_session_id_t* fix_session_id_create(
    const char* beginString,
    const char* senderCompID,
    const char* targetCompID,
    const char* sessionQualifier);

void fix_session_id_destroy(fix_session_id_t* session);

const char* fix_session_id_toString(const fix_session_id_t* session);

#ifdef __cplusplus
}
#endif

#endif // SESSIONID_C_H