//
//  main.cpp
//  Pokedex
//
//  Created by Ryan on 12/16/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#include "pokedex.h"

int main() {
    pokedex alolaDex;
//    pokedex johtoDex;
//    pokedex kantoDex;
    int mainMenu = 0;
    int searchMenu = 0;
    char sName[NAME];
    char delName[NAME];
    char sType[TYPE];
    int sNum = 0;
    do {
//        int mainMenu = 0;
        mainMenu = alolaDex.mainMenu();
        switch (mainMenu) {
            case 1:
                alolaDex.displayAll();
                break;
            case 2:
                do {
                    alolaDex.readIn();
                } while (alolaDex.another());
                break;
            case 3:
                do {
//                    int searchMenu = 0;
                    searchMenu = alolaDex.searchMenu();
                    switch (searchMenu) {
                        case 1:
                            if (alolaDex.searchName(sName));
                            else
                                cout << "\nNo match!\n";
                            break;
                        case 2:
                            if (alolaDex.searchType(sType));
                            else
                                cout << "\nNo match!\n";
                            break;
                        case 3:
                            if (alolaDex.searchNum(sNum));
                            else
                                cout << "\nNo Match!\n";
//                            alolaDex.mainMenu();
                            break;
                        case 4:
                            break;
                    }
                } while (searchMenu != 4 && alolaDex.toMenu());
//                if (alolaDex.searchName(sName));
//                else
//                    cout << "\nNo match!";
                break;
            case 4:
                if (alolaDex.delEntry(delName));
                else
                    cout << "\nNo match!";
                break;
            case 5:
                break;
            //default:
                //cout << "\nBack to menu\n";
                //alohaDex.toMenu();
        }
    } while (mainMenu != 5 && alolaDex.toMenu());
//    do {
//        alohaDex.readIn();
//    } while (alohaDex.another());
//    alohaDex.displayAll();
    cout << "\n\nGotta catch 'em all!!\n"
        << "\n(Press ENTER/RETURN to exit)\n";
    cin.get();
    return 0;
}
