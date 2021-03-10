# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 16:58:17 by jiqarbac          #+#    #+#              #
#    Updated: 2021/02/27 16:28:07 by jiqarbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OBJ  = srcs/julia.o srcs/mandelbrot.o srcs/main.o srcs/burningship.o srcs/treecorns.o\
srcs/tools.o srcs/key.o srcs/zoom.o srcs/menu.o
FLG  = -Wall -Wextra -Werror
INC  = includes/
INCS = includes/fractol.h


all: $(NAME)

%.o : %.c $(INCS)
	@gcc $(FLG) -o $@ -c $< -I $(INC)

$(NAME): $(OBJ) 
	@make -s -C libft/
	@gcc $(FLG) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "compilation completed\n"

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@printf "clean terminated\n"

fclean: clean
	@make fclean -C libft/
	@rm -f $(OBJ) $(NAME)
	@printf "clean all\n"

re: fclean all
