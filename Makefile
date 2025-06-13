all: hello_world

hello_world: hello_world.cpp
	g++ -std=c++20 hello_world.cpp -o hello_world

#hello_world: hello_world.cpp
#	g++ $@.cpp -o $@

clean:
	rm hello_world