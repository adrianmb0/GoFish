// FILE: go_fish.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
// Project Finished by Adrian Melo and David Fernandez
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void booksChecker(Player *p);

int main( ) {

    ofstream gfFile;
    gfFile.open("GoFish.txt");

    cout << "Starting GoFish!" << endl;

    gfFile << "Let's Play Go Fish!\n\n";

    int numCards = 7;

    Card tempCard = Card();

    Player p1("Adrian");
    Player p2("David");

    Deck mainDeck;                      //create deck and shuffle
    mainDeck.shuffle();

    dealHand(mainDeck, p1, numCards);   //deal cards to each player
    dealHand(mainDeck, p2, numCards);

    booksChecker(&p1);
    booksChecker(&p2);

    Player pA = p1;
    Player pB = p2;                     //Player variables for different turns in while loop
    Player pT;                          //for swap

    while ((pA.getBookSize() < 13 && pB.getBookSize() < 13)) {
        gfFile << pA.getName() << "'s Turn\n";
        cout << pA.getName() << "'s Turn\n";

        if(pA.getHandSize()!=0 || pB.getHandSize() != 0) {


            tempCard = pA.chooseCardFromHand();
            gfFile << pA.getName() <<": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
            cout << pA.getName() <<": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";


            while (pB.rankInHand(tempCard) && (pA.getBookSize()<14)) {                           //While pB has a card that matches pA's request
                gfFile << pB.getName() << ": Yes!\n\n";
                cout << pB.getName() << ": Yes!\n\n";
                Card cardMatch = pB.removeCardFromHand(tempCard);       //remove card from pB's hand and add it to pA's
                pA.addCard(cardMatch);
                booksChecker(&pA);                                      //add pA's new pair to books
                if (pA.getBookSize() < 14) {
                    tempCard = pA.chooseCardFromHand();                     //choose new card for while conditions
                    gfFile << pA.getName() << ": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
                    cout << pA.getName() << ": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
                }
                //WE NEED TO DO SOMETHING HERE SO THAT PA DOESNT ASK AGAIN AFTER HE's WON
            }

            if (pA.getBookSize() < 14 && pB.getBookSize() < 14 && mainDeck.size() > 0) {
                gfFile << pB.getName() <<": Go Fish!\n\n";                                     //pB did not have a card that matched pA's go fish
                cout << pB.getName() <<": Go Fish!\n\n";
                if (mainDeck.size() != 0) {
                    dealHand(mainDeck, pA, 1);
                }
                booksChecker(&pA);
            }

            pT = pA;                                                    //Swap player's turns
            pA = pB;
            pB = pT;
        }

    }

    if (pA.getBookSize() == pB.getBookSize()) {
        gfFile << "Y'all tied!\n";
    } else {
        gfFile << pB.getName() << " wins!\n";
        cout << pA.getName() << "'s Books: " << pA.showBooks() << endl;
        cout << pB.getName() << "'s Books: " << pB.showBooks() << endl;

        cout << pA.getName() << "'s Hand: " << pA.showHand() << endl;
        cout << pB.getName() << "'s Hand: " << pB.showHand() << endl;

        cout << "Main Deck Size:" << mainDeck.size() << endl;

        cout << "Total Cards:" << mainDeck.size()+(2*pA.getBookSize())+pA.getHandSize()+(2*pB.getBookSize())+pB.getHandSize()<< endl;

        cout << pB.getName() << " wins!\n";
    }

//    tempCard = p1.chooseCardFromHand();
//
//    gfFile << "Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
//




    cout << "End of GoFish!" << endl;

    gfFile.close();
}

void booksChecker(Player *p){
    //Checking Pair, Booking the Card, and Remove Cards//

    //Check Hand Tester//
        Card* card1 = new Card();
        Card* card2 = new Card();

      while(p->checkHandForBook(*card1, *card2)) {
          //Book Cards //
          p->bookCards(*card1, *card2);
          //Remove Cards Hand//
          p->removeCardFromHand(*card1);
          p->removeCardFromHand(*card2);
      }



}


void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
