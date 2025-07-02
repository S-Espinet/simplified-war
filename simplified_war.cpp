#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <array>
using namespace std;

int numOfCardTypes = 13;

int main() {
  srand(time(NULL));
  int counts[numOfCardTypes];
  for (int i = 0; i < numOfCardTypes; i++) {
    counts[i] = 4;
    //cout << i << " " << counts[i] << endl;
  }
}

int drawCard() {
  int cardValue = rand() % 13;
}

// Stage one: crazy random
//choose new cardValue until you find a non-zero count (might take a LONG time)
//  use deckCount = 52 (initially and decrement when drawing) - stop drawing cards when 0.

// Stage two: make a linked list of structs and pointers to hold valid indices to `counts`

// The Right Way (do this in hello_world.cpp): use <algorithm> and `std::ranges::sample` to rand pick a card from a 'sequence'