/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 10:35:00 by copilot           #+#    #+#             */
/* ************************************************************************** */

#include "../inc/display.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cstdlib>
#include <cmath>

static void PrintChar(double val)
{
    if (val < CHAR_MIN || val > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (val < ' ' || val > '~')
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: \'" <<static_cast<char>(val) << "\'" << std::endl;
}

static void PrintInt(double val)
{
    if (val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void PrintFloat(double val)
{
    if (val < -FLT_MAX || val > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else if (val == std::floor(val))
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
}

static void PrintDouble(double val)
{ 
    if (val == std::floor(val))
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
    else
        std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void displayInvalid(const std::string &lit)
{
    (void)lit;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void displayPseudo(const std::string &lit)
{
    size_t len = lit.length();

    if (lit == "nan" || lit == "+inf" || lit == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << lit + "f" << std::endl;
        std::cout << "double: " << lit << std::endl;
    }
    else if (lit == "nanf" || lit == "+inff" || lit == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << lit << std::endl;
        std::cout << "double: " << lit.substr(0, len - 1) << std::endl;
    }
}

void displayChar(const std::string &lit)
{
    double num;
    size_t len = lit.length();

    if (len == 1)
        num = static_cast<double>(lit[0]);
    else
        num = static_cast<double>(lit[1]);

    PrintChar(num);
    PrintInt(num);
    PrintFloat(num);
    PrintDouble(num);
}

void displayNum(const std::string &lit)
{
    double num = std::strtod(lit.c_str(), NULL);

    PrintChar(num);
    PrintInt(num);
    PrintFloat(num);
    PrintDouble(num);
}
