NAME = test
CXX = g++
CXXFLAGS = -std=c++17 -I../include -Wall -Werror -Wextra

SRC = $(wildcard *.cpp)

.PHONY: all clean re

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re:	clean all
