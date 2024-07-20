/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                   Animation                             +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 11:02:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animation.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Animation::Animation() : _isAnimation(false), _i(0) { }

Animation::Animation(const Animation &src) { *this = src; }

Animation::~Animation() { }


AnimationValue::AnimationValue() : _curr(0), _prev(0) { }

AnimationValue::AnimationValue(int curr) : _curr(curr), _prev(0) { }

AnimationValue::AnimationValue(const AnimationValue &src) : Animation(src) { *this = src; }

AnimationValue::~AnimationValue() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Animation &Animation::operator=(const Animation &rhs)
{
	if (this != &rhs)
	{
		this->_i = rhs._i;
		this->_isAnimation = rhs._isAnimation;
	}
	return (*this);
}

bool	Animation::operator<(int rhs) const { return (this->_i < rhs); }

bool	Animation::operator<=(int rhs) const { return (this->_i <= rhs); }

bool	Animation::operator>(int rhs) const { return (this->_i > rhs); }

bool	Animation::operator>=(int rhs) const { return (this->_i >= rhs); }

Animation::operator	bool() const { return (this->_isAnimation); }


AnimationValue &AnimationValue::operator=(const AnimationValue &rhs)
{
	Animation::operator=(rhs);
	if (this != &rhs)
	{
		this->_curr = rhs._curr;
		this->_prev = rhs._prev;
	}
	return (*this);
}

bool	AnimationValue::operator==(int rhs) const { return (this->_curr == rhs); }

// GETTER - SETTER -------------------------------------------------------------
int	AnimationValue::getCurr() const { return (this->_curr); }

int	AnimationValue::getPrev() const { return (this->_prev); }

// MEMBER FUNCTIONS ------------------------------------------------------------
int	Animation::getI() const { return (this->_i); }

void	Animation::setAnimation(bool isAnimation) { this->_isAnimation = isAnimation; }

// FUNCTIONS ------------------------------------------------------------------
double	getValue(double a, double b, int i)
{
	const double	values[29] = {0.4, 1.7, 4.6, 9.8, 19, 32, 44.7, 54.7, 62.4, \
68.6, 73.6, 77.7, 81.2, 84.2, 86.8, 89, 90.9, 92.5, 93.9, 95.2, \
96.2, 97.1, 97.8, 98.5, 99, 99.4, 99.6, 99.8, 99.9};

	if (a > b)
		return (a - (values[i] * (a - b) / 100));
	else if (a < b)
		return ((values[i] * (b - a) / 100) + a);
	return (a);
}
