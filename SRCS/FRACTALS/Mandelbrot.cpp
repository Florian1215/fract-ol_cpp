/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:39:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 15:39:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Mandelbrot::Mandelbrot(void *mlxPtr) : Fractal(mlxPtr, MANDELBROT, GREEN, PATH_MANDELBROT)
{
	this->_plan.setStartX(-2.2);
	this->_plan.setEndX(1.8);
	this->_planDefault = this->_plan;
}

Mandelbrot::Mandelbrot(const Mandelbrot &src) : Fractal(src) { }

Mandelbrot::~Mandelbrot() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Mandelbrot &Mandelbrot::operator=(const Mandelbrot &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
int	Mandelbrot::sequence(Data &data, DCo c, DCo co) const
{
	int	i;
	DCo	z(this->_c.getX(), this->_c.getY());
	DCo	sqr(pow(z.getX(), 2), pow(z.getY(), 2));

	i = 0;
	while (i < this->_maxIter)
	{
		z.setY(2 * z.getX() * z.getY() + c.getY());
		z.setX(sqr.getX() - sqr.getY() + c.getX());
		sqr = DCo(pow(z.getX(), 2), pow(z.getY(), 2));
		if (sqr.getX() + sqr.getY() > 4)
			return (get_color(data, (t_color_data){frac, i, sqr.getX() + sqr.getY()}, \
co, z));
		i++;
	}
	return (FG);
}
