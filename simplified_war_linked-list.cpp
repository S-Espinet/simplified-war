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

struct WarNode {
  int numOfCard = 4;
  int rank;
  WarNode *nextNode;
};

class LinkedCardList {
  //move WarNode struct inside LinkedCardList class?
  WarNode *root = NULL;
  //create node after node that points to null (tail)/append:
  void addNode();
  //remove node based on rank (once numOfCard = 0)
  //decrement numOfCard based on node rank
};

//write code to create a node using a loop
//include a check if rank != 13, current node points to next node

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

//functions that apply to Deck class

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

//functions that apply to LinkedCardList class

void LinkedCardList::addNode() {
  if (root == NULL) {
    root = new WarNode();
    root->rank = 0;
  }
  else {
    WarNode *endNode = root->nextNode;
    int rankCount = 0;
    while (endNode != NULL) {
      endNode = endNode->nextNode;
      rankCount ++;
    }
    endNode = new WarNode();
    endNode->rank = rankCount + 1;
  }
}