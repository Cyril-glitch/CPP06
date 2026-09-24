/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:30:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/24 14:23:37 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

ScalarConverter::~ScalarConverter()
{
}


/* ************************************************************************** */
/**
 * @brief CheckType
 */
bool ScalarConverter::_isInvalid(const std::string& lit)
{
    char *end;
    errno = 0;

    if (lit.empty()) return true;
    std::cout << "1" << std::endl;
    if (std::strtod(lit.c_str(), &end) == ERANGE ) return true;
    return false;
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
    size_t len = lit.length();
    std::cout << "3" << std::endl;
    if (len != 3 && len != 1) return false; 
    if (len == 1 && std::isdigit(lit[0])) return false;
    if (len == 3 && (lit[0] != '\'' || lit[2] != '\'')) return false;
    return true;
}

bool ScalarConverter::_isInt(const std::string &lit)
{
    if ((lit[0] != '+' || lit[0] != '-') && !std::isdigit(lit[0]))
        return false;
    if (!lit.find_first_not_of("0123456789+-"))
        return false;
    return true;
}

bool ScalarConverter::_isFloat(const std::string &lit)
{
    size_t len = lit.length();
    if (lit[0] != '+' || lit[0] != '-' || lit[0] != '.' || !std::isdigit(lit[0]))
        return false;
    if (lit[len] != 'f')
        return false; 
    if (!lit.find_first_not_of("0123456789+-.f"))
        return false;
    return true;
}

bool ScalarConverter::_isDouble(const std::string &lit)
{
    if (lit[0] != '+' || lit[0] != '-' || lit[0] != '.' || !std::isdigit(lit[0]))
        return false;
    if (!lit.find_first_not_of("0123456789+-."))
        return false;
    return true;
}

ScalarConverter::Type ScalarConverter::_checkType(const std::string &lit)
{
    if (_isInvalid(lit)) return INVALID;
    std::cout << "2" << std::endl;
    if (_isPseudoLit(lit)) return PSEUDOLIT;
    if (_isChar(lit)) return CHAR;
    //if (_isInt(lit)) return INT;
    // if (_isFloat(lit)) return FLOAT;
    //if (_isDouble(lit)) return DOUBLE;
    return INVALID;
}
/* ************************************************************************** */

/* ************************************************************************** */
/**
 * @brief DisplayInvalid & DisplayPseudo
 */
void ScalarConverter::_displayInvalid(const std::string &lit)
{ 
    (void)lit;
    std::cerr << BL_RED "Error: Invalid argument" RESET << std::endl;
}

void ScalarConverter::_displayPseudo(const std::string &lit)
{
    size_t len = lit.length();

    if (lit == "nan" || lit == "+inf" || lit == "-inf") 
    {
        std::cout << "char: " << "impossible"<< std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << lit + "f" << std::endl;
        std::cout << "double: " << lit << std::endl;
    }
    if (lit == "nanf" || lit == "+inff" || lit == "-inff")
    {
        std::cout << "char: " << "impossible"<< std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << lit << std::endl;
        std::cout << "double: " << lit.substr(0, len - 1) << std::endl;
    }
}
/* ************************************************************************** */

/* ************************************************************************** */
/**
 * @brief DisplayNum
 */
void ScalarConverter::_PrintChar(double val)
{
    std::cout << val << std::endl;
    if (val < CHAR_MIN || val > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else 
        std::cout << "char: " << static_cast<char>(val) << std::endl;
}

void ScalarConverter::_PrintInt(double val)
{
    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

void ScalarConverter::_PrintFloat(double val)
{
    if (val < __FLT_MIN__ || val > __FLT_MAX__)
        std::cout << "float: impossible" << std::endl;  
    else
        std::cout << "float: " << static_cast<float>(val) << std::endl;
}

void ScalarConverter::_PrintDouble(double val)
{
        std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void ScalarConverter::_displayChar(const std::string &lit)
{
    double num;

    num =  static_cast<double>(lit[0]);
    
    _PrintChar(num);
    _PrintInt(num);
    _PrintFloat(num);
    _PrintDouble(num);
}


void ScalarConverter::_displayNum(const std::string &lit)
{
    char *end;

     double num = std::strtod(lit.c_str(), &end);
    _PrintChar(num);
    _PrintInt(num);
    _PrintFloat(num);
    _PrintDouble(num);
}
/* ************************************************************************** */

void ScalarConverter::convert(const std::string& lit)
{
    void (*f[])(const std::string& lit) = {&_displayInvalid, &_displayPseudo, &_displayChar, &_displayNum};
    ScalarConverter::Type type;
    
    type = _checkType(lit);
    f[type](lit);
}