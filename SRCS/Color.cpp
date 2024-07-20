/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:30:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 11:30:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Data.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Color::Color() : _color(0), _r(0),  _g(0),  _b(0) { }
Color::Color(int color) { setColor(color); }
Color::Color(unsigned char r, unsigned char g, unsigned char b) { setRGB(r, g, b); }
Color::Color(const Color &src) { *this = src; }
Color::~Color() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Color &Color::operator=(const Color &rhs)
{
	if (this != &rhs)
	{
		this->_color = rhs._color;
		this->_r = rhs._r;
		this->_g = rhs._g;
		this->_b = rhs._b;
	}
	return (*this);
}

bool	Color::operator==(int rhs) const { return (this->_color == static_cast<unsigned int>(rhs)); }
Color::operator		int() const { return (static_cast<int>(this->_color)); }
Color::operator		unsigned int() const { return (this->_color); }

// GETTER - SETTER -------------------------------------------------------------
unsigned char	Color::getR() const { return (this->_r); }
unsigned char	Color::getG() const { return (this->_g); }
unsigned char	Color::getB() const { return (this->_b); }

void Color::setColor(unsigned int color)
{
	this->_color = color;
	this->_r = color >> 16;
	this->_g = color >> 8;
	this->_b = color;
}

void Color::setRGB(unsigned char r, unsigned char g, unsigned char b)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_color = (r << 16) + (g << 8) + b;
}

// MEMBER FUNCTIONS ------------------------------------------------------------
void	Color::renderBW(Data &data, DCo z, bool prevRender)
{
	tBWMode	mode;

	if (prevRender)
		mode = static_cast<tBWMode>(data.getBw().getPrev());
	else
		mode = static_cast<tBWMode>(data.getBw().getCurr());
	if ((data.getAppearance() == LIGHT && ((mode == _X && z.getX() > 0) || (\
mode == _Y && z.getY() > 0))) || (data.getAppearance() == DARK && ((mode == _X && \
z.getX() < 0) || (mode == _Y && z.getY() < 0))))
		*this = Color(FG);
	else
		*this = Color(WHITE);
	if (data.getAppearance())
	{
		if (*this == FG)
			this->_getGradientColors(Color(WHITE), data.getAppearance().getI());
		else
			this->_getGradientColors(Color(FG), data.getAppearance().getI());
	}
}

void	Color::renderColor(Data &data, int i, double op, bool prevRender)
{
	int						colorShade;
	int						cat;
	tAppearance				app;
	Palette					palette;

	op = 1 + ((log(log(2)) - log((0.5 * log(color_data.sqr)))) / log(2));
	if (op > 0.9999)
		op = 0.9999;
	if (op < 0)
		op = 0;
	op += i;
	cat = color_data.frac->max_iter / 4;
	if (!cat)
		cat = 1;
	colorShade = i / cat;
	if (colorShade < 0)
		colorShade = 0;
	else if (colorShade >= 4)
		colorShade = 3;
	app = static_cast<tAppearance>(data.getAppearance().getCurr());
	palette = data.getPal().getPalette();
	this->_getGradientPalettes(palette[app], op, colorShade, cat);
	if (data.getAppearance() && app == data.getAppearance())
		this->_getGradientColors(this->_getGradientPalettes(palette[!data.getAppearance()], op, colorShade, cat), data.getAppearance().getI());
}

void	Color::_getGradientColors(const Color &c1, int i) { this->setRGB(getValue(c1.getR(), this->_r, i), getValue(c1.getG(), this->_g, i), getValue(c1.getB(), this->_b, i)); }

void	Color::_getGradientPalettes(const Palette &pal, double op, int colorShade, int cat)
{
	this->setRGB(
		pal[colorShade].getR() + ((pal[colorShade + 1].getR() - pal[colorShade].getR()) * ((op - cat * colorShade) / cat)),
		pal[colorShade].getG() + ((pal[colorShade + 1].getG() - pal[colorShade].getG()) * ((op - cat * colorShade) / cat)),
		pal[colorShade].getB() + ((pal[colorShade + 1].getB() - pal[colorShade].getB()) * ((op - cat * colorShade) / cat))
	);
}
