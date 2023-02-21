#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

///////////////////////////////Function Prototypes////////////////////////////////////
void gotoxy(int x, int y);
void panel();
void menu();
bool menuValidity(string option);
void signUp();
bool signUpValidity(string checkName);
bool passwordValidity(string password);
void login();
int loginValidity(string checkName, string checkPassword);
void adminMenu();
char adminMenuValidity(string option);
void addTrain();
bool addTrainValidity(string trainCheck);
bool addTrainTypeValidity(string trainType);
int addTrainPriceValidity(string trainPrice);
bool addTrainDiscountValidity(string trainDiscount);
bool addTrainLuggageValidity(string trainLuggage);
void searchTrain();
int searchTrainValidity(string checkName);
bool addTrainDepartureValidity(string trainDeparture);
bool addTrainCompartmentValidity(string trainCompartment);
bool addTrainStartValidity(string trainStart);
bool addTrainEndValidity(string trainStart, string trainEnd);
void removeTrain();
int removeTrainValidity(string checkName);
void removeTrainExe(string checkName);
void classTrain();
int classTrainValidity(string checkName);
string previousClass(string checkName);
bool TrainTypeValidity(string trainType,string preType);
void classAssign(string checkName, string preClass);
void departure();
string previousTime(string checkName);
void timeAssign(string checkName, string preTime);
void price();
string previousPrice(string checkName);
void priceAssign(string checkName, string prePrice);
void compartment();
string previousCompartment(string checkName);
void compartmentAssign(string checkName, string preCompartment);
void luggage();
string previousLuggage(string checkName);
void luggageAssign(string checkName, string preLuggage);
void discount();
string previousDiscount(string checkName);
void discountAssign(string checkName, string preDiscount);

void user();
bool budgetEnteringValidity(string budget);
void startingPoint();
void selectClass();
bool availableTrains(string choiceS, string choiceE);
bool shedulingDeparture(string trainName, string choiceS, string choiceE);
int sheduling(string choice);
bool shedulingCompartment(string choice ,string trainCompartment);
bool shedulingLuggage(string choiceL);
void final(string choice,string choiceT,string choiceL,string choiceC);
string conversion(string line);
////////////////////////////////////////Global Variables/////////////////////////////////////////////////
int total = 10;

int cycle = 1;

string trainCheck;
string train[10];
string type[10];
string ticketPrice[10];
string departureTime[10];
string compartments[10];
string ticketsDiscount[10];
string luggageTax[10];
string starting[10];
string ending[10];

int count = 2;

string name[10];
string password[10];
string role[10];
///////////////////////////////////////MAIN FUNCTION//////////////////////////////////
int main()
{
    ////////////////////////////////////Test Values///////////////////////////////////////
    role[0] = {"admin"};
    role[1] = {"user"};
    name[0] = {"bilal"};
    name[1] = {"bilal1"};
    password[0] = {"bilal"};
    password[1] = {"bilal1"};

    train[0] = "t1";
    type[0] = "BUSINESS";
    ticketPrice[0] = "500";
    departureTime[0] = "15:30";
    compartments[0] = "10";
    ticketsDiscount[0] = "5";
    luggageTax[0] = "15";
    starting[0] = "LAHORE";
    ending[0] = "KARACHI";
    /////////////////////////////////////////////////////////////////////////////////////
    string option;
    string checkName;
    string checkPassword;
    string checkRole;
    string preClass;
    string currentClass;
    string preTime;
    string prePrice;
    string preCompartment;
    string preLuggage;
    string preDiscount;

    string budget;
    string choice;
    string choiceE;
    string choiceS;
    string choiceT;
    string choiceC;
    string choiceL;

    bool flagmenu;
    int flaglog;
    bool flagSign;
    char check1 = '0';
    bool flagAdd;
    bool flag;
    int flag1;
    int flagSearch;

    while (count < total)
    {
        system("cls");
        panel();
        menu();
        gotoxy(20, 24);
        cout << "Enter your choice : ";
        cin >> option;
        flagmenu = menuValidity(option);
        while (flagmenu == false)
        {
            gotoxy(20, 26);
            cout << "Enter a valid option!!";
            gotoxy(40, 24);
            cout << "                         ";
            gotoxy(20, 24);
            cout << "Enter your choice : ";
            cin >> option;
            flagmenu = menuValidity(option);
        }

        if (option[0] == '1')
        {
            login();
            gotoxy(20, 20);
            cout << "Enter your name :";
            cin >> checkName;
            gotoxy(20, 21);
            cout << "Enter your password :";
            cin >> checkPassword;

            flaglog = loginValidity(checkName, checkPassword);
            while (flaglog == -1)
            {
                gotoxy(20, 24);
                cout << "Please enter the correct information correct!!";
                gotoxy(37, 20);
                cout << "                    ";
                gotoxy(41, 21);
                cout << "                    ";
                gotoxy(37, 20);
                cin >> checkName;
                gotoxy(41, 21);
                cin >> checkPassword;

                flaglog = loginValidity(checkName, checkPassword);
            }

            if (role[flaglog] == "admin")
            {
                while (count < total)
                {
                    adminMenu();
                    gotoxy(20, 31);
                    cout << "Enter your choice :";
                    cin >> option;
                    check1 = adminMenuValidity(option);
                    while (check1 == '|')
                    {
                        gotoxy(20, 33);
                        cout << "Enter a valid number!! ";
                        gotoxy(38, 31);
                        cout << "                         ";
                        gotoxy(38, 31);
                        cin >> option;
                        check1 = adminMenuValidity(option);
                    }

                    if (check1 == '1')
                    {
                        addTrain();

                        gotoxy(20, 22);
                        cout << "Enter the name of new train :";
                        cin >> trainCheck;
                        flagAdd = addTrainValidity(trainCheck);
                        while (flagAdd == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a different train name this one is already taken!!";
                            gotoxy(49, 22);
                            cout << "                                  ";
                            gotoxy(49, 22);
                            cin >> trainCheck;

                            flagAdd = addTrainValidity(trainCheck);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                        }

                        gotoxy(20, 23);
                        cout << "Enter the class of the new train :";
                        cin >> type[cycle];
                        type[cycle] = conversion(type[cycle]);
                        flag = addTrainTypeValidity(type[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid train class!!";
                            gotoxy(20, 32);
                            cout << "business,economical or firstClass";
                            gotoxy(54, 23);
                            cout << "                                  ";
                            gotoxy(54, 23);
                            cin >> type[cycle];
                            type[cycle] = conversion(type[cycle]);

                            flag = addTrainTypeValidity(type[cycle]);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 32);
                            cout << "                                       ";
                        }

                        gotoxy(20, 24);
                        cout << "Enter the price of ticket of the new train :";
                        cin >> ticketPrice[cycle];
                        flag1 = addTrainPriceValidity(ticketPrice[cycle]);
                        while (flag1 <= 0)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid price!!";
                            gotoxy(64, 24);
                            cout << "                                  ";
                            gotoxy(64, 24);
                            cin >> ticketPrice[cycle];

                            flag1 = addTrainPriceValidity(ticketPrice[cycle]);
                            gotoxy(20, 31);
                            cout << "                                         ";
                        }

                        gotoxy(20, 25);
                        cout << "Enter the time of departure of the new train :";
                        cin >> departureTime[cycle];
                        flag = addTrainDepartureValidity(departureTime[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Time might be invalid or format might be incorrect!!";
                            gotoxy(20, 32);
                            cout << "Correct format is hours:minutes and max time is 23:59";
                            gotoxy(66, 25);
                            cout << "                                  ";
                            gotoxy(66, 25);
                            cin >> departureTime[cycle];

                            flag = addTrainDepartureValidity(departureTime[cycle]);
                            gotoxy(20, 31);
                            cout << "                                                     ";
                            gotoxy(20, 32);
                            cout << "                                                       ";
                        }

                        gotoxy(20, 26);
                        cout << "Enter the number of compartments of the new train :";
                        cin >> compartments[cycle];
                        flag = addTrainCompartmentValidity(compartments[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid compartment number !!";
                            gotoxy(20, 32);
                            cout << "Minimum 10 and Maximum 20";
                            gotoxy(71, 26);
                            cout << "                                  ";
                            gotoxy(71, 26);
                            cin >> compartments[cycle];

                            flag = addTrainCompartmentValidity(compartments[cycle]);
                            gotoxy(20, 31);
                            cout << "                                         ";
                            gotoxy(20, 32);
                            cout << "                                           ";
                        }

                        gotoxy(20, 27);
                        cout << "Enter the number of tickets to avail the discount :";
                        cin >> ticketsDiscount[cycle];
                        flag = addTrainDiscountValidity(ticketsDiscount[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid number !!";
                            gotoxy(20, 32);
                            cout << "Minimum 1 and Maximum 9";
                            gotoxy(71, 27);
                            cout << "                                  ";
                            gotoxy(71, 27);
                            cin >> ticketsDiscount[cycle];

                            flag = addTrainDiscountValidity(ticketsDiscount[cycle]);
                            gotoxy(20, 31);
                            cout << "                                         ";
                            gotoxy(20, 32);
                            cout << "                                           ";
                        }

                        gotoxy(20, 28);
                        cout << "Enter the minimum weight(kg) of luggage to apply tax :";
                        cin >> luggageTax[cycle];
                        flag = addTrainLuggageValidity(luggageTax[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid number !!";
                            gotoxy(20, 32);
                            cout << "Minimum 0 and Maximum 30";
                            gotoxy(74, 28);
                            cout << "                                  ";
                            gotoxy(74, 28);
                            cin >> luggageTax[cycle];

                            flag = addTrainLuggageValidity(luggageTax[cycle]);
                            gotoxy(20, 31);
                            cout << "                                         ";
                            gotoxy(20, 32);
                            cout << "                                           ";
                        }

                        gotoxy(20, 29);
                        cout << "Enter the starting point of the train :";
                        cin >> starting[cycle];
                        starting[cycle] = conversion(starting[cycle]);
                        flag = addTrainStartValidity(starting[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid Name !!";
                            gotoxy(20, 32);
                            cout << "Lahore,Karachi,Islamabad,Multan,Sialkot,Peshawar,Haiderabad,Gujranwala or Quoitta";
                            gotoxy(59, 29);
                            cout << "                                  ";
                            gotoxy(59, 29);
                            cin >> starting[cycle];
                            starting[cycle] = conversion(starting[cycle]);

                            flag = addTrainStartValidity(starting[cycle]);
                            gotoxy(20, 31);
                            cout << "                                         ";
                            gotoxy(20, 32);
                            cout << "                                                                                       ";
                        }

                        gotoxy(20, 30);
                        cout << "Enter the destination of the train :";
                        cin >> ending[cycle];
                        ending[cycle] = conversion(ending[cycle]);
                        flag = addTrainEndValidity(starting[cycle], ending[cycle]);
                        while (flag == false)
                        {
                            gotoxy(20, 33);
                            cout << "Enter a valid Name !!";
                            gotoxy(20, 34);
                            cout << "Lahore,Karachi,Islamabad,Multan,Sialkot,Peshawar,Haiderabad,Gujranwala or Quoitta";
                            gotoxy(20, 35);
                            cout << "Note : Starting point must not match the destination";
                            gotoxy(56, 30);
                            cout << "                                  ";
                            gotoxy(56, 30);
                            cin >> ending[cycle];
                            ending[cycle] = conversion(ending[cycle]);

                            flag = addTrainEndValidity(starting[cycle], ending[cycle]);
                            gotoxy(20, 33);
                            cout << "                                         ";
                            gotoxy(20, 34);
                            cout << "                                                                                       ";
                            gotoxy(20, 35);
                            cout << "                                                      ";
                        }

                        train[cycle] = trainCheck;
                        cycle = cycle + 1;
                        gotoxy(20, 36);
                        cout << "New train has been added!";
                        gotoxy(20, 31);
                        cout << "                                                           ";
                        getch();
                    }
                    else if (check1 == '2')
                    {
                        searchTrain();
                        gotoxy(20, 22);
                        cout << "Enter the name of train you want to search :";
                        cin >> checkName;

                        flagSearch = searchTrainValidity(checkName);
                        while (flagSearch == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist :";
                            gotoxy(64, 22);
                            cout << "                             ";
                            gotoxy(64, 22);
                            cin >> checkName;

                            flagSearch = searchTrainValidity(checkName);
                        }

                        searchTrain();
                        gotoxy(20, 22);
                        cout << "Required train is : " << train[flagSearch];
                        gotoxy(20, 23);
                        cout << "The class of this train is : " << type[flagSearch];
                        gotoxy(20, 24);
                        cout << "The time of departure of this train is : " << departureTime[flagSearch];
                        gotoxy(20, 25);
                        cout << "The number of compartments of this train is : " << compartments[flagSearch];
                        gotoxy(20, 26);
                        cout << "The price of ticket of this train is : " << ticketPrice[flagSearch];
                        gotoxy(20, 27);
                        cout << "The minimum number of tickets to avail discount are : " << ticketsDiscount[flagSearch];
                        gotoxy(20, 28);
                        cout << "The minimum amount of luggage to apply tax is  : " << luggageTax[flagSearch];
                        gotoxy(20, 29);
                        cout << "The starting point of the train is : " << starting[flagSearch];
                        gotoxy(20, 30);
                        cout << "The destination of the train is  : " << ending[flagSearch];
                        getch();
                    }
                    else if (check1 == '3')
                    {
                        removeTrain();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train you want to delete :";
                        cin >> checkName;
                        flag1 = removeTrainValidity(checkName);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist !";
                            gotoxy(68, 22);
                            cout << "                                          ";
                            gotoxy(68, 22);
                            cin >> checkName;

                            flagSearch = removeTrainValidity(checkName);
                            gotoxy(20, 25);
                            cout << "                                               ";
                        }

                        gotoxy(20, 31);
                        cout << "Tne train named " << checkName << "has been deleted successfully!!";
                        removeTrainExe(checkName);
                        count = count - 1;
                        getch();
                    }
                    else if (check1 == '4')
                    {
                        classTrain();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train whose class you want to change :";
                        cin >> trainCheck;
                        flag1 = classTrainValidity(trainCheck);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 30);
                            cout << "The train you have entered doesn't exist !!";
                            gotoxy(80, 22);
                            cout << "                                          ";
                            gotoxy(80, 22);
                            cin >> trainCheck;
                            flag1 = classTrainValidity(trainCheck);
                            gotoxy(20, 30);
                            cout << "                                           ";
                        }

                        preClass = previousClass(trainCheck);
                        gotoxy(20, 23);
                        cout << "The previous class of train is " << preClass;
                        gotoxy(20, 24);
                        cout << "Enter the new class for the train ";
                        cin >> currentClass;
                        currentClass = conversion(currentClass);
                        flag = TrainTypeValidity(currentClass,preClass);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid train class!!";
                            gotoxy(20, 32);
                            cout << "business,economical or firstClass";
                            gotoxy(20, 33);
                            cout << "Note : new class must not mmatch the previous class!";
                            gotoxy(54, 24);
                            cout << "                                  ";
                            gotoxy(54, 24);
                            cin >> currentClass;
                            currentClass = conversion(currentClass);

                            flag = TrainTypeValidity(currentClass,preClass);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 32);
                            cout << "                                           ";
                            gotoxy(20, 33);
                            cout << "                                                           ";
                        }

                        classAssign(trainCheck, currentClass);
                        gotoxy(20, 30);
                        cout << "Class of the train has been updated successfully!!";
                        getch();
                    }
                    else if (check1 == '5')
                    {
                        departure();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train whose departure time you want to change :";
                        cin >> checkName;
                        flag1 = searchTrainValidity(checkName);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist :";
                            gotoxy(89, 22);
                            cout << "                             ";
                            gotoxy(89, 22);
                            cin >> checkName;

                            flag1 = searchTrainValidity(checkName);
                            gotoxy(20, 25);
                            cout << "                                                   ";
                        }

                        preTime = previousTime(checkName);
                        gotoxy(20, 23);
                        cout << "The previous departure time of this train is " << preTime;
                        gotoxy(20, 24);
                        cout << "Enter the new departure time for the train :";
                        cin >> preTime;
                        flag = addTrainDepartureValidity(preTime);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid time for departure!!";
                            gotoxy(20, 32);
                            cout << "Correct format is hours:minutes and max time is 23:59";
                            gotoxy(64, 24);
                            cout << "                                  ";
                            gotoxy(64, 24);
                            cin >> preTime;

                            flag = addTrainDepartureValidity(preTime);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 32);
                            cout << "                                                            ";
                        }

                        timeAssign(checkName, preTime);
                        gotoxy(20, 30);
                        cout << "Departure time of the train has been updated successfully!!";
                        getch();
                    }
                    else if (check1 == '6')
                    {
                        price();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train whose ticket price you want to change :";
                        cin >> checkName;
                        flag1 = searchTrainValidity(checkName);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist :";
                            gotoxy(87, 22);
                            cout << "                             ";
                            gotoxy(87, 22);
                            cin >> checkName;

                            flag1 = searchTrainValidity(checkName);
                            gotoxy(20, 25);
                            cout << "                                                   ";
                        }

                        prePrice = previousPrice(checkName);
                        gotoxy(20, 23);
                        cout << "The previous ticket price of this train is " << prePrice;
                        gotoxy(20, 24);
                        cout << "Enter the new ticket price for the train :";
                        cin >> prePrice;
                        flag1 = addTrainPriceValidity(prePrice);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid ticket price!!";
                            gotoxy(62, 24);
                            cout << "                                  ";
                            gotoxy(62, 24);
                            cin >> prePrice;

                            flag1 = addTrainPriceValidity(prePrice);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                        }

                        priceAssign(checkName, prePrice);
                        gotoxy(20, 30);
                        cout << "Ticket price of the train has been updated successfully!!";
                        getch();
                    }
                    else if (check1 == '7')
                    {
                        compartment();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train whose compartments you want to change :";
                        cin >> checkName;
                        flag1 = searchTrainValidity(checkName);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist :";
                            gotoxy(87, 22);
                            cout << "                             ";
                            gotoxy(87, 22);
                            cin >> checkName;

                            flag1 = searchTrainValidity(checkName);
                            gotoxy(20, 25);
                            cout << "                                                   ";
                        }

                        preCompartment = previousCompartment(checkName);
                        gotoxy(20, 23);
                        cout << "The previous number of compartments of this train is " << preCompartment;
                        gotoxy(20, 24);
                        cout << "Enter the new number of compartments for the train :";
                        cin >> preCompartment;
                        flag = addTrainCompartmentValidity(preCompartment);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid number for compartment !!";
                            gotoxy(20, 32);
                            cout << "Minimum 10 and Maximum 20";
                            gotoxy(72, 24);
                            cout << "                                  ";
                            gotoxy(72, 24);
                            cin >> preCompartment;

                            flag = addTrainCompartmentValidity(preCompartment);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 32);
                            cout << "                                   ";
                        }

                        priceAssign(checkName, preCompartment);
                        gotoxy(20, 30);
                        cout << "Compartment numbers of the train has been updated successfully!!";
                        getch();
                    }
                    else if (check1 == '8')
                    {

                        luggage();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train whose luggage tax you want to change :";
                        cin >> checkName;
                        flag1 = searchTrainValidity(checkName);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist :";
                            gotoxy(86, 22);
                            cout << "                             ";
                            gotoxy(86, 22);
                            cin >> checkName;

                            flag1 = searchTrainValidity(checkName);
                            gotoxy(20, 25);
                            cout << "                                                   ";
                        }

                        preLuggage = previousLuggage(checkName);
                        gotoxy(20, 23);
                        cout << "The previous luggage tax of this train is " << preLuggage;
                        gotoxy(20, 24);
                        cout << "Enter the new luggage tax for the train :";
                        cin >> preLuggage;
                        flag = addTrainLuggageValidity(preLuggage);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid number !!";
                            gotoxy(20, 30);
                            cout << "Minimum 0 kg and Maximum 30 kg";
                            gotoxy(61, 24);
                            cout << "                                  ";
                            gotoxy(61, 24);
                            cin >> preLuggage;

                            flag = addTrainLuggageValidity(preLuggage);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 30);
                            cout << "                                     ";
                        }

                        priceAssign(checkName, preLuggage);
                        gotoxy(20, 30);
                        cout << "Luggage Tax of the train has been updated successfully!!";
                        getch();
                    }
                    else if (check1 == '9')
                    {

                        discount();

                        gotoxy(20, 22);
                        cout << "Enter the name of the train whose discount availing tickets you want to change :";
                        cin >> checkName;
                        flag1 = searchTrainValidity(checkName);
                        while (flag1 == -1)
                        {
                            gotoxy(20, 25);
                            cout << "The train you have entered doesn't exist :";
                            gotoxy(100, 22);
                            cout << "                             ";
                            gotoxy(100, 22);
                            cin >> checkName;

                            flag1 = searchTrainValidity(checkName);
                            gotoxy(20, 25);
                            cout << "                                                   ";
                        }

                        preDiscount = previousDiscount(checkName);
                        gotoxy(20, 23);
                        cout << "The previous number of tickets of this train to avail discount is " << preDiscount;
                        gotoxy(20, 24);
                        cout << "Enter the new number of tickets to avail discount for the train :";
                        cin >> preDiscount;
                        flag = addTrainDiscountValidity(preDiscount);
                        while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid number of tickets for availing discount !!";
                            gotoxy(20, 32);
                            cout << "Minimum 1 and Maximum 9";
                            gotoxy(85, 24);
                            cout << "                                  ";
                            gotoxy(85, 24);
                            cin >> preDiscount;

                            flag = addTrainDiscountValidity(preDiscount);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 32);
                            cout << "                                                               s";
                        }

                        discountAssign(checkName, preDiscount);
                        gotoxy(20, 30);
                        cout << "Number of tickets to avail discount of the train has been updated successfully!!";
                        getch();
                    }
                    else
                    {
                        gotoxy(20, 32);
                        cout << "Press Enter to return to the previous screen ";
                        break;
                    }
                }
                getch();
            }
            else
            {

                while (count < total)
                {
                    user();
                    gotoxy(20,20);
                    cout<<"Enter 1 for purchasing tickets and sheduling departure";
                    gotoxy(20,21);
                    cout<<"Enter 0 for returning to the previous screen";
                    gotoxy(20,24);
                    cout<<"Enter your choice :";
                    cin>>choice;
                    while(choice != "0" && choice != "1")
                    {
                        gotoxy(20,26);
                        cout<<"Enter a valid choice!!";
                        gotoxy(39,24);
                        cout<<"                     ";
                        gotoxy(39,24);
                        cin>>choice;
                    }
                    if(choice == "0")
                    break;

                    startingPoint();
                    gotoxy(20, 20);
                    cout << "Enter your starting point :";
                    cin >> choiceS;
                    choiceS = conversion(choiceS);
                    flag = addTrainStartValidity(choiceS);
                    while (flag == false)
                    {
                        gotoxy(20, 30);
                        cout << "Enter a valid choice!!";
                        gotoxy(20, 31);
                        cout << "Lahore,Karachi,Islamabad,Multan,Sialkot,Peshawar,Haiderabad,Gujranwala or Quoitta";
                        gotoxy(47, 20);
                        cout << "                        ";
                        gotoxy(47, 20);
                        cin >> choiceS;
                        choiceS = conversion(choiceS);
                        flag = addTrainStartValidity(choiceS);
                        gotoxy(20, 30);
                        cout << "                             ";
                        gotoxy(20, 31);
                        cout << "                                                                                   ";
                    }

                    startingPoint();
                    gotoxy(20, 20);
                    cout << "Enter your destination :";
                    cin >> choiceE;
                    choiceE = conversion(choiceE);
                    flag = addTrainEndValidity(choiceS, choiceE);
                    while (flag == false)
                    {
                        gotoxy(20, 30);
                        cout << "Enter a valid choice!!";
                        gotoxy(20, 31);
                        cout << "Lahore,Karachi,Islamabad,Multan,Sialkot,Peshawar,Haiderabad,Gujranwala or Quoitta";
                        gotoxy(20, 32);
                        cout << "Note: starting point and destination must not match";
                        gotoxy(44, 20);
                        cout << "                        ";
                        gotoxy(44, 20);
                        cin >> choiceE;
                        choiceE = conversion(choiceE);
                        flag = addTrainEndValidity(choiceS, choiceE);
                        gotoxy(20, 30);
                        cout << "                             ";
                        gotoxy(20, 31);
                        cout << "                                                                                  ";
                        gotoxy(20, 32);
                        cout << "                                                       ";
                    }

                    flag = availableTrains(choiceS, choiceE);
                    if (flag == false)
                    {
                        gotoxy(20, 30);
                        cout << "Press Enter to return to starting point panel";
                        getch();
                        gotoxy(20, 20);
                        cout << "                                                                                                           ";
                        gotoxy(20, 26);
                        cout<<"                                                                                 ";
                        gotoxy(20, 30);
                        cout << "                                                    ";
                        continue;
                    }
                    gotoxy(20, 23);
                    cout << "Enter the name of train in which you want to travel :";
                    cin >> choice;

                    flag = shedulingDeparture(choice, choiceS, choiceE);
                    while (flag == false)
                    {
                        gotoxy(20,24);
                        cout<<"Enter a train's name from the given options!!";
                        gotoxy(73,23);
                        cout<<"                                                 ";
                        gotoxy(73,23);
                        cin>>choice;
                        flag = shedulingDeparture(choice, choiceS, choiceE);
                        gotoxy(20,24);
                        cout<<"                                                 ";
                    }
                    user();
                    flag1 = sheduling(choice);
                    gotoxy(20,25);
                    cout<<"Purchase "<<ticketsDiscount[flag1]<<" tickets to get 30 percent discount";
                    gotoxy(20,20);
                    cout<<"Enter how many tickets you want to purchase :";
                    cin>>choiceT;
                    flag = addTrainDiscountValidity(choiceT);
                    
                    while (flag == false)
                        {
                            gotoxy(20, 31);
                            cout << "Enter a valid number of tickets for availing discount !!";
                            gotoxy(20, 32);
                            cout << "Minimum 1 and Maximum 9 tickets can be purchased from 1 user account";
                            gotoxy(65, 20);
                            cout << "                                  ";
                            gotoxy(65, 20);
                            cin >> choiceT;

                            flag = addTrainDiscountValidity(choiceT);
                            gotoxy(20, 31);
                            cout << "                                                          ";
                            gotoxy(20, 32);
                            cout << "                                                                        ";
                        }
                    user();
                    gotoxy(20,25);
                    cout<<"Total compartments of the selected train are "<<compartments[flag1];
                    gotoxy(20,20);
                    cout<<"Enter the compartment of the train in which you want to sit in :";
                    cin>>choiceC;
                    flag = shedulingCompartment(choice,choiceC);
                    while (flag == false)
                        {
                            gotoxy(20, 30);
                            cout << "Enter a valid compartment number to sit in !!";
                            gotoxy(20, 31);
                            cout << "Your choice should not exceed total number of compartments of selected train!!";
                            gotoxy(84, 20);
                            cout << "                                  ";
                            gotoxy(84, 20);
                            cin >> choiceC;

                            flag = shedulingCompartment(choice,choiceC);;
                            gotoxy(20, 30);
                            cout << "                                                          ";
                            gotoxy(20, 31);
                            cout << "                                                                                   ";
                        }
                
                    user();
                    gotoxy(20,25);
                    cout<<"if your luggage exceeds "<<luggageTax[flag1]<<" kg, tax of 20% of total bill will be applied";
                    gotoxy(20,20);
                    cout<<"Enter the amount of luggage you want to carry with :";
                    cin>>choiceL;
                    flag = shedulingLuggage(choiceL);
                    while (flag == false)
                        {
                            gotoxy(20, 30);
                            cout << "Enter a valid luggage amount !!";
                            gotoxy(72, 20);
                            cout << "                                  ";
                            gotoxy(72, 20);
                            cin >> choiceL;

                            flag = shedulingLuggage(choiceL);
                            gotoxy(20, 30);
                            cout << "                                                          ";
                        }
                    user();
                    final(choice,choiceT,choiceL,choiceC);
                    getch();
                    }
                gotoxy(20,30);    
                cout<<"Press any key to return";    
                getch();
            }
        }

        else if (option[0] == '2')
        {
            signUp();
            gotoxy(20, 20);
            cout << "Enter your name :";
            cin >> checkName;

            flagSign = signUpValidity(checkName);
            while (flagSign == false)
            {
                gotoxy(37, 20);
                cout << "                  ";
                gotoxy(20, 24);
                cout << "Enter another name this one is already taken!";
                gotoxy(37, 20);
                cin >> checkName;
                gotoxy(20, 24);
                cout << "                                              ";
                flagSign = signUpValidity(checkName);
            }

            gotoxy(20, 21);
            cout << "Enter your password :";
            cin >> password[count];

            flagSign = passwordValidity(password[count]);
            
            while (flagSign == false)
            {
                gotoxy(41, 21);
                cout << "                  ";
                gotoxy(20, 24);
                cout << "Password atleast have length of 8 !!";
                gotoxy(41, 21);
                cin >> password[count];
                gotoxy(20, 24);
                cout << "                                              ";
                flagSign = passwordValidity(password[count]);
            }

            gotoxy(20, 22);
            cout << "Enter your role :";
            cin >> role[count];

            

            while (role[count] != "admin" && role[count] != "user")
            {
                gotoxy(20, 24);
                cout << "Enter a valid Role!!";
                gotoxy(37, 22);
                cout << "                    ";
                gotoxy(37, 22);
                cin >> role[count];
            }

            gotoxy(20, 26);
            cout << "User has been added successfully...";
            name[count] = checkName;
            count++;
            getch();
        }
        else
        {
            return 0;
        }
    }
}

///////////////////////////////////////other functions/////////////////////////////////////////////////////////
void menu()
{
    gotoxy(75, 18);
    cout << "*****MENU*****";
    gotoxy(20, 20);
    cout << "Enter 1 to login ";
    gotoxy(20, 21);
    cout << "Enter 2 to SignUP ";
    gotoxy(20, 22);
    cout << "Enter 3 to exit program ";
}
bool menuValidity(string option)
{
    int n;
    bool flag = false;

    n = option.length();
    if (n == 1)
    {
        for (char j = '1'; j <= '3'; j++)
        {
            if (option[0] == j)
            {
                flag = true;
            }
        }
    }
    if (n != 1 || flag == false)
        return false;
    else
        return true;
}
void signUp()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****SignUp Menu*****";
}
bool signUpValidity(string checkName)
{
    bool flag = true;
    for (int i = 0; i < total; i++)
    {
        if (checkName == name[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool passwordValidity(string password)
{
    bool flag = true;
    int leng = password.length();
    
    if(leng<8)
    flag = false;

    return flag;
}
void login()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Login Menu*****";
}
int loginValidity(string checkName, string checkPassword)
{
    int flag;
    int c = 0;
    for (int i = 0; i < total; i++)
    {
        if (checkName == name[i] && checkPassword == password[i])
        {
            if (role[i] == "admin" || role[i] == "user")
                ;
            {
                c++;
                flag = i;
                break;
            }
        }
    }
    if (c != 0)
        return flag;
    else
        return -1;
}
void adminMenu()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";
    gotoxy(20, 20);
    cout << "Enter 1 to add a new train           ";
    gotoxy(20, 21);
    cout << "Enter 2 to search a train by its name";
    gotoxy(20, 22);
    cout << "Enter 3 to remove a train";
    gotoxy(20, 23);
    cout << "Enter 4 to change the class of train";
    gotoxy(20, 24);
    cout << "Enter 5 to change the time of departure of a train";
    gotoxy(20, 25);
    cout << "Enter 6 to change the price of a ticket";
    gotoxy(20, 26);
    cout << "Enter 7 to change number of compartments of a train";
    gotoxy(20, 27);
    cout << "Enter 8 to change the tax on luggage";
    gotoxy(20, 28);
    cout << "Enter 9 to change number of tickets to avail discount";
    gotoxy(20, 29);
    cout << "Enter 0 to return to menu";
    gotoxy(20, 31);
}
char adminMenuValidity(string option)
{
    int n;
    bool flag = false;
    char value;

    n = option.length();

    for (char i = '0'; i <= '9'; i++)
    {
        if (option[0] == i)
        {
            value = i;
            flag = true;
        }
    }

    if (n != 1 || flag == false)
    {
        value = '|';
    }

    return value;
}
void addTrain()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train adding section";
}
bool addTrainValidity(string trainCheck)
{
    bool flag = true;

    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool addTrainTypeValidity(string trainType)
{
    bool flag = false;
    if (trainType == "BUSINESS" || trainType == "ECONOMICAL" || trainType == "FIRSTCLASS")
    {
        flag = true;
    }
    return flag;
}
bool TrainTypeValidity(string trainType,string preType)
{
    bool flag = false;
    if ((trainType == "BUSINESS" || trainType == "ECONOMICAL" || trainType == "FIRSTCLASS") && (trainType != preType))
    {
        flag = true;
    }
    return flag;
}
int addTrainPriceValidity(string trainPrice)
{
    int c = 0;
    int leng = trainPrice.length();

    for (int j = 0; j < leng; j++)
    {
        for (char i = '0'; i <= '9'; i++)
        {
            if (i == trainPrice[j])
            {
                c++;
            }
        }
    }
    if (c == leng)
    {
        c = stoi(trainPrice);
        return c;
    }
    else
    {
        return -1;
    }
}
bool addTrainDepartureValidity(string trainDeparture)
{

    int c = 0;
    int len = trainDeparture.length();

    if ((trainDeparture[0] >= '0' && trainDeparture[0] <= '9'))
    {
        if (trainDeparture[0] <= '2')
            c++;
    }
    if ((trainDeparture[1] >= '0' && trainDeparture[1] <= '9'))
    {
        if (trainDeparture[0] == '2' && trainDeparture[1] <= '3')
            c++;
        if (trainDeparture[0] != '2' && trainDeparture[1] <= '9')
            c++;
    }
    if (trainDeparture[2] == ':')
    {
        c++;
    }
    if ((trainDeparture[3] >= '0' && trainDeparture[3] <= '9'))
    {
        if (trainDeparture[3] <= '5')
            c++;
    }
    if ((trainDeparture[4] >= '0' && trainDeparture[4] <= '9'))
    {
        c++;
    }

    if (len != 5 || c != 5)
        return false;
    else
        return true;
}
bool addTrainCompartmentValidity(string trainCompartment)
{
    int c = 0;

    int leng = trainCompartment.length();

    for (int i = 0; i < 2; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (trainCompartment[i] == j)
                c++;
        }
    }
    if (c == 2 && leng == 2)
    {
        if (trainCompartment[0] == '1')
        {
            return true;
        }
        else if (trainCompartment[0] == '2' && trainCompartment[1] == '0')
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    else
        return false;
}
bool addTrainDiscountValidity(string trainDiscount)
{
    bool flag = false;
    int leng = trainDiscount.length();

    for (char i = '1'; i <= '9'; i++)
    {
        if (trainDiscount[0] == i)
            flag = true;
    }

    if (leng == 1 && flag == true)
        return true;
    else
        return false;
}
bool addTrainLuggageValidity(string trainLuggage)
{
    bool flag = false;
    int leng = trainLuggage.length();

    if (leng == 1)
    {
        for (char i = '0'; i <= '9'; i++)
        {
            if (trainLuggage[0] == i)
                flag = true;
        }
    }
    if (leng == 2)
    {
        if (trainLuggage[0] >= '0' && trainLuggage[0] <= '2')
        {
            if (trainLuggage[1] >= '0' && trainLuggage[1] <= '9')
                flag = true;
        }
    }
    if (trainLuggage[0] >= '0' && trainLuggage[0] <= '3')
    {
        if (trainLuggage[1] == '0')
            flag = true;
    }

    if ((leng == 1 || leng == 2) && flag == true)
        return true;
    else
        return false;
}
bool addTrainStartValidity(string trainStart)
{
    bool flag = false;

    if (trainStart == "LAHORE" || trainStart == "KARACHI" || trainStart == "ISLAMABAD" 
    || trainStart == "MULTAN" || trainStart == "PESHAWAR" || trainStart == "QUETTA" 
    || trainStart == "GUJRANWALA" || trainStart == "HAIDERABAD" || trainStart == "SIALKOT")
    {
        flag = true;
    }
    return flag;
}
bool addTrainEndValidity(string trainStart, string trainEnd)
{
    bool flag = false;
    
    if (trainEnd == "LAHORE" || trainEnd == "KARACHI" || trainEnd == "ISLAMABAD" 
    || trainEnd == "MULTAN" || trainEnd == "PESHAWAR" || trainEnd == "QUETTA" 
    || trainEnd == "GUJRANWALA" || trainEnd == "HAIDERABAD" || trainEnd == "SIALKOT")
    {

        if (trainStart != trainEnd)
            flag = true;
    }
    return flag;
}
void searchTrain()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to Searching Section ";
}
int searchTrainValidity(string checkName)
{
    int flag = -1;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            flag = i;
            break;
        }
    }
    return flag;
}
void removeTrain()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train deleting section";
}
int removeTrainValidity(string checkName)
{
    int flag = -1;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            flag = i;
            break;
        }
    }
    return flag;
}
void removeTrainExe(string checkName)
{
    int temp = 0;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = i;
            break;
        }
    }
    for (int j = temp; j < total; j++)
    {
        train[j] = train[j + 1];
        type[j] = type[j + 1];
        ticketPrice[j] = ticketPrice[j + 1];
        departureTime[j] = departureTime[j + 1];
        compartments[j] = compartments[j + 1];
        ticketsDiscount[j] = ticketsDiscount[j + 1];
        starting[j] = starting[j + 1];
        ending[j] = ending[j + 1];
    }
}
void classTrain()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train class change section";
}
int classTrainValidity(string checkName)
{
    int flag = -1;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            flag = i;
            break;
        }
    }
    return flag;
}
string previousClass(string checkName)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = type[i];
            break;
        }
    }
    return temp;
}
void classAssign(string checkName, string preClass)
{
    int temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            type[i] = preClass;
        }
    }
}
void departure()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train departure time change section";
}
string previousTime(string checkName)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = departureTime[i];
            break;
        }
    }
    return temp;
}
void timeAssign(string checkName, string preTime)
{
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            departureTime[i] = preTime;
        }
    }
}
void price()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's ticket price change section";
}
string previousPrice(string checkName)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = ticketPrice[i];
            break;
        }
    }
    return temp;
}
void priceAssign(string checkName, string prePrice)
{
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            ticketPrice[i] = prePrice;
        }
    }
}
void compartment()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's compartment changing section";
}
string previousCompartment(string checkName)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = compartments[i];
            break;
        }
    }
    return temp;
}
void compartmentAssign(string checkName, string preCompartment)
{
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            ticketPrice[i] = preCompartment;
        }
    }
}
void luggage()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's applying tax changing section";
}
string previousLuggage(string checkName)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = luggageTax[i];
            break;
        }
    }
    return temp;
}
void luggageAssign(string checkName, string preLuggage)
{
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            ticketPrice[i] = preLuggage;
        }
    }
}
void discount()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's discount availing section";
}
string previousDiscount(string checkName)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            temp = ticketsDiscount[i];
            break;
        }
    }
    return temp;
}
void discountAssign(string checkName, string preDiscount)
{
    for (int i = 0; i < total; i++)
    {
        if (checkName == train[i])
        {
            ticketPrice[i] = preDiscount;
        }
    }
}

void user()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";
}
bool budgetEnteringValidity(string budget)
{
    int c = 0;
    int leng = budget.length();

    for (int i = 0; i < leng; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (budget[i] == j)
            {
                c++;
            }
        }
    }
    if (leng == c)
        return true;
    else
        return false;
}
void startingPoint()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";
}
void selectClass()
{
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";
    gotoxy(20, 20);
    cout << "business , economical , firstClass  ";
    gotoxy(20, 22);
}
bool availableTrains(string choiceS, string choiceE)
{
    int c = 0;

    for (int i = 0; i < total; i++)
    {
        if (choiceS == starting[i] && choiceE == ending[i])
        {
            gotoxy(20, c + 28);
            cout << departureTime[i];
            gotoxy(38, c + 28);
            cout << type[i];
            gotoxy(53, c + 28);
            cout << ticketPrice[i];
            gotoxy(70, c + 28);
            cout << starting[i];
            gotoxy(85, c + 28);
            cout << ending[i];
            gotoxy(104, c + 28);
            cout << train[i];
            c++;
        }
    }

    if (c != 0)
    {
        gotoxy(20, 26);
        cout << "DepartureTime       Type      TicketPrice        Starting        Destination        Train";
        return true;
    }
    else
    {
        gotoxy(20, 26);
        cout << "No such train available which fulfills your requirement!!";
        return false;
    }
}
bool shedulingDeparture(string trainName, string choiceS, string choiceE)
{
    bool flag=false;

    for(int i=0 ; i<total ; i++ )
    {
    if(trainName == train[i] && choiceS == starting[i] && choiceE == ending[i])
    {
        flag = true;
    }
    }
    return flag;
}
int sheduling(string choice)
{
    int temp=-1;
    for(int i=0 ; i<total ; i++)
    {
        if(train[i]  == choice)
        {
        temp = i;
        break;
        }
    }
    return temp;
}
bool shedulingCompartment(string choice ,string trainCompartment)
{
    int c = 0;
    int temp;

    for(int i = 0 ; i<total ; i++)
    {
        if(train[i] == choice)
        {
            temp = i;
        }
    }

    int leng = trainCompartment.length();
    
    for(int i = 0 ; i<leng ; i++)
    {
        for(char j='0' ; j<='9' ; j++)
        {
            if(trainCompartment[i] == j)
            {
                c++;
            }
        }
    }

    if(leng <= 2 && c==leng )
    {
        c = stoi(trainCompartment);
        temp = stoi(compartments[temp]);

        if(c<=temp && c!=0)
        return true;
        else
        return false;
    }
    else
    return false;
   
}
bool shedulingLuggage(string choiceL)
{
    int c=0;
    int leng = choiceL.length();

    for(int i = 0 ; i<leng ; i++)
    {
        for(char j='0'; j<='9' ; j++ )
        {
            if(choiceL[i] == j)
            {
                c++;
            } 
        }
    }
    if(leng == c)
    return true;
    else
    return false;

}
void final(string choice,string choiceT,string choiceL,string choiceC)
{
    int tic;
    int ticDis;
    int ticPrice;
    int lug;
    int lugDis;
    int temp;
    int result;

    for(int i=0 ; i<total ; i++)
    {
        if(choice == train[i])
        {
            temp = i;
            break;
        }
    }

    ticPrice = stoi(ticketPrice[temp]);
    tic = stoi(choiceT);
    lug = stoi(choiceL);
    ticDis = stoi(ticketsDiscount[temp]);
    lugDis = stoi(luggageTax[temp]);

    ticPrice = ticPrice*tic;

    if(tic >= ticDis )
    {
        ticPrice=ticPrice - ticPrice*0.3;
    }
    result = ticPrice;
    if(lug>=lugDis)
    {
        result=ticPrice+ticPrice*0.2;
    }

    
                    gotoxy(20,20);
                    cout<<"Your total payable amount is :"<<result;
                    gotoxy(20,21);
                    cout<<"Your train's name is :"<<choice;
                    gotoxy(20,22);
                    cout<<"The class of the train is :"<<type[temp];
                    gotoxy(20,23);
                    cout<<"Your starting station is :"<<starting[temp];
                    gotoxy(20,24);
                    cout<<"Your destination is :"<<ending[temp];
                    gotoxy(20,25);
                    cout<<"Your selected compartment number is :"<<choiceC;
                    gotoxy(20,26);
                    cout<<"Please reach the station before "<<departureTime[temp];
                    gotoxy(70,30);
                    cout<<"Thank you!";
}
string conversion(string line)
{
    int len = line.length();

    for(int i=0 ; i<len ; i++)
    {
        for(char j='a' ; j<='z' ; j++)
        {
            if(line[i] == j)
            {
                line[i] = j - 32;
            }
        }
    }
    return line;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void panel()
{
    cout << "***************************************************************************************************************************************************************************" << endl;
    cout << "                                                                                                                                                                     " << endl;
    cout << "           ________                  __                  __       __                                                                                        __       " << endl;
    cout << "          /        |                /  |                /  \\     /  |                                                                                      /  |      " << endl;
    cout << "          ********/______   ______  **/  _______        **  \\   /** |  ______   _______    ______    ______    ______   _____  ____    ______   _______   _** |_     " << endl;
    cout << "            ** | /      \\ /      \\ /  |/       \\       ***  \\ /*** | /      \\ /       \\  /      \\  /      \\  /      \\ /     \\/    \\  /      \\ /       \\ / **   |     " << endl;
    cout << "            ** |/******  |******  |** |*******  |      ****  /**** | ******  |*******  | ******  |/******  |/******  |****** ****  |/******  |*******  |******/      " << endl;
    cout << "            ** |** |  **/ /    ** |** |** |  ** |      ** ** **/** | /    ** |** |  ** | /    ** |** |  ** |**    ** |** | ** | ** |**    ** |** |  ** |  ** | __    " << endl;
    cout << "            ** |** |     /******* |** |** |  ** |      ** |***/ ** |/******* |** |  ** |/******* |** \\__** |********/ ** | ** | ** |********/ ** |  ** |  ** |/  |   " << endl;
    cout << "            ** |** |     **    ** |** |** |  ** |      ** | */  ** |**    ** |** |  ** |**    ** |**    ** |**       |** | ** | ** |**       |** |  ** |  **  **/    " << endl;
    cout << "            **/ **/       *******/**/ **/    **/       **/      **/  *******/ **/   **/  *******/  ******* | *******/ **/  **/  **/  *******/ **/   **/    ****/     " << endl;
    cout << "                                                                                                  /  \\__** |                                                               " << endl;
    cout << "                                                                                                  **    **/                                                                " << endl;
    cout << "                                                                                                   ******/                                                                 " << endl;
    cout << "***************************************************************************************************************************************************************************" << endl;
    cout << "___________________________________________________________________________________________________________________________________________________________________________" << endl;
}
