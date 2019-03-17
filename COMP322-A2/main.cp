/*
 * Assignment 2
 * File:   main.cpp
 * Author: Margaret Gu
 * Student ID: 260723084
 *
 */
#include <iostream>
#include "ticket.h"
#include "SuperDraw.h"

using namespace std;

void mainMenu();

int main() {
    //createList(L);
    //createList(L_passed);

    mainMenu();

    return 0;
}

void mainMenu() {
            SuperDraw sd;
            SuperDraw sd2(10);
            unsigned int test_numbers[6] = {6,12,15,40,41,47}; 
            SuperDraw sdcopy;
            
    
    /**
    * IS : List has been created
    * PR : prints menu to user
    *       1. insert new data
    *       2. print all data (List L)
    *       3. find and print a data by ID
    *       4. edit data by ID
    *       5. delete data by ID
    *       6. separate passed member
    *       7. print all data (List L2)
    *       0. exit
    */
    //-------------your code here-------------
    int choice;
    do {
        cout<<"------ Menu -------"<<endl;
        cout<<"1. Question 7 - clear tickets, called by destructor"<<endl;
        cout<<"2. Question 2 - Generate one ticket "<<endl;
        cout<<"3. Question 3 - Generate 10 tickets"<<endl;
        cout<<"4. Question 4 - Print all generated ticket numbers"<<endl;
        cout<<"5. Question 5 - Verify if ticket numbers already generated"<<endl;
        cout<<"6. Question 6 - Delete a ticket"<<endl;
        cout<<"7. Question 5/6 - Create a ticket to test 5 or 6"<<endl;
        cout<<"8. Question 8 - Constructor copy and print all tickets"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"input choice: ";
        cin>>choice;
        switch(choice) {
        case 1:
            sd2.clearTickets();
            cout << "Clear ticket, the print tickets (select 4)" << endl; 
            break;
        case 2:
            sd.newTicket(1);
            cout << "Add ticket on list initialized by simple constructor(SuperDraw sd)" << endl; 
            break;
        case 3:
            sd2.newTicket(1);
            cout << "Add ticket on list initialized by parameterized constructor (SuperDraw sd2(10))" << endl; 
            break;
        case 4:
            cout << "Print all ticket (simple constructor)" << endl;
            sd.printAllTicketNumbers();
            cout << "Print all ticket (2+ tickets constructor)" << endl;
            sd2.printAllTicketNumbers();
            break;
        case 5:
            if (sd2.verifySequence(test_numbers))
                cout << "The provided sequence of numbers was already generated" <<endl;
            else
                cout << "The provided sequence of numbers was never generated before" <<endl;
            break;
        case 6:
            sd2.deleteSequence(test_numbers);
            break;
        case 7:
            sd2.newTicket(test_numbers, 1);
            break;
        case 8:
            sdcopy= sd;
            cout << "Originally generated ticket :" << endl;
            sd.printAllTicketNumbers();
            cout << "Copied generated ticket :" << endl;
            sdcopy.printAllTicketNumbers();
            break;
        case 0:
            return;
        }
            
    } while(true);

    //----------------------------------------
}
