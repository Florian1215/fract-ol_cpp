/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slide.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:45:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 17:45:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Slide.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Slide::Slide(void *mlx_ptr) : _img(mlx_ptr), _renderImg(false) { }

Slide::Slide(const Slide &src) : _img(src._img) { *this = src; }

Slide::~Slide() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Slide &Slide::operator=(const Slide &rhs)
{
	if (this != &rhs)
	{
		this->_side = rhs._side;
		this->_i = rhs._i;
		this->_start = rhs._start;
		this->_value = rhs._value;
		this->_animation = rhs._animation;
		this->_renderImg = rhs._renderImg;
	}
	return (*this);
}

// GETTER - SETTER -------------------------------------------------------------
void Slide::setAnimation(bool animation)
{
	this->_animation = animation;
}
