/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:10:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:10:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Image.hpp"
#include "preprocessing.hpp"

// TODO secure create img
// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
Image::Image() : _img(NULL) { }

Image::Image(void *mlx_ptr) : _mlxPtr(mlx_ptr), _width(WIN), _height(WIN)
{
	this->initValue();
}

Image::Image(void *mlx_ptr, const std::string &path) : _mlxPtr(mlx_ptr), _path(path)
{
	this->initValue();
}

Image::Image(const Image &src) : _path(src._path) { *this = src; }

Image::~Image()
{
	mlx_destroy_image(this->_mlxPtr, this->_img);
}

// OPERATOR OVERLOADING --------------------------------------------------------

// TODO secure
Image &Image::operator=(const Image &rhs)
{
	if (this != &rhs)
	{
		if (this->_img)
			mlx_destroy_image(this->_mlxPtr, this->_img);
		this->_mlxPtr = rhs._mlxPtr;
		this->_width = rhs._width;
		this->_height = rhs._height;
		initValue();
	}
	return (*this);
}

// MEMBER FUNCTIONS ------------------------------------------------------------
void		Image::initValue()
{
	if (this->_path.empty())
		this->_img = mlx_new_image(this->_mlxPtr, WIN, WIN);
	else
		this->_img = mlx_xpm_file_to_image(this->_mlxPtr, \
const_cast<char *>(this->_path.c_str()), &this->_width, &this->_height);
	this->_addr = mlx_get_data_addr(this->_img, &this->_bitsPerPixel, \
&this->_lineLength, &this->_endian);
	this->_bitRatio = this->_bitsPerPixel / 8;
}