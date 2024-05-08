/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractals.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:27:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/08 14:27:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fractals.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Fractals::Fractals() { }

Fractals::Fractals(void *mlxPtr) : _mandelbrot(mlxPtr), _julia(mlxPtr), _celtic(mlxPtr), _burningShip(mlxPtr), _buffalo(mlxPtr), _burningJulia(mlxPtr), _julia3(mlxPtr), _celticMandelbar(mlxPtr), _perpendicularCeltic(mlxPtr), _heart(mlxPtr), _mandelbar(mlxPtr), _celticMandelbrot(mlxPtr) { }

Fractals::Fractals(const Fractals &src) { *this = src; }

Fractals::~Fractals() {}

// OPERATOR OVERLOADING --------------------------------------------------------
Fractals &Fractals::operator=(const Fractals &rhs)
{
	if (this != &rhs)
	{
		this->_mandelbrot = rhs._mandelbrot;
		this->_julia = rhs._julia;
		this->_celtic = rhs._celtic;
		this->_burningShip = rhs._burningShip;
		this->_buffalo = rhs._buffalo;
		this->_burningJulia = rhs._burningJulia;
		this->_julia3 = rhs._julia3;
		this->_celticMandelbar = rhs._celticMandelbar;
		this->_perpendicularCeltic = rhs._perpendicularCeltic;
		this->_heart = rhs._heart;
		this->_mandelbar = rhs._mandelbar;
		this->_celticMandelbrot = rhs._celticMandelbrot;
	}
	return (*this);
}

Fractal &Fractals::operator[](tFractals i)
{
	switch (i)
	{
		case MANDELBROT:
			return (this->_mandelbrot);
		case JULIA:
			return (this->_julia);
		case CELTIC:
			return (this->_celtic);
		case BURNING_SHIP:
			return (this->_burningShip);
		case BUFFALO:
			return (this->_buffalo);
		case BURNING_JULIA:
			return (this->_burningJulia);
		case JULIA3:
			return (this->_julia3);
		case CELTIC_MANDELBAR:
			return (this->_celticMandelbar);
		case PERPENDICULAR_CELTIC:
			return (this->_perpendicularCeltic);
		case HEART:
			return (this->_heart);
		case MANDELBAR:
			return (this->_mandelbar);
		case CELTIC_MANDELBROT:
			return (this->_celticMandelbrot);
		default:
			throw (std::runtime_error(IDX_ERROR));
	}
}
