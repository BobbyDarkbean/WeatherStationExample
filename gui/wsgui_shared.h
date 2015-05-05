#ifndef WSGUI_SHARED_H
#define WSGUI_SHARED_H

#include <qobjectdefs.h>

#ifdef WS_GUI_LIB
#define WS_GUI_SHARED Q_DECL_EXPORT
#else
#define WS_GUI_SHARED Q_DECL_IMPORT
#endif

#endif // WSGUI_SHARED_H
