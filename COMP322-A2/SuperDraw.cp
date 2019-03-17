/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Assignment 2
 * File:   SuperDraw.cpp
 * Author: Margaret Gu
 * Student ID: 260723084
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ticket.h"
#include "SuperDraw.h"

SuperDraw::SuperDraw() {
    this->length = 0;
    this->ticketListHead = NULL;
    this->ticketListTail = NULL;
    
    cout << "SuperDraw is being created (Question 1)" << endl;
}
SuperDraw::SuperDraw(int count) {
    this->length = 0;
    this->ticketListHead = NULL;
    this->ticketListTail = NULL;

    for(int i=0;i<count;i++) {
        this->newTicket(); //verbose=1 to show details
    }
    cout << this->length << " new ticket were successfully generated." << endl;
    cout << "The numbers are:";
    ticket* p = ticketListHead;
    for (int j = 0; j < this->length; j++) {
        for (int i = 0; i < sizeof(p->numbers)/sizeof(*p->numbers); i++) {
            cout << p->numbers[i] ;
            if ( i <sizeof(p->numbers)/sizeof(*p->numbers)-1) 
                cout << ",";
        }
        if (j < this->length - 1 )
            cout << " and ";
        else 
            cout << endl;
        p = p->next;
    }
    cout << endl;
}
SuperDraw::SuperDraw(const SuperDraw &sd) {
    this->length = sd.length;
    this->ticketListHead = sd.ticketListHead;
    this->ticketListTail = sd.ticketListTail;
    
    cout << "SuperDraw is being copied (Question 8)" << endl;
}

SuperDraw::~SuperDraw() {

    cout << "SuperDraw tickets are being destroyed (question 7)" << endl;

    this->clearTickets();
    
    free(this->ticketListHead);
    free(this->ticketListTail);
        
}

void SuperDraw::newTicket(int verbose) {
    //generate 6 numbers array
    
    ticket *temp = new ticket();
 
     temp->next=NULL;
      if(ticketListHead==NULL)
      {
        this->ticketListHead=temp;
        this->ticketListTail=temp;
      }
      else
      {	
        this->ticketListTail->next=temp;
        this->ticketListTail=this->ticketListTail->next;

      }    
    this->length++;
    
    
    if (verbose == 1) {
        cout << "A new ticket was successfully generated. The numbers are: ";
        for (int i = 0; i < sizeof(temp->numbers)/sizeof(*temp->numbers); i++)
            cout << temp->numbers[i] << " ";
         cout << endl;
    } 
}

void SuperDraw::newTicket(unsigned int *myNumbers, int verbose) {
    //generate 6 numbers array
    
    ticket *temp = new ticket(myNumbers);
 
     temp->next=NULL;
      if(ticketListHead==NULL)
      {
        this->ticketListHead=temp;
        this->ticketListTail=temp;
      }
      else
      {	
        this->ticketListTail->next=temp;
        this->ticketListTail=this->ticketListTail->next;

      }    
    this->length++;
    
    
    if (verbose == 1) {
        cout << "A new ticket was successfully generated. The numbers are: ";
        for (int i = 0; i < sizeof(temp->numbers)/sizeof(*temp->numbers); i++)
            cout << temp->numbers[i] << " ";
         cout << endl;
    } 
}

void SuperDraw::clearTickets() {
        
    ticket* current = this->ticketListHead;
    ticket* next;

    while (current != NULL)
        {
          next = current->next;
          free(current);
          current = next;
        }
    this->ticketListHead = NULL; 
    this->length = 0;
}

void SuperDraw::printAllTicketNumbers() {
    if (ticketListHead==NULL)
        cout << "We found no tickets to print" << endl;

    cout << "We found "<< this->length <<" generated tickets:" << endl;
    ticket* p = ticketListHead;
    for (int j = 0; j < this->length; j++) {
        for (int i = 0; i < sizeof(p->numbers)/sizeof(*p->numbers); i++)
            cout << p->numbers[i] << " ";
         cout << endl << endl;
        p = p->next;
    }

}

bool SuperDraw::matchedNodeWithNumbers(ticket *tkt, unsigned int *myNumbers) {
    int num_size = 6; //sizeof(myNumbers)/sizeof(*myNumbers);
    int tkt_num_size = sizeof(tkt->numbers)/sizeof(*tkt->numbers);
    //cout << "num_size " << num_size << " : " << tkt_num_size << endl;
    if (num_size == tkt_num_size) {
        int match_cnt = 0;
        for (int i = 0; i < tkt_num_size; i++) {
            bool matched = 0;
            for (int k = 0; k < 6; k++) {
                if (tkt->numbers[i] == myNumbers[k])
                    matched = 1;
            }
            if (matched) 
                match_cnt++;
        }
        if (num_size == match_cnt)
            return 1;
    }
    return 0;
}

bool SuperDraw::verifySequence(unsigned int *myNumbers) {
    int num_size = sizeof(*myNumbers);
    
    ticket* p = ticketListHead;
    for (int j = 0; j < this->length; j++) {
        int match_cnt = 0;
        for (int i = 0; i < sizeof(p->numbers)/sizeof(*p->numbers); i++) {
            bool matched = 0;
            for (int k = 0; k < sizeof(*myNumbers); k++) {
                if (p->numbers[i] == myNumbers[k])
                    matched = 1;
            }
            if (matched) 
                match_cnt++;
        }
        if (num_size == match_cnt)
            return 1;
        p = p->next;
    }
    return 0;
    
}

bool SuperDraw::deleteSequence(unsigned int *myNumbers) {
    if (this->verifySequence(myNumbers)) {
        ticket* p = ticketListHead;
        
        if (this->matchedNodeWithNumbers(p, myNumbers)) {
            // test delete first node
                if(this->ticketListHead->next == NULL)  
                {  
                    this->ticketListHead=NULL;
                    this->ticketListTail=NULL;
                    this->length=0;
                }  
                // Copy the data of next node to head 
                //this->ticketListHead->numbers = this->ticketListHead->next->numbers;
                for (int i = 0; i < sizeof(this->ticketListHead->numbers); i++) {
                    this->ticketListHead->numbers[i] = this->ticketListHead->next->numbers[i];
                }
                // store address of next node  
                myNumbers = this->ticketListHead->next->numbers;  

                // Remove the link of next node  
                this->ticketListHead->next = this->ticketListHead->next->next;  

                // free memory  
                free(myNumbers);
                this->length--;
                cout << "The provided sequence of numbers was successfully deleted." << endl;
                return 1;
        }
        while (p->next!=NULL) {
            ticket* tk = p->next;
            if (this->matchedNodeWithNumbers(tk, myNumbers)) {
                myNumbers = p->next->numbers;  

                // Remove the link of next node  
                p->next = p->next->next;  

                // free memory  
                free(myNumbers);
                this->length--;
                cout << "The provided sequence of numbers was successfully deleted." << endl;
                return 1;
            }
            p = p->next;
        }
        
    } 
       cout << "The provided sequence of numbers was never generated before" << endl;
       return 0;
    
}
