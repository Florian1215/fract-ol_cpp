/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CelticMandelbrot.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "CelticMandelbrot.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
CelticMandelbrot::CelticMandelbrot(void *mlxPtr) : Fractal(mlxPtr, CELTIC_MANDELBROT, YELLOW, PATH_CELTIC_MANDELBROT, CPreset(DCo(-0.816, 0.128), DCo(-0.804, -0.32), DCo(-1.184, -0.252), DCo(-0.872, -0.804), DCo(-0.562, -1.044), DCo(-1.26, -0.008)))
{
	this->_animationC.setStart(DCo(-2, 2));
}

CelticMandelbrot::CelticMandelbrot(const CelticMandelbrot &src) : Fractal(
		src) { }

CelticMandelbrot::~CelticMandelbrot() { }

// OPERATOR OVERLOADING --------------------------------------------------------
CelticMandelbrot &CelticMandelbrot::operator=(const CelticMandelbrot &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
int CelticMandelbrot::sequence(Data &data, DCo z, DCo co) const
{
	int		i;
	DCo	sqr(z, 2);

	i = 0;
	sqr = DCo(z, 2);
	while (i < this->_maxIter)
	{
		z.setY(2 * z.getX() * z.getY() + this->_c.getY());
		z.setX(fabs(sqr.getX() - sqr.getY()) + this->_c.getX());
		sqr = DCo(z, 2);
		if (sqr.getX() + sqr.getY() > 4)
			return (get_color(data, (t_color_data){frac, i, sqr.getX() + sqr.getY()}, \
co, z));
		i++;
	}
	return (FG);
}
