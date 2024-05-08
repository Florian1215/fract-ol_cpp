/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DCo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:29:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:29:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCO_HPP
# define DCO_HPP

# include "Coordinate.hpp"

class DCo : public Coordinate<double>
{
public:
	DCo();
	DCo(double x, double y);
	DCo(const DCo &c, int pow);
	DCo(const DCo &src);
	~DCo();

	DCo			&operator=(const DCo &rhs);
	DCo			operator+(int value) const;

private:
};

std::ostream	&operator<<(std::ostream &os, const DCo &co);

#endif
