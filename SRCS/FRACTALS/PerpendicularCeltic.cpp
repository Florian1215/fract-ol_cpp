/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerpendicularCeltic.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PerpendicularCeltic.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
PerpendicularCeltic::PerpendicularCeltic(void *mlxPtr) : Fractal(mlxPtr, PERPENDICULAR_CELTIC, PASTEL_PINK, PATH_PERPENDICULAR_CELTIC, CPreset(DCo(-0.75, -0.09), DCo(-0.796, 0.23), DCo(-0.648, -1.08), DCo(-0.664, 1.02), DCo(0.068, -0.828), DCo(-0.824, -0.128), DCo(0.292, -0.20), DCo(-0.204, -1.04)))
{
	this->_animationC.setStart(DCo(2, 2));
}

PerpendicularCeltic::PerpendicularCeltic(const PerpendicularCeltic &src)
		: Fractal(src) { }

PerpendicularCeltic::~PerpendicularCeltic() { }

// OPERATOR OVERLOADING --------------------------------------------------------
PerpendicularCeltic &PerpendicularCeltic::operator=(const PerpendicularCeltic &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
Color	PerpendicularCeltic::sequence(Data &data, DCo z, DCo co) const
{
	int	i;
	DCo	sqr(z, 2);

	i = 0;
	while (i < this->_maxIter)
	{
		z.setY(-2 * fabs(z.getX()) * z.getY() + this->_c.getY());
		z.setX(fabs(sqr.getX() - sqr.getY()) + this->_c.getX());
		sqr = DCo(z, 2);
		if (sqr.sum() > 4)
			return (this->_getColor(data, i, sqr.sum(), co, z));
		i++;
	}
	return (FG);
}
