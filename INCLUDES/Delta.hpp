/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delta.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:06:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:06:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELTA_HPP
# define DELTA_HPP

# include "DCo.hpp"

class Delta
{
public:
	Delta();
	Delta(const DCo &start, const DCo &end);
	Delta(const Delta &src);
	~Delta();

	Delta		&operator=(const Delta &rhs);

	const DCo	&getStart() const;
	const DCo	&getEnd() const;

	void		setStart(const DCo &start);
	void		setStartX(double x);
	void		setStartY(double y);
	void		setEnd(const DCo &end);
	void		setEndX(double x);
	void		setEndY(double y);

private:
	DCo			_start;
	DCo			_end;
};

#endif
