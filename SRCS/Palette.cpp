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

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
	// PALETTE
Palette::Palette() : _l1(0), _l2(0), _l3(0), _l4(0), _l5(0), _d1(0), _d2(0), _d3(0), _d4(0), _d5(0) { }

Palette::Palette(Color l1, Color l2, Color l3, Color l4, Color l5) : _l1(l1), _l2(l2), _l3(l3), _l4(l4), _l5(l5), _d1(FG), _d2(l2), _d3(l3), _d4(l4), _d5(l5) { }

Palette::Palette(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2) : _l1(l1), _l2(l2), _l3(l3), _l4(l4), _l5(l5), _d1(FG), _d2(d2), _d3(l3), _d4(l4), _d5(l5) { }

Palette::Palette(Color l1, Color l2, Color l3, Color l4, Color l5, Color d2, Color d3, Color d4, Color d5) : _l1(l1), _l2(l2), _l3(l3), _l4(l4), _l5(l5), _d1(FG), _d2(d2), _d3(d3), _d4(d4), _d5(d5) { }

Palette::Palette(const Palette &src) : _l1(src._l1), _l2(src._l2), _l3(src._l3), _l4(src._l4), _l5(src._l5), _d1(src._d1), _d2(src._d2), _d3(src._d3), _d4(src._d4), _d5(src._d5) { }

Palette::~Palette() { }

	// PALETTES
Palettes::Palettes() :
_green(Palette(0x468966, 0xFFF0A5, 0xFFB03B, 0xB64926, 0x8E2800, 0x295E52)),
_purple(Palette(0x23254C, 0xB6696A, 0xE8ECF4, 0xE1E2E5, 0xE7CE8C)),
_electricBlue(Palette(0x2A4858, 0x007882, 0x23AA8F, 0x86D780, 0xFAFA6E)),
_red(Palette(0xF45D4C, 0xF7A541, 0xFACA66, 0xFEE5AD, 0xA1DBB2, 0x374140, 0x817A63, 0xD9CB9E, 0xDC3522)),
_blueRed(Palette(0x00748E, 0xE3DFBB, 0xF4BA4D, 0xE3753C, 0xDA3B3A, 0x263248, 0x7E8AA2, 0xE3DFBB, 0xF0642A)),
_pink(Palette(0xEE7788, 0xFFCCCC, 0xFF99AA, 0xCC4466, 0x441122, 0x333F58, 0x4A7A96, 0xEE8695, 0xFBBBAD)),
_greenBlue(Palette(0xBEE4C2, 0xE2F3E4, 0x94E344, 0x46878F, 0x332C50)),
_blueLight(Palette(0xF0EFF4, 0x8ECDE6, 0x66A1FF, 0x6B61FF, 0xFADDA2)),
_pastelPink(Palette(0xD8BFD8, 0xFFB3CB, 0xF7FFAE, 0x96FBC7, 0x74569B)),
_nightBlue(Palette(0x272744, 0x494D7E, 0xC69FA5, 0xF2D3AB, 0xFBF5EF)),
_blue(Palette(0xF7FFED, 0xB5F5EC, 0x5BACE3, 0x636AB8, 0x574175, 0x82C9FF)),
_yellow(Palette(0xF5E5BF, 0xE8AD80, 0xCF784C, 0xAD5845, 0x73383E)) { }

Palettes::Palettes(const Palettes &src) : _green(src._green), _purple(src._purple), _electricBlue(src._electricBlue), _red(src._red), _blueRed(src._blueRed), _pink(src._pink), _greenBlue(src._greenBlue), _blueLight(src._blueLight), _pastelPink(src._pastelPink), _nightBlue(src._nightBlue), _blue(src._blue), _yellow(src._yellow) { }

Palettes::~Palettes() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Palette &Palette::operator=(const Palette &rhs)
{
	if (this != &rhs)
	{
		this->_l1 = rhs._l1;
		this->_l2 = rhs._l2;
		this->_l3 = rhs._l3;
		this->_l4 = rhs._l4;
		this->_l5 = rhs._l5;
		this->_d1 = rhs._d1;
		this->_d2 = rhs._d2;
		this->_d3 = rhs._d3;
		this->_d4 = rhs._d4;
		this->_d5 = rhs._d5;
	}
	return (*this);
}

Color &Palette::operator[](unsigned int i)
{
	switch (i)
	{
		case 0:
			return (this->_l1);
		case 1:
			return (this->_l2);
		case 2:
			return (this->_l3);
		case 3:
			return (this->_l4);
		case 4:
			return (this->_l5);
		default:
			throw std::runtime_error(IDX_ERROR);
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
