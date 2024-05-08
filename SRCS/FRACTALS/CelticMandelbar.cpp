/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CelticMandelbar.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "CelticMandelbar.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
CelticMandelbar::CelticMandelbar(void *mlxPtr) : Fractal(mlxPtr, CELTIC_MANDELBAR, BLUE_LIGHT, PATH_CELTIC_MANDELBAR, CPreset(DCo(0.80, 0), DCo(-0.78, -0.18), DCo(-1.66, 0.0), DCo(0.276, -0.024), DCo(0.096, -0.852), DCo(-0.796000, -0.048000)))
{
	this->_animationC.setStart(DCo(-2, -2));
}

CelticMandelbar::CelticMandelbar(const CelticMandelbar &src) : Fractal(src) { }

CelticMandelbar::~CelticMandelbar() { }

// OPERATOR OVERLOADING --------------------------------------------------------
CelticMandelbar &CelticMandelbar::operator=(const CelticMandelbar &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
int CelticMandelbar::sequence(Data &data, DCo z, DCo co) const
{
	int		i;
	DCo	sqr(z, 2);

	i = 0;
	sqr = DCo(z, 2);
	while (i < this->_maxIter)
	{
		z.setY(-2 * z.getX() * z.getY() + this->_c.getY());
		z.setX(fabs(sqr.getX() - sqr.getY()) + this->_c.getX());
		sqr = DCo(z, 2);
		if (sqr.getX() + sqr.getY() > 4)
			return (get_color(data, (t_color_data){frac, i, sqr.getX() + sqr.getY()}, \
co, z));
		i++;
	}
	return (FG);
}
