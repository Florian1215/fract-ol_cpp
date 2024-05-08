/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:30:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 11:30:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Color::Color() : _color(0), _r(0),  _g(0),  _b(0) { }

Color::Color(int color) : _color(color), _r(color >> 16),  _g(color >> 8),  _b(color) { }

Color::Color(unsigned char r, unsigned char g, unsigned char b) : _color((r << 16) + (g << 8) + b), _r(r),  _g(g),  _b(b) { }

Color::Color(const Color &src) { *this = src; }

Color::~Color() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Color &Color::operator=(const Color &rhs)
{
	if (this != &rhs)
	{
		this->_color = rhs._color;
		this->_r = rhs._r;
		this->_g = rhs._g;
		this->_b = rhs._b;
	}
	return (*this);
}
