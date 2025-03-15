#include "quickfixc.h"

using namespace FIX;

fix_session_settings_t* fix_session_settings_create() {
    return new fix_session_settings_t();
}

fix_session_settings_t* fix_session_settings_create_from_file(const char* file, fix_error_t* err) {
    try {
        return new fix_session_settings_t{SessionSettings(file)};
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr;
    }
}

void fix_session_settings_destroy(fix_session_settings_t* settings) {
    delete settings;
}

bool fix_session_settings_has(fix_session_settings_t* settings, const fix_session_id_t* session) {
    return settings->settings.has(session->id);
}

fix_dictionary_t* fix_session_settings_get(fix_session_settings_t* settings, const fix_session_id_t* session, fix_error_t* err) {
    try {
        return new fix_dictionary_t{settings->settings.get(session->id)};
    } catch (const Exception& e) {
        fix_error_set(err, e);
        return nullptr;
    }
}

void fix_session_settings_set(fix_session_settings_t* settings, const fix_session_id_t* session, const fix_dictionary_t* dict, fix_error_t* err) {
    try {
        settings->settings.set(session->id, dict->dict);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

fix_dictionary_t* fix_session_settings_get_defaults(fix_session_settings_t* settings) {
    return new fix_dictionary_t{settings->settings.get()};
}

void fix_session_settings_set_defaults(fix_session_settings_t* settings, const fix_dictionary_t* defaults, fix_error_t* err) {
    try {
        settings->settings.set(defaults->dict);
    } catch (const Exception& e) {
        fix_error_set(err, e);
    }
}

size_t fix_session_settings_size(fix_session_settings_t* settings) {
    return settings->settings.size();
}

fix_session_id_t** fix_session_settings_getSessions(fix_session_settings_t* settings) {
    std::set<SessionID> sessions = settings->settings.getSessions();
    size_t count = sessions.size();

    if (count == 0) return nullptr;

    fix_session_id_t** sessionArray = new fix_session_id_t*[count];
    size_t i = 0;
    for (const auto& session : sessions) {
        sessionArray[i] = new fix_session_id_t{
            session.getBeginString().getString(),
            session.getSenderCompID().getString(),
            session.getTargetCompID().getString(),
            session.getSessionQualifier()
        };
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