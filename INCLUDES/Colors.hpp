/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:11:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 11:11:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
# define COLORS_HPP

# include "Animation.hpp"
# include "Palette.hpp"

class Colors : public Animation
{
public:
	Colors();
	Colors(const Colors &src);
	~Colors();

	Colors		&operator=(const Colors &rhs);

private:
	tPalette	_color;
	tPalette	_prevColor;
};

#endif
