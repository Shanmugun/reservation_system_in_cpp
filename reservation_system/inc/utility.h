/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* FILE NAME     : utility.h
*
* DESCRIPTION   : contains class & utility function declaration which are used in main function.
*
* DATE NAME REFERENCE REASON
*
* Copyright 2021, Aricent Inc.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _UTILITY_H_
#define _UTILITY_H_

/* * * * * * * * * * * * * * * * * * * * * * * * * * Header File Inclusions * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>  //to work with files
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <ctype.h> //isdigit()
#include <ctime>    //to display date and time

using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * Macro Definition * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define SUCCESS 1
#define FAILURE 0

#define SEP ' '

/* * * * * * * * * * * * * * * * * * * * * * * * * * Structure Definition * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * *   Global variable    * * * * * * * * * * * * * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * * * * *  Class Declaration   * * * * * * * * * * * * * * * * * * * * * * * * */

class Bus
    {
        public:
            Bus()
            {
                filename = "../src/data.txt";
            }
            Bus(string i_filename)
            {
                filename = i_filename;
            }
        
            void ExtractAndStoreBusDetails();
            //Extracts bus details from Text File and stores into the datastructure
            void DisplayBusDetails();
            //Displays the Bus Schedule i.e all buses
            
            
        
        protected:
            string filename = "data.txt";
            string date;
            string bus_number;
            string from;
            string to;
            string driver_name;
            string driver_contact_num;
            string num_seats_available;
            
            vector<string> bus_details;
            //from, to, driver_name, driver_contact_num, num_seats_available
            map<string,vector<string>> bmap;
            //bus_number, bus_details(vector)
            multimap<string,map<string,vector<string>>> imap;
            //date, bus_map(multimap)
            //date, bus_num, from, to, driver_name, driver_contact_num, num_seats_available
            
    };

class Reservation: public Bus
    {
        public:
            int SetDateOfJourney();    //Reads & sets date_of_journey value
            int ValidateDate(int dd,int mm,int yy); //Validates date format
            int DispalyAvailableBuses();   //Displays available buses on date_of_journey
            int ReadCustomerDetailsAndBookTicket(); //Reads & sets customers details value
            int BusNumValidation(); //Checks whether the entered bus number is available on date_of_journey or not
            int NumOfSeatsValidation(); //Checks whether the nym_of_seats entered is greater than num_seats_available
            void UpdateInventory();  //Updates the DataBase i.e Text file by decreasing the num_seats_available for particular bus
            void PrintTicket();   //If the BusNum & NumOfSeats Validation return SUCCESS then ticket is printed
            
        private:
            string name;
            int age = 0;
            char gender;
            int bus_num = 0;
            int num_of_seats = 0;
            string date_of_journey;
            string i_from;
            string i_to;
            string i_driver;
            string i_driver_num;
    };

/* * * * * * * * * * * * * * * * * * * * * * * * * * Function Declaration * * * * * * * * * * * * * * * * * * * * * * * * */

#endif
