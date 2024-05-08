
# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	SRCS/Animation.cpp SRCS/Color.cpp SRCS/CPreset.cpp SRCS/Data.cpp SRCS/Hover.cpp SRCS/Fractal.cpp SRCS/Fractals.cpp SRCS/Menu.cpp SRCS/Palette.cpp SRCS/Slide.cpp \
					SRCS/FRACTALS/Buffalo.cpp SRCS/FRACTALS/BurningJulia.cpp SRCS/FRACTALS/BurningShip.cpp SRCS/FRACTALS/Celtic.cpp SRCS/FRACTALS/CelticMandelbar.cpp SRCS/FRACTALS/CelticMandelbrot.cpp SRCS/FRACTALS/Heart.cpp SRCS/FRACTALS/Julia3.cpp SRCS/FRACTALS/Julia.cpp SRCS/FRACTALS/Mandelbar.cpp SRCS/FRACTALS/Mandelbrot.cpp SRCS/FRACTALS/PerpendicularCeltic.cpp \
					SRCS/UTILS/MATHS/DCo.cpp SRCS/UTILS/MATHS/Delta.cpp SRCS/UTILS/MATHS/ICo.cpp \
					SRCS/UTILS/MLX/Image.cpp \
					main.cpp
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.d))

NAME			=	fractol
HEAD			=	INCLUDES/

CC				=	c++
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -g

MLX_NAME		=	libmlx.a


UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
MLX_DIR			=	mlx/linux/
MLX_FLAGS		=	-lXext -lX11 -lm -lz
endif

ifeq ($(UNAME), Darwin)
MLX_DIR			=	mlx/mac/
MLX_FLAGS		=	-framework OpenGL -framework AppKit
endif

# RULES -------------------------------------------------------------
all:				$(NAME)

run:				all
					./$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.cpp
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)SRCS
					@mkdir -p $(OBJS_DIR)SRCS/HOOK
					@mkdir -p $(OBJS_DIR)SRCS/FRACTALS
					@mkdir -p $(OBJS_DIR)SRCS/UTILS
					@mkdir -p $(OBJS_DIR)SRCS/UTILS/MATHS
					@mkdir -p $(OBJS_DIR)SRCS/UTILS/MLX
					$(CC) $(FLAGS) -I $(HEAD) -c $< -o $@

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all run clean fclean re
