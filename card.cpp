//
//  card.cpp
//  
//
//  Created by David Fernandez on 11/6/18.
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
            return "Error";          // is this right?
        }
    }

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


    bool Card::operator==(const Card &rhs) const {
        if (myRank != rhs.myRank) {
            return false;
        } else if (mySuit != rhs.mySuit) {
            return false;
        } else {
            return true;
        }
    }


    bool Card::operator!=(const Card &rhs) const {
        if (myRank == rhs.myRank) {
            return false;
        } else if (mySuit == rhs.mySuit) {
            return false;
        } else {
            return true;
        }
    }

ostream& operator << (ostream& out, const Card& c){
        out << c.toString();
        return out;
    }