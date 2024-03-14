NAME ?= libft.a

BUILD_DIR ?= ./obj
SRC_DIRS ?= ./src
INCL_DIR ?= ./includes

SRCS := $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(subst $(SRC_DIRS), $(BUILD_DIR), $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(INCL_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC = cc
CFLAGS ?= $(INC_FLAGS) -Wall -Werror -Wextra -MMD -MP

LD = ar
LDFLAGS = -crs

HIDE = @

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\nLinking:"
	$(LD) $(LDFLAGS) $@ $(OBJS)
	@echo "..\n"

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	$(HIDE) mkdir -p $(@D)
	$(HIDE) $(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $< ..\n"

.PHONY: clean fclean re debug

clean:
	$(HIDE) $(RM) -r $(BUILD_DIR)
	@echo "removing obj/ ..\n"

fclean: clean
	$(HIDE) $(RM) $(NAME)
	@echo "removing $(NAME) ..\n"

re: fclean all

-include $(DEPS)
