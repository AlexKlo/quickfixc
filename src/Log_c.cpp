#include "quickfixc.h"

using namespace FIX;

fix_screen_log_factory_t* fix_screen_log_factory_create_with_settings(fix_session_settings_t* settings) {
    return new fix_screen_log_factory_t{ScreenLogFactory(settings->settings)};
}

fix_screen_log_factory_t* fix_screen_log_factory_create(bool incoming, bool outgoing, bool event) {
    return new fix_screen_log_factory_t{ScreenLogFactory(incoming, outgoing, event)};
}

void fix_screen_log_factory_destroy(fix_screen_log_factory_t* factory) {
    delete factory;
}

// fix_log_t* fix_screen_log_factory_create_log(fix_screen_log_factory_t* factory) {
//     if (!factory) return nullptr;
//     return reinterpret_cast<fix_log_t*>(factory->factory.create());
// }

// fix_log_t* fix_screen_log_factory_create_log_for_session(fix_screen_log_factory_t* factory, const fix_session_id_t* session_id) {
//     if (!factory || !session_id) return nullptr;
//     return reinterpret_cast<fix_log_t*>(factory->factory.create(session_id->id));
// }

// void fix_screen_log_factory_destroy_log(fix_screen_log_factory_t* factory, fix_log_t* log) {
//     if (!factory || !log) return;
//     factory->factory.destroy(reinterpret_cast<Log*>(log));
// }
