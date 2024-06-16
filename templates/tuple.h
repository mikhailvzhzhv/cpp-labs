#pragma once
#include <iostream>
#include <tuple>
#include <string>

namespace base {

template <size_t idx, typename... Ts>
typename std::enable_if<idx == sizeof...(Ts)>::type
printTuple(std::ostream& os, const std::tuple<Ts...>& t) {
    return;
}

template <size_t idx, typename... Ts>
typename std::enable_if<idx < sizeof...(Ts)>::type
printTuple(std::ostream& os, const std::tuple<Ts...>& t) {
    if (idx != 0) {
        os << ", ";
    }
    os << std::get<idx>(t);
    printTuple<idx + 1>(os, t);
}

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
    os << "(";
    printTuple<0>(os, t);
    os << ")";
    return os;
}

}


namespace constexpression {

template <size_t idx, typename... Ts>
void printTuple(std::ostream& os, const std::tuple<Ts...>& t) {
    if constexpr (idx < sizeof...(Ts)) {
        if (idx != 0) {
            os << ", ";
        }
        os << std::get<idx>(t);
        printTuple<idx + 1>(os, t);
    }
}

template <typename... Ts>
std::ostream& operator<<(std::ostream& os, const std::tuple<Ts...>& t) {
    os << "(";
    printTuple<0>(os, t);
    os << ")";
    return os;
}

}


namespace foldexpr {

template <typename TupleT, std::size_t... Is>
std::ostream& printTuple(std::ostream& os, const TupleT& tp, std::index_sequence<Is...>) {
    os << "(";
    ((os << (Is == 0 ? "" : ", ") << std::get<Is>(tp)), ...);
    os << ")";
    
    return os;
}

template <typename TupleT, std::size_t TupSize = std::tuple_size<TupleT>::value>
std::ostream& operator <<(std::ostream& os, const TupleT& tp) {
    return printTuple(os, tp, std::make_index_sequence<TupSize>{}); 
}

}