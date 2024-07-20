/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animation.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:02:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 11:02:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_HPP
# define ANIMATION_HPP

class Animation
{
public:
	// CONSTRUCTOR - DESTRUCTOR ------------------------------------------------
	Animation();
	Animation(const Animation &src);
	~Animation();

	// OPERATOR OVERLOADING ----------------------------------------------------
	// TODO overload operator ++, than execute func
	Animation	&operator=(const Animation &rhs);
	bool		operator<(int rhs) const;
	bool		operator<=(int rhs) const;
	bool		operator>(int rhs) const;
	bool		operator>=(int rhs) const;
	operator	bool() const;

	// GETTER - SETTER ---------------------------------------------------------
	int			getI() const;
	void		setAnimation(bool isAnimation);

protected:
	bool		_isAnimation;
	int			_i;
};

class AnimationValue : public Animation
{
public:
	// CONSTRUCTOR - DESTRUCTOR ------------------------------------------------
	AnimationValue();
	AnimationValue(int curr);
	AnimationValue(const AnimationValue &src);
	~AnimationValue();

	// OPERATOR OVERLOADING ----------------------------------------------------
	AnimationValue	&operator=(const AnimationValue &rhs);
	bool			operator==(int rhs) const;

	// GETTER - SETTER ---------------------------------------------------------
	int				getCurr() const;
	int				getPrev() const;

private:
	int				_curr;
	int				_prev;
};

#endif
