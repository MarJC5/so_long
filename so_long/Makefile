# COLORS
GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

RUN		= so_long
NAME 	= so_long.a
MLX 	= ./mlx
LIBFT 	= ./libft
FOLDER 	= src/
LIB 	= -L ./libft -lft -L ./mlx -lmlx

RM 		= rm -f
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra -I.
OPTIONS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit #To link with the required internal macOS API

FILES 	=	main.c \
			init_win.c \
			key_action.c \
			key_event.c \
			monster_event.c \
			get_map.c \
			get_next_line.c \
			setup_collectible.c \
			setup_fire.c \
			setup_img.c \
			setup_move.c \
			setup_monster.c \
			utils.c
SOURCES = $(addprefix $(FOLDER), $(FILES))
OBJ		= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(MLX)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(RUN) $(OBJ) $(LIB)
	@echo "[$(GREEN)created$(RESET)]: Run the program with \033[1m$(RUN) 'map name'$(RESET)"

clean :
	@$(RM) $(OBJ)
	@$(RM) $(RUN)
	@$(MAKE) -C $(MLX) clean
	@$(MAKE) -C $(LIBFT) clean
	@echo "[$(RED)deleted$(RESET)]: all *.o files"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@echo "[$(RED)deleted$(RESET)]: $(NAME), libmlx.a and libft.a"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt -s ./$(RUN) ./map/small.ber

re: fclean all

.PHONY: all re clean fclean valgrind