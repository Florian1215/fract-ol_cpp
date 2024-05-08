/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heart.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEART_HPP
# define HEART_HPP

# include "Fractal.hpp"

class Heart : public Fractal
{
public:
	Heart(void *mlxPtr);

	Heart(const Heart &src);

	~Heart();

	Heart &operator=(const Heart &rhs);

	int sequence(Data &data, DCo c, DCo co) const;

private:
	Heart();
};

#endif