NAME ?= cub3d
BONUS_NAME ?=

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src
INCL_DIR ?= ./MLX42/include ./libft/includes ./inc

LIB = libft MLX42
LIBS = $(addprefix -L ,$(LIB))

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
LINKS = -lft -ldl -lglfw -pthread -lm $(word 2, $(LIB))/build/libmlx42.a  $(word 1, $(LIB))/libft.a

all: $(NAME)

do_libft:
	make -sC $(word 1, $(LIB))

do_libmlx:
	@cmake $(word 2, $(LIB)) -B $(word 2, $(LIB))/build && make -sC $(word 2, $(LIB))/build -j4

$(NAME): init_submodules do_libft do_libmlx $(OBJS)
	$(LD) $(LDFLAGS) $(LINKS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): init_submodules do_libft do_libmlx $(BONUS_OBJS)
	@$(LD) $(LDFLAGS) $(LINKS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(BUILD_DIR)/%_bonus.o: $(SRC_DIRS)/%_bonus.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(BUILD_DIR)
	make -sC $(word 1, $(LIB)) clean

fclean:
	make fclean -sC $(word 1, $(LIB))
	@$(RM) -r $(BUILD_DIR)
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

re: fclean all

init_submodules:
	git submodule update --init --recursive

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes

.PHONY: clean fclean re all bonus init_submodules do_libft do_libmlx

-include $(DEPS)
