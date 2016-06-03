/*
 * FriendsBook.cpp - Assignment 1
 *
 * Class Description: Social network application.
 *
 * In this version, we use our MyADT.
 *
 * Created on: May 18, 2016
 * Author: AL
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#include "Profile.h"
#include "MyADT.h"



void join(MyADT* theMembers) {
    string theName = "";
    
    // Create a new member profile
    cout << "Please, enter your name: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, theName);
    Profile theMember(theName);
    
    // Add new member profile to list
    if ( theMembers->insert(theMember) )
        // Report to user
        cout << "Member: " << theMember << " has successfully joined FriendsBook." << endl;
    else
        cout << "Member: " << theMember << " has not joined FriendsBook as she/he is already a member!" << endl;
    
    return;
}

void leave(MyADT* theMembers) {
    string theName = "";
    
    // Create the member profile
    cout << "Please, enter your name: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, theName);
    Profile theMember(theName);
    
    // Remove member profile from list
    if ( theMembers->remove(theMember) )
        cout << "Member : " << theMember << " has now left the network." << endl;
    else
        cout << "Member : " << theMember << " is not a member!" << endl;
    
    return;
}


void search(MyADT* theMembers) {
    string theName = "";
    
    // Create a new member profile
    cout << "Please, enter the name of the member you are looking for: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, theName);
    Profile theMember(theName);
    
    // Add new member profile to list
    Profile * target = theMembers->search(theMember);
    
    if ( target != NULL )
        // Report to user
        cout << "Member: " << target->getName() << " has been successfully found in FriendsBook." << endl;
    else
        cout << "Member : " << theMember.getName() << " is not a member of FriendsBook." << endl;
    return;
}


void modify(MyADT* theMembers) {
    string newString = "";
    string theName = "";
    
    
    // Create a new member profile
    cout << "Please, enter the name of the member you are looking for: ";
    // Remove all leading whitespace -> ws
    getline(cin >> ws, theName);
    Profile theMember(theName);
    
    // Add new member profile to list
    Profile * target = theMembers->search(theMember);
    
    if ( target != NULL ) {
        
        cout << "Modifying member : " << target->getName() << endl;
        cout << "Please, enter the new image for this member: ";
        // Remove all leading whitespace -> ws
        getline(cin >> ws, newString);
        if ( !newString.empty() ) target->setImage(newString);
        cout << "Please, enter the new status of this member: ";
        // Remove all leading whitespace -> ws
        getline(cin >> ws, newString);
        if ( !newString.empty() ) target->setStatus(newString);
        
        cout << "Please, enter the friend name to be inserted: ";
        // Remove all leading whitespace -> ws
        getline(cin >> ws, newString);
        if ( !newString.empty() ) target->addFriend(newString);
        
        // Report to user
        cout << "Status of member : " << target->getName() << " has been successfully modified in FriendsBook." << endl;
    } else
        cout << "Member : " << theMember << " is not a member of FriendsBook." << endl;
    
    
    return;
}


int main() {
    
    // Variables declaration
    MyADT* members = new MyADT();
    bool done = false;
    char input = 0;
    
    int elements = members->getElementCount();
    
    Profile *someProfile = new Profile();
    someProfile->setName("Aoe");
    
    Profile *jane = new Profile("Jane");
    Profile *bob = new Profile("Bob");
    Profile *bobby = new Profile("Bobby");
    Profile *casey = new Profile("casey");
    Profile *debbie = new Profile("debbie");
    Profile *ernie = new Profile("ernie");
    Profile *fei = new Profile("fei");
    
    Profile *dibby = new Profile("dibby");
    Profile *debby = new Profile("debby");
    Profile *dabby = new Profile("dabby");
    Profile *dubby = new Profile("dubby");
    Profile *dobby = new Profile("dobby");
    
    members->insert(*jane);
    members->insert(*jane);
    members->insert(*bob);
    members->insert(*ernie);
    members->insert(*fei);
    members->insert(*casey);
    members->insert(*bobby);
    members->insert(*debbie);
    
    
    cout << *members;
    
    
    members->insert(*dibby);
    members->insert(*debby);
    members->insert(*dabby);
    members->insert(*dubby);
    members->insert(*dobby);
    
    cout << *members;
    
    
    members->remove(*someProfile);
    members->printAll();
    members->remove(*jane);
    members->remove(*bob);
    members->remove(*ernie);
    members->printAll();
    members->remove(*fei);
    members->remove(*fei);
    members->printAll();
    members->remove(*casey);
    members->remove(*bobby);
    members->remove(*debbie);
    cout << *members;
    
    
    // Keep doing what the user selects until the user exits
    while (not done) {
        // Print menu to user
        cout << "\n----Welcome to FriendsBook!\n" << endl;
        cout << "To join the network and create a profile  enter: j" << endl;
        cout << "To leave the network\t\t\t  enter: l" << endl;
        cout << "To modify your profile\t\t\t  enter: m" << endl;
        cout << "To search for someone on the network\t  enter: s" << endl;
        cout << "To exit FriendsBook\t\t\t  enter: x\n" << endl;
        
        cout << "Your choice: ";
        cin >> input;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 'm': modify(members); break;
            case 's': search(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
        cout << "There are now " << members->getElementCount() << " members in FriendsBook." << endl;	
        cout << *members << endl;
        
    }
    
    return 0;
}
