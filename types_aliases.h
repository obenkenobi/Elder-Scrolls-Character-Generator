#ifndef TYPES_ALIASES_H
#define TYPES_ALIASES_H

#include <QString>
#include <QtTypes>
#include <QVector>

namespace TAS {
using String = QString;
using Uint8 = quint8;

template <class T>
using Vector = QVector<T>;

} // namespace type_aliases
#endif // TYPES_ALIASES_H
