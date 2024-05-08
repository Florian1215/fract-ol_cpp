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
	// Animation
Animation::Animation() : _isAnimation(false), _i(0) { }

Animation::Animation(const Animation &src) { *this = src; }

Animation::~Animation() { }

	// AnimationValue
AnimationValue::AnimationValue() : _curr(0), _prev(0) { }

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

// MEMBER FUNCTIONS ------------------------------------------------------------
void	Animation::setAnimation(bool isAnimation)
{
	this->_isAnimation = isAnimation;
}