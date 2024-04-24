#ifndef TYPES_H
#define TYPES_H

#include <QMap>
#include <QPointer>
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

template<class T>
using UniquePtr = QScopedPointer<T>;

template<class T>
using SharedPtr = QSharedPointer<T>;

template<class T>
using WeakPtr = QWeakPointer<T>;

} // namespace Types
#endif // TYPES_H
