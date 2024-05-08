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
Menu::Menu() : _animation(false), _saveImg(false) { }

Menu::Menu(const Menu &src) { *this = src; }

Menu::~Menu() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Menu &Menu::operator=(const Menu &rhs)
{
	if (this != &rhs)
	{
		this->_animation = rhs._animation;
		this->_saveImg = rhs._saveImg;
		this->_start = rhs._start;
		this->_end = rhs._end;
		this->_i = rhs._i;
		this->_size = rhs._size;
		this->_pos = rhs._pos;
		this->_value = rhs._value;
		this->_step = rhs._step;
	}
	return (*this);
}
