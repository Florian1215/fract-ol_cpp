/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerpendicularCeltic.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERPENDICULARCELTIC_HPP
# define PERPENDICULARCELTIC_HPP

# include "Fractal.hpp"

class PerpendicularCeltic : public Fractal
{
public:
	PerpendicularCeltic(void *mlxPtr);

	PerpendicularCeltic(const PerpendicularCeltic &src);

	~PerpendicularCeltic();

	PerpendicularCeltic &operator=(const PerpendicularCeltic &rhs);

	Color	sequence(Data &data, DCo c, DCo co) const;

private:
	PerpendicularCeltic();
};

#endif