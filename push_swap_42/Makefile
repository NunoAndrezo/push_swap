# Executable Name
NAME = push_swap

# Directories
PRINTF				= ./printf/libftprintf.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
RM					= rm -f

# Source Files
COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
					$(SRC_DIR)commands/reverse_rotate.c \
					$(SRC_DIR)commands/rotate.c \
					$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)algorithm/push_swap.c \
					$(SRC_DIR)algorithm/ft_calloc.c \
					$(SRC_DIR)algorithm/utils.c \
					$(SRC_DIR)algorithm/ordering.c \
					$(SRC_DIR)algorithm/ft_split.c \
					$(SRC_DIR)algorithm/init_nodes_a.c \
					$(SRC_DIR)algorithm/errors_and_free.c \
					$(SRC_DIR)algorithm/stack_initialization.c \
					$(SRC_DIR)algorithm/stack_auxil.c \
					$(SRC_DIR)algorithm/init_nodes_b.c 

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:				
					@make all

$(PRINTF):
					@make -C ./printf

all: 				$(NAME)

$(NAME): 			loading_bar $(OBJ) $(PRINTF)
					@$(CC) $(CFLAGS) -I$(INC) $(OBJ) $(PRINTF) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

# Loading bar implementation
loading_bar:
					@if [ ! -f $(NAME) ] || [ "$(MAKECMDGOALS)" = "re" ]; then \
						echo "Building project..."; \
						for i in $$(seq 0 1 100); do \
							sleep 0.01; \
							printf "\rLoading: %3d%% [%-50s]" $$i $$(printf '#%.0s' $$(seq 1 $$((i / 2)))); \
						done; \
						printf "\n"; \
					else \
						echo "Nothing to be made!"; \
					fi

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./printf

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(PRINTF)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re loading_bar


#.PHONY specifies targets that are not actual files.
#This helps ensure that make runs these commands when specified
#even if files with these names exist.