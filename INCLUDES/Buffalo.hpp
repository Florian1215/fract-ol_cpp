/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Buffalo.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFALO_HPP
# define BUFFALO_HPP

# include "Fractal.hpp"

class Buffalo : public Fractal
{
public:
	Buffalo(void *mlxPtr);

	Buffalo(const Buffalo &src);

	~Buffalo();

	Buffalo &operator=(const Buffalo &rhs);

	int sequence(Data &data, DCo c, DCo co) const;

private:
	Buffalo();
};

#endif