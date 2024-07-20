/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:01:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 18:01:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Menu.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Menu::Menu() : Animation(), _saveImg(false) { }

Menu::Menu(const Menu &src) : Animation(src) { *this = src; }

Menu::~Menu() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Menu &Menu::operator=(const Menu &rhs)
{
	Animation::operator=(rhs);
	if (this != &rhs)
	{
		this->_saveImg = rhs._saveImg;
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_size = rhs._size;
		this->_pos = rhs._pos;
		this->_value = rhs._value;
		this->_step = rhs._step;
	}
	return (*this);
}
