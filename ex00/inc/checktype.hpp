/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktype.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 10:30:00 by copilot           #+#    #+#             */
/* ************************************************************************** */

#ifndef CHECKTYPE_HPP
#define CHECKTYPE_HPP

#include <string>

enum Type { INVALID, PSEUDOLIT, CHAR, NUM };

Type checkType(const std::string& lit);

#endif
