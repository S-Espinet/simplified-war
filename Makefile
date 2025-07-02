all: simplified_war

hello_world: simplified_war.cpp
	g++ -std=c++20 simplified_war.cpp -o simplified_war

#simplified_war: simplified_war.cpp
#	g++ $@.cpp -o $@

clean:
	rm simplified_war