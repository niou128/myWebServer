CC = g++
CFLAGS = -W -Wall -Werror
NAME = MonServeurWeb
RM = rm -f

# Default rule
all: clean $(NAME)

# Compiling
$(NAME):
	$(CC) $(CFLAGS) src/*.cpp $(SDLBIN) -o $(NAME)

# Object files removing
clean:
	$(RM) $(NAME)
