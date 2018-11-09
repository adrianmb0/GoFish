//// FILE: card_demo.cpp
//// This is a small demonstration program showing how the Card and Deck classes are used.
//// Project Finished by Adrian Melo and David Fernandez
//#include <iostream>    // Provides cout and cin
//#include <cstdlib>     // Provides EXIT_SUCCESS
//#include "card.h"
//#include "player.h"
//#include "deck.h"
//
//using namespace std;
//
//// PROTOTYPES for functions used by this demonstration program:
//void dealHand(Deck &d, Player &p, int numCards);
//
//int main( ) {
//////////CARD TESTER//////////
////    Card testCard;
////
////    cout << testCard.toString() << endl;
////
////    Card testCard2(1, Card::spades);
////
////    cout << testCard2.toString() << endl;
////
////    if(testCard.sameSuitAs(testCard2)){
////        cout << "Same Suit" << endl;
////    }else{
////        cout << "Not Same Suit" << endl;
////    }
////
////    if(testCard==testCard2){
////        cout << "Same Card" << endl;
////    }else{
////        cout << "Not Same Card" << endl;
////    }
//
//
//////////DECK TESTER//////////
////Deck newDeck;
////
////    //Size Tester//
////cout << "There are " << newDeck.size() << " cards left in the deck" << endl << endl;
////
////    //Shuffle Tester
////newDeck.shuffle();
////
////    //SHOW DECK//
////for(int i = 0; i < 52; i++){
////    cout << newDeck.dealCard() << endl;
////}
////
////    //Size Edge case of 0 Tester //
////cout << "There are " << newDeck.size() << "  cards left in the deck" << endl << endl;
//
//////////PLAYER TESTER//////////
//
//    int numCards = 14;
//
//    Player p1("Adrian");
//    Player p2("David");
//
//    Deck d;  //create a deck of cards
//
//    dealHand(d, p1, numCards);
//    dealHand(d, p2, numCards);
//
//    //cout debug statements
//
//    cout << p1.getName()<< endl;
//    cout << p2.getName()<< endl;
//
//    cout << "Adrian's Hand: " << p1.showHand() << endl;
//
//    cout << "Adrian's Cards in Hand: " <<  p1.getHandSize() << endl;
//
//    cout << "Adrian's Cards in Book: " <<  p1.getBookSize() << endl;
//
//    //Checking Pair and Booking the Card//
//        //Check Hand Tester//
//            Card* card1 = new Card();
//            Card* card2 = new Card();
//
//            if(p1.checkHandForBook(*card1, *card2)){
//                cout << "Adrian has a pair!" << endl;
//            } else{
//                cout << "Adrian doesn't have a pair!" << endl;
//            }
//
//        //Book Cards Tester//
//            p1.bookCards(*card1, *card2);
//            cout << "Adrian's Book: " << p1.showBooks() << endl;
//
//        //Remove Hand Tester//
//            p1.removeCardFromHand(*card1);
//            p1.removeCardFromHand(*card2);
//            cout << "Adrian's Hand: " << p1.showHand() << endl;
//
//    //Rank in Hand Tester//
//        if(p1.rankInHand(Card(1,Card::spades))){
//            cout << "Adrian has the rank!" << endl;
//        }
//        if(p1.cardInHand(Card(2,Card::spades))){
//            cout << "Adrian has the card!" << endl;
//        }
//
//    //Have to create a function to iterate through the hand to check pairs to be able to book any pairs
//    d.shuffle();
//
//////////DEMO TESTER//////////
//
////    int numCards = 5;
////
////    Player p1("Joe");
////    Player p2("Jane");
////
////    Deck d;  //create a deck of cards
////    d.shuffle();
////
////    dealHand(d, p1, numCards);
////    dealHand(d, p2, numCards);
////
////    cout << p1.getName() <<" has : " << p1.showHand() << endl;
////    cout << p2.getName() <<" has : " << p2.showHand() << endl;
////
////    return EXIT_SUCCESS;
//}
//
//void dealHand(Deck &d, Player &p, int numCards)
//{
//    for (int i=0; i < numCards; i++)
//        p.addCard(d.dealCard());
//}
//
//
//
//
//
//
//
