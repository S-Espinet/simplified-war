all: simplified_war_class.out

simplified_war_class.out: simplified_war_class.cpp
	g++ -std=c++20 simplified_war_class.cpp -o simplified_war_class.out

clean:
	rm simplified_war_class.out