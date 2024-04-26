#ifndef LOGGING_H
#define LOGGING_H

#include <QDateTime>
#include <QDebug>
#include <QTimeZone>
#include "types.h"

static inline auto formatLogPrefix(const Types::String &level)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    Types::String dateTimeString = currentDateTime.toTimeZone(currentDateTime.timeZone())
                                       .toString(Qt::ISODate);
    Types::Size spaceCount = (level.size() < 5) ? 5 - level.size() : 0;
    auto prefix = Types::String("[%1]%2 [%3] ")
                      .arg(level, Types::String(spaceCount, ' '), dateTimeString)
                      .toUtf8()
                      .data();

    return prefix;
}

#ifndef LOG_DEBUG
#define LOG_DEBUG (qDebug() << formatLogPrefix("DEBUG"))
#endif

#ifndef LOG_INFO
#define LOG_INFO (qInfo() << formatLogPrefix("INFO"))
#endif

#ifndef LOG_WARN
#define LOG_WARN (qWarning() << formatLogPrefix("WARN"))
#endif

#ifndef LOG_CRITICAL
#define LOG_CRITICAL (qCritical() << formatLogPrefix("CRIT"))
#endif

#ifndef LOG_FATAL
#define LOG_FATAL (qFatal() << formatLogPrefix("FATAL"))
#endif

#endif // LOGGING_H
