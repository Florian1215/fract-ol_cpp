/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICo.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:29:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:29:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ICo.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
ICo::ICo() { }

ICo::ICo(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

ICo::ICo(const ICo &src) { *this = src; }

ICo::~ICo() { }

// OPERATOR OVERLOADING --------------------------------------------------------
ICo &ICo::operator=(const ICo &rhs)
{
	Coordinate::operator=(rhs);
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const ICo &co)
{
	os << Coordinate<int>(co);
	return (os);
}
