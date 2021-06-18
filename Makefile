# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acami <acami@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 15:34:26 by acami             #+#    #+#              #
#    Updated: 2021/06/18 17:50:38 by acami            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

MINILIBX_DIR	=	./minilibx_opengl/
LIBFT_DIR		=	./libft/
HEADERS_DIR		=	./headers/

SRC_DIR			=	./srcs/
SRC_F			= 	equations.c \
fractol.c \
fractol_init.c \
parse_input.c \
error_handlers.c \
fractol_draw.c \
handlers.c \
utils.c \
generate_colour.c \
actions.c
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_F))

OBJ_DIR			=	./objs/
OBJ_F			=	$(SRC_F:.c=.o)
OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_F))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -O3
LIBS			=	-lmlx -lm -lft \
					-L $(LIBFT_DIR) -L $(MINILIBX_DIR) \
					-framework OpenGL -framework AppKit
INCLUDES		=	-I $(HEADERS_DIR) -I $(LIBFT_DIR) -I $(MINILIBX_DIR)

MULTITHREAD_ON	=	-D MULTITHREAD_ON=1
LINUX_BUILD		=	-D LINUX_BUILD=1

# COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
RESET 	= 	\033[0m


$(NAME) :	 	$(OBJ_DIR) $(OBJS)
				@echo "$(NAME): $(GREEN) Calling make in $(LIBFT_DIR) $(RESET)"
				@make -sC $(LIBFT_DIR) all
				@echo "$(NAME): $(GREEN) Calling make in $(MINILIBX_DIR) $(RESET)"
				@make -sC $(MINILIBX_DIR) all
				@echo "$(NAME): $(GREEN) Creating $(NAME) $(RESET)"
				$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(MULTITHREAD_ON) $(OBJS) -o $(NAME)
				@echo "$(NAME): $(GREEN) >>>>>>>>>> DONE <<<<<<<<<< $(RESET)"

all : 			$(NAME)

include $(wildcard $(OBJ_DIR)*.d)

$(OBJ_DIR) :
				@mkdir -p $(OBJ_DIR)
				@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c		
				$(CC) $(CFLAGS) -c $(INCLUDES) $(MULTITHREAD_ON) $< -o $@ -MMD

clean_libs :
				@echo "$(NAME): $(BLUE) Calling clean in $(LIBFT_DIR) $(RESET)"
				@make -sC $(LIBFT_DIR) clean
				@echo "$(NAME): $(BLUE) Calling clean in $(MINILIBX_DIR) $(RESET)"
				@make -sC $(MINILIBX_DIR) clean

clean_objs :
				@echo "$(NAME): $(BLUE) Deleting $(OBJ_DIR) $(RESET)"
				@rm -rf $(OBJ_DIR)

clean :			clean_libs clean_objs
				@echo "$(NAME): $(GREEN) clean: DONE $(RESET)"

fclean_libs :
				@echo "$(NAME): $(CYAN) Calling fclean in $(LIBFT_DIR) $(RESET)"
				@make -sC $(LIBFT_DIR) fclean
				@echo "$(NAME): $(CYAN) Calling clean in $(MINILIBX_DIR) $(RESET)"
				@make -sC $(MINILIBX_DIR) clean
				@echo "$(NAME): $(CYAN) Deleting $(MINILIBX_DIR)libmlx.a  $(RESET)"
				@rm -f $(MINILIBX_DIR)libmlx.a
				
fclean_objs :
				@echo "$(NAME): $(CYAN) Deleting $(OBJ_DIR) $(RESET)"
				@rm -rf $(OBJ_DIR)
				@echo "$(NAME): $(CYAN) Deleting $(NAME) $(RESET)"
				@rm -f $(NAME)		

fclean :		fclean_libs fclean_objs
				@echo "$(NAME): $(GREEN) fclean: DONE $(RESET)"

re :			fclean all

.PHONY : 		all clean_libs clean_objs clean fclean_libs fclean_objs fclean re
