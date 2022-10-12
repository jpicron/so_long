NAME		= so_long

OBJS		= ${SRCS:.c=.o}
SRC			= main.c verif_path.c verif_path_utils.c ft_printf.c ft_printf_utils1.c ft_printf_utils2.c check_map_utils.c ft_split.c gen_utils.c make_map_utils.c map.c move_player_1.c move_player_2.c start.c write_move_to_win.c
SRCS		= ${addprefix src/, ${SRC}}
CC+FLAGS 	= gcc -Wall -Wextra -Werror -g

HEADER		= so_long.h

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@printf "Compiling [%s]...%-42s${RESET}\r" $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\nFinished : $(NAME)${RESET}"

all:	${NAME}

clean:
		@rm -rf ${OBJS}
		@echo "Removing objects...${RESET}"

fclean:	clean
		@rm -rf ${NAME}
		@echo "Removing ${NAME}...${RESET}"

re:		fclean all

.PHONY : all clean fclean re