#ifndef TYPES_ALIASES_H
#define TYPES_ALIASES_H

#include <QString>
#include <QtTypes>
#include <QVector>

namespace type_aliases {
using string_t = QString;
using a_uint8_t = quint8;

template <class T>
using vector = QVector<T>;

} // namespace type_aliases
#endif // TYPES_ALIASES_H
