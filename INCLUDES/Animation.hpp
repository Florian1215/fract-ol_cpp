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
	Animation();
	Animation(const Animation &src);
	~Animation();

	// TODO overload operator ++, than execute func
	Animation &operator=(const Animation &rhs);

	void setAnimation(bool isAnimation);

protected:
	bool	_isAnimation;
	int		_i;
};

class AnimationValue : public Animation
{
public:
	AnimationValue();
	AnimationValue(const AnimationValue &src);
	~AnimationValue();

	AnimationValue			&operator=(const AnimationValue &rhs);

private:
	unsigned int	_curr;
	unsigned int	_prev;
};

#endif
