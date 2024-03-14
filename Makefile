NAME ?= cub3d
BONUS_NAME ?=

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src
INCL_DIR ?= ./MLX42/include/ ./inc

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
LINKS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

HIDE =

all: init_submodules $(NAME)

libft:
	@make -C $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): libft libmlx $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LINKS)

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@

bonus: init_submodules $(BONUS_NAME)

$(BONUS_NAME): libft libmlx $(BONUS_OBJS)
	$(LD) $(LDFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LINKS)

$(BUILD_DIR)/%_bonus.o: $(SRC_DIRS)/%_bonus.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(HIDE) $(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	@make fclean -C $(LIBFT)
	$(HIDE) $(RM) $(NAME)
	$(HIDE) $(RM) $(BONUS_NAME)
	make -C $(LIBFT) fclean

re: clean all

init_submodules:
	@git submodule update --init

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all

.PHONY: clean fclean re all bonus init_submodules

-include $(DEPS)
