/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BurningJulia.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BurningJulia.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
BurningJulia::BurningJulia(void *mlxPtr) : Fractal(mlxPtr, BURNING_JULIA, PINK, PATH_BURNING_JULIA, CPreset(DCo(0.92, -0.54), DCo(1.02, -0.2), DCo(0.344, -0.724), DCo(-0.216, 0.572), DCo(-0.34, -0.03), DCo(0.95, 0.12), DCo(-0.33, 0.81), DCo(-0.232, -0.58), DCo(0.88, -0.81), DCo(-0.34, -0.06)))
{
	this->_animationC.setStart(DCo(2, -2));
}

BurningJulia::BurningJulia(const BurningJulia &src) : Fractal(src) { }

BurningJulia::~BurningJulia() { }

// OPERATOR OVERLOADING --------------------------------------------------------
BurningJulia &BurningJulia::operator=(const BurningJulia &rhs)
{
	Fractal::operator=(rhs);
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
int BurningJulia::sequence(Data &data, DCo c, DCo co) const
{
	DCo	z(c);
	DCo	sqr(z, 2);
	int		i;

	sqr = DCo(z, 2);
	i = 0;
	while (i < this->_maxIter)
	{
		z.setY(fabs(2 * z.getX() * z.getY() - this->_c.getY()));
		z.setX(sqr.getX() - sqr.getY() - this->_c.getX());
		sqr = DCo(z, 2);
		if (sqr.getX() + sqr.getY() > 4)
			return (get_color(data, (t_color_data){frac, i, sqr.getX() + sqr.getY()}, \
co, z));
		i++;
	}
	return (FG);
}
