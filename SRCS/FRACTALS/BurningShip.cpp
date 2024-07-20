/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BurningShip.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:18:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:18:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BurningShip.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
BurningShip::BurningShip(void *mlxPtr) : Fractal(mlxPtr, BURNING_SHIP, RED, PATH_BURNING_SHIP, Delta(DCo(-2.4, 1.6), DCo(1.6, -2.4))) { }

BurningShip::BurningShip(const BurningShip &src) : Fractal(src) { }

BurningShip::~BurningShip() { }

// OPERATOR OVERLOADING --------------------------------------------------------
BurningShip &BurningShip::operator=(const BurningShip &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
Color	BurningShip::sequence(Data &data, DCo z, DCo co) const
{
	DCo	sqr(z, 2);
	int		i;

	sqr = DCo(z, 2);
	i = 0;
	while (i < this->_maxIter)
	{
		z.setY(2 * fabs(z.getX() * z.getY()) + z.getY());
		z.setX(sqr.getX() - sqr.getY() + z.getX());
		sqr = DCo(z, 2);
		if (sqr.sum() > 4)
			return (this->_getColor(data, i, sqr.sum(), co, z));
		i++;
	}
	return (Color(FG));
}
