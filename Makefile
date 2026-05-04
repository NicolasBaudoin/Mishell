NAME = Minishell

CC := cc
CFLAGS := -Wall -Werror -Wextra

cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"


# ====== files ======

SRC_FILES = main.c

SRCS = ${SRC_FILES}
LIBFT_DIR := libft
OBJ_DIR = obj
LIBFT_DIR := libft
# OBJECT rule
OBJ := ${SRCS:%.c=${OBJ_DIR}/%.o}

# Includes and Libs
INCLUDES :=	-I ${INCLUDE_DIR} \
			-I ${LIBFT_DIR} \
			${READLINE_INCLUDE}

LIBS := -L ${LIBFT_DIR} -lft \

LIBFT = ${LIBFT_DIR}/libft.a

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

${LIBFT} :
	${MAKE} -C ${LIBFT_DIR}

clean:
	@$(call cyan,"Cleaning .o files...")
	@rm -rf $(OBJ_DIR)
	${MAKE} -C ${LIBFT_DIR} clean
	@$(call cyan,"All .o files are removed !")

fclean: clean
	@$(call cyan,"Cleaning executables and .a files...")
	@rm -f $(NAME)
	${MAKE} -C ${LIBFT_DIR} fclean
	@$(call cyan,"All executables and .a files are removed !")

re: fclean all

.PHONY: all clean fclean re bonus
