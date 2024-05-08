/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Celtic                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:07:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:07:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELTIC_HPP
# define CELTIC_HPP

# include "Fractal.hpp"

class Celtic : public Fractal
{
public:
	Celtic(void *mlxPtr);
	Celtic(const Celtic &src);
	~Celtic();

	Celtic	&operator=(const Celtic &rhs);

	int		sequence(Data &data, DCo c, DCo co) const;

private:
	Celtic();
};

#endif