NAME = Minishell

CC := cc
CFLAGS := -Wall -Werror -Wextra

cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"

SRC_FILES = main.c

SRC = ${SRC_FILES}

OBJ = $(SRC:%.c=${OBJ_DIR}/%.o)

# LIBFT

LIBFT_DIR = libft
LIBFT_REPO = git@github.com:NicolasBaudoin/ft_libft.git
LIBFT = $(LIBFT_DIR)/libft.a

# INCLUDE
INCLUDE = -I$(LIBFT_DIR) -I/usr/include/readline

OBJ_DIR = obj

all: $(NAME)
	@$(call cyan,"Compilation done !")

${NAME} : ${OBJ} ${LIBFT}
	@$(CC) $(CFLAGS) $(OBJ) ${LIBFT} -lreadline -o $(NAME)
	@$(call cyan,"Creating Mishell...")

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_DIR):
	@git clone $(LIBFT_REPO) $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): | $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(call cyan,"Cleaning .o files...")
	@rm -rf $(OBJ_DIR)
	@$(call cyan,"All .o files are removed !")

fclean: clean
	@$(call cyan,"Cleaning executables and .a files...")
	@rm -f $(NAME)
	@$(call cyan,"All executables and .a files are removed !")

re: fclean all

.PHONY: all clean fclean re bonus
