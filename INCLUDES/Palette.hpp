/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palette.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 11:41:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALETTE_HPP
# define PALETTE_HPP

# include "Color.hpp"
# include <stdexcept>

class Palette
{
public:
	Palette(Color l1, Color l2, Color l3, Color l4, Color l5);
	Palette(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2);
	Palette(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2, Color d3, Color d4, Color d5);
	Palette(const Palette &src);
	~Palette();

	Palette	&operator=(const Palette &rhs);
	Color	&operator[](unsigned int i);

private:
	Palette();

	Color	_l1;
	Color	_l2;
	Color	_l3;
	Color	_l4;
	Color	_l5;
	Color	_d1;
	Color	_d2;
	Color	_d3;
	Color	_d4;
	Color	_d5;
};

class Palettes
{
public:
	Palettes();
	Palettes(const Palettes &src);
	~Palettes();

	Palettes	&operator=(const Palettes &rhs);
	Palettes	&operator[](unsigned int i);

private:
	Palette		_green;
	Palette		_purple;
	Palette		_electricBlue;
	Palette		_red;
	Palette		_blueRed;
	Palette		_pink;
	Palette		_greenBlue;
	Palette		_blueLight;
	Palette		_pastelPink;
	Palette		_nightBlue;
	Palette		_blue;
	Palette		_yellow;
};

typedef enum ePalette
{
	GREEN,
	PURPLE,
	ELECTRIC_BLUE,
	RED,
	BLUE_RED,
	PINK,
	GREEN_BLUE,
	BLUE_LIGHT,
	PASTEL_PINK,
	NIGHT_BLUE,
	BLUE,
	YELLOW,
}			tPalette;

#endif
