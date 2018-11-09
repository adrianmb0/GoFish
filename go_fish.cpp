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
    gfFile.open("gofish_results.txt");

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

    Player pA = p1;
    Player pB = p2;                     //Player variables for different turns in while loop
    Player pT;                          //for swap

    booksChecker(&pA);
    booksChecker(&pB);

    //While Loop conditions: Breaks out if a player reaches 14 books,
    //  or if the either player reaches 0 cards and there are no more cards in the deck
    while ((pA.getBookSize() < 14 && pB.getBookSize() < 14) && ((pA.getHandSize()!=0 || pB.getHandSize() != 0) && mainDeck.size() != 0)) {
        gfFile << pA.getName() << "'s Turn\n";
        cout << pA.getName() << "'s Turn\n";

            //If condition so that if hand is empty after getting a match and still cards in deck
            if(pA.getHandSize() == 0 && mainDeck.size() > 0 ){
                dealHand(mainDeck, pA, 1);
                booksChecker(&pA);
            }

            tempCard = pA.chooseCardFromHand();

            gfFile << pA.getName() <<": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
            cout << pA.getName() <<": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";

            //While pB has a card that matches pA's request
            while (pB.rankInHand(tempCard) && (pA.getBookSize()<14)) {
                gfFile << pB.getName() << ": Yes!\n\n";
                cout << pB.getName() << ": Yes!\n\n";

                //Passing Card from one players hand to the other
                Card cardMatch = pB.removeCardFromHand(tempCard);       //remove card from pB's hand and add it to pA's
                pA.addCard(cardMatch);
                booksChecker(&pA);                                      //add pA's new pair to books

                //If condition so that if hand is empty after getting a match and still cards in deck
                if(pA.getHandSize() == 0 && mainDeck.size() > 0 ){
                    dealHand(mainDeck, pA, 1);
                }
                //Continues Turn
                if (pA.getBookSize() < 14) {
                    tempCard = pA.chooseCardFromHand();                     //choose new card for while conditions
                    gfFile << pA.getName() << ": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
                    cout << pA.getName() << ": Do you have a " << tempCard.rankString(tempCard.getRank()) << "?\n";
                }
            }

            //pB did not have a card that matched pA's go fish
            if (pA.getBookSize() < 14 && pB.getBookSize() < 14 && mainDeck.size() > 0) {
                gfFile << pB.getName() <<": Go Fish!\n\n";
                cout << pB.getName() <<": Go Fish!\n\n";
                if (mainDeck.size() > 0) {
                    dealHand(mainDeck, pA, 1);
                }
                booksChecker(&pA);
            }

            //Swap player's turns
            pT = pA;
            pA = pB;
            pB = pT;
    }

    if (pA.getBookSize() == pB.getBookSize()) {

        gfFile << "Y'all tied!\n";
        cout << "Y'all tied!\n";

    } else {

        gfFile << pB.getName() << " wins!\n";
        cout << pB.getName() << " wins!\n";
    }

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
