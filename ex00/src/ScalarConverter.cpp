/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:30:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/23 08:28:14 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
}

ScalarConverter::~ScalarConverter()
{
}


bool ScalarConverter::_isEmpty(const std::string& lit)
{
    return (lit.empty());
}

bool ScalarConverter::_isPseudoLit(const std::string& lit)
{
    if (lit == "nan" || lit == "+inf" || lit == "-inf" ||
        lit == "nanf" || lit == "+inff" || lit == "-inff")
        return true;
    return false; 
}

bool ScalarConverter::_isChar(const std::string& lit)
{
    if (lit.length() != 3) return false;
    if (std::isprint(lit[1]) || std::isdigit(lit[1])) return false;
    if (lit[0] != '\'' || lit[2] != '\'') return false;
    return true;
}

bool ScalarConverter::_isInt(const std::string &lit)
{
    if (lit[0] != '+' || lit[0] != '-' || !std::isdigit(lit[0]))
        return false;
    if (lit.find_first_not_of("0123456789+-"))
        return false;
    return true;
}

bool ScalarConverter::_isFloat(const std::string &lit)
{
    if (lit[0] != '+' || lit[0] != '-' || lit[0] != '.' || !std::isdigit(lit[0]))
        return false;
    if (lit.back() != 'f')
        return false; 
    if (lit.find_first_not_of("0123456789+-.f"))
        return false;
    return true;
}

bool ScalarConverter::_isDouble(const std::string &lit)
{
    if (lit[0] != '+' || lit[0] != '-' || lit[0] != '.' || !std::isdigit(lit[0]))
        return false;
    if (lit.find_first_not_of("0123456789+-."))
        return false;
    return true;
}

ScalarConverter::Type ScalarConverter::_checkType(const std::string &lit)
{
    if (_isEmpty(lit)) return INVALID;
    if (_isPseudoLit(lit)) return PSEUDOLIT;
    if (_isChar(lit)) return CHAR;
    if (_isInt(lit)) return INT;
    if (_isFloat(lit)) return FLOAT;
    if (_isDouble(lit)) return DOUBLE;
    return INVALID;
}

void ScalarConverter::_printInvalid(const std::string &lit)
{

}

void ScalarConverter::_printPseudo(const std::string &lit)
{

}

void ScalarConverter::_printChar(const std::string &lit)
{

}

void ScalarConverter::_printInt(const std::string &lit)
{

}

void ScalarConverter::_printFloat(const std::string &lit)
{

}

void ScalarConverter::_printDouble(const std::string &lit)
{

}

void ScalarConverter::convert(const std::string& lit)
{
    void (*f[])(const std::string& lit) {&_printInvalid, &_printPseudo, &_printChar, &_printInt, &_printFloat, &_printDouble};
    ScalarConverter::Type type;
    
    type = _checkType(lit);
    f[type](lit);
}