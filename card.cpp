//
//  card.cpp
//  
//
// Project Finished by Adrian Melo and David Fernandez
//

#include <stdio.h>
#include "card.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;



    Card::Card() {                   //default, ace of spades when creating a card
        mySuit = spades;
        myRank = 1;
    }

    Card::Card(int rank, Suit s) {  //set suit and rank from input parameters
        mySuit = s;
        myRank = rank;
    }

    string Card::toString() const {       //returns the string version i.e. Ac 4h Js
        return (rankString(myRank) + suitString(mySuit));
    }

    bool Card::sameSuitAs(const Card& c) const{
        if(mySuit == c.mySuit){
            return true;
        }else{
            return false;
        }
    }

    //Converts Enum to String
    //Output: suit - s or h or d or c
    string Card::suitString(Suit s) const {
        if (s == spades) {
            return "s";
        } else if (s == hearts) {
            return "h";
        } else if (s == diamonds) {
            return "d";
        } else if (s == clubs) {
            return "c";
        } else {
            return "Error";
        }
    }
    //Converts rank int to String
    //Output: rank - A to K
    string Card::rankString(int r) const {
        if (r == 1) {
            return "A";
        } else if (r > 1 && r < 11) {
            return (to_string(r));
        } else if (r == 11) {
            return "J";
        } else if (r == 12) {
            return "Q";
        } else if (r == 13) {
            return "K";
        } else{
            return "Error";
        }
    }

    //Compares two cards
    //Output: True if equal
    bool Card::operator==(const Card &rhs) const {
        if (myRank != rhs.myRank) {
            return false;
        } else if (mySuit != rhs.mySuit) {
            return false;
        } else {
            return true;
        }
    }

    //Compares two cards
    //Output: True if not equal
    bool Card::operator!=(const Card &rhs) const {
        if (myRank == rhs.myRank) {
            return false;
        } else if (mySuit == rhs.mySuit) {
            return false;
        } else {
            return true;
        }
    }

    //Operator to be able to outputcards
ostream& operator << (ostream& out, const Card& c){
        out << c.toString();
        return out;
    }