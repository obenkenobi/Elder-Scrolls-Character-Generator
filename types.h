#ifndef TYPES_H
#define TYPES_H

#include <QMap>
#include <QString>
#include <QVector>
#include <QtTypes>
#include <initializer_list>

namespace Types {

using String = QString;
using Uint8 = quint8;
using Size = qsizetype;

template <class T> using Vector = QVector<T>;

template<class K, class V>
using Map = QMap<K, V>;

template <class T> using InitializerList = std::initializer_list<T>;

} // namespace Types
#endif // TYPES_H
