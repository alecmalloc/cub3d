NAME ?= cub3d
BONUS_NAME ?=

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src
INCL_DIR ?= ./MLX42/include/ ./inc

LIBFT = libft
LIBMLX = MLX42
LIBS = $(addprefix -L ,$(LIBFT) $(LIBMLX))

OBJS	:= ${SRCS:.c=.o}

all: libft libmlx $(NAME)

libft:
		make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

CC = cc
CFLAGS ?= $(INC_FLAGS) -Wall -Werror -Wextra -MMD -MP -g

LD = cc
LDFLAGS = $(LIBS)
LINKS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

HIDE =

all: init_submodules $(NAME)

libft:
	echo "\n\ncompiling libft\n\n"
	@make -C $(LIBFT)

libmlx:
	echo "\n\ncompiling mlx\n\n"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): libft libmlx $(OBJS)
	@echo "\nLinking:"
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LINKS)
	@echo "..\n"

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< ..\n"

bonus: init_submodules $(BONUS_NAME)

$(BONUS_NAME): libft libmlx $(BONUS_OBJS)
	@echo "\nlinking bonus:"
	$(LD) $(LDFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LINKS)
	@echo "..\n"

$(BUILD_DIR)/%_bonus.o: $(SRC_DIRS)/%_bonus.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $< ...\n"

clean:
	$(HIDE) $(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFT) clean
	@echo "removing obj/ ..\n"

fclean: clean
	@make fclean -C $(LIBFT)
	$(HIDE) $(RM) $(NAME)
	$(HIDE) $(RM) $(BONUS_NAME)
	make -C $(LIBFT) fclean
	@echo "removing $(NAME) ..\n"

re: clean all

init_submodules:
	@git submodule update --init

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all

.PHONY: clean fclean re all bonus init_submodules

-include $(DEPS)
