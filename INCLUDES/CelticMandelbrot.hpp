/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CelticMandelbrot.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/07 10:19:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELTICMANDELBROT_HPP
# define CELTICMANDELBROT_HPP

# include "Fractal.hpp"

class CelticMandelbrot : public Fractal
{
public:
	CelticMandelbrot(void *mlxPtr);

	CelticMandelbrot(const CelticMandelbrot &src);

	~CelticMandelbrot();

	CelticMandelbrot &operator=(const CelticMandelbrot &rhs);

	Color	sequence(Data &data, DCo c, DCo co) const;

private:
	CelticMandelbrot();
};

#endif