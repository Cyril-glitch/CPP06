/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:50:21 by cycolonn          #+#    #+#             */
/*   Updated: 2026/09/26 10:30:55 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/colors.hpp"
#include "../inc/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return std::cerr << BL_RED "Error: no argument." RESET << std::endl, 0;
    ScalarConverter::convert(av[1]);
    return 0;
}