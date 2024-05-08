/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heart.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Heart.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Heart::Heart(void *mlxPtr) : Fractal(mlxPtr, HEART, NIGHT_BLUE, PATH_HEART, CPreset(DCo(-0.07, 0.278), DCo(-0.51, 0.085), DCo(-0.982, -0.066), DCo(0.29, 0.008), DCo(-0.108, -0.26), DCo(0.29, -0.012)))
{
	this->_animationC.setStart(DCo(-1, 2));
}

Heart::Heart(const Heart &src) : Fractal(src) { }

Heart::~Heart() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Heart &Heart::operator=(const Heart &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
int Heart::sequence(Data &data, DCo z, DCo co) const
{
	int		i;
	DCo	sqr(z, 2);

	i = 0;
	sqr = DCo(z, 2);
	while (i < this->_maxIter)
	{
		z.setY(2 * fabs(z.getX()) * z.getY() + this->_c.getY());
		z.setX(sqr.getX() - sqr.getY() + this->_c.getX());
		sqr = DCo(z, 2);
		if (sqr.getX() + sqr.getY() > 4)
			return (get_color(data, (t_color_data){frac, i, sqr.getX() + sqr.getY()}, \
co, z));
		i++;
	}
	return (FG);
}
