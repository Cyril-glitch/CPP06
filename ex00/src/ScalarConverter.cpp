/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:30:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/22 12:35:22 by cycolonn         ###   ########.fr       */
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


bool _isEmpty(const std::string& from)
{
    return (from.empty());
}

bool _isPseudoLit(const std::string& from)
{
    if (from == "nan" || from == "+inf" || from == "-inf" ||
        from == "nanf" || from == "+inff" || from == "-inff")
        return true;
    return false; 
}

bool _isChar(const std::string& from)
{
    if (from.length() != 3) return false;
    if (std::isprint(from[1]) || std::isdigit(from[1])) return false;
    if (from[0] != '\'' || from[2] != '\'') return false;
    return true;
}

bool _isNum(const std::string& from)
{
    return std::__count_if(from.begin(), from.end(),std::isdigit())
}

void ScalarConverter::convert(const std::string& from)
{

}