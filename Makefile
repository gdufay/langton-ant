NAME = langton-ant


LIBS = -lsfml-graphics -lsfml-window -lsfml-system

INCDIR = includes
_INCLUDES = grid.hpp ant.hpp
INCLUDES = $(patsubst %,$(INCDIR)/%,$(_INCLUDES))

SRCDIR = src
_SRC = main.cpp grid.cpp ant.cpp
SRC = $(patsubst %,$(SRCDIR)/%,$(_SRC))

OBJDIR = obj
OBJ = $(SRC:%=$(OBJDIR)/%.o)

CC = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17 -pedantic -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJDIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re