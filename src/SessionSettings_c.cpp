#include "quickfixc.h"

using namespace FIX;

fix_session_settings_t* fix_session_settings_create() {
    return new fix_session_settings_t{new SessionSettings()};
}

fix_session_settings_t* fix_session_settings_create_from_file(const char* file, fix_error_t* err) {
    try {
        return new fix_session_settings_t{new SessionSettings(file)};
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr;
    }
}

void fix_session_settings_destroy(fix_session_settings_t* settings) {
    delete settings;
}

bool fix_session_settings_has(fix_session_settings_t* settings, const fix_session_id_t* session) {
    return settings->ptr->has(*session->ptr);
}

fix_dictionary_t* fix_session_settings_get(fix_session_settings_t* settings, const fix_session_id_t* session, fix_error_t* err) {
    try {
        fix_dictionary_t* dict = new fix_dictionary_t;
        dict->ptr = new Dictionary(settings->ptr->get(*session->ptr)); 
        return dict;
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr;
    }
}

void fix_session_settings_set(fix_session_settings_t* settings, const fix_session_id_t* session, const fix_dictionary_t* dict, fix_error_t* err) {
    try {
        settings->ptr->set(*session->ptr, *dict->ptr);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

fix_dictionary_t* fix_session_settings_get_defaults(fix_session_settings_t* settings) {
    fix_dictionary_t* dict = new fix_dictionary_t;
    dict->ptr = new Dictionary(settings->ptr->get()); 
    return dict;
}

void fix_session_settings_set_defaults(fix_session_settings_t* settings, const fix_dictionary_t* defaults, fix_error_t* err) {
    try {
        settings->ptr->set(*defaults->ptr);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

size_t fix_session_settings_size(fix_session_settings_t* settings) {
    return settings->ptr->size();
}

fix_session_id_t** fix_session_settings_getSessions(fix_session_settings_t* settings) {
    std::set<SessionID> sessions = settings->ptr->getSessions();
    size_t count = sessions.size();

    if (count == 0) return nullptr;

    fix_session_id_t** sessionArray = new fix_session_id_t*[count];
    size_t i = 0;
    for (const auto& session : sessions) {
        sessionArray[i] = fix_session_id_create(
            session.getBeginString().getString().c_str(),
            session.getSenderCompID().getString().c_str(),
            session.getTargetCompID().getString().c_str(),
            session.getSessionQualifier().c_str()
        );
        i++;
    }
    return sessionArray;
}

void fix_session_settings_freeSessions(fix_session_id_t** sessions, size_t count) {
    if (!sessions) return;
    for (size_t i = 0; i < count; i++) {
        delete sessions[i];
    }
    delete[] sessions;
}
