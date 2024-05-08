/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:11:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 11:11:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Colors::Colors() : _color(GREEN), _prevColor(GREEN) { }

Colors::Colors(const Colors &src) : Animation(src) { *this = src; }


Colors::~Colors() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Colors &Colors::operator=(const Colors &rhs)
{
	Animation::operator=(rhs);
	if (this != &rhs)
	{
		this->_color = rhs._color;
		this->_prevColor = rhs._prevColor;
	}
	return (*this);
}
