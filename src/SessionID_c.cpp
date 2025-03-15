#include "quickfixc.h"

using namespace FIX;

fix_session_id_t* fix_session_id_create(
    const char* beginString,
    const char* senderCompID,
    const char* targetCompID,
    const char* sessionQualifier) {
    return new fix_session_id_t(
        beginString, 
        senderCompID, 
        targetCompID, 
        sessionQualifier ? sessionQualifier : ""
    );
}

void fix_session_id_destroy(fix_session_id_t* session) {
    delete session;
}

const char* fix_session_id_toString(const fix_session_id_t* session) {
    return strdup(session->id.toString().c_str());
}