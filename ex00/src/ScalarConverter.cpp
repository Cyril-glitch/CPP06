/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:30:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/26 10:18:26 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include "../inc/checktype.hpp"
#include "../inc/display.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& lit)
{
    void (*display[])(const std::string& lit) = {&displayInvalid, &displayPseudo, &displayChar, &displayNum};
    enum Type type;
    
    type = checkType(lit);
    display[type](lit);
}