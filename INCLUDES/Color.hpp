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

class Color
{
public:
	Color(int color);
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(const Color &src);
	~Color();

	Color &operator=(const Color &rhs);

private:
	Color();

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
