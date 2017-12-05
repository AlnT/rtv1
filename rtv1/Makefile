NAME = RTv1

SRCP = src

SRC = main.c error.c create_rt.c get_next_line.c pars.c\
	  add_f.c addl.c inter.c mlxc.c newfunc.c newfunc1.c\
	  paint.c rayt.c vect.c

OBJP = obj

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

WFLAGS = -Wall -Wextra -Werror

FLAGS = -lmlx -framework OpenGL -framework AppKit

S = $(addprefix $(SRCP)/,$(SRC))
O = $(addprefix $(OBJP)/,$(OBJ))

all: $(NAME)

$(NAME): $(O)
	@make -C ./libft all
	@gcc $(FLAGS) -L. libft/libft.a $^ -o $@

$(OBJP)/%.o: $(SRCP)/%.c
	@mkdir $(OBJP) 2> /dev/null || true
	@gcc $(WFLAGS) -c $< -I libft/libft.h -I RTv1.h -o $@

clean:
	@make -C libft clean
	@rm -f $(O)
	@rmdir $(OBJP) 2> /dev/null || true

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
