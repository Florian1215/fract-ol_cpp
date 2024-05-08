/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbar.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBAR_HPP
# define MANDELBAR_HPP

# include "Fractal.hpp"

class Mandelbar : public Fractal
{
public:
	Mandelbar(void *mlxPtr);

	Mandelbar(const Mandelbar &src);

	~Mandelbar();

	Mandelbar &operator=(const Mandelbar &rhs);

	int sequence(Data &data, DCo c, DCo co) const;

private:
	Mandelbar();
};

#endif