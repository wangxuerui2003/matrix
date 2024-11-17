CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Werror -Wextra

# Paths
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

# Targets
LIBRARY = $(LIB_DIR)/libmatrix.a
OBJECTS = $(OBJ_DIR)/Matrix.o $(OBJ_DIR)/Vector.o

all: $(LIBRARY)

# Build the Matrix library
$(LIBRARY): $(OBJECTS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# Compile Matrix object file
$(OBJ_DIR)/Matrix.o: $(INCLUDE_DIR)/Matrix.hpp $(INCLUDE_DIR)/Matrix.tpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_DIR)/Matrix.hpp -o $@

# Compile Vector object file
$(OBJ_DIR)/Vector.o: $(INCLUDE_DIR)/Vector.hpp $(INCLUDE_DIR)/Vector.tpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $(INCLUDE_DIR)/Vector.hpp -o $@

clean:
	rm -rf $(LIB_DIR)/*.a $(OBJ_DIR)/*.o

re:	clean all

.PHONY:	all libmatrix clean re