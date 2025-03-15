#include "quickfixc.h"

void fix_error_init(fix_error_t* err) {
    if (err) {
        err->message = (char*)malloc(256);
        if (err->message) {
            err->message[0] = '\0';
        }
    }
}

void fix_error_fini(fix_error_t* err) {
    if (err && err->message) {
        free(err->message);
        err->message = NULL;
    }
}

void fix_error_set(fix_error_t* err, const Exception& e) {
    if (err) {
        free(err->message);
        size_t len = std::strlen(e.what()) + 1;
        err->message = (char*)malloc(len);
        if (err->message) {
            std::memcpy(err->message, e.what(), len);
        }
    }
}