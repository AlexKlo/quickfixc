#ifndef QUICKFIXC_H
#define QUICKFIXC_H

#include "quickfix/Exceptions.h"
#include "quickfix/Dictionary.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/Log.h"
#include "quickfix/FileLog.h"
#include "quickfix/MessageStore.h"
#include "quickfix/FileStore.h"
#include "quickfix/Application.h"
#include "quickfix/Initiator.h"
#include "quickfix/SocketInitiator.h"
#include "quickfix/config.h"
#include "quickfix/SSLSocketInitiator.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdexcept>
#include <cstring> 
#include <thread>

using namespace FIX;

#ifdef __cplusplus
extern "C" {
#endif

#include "Types.h"
#include "Errors.h"
#include "Dictionary_c.h"
#include "SessionID_c.h"
#include "SessionSettings_c.h"
#include "Log_c.h"
#include "FileLog_c.h"
#include "MessageStore_c.h"
#include "FileStore_c.h"
#include "Application_c.h"
#include "SocketInitiator_c.h"
#include "SSLSocketInitiator_c.h"
#include "FieldBase_c.h"
#include "Message_c.h"

#ifdef __cplusplus
}
#endif

#endif // QUICKFIXC_H