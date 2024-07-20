/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:00:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:00:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_HPP
# define FRACTAL_HPP

# include "DCo.hpp"
# include "CPreset.hpp"
# include "Palette.hpp"
# include "Delta.hpp"
# include "Image.hpp"

# include "preprocessing.hpp"


class Data;

typedef enum eFractal
{
	MANDELBROT,
	JULIA,
	CELTIC,
	BURNING_SHIP,
	BUFFALO,
	BURNING_JULIA,
	JULIA3,
	CELTIC_MANDELBAR,
	PERPENDICULAR_CELTIC,
	HEART,
	MANDELBAR,
	CELTIC_MANDELBROT,
}					tFractals;

class Fractal
{
public:
	Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path);
	Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, Delta plan);
	Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, CPreset preset);
	Fractal(void *mlxPtr, tFractals set, tPalette color, const std::string &path, Delta plan, CPreset preset);
	Fractal(const Fractal &src);
	virtual ~Fractal();

	Fractal &operator=(const Fractal &rhs);

	virtual Color	sequence(Data &, DCo, DCo) const = 0;

protected:
	void			_initMenu();
	Color			_getColor(Data &data, int i, double op, DCo co, DCo z);

	tFractals		_set;
	tPalette		_color;
	DCo				_c;
	Delta			_animationC;
	Delta			_plan;
	Delta			_planDefault;
	Delta			_planStartHover;
	Delta			_animationPlan;
	Delta			_menu;
	int				_maxIter;
	Image			_name;
	CPreset			_preset;

private:
	Fractal();
};

#endif
