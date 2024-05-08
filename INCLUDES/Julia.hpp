/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:54:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 15:54:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_HPP
# define JULIA_HPP

# include "Fractal.hpp"

class Julia : public Fractal
{
public:
	Julia(void *mlxPtr);
	Julia(const Julia &src);
	~Julia();

	Julia	&operator=(const Julia &rhs);

	int		sequence(Data &data, DCo c, DCo co) const;

private:
	Julia();
};

#endif
