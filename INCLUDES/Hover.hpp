/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hover.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:26:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 10:26:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOVER_HPP
# define HOVER_HPP

# include "Animation.hpp"

class HoverValue
{
public:
	HoverValue();
	HoverValue(const HoverValue &src);
	~HoverValue();

	HoverValue &operator=(const HoverValue &rhs);

private:
	double	_value;
	double	_start;
	double	_end;
};

class Hover : public Animation
{
public:
	Hover();
	Hover(const Hover &src);
	~Hover();

	Hover		&operator=(const Hover &rhs);

private:
	HoverValue	_zoom;
	HoverValue	_max_iter;
	bool		_hover;
	bool		_unhover;
	bool		_isActive;
};

#endif
