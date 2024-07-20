/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BurningShip.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:18:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:18:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BURNINGSHIP_HPP
# define BURNINGSHIP_HPP

# include "Fractal.hpp"

class BurningShip : public Fractal
{
public:
	BurningShip(void *mlxPtr);
	BurningShip(const BurningShip &src);
	~BurningShip();

	BurningShip &operator=(const BurningShip &rhs);

	Color sequence(Data &data, DCo c, DCo co) const;

private:
	BurningShip();
};

#endif