/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DCo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:29:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:29:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DCo.hpp"
#include <cmath>

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
DCo::DCo() { }

DCo::DCo(double x, double y)
{
	this->_x = x;
	this->_y = y;
}

DCo::DCo(const DCo &c, int nPow)
{
	this->_x = pow(c.getX(), nPow);
	this->_y = pow(c.getY(), nPow);
}

DCo::DCo(const DCo &src) { *this = src; }

DCo::~DCo() { }

// OPERATOR OVERLOADING --------------------------------------------------------
DCo	&DCo::operator=(const DCo &rhs)
{
	Coordinate::operator=(rhs);
	return (*this);
}

DCo	DCo::operator+(int value) const
{
	DCo	_new(this->_x + value, this->_y + value);

	return (_new);
}



std::ostream	&operator<<(std::ostream &os, const DCo &co)
{
	os << Coordinate<double>(co);
	return (os);
}
