/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Celtic                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:07:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:07:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Celtic.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Celtic::Celtic(void *mlxPtr) : Fractal(mlxPtr, CELTIC, ELECTRIC_BLUE, PATH_CELTIC, Delta(DCo(-2, 1.3), DCo(-2, -2.7))) { }

Celtic::Celtic(const Celtic &src) : Fractal(src) { }

Celtic::~Celtic() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Celtic &Celtic::operator=(const Celtic &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
int Celtic::sequence(Data &data, DCo c, DCo co) const
{
	int	i;
	DCo	z(c.getX(), c.getY());
	DCo	sqr(pow(z.getX(), 2), pow(z.getY(), 2));

	i = 0;
	while (i < this->_maxIter)
	{
		z.setY((2 * z.getX() * z.getY()) + c.getX() + this->_c.getX());
		z.setX(fabs(sqr.getX() - sqr.getY()) + c.getY() + fabs(this->_c.getY()));
		sqr = DCo(pow(z.getX(), 2), pow(z.getY(), 2));
		if (sqr.getX() + sqr.getY() > 4)
			return (get_color(data, (t_color_data){frac, i, sqr.getX() + sqr.getY()}, \
co, z));
		i++;
	}
	return (FG);
}
