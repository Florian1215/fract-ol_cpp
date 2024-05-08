/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPreset.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:09:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:09:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPRESET_HPP
# define CPRESET_HPP

# include "DCo.hpp"
# include <stdarg.h>

typedef enum ePreset
{
	PRESET_0,
	PRESET_1,
	PRESET_2,
	PRESET_3,
	PRESET_4,
	PRESET_5,
	PRESET_6,
	PRESET_7,
	PRESET_8,
	PRESET_9,
}				tPreset;

class CPreset
{
public:
	CPreset();
	CPreset(DCo pDefault);
	CPreset(DCo pDefault, DCo p1);
	CPreset(DCo pDefault, DCo p1, DCo p2);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6, DCo p7);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6, DCo p7, DCo p8);
	CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6, DCo p7, DCo p8, DCo p9);
	CPreset(const CPreset &src);
	~CPreset();

	CPreset		&operator=(const CPreset &rhs);
	DCo			&operator[](tPreset i);

private:
	tPreset	_max;
	DCo		_pDefault;
	DCo		_p1;
	DCo		_p2;
	DCo		_p3;
	DCo		_p4;
	DCo		_p5;
	DCo		_p6;
	DCo		_p7;
	DCo		_p8;
	DCo		_p9;
};



#endif
