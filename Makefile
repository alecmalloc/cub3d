NAME ?= cub3d
BONUS_NAME ?=

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src
INCL_DIR ?= ./inc

LIB = libft
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
LINKS = -lft

HIDE =

all: init_submodules $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB)
	@echo "\nLinking:"
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LINKS)
	@echo "..\n"

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $< ..\n"

bonus: init_submodules $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIB)
	@echo "\nlinking bonus:"
	$(LD) $(LDFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LINKS)
	@echo "..\n"

$(BUILD_DIR)/%_bonus.o: $(SRC_DIRS)/%_bonus.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "Compiling $< ...\n"

clean:
	$(HIDE) $(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIB) clean
	$(HIDE) $(RM) heredoc.txt
	@echo "removing obj/ ..\n"

fclean: clean
	@make fclean -C $(LIB)
	$(HIDE) $(RM) $(NAME)
	$(HIDE) $(RM) $(BONUS_NAME)
	$(MAKE) -C $(LIB) fclean
	@echo "removing $(NAME) ..\n"

re: fclean all

init_submodules:
	@git submodule update --init

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=$(SUPP) ./$(NAME)

.PHONY: clean fclean re all bonus init_submodules

-include $(DEPS)
