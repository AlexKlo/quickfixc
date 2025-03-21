#include "quickfixc.h"

using namespace FIX;

fix_session_id_t* fix_session_id_create(
    const char* beginString,
    const char* senderCompID,
    const char* targetCompID,
    const char* sessionQualifier) {
    
    fix_session_id_t *session_id = new fix_session_id_t;
    session_id->ptr = new SessionID(
        beginString,
        senderCompID,
        targetCompID,
        sessionQualifier ? sessionQualifier : ""
    );

    return session_id;
}

void fix_session_id_destroy(fix_session_id_t* session) {
    delete session->ptr;
    delete session;
}

const char* fix_session_id_toString(const fix_session_id_t* session) {
    return strdup(session->ptr->toString().c_str());
}