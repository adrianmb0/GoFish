//
// Project Finished by Adrian Melo and David Fernandez
//

#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "card.h"

using namespace std;

//Creates a generic player
Player::Player(){
    myName = "Default Player";
}

//adds a card to the hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
}
//
////OPTIONAL
//// comment out if you decide to not use it
////this function will check a players hand for a pair.
////If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//bool Player::checkHandForBook(Card &c1, Card &c2){
//
//}
//
//
///OPTIONAL
/// comment out if you decide to not use it
///Does the player have a card with the same rank as c in her hand?

//bool Player::rankInHand(Card c) const{
//
//}




////uses some strategy to choose one card from the player's
////hand so they can say "Do you have a 4?"

Card Player::chooseCardFromHand() const{
    //should we sort the cards then go through them individually?

    return(myHand[0]);

}


////Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{

}

////Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    Card temp(1, Card::spades);

    for(int i = 0; i< getHandSize(); i++){
        if(c == myHand[i]){
            temp = myHand[i];
            myHand.erase((myHand.begin())+i);
            return temp;
        }
    }
}

string Player::showHand() const{
    vector<Card>::const_iterator iter;
    string hand;

    for(iter = (myHand.begin()); iter!=myHand.end(); iter++){
        hand+= iter->toString();
    }
    return hand;
}

string Player::showBooks() const{

}

int Player::getHandSize() const{
    vector<Card>::const_iterator iter;
    int size = 0;

    for(iter = (myHand.begin()); iter!=myHand.end(); iter++){
        size ++;
    }
    return size;
}


int Player::getBookSize() const{
    vector<Card>::const_iterator iter;
    int size = 0;

    for(iter = (myBook.begin()); iter!=myBook.end(); iter++){
        size ++;
    }

    return size;
}
