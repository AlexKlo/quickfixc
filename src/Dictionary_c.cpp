#include "quickfixc.h"

using namespace FIX;

fix_dictionary_t* fix_dictionary_create(const char* name) {
    return new fix_dictionary_t{name ? new Dictionary(name) : new Dictionary()};
}

void fix_dictionary_destroy(fix_dictionary_t* dict) {
    delete dict->ptr;
    delete dict;
}

const char* fix_dictionary_getName(fix_dictionary_t* dict) {
    return strdup(dict->ptr->getName().c_str());
}

size_t fix_dictionary_size(fix_dictionary_t* dict) {
    return dict->ptr->size();
}

bool fix_dictionary_has(fix_dictionary_t* dict, const char* key) {
    return dict->ptr->has(key);
}

const char* fix_dictionary_getString(fix_dictionary_t* dict, const char* key, bool capitalize, fix_error_t* err) {
    try {
        return strdup(dict->ptr->getString(key, capitalize).c_str());
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr;
    }
}

int fix_dictionary_getInt(fix_dictionary_t* dict, const char* key, fix_error_t* err) {
    try {
        return dict->ptr->getInt(key);
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return 0;
    }
}

double fix_dictionary_getDouble(fix_dictionary_t* dict, const char* key, fix_error_t* err) {
    try {
        return dict->ptr->getDouble(key);
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return 0.0;
    }
}

bool fix_dictionary_getBool(fix_dictionary_t* dict, const char* key, fix_error_t* err) {
    try {
        return dict->ptr->getBool(key);
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return false;
    }
}

int fix_dictionary_getDay(fix_dictionary_t* dict, const char* key, fix_error_t* err) {
    try {
        return dict->ptr->getDay(key);
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return 0;
    }
}

void fix_dictionary_setString(fix_dictionary_t* dict, const char* key, const char* value) {
    dict->ptr->setString(key, value);
}

void fix_dictionary_setInt(fix_dictionary_t* dict, const char* key, int value) {
    dict->ptr->setInt(key, value);
}

void fix_dictionary_setDouble(fix_dictionary_t* dict, const char* key, double value) {
    dict->ptr->setDouble(key, value);
}

void fix_dictionary_setBool(fix_dictionary_t* dict, const char* key, bool value) {
    dict->ptr->setBool(key, value);
}

void fix_dictionary_setDay(fix_dictionary_t* dict, const char* key, int value) {
    dict->ptr->setDay(key, value);
}

void fix_dictionary_merge(fix_dictionary_t* dest, const fix_dictionary_t* src) {
    if (!dest || !src) return;
    dest->ptr->merge(*src->ptr);
}
