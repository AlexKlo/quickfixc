#ifndef QUICKFIXC_H
#define QUICKFIXC_H

#include "quickfix/Exceptions.h"
#include "quickfix/Dictionary.h"
#include "quickfix/SessionSettings.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdexcept>
#include <cstring> 

using namespace FIX;

#ifdef __cplusplus
extern "C" {
#endif

#include "Types.h"
#include "Errors.h"
#include "Dictionary_c.h"
#include "SessionID_c.h"
#include "SessionSettings_c.h"

#ifdef __cplusplus
}
#endif

#endif // QUICKFIXC_H