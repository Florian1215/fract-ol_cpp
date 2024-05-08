/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Slide.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:45:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 17:45:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLIDE_HPP
# define SLIDE_HPP

# include "Image.hpp"

class Slide
{
public:
	Slide(void *mlx_ptr);
	Slide(const Slide &src);
	~Slide();

	Slide &operator=(const Slide &rhs);

	void setAnimation(bool animation);

private:
	Image	_img;
	int		_side;
	int		_i;
	int		_start;
	int		_value;
	bool	_animation;
	bool	_renderImg;
};

#endif
