//
//  pokedexData.cpp
//  Pokedex
//
//  Created by Ryan on 12/17/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#include "pokedex.h"

//------------------------------------------------------------------------------------

pokedex::pokedex() {
    //entries entry;
    //entry.name = NULL;
    //entry.desc = NULL;
    //entry.type1 = NULL;
    //ent\ry.type2 = NULL;
    //entry.bio = NULL;
    PDtotal = MAX;
    PDcount = 0;
    head = NULL;
    cout << "\nloadFile()";
    loadFile();
}

//------------------------------------------------------------------------------------

pokedex::~pokedex() {
    cout << "\nwriteFile()";
    writeFile();
    delAll();
    cout << "\nNode memory deallocated\n";
}

//------------------------------------------------------------------------------------

void pokedex::readIn() {
    entries entry;
    char nameIn[NAME];
    char descIn[DESC];
    char type1In[TYPE];
    char type2In[TYPE];
    char bioIn[BIO];
    //char response = 'n';
    //bool answer = false;
    
    do {
        cout << "\n++ == ++ == ++ == ++ == ++ == ++ == ++ == ++\n"
            << "\nPokémon number << ";
        cin >> entry.number;
        cin.ignore(SIZE,'\n');
        if (cin.fail() || entry.number > PDtotal)
            cout << "\nError - enter a valid number << ";
        while (cin.fail() || entry.number > PDtotal) {
            //cout << "\nError - enter a valid number: ";
            cin.clear();
            cin.ignore();
            cin >> entry.number;
            cin.ignore(SIZE,'\n');
        }
        //do {} while (cin.fail() && !isdigit(entry.number))
        
        cout << "\nPokémon name << ";
        cin.get(nameIn,NAME,'\n');
        cin.ignore(NAME,'\n');
        nameIn[0] = toupper(nameIn[0]);
        entry.name = new char[strlen(nameIn)+1];
        strcpy(entry.name, nameIn);
        // eg: grass quill pokemon
        cout << "\nDescriptior phrase << ";
        cin.get(descIn,DESC,'\n');
        cin.ignore(DESC,'\n');
        descIn[0] = toupper(descIn[0]);
        for (int i = 0; i < strlen(descIn); ++i) {
            if (descIn[i] == ' ')
                descIn[i+1] = toupper(descIn[i+1]);
        }
        entry.desc = new char[strlen(descIn)+1];
        strcpy(entry.desc, descIn);
        cout << "\nType 1 << ";
        cin.get(type1In,TYPE,'\n');
        cin.ignore(TYPE,'\n');
        for (int i = 0; i < strlen(type1In); ++i)
            type1In[i] = toupper(type1In[i]);
        entry.type1 = new char[strlen(type1In)+1];
        strcpy(entry.type1, type1In);
        // add type 2 as an optional input, most pokemon will be one type
        //char response = 'n';
        //cout << "\n2nd Type? (Y/N): ";
        //cin >> response;
        //cin.ignore(SIZE,'\n');
    
        
            //if (response == 'Y' || response == 'y')
            //    answer = true;
        if (typeTwoCheck()) {
            cout << "\nType 2 << ";
            cin.get(type2In,TYPE,'\n');
            cin.ignore(TYPE,'\n');
            for (int i=0;i<strlen(type2In);++i)
                type2In[i] = toupper(type2In[i]);
            entry.type2 = new char[strlen(type2In)+1];
            strcpy(entry.type2, type2In);
        }
        
        else {
            //char type2blank[2] = {' ','\0'};
            type2In[0] = ' ';
            type2In[1] = '\0';
            //for (int i=0;i<strlen(type2In);++i)
            //    type2In[i] = toupper(type2In[i]);
            entry.type2 = new char[2];
            strcpy(entry.type2, type2In);
            cout << "\nNo 2nd type set.\n";
        }
            
//            while (cin.fail()) {
//                cout << "\nError 1 - Enter Y or N: ";
//                cin.clear();
//                cin.ignore(SIZE,'\n');
//                cin >> response;
//                cin.ignore(SIZE,'\n');
//            }
            
            //if (response!='Y'&&response!='y'&&response!='N'&&response!='n')
            //    cout << "\nError 2 - Enter  Y or N\n";
        
        cout << "\nHeight (feet) << ";
        cin >> entry.heightFeet;
        cin.ignore(SIZE,'\n');
        while (cin.fail()) {
            cout << "Error - Enter a valid number << ";
            cin.clear();
            cin.ignore(SIZE,'\n');
            cin >> entry.heightFeet;
            cin.ignore(SIZE,'\n');
        }
        cout << "\nHeight (inches) << ";
        cin >> entry.heightInch;
        cin.ignore(SIZE,'\n');
        while (cin.fail()) {
            cout << "Error - Enter a valid number << ";
            cin.clear();
            cin.ignore(SIZE,'\n');
            cin >> entry.heightInch;
            cin.ignore(SIZE,'\n');
        }
        cout << "\nWeight in lbs (can be decimal) << ";
        cin >> entry.weight;
        cin.ignore(SIZE,'\n');
        while (cin.fail()) {
            cout << "Error - Enter a valid number << ";
            cin.clear();
            cin.ignore(SIZE,'\n');
            cin >> entry.weight;
            cin.ignore(SIZE,'\n');
        }
        cout << "Short bio << ";
        cin.get(bioIn,BIO,'\n');
        cin.ignore(BIO,'\n');
        entry.bio = new char[strlen(bioIn)+1];
        strcpy(entry.bio, bioIn);
    } while (confirm());
    ++PDcount;
    listInsert(entry);
    cout << "\n* * * * REGISTERED!! * * * *\n";
}

//------------------------------------------------------------------------------------

void pokedex::displayAll() {
    node * current = head;
    cout << "\n\nPokédex Entries (" << PDcount << ") out of (" << PDtotal << "):\n"
         << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
    while (current) {
//        cout << '\n';
        if (current->data.number < 10)
            cout << "00" << current->data.number;
        else if (current->data.number < 100)
            cout << "0" << current->data.number;
        else
            cout << current->data.number;
        cout << '\t' << current->data.name
             << "\n\n" << current->data.desc << '\t' << '\t'
             << "[" << current->data.type1 << "]  ";
        
        char type2blank[2] = {' ','\0'};
        if (!strcmp(current->data.type2, type2blank))
            cout << current->data.type2;
        else
            cout << "[" << current->data.type2 << "]";
            //cout << current->data.type2;
        
        cout << "\nHeight: "
             << current->data.heightFeet << "'" << current->data.heightInch << "''"
             <<"\tWeight: "<< current->data.weight << " lbs."
             << '\n' << current->data.bio << '\n'
             << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
        current = current->next;
    }
}

//------------------------------------------------------------------------------------
