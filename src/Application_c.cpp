#include "quickfixc.h"

using namespace FIX;

class FixApplicationWrapper : public Application {
public:
    explicit FixApplicationWrapper(fix_application_callbacks_t *callbacks)
        : m_callbacks(callbacks) {
        fix_error_init(&m_error);
    }

    ~FixApplicationWrapper() {
        fix_error_fini(&m_error);
    }

    const char* getError() const {
        return m_error.message;
    }
private:
    fix_application_callbacks_t *m_callbacks;
    fix_error_t m_error;

    void onCreate(const SessionID &sessionID) {
        if (m_callbacks && m_callbacks->on_create) {
            fix_session_id_t session_wrapper;
            session_wrapper.ptr = const_cast<SessionID *>(&sessionID);
            m_callbacks->on_create(m_callbacks->user_data, &session_wrapper);
        }
    }

    void onLogon(const SessionID &sessionID) {
        if (m_callbacks && m_callbacks->on_logon) {
            fix_session_id_t session_wrapper;
            session_wrapper.ptr = const_cast<SessionID *>(&sessionID);
            m_callbacks->on_logon(m_callbacks->user_data, &session_wrapper);
        }
    }

    void onLogout(const SessionID &sessionID) {
        if (m_callbacks && m_callbacks->on_logout) {
            fix_session_id_t session_wrapper;
            session_wrapper.ptr = const_cast<SessionID *>(&sessionID);
            m_callbacks->on_logout(m_callbacks->user_data, &session_wrapper);
        }
    }

    void toAdmin(Message &message, const SessionID &sessionID) {
        if (m_callbacks && m_callbacks->to_admin) {
            fix_message_t message_wrapper{&message};
            fix_session_id_t session_wrapper{const_cast<SessionID *>(&sessionID)};
            m_callbacks->to_admin(m_callbacks->user_data, &message_wrapper, &session_wrapper);
        }
    }

    void toApp(Message &message, const SessionID &sessionID) EXCEPT(DoNotSend) {
        try {
            if (m_callbacks && m_callbacks->to_app) {
                fix_message_t message_wrapper{&message};
                fix_session_id_t session_wrapper{const_cast<SessionID *>(&sessionID)};
                m_callbacks->to_app(m_callbacks->user_data, &message_wrapper, &session_wrapper);
            }
        } catch (const Exception &e) {
            fix_error_set(&m_error, e);
        }
    }

    void fromAdmin(const Message &message, const SessionID &sessionID) 
        EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, RejectLogon) {
        try {
            if (m_callbacks && m_callbacks->from_admin) {
                fix_message_t message_wrapper{const_cast<Message *>(&message)};
                fix_session_id_t session_wrapper{const_cast<SessionID *>(&sessionID)};
                m_callbacks->from_admin(m_callbacks->user_data, &message_wrapper, &session_wrapper);
            }
        } catch (const Exception &e) {
            fix_error_set(&m_error, e);
        }
    }

    void fromApp(const Message &message, const SessionID &sessionID) 
        EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, UnsupportedMessageType) {
        try {
            if (m_callbacks && m_callbacks->from_app) {
                fix_message_t message_wrapper{const_cast<Message *>(&message)};
                fix_session_id_t session_wrapper{const_cast<SessionID *>(&sessionID)};
                m_callbacks->from_app(m_callbacks->user_data, &message_wrapper, &session_wrapper);
            }
        } catch (const Exception &e) {
            fix_error_set(&m_error, e);
        }
    }
};

fix_application_t *fix_application_create(fix_application_callbacks_t *callbacks) {
    fix_application_t *app = new fix_application_t;
    app->ptr = new FixApplicationWrapper(callbacks);
    return app;
}

void fix_application_destroy(fix_application_t *app) {
    delete reinterpret_cast<FixApplicationWrapper *>(app->ptr);
    delete app;
}

const char* fix_application_get_error(fix_application_t *app) {
    auto wrapper = reinterpret_cast<FixApplicationWrapper *>(app->ptr);
    return wrapper->getError();
}
