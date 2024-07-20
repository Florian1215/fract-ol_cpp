/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:30:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 11:30:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# include <stdexcept>
# include "DCo.hpp"
#include "Palette.hpp"

class Data;

class Color
{
public:
	Color();
	Color(int color);
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(const Color &src);
	~Color();

	// OPERATOR OVERLOADING ----------------------------------------------------
	Color			&operator=(const Color &rhs);
	bool			operator==(int rhs) const;
	operator		int() const;
	operator		unsigned int() const;

	// GETTER - SETTER ---------------------------------------------------------
	unsigned char	getR() const;
	unsigned char	getG() const;
	unsigned char	getB() const;
	void			setColor(unsigned int color);
	void			setRGB(unsigned char r, unsigned char g, unsigned char b);

	// MEMBER FUNCTIONS --------------------------------------------------------
	void			renderBW(Data &data, DCo z, bool prevRender);
	void			renderColor(Data &data, int i, double op, bool prevRender);

private:
	void			_getGradientColors(const Color &c1, int i);
	void			_getGradientPalettes(const Palette &pal, double op, int colorShade, int cat);

	unsigned int	_color;
	unsigned char	_r;
	unsigned char	_g;
	unsigned char	_b;
};

enum e_color_hex
{
	FG = 0x202020,
	WHITE = 0xFFFFFF,
};

typedef enum eAppearance
{
	LIGHT,
	DARK,
}					tAppearance;

typedef enum eBWMode
{
	OFF,
	_Y,
	_X,
}					tBWMode;

#endif
