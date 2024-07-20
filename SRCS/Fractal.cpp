/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:00:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:00:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fractal.hpp"
#include "Data.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Fractal::Fractal() { }

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path) :
_set(set),
_color(color),
_plan(DCo(-2, 2), DCo(2, -2)),
_planDefault(this->_plan),
_maxIter(MAX_ITER),
_name(mlxPtr, path)
{
	this->_initMenu();
}

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, CPreset preset) :
_set(set),
_color(color),
_plan(DCo(-2, 2), DCo(2, -2)),
_planDefault(this->_plan),
_maxIter(MAX_ITER),
_name(mlxPtr, path),
_preset(preset)
{
	this->_initMenu();
}

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, Delta plan) :
_set(set),
_color(color),
_plan(plan),
_planDefault(plan),
_maxIter(MAX_ITER),
_name(mlxPtr, path)
{
	this->_initMenu();
}

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, Delta plan, CPreset preset) :
_set(set),
_color(color),
_plan(plan),
_planDefault(plan),
_maxIter(MAX_ITER),
_name(mlxPtr, path),
_preset(preset)
{
	this->_initMenu();
}

Fractal::Fractal(const Fractal &src) { *this = src; }

Fractal::~Fractal() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Fractal &Fractal::operator=(const Fractal &rhs)
{
	if (this != &rhs)
	{
		this->_set = rhs._set;
		this->_color = rhs._color;
		this->_c = rhs._c;
		this->_animationC = rhs._animationC;
		this->_plan = rhs._plan;
		this->_planDefault = rhs._planDefault;
		this->_planStartHover = rhs._planStartHover;
		this->_animationPlan = rhs._animationPlan;
		this->_menu = rhs._menu;
		this->_maxIter = rhs._maxIter;
		this->_name = rhs._name;
		this->_preset = rhs._preset;
	}
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
void	Fractal::_initMenu()
{
	this->_menu.setStart(DCo(((this->_set % 2) == 1) * HWIN, (this->_set >= 2) * HWIN));
	this->_menu.setEnd(this->_menu.getStart() + HWIN);
}

Color	Fractal::_getColor(Data &data, int i, double op, DCo co, DCo z)
{
	Color	res;

	if ((data.getBw() || data.getColor()) && ((!data.isInMenu() && \
data.getColorAnimationLineCo().getSideLine(co) < 0) || (data.isInMenu() && \
co.getX() < data.getColorAnimationLineCo().getX())))
	{
		if (data.getBw().getPrev())
			res = render_bw(data, z, true);
		else
			res = render_color(data, color_data, data->color_animation);
	}
	else if (data.getBw())
		res = render_bw(data, z, false);
	else
		res = render_color(data, color_data, false);
	return (res);
}