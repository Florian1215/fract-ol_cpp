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

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path) : _set(set), _color(color), _plan(DCo(-2, 2), DCo(2, -2)), _planDefault(this->_plan), _menu(DCo(((set % 2) == 1) * HWIN, (set >= 2) * HWIN), this->_menu.getStart() + HWIN), _maxIter(MAX_ITER), _name(mlxPtr, path) { }

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, CPreset preset) : _set(set), _color(color), _plan(DCo(-2, 2), DCo(2, -2)), _planDefault(this->_plan), _menu(DCo(((set % 2) == 1) * HWIN, (set >= 2) * HWIN), this->_menu.getStart() + HWIN), _maxIter(MAX_ITER), _name(mlxPtr, path), _preset(preset) { }

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, Delta plan) : _set(set), _color(color), _plan(plan), _planDefault(plan), _menu(DCo(((set % 2) == 1) * HWIN, (set >= 2) * HWIN), this->_menu.getStart() + HWIN), _maxIter(MAX_ITER), _name(mlxPtr, path) { }

Fractal::Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, Delta plan, CPreset preset) : _set(set), _color(color), _plan(plan), _planDefault(plan), _menu(DCo(((set % 2) == 1) * HWIN, (set >= 2) * HWIN), this->_menu.getStart() + HWIN), _maxIter(MAX_ITER), _name(mlxPtr, path), _preset(preset) { }

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
