#include "quickfixc.h"

using namespace FIX;

fix_ssl_socket_initiator_t *fix_ssl_socket_initiator_create(fix_application_t *app, void *store, fix_session_settings_t *settings, void *log, fix_error_t *error) {
    try {
        MessageStoreFactory *storeFactory = nullptr;
        LogFactory *logFactory = nullptr;

        if (store) {
            if (auto *fileStore = reinterpret_cast<fix_file_store_factory_t *>(store)) {
                storeFactory = &fileStore->factory;
            } else if (auto *memoryStore = reinterpret_cast<fix_memory_store_factory_t *>(store)) {
                storeFactory = &memoryStore->factory;
            }
        }

        if (log) {
            if (auto *screenLog = reinterpret_cast<fix_screen_log_factory_t *>(log)) {
                logFactory = &screenLog->factory;
            } else if (auto *fileLog = reinterpret_cast<fix_file_log_factory_t *>(log)) {
                logFactory = &fileLog->factory;
            }
        }

        return new fix_ssl_socket_initiator_t{
            logFactory
                ? new SSLSocketInitiator(*reinterpret_cast<Application *>(app->internal),
                                      *storeFactory,
                                      settings->settings,
                                      *logFactory)
                : new SSLSocketInitiator(*reinterpret_cast<Application *>(app->internal),
                                      *storeFactory,
                                      settings->settings)};
    } catch (const Exception& e) {
        fix_error_set(error, e);
        return nullptr;
    }
}

void fix_ssl_socket_initiator_destroy(fix_ssl_socket_initiator_t *initiator) {
    delete initiator->initiator;
    delete initiator;
}

void fix_ssl_socket_initiator_start(fix_ssl_socket_initiator_t *initiator, fix_error_t *error) {
    try {
        initiator->initiator->start();
    } catch (const Exception& e) {
        fix_error_set(error, e);
    }
}

void fix_ssl_socket_initiator_block(fix_ssl_socket_initiator_t *initiator, fix_error_t *error) {
    try {
        initiator->initiator->block();
    } catch (const Exception& e) {
        fix_error_set(error, e);
    }
}

bool fix_ssl_socket_initiator_poll(fix_ssl_socket_initiator_t *initiator, fix_error_t *error) {
    try {
        return initiator->initiator->poll();
    } catch (const Exception& e) {
        fix_error_set(error, e);
        return false;
    }
}

void fix_ssl_socket_initiator_stop(fix_ssl_socket_initiator_t *initiator, bool force) {
    initiator->initiator->stop(force);
}

bool fix_ssl_socket_initiator_isLoggedOn(fix_ssl_socket_initiator_t *initiator) {
    return initiator->initiator->isLoggedOn();
}

bool fix_ssl_socket_initiator_has(fix_ssl_socket_initiator_t *initiator, fix_session_id_t *session) {
    return initiator->initiator->has(session->id);
}

bool fix_ssl_socket_initiator_isStopped(fix_ssl_socket_initiator_t *initiator) {
    return initiator->initiator->isStopped();
}