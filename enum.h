#ifndef ENUM_H
#define ENUM_H

// #include "aliases.h"

// #define ENUM(TYPENAME, ...) \
//     enum TYPENAME { __VA_ARGS__ }; \
//     Aliases::String enumToString(TYPENAME val) \
//     { \
//         static const Aliases::String joinedEnums = #__VA_ARGS__; \
//         static const auto splitList = joinedEnums.trimmed().remove(" ").split(","); \
//         return (0 <= val && val <= splitList.size()) ? splitList[val] : ""; \
//     };

#define ENUM(TYPENAME, ...) enum TYPENAME { __VA_ARGS__ };

#endif // ENUM_H
