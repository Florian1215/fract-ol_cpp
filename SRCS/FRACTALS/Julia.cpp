/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:54:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 15:54:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Julia.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Julia::Julia(void *mlxPtr) : Fractal(mlxPtr, JULIA, PURPLE, PATH_JULIA, CPreset(DCo(0.80, 0), DCo(0.75, 0.13), DCo(0.82, -0.2), DCo(0.76, 0.06), DCo(0.18, 0.69), DCo(0.76, -0.32), DCo(0.8, -0.14)))
{
	this->_animationC.setStart(DCo(2, -2));
}

Julia::Julia(const Julia &src) : Fractal(src) { }

Julia::~Julia() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Julia &Julia::operator=(const Julia &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
Color	Julia::sequence(Data &data, DCo z, DCo co) const
{
	int	i;
	DCo	sqr(pow(z.getX(), 2), pow(z.getY(), 2));

	i = 0;
	while (i < this->_maxIter)
	{
		z.setY(2 * z.getX() * z.getY() - this->_c.getY());
		z.setX(sqr.getX() - sqr.getY() - this->_c.getX());
		sqr = DCo(pow(z.getX(), 2), pow(z.getY(), 2));
		if (sqr.sum() > 4)
			return (this->_getColor(data, i, sqr.sum(), co, z));
		i++;
	}
	return (FG);
}
