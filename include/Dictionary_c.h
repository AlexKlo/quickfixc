#ifndef DICTIONARY_C_H
#define DICTIONARY_C_H

fix_dictionary_t* fix_dictionary_create(const char* name);
void fix_dictionary_destroy(fix_dictionary_t* dict);

const char* fix_dictionary_getName(fix_dictionary_t* dict);
size_t fix_dictionary_size(fix_dictionary_t* dict);
bool fix_dictionary_has(fix_dictionary_t* dict, const char* key);

const char* fix_dictionary_getString(fix_dictionary_t* dict, const char* key, bool capitalize, fix_error_t* err);
int fix_dictionary_getInt(fix_dictionary_t* dict, const char* key, fix_error_t* err);
double fix_dictionary_getDouble(fix_dictionary_t* dict, const char* key, fix_error_t* err);
bool fix_dictionary_getBool(fix_dictionary_t* dict, const char* key, fix_error_t* err);
int fix_dictionary_getDay(fix_dictionary_t* dict, const char* key, fix_error_t* err);

void fix_dictionary_setString(fix_dictionary_t* dict, const char* key, const char* value);
void fix_dictionary_setInt(fix_dictionary_t* dict, const char* key, int value);
void fix_dictionary_setDouble(fix_dictionary_t* dict, const char* key, double value);
void fix_dictionary_setBool(fix_dictionary_t* dict, const char* key, bool value);
void fix_dictionary_setDay(fix_dictionary_t* dict, const char* key, int value);

void fix_dictionary_merge(fix_dictionary_t* dest, const fix_dictionary_t* src);

#endif // DICTIONARY_C_H