/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPreset.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:09:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:09:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "CPreset.hpp"

// CONSTRUCTOR - DESTRUCTOR ----------------------------------------------------
CPreset::CPreset() : _max(PRESET_0) { }

CPreset::CPreset(DCo pDefault) : _max(PRESET_0), _pDefault(pDefault) { }


CPreset::CPreset(DCo pDefault, DCo p1) : _max(PRESET_1), _pDefault(pDefault), _p1(p1) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2) : _max(PRESET_2), _pDefault(pDefault), _p1(p1), _p2(p2) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3) : _max(PRESET_3), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4) : _max(PRESET_4), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3), _p4(p4) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5) : _max(PRESET_5), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3), _p4(p4), _p5(p5) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6) : _max(PRESET_6), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3), _p4(p4), _p5(p5), _p6(p6) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6, DCo p7) : _max(PRESET_7), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3), _p4(p4), _p5(p5), _p6(p6), _p7(p7) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6, DCo p7, DCo p8) : _max(PRESET_8), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3), _p4(p4), _p5(p5), _p6(p6), _p7(p7), _p8(p8) { }


CPreset::CPreset(DCo pDefault, DCo p1, DCo p2, DCo p3, DCo p4, DCo p5, DCo p6, DCo p7, DCo p8, DCo p9) : _max(PRESET_9), _pDefault(pDefault), _p1(p1), _p2(p2), _p3(p3), _p4(p4), _p5(p5), _p6(p6), _p7(p7), _p8(p8), _p9(p9) { }

CPreset::CPreset(const CPreset &src) { *this = src; }

CPreset::~CPreset() { }

// OPERATOR OVERLOADING --------------------------------------------------------
CPreset &CPreset::operator=(const CPreset &rhs)
{
	if (this != &rhs)
	{
		this->_max = rhs._max;
		this->_pDefault = rhs._pDefault;
		this->_p1 = rhs._p1;
		this->_p2 = rhs._p2;
		this->_p3 = rhs._p3;
		this->_p4 = rhs._p4;
		this->_p5 = rhs._p5;
		this->_p6 = rhs._p6;
		this->_p7 = rhs._p7;
		this->_p8 = rhs._p8;
		this->_p9 = rhs._p9;
	}
	return (*this);
}

DCo			&CPreset::operator[](tPreset i)
{
	if (i > this->_max)
		throw ;
	switch (i)
	{
		case PRESET_0:
			return (this->_pDefault);
		case PRESET_1:
			return (this->_p1);
		case PRESET_2:
			return (this->_p2);
		case PRESET_3:
			return (this->_p3);
		case PRESET_4:
			return (this->_p4);
		case PRESET_5:
			return (this->_p5);
		case PRESET_6:
			return (this->_p6);
		case PRESET_7:
			return (this->_p7);
		case PRESET_8:
			return (this->_p8);
		case PRESET_9:
			return (this->_p9);
	}
}

