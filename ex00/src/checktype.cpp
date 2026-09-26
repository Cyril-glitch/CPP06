/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 10:30:00 by copilot           #+#    #+#             */
/* ************************************************************************** */

#include "../inc/checktype.hpp"
#include <cstdlib>
#include <cerrno>
#include <cctype>

static bool isEmpty(const std::string& lit)
{
    return lit.empty();
}

static bool isPseudoLit(const std::string& lit)
{
    return (lit == "nan" || lit == "+inf" || lit == "-inf" ||
            lit == "nanf" || lit == "+inff" || lit == "-inff");
}

static bool isChar(const std::string& lit)
{
    size_t len = lit.length();
    if (len != 3 && len != 1) return false;
    if (len == 1 && std::isdigit(lit[0])) return false;
    if (len == 3 && (lit[0] != '\'' || lit[2] != '\'')) return false;
    return true;
}

static bool isNum(const std::string& lit)
{
    errno = 0;
    char *end;
    double d = std::strtod(lit.c_str(), &end);
    (void)d;

    if (errno == ERANGE) return false;
    if ((*end == 'f') && *(end + 1) == '\0') return true;
    if (*end == '\0') return true;
    return false;
}

Type checkType(const std::string &lit)
{
    if (isEmpty(lit)) return INVALID;
    if (isPseudoLit(lit)) return PSEUDOLIT;
    if (isChar(lit)) return CHAR;
    if (isNum(lit)) return NUM;
    return INVALID;
}
