CC = g++
CFLAGS = -W -Wall -Werror
NAME = MonServeurWeb
RM = rm -f

LDFLAGS	= 

# Default rule
all: clean $(NAME)

# Compiling
$(NAME):
	$(CC) $(CFLAGS) src/*.cpp -o $(NAME) $(LDFLAGS)

# Object files removing
clean:
	$(RM) $(NAME)
