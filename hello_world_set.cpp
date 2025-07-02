#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
using namespace std;
// The Right Way (do this in hello_world.cpp): use <algorithm> and `std::ranges::sample` to rand pick a card from a 'sequence'

int drawCard(unordered_multiset<int> & fullDeck);

int main() {
  srand(time(NULL));
  unordered_multiset<int> fullDeck;
  //fullDeck is every "card"
  vector<int> cardList;
  for (int i = 2; i < 15; i++) {
    cardList.push_back(i);
  }
  //cardList now contains one of each "card"; 2-14
  for (int i = 0; i < 4; i++) {
    fullDeck.insert(cardList.begin(), cardList.end());
    //cout << fullDeck.size() << endl;
  }
  //fullDeck is now a full Deck - 52 cards
  drawCard(fullDeck);
  cout << fullDeck.size() <<endl;
  //int player1Score = 0;
  //int player2Score = 0;
}

int drawCard(unordered_multiset<int> & fullDeck) {
  int cardValue = rand() % 13 + 2;
  //the size of fullDeck is the limit (not 13 + 2)
  //tell the iterator to go that far forward and give me the value when it's stopped
  //card now drawn
  //if fullDeck does not contain cardValue try again
  while (fullDeck.count(cardValue) == 0) {
    cardValue = rand() % 13 + 2;
  }
  //else decrement count of that cardValue in fullDeck
  auto it = fullDeck.find(cardValue);
  if (it != fullDeck.end())
    fullDeck.erase(it);
  return cardValue;  
}