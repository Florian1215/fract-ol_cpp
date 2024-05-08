/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hover.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:26:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 10:26:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Hover.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
	// Hover
Hover::Hover() : _hover(false), _isActive(false) { }

Hover::Hover(const Hover &src) { *this = src; }

Hover::~Hover() { }

	// HoverValue
HoverValue::HoverValue() { }

HoverValue::HoverValue(const HoverValue &src) { *this = src; }

HoverValue::~HoverValue() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Hover &Hover::operator=(const Hover &rhs)
{
	Animation::operator=(rhs);
	if (this != &rhs)
	{
		this->_zoom = rhs._zoom;
		this->_max_iter = rhs._max_iter;
		this->_i = rhs._i;
		this->_hover = rhs._hover;
		this->_unhover = rhs._unhover;
		this->_isActive = rhs._isActive;
	}
	return (*this);
}

HoverValue &HoverValue::operator=(const HoverValue &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs._value;
		this->_start = rhs._start;
		this->_end = rhs._end;
	}
	return (*this);
}
