#ifndef KERNEL_SHARED_H
#define KERNEL_SHARED_H

#include <qobjectdefs.h>

#ifdef WS_KERNEL_LIB
#define WS_KERNEL_SHARED Q_DECL_EXPORT
#else
#define WS_KERNEL_SHARED Q_DECL_IMPORT
#endif

#endif // KERNEL_SHARED_H

