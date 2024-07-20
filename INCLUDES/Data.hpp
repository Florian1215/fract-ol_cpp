/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:34:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:34:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include "Fractal.hpp"
# include "Slide.hpp"
# include "Menu.hpp"
# include "Hover.hpp"
# include "Animation.hpp"
# include "Colors.hpp"
# include "Fractals.hpp"

# include "preprocessing.hpp"

# include <vector>

typedef unsigned long long int	tTime;

typedef enum eLevel
{
	_100 = 1,
	_50 = 2,
	_25 = 3,
}								tLevel;

class Data
{
public:
	// CONSTRUCTOR - DESTRUCTOR ------------------------------------------------
	Data();
	Data(const Data &src);
	~Data();

	// OPERATOR OVERLOADING ----------------------------------------------------
	Data						&operator=(const Data &rhs);

	// GETTER - SETTER ---------------------------------------------------------
	void						*getMlxPtr() const;
	const AnimationValue		&getBw() const;
	const AnimationValue		&getColor() const;
	const AnimationValue		&getAppearance() const;
	int 						getOffsetColor() const;
	bool						isInMenu() const;
	const DCo					&getColorAnimationLineCo() const;
	const Palettes				&getPal() const;
	const Menu					&getMenu() const;

private:
	void						stopAnimation();

	void						*_mlxPtr;
	void						*_winPtr;
	Image						_img;
	Hover						_hover[4];
	tFractals					_menus[4];
	Fractals					_fractals;
	Fractal						&_f;
	AnimationValue				_color;
	DCo							_prevPos;
	int							_offsetColor;
	int							_page;
	bool						_editC;
	Animation					_c;
	AnimationValue				_appearance;
	AnimationValue				_bw;
	DCo							_colorAnimationLineCo;
	tLevel						_renderLevel;
	tTime						_lastRender;
	bool						_prevRender;
	bool						_reset;
	bool						_moving;
	bool						_inMenu;
	Slide						_slide;
	bool						_edit;
	bool						_update;
	bool						_zoomSize;
	Palettes					_pal;
	Menu						_menu;
	std::vector<int>			_keyBuff;
	bool						_isKeyBuff;
	pthread_mutex_t				_mutexLine;
};

double							getValue(double a, double b, int i);

#endif
