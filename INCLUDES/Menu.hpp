/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Menu.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:01:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 18:01:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
# define MENU_HPP

# include "DCo.hpp"
# include "Animation.hpp"

typedef enum ePos
{
	POS_ERROR = -1,
	POS_1,
	POS_2,
	POS_3,
	POS_4,
}			tPos;

class Menu : public Animation
{
public:
	Menu();
	Menu(const Menu &src);
	~Menu();

	Menu &operator=(const Menu &rhs);

private:
	bool	_saveImg;
	int		_start;
	int		_end;
	int		_size;
	tPos	_pos;
	DCo		_value;
	DCo		_step;
};

#endif
