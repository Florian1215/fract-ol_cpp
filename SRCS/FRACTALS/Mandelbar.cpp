/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbar.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbar.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Mandelbar::Mandelbar(void *mlxPtr) : Fractal(mlxPtr, MANDELBAR, BLUE, PATH_MANDELBAR, CPreset(DCo(-0.23, 0.796), DCo(-0.272, -0.776), DCo(-0.768, -0.296), DCo(-0.132, -0.796), DCo(-0.352, -0.746), DCo(0.416, -0.526), DCo(-0.574, -0.506), DCo(-0.78, 0.186)))
{
	this->_animationC.setStart(DCo(-2, 2));
}

Mandelbar::Mandelbar(const Mandelbar &src) : Fractal(src) { }

Mandelbar::~Mandelbar() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Mandelbar &Mandelbar::operator=(const Mandelbar &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
Color	Mandelbar::sequence(Data &data, DCo z, DCo co) const
{
	int		i;
	DCo	sqr(z, 2);

	i = 0;
	sqr = DCo(z, 2);
	while (i < this->_maxIter)
	{
		z.setY(-2 * fabs(z.getX()) * z.getY() + this->_c.getY());
		z.setX(sqr.getX() - sqr.getY() + this->_c.getX());
		sqr = DCo(z, 2);
		if (sqr.sum() > 4)
			return (this->_getColor(data, i, sqr.sum(), co, z));
		i++;
	}
	return (FG);
}
