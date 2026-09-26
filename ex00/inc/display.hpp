/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 10:35:00 by copilot           #+#    #+#             */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

void displayInvalid(const std::string& lit);
void displayPseudo(const std::string& lit);
void displayChar(const std::string& lit);
void displayNum(const std::string& lit);

#endif
