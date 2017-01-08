//
//  pokeList.h
//  Pokedex
//
//  Created by Ryan on 12/16/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#ifndef pokeList_h
#define pokeList_h


//#endif /* pokeList_h */

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

//------------------------------------------------------------------------------------

const int MAX = 750;
const int SIZE = 100;
const int NAME = 21;
const int TYPE = 11;
const int DESC = 26;
const int BIO = 181;

//------------------------------------------------------------------------------------

struct entries {
    int number;
    char * name;
    char * desc;
    char * type1;
    char * type2;
    int heightFeet;
    int heightInch;
    double weight;
    char * bio;
};

//------------------------------------------------------------------------------------

struct node {
    entries data;
    node * next;
};

//------------------------------------------------------------------------------------

class pokedex {
    private:
        int PDcount;
        int PDtotal;
        node * head;
    public:
        pokedex();
        ~pokedex();
        void delAll();  // destructor helper
        bool delHead(); // destructor helper
        // primary
        void readIn();
        void displayAll();
        void listInsert(entries & entry);
        void writeFile();
        void loadFile();
        // secondary
        bool searchName(char sName[]);
        bool searchType(char aType[]);
        bool delEntry(char delName[]);
        bool searchNum(int sNum);
        // tertiary
        void welcome();
        int mainMenu();
        int searchMenu();
        bool confirm();
        bool another();
        bool toMenu();
        bool typeTwoCheck();
        //void addBrackets(char typeIn[]);
};

//------------------------------------------------------------------------------------

#endif
