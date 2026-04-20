NAME = tester

# Change LIBFT_PATH to your libft repository
LIBFT_PATH = ../libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
FLAGS = -Wall -Werror -Wextra -Iincludes -I$(LIBFT_PATH)

O_FLAGS = -MMD -MP
L_FLAGS = -L$(LIBFT_PATH) -lft -lbsd

OBJDIR = objects

SRC = $(shell find src -name "*.c")

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(L_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(O_FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

-include $(DEP)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
