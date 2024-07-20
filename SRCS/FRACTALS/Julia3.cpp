/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Julia3.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Julia3::Julia3(void *mlxPtr) : Fractal(mlxPtr, JULIA3, GREEN_BLUE, PATH_JULIA3, CPreset(DCo(-0.54, 0.45), DCo(-0.462, -0.536), DCo(-0.452, -0.616), DCo(-0.53, -0.166), DCo(-0.208, -0.924), DCo(-0.538, -0.17), DCo(-0.53, -0.456), DCo(-0.472, -0.536), DCo(-0.53, -0.146)))
{
	this->_animationC.setStart(DCo(-2, -2));
}

Julia3::Julia3(const Julia3 &src) : Fractal(src) { }

Julia3::~Julia3() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Julia3 &Julia3::operator=(const Julia3 &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
Color	Julia3::sequence(Data &data, DCo z, DCo co) const
{
	int		i;
	DCo	sqr(z, 2);

	i = 0;
	sqr = DCo(z, 2);
	while (i < this->_maxIter)
	{
		z.setX(sqr.getX() * z.getX() - 3 * sqr.getY() * z.getX() + this->_c.getX());
		z.setY(-z.getY() * z.getY() * z.getY() + 3 * sqr.getX() * z.getY() + this->_c.getY());
		sqr = DCo(z, 2);
		if (sqr.sum() > 4)
			return (this->_getColor(data, i, sqr.sum(), co, z));
		i++;
	}
	return (FG);
}
