#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <array>
using namespace std;

class Deck {
  const int numOfCardTypes = 13;
  int deckCount = 52;
  int *counts;
public:
  Deck();
  int getDeckCount();
  int drawCard();
  void printCounts();
};

int main() {
  //random seed - for rand function:
  srand(time(NULL));
  //initializes points
  int playerAPoints = 0;
  int playerBPoints = 0;
  Deck warDeck = Deck();
  while (warDeck.getDeckCount() > 1) {
  //saves return value of drawCard function:
    int drawnCardA = warDeck.drawCard();
    int drawnCardB = warDeck.drawCard();
    if (drawnCardA > drawnCardB) {
      playerAPoints += 1;
    }
    else if (drawnCardB > drawnCardA) {
      playerBPoints += 1;
    }
  }
  cout << "Player A: " << playerAPoints << endl;
  cout << "Player B: " << playerBPoints << endl;
  warDeck.printCounts();
}

Deck::Deck() {
  counts = new int[numOfCardTypes];
  //initializes list of counts:
  for (int i = 0; i < numOfCardTypes; i++) {
    counts[i] = 4;
  }
}

int Deck::drawCard() {
  int cardValue;
  //keep picking numbers until you pick one that is still in the deck
  do {
    cardValue = rand() % numOfCardTypes;
  }
  while (counts[cardValue] == 0);
  deckCount -= 1;
  counts[cardValue] -= 1;
  return cardValue;
}

int Deck::getDeckCount() {
  return deckCount;
}

void Deck::printCounts() {
  //loop to print multiple values because array/pointer points to first allocated space in memory
  for (int i = 0; i < numOfCardTypes; i++) {
    cout << i << " " << counts[i] << endl;
  }
}

// Stage one: crazy random
//choose new cardValue until you find a non-zero count (might take a LONG time)
//  use deckCount = 52 (initially and decrement when drawing) - stop drawing cards when 0.

//use classes

// Stage two: make a linked list of structs and pointers to hold valid indices to `counts`

// The Right Way (do this in hello_world.cpp): use <algorithm> and `std::ranges::sample` to rand pick a card from a 'sequence'

//Add more classes "Player", "Game/War", etc.