/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:10:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:10:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_HPP
# define IMAGE_HPP

# include <string>
# include "preprocessing.hpp"

class Image
{
public:
	Image();
	Image(void *mlx_ptr);
	Image(void *mlx_ptr, const std::string &path);
	Image(const Image &src);
	~Image();

	Image &operator=(const Image &rhs);

private:
	void		initValue();

	void		*_mlxPtr;
	std::string	_path;
	void		*_img;
	char		*_addr;
	int			_bitsPerPixel;
	int			_lineLength;
	int			_bitRatio;
	int			_endian;
	int			_width;
	int			_height;
};

#endif
