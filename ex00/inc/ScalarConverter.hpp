/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:56:26 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/23 08:26:20 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

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
        static bool _isEmpty(const std::string& lit);
        static bool _isPseudoLit(const std::string& lit);
        static bool _isChar(const std::string& lit);
        static bool _isInt(const std::string& lit);
        static bool _isFloat(const std::string& lit);
        static bool _isDouble(const std::string& lit);

        static void _printInvalid(const std::string& lit);
        static void _printPseudo(const std::string& lit);
        static void _printChar(const std::string& lit);
        static void _printInt(const std::string& lit);
        static void _printFloat(const std::string& lit);
        static void _printDouble(const std::string& lit);
};

#endif