/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia3.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA3_HPP
# define JULIA3_HPP

# include "Fractal.hpp"

class Julia3 : public Fractal
{
public:
	Julia3(void *mlxPtr);

	Julia3(const Julia3 &src);

	~Julia3();

	Julia3 &operator=(const Julia3 &rhs);

	Color	sequence(Data &data, DCo c, DCo co) const;

private:
	Julia3();
};

#endif