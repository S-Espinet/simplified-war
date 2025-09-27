all: simplified_war_linked-list.out

simplified_war_linked-list.out: simplified_war_linked-list.cpp
	g++ -std=c++20 simplified_war_linked-list.cpp -o simplified_war_linked-list.out

clean:
	rm simplified_war_linked-list.out