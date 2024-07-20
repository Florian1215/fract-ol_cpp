/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractals.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:27:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/08 14:27:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_HPP
# define FRACTALS_HPP

# include "Mandelbrot.hpp"
# include "Julia.hpp"
# include "Celtic.hpp"
# include "BurningShip.hpp"
# include "Buffalo.hpp"
# include "BurningJulia.hpp"
# include "Julia3.hpp"
# include "CelticMandelbar.hpp"
# include "PerpendicularCeltic.hpp"
# include "Heart.hpp"
# include "Mandelbar.hpp"
# include "CelticMandelbar.hpp"

class Fractals
{
public:
	Fractals(void *mlxPtr);
	Fractals(const Fractals &src);
	~Fractals();

	Fractals	&operator=(const Fractals &rhs);
	Fractal		&operator[](tFractals i);

protected:
	void				*_mlxPtr;
	Mandelbrot			_mandelbrot;
	Julia				_julia;
	Celtic				_celtic;
	BurningShip			_burningShip;
	Buffalo				_buffalo;
	BurningJulia		_burningJulia;
	Julia3				_julia3;
	CelticMandelbar		_celticMandelbar;
	PerpendicularCeltic	_perpendicularCeltic;
	Heart				_heart;
	Mandelbar			_mandelbar;
	CelticMandelbar		_celticMandelbrot;
};

#endif
