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
# include "preprocessing.hpp"
# include <stdexcept>

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

class Palette
{
public:
	// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
	Palette();
	Palette(Color c1, Color c2, Color c3, Color c4, Color c5);
	Palette(const Palette &src);
	~Palette();

	// OPERATOR OVERLOADING --------------------------------------------------------
	Palette		&operator=(const Palette &rhs);
	const Color	&operator[](unsigned int i) const;

	// GETTER - SETTER -------------------------------------------------------------
	const Color	&getC1() const;
	const Color	&getC2() const;
	const Color	&getC3() const;
	const Color	&getC4() const;
	const Color	&getC5() const;

private:
	Color		_c1;
	Color		_c2;
	Color		_c3;
	Color		_c4;
	Color		_c5;
};

class PaletteAppearance
{
public:
	// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
	PaletteAppearance(Color c1, Color c2, Color c3, Color c4, Color c5);
	PaletteAppearance(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2);
	PaletteAppearance(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2, Color d3, Color d4, Color d5);
	PaletteAppearance(const PaletteAppearance &src);
	~PaletteAppearance();

	// OPERATOR OVERLOADING --------------------------------------------------------
	PaletteAppearance	&operator=(const PaletteAppearance &rhs);
	const Palette		&operator[](tAppearance i) const;

	// GETTER - SETTER -------------------------------------------------------------
	const Palette		&getLight() const;
	const Palette		&getDark() const;

private:
	PaletteAppearance();

	Palette	_light;
	Palette	_dark;
};

class Palettes
{
public:
	// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
	Palettes();
	Palettes(const Palettes &src);
	~Palettes();

	// OPERATOR OVERLOADING --------------------------------------------------------
	Palettes				&operator=(const Palettes &rhs);
	const PaletteAppearance	&operator[](tPalette i) const;

	// MEMBER FUNCTIONS ------------------------------------------------------------
	PaletteAppearance		&getPalette(Data &data, t_color_data color_data, t_bool prev_render, tAppearance *app);

	// GETTER - SETTER -------------------------------------------------------------
	const PaletteAppearance 	&getGreen() const;
	const PaletteAppearance 	&getPurple() const;
	const PaletteAppearance 	&getElectricBlue() const;
	const PaletteAppearance 	&getRed() const;
	const PaletteAppearance 	&getBlueRed() const;
	const PaletteAppearance 	&getPink() const;
	const PaletteAppearance 	&getGreenBlue() const;
	const PaletteAppearance 	&getBlueLight() const;
	const PaletteAppearance 	&getPastelPink() const;
	const PaletteAppearance 	&getNightBlue() const;
	const PaletteAppearance 	&getBlue() const;
	const PaletteAppearance 	&getYellow() const;

private:
	PaletteAppearance			_green;
	PaletteAppearance			_purple;
	PaletteAppearance			_electricBlue;
	PaletteAppearance			_red;
	PaletteAppearance			_blueRed;
	PaletteAppearance			_pink;
	PaletteAppearance			_greenBlue;
	PaletteAppearance			_blueLight;
	PaletteAppearance			_pastelPink;
	PaletteAppearance			_nightBlue;
	PaletteAppearance			_blue;
	PaletteAppearance			_yellow;
};

#endif
