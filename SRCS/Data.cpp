/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:34:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:34:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Data::Data() : _mlxPtr(mlx_init()),
_winPtr(mlx_new_window(this->_mlxPtr, WIN, WIN, const_cast<char *>(std::string(PROJECT_NAME).c_str()))),
_img(this->_mlxPtr), _fractals(this->_mlxPtr), _f(this->_fractals[MANDELBROT]),
_offsetColor(0), _page(0), _appearance(LIGHT), _renderLevel(_100),
_lastRender(0), _prevRender(false), _inMenu(true), _slide(this->_mlxPtr),
_isKeyBuff(false)
{
	this->stopAnimation();
	pthread_mutex_init(&this->_mutexLine, NULL);
}

Data::Data(const Data &src) : _winPtr(NULL), _img(src._mlxPtr), _fractals(src._mlxPtr), _f(this->_fractals[MANDELBROT]), _slide(src._mlxPtr) { *this = src; }

Data::~Data() { }

// OPERATOR OVERLOADING --------------------------------------------------------
Data &Data::operator=(const Data &rhs)
{
	if (this != &rhs)
	{
		this->_mlxPtr = rhs._mlxPtr;
		if (this->_winPtr)
			mlx_destroy_window(this->_mlxPtr, this->_winPtr);
		this->_winPtr = mlx_new_window(this->_mlxPtr, WIN, WIN, const_cast<char *>(std::string(PROJECT_NAME).c_str()));
		this->_img = rhs._img;
		this->_hover[POS_1] = rhs._hover[POS_1];
		this->_hover[POS_2] = rhs._hover[POS_2];
		this->_hover[POS_3] = rhs._hover[POS_3];
		this->_hover[POS_4] = rhs._hover[POS_4];
		this->_menus[POS_1] = rhs._menus[POS_1];
		this->_menus[POS_2] = rhs._menus[POS_2];
		this->_menus[POS_3] = rhs._menus[POS_3];
		this->_menus[POS_4] = rhs._menus[POS_4];
		this->_fractals = rhs._fractals;
		this->_f = rhs._f;
		this->_color = rhs._color;
		this->_prevPos = rhs._prevPos;
		this->_offsetColor = rhs._offsetColor;
		this->_page = rhs._page;
		this->_editC = rhs._editC;
		this->_c = rhs._c;
		this->_appearance = rhs._appearance;
		this->_animAppearance = rhs._animAppearance;
		this->_bw = rhs._bw;
		this->_colorAnimationLineCo = rhs._colorAnimationLineCo;
		this->_renderLevel = rhs._renderLevel;
		this->_lastRender = rhs._lastRender;
		this->_prevRender = rhs._prevRender;
		this->_reset = rhs._reset;
		this->_moving = rhs._moving;
		this->_inMenu = rhs._inMenu;
		this->_slide = rhs._slide;
		this->_edit = rhs._edit;
		this->_update = rhs._update;
		this->_zoomSize = rhs._zoomSize;
		this->_pal = rhs._pal;
		this->_menu = rhs._menu;
		this->_keyBuff = rhs._keyBuff;
		this->_isKeyBuff = rhs._isKeyBuff;
		pthread_mutex_init(&this->_mutexLine, NULL);
	}
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
void	Data::stopAnimation()
{
	this->_reset = false;
	this->_moving = false;
	this->_edit = false;
	this->_update = false;
	this->_editC = false;
	this->_slide.setAnimation(false);
	this->_zoomSize = false;
	this->_c.setAnimation(false);
	this->_color.setAnimation(false);
	this->_bw.setAnimation(false);
}

// GETTER - SETTER -------------------------------------------------------------
void	*Data::getMlxPtr() const
{
	return _mlxPtr;
}
