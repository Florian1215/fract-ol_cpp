/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CelticMandelbar.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELTICMANDELBAR_HPP
# define CELTICMANDELBAR_HPP

# include "Fractal.hpp"

class CelticMandelbar : public Fractal
{
public:
	CelticMandelbar(void *mlxPtr);

	CelticMandelbar(const CelticMandelbar &src);

	~CelticMandelbar();

	CelticMandelbar &operator=(const CelticMandelbar &rhs);

	int sequence(Data &data, DCo c, DCo co) const;

private:
	CelticMandelbar();
};

#endif