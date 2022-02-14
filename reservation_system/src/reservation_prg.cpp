/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * FILE NAME     :   reservation_prg.cpp
 *
 * DESCRIPTION   :   An application in C++ for Bus reservation system.
 *
 *                      Implements the following requirements:
 *
 *                      Requirement Tag             Requirement Description
 *
 *                      TDIR/01            To print the routes plying on a given particular date along with the available seats.
 *
 *                      TDIR/02            To allow booking the seats only if the requires seats are available.
 *
 *                      TDIR/03            To display the ticket on screen after successful booking.
 *
 *                      TDIR/04            To update the available seats in that particular route after every successful booking.
 *
 * DATE  NAME  REFERENCE REASON
 *
 * Copyright 2021, Aricent Inc.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <utility.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * FUNCTION NAME    :   main()
 *
 * DESCRIPTION      :   Calls various functions to implement the following requirements:
 *
 *                      Requirement Tag             Requirement Description
 *
 *                      TDIR/01            To print the routes plying on a given particular date along with the available seats.
 *
 *                      TDIR/02            To allow booking the seats only if the requires seats are available.
 *
 *                      TDIR/03            To display the ticket on screen after successful booking.
 *
 *                      TDIR/04            To update the available seats in that particular route after every successful booking.
 *
 * RETURNS          :   status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main()
{
    
    int status = 0;
    
    Bus bobj;
    //Bus bobj("../src/filename.txt");
    bobj.ExtractAndStoreBusDetails();
    bobj.DisplayBusDetails();
    
    Reservation robj;
    status = robj.SetDateOfJourney();
    if(status == SUCCESS)
    {
        status = robj.DispalyAvailableBuses();
        
        if(status == SUCCESS)
        {
            status = robj.ReadCustomerDetailsAndBookTicket();
            if(status == SUCCESS)
            {
                time_t ttime = time(0);
                tm *local_time = localtime(&ttime);
                cout<<"Reservation done successfully on "<<1 + local_time->tm_hour << ":"<< 1 + local_time->tm_min << ":" << 1 + local_time->tm_sec<<" "<< local_time->tm_mday <<"-"<< 1 + local_time->tm_mon << "-"<< 1900 + local_time->tm_year<<endl<<endl;
                
                robj.UpdateInventory();
                robj.PrintTicket();
            }
        }
    }
    else
    {
        cout<<"Invalid date"<<endl<<endl;
    }
    
    return 0;
}

