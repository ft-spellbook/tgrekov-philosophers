NAME = philo
DEBUG_NAME = debug.out

SRC_DIR = src/mandatory
OBJ_DIR = obj

SRC_NAMES =	main.c						\
			host.c						\
			philosopher/breakfast.c		\
			philosopher/status.c		\
			philosopher/stop.c			\
			utils/aton_errable.c		\
			utils/cancellable_sleep.c	\
			utils/err.c					\
			utils/len.c					\
			utils/timestamp.c			\
			utils/wrap_err.c			\
			utils/wrap_ix.c
			
CC = cc
CC_EXT_SRCS = -lpthread
FLAGS = -I$(INC_DIR) -Ofast -Wall -Wextra -Werror
DEBUG_FLAGS = -I$(INC_DIR) -g #-fsanitize=thread

################################################################################

OBJS = $(SRC_NAMES:%.c=$(OBJ_DIR)/mandatory/%.o)
OBJS_DEBUG = $(SRC_NAMES:%.c=$(OBJ_DIR)/debug/%.o)

.PHONY: all debug \
clean .clean fclean re

################################################################################

all: $(NAME)

$(OBJ_DIR)/debug/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(DEBUG_FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(DEBUG_FLAGS) -c $< -o $@

$(OBJ_DIR)/mandatory/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(FLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(FLAGS) -c $< -o $@

################################################################################

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(CC_EXT_SRCS) -o $(NAME)
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(GREEN)Mandatory done$(DEFAULT)"

################################################################################

$(DEBUG_NAME): $(OBJS_DEBUG)
	@$(CC) $(DEBUG_FLAGS) $(CC_EXT_SRCS) $(OBJS_DEBUG) -o $(DEBUG_NAME)
	@echo "$(GREY)$(NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Mandatory done$(DEFAULT)"

debug: $(DEBUG_NAME)

################################################################################

clean:
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR)"
	@rm -rf $(OBJ_DIR) .bonus .debug_bonus
	
fclean: clean
	@echo "$(GREY)$(NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME) and $(DEBUG_NAME)"
	@rm -rf $(NAME) $(DEBUG_NAME)

re: fclean all

################################################################################

GREEN = \033[38;5;84m
RED = \033[38;5;9m
BLUE = \033[38;5;45m
#PURPLE = \033[38;5;63m
PINK = \033[38;5;207m
PURPLE = \033[38;5;165m
BLACK = \033[38;5;0m
BG_WHITE = \033[48;5;15m
BG_GREEN = \033[48;5;84m
BG_RED = \033[48;5;9m
BG_PURPLE = \033[48;5;54m
GREY = \033[38;5;8m
BOLD = \033[1m
DEFAULT = \033[0m
CHECKMARK = \xE2\x9C\x93
