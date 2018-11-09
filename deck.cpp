//
// Project Finished by Adrian Melo and David Fernandez
//



#include "deck.h"
#include "card.h"

//Creates a new deck in order with the Ace of Spades as the first card starting at index 51 and goes to 0
Deck::Deck(){

    int i = 51;

    for(int suit=0 ; suit <= 3; suit++){
        for(int rank = 1; rank <= 13 ; rank++){
            Card newCard(rank, (Card::Suit) suit);
            myCards[i--] = newCard;
        }
    }
}

//Shuffles a deck
void Deck::shuffle(){

    unsigned int currentTime =  (unsigned)time(0);

    Card tempCard(1, Card::spades);

    srand(currentTime);

    //Our random number generator isn't accessing the 0th position
    for (int i = 0; i < myIndex*2; i++) {

        //Random Indexes to swap cards. Modding by (index+1) to access from 0 to index
        int ind1 = rand() % (myIndex+1);
        int ind2 = rand() % (myIndex+1);

        //Swapping of cards
        tempCard = myCards[ind1];
        myCards[ind1] = myCards[ind2];
        myCards[ind2] = tempCard;
    }
}

//Gives the size of the deck
//Output: Amount of cards in deck
int  Deck::size() const {
    //myIndex + 1 because of the index starts at 0 but counting starts at 1
    return (myIndex+1);
}

//Deals a card from the deck
//Output: The card on the top of the array
Card Deck::dealCard(){
    //Need to make a condition to stop dealing after there are no more cards in the deck
    return myCards[myIndex--];
}