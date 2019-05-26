#!make -f

all: demo
	./$<

demo:  demo.o 
	g++ -std=c++17 $^ -o demo

test:  test.o 
	g++ -std=c++17 $^ -o test

%.o: %.cpp range.hpp chain.hpp powerset.hpp product.hpp zip.hpp
	g++ -std=c++17 --compile $< -o $@

clean:
	rm -f *.o demo test
