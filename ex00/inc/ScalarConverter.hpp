/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:56:26 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/24 14:20:35 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "../inc/colors.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>

class ScalarConverter
{
    public :

        static void convert(const std::string& lit);

    private :
    
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ~ScalarConverter();

        ScalarConverter& operator=(const ScalarConverter& rhs);

        enum  Type {INVALID, PSEUDOLIT, CHAR, INT, DOUBLE, FLOAT};
        
        static enum Type _checkType(const std::string& lit);
        static bool _isInvalid(const std::string& lit);
        static bool _isPseudoLit(const std::string& lit);
        static bool _isChar(const std::string& lit);
        static bool _isInt(const std::string& lit);
        static bool _isFloat(const std::string& lit);
        static bool _isDouble(const std::string& lit);

        static void _displayInvalid(const std::string& lit);
        static void _displayPseudo(const std::string& lit);
        static void _displayNum(const std::string& lit);
        static void _displayChar(const std::string& lit);

        static void _PrintChar(double val);
        static void _PrintInt(double val);
        static void _PrintFloat(double val);
        static void _PrintDouble(double val);

};

#endif