#include "quickfixc.h"

fix_header_t *fix_header_create() {
    return new fix_header_t{Header()};
}

void fix_header_destroy(fix_header_t *header) {
    if (header) {
        delete header;
    }
}

const char *fix_header_getField_as_string(fix_header_t *header, int tag, fix_error_t *err) {
    try {
        return strdup(header->header.getField(tag).c_str());
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr; 
    }
}

void fix_header_setField_by_tag(fix_header_t *header, int tag, const char *value, fix_error_t *err) {
    try {
        header->header.setField(tag, value);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

fix_message_t *fix_message_create() {
    return new fix_message_t{Message()};
}

void fix_message_destroy(fix_message_t *message) {
    if (message) {
        delete message;
    }
}

fix_header_t *fix_message_getHeader(fix_message_t *message) {
    return new fix_header_t{message->message.getHeader()};
}

void fix_message_setField_by_tag(fix_message_t *message, int tag, const char *value, fix_error_t *err) {
    try {
        message->message.setField(tag, value);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

const char *fix_message_toString(fix_message_t *message) {
    return strdup(message->message.toString().c_str());
}

const char *fix_message_toXML(fix_message_t *message) {
    return strdup(message->message.toXML().c_str());
}