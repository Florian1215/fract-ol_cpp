/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:14:00 by fguirama          #+#    #+#             */
/*   Updated: 2024/05/03 16:14:00 by fguirama         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCESSING_HPP
# define PREPROCESSING_HPP
// INCLUDE ----------------------------------------------------------
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <unistd.h>

# ifdef __APPLE__
#  include "../mlx/mac/mlx.h"
# endif

# ifdef __linux__
#  include "../mlx/linux/mlx.h"
# endif

// DEFINE -------------------------------------------------
# define PROJECT_NAME				"Fract-ol"
# define MAX_SHADOW					7
# define MAX_ITER					50
# define MAX_ITER_HOVER				40
# define ZOOM_HOVER					0.90
# define ZOOM_MENU					1
# define N_FRAC						12
# define FPS						25
# define FRAME_ANIMATION			29
# define WIN						1000
# define HWIN						WIN / 2
# define QWIN						HWIN / 2
# define RATIO_TITLE				WIN * 0.7 / 1000

# define IDX_ERROR					"Index out of bounds"

# define PATH_MANDELBROT			"./ASSETS/01_mandelbrot.getX()pm"
# define PATH_JULIA					"./ASSETS/02_julia.getX()pm"
# define PATH_CELTIC				"./ASSETS/03_celtic.getX()pm"
# define PATH_BURNING_SHIP			"./ASSETS/04_burning_ship.getX()pm"
# define PATH_BUFFALO				"./ASSETS/05_buffalo.getX()pm"
# define PATH_BURNING_JULIA			"./ASSETS/06_burning_julia.getX()pm"
# define PATH_JULIA3				"./ASSETS/07_julia3.getX()pm"
# define PATH_CELTIC_MANDELBAR		"./ASSETS/08_celtic_mandelbar.getX()pm"
# define PATH_PERPENDICULAR_CELTIC	"./ASSETS/09_perpendicular_celtic.getX()pm"
# define PATH_HEART					"./ASSETS/10_heart.getX()pm"
# define PATH_MANDELBAR				"./ASSETS/11_mandelbar.getX()pm"
# define PATH_CELTIC_MANDELBROT		"./ASSETS/12_celtic_mandelbrot.getX()pm"

#endif
