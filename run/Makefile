######################
# Fun With Makefiles #
######################

SOURCE_DIR  = ../source
MAIN_DIR    = $(SOURCE_DIR)/main
INCLUDE_DIR = $(SOURCE_DIR)/include

run : all
	./run -arrays

all : main.o fun_with_arrays.o fun_with_strings.o
	g++ main.o fun_with_arrays.o fun_with_strings.o -o run

main.o : $(MAIN_DIR)/main.cpp fun_with_strings.o fun_with_arrays.o
	g++ -c $(MAIN_DIR)/main.cpp -I$(INCLUDE_DIR)

fun_with_strings.o: $(MAIN_DIR)/fun_with_strings.cpp $(INCLUDE_DIR)/fun_with_strings.h
	g++ -c $(MAIN_DIR)/fun_with_strings.cpp -I$(INCLUDE_DIR)

fun_with_arrays.o: $(MAIN_DIR)/fun_with_arrays.cpp $(INCLUDE_DIR)/fun_with_arrays.h
	g++ -c $(MAIN_DIR)/fun_with_arrays.cpp -I$(INCLUDE_DIR)

clean:
	rm -rf *.o *.out run
