#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

/*
 * Assignment 2
 * File:   ticket.h
 * Author: Margaret Gu
 * Student ID: 260723084
 *
 */

struct ticket {
    /**
     TODO:  create a new Data type with specification:
            - an integer array for lotto numbers
            - pointer to next data
    */
        unsigned int numbers[6];
        ticket* next;
        ticket () {
            time_t t;
    /*get the system time*/
            time(&t);
    /*transfer time_t variable plus a random number and send it to the srand function*/
            srand((unsigned int) t + rand());
            int sz, pos, src[49];
            for (int j = 0; j < sizeof(src)/sizeof(*src); j++)
                src[j] = j + 1;
            sz = 49;
            unsigned int nums[6];
            for (int j = 0; j < 6; j++) {
                pos = rand() % sz;
                nums[j] = src[pos];
                src[pos] = src[sz-1];
                sz--;
            } 
            //sort the random number
            for(int i=0;i<=6;i++) {
                for (int j = 0; j <= 6 - i; j++) {
                    if (nums[j] > nums[j + 1]) {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                    }
                }
            }
            //cout << "Ticket is created, numbers are: " ;
            for (int i = 0; i < sizeof(nums)/sizeof(*nums); i++) {
                //cout << nums[i] << " ";
                numbers[i]=nums[i];
            }
            //cout << endl;
            
         }
        ticket (unsigned int *nums) {  //Use manually picked numbers
            
                for (int i = 0; i < 6; i++) {
                     cout << nums[i] << " ";
                    numbers[i]=nums[i];
                }
        }
        
};

#endif // TICKET_H_INCLUDED
