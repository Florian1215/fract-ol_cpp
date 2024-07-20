/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Palette.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 11:41:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Palette.hpp"
#include "Data.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Palette::Palette() : _c1(0), _c2(0), _c3(0), _c4(0), _c5(0) { }

Palette::Palette(Color c1, Color c2, Color c3, Color c4, Color c5) : _c1(c1), _c2(c2), _c3(c3), _c4(c4), _c5(c5) { }

Palette::Palette(const Palette &src) : _c1(c1), _c2(c2), _c3(c3), _c4(c4), _c5(c5) { }

Palette::~Palette() { }

PaletteAppearance::PaletteAppearance() {}

PaletteAppearance::PaletteAppearance(Color c1, Color c2, Color c3, Color c4, Color c5) : _light(c1, c2, c3, c4, c5), _dark(FG, c2, c3, c4, c5) { }

PaletteAppearance::PaletteAppearance(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2) : _light(l1, l2, l3, l4, l5), _dark(FG, d2, l3, l4, l5) { }

PaletteAppearance::PaletteAppearance(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2, Color d3, Color d4, Color d5) : _light(l1, l2, l3, l4, l5), _dark(FG, d2, d3, d4, d5) { }

PaletteAppearance::PaletteAppearance(const PaletteAppearance &src) : _light(src._light), _dark(src._dark) { }

PaletteAppearance::~PaletteAppearance() { }


Palettes::Palettes() :
_green(0x468966, 0xFFF0A5, 0xFFB03B, 0xB64926, 0x8E2800, 0x295E52),
_purple(0x23254C, 0xB6696A, 0xE8ECF4, 0xE1E2E5, 0xE7CE8C),
_electricBlue(0x2A4858, 0x007882, 0x23AA8F, 0x86D780, 0xFAFA6E),
_red(0xF45D4C, 0xF7A541, 0xFACA66, 0xFEE5AD, 0xA1DBB2, 0x374140, 0x817A63, 0xD9CB9E, 0xDC3522),
_blueRed(0x00748E, 0xE3DFBB, 0xF4BA4D, 0xE3753C, 0xDA3B3A, 0x263248, 0x7E8AA2, 0xE3DFBB, 0xF0642A),
_pink(0xEE7788, 0xFFCCCC, 0xFF99AA, 0xCC4466, 0x441122, 0x333F58, 0x4A7A96, 0xEE8695, 0xFBBBAD),
_greenBlue(0xBEE4C2, 0xE2F3E4, 0x94E344, 0x46878F, 0x332C50),
_blueLight(0xF0EFF4, 0x8ECDE6, 0x66A1FF, 0x6B61FF, 0xFADDA2),
_pastelPink(0xD8BFD8, 0xFFB3CB, 0xF7FFAE, 0x96FBC7, 0x74569B),
_nightBlue(0x272744, 0x494D7E, 0xC69FA5, 0xF2D3AB, 0xFBF5EF),
_blue(0xF7FFED, 0xB5F5EC, 0x5BACE3, 0x636AB8, 0x574175, 0x82C9FF),
_yellow(0xF5E5BF, 0xE8AD80, 0xCF784C, 0xAD5845, 0x73383E) { }

Palettes::Palettes(const Palettes &src) : _green(src._green), _purple(src._purple), _electricBlue(src._electricBlue), _red(src._red), _blueRed(src._blueRed), _pink(src._pink), _greenBlue(src._greenBlue), _blueLight(src._blueLight), _pastelPink(src._pastelPink), _nightBlue(src._nightBlue), _blue(src._blue), _yellow(src._yellow) { }

Palettes::~Palettes() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Palette &Palette::operator=(const Palette &rhs)
{
	if (this != &rhs)
	{
		this->_c1 = rhs._c1;
		this->_c2 = rhs._c2;
		this->_c3 = rhs._c3;
		this->_c4 = rhs._c4;
		this->_c5 = rhs._c5;
	}
	return (*this);
}

const Color &Palette::operator[](unsigned int i) const
{
	switch (i)
	{
		case 0:
			return (this->getC1());
		case 1:
			return (this->getC2());
		case 2:
			return (this->getC3());
		case 3:
			return (this->getC4());
		case 4:
			return (this->getC5());
		default:
			throw std::runtime_error(IDX_ERROR);
	}
}


PaletteAppearance &PaletteAppearance::operator=(const PaletteAppearance &rhs)
{
	if (this != &rhs)
	{
		this->_light = rhs._light;
		this->_dark = rhs._dark;
	}
	return (*this);
}

const Palette &PaletteAppearance::operator[](tAppearance i) const
{
	switch (i)
	{
		case LIGHT:
			return (this->getLight());
		case DARK:
			return (this->getDark());
	}
}


Palettes &Palettes::operator=(const Palettes &rhs)
{
	if (this != &rhs)
	{
		this->_green = rhs._green;
		this->_purple = rhs._purple;
		this->_electricBlue = rhs._electricBlue;
		this->_red = rhs._red;
		this->_blueRed = rhs._blueRed;
		this->_pink = rhs._pink;
		this->_greenBlue = rhs._greenBlue;
		this->_blueLight = rhs._blueLight;
		this->_pastelPink = rhs._pastelPink;
		this->_nightBlue = rhs._nightBlue;
		this->_blue = rhs._blue;
		this->_yellow = rhs._yellow;
	}
	return (*this);
}

const PaletteAppearance &Palettes::operator[](tPalette i) const
{
	switch (i)
	{
		case GREEN:
			return (this->getGreen());
		case PURPLE:
			return (this->getPurple());
		case ELECTRIC_BLUE:
			return (this->getElectricBlue());
		case RED:
			return (this->getRed());
		case BLUE_RED:
			return (this->getBlueRed());
		case PINK:
			return (this->getPink());
		case GREEN_BLUE:
			return (this->getGreenBlue());
		case BLUE_LIGHT:
			return (this->getBlueLight());
		case PASTEL_PINK:
			return (this->getPastelPink());
		case NIGHT_BLUE:
			return (this->getNightBlue());
		case BLUE:
			return (this->getBlue());
		case YELLOW:
			return (this->getYellow());
	}
}

// GETTER - SETTER -------------------------------------------------------------
const Color &Palette::getC1() const { return (this->_c1); }
const Color &Palette::getC2() const { return (this->_c2); }
const Color &Palette::getC3() const { return (this->_c3); }
const Color &Palette::getC4() const { return (this->_c4); }
const Color &Palette::getC5() const { return (this->_c5); }

const Palette &PaletteAppearance::getLight() const { return (this->_light); }
const Palette &PaletteAppearance::getDark() const { return (this->_dark); }

const PaletteAppearance &Palettes::getGreen() const { return (this->_green); }
const PaletteAppearance &Palettes::getPurple() const { return (this->_purple); }
const PaletteAppearance &Palettes::getElectricBlue() const { return (this->_electricBlue); }
const PaletteAppearance &Palettes::getRed() const { return (this->_red); }
const PaletteAppearance &Palettes::getBlueRed() const { return (this->_blueRed); }
const PaletteAppearance &Palettes::getPink() const { return (this->_pink); }
const PaletteAppearance &Palettes::getGreenBlue() const { return (this->_greenBlue); }
const PaletteAppearance &Palettes::getBlueLight() const { return (this->_blueLight); }
const PaletteAppearance &Palettes::getPastelPink() const { return (this->_pastelPink); }
const PaletteAppearance &Palettes::getNightBlue() const { return (this->_nightBlue); }
const PaletteAppearance &Palettes::getBlue() const { return (this->_blue); }
const PaletteAppearance &Palettes::getYellow() const { return (this->_yellow); }


// MEMBER FUNCTIONS ------------------------------------------------------------
Palette		&Palettes::getPalette(Data &data, t_color_data color_data, t_bool prev_render, tAppearance *app)
{
	tPalette	set;

	if (data.isInMenu() || data.getMenu())
	{
		if (prev_render)
			set = (color_data.frac->color + data.getOffsetColor() - 1) % 12;
		else
			set = (color_data.frac->color + data.getOffsetColor()) % 12;
	}
	else
	{
		if (prev_render)
		{
			set = static_cast<tPalette>(data.getColor().getPrev());
			if (data.getAppearance() && data.getAppearance() < data.getColor())
				*app = static_cast<tAppearance>(!*app);
		}
		else
			set = static_cast<tPalette>(data.getColor().getCurr());
	}
	return ((*this)[set]);
}
