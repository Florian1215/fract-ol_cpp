/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BurningJulia.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BURNINGJULIA_HPP
# define BURNINGJULIA_HPP

# include "Fractal.hpp"

class BurningJulia : public Fractal
{
public:
	BurningJulia(void *mlxPtr);

	BurningJulia(const BurningJulia &src);

	~BurningJulia();

	BurningJulia &operator=(const BurningJulia &rhs);

	int sequence(Data &data, DCo c, DCo co) const;

private:
	BurningJulia();
};

#endif