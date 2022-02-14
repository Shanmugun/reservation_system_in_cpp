/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* FILE NAME : utility.cpp
*
* DESCRIPTION: contains utility function definition which can be used in main function.
*
* DATE NAME REFERENCE REASON
*
* Copyright 2021, Aricent Inc.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <utility.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  ExtractAndStoreBusDetails()
 *
 *    DESCRIPTION        :  Extracts bus details from Text File and stores into the datastructure
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  void
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Bus::ExtractAndStoreBusDetails() //Extracts bus details from Text File and stores into the datastructure
{
    //string filename = "data.txt";
    string myText;
    ifstream MyReadFile(filename);
    
        
        while (getline(MyReadFile,myText))
        {
            stringstream stream(myText);
            string tok;
            
            //Tokenizing to get details i.e date from to seat_count
            while(getline(stream,tok,SEP)) //extract username   //SEP = ' '
            {
            
                date = tok;
                
                while(getline(stream,tok,SEP))//SEP = ' '
                {
                    
                    bus_number = tok;
                    
                    while(getline(stream,tok,SEP))//SEP = ' '
                    {
                        from =tok;
                        bus_details.push_back(from);
                        
                        while(getline(stream,tok,SEP))//SEP = ' '
                        {
                            to =tok;
                            bus_details.push_back(to);
                            
                            while(getline(stream,tok,SEP))//SEP = ' '
                            {
                                driver_name = tok;
                                bus_details.push_back(driver_name);
                                
                                while(getline(stream,tok,SEP))//SEP = ' '
                                {
                                    driver_contact_num = tok;
                                    bus_details.push_back(driver_contact_num);
                                    
                                    while(getline(stream,tok,SEP))//SEP = ' '
                                    {
                                        num_seats_available = tok;
                                        bus_details.push_back(num_seats_available);
                                    }
                                }
                            }
                        }
                    }
                    
                    //Inserting bus details into multimap
                    bmap.insert({bus_number,bus_details});
                    bus_details.clear();
                }
                imap.insert({date,bmap});
                bmap.clear();
            }
        }
    MyReadFile.close();
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  DisplayBusDetails()
 *
 *    DESCRIPTION        :  Displays all buses which are scheduled
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  void
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Bus::DisplayBusDetails()
{
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|\t\t\t\t\t\t\tBus Schedule\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    cout<<"|\t  "<<"Date\t\t      Bus_Num\t\t From\t\t   To\t     Driver_Name\tContact_No\t No_Seats_Avalible\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    for (auto imitr = imap.begin(); imitr != imap.end(); ++imitr)
    {
        cout<<"|\t"<< imitr->first<<"\t\t   ";//<< '\t' << itr->second << '\n';
        for (auto bmitr = imitr->second.begin(); bmitr != imitr->second.end(); ++bmitr)
        {
            cout<<"\t"<< bmitr->first<<"\t\t";
            int count = 0;
            for(auto it2 = bmitr->second.begin(); it2 != bmitr->second.end(); ++it2)
            {
                if(count == 4)
                {
                    cout<<"\t"<<*it2;
                }
                else
                {
                    int len = (*it2).length();
                    if( len >= 8)
                    {
                        cout<<*it2<<"\t";
                    }
                    else
                    {
                        cout << *it2 << "\t\t";
                    }
                }
                count++;
                 
            }
            cout<<"\t\t|"<<endl;
            cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
        }
    }
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  SetDateOfJourney()
 *
 *    DESCRIPTION        :  Reads date of journey from user and stores it in a variable(i.e date_of_journey).
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Reservation::SetDateOfJourney()
{
    int dd,mm,yy;
    string s;
    cout<<"\nEnter date in formate Date Month Year : ";
    cin>>dd>>mm>>yy;
    cout<<endl;
    int date_status = ValidateDate(dd,mm,yy);
    if(date_status == SUCCESS)
    {
        date_of_journey = to_string(dd) + "-"+to_string(mm)+"-"+to_string(yy);
        return SUCCESS;
    }
    else
    {
        //cout<<"Invalid date"<<endl;
        return FAILURE;
    }

}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  ValidateDate()
 *
 *    DESCRIPTION        :  Validate the date formate
 *
 *    PARAMETERS         :  dd(day), mm(month), yy(year)
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Reservation::ValidateDate(int dd,int mm,int yy)
{
    if(yy>0)
    {
        if((mm==1 || mm==3 || mm==5|| mm==7|| mm==8||mm==10||mm==12) && (dd>0 && dd<=31))
        {
            //cout<<"Date is Valide";
            return SUCCESS;
        }
        else
        {
            if((mm==4 || mm==6 || mm==9|| mm==11) && (dd>0 && dd<=30))
            {
                //cout<<"Date is Valid";
                return SUCCESS;
            }
            else
            {
                if(mm==2)
                {
                    if((yy%400==0 || (yy%100!=0 && yy%4==0)) && (dd>0 && dd<=29))
                    {
                        //cout<<"Date is Valide";
                        return SUCCESS;
                    }
                    else if(dd>0 && dd<=28)
                    {
                        //cout<<"Date is Valid";
                        return SUCCESS;
                    }
                    else
                    {
                        //cout<<"Date is Invalid";
                        return FAILURE;
                    }
                }
                else
                {
                    //cout<<"Date is Invalid";
                    return FAILURE;
                }
          }
        }
    }
    else
    {
        //cout<<"Date is Invalid";
        return FAILURE;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  DispalyAvailableBuses()
 *
 *    DESCRIPTION        :  Displays the details of the available buses on selected date(i.e date_of_journey)
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Reservation::DispalyAvailableBuses()
{
    
    ExtractAndStoreBusDetails();
    //cout<<date_of_journey<<endl;
    //cout<<imap.size()<<endl;
    
    int found_count = 0;

    for (auto imitr = imap.find(date_of_journey); imitr != imap.end(); imitr++)
    {
        if(imitr->first == date_of_journey)
        {
            if(found_count == 0)
            {
                cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"|\t\t\t\t\t\tBuses Available on "<<date_of_journey<<" are\t\t\t\t\t\t\t\t|"<<endl;
                cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
                cout<<"|\t  "<<"Date\t\t      Bus_Num\t\t From\t\t   To\t     Driver_Name\tContact_No\t No_Seats_Avalible\t|"<<endl;
                cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
            }
            cout<<"|\t"<< imitr->first<<"\t\t   ";//<< '\t' << itr->second << '\n';
            for (auto bmitr = imitr->second.begin(); bmitr != imitr->second.end(); ++bmitr)
            {
                cout<<"\t"<< bmitr->first<<"\t\t";
                int count = 0;
                for(auto it2 = bmitr->second.begin(); it2 != bmitr->second.end(); ++it2)
                {
                    if(count == 4)
                    {
                        cout<<"\t"<<*it2;
                    }
                    else
                    {
                        int len = (*it2).length();
                        if( len >= 8)
                        {
                            cout<<*it2<<"\t";
                        }
                        else
                        {
                            cout << *it2 << "\t\t";
                        }
                    }
                    count++;
                     
                }
                cout<<"\t\t|"<<endl;
                cout<<"|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
            }
            found_count ++;
        }
    }
    
    if(found_count == 0)
    {
        cout<<"No buses available on "<<date_of_journey<<endl<<endl;
        return FAILURE;
    }
    else
    {
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        return SUCCESS;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  ReadCustomerDetailsAndBookTicket()
 *
 *    DESCRIPTION        :  Reads Customer details, validates and ticket is booked
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Reservation::ReadCustomerDetailsAndBookTicket()
{
    int status = 0;
    
    cout<<"\nEnter your details"<<endl;
    cout<<"Name : ";
    cin>>name;
    
    cout<<"Age : ";
    cin>>age;
    if(age < 18)
    {
        cout<<"\nAge must be greater than 18"<<endl<<endl;
        return status = 0;
    }
    
    cout<<"Gender(M/F) : ";
    cin>>gender;
    if(!(gender == 'M' || gender == 'F'||gender == 'm' || gender == 'f'))
    {
        cout<<"\nInvalid Gender"<<endl<<endl;
        return status = 0;
    }
    
    cout<<"Bus number : ";
    cin>>bus_num;
    status = BusNumValidation();
    if(status != SUCCESS)
    {
        return status;
    }
    
    cout<<"Number of seats : ";
    cin>>num_of_seats;
    status = NumOfSeatsValidation();
    if(status != SUCCESS)
    {
        return status;
    }
    cout<<endl;
    
    return status;
    
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  BusNumValidation()
 *
 *    DESCRIPTION        :  checks whether the entered bus_num is available on date_of_journey
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Reservation::BusNumValidation()
{
    
    //ExtractAndStoreBusDetails();
    
    for (auto imitr = imap.find(date_of_journey); imitr != imap.end(); imitr++)
    {
        if(imitr->first == date_of_journey)
        {
            for (auto bmitr = imitr->second.begin(); bmitr != imitr->second.end(); ++bmitr)
            {
                if(stoi(bmitr->first) == bus_num)
                {
                    return SUCCESS;
                }
            }
        }
    }
    cout<<"\nInvalid Bus Number"<<endl<<endl;
    return FAILURE;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  NumOfSeatsValidation()
 *
 *    DESCRIPTION        :  Validate whether the requested number of seats are available or not.
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Reservation::NumOfSeatsValidation()
{
    //ExtractAndStoreBusDetails();
    if(num_of_seats == 0)
    {
        cout<<"\nNumber of seats cannot be 0"<<endl<<endl;
        return FAILURE;
    }
    else if(num_of_seats < 0)
    {
        cout<<"\nNumber of seats cannot be negative"<<endl<<endl;
        return FAILURE;
    }
    else
    {
        for (auto imitr = imap.find(date_of_journey); imitr != imap.end(); imitr++)
        {
            if(imitr->first == date_of_journey)
            {
                for (auto bmitr = imitr->second.begin(); bmitr != imitr->second.end(); ++bmitr)
                {
                    if(stoi(bmitr->first) == bus_num)
                    {
                        int count = 0;
                        for(auto it2 = bmitr->second.begin(); it2 != bmitr->second.end(); ++it2)
                        {
                            count++;
                            
                            if(count == 1)
                            {
                                i_from = *it2;
                            }
                            if(count == 2)
                            {
                                i_to = *it2;
                            }
                            if(count == 3)
                            {
                                i_driver = *it2;
                            }
                            if(count == 4)
                            {
                                i_driver_num = *it2;
                            }
                            if(count == 5)
                            {
                                if(stoi(*it2) >= num_of_seats)
                                {
                                    //cout<<*it2<<" is greater than "<<num_of_seats<<"\t";
                                    return SUCCESS;
                                }
                                else
                                {
                                    cout<<"\nOnly "<<stoi(*it2)<<" of seats are available"<<endl<<endl;
                                    return FAILURE;
                                }
                                //cout<<*it2<<"\t";
                            }
                        }
                    }
                }
            }
        }
        return FAILURE;
    }
    
}
    
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  UpdateInventory()
 *
 *    DESCRIPTION        :  Updates the inventory/database(i.e file data) by reducing the number of seats booked.
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  void
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Reservation::UpdateInventory()
{
    // Create and open a text file
    ofstream MyFile(filename);
    
    // Write to the file
    for (auto imitr = imap.begin(); imitr != imap.end(); ++imitr)
    {
        MyFile<< imitr->first;//<< '\t' << itr->second << '\n';
        for (auto bmitr = imitr->second.begin(); bmitr != imitr->second.end(); ++bmitr)
        {
            if(stoi(bmitr->first) == bus_num)
            {
                MyFile<<" "<< bmitr->first;
                int count = 0;
                for(auto it2 = bmitr->second.begin(); it2 != bmitr->second.end(); ++it2)
                {
                    count++;
                    
                    if(count == 5)
                    {
                        if(stoi(*it2) >= num_of_seats)
                        {
                            //cout<<*it2<<" is greater than "<<num_of_seats<<"\t";
                            int updated_seats = stoi(*it2) - num_of_seats;
                            MyFile<<" "<<updated_seats;
                        }
                        //cout<<*it2<<"\t";
                    }
                    else
                    {
                        MyFile<<" "<<*it2;
                    }
                }
                MyFile<<endl;
            }
            else
            {
                MyFile<<" "<< bmitr->first;
                //int count = 0;
                for(auto it2 = bmitr->second.begin(); it2 != bmitr->second.end(); ++it2)
                {
                    MyFile<<" "<<*it2;
                }
                MyFile<<endl;
            }
        }
    }
    
    // Close the file
    MyFile.close();
    
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *    FUNCTION NAME      :  PrintTicket()
 *
 *    DESCRIPTION        :  Prints the ticket with all the details
 *
 *    PARAMETERS         :  none
 *
 *    RETURNS            :  status
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Reservation::PrintTicket()
{
    srand(time(0));
    int ticket_num = rand();
    //printf(" %d ", rand());
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    cout<<"|\t\t\t\t\tTICKET\t\t\t\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    cout<<"|\tDate of journey : "<<date_of_journey;
    cout<<"\t\t\tTicket Number : "<<ticket_num<<"\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    cout<<"|\tName : "<<name;
    if(name.length()<9)
        cout<<"\t\t\t";
    else
        cout<<"\t\t";
    cout<<"Age : "<<age<<"\t";
    cout<<"Gender(M/F) : "<<gender<<"\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    cout<<"|\tBus Number : "<<bus_num<<"\t\t\t\t";
    cout<<"Number of seats : "<<num_of_seats<<"\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    int len = (i_from).length();
    if( len >= 8)
    {
        cout<<"|\tFrom : "<<i_from<<"\t\t\t\t";
    }
    else
    {
        cout<<"|\tFrom : "<<i_from<<"\t\t\t\t\t";
    }
    
    //cout<<"|\tFrom : "<<i_from<<"\t\t\t\t\t";
    cout<<"To : "<<i_to<<"\t\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    cout<<"|\tDriver : "<<i_driver<<"\t\t\t\t\t";
    cout<<"Contact : "<<i_driver_num<<"\t\t|"<<endl;
    cout<<"|\t\t\t\t\t\t\t\t\t\t\t|"<<endl;
    
    cout<<"-----------------------------------------------------------------------------------------"<<endl;
    
}
