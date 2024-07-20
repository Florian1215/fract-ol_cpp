/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Buffalo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Buffalo.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Buffalo::Buffalo(void *mlxPtr) : Fractal(mlxPtr, BUFFALO, BLUE_RED, PATH_BUFFALO, Delta(DCo(-2.1, 2.1), DCo(2.1, -2.1)), CPreset(DCo(-1.14, 0.06), DCo(0.406, -0.936), DCo(-0.936, 0.052), DCo(-1.752, -1.0266), DCo(0.18, -0.544), DCo(0.366, -0.676), DCo(-1.552, -1.772), DCo(-1.13, 0.08), DCo(-0.428, -1.52), DCo(0.426, -0.716)))
{
	this->_animationC.setStart(DCo(-1, 1));
}

Buffalo::Buffalo(const Buffalo &src) : Fractal(src) { }

Buffalo::~Buffalo() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Buffalo &Buffalo::operator=(const Buffalo &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
Color	Buffalo::sequence(Data &data, DCo c, DCo co) const
{
	int		i;
	DCo	sqr(c, 2);

	i = 0;
	while (i < this->_maxIter)
	{
		c.setY(2 * fabs(c.getX() * c.getY()) + this->_c.getY());
		c.setX(fabs(sqr.getX() - sqr.getY()) + this->_c.getX());
		sqr = DCo(c, 2);
		if (sqr.sum() > 4)
			return (this->_getColor(data, i, sqr.sum(), co, c));
		i++;
	}
	return (FG);
}
