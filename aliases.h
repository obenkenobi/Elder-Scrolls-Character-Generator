#ifndef ALIASES_H
#define ALIASES_H

#include <QMap>
#include <QString>
#include <QVector>
#include <QtTypes>
#include <initializer_list>

namespace Aliases {

using String = QString;
using Uint8 = quint8;

template <class T> using Vector = QVector<T>;

template<class K, class V>
using Map = QMap<K, V>;

template <class T> using InitializerList = std::initializer_list<T>;

} // namespace Aliases
#endif // ALIASES_H
