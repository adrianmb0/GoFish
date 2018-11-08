//
// Created by David Fernandez on 11/7/18.
//



#include "deck.h"
#include "card.h"


Deck::Deck(){

    int i = 51;

    for(int suit=0 ; suit < 4; suit++){
        for(int rank = 1; rank < 13 ; rank++){
            Card newCard(rank, (Card::Suit) suit);//initialize card here
            myCards[i--] = newCard;
        }
    }
}

void Deck::shuffle(){

    unsigned int currentTime =  (unsigned)time(0);

    Card tempCard(1, Card::spades);

    srand(currentTime);

    for (int i = 0; i < myIndex*2; i++) {
        int ind1 = rand() % myIndex + 1;
        int ind2 = rand() % myIndex + 1;

        tempCard = myCards[ind1];
        myCards[ind1] = myCards[ind2];
        myCards[ind2] = tempCard;
    }


}

Card Deck::dealCard(){
    return myCards[myIndex--];

}