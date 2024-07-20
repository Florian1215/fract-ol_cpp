/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Co.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:04:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:04:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_HPP
# define COORDINATE_HPP

# include <iostream>

template <typename T>
class Coordinate
{
public:
	// CONSTRUCTOR - DESTRUCTOR ------------------------------------------------
	Coordinate() : _x(0), _y(0) { };
	Coordinate(T x, T y) : _x(x), _y(y) { };
	Coordinate(const Coordinate &src)
	{
		*this = src;
	}
	virtual ~Coordinate() { };

	// OPERATOR OVERLOADING ----------------------------------------------------
	Coordinate	&operator=(const Coordinate &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		return (*this);
	}

	// GETTER - SETTER ---------------------------------------------------------
	T				getX() const { return (this->_x); }
	T				getY() const { return (this->_y); }
	T				getSideLine(const Coordinate<T> &co) const { return ((0 - \
this->_x) * (co.getX() - 0) + ((this->_y * -1) + 0) * (co.getY() - this->_x)); }

	void			setX(T x) { this->_x = x; }
	void			setY(T y) { this->_y = y; }

	// MEMBER FUNCTIONS --------------------------------------------------------
	T				sum() { return (this->getX() + this->getY()); }

protected:
	T				_x;
	T				_y;
};

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Coordinate<T> &co)
{
	os
		<< "("
		<< co.getX()
		<< ", "
		<< co.getY()
		<< ")";
	return (os);
}

#endif
