NAME ?= cub3d
BONUS_NAME ?=

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src
INCL_DIR ?= ./MLX42/include/ ./libft/includes ./inc

LIBFT = libft
LIBMLX = MLX42
LIBS = $(addprefix -L ,$(LIBFT) $(LIBMLX))

SRCS := $(filter-out %_bonus.c, $(shell find $(SRC_DIRS) -name *.c))
OBJS := $(subst $(SRC_DIRS), $(BUILD_DIR), $(SRCS:.c=.o))

BONUS_SRCS := $(shell find $(SRC_DIRS) -name *_bonus.c)
BONUS_OBJS := $(subst $(SRC_DIRS), $(BUILD_DIR), $(BONUS_SRCS:.c=.o))

DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(INCL_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC = cc
CFLAGS ?= $(INC_FLAGS) -Wall -Werror -Wextra -MMD -MP -g

LD = cc
LDFLAGS = $(LIBS)
LINKS = -lft -ldl -lglfw -pthread -lm
#$(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a 

all: $(NAME)

libft:
	make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -sC $(LIBMLX)/build -j4

$(NAME): init_submodules libft libmlx $(OBJS)
	@$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LINKS)

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	@$(HIDE) mkdir -p $(@D)
	@$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): init_submodules libft libmlx $(BONUS_OBJS)
	@$(LD) $(LDFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LINKS)

$(BUILD_DIR)/%_bonus.o: $(SRC_DIRS)/%_bonus.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(BUILD_DIR)
	@make -sC $(LIBFT) clean

fclean:
	@make fclean -sC $(LIBFT)
	@$(RM) -r $(BUILD_DIR)
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

re: fclean all

init_submodules:
	git submodule update --init
#	git submodule update --remote

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes

.PHONY: clean fclean re all bonus init_submodules

-include $(DEPS)
