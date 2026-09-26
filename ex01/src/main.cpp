/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:54:26 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/26 12:28:30 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
    Data d;
    uintptr_t u_ptr;
    Data* d_ptr;

    d.i = 42;
    d.s = "hello world";

    u_ptr = Serializer::serialize(&d);
    std::cout << "&data = " << MINT << &d << RESET << std::endl;
    std::cout << "serialization: " << MINT << u_ptr << RESET << std::endl;
    d_ptr = Serializer::deserialize(u_ptr);
    std::cout << "deserialization: " << MINT << d_ptr << RESET << std::endl;

    std::cout << d_ptr->i << std::endl;
    std::cout << d_ptr->s << std::endl;
}