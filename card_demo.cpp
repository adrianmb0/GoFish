// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
////////CARD TESTER//////////
//    Card testCard;
//
//    cout << testCard.toString() << endl;
//
//    Card testCard2(1, Card::spades);
//
//    cout << testCard2.toString() << endl;
//
//    if(testCard.sameSuitAs(testCard2)){
//        cout << "Same Suit" << endl;
//    }else{
//        cout << "Not Same Suit" << endl;
//    }
//
//    if(testCard==testCard2){
//        cout << "Same Card" << endl;
//    }else{
//        cout << "Not Same Card" << endl;
//    }


////////DECK TESTER//////////
Deck newDeck;

    //Size Tester//
cout << "There are " << newDeck.size() << " cards left in the deck" << endl << endl;

    //Shuffle Tester
newDeck.shuffle();

    //SHOW DECK//
for(int i = 0; i < 52; i++){
    cout << newDeck.dealCard() << endl;
}

    //Size Edge case of 0 Tester //
cout << "There are " << newDeck.size() << "  cards left in the deck" << endl << endl;

////////DEMO TESTER//////////

//    int numCards = 5;
//
//    Player p1("Joe");
//    Player p2("Jane");
//
//    Deck d;  //create a deck of cards
//    d.shuffle();
//
//    dealHand(d, p1, numCards);
//    dealHand(d, p2, numCards);
//
//    cout << p1.getName() <<" has : " << p1.showHand() << endl;
//    cout << p2.getName() <<" has : " << p2.showHand() << endl;
//
//    return EXIT_SUCCESS;
}


//
//void dealHand(Deck &d, Player &p, int numCards)
//{
//   for (int i=0; i < numCards; i++)
//      p.addCard(d.dealCard());
//}
   



