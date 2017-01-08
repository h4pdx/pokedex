//
//  pokedexSearch.cpp
//  Pokedex
//
//  Created by Ryan on 12/20/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#include "pokedex.h"

//------------------------------------------------------------------------------------

bool pokedex::searchName(char sName[]) {
    bool match = false;
    if (!head)
        return match;
    node * current = head;
    cout << "\n-_-_- Search _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    cout << "\nSearch Pokémon by name << ";
    cin.get(sName,NAME,'\n');
    cin.ignore(NAME,'\n');
    // this capitalizes the input terms for easier matching,
    // user doesnt have to worry about letter case
    sName[0] = toupper(sName[0]);
    for (int i = 1; i < strlen(sName)+1; ++i) {
        sName[i] = tolower(sName[i]);
    }
    while (current && !match) {
        if (!strcmp(current->data.name, sName)) {
            match = true;
            cout << "\n-_-_-_ Match! -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
            if (current->data.number < 10)
                cout << "00" << current->data.number;
            else if (current->data.number < 100)
                cout << "0" << current->data.number;
            else
                cout << current->data.number;
            cout << '\t' << current->data.name
            << "\n\n" << current->data.desc << '\t' << '\t'
            << "[" << current->data.type1 << "]  ";
            // << current->data.type2;
            char type2blank[2] = {' ','\0'};
            if (!strcmp(current->data.type2, type2blank))
                cout << current->data.type2;
            else
                cout << "[" << current->data.type2 << "]";
            cout << "\nHeight: "
            << current->data.heightFeet << "'" << current->data.heightInch << "''"
            <<"\tWeight: "<< current->data.weight << " lbs."
            << '\n' << current->data.bio << '\n'
            << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
        }
        current = current->next;
    }
    return match;
}

//------------------------------------------------------------------------------------

bool pokedex::searchType(char aType[]) {
    bool match = false;
    if (!head)
        return match;
    node * current = head;
    cout << "\n-_-_- Search _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    cout << "\nSearch Pokémon by Type << ";
    cin.get(aType,TYPE,'\n');
    cin.ignore(NAME,'\n');
    for (int i = 0; i < strlen(aType)+1; ++i) {
        aType[i] = toupper(aType[i]);
    }
    while (current) {
        if (!strcmp(current->data.type1, aType) || !strcmp(current->data.type2, aType)) {
            match = true;
            cout << "\n-_-_-_ Match! -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
            if (current->data.number < 10)
                cout << "00" << current->data.number;
            else if (current->data.number < 100)
                cout << "0" << current->data.number;
            else
                cout << current->data.number;
            cout << '\t' << current->data.name
            << "\n\n" << current->data.desc << '\t' << '\t'
            << "[" << current->data.type1 << "]  ";
            // << current->data.type2;
            char type2blank[2] = {' ','\0'};
            if (!strcmp(current->data.type2, type2blank))
                cout << current->data.type2;
            else
                cout << "[" << current->data.type2 << "]";
            cout << "\nHeight: "
            << current->data.heightFeet << "'" << current->data.heightInch << "''"
            <<"\tWeight: "<< current->data.weight << " lbs."
            << '\n' << current->data.bio << '\n' << '\n';
//            << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
        }
        current = current->next;
    }
    return match;
}

//------------------------------------------------------------------------------------

bool pokedex::searchNum(int sNum) {
    bool match = false;
    if (!head)
        return match;
    node * current = head;
    char type2blank[2] = {' ','\0'};
    cout << "\n-_-_- Search _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    cout << "\nSearch Pokémon by NUMBER << ";
    cin >> sNum;
    cin.ignore(SIZE,'\n');
    while (cin.fail()) {
        cin.clear();
        cin.ignore(SIZE,'\n');
        cout <<"\nError - Enter a valid number << \n";
        cin >> sNum;
        cin.ignore(SIZE,'\n');
    }
    while (current && !match) {
        if (current->data.number == sNum) {
            match = true;
            cout << "\n-_-_-_ Match! -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
            if (current->data.number < 10)
                cout << "00" << current->data.number;
            else if (current->data.number < 100)
                cout << "0" << current->data.number;
            else
                cout << current->data.number;
            cout << '\t' << current->data.name
                 << "\n\n" << current->data.desc << '\t' << '\t'
                 << "[" << current->data.type1 << "]  ";
            // << current->data.type2;
            //char type2blank[2] = {' ','\0'};
            if (!strcmp(current->data.type2, type2blank))
                cout << current->data.type2;
            else
                cout << "[" << current->data.type2 << "]";
            cout << "\nHeight: "
                 << current->data.heightFeet << "'" << current->data.heightInch << "''"
                 <<"\tWeight: "<< current->data.weight << " lbs."
                 << '\n' << current->data.bio << '\n' << '\n'
                 << "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";

        }
        current = current->next;
    }
    return match;
}

//------------------------------------------------------------------------------------

bool pokedex::delEntry (char delName[]) {
    bool match = false;
    if (!head)
        return match;
    node * current = head;
    node * follow = NULL;
//    cout << "\n-- == -- == -- == -- == -- == -- == -- == -- == --\n"
    cout << "\n-_-_- Delete Entry _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n"
        << "\nSearch & delete by name << ";
    cin.get(delName,NAME,'\n');
    cin.ignore(NAME,'\n');
//     if head is the match
    if (!strcmp(head->data.name, delName)) {
        match = true;
        current = head->next;
        head->data.number = 0;
        delete [] head->data.name;
        head->data.name = NULL;
        delete [] head->data.desc;
        head->data.desc = NULL;
        delete [] head->data.type1;
        head->data.type1 = NULL;
        delete [] head->data.type2;
        head->data.type2 = NULL;
        head->data.heightFeet = 0;
        head->data.heightInch = 0;
        head->data.weight = 0.0;
        delete [] head->data.bio;
        head->data.bio = NULL;
        delete head;
        head = current;
        --PDcount;
        cout << "\n- - - Pokédex Entry deleted!! - - -\n";
    }
    else {
        for (int i = 0; i<PDcount && !match && current; ++i) {
            follow = current;
            current = current->next;
            if (current && !strcmp(current->data.name, delName)) {
                match = true;
                follow->next = current->next;
                current->data.number = 0;
                delete [] current->data.name;
                current->data.name = NULL;
                delete [] current->data.desc;
                current->data.desc = NULL;
                delete [] current->data.type1;
                current->data.type1 = NULL;
                delete [] current->data.type2;
                current->data.type2 = NULL;
                current->data.heightFeet = 0;
                current->data.heightInch = 0;
                current->data.weight = 0.0;
                delete [] current->data.bio;
                current->data.bio = NULL;
                delete current;
                --PDcount;
                cout << "\n- - - Pokédex Entry deleted!! - - -\n";
            }
        }
    }
    return match;
}

//------------------------------------------------------------------------------------
