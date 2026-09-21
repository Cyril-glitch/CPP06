/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:56:26 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/21 15:09:32 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    public :

        static void convert(const std::string& from);

    private :
    
        ScalarConverter();
        ScalarConverter(const ScalarConverter& src);
        ~ScalarConverter();

        ScalarConverter& operator=(const ScalarConverter& rhs);
        
        static void 
        static bool    _pseudoLit(const std::string& from);
};

#endif