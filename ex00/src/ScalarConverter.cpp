/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:30:47 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/21 15:30:03 by cycolonn         ###   ########.fr       */
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

bool    ScalarConverter::HandlePseudoLit(const std::string& from)
{
    if(from == "nan" || from == "+inf" || from == "-inf")     
        return true;  
    if(from == "nanf" || from == "+inff" || from == "-inff") 
        return true;
    return false; 
}



void ScalarConverter::convert(const std::string& from)
{

}