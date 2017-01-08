//
//  pokedexUtility.cpp
//  Pokedex
//
//  Created by Ryan on 12/17/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#include "pokedex.h"

//------------------------------------------------------------------------------------

int pokedex::mainMenu() {
    int menuItem = 0;
    cout << "\n\n+ + Main menu! + + + + + + + + + + + + "
    << "\n>> Enter a number >> corresponding option >>\n"
    << "\n\t >>     1     >> Display All Pokédex Entries      >>"
    << "\n\t >>     2     >> Register a new Pokémon entry     >>"
    << "\n\t >>     3     >> Search Pokémon (by NAME or TYPE) >>"
    << "\n\t >>     4     >> Delete Pokémon entry by name     >>"
    << "\n\t >>     5     >> Quit (and Save) Pokédex          >>\n";
    do {
        cout << "\nMenu selection << ";
        cin >> menuItem;
        cin.ignore(SIZE,'\n');
        while (cin.fail()) {
            cin.clear();
            cin.ignore(SIZE,'\n');
            cout << "\nError - Enter a valid number << ";
            cin >> menuItem;
            cin.ignore(SIZE,'\n');
        }
        cout << "\n<< You selected (" << menuItem << ") <<";
    } while (menuItem < 1 || menuItem > 5);
    return menuItem;
}

//------------------------------------------------------------------------------------

int pokedex::searchMenu() {
    int menuItem = 0;
    cout << "\n\n+ + Search Menu! + + + + + + + + + + + + "
    << "\n>> Enter a number >> corresponding option >>\n"
    << "\n\t >>     1     >> Search Pokémon by NAME     >>"
    << "\n\t >>     2     >> Search Pokémon by TYPE     >>"
    << "\n\t >>     3     >> Search Pokémon by NUMBER   >>"
    << "\n\t >>     4     >> Quit search                >>\n";
    do {
        cout << "\nSearch menu selection << ";
        cin >> menuItem;
        cin.ignore(SIZE,'\n');
        while (cin.fail()) {
            cin.clear();
            cin.ignore(SIZE,'\n');
            cout << "\nError - Enter a valid number << ";
            cin >> menuItem;
            cin.ignore(SIZE,'\n');
        }

        cout << "\n << You selected (" << menuItem << ") <<";
    } while (menuItem < 1 || menuItem > 4);
    return menuItem;
}

//------------------------------------------------------------------------------------

bool pokedex::confirm() {
    bool answer = false;
    char response = 'n';
    do {
        cout << "\nIs the entered info correct? (Y/N) << ";
        cin >> response;
        cin.ignore(SIZE,'\n');
        if (response=='N'||response == 'n')
            answer = true;
    } while (response!='Y'&&response!='y'&&response!='N'&&response!='n');
    return answer;
}

//------------------------------------------------------------------------------------

bool pokedex::another() {
    bool answer = false;
    char response = 'n';
    do {
        cout << "\nRegister another entry? (Y/N) << ";
        cin >> response;
        cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            answer = true;
    } while (response!='Y'&&response!='y'&&response!='N'&&response!='n');
    return answer;
}

//------------------------------------------------------------------------------------

bool pokedex::toMenu() {
    bool answer = false;
    char response = 'n';
    do {
        cout << "\nBack to menu? (Y/N) << ";
        cin >> response;
        cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            answer = true;
    } while (response!='Y'&&response!='y'&&response!='N'&&response!='n');
    return answer;
}

//------------------------------------------------------------------------------------

bool pokedex::typeTwoCheck() {
    bool answer = false;
    char response = 'n';
    do {
        cout << "\nEnter a 2nd Type? (Y/N) << ";
        cin >> response;
        cin.ignore(SIZE,'\n');
        if (response == 'Y' || response == 'y')
            answer = true;
    } while (response!='Y'&&response!='y'&&response!='N'&&response!='n');
    return answer;
}

//------------------------------------------------------------------------------------
