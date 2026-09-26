/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:56:26 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/26 12:31:00 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "colors.hpp"
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
    public :
    
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

    private :
    
        Serializer();
        Serializer(const Serializer& src);
        ~Serializer();

        Serializer& operator=(const Serializer& rhs);
};

#endif