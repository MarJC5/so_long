# COLORS
GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
RESET	= \033[0m

RUN		= so_long
NAME 	= so_long.a
MLX 	= ./mlx
FOLDER 	= src/

RM 		= rm -f
CC 		= cc
AR		= ar -rcs
CFLAGS 	= -Wall -Werror -Wextra -Imlx
OPTIONS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

FILES 	= main.c
SOURCES = $(addprefix $(FOLDER), $(FILES))
OBJ		= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(MLX)
	@cp $(MLX)/libmlx.a $(NAME)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(RUN) $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "[$(GREEN)created$(RESET)]: Run the program with \033[1m$(RUN) 'map name'$(RESET)"

clean :
	@$(RM) $(OBJ)
	@$(RM) $(RUN)
	@$(MAKE) -C $(MLX) clean
	@echo "[$(RED)deleted$(RESET)]: all *.o files"

fclean: clean
	@$(RM) $(NAME)
	@echo "[$(RED)deleted$(RESET)]: $(NAME) and libmlx.a"

re: fclean all

.PHONY: all re clean fclean