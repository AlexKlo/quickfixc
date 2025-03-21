#ifndef FIELDBASE_C_H
#define FIELDBASE_C_H

fix_field_base_t *fix_field_create(int tag, const char *string);
void fix_field_destroy(fix_field_base_t *field);

void fix_field_set_tag(fix_field_base_t *field, int tag);
void fix_field_set_string(fix_field_base_t *field, const char *string);
const char *fix_field_get_string(fix_field_base_t *field);
const char *fix_field_get_fix_string(fix_field_base_t *field);

#endif // FIELDBASE_C_H