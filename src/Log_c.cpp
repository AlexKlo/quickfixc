#include "quickfixc.h"

using namespace FIX;

fix_screen_log_factory_t* fix_screen_log_factory_create_with_settings(fix_session_settings_t* settings) {
    return new fix_screen_log_factory_t{new ScreenLogFactory(*settings->ptr)};
}

fix_screen_log_factory_t* fix_screen_log_factory_create(bool incoming, bool outgoing, bool event) {
    return new fix_screen_log_factory_t{new ScreenLogFactory(incoming, outgoing, event)};
}

void fix_screen_log_factory_destroy(fix_screen_log_factory_t* factory) {
    delete factory->ptr;
    delete factory;
}
