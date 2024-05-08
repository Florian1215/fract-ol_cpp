/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:29:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 13:29:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICO_HPP
# define ICO_HPP

# include "Coordinate.hpp"

class ICo : public Coordinate<int>
{
public:
	ICo();
	ICo(int x, int y);
	ICo(const ICo &src);
	~ICo();

	ICo &operator=(const ICo &rhs);

private:
};

std::ostream	&operator<<(std::ostream &os, const ICo &co);

#endif
