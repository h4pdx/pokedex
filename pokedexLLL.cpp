//
//  pokedexLLL.cpp
//  Pokedex
//
//  Created by Ryan on 12/17/16.
//  Copyright © 2016 Fatal_Error. All rights reserved.
//

#include "pokedex.h"

//------------------------------------------------------------------------------------

// sorted by pokedex number
// seacrh function can do the sorting by type/name/
void pokedex::listInsert(entries &entry) {
//    this takes place after each user or file input.
//    create a new node to encapsulate the node data,
//    which is an object of the struct 'entries'.
    node * temp = new node;
    temp->data = entry;
    temp->next = NULL;
    cout << "\nNew node allocated";
//    if there is no list; this entry is the 1st
    if (!head) {
//        node * temp = new node;
//        temp->data = entry;
//        temp->next = NULL;
        head = temp;
        cout << "\nFirst (and only) node assigned";
        return;
    }
//    if the new entry needs to be inserted before the current 1st
    if (head->data.number > temp->data.number) {
//        node * temp = new node;
//        temp->data = entry;
        temp->next = head;
        head = temp;
        cout << "\nFirst node replaced.";
    }
//    if the new node clears those two conditions, then ...
//    traversal with two pointers
//    find where the new node needs to be inserted
    node * follow = NULL;
    node * current = head;
    while (current && (current->data.number < temp->data.number)) {
        follow = current;
        current = current->next;
        cout << "\nTraversal to sorted node allocation point.";
    }
    // once loop has brought us to our insertion point in list
    // follow is initialized as NULL,
    // will only be true past the head node.
    if (follow) {
//        node * temp = new node;
//        temp->data = entry;
        follow->next = temp;
        temp->next = current;
        cout << "\nNode inserted in sorted list.";
    }
}

//------------------------------------------------------------------------------------

void pokedex::delAll() {
    while (delHead());
}

//------------------------------------------------------------------------------------

bool pokedex::delHead() {
    if (!head)
        return false;
    node * current = head->next;
    head->data.number = 0;
    delete [] head->data.name;
    head->data.name = NULL;
    delete [] head->data.desc;
    head->data.desc = NULL;
    delete [] head->data.type1;
    head->data.type1 = NULL;
    delete [] head->data.type2;
    head->data.type2 = NULL;
    //if (head->data.type2) {
    //    delete [] head->data.type2;
    //    head->data.type2 = NULL;
    //}
    head->data.heightFeet = 0;
    head->data.heightInch = 0;
    head->data.weight = 0.0;
    delete [] head->data.bio;
    head->data.bio = NULL;
    delete head;
    head = current;
    return true;
}

//------------------------------------------------------------------------------------
