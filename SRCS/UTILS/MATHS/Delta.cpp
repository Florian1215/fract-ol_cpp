/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delta.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:06:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:06:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Delta.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Delta::Delta() { }

Delta::Delta(const DCo &start, const DCo &end) : _start(start), _end(end) { }

Delta::Delta(const Delta &src) { *this = src; }

Delta::~Delta() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Delta &Delta::operator=(const Delta &rhs)
{
	if (this != &rhs)
	{
		this->_start = rhs._start;
		this->_end = rhs._end;
	}
	return (*this);
}

// GETTER - SETTER -------------------------------------------------------------
const DCo	&Delta::getStart() const
{
	return (this->_start);
}

const DCo	&Delta::getEnd() const
{
	return (this->_end);
}

void	Delta::setStart(const DCo &start)
{
	this->_start = start;
}

void	Delta::setStartX(double x)
{
	this->_start.setX(x);
}

void	Delta::setStartY(double y)
{
	this->_start.setY(y);
}

void	Delta::setEnd(const DCo &end)
{
	this->_end = end;
}

void	Delta::setEndX(double x)
{
	this->_end.setX(x);
}

void	Delta::setEndY(double y)
{
	this->_end.setY(y);
}
