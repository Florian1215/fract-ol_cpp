/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:39:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/06 15:39:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_HPP
# define MANDELBROT_HPP

# include "Fractal.hpp"

class Mandelbrot : public Fractal
{
public:
	Mandelbrot(void *mlxPtr);
	Mandelbrot(const Mandelbrot &src);
	~Mandelbrot();

	Mandelbrot	&operator=(const Mandelbrot &rhs);

	Color		sequence(Data &data, DCo c, DCo co) const;

private:
	Mandelbrot();
};

#endif
