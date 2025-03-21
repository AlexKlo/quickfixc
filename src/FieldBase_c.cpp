#include "quickfixc.h"

fix_field_base_t *fix_field_create(int tag, const char *string) {
    return new fix_field_base_t{new FieldBase(tag, string)};
}

void fix_field_destroy(fix_field_base_t *field) {
    delete field->ptr;
    delete field;
}

void fix_field_set_tag(fix_field_base_t *field, int tag) {
    field->ptr->setTag(tag);
}

void fix_field_set_string(fix_field_base_t *field, const char *string) {
    field->ptr->setString(string);
}

const char *fix_field_get_string(fix_field_base_t *field) {
    return field->ptr->getString().c_str();
}

const char *fix_field_get_fix_string(fix_field_base_t *field) {
    return field->ptr->getFixString().c_str();
}
