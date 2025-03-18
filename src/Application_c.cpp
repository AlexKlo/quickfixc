#include "quickfixc.h"

using namespace FIX;

class FixApplicationWrapper : public FIX::Application {
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

    void onCreate(const FIX::SessionID &sessionID) {
        if (m_callbacks && m_callbacks->on_create) {
            m_callbacks->on_create(m_callbacks->user_data, reinterpret_cast<const fix_session_id_t *>(&sessionID));
        }
    }

    void onLogon(const FIX::SessionID &sessionID) {
        if (m_callbacks && m_callbacks->on_logon) {
            m_callbacks->on_logon(m_callbacks->user_data, reinterpret_cast<const fix_session_id_t *>(&sessionID));
        }
    }

    void onLogout(const FIX::SessionID &sessionID) {
        if (m_callbacks && m_callbacks->on_logout) {
            m_callbacks->on_logout(m_callbacks->user_data, reinterpret_cast<const fix_session_id_t *>(&sessionID));
        }
    }

    void toAdmin(FIX::Message &message, const FIX::SessionID &sessionID) {
        if (m_callbacks && m_callbacks->to_admin) {
            m_callbacks->to_admin(m_callbacks->user_data, reinterpret_cast<fix_message_t *>(&message),
                                  reinterpret_cast<const fix_session_id_t *>(&sessionID));
        }
    }

    void toApp(FIX::Message &message, const FIX::SessionID &sessionID) EXCEPT(DoNotSend) {
        try {
            if (m_callbacks && m_callbacks->to_app) {
                m_callbacks->to_app(m_callbacks->user_data, reinterpret_cast<fix_message_t *>(&message),
                                    reinterpret_cast<const fix_session_id_t *>(&sessionID));
            }
        } catch (const FIX::Exception &e) {
            fix_error_set(&m_error, e);
        }
    }

    void fromAdmin(const FIX::Message &message, const FIX::SessionID &sessionID) 
        EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, RejectLogon) {
        try {
            if (m_callbacks && m_callbacks->from_admin) {
                m_callbacks->from_admin(m_callbacks->user_data, reinterpret_cast<const fix_message_t *>(&message),
                                        reinterpret_cast<const fix_session_id_t *>(&sessionID));
            }
        } catch (const FIX::Exception &e) {
            fix_error_set(&m_error, e);
        }
    }

    void fromApp(const FIX::Message &message, const FIX::SessionID &sessionID) 
        EXCEPT(FieldNotFound, IncorrectDataFormat, IncorrectTagValue, UnsupportedMessageType) {
        try {
            if (m_callbacks && m_callbacks->from_app) {
                m_callbacks->from_app(m_callbacks->user_data, reinterpret_cast<const fix_message_t *>(&message),
                                      reinterpret_cast<const fix_session_id_t *>(&sessionID));
            }
        } catch (const FIX::Exception &e) {
            fix_error_set(&m_error, e);
        }
    }
};

fix_application_t *fix_application_create(fix_application_callbacks_t *callbacks) {
    fix_application_t *app = new fix_application_t;
    app->internal = new FixApplicationWrapper(callbacks);
    return app;
}

void fix_application_destroy(fix_application_t *app) {
    delete reinterpret_cast<FixApplicationWrapper *>(app->internal);
    delete app;
}

const char* fix_application_get_error(fix_application_t *app) {
    auto wrapper = reinterpret_cast<FixApplicationWrapper *>(app->internal);
    return wrapper->getError();
}
