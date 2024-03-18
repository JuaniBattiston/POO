#ifndef EJ2LIB_GLOBAL_H
#define EJ2LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EJ2LIB_LIBRARY)
#define EJ2LIB_EXPORT Q_DECL_EXPORT
#else
#define EJ2LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // EJ2LIB_GLOBAL_H
