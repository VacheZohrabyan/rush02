# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = rush-02

# Source files
SRCS = rush-02.c dict.c

# Object files
OBJS = $(SRCS:.c=.o)

# Build rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all
