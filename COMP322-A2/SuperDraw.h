/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Assignment 2
 * File:   SuperDraw.h
 * Author: Margaret Gu
 * Student ID: 260723084
 *
 */

#ifndef SUPERDRAW_H
#define SUPERDRAW_H

class SuperDraw {
public:
    SuperDraw();
    SuperDraw(int count);
    SuperDraw(const SuperDraw &sd);
    virtual ~SuperDraw();
    void newTicket(int = 0);
    void newTicket(unsigned int *myNumbers, int = 0);
    void printAllTicketNumbers();
    bool verifySequence(unsigned int *myNumbers);
    bool deleteSequence(unsigned int *myNumbers);
    bool matchedNodeWithNumbers(ticket *tkt, unsigned int *myNumbers);
    void clearTickets();
private:
    ticket* ticketListHead;
    ticket* ticketListTail;
    int length;

};

#endif /* SUPERDRAW_H */

