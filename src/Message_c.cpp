#include "quickfixc.h"

fix_header_t *fix_header_create() {
    return new fix_header_t{new Header()};
}

void fix_header_destroy(fix_header_t *header) {
    delete header->ptr;
    delete header;
}

const char *fix_header_getField_as_string(fix_header_t *header, int tag, fix_error_t *err) {
    try {
        return strdup(header->ptr->getField(tag).c_str());
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr; 
    }
}

void fix_header_setField_by_tag(fix_header_t *header, int tag, const char *value, fix_error_t *err) {
    try {
        header->ptr->setField(tag, value);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

fix_message_t *fix_message_create() {
    return new fix_message_t{new Message()};
}

void fix_message_destroy(fix_message_t *message) {
    delete message->ptr;
    delete message;
}

fix_header_t *fix_message_getHeader(fix_message_t *message) {
    return new fix_header_t{&message->ptr->getHeader()};
}

void fix_message_setField_by_tag(fix_message_t *message, int tag, const char *value, fix_error_t *err) {
    try {
        message->ptr->setField(tag, value);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

const char *fix_message_toString(fix_message_t *message) {
    return strdup(message->ptr->toString().c_str());
}

const char *fix_message_toXML(fix_message_t *message) {
    return strdup(message->ptr->toXML().c_str());
}

bool fix_send_to_target(fix_message_t* message, fix_session_id_t* session_id, fix_error_t* error) {
    try {
        return FIX::Session::sendToTarget(*(message->ptr), *(session_id->ptr));
    } catch (const Exception& e) {
        fix_error_set(error, e);
        return false;
    }
}

fix_group_t* fix_group_create(int field, int delim) {
    return new fix_group_t{new FIX::Group(field, delim)};
}

void fix_group_destroy(fix_group_t* group) {
    delete group->ptr;
    delete group;
}

void fix_message_add_group(fix_message_t *message, fix_group_t *group) {
    message->ptr->addGroup(*group->ptr);
}

void fix_group_setField_by_tag(fix_group_t *group, int tag, const char *value, fix_error_t *err) {
    try {
        group->ptr->setField(tag, value);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}