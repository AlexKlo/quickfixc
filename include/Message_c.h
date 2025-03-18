#ifndef MESSAGE_C_H
#define MESSAGE_C_H

//TODO: expand Header and Message, add Trailer

//Header
fix_header_t *fix_header_create();
void fix_header_destroy(fix_header_t *header);
const char *fix_header_getField_as_string(fix_header_t *header, int tag, fix_error_t *err);
void fix_header_setField_by_tag(fix_header_t *header, int tag, const char *value, fix_error_t *err);

//Message
fix_message_t *fix_message_create();
void fix_message_destroy(fix_message_t *message);
fix_header_t *fix_message_getHeader(fix_message_t *message);
void fix_message_setField_by_tag(fix_message_t *header, int tag, const char *value, fix_error_t *err);
const char *fix_message_toString(fix_message_t *message);
const char *fix_message_toXML(fix_message_t *message);


#endif // MESSAGE_C_H