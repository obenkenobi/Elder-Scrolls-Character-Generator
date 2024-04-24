#ifndef LOGGING_H
#define LOGGING_H

#include <QDebug>

#ifndef LOG_DEBUG
#define LOG_DEBUG qDebug()
#endif

#ifndef LOG_INFO
#define LOG_INFO qInfo()
#endif

#ifndef LOG_WARN
#define LOG_WARN qWarning()
#endif

#ifndef LOG_CRITICAL
#define LOG_CRITICAL qCritical()
#endif

#ifndef LOG_FATAL
#define LOG_FATAL qFatal()
#endif

#endif // LOGGING_H
