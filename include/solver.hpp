#pragma once

#include <iostream>

template <typename type>
void __info(const type& chunk)
{
    std::cout << chunk << "\x1b[0m\n";
}
template <typename type, typename... types>
void __info(const type& chunk, const types&... message)
{
    std::cout << chunk;
    __info(message...);
}
template <typename... types>
void info(const types&... message)
{
    std::cout << "\x1b[1;34minfo:   \x1b[0;34m";
    __info(message...);
}

template <typename type>
void __error(const type& chunk)
{
    std::cerr << chunk << "\x1b[0m\n";
    exit(1);
}
template <typename type, typename... types>
void __error(const type& chunk, const types&... message)
{
    std::cerr << chunk;
    __error(message...);
}
template <typename... types>
void error(const types&... message)
{
    std::cerr << "\x1b[1;31merror:  \x1b[0;31m";
    __error(message...);
}

template <typename type>
void __result(const type& chunk)
{
    std::cerr << chunk << "\x1b[0m\n";
}
template <typename type, typename... types>
void __result(const type& chunk, const types&... message)
{
    std::cerr << chunk;
    __result(message...);
}
template <typename... types>
void result(const types&... message)
{
    std::cerr << "\x1b[1;32mresult: \x1b[0;32m";
    __result(message...);
}