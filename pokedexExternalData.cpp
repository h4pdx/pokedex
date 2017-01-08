//
//  pokedexExternalData.cpp
//  Pokedex
//
//  Created by Ryan on 12/19/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#include "pokedex.h"

void pokedex::loadFile() {
    ifstream fileIn;
    entries entry;
    char nameIn[NAME];
    char descIn[DESC];
    char type1In[TYPE];
    char type2In[TYPE];
    char bioIn[BIO];
    fileIn.open("pokedex.txt");
    if (fileIn) {
        // number
        fileIn >> entry.number;
        fileIn.ignore(NAME,'\n');
        while (fileIn && !fileIn.eof()) {
//            name
            fileIn.get(nameIn,NAME,'\n');
            fileIn.ignore(NAME,'\n');
            entry.name = new char[strlen(nameIn)+1];
            strcpy(entry.name, nameIn);
//            description
            fileIn.get(descIn,DESC,'\n');
            fileIn.ignore(DESC,'\n');
            entry.desc = new char[strlen(descIn)+1];
            strcpy(entry.desc, descIn);
//            type1
            fileIn.get(type1In,TYPE,'\n');
            fileIn.ignore(TYPE,'\n');
            entry.type1 = new char[strlen(type1In)+1];
            strcpy(entry.type1, type1In);
//            type 2
            fileIn.get(type2In,TYPE,'\n');
//            fileIn.get(type2In,TYPE,'\n');
            fileIn.ignore(TYPE,'\n');
            entry.type2 = new char[strlen(type2In)+1];
            strcpy(entry.type2, type2In);
//            cout << "\nType 2 loaded from file";
//            height
            fileIn >> entry.heightFeet;
            fileIn.ignore(SIZE,'\n');
            fileIn >> entry.heightInch;
            fileIn.ignore(SIZE,'\n');
//            weight
            fileIn >> entry.weight;
            fileIn.ignore(SIZE,'\n');
//            bio
            fileIn.get(bioIn,BIO,'\n');
            fileIn.ignore(BIO,'\n');
            entry.bio = new char[strlen(bioIn)+1];
            strcpy(entry.bio, bioIn);
            listInsert(entry);
            ++PDcount;
            cout << "\nData loaded from file.";
//          prime the pump
            fileIn >> entry.number;
            fileIn.ignore(SIZE,'\n');
        }
        fileIn.clear();
        fileIn.close();
    }
    else
        cout << "Error - File not found.\n";
}

//------------------------------------------------------------------------------------

void pokedex::writeFile() {
    node * current = head;
    ofstream fileOut;
    fileOut.open("pokedex.txt");
    if (fileOut) {
        while (current) {
            fileOut << current->data.number << '\n';
            fileOut << current->data.name << '\n';
            fileOut << current->data.desc << '\n';
            fileOut << current->data.type1 << '\n';
            fileOut << current->data.type2 << '\n';
//            cout << "\nType2 witten to file.";
            fileOut << current->data.heightFeet << '\n';
            fileOut << current->data.heightInch << '\n';
            fileOut << current->data.weight << '\n';
            fileOut << current->data.bio << '\n';
            cout << "\nData written to file.";
            current = current->next;
        }
        fileOut.clear();
        fileOut.close();
    }
    else
        cout << "Error - file not found.\n";
}

//------------------------------------------------------------------------------------
