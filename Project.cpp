//////////////////////////////Buildin libraries////////////////////////////////////////
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

///////////////////////////////Function Prototypes////////////////////////////////////
void gotoxy(int x, int y);
bool commaCheck(string input);                                    // it checks if there is any comma in given input or not
void panel();                                                     // prints header
string menu();                                                    // takes input from user
bool menuValidity(string option);                                 // checks whether the input is correct or not
string signUp();                                                  // take user's name for making account
bool isUserNameValid(string checkName);                           // checks whether the username is valid or not
bool passwordValidity(string password);                           // checks whether the password is valid or not
int loginValidity(string checkName, string checkPassword);        // checks if user can login or not
string adminMenu();                                               // takes user's choice
char adminMenuValidity(string option);                            // checks if user's choice is valid or not
string addTrain();                                                // takes train's name from the user
bool isTrainNameValid(string trainCheck);                         // checks if the train's name is valid or not
bool isTrainTypeValid(string trainType);                          // checks whether class of train is valid or not
int isTrainPriceValid(string trainPrice);                         // checks whether the ticket price is valid or not
bool isTrainDiscountValid(string trainDiscount);                  // checks whether the number of tickets to avail discount is valid or not
bool isTrainLuggageValid(string trainLuggage);                    // checks whether the luggage amount is valid or not
string searchTrain();                                             // takes the name of the train which is to be searched
void DisplaySearchTrain(int trainIndex);                          // display the information of the searched train
int searchTrainValidity(string trainCheck);                       // checks whether the given train exists or not
bool isDepartureTimeValid(string trainDeparture);                 // checks whether the departure time is valid or not
bool isTrainCompartmentValid(string trainCompartment);            // checks if the compartment number is valid or not
bool isTrainStartValid(string trainStart);                        // checks if the starting station is valid or not
bool isTrainEndValid(string trainStart, string trainEnd);         // checks if the destination station is valid or not
string removeTrain();                                             // takes the name of the train which is to be deleted
void removeTrainExecute(string trainCheck);                       // delete all the data of the given train
string classTrain();                                              // takes the name of train class
string previousClass(string trainCheck);                          // gives the previous class of the train
bool compareClasses(string trainType, string preType);            // checks if the new class and previous class are same or not
void classAssign(string trainCheck, string currentClass);         // updates the train class of given train
string departure();                                               // takes the departure time as input
string previousTime(string trainCheck);                           // gives the previous departure time of the given train
void timeAssign(string trainCheck, string preTime);               // updates the departure time of given train
string price();                                                   // takes the ticket price as input
string previousPrice(string trainCheck);                          // gives the previous ticket price of the given train
void priceAssign(string trainCheck, string prePrice);             // updates the ticket price of given train
string compartment();                                             // takes the number of compartments as input
string previousCompartment(string trainCheck);                    // gives the previous number of compartments of the given train
void compartmentAssign(string trainCheck, string preCompartment); // updates the number of compartments of given train
string luggage();                                                 // takes the luggage tax limit as input
string previousLuggage(string trainCheck);                        // gives the previous luggage tax limit of the given train
void luggageAssign(string trainCheck, string preLuggage);         // updates the luggage tax limit of given train
string discount();                                                // takes the number of tickets to avail discount as input
string previousDiscount(string trainCheck);                       // gives the previous number of tickets to avail discount of the given train
void discountAssign(string trainCheck, string preDiscount);       // updates the number of tickets to avail discount of given train

string user();                                                                                              // gives user's choice
string startingPoint();                                                                                     // gives starting station
string destinationPoint();                                                                                  // gives destination station
void selectClass();                                                                                         // shows class details
bool availableTrains(string startingInput, string destinationInput);                                        // tells if trains are available whose fulfill users requirements
bool isSelectedTrainValid(string trainName, string startingInput, string destinationInput);                 // tells if user entered the right train name or not
int currentTrainIndex(string trainCheck);                                                                   // gives the index of array of the selected train
bool isSelectedCompartmentValid(string trainCheck, string trainCompartment);                                // tells if the entered compartment is valid or not
bool isLuggageInNumbers(string luggageTaxCheck);                                                            // tells if the entered luggage is valid or not
int bill(string trainCheck, string ticketsDiscountCheck, string luggageTaxCheck, string compartmentsCheck); // gives the total payable amount
bool isReceivedAmountCorrect(string receivedAmount);                                                        // checks if the amount given by user is valid or not
string conversion(string line);                                                                             // converts all the string in uppercase letters
void sort();                                                                                                // sort the data with respect to ticket price

void loadingAccounts();                                                                                                                                                                                                                 // load user's data
void loadingTrainData();                                                                                                                                                                                                                // load trains related data
void storeTrainData(string trainCheck, string classCheck, string ticketPriceCheck, string departureTimeCheck, string compartmentsCheck, string ticketsDiscountCheck, string luggageTaxCheck, string startingCheck, string endingCheck); // store trains data
void storeUserTravelingHistory(string checkName, string trainCheck, string startingInput, string destinationInput, string ticketsDiscountCheck, string compartmentsCheck, string luggageTaxCheck, int totalBill);                       // store travelling history of users
void storeAccounts(string userName, string password, string role);                                                                                                                                                                      // store user accounts
void deleteTrainData();                                                                                                                                                                                                                 // delete data from the files
void updateInFile();                                                                                                                                                                                                                    // update's data in the file after some changes
void displayUserTravelingHistory();                                                                                                                                                                                                     // shows travelling history of all users
void displaySpecificUserTravelingHistory(string userName);                                                                                                                                                                              // shows travelling history of only specific user
string parsing(string word, int location);                                                                                                                                                                                              // user to parse specific data items from a file
////////////////////////////////////////Global Variables/////////////////////////////////////////////////
int total = 100;

int cycle = 0; // use to manage parallel arrays data of train

// all data related to trains is stored in given these arrays
string train[100];
string type[100];
string ticketPrice[100];
string departureTime[100];
string compartments[100];
string ticketsDiscount[100];
string luggageTax[100];
string starting[100];
string ending[100];

int count = 0; // use to manage parallel arrays data of users

// all data related to user accounts is stored in given these arrays
string names[100];
string passwords[100];
string role[100];
///////////////////////////////////////MAIN FUNCTION//////////////////////////////////
int main()
{

    loadingAccounts();
    loadingTrainData();
    ////////////////////////////////Local Variables//////////////////////////////////
    string option;
    string checkName;
    string checkPassword;
    string checkRole;
    string trainCheck;
    string classCheck;
    string ticketPriceCheck;
    string departureTimeCheck;
    string compartmentsCheck;
    string ticketsDiscountCheck;
    string luggageTaxCheck;
    string startingCheck;
    string endingCheck;
    string preClass;
    string currentClass;
    string preTime;
    string currentTime;
    string prePrice;
    string currentPrice;
    string preCompartment;
    string currentCompartment;
    string preLuggage;
    string currentLuggage;
    string preDiscount;
    string currentDiscount;

    string choice;
    string destinationInput;
    string startingInput;
    string receivedAmount;
    int totalBill;

    int intFlag;
    bool flagSign;
    char check1 = '0';

    bool flag;
    bool commaFlag;
    int flagSearch;

    while (true)
    {
        panel();
        option = menu();

        flag = menuValidity(option);
        while (flag == false) // force user to enter valid input
        {
            gotoxy(20, 26);
            cout << "Enter a valid option!!";
            gotoxy(40, 24);
            cout << "                         ";
            gotoxy(20, 24);
            cout << "Enter your choice : ";
            cin >> option;
            flag = menuValidity(option);
        }

        if (option[0] == '1')
        {
            panel();

            gotoxy(70, 18);
            cout << "*****Login Menu*****";
            gotoxy(20, 20);
            cout << "Enter your name :";
            cin >> checkName;
            gotoxy(20, 21);
            cout << "Enter your password :";
            cin >> checkPassword;

            intFlag = loginValidity(checkName, checkPassword);

            if (intFlag == -1)
            {
                gotoxy(20, 24);
                cout << " Information you have entered is invalid!!";
                getch();
                continue;
            }
            else
            {

                if (role[intFlag] == "ADMIN") // all of admin's functionalities are in this loop
                {
                    while (true)
                    {
                        option = adminMenu();

                        check1 = adminMenuValidity(option);
                        option = conversion(option);
                        if (option == "RETURN") // logout condition
                        {
                            gotoxy(20, 32);
                            cout << "Press any key to continue... ";
                            break;
                        }
                        else if (check1 == ',')
                        {
                            gotoxy(20, 33);
                            cout << "Enter a valid number!! ";
                            continue;
                        }

                        if (check1 == '1') // train adding section
                        {
                            trainCheck = addTrain();

                            flag = isTrainNameValid(trainCheck);
                            commaFlag = commaCheck(trainCheck);
                            if (trainCheck.length() < 3)
                            {
                                gotoxy(20, 31);
                                cout << "Train name should atleast have 3 characters!!";
                                getch();
                                continue;
                            }
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a different train name this one is already taken!!";
                                getch();
                                continue;
                            }
                            else if (commaFlag == false)
                            {
                                gotoxy(20, 31);
                                cout << "comma can not be used in username!!";
                                getch();
                                continue;
                            }

                            gotoxy(20, 32);
                            cout << "business,economical or firstClass";
                            gotoxy(20, 23);
                            cout << "Enter the class of the new train :";
                            cin >> classCheck;
                            classCheck = conversion(classCheck);
                            flag = isTrainTypeValid(classCheck);

                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid train class!!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                   ";
                            }

                            gotoxy(20, 32);
                            cout << "Minimum 500 and Maximum 5000";
                            gotoxy(20, 24);
                            cout << "Enter the price of ticket of the new train :";
                            cin >> ticketPriceCheck;
                            intFlag = isTrainPriceValid(ticketPriceCheck);
                            if (intFlag <= 0)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid price!!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                       ";
                            }

                            gotoxy(20, 32);
                            cout << "Correct format is hours:minutes and max time is 23:59";
                            gotoxy(20, 25);
                            cout << "Enter the time of departure of the new train :";
                            cin >> departureTimeCheck;
                            flag = isDepartureTimeValid(departureTimeCheck);
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Time might be invalid or format might be incorrect!!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                       ";
                            }

                            gotoxy(20, 32);
                            cout << "Minimum 10 and Maximum 20";
                            gotoxy(20, 26);
                            cout << "Enter the number of compartments of the new train :";
                            cin >> compartmentsCheck;
                            flag = isTrainCompartmentValid(compartmentsCheck);
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid compartment number !!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                       ";
                            }

                            gotoxy(20, 32);
                            cout << "Minimum 1 and Maximum 9";
                            gotoxy(20, 27);
                            cout << "Enter the number of tickets to avail the discount :";
                            cin >> ticketsDiscountCheck;
                            flag = isTrainDiscountValid(ticketsDiscountCheck);
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid number !!";

                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                   ";
                            }

                            gotoxy(20, 32);
                            cout << "Minimum 1 and Maximum 30";
                            gotoxy(20, 28);
                            cout << "Enter the minimum weight(kg) of luggage to apply tax :";
                            cin >> luggageTaxCheck;
                            flag = isTrainLuggageValid(luggageTaxCheck);
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid number !!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                               ";
                            }

                            gotoxy(20, 32);
                            cout << "Lahore,Karachi,Islamabad,Multan,Sialkot,Peshawar,Haiderabad,Gujranwala or Quetta";
                            gotoxy(20, 29);
                            cout << "Enter the starting point of the train :";
                            cin >> startingCheck;
                            startingCheck = conversion(startingCheck);
                            flag = isTrainStartValid(startingCheck);
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid Name !!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 32);
                                cout << "                                                                                            ";
                            }

                            gotoxy(20, 34);
                            cout << "Lahore,Karachi,Islamabad,Multan,Sialkot,Peshawar,Haiderabad,Gujranwala or Quetta";
                            gotoxy(20, 35);
                            cout << "Note : Starting point must not match the destination";
                            gotoxy(20, 30);
                            cout << "Enter the destination of the train :";
                            cin >> endingCheck;
                            endingCheck = conversion(endingCheck);
                            flag = isTrainEndValid(startingCheck, endingCheck);
                            if (flag == false)
                            {
                                gotoxy(20, 33);
                                cout << "Enter a valid Name !!";
                                getch();
                                continue;
                            }
                            else
                            {
                                gotoxy(20, 34);
                                cout << "                                                                                       ";
                                gotoxy(20, 35);
                                cout << "                                                                                         ";
                            }

                            train[cycle] = trainCheck;
                            type[cycle] = classCheck;
                            ticketPrice[cycle] = ticketPriceCheck;
                            departureTime[cycle] = departureTimeCheck;
                            compartments[cycle] = compartmentsCheck;
                            ticketsDiscount[cycle] = ticketsDiscountCheck;
                            luggageTax[cycle] = luggageTaxCheck;
                            starting[cycle] = startingCheck;
                            ending[cycle] = endingCheck;

                            storeTrainData(trainCheck, classCheck, ticketPriceCheck, departureTimeCheck, compartmentsCheck, ticketsDiscountCheck, luggageTaxCheck, startingCheck, endingCheck);
                        
                            cycle = cycle + 1;
                            gotoxy(20, 36);
                            cout << "New train has been added!";
                            gotoxy(20, 31);
                            cout << "                                                           ";
                            getch();
                        }
                        else if (check1 == '2') // train searching section
                        {
                            trainCheck = searchTrain();

                            flagSearch = searchTrainValidity(trainCheck);
                            if (flagSearch == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist !";
                                getch();
                                continue;
                            }

                            DisplaySearchTrain(flagSearch);
                        }
                        else if (check1 == '3') // train deleting section
                        {
                            trainCheck = removeTrain();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist !";
                                getch();
                                continue;
                            }

                            gotoxy(20, 31);
                            cout << "Tne train named " << trainCheck << " has been deleted successfully!!";
                            removeTrainExecute(trainCheck);
                            getch();
                        }
                        else if (check1 == '4') // class changing section
                        {
                            trainCheck = classTrain();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 30);
                                cout << "The train you have entered doesn't exist !!";
                                getch();
                                continue;
                            }

                            preClass = previousClass(trainCheck);
                            gotoxy(20, 23);
                            cout << "The previous class of train is " << preClass;
                            gotoxy(20, 32);
                            cout << "BUSINESS,ECONOMICAL or FIRSTCLASS";
                            gotoxy(20, 24);
                            cout << "Enter the new class for the train ";
                            cin >> currentClass;
                            currentClass = conversion(currentClass);
                            flag = compareClasses(currentClass, preClass);
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid train class!!";
                                gotoxy(20, 33);
                                cout << "Note : new class must not match the previous class!";
                                getch();
                                continue;
                            }

                            classAssign(trainCheck, currentClass);
                            gotoxy(20, 30);
                            cout << "Class of the train has been updated successfully!!";
                            getch();
                        }
                        else if (check1 == '5') // departing time changing section
                        {
                            trainCheck = departure();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist :";
                                getch();
                                continue;
                            }

                            preTime = previousTime(trainCheck);
                            gotoxy(20, 32);
                            cout << "Correct format is hours:minutes and max time is 23:59";
                            gotoxy(20, 23);
                            cout << "The previous departure time of this train is " << preTime;
                            gotoxy(20, 24);
                            cout << "Enter the new departure time for the train :";
                            cin >> currentTime;
                            flag = isDepartureTimeValid(currentTime);
                            if (currentTime == preTime)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid time for departure!!";
                                gotoxy(20, 32);
                                cout << "Previous Time must not match the new time";
                                getch();
                                continue;
                            }
                            else if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid time for departure!!";
                                getch();
                                continue;
                            }

                            timeAssign(trainCheck, currentTime);
                            gotoxy(20, 30);
                            cout << "Departure time of the train has been updated successfully!!";
                            getch();
                        }
                        else if (check1 == '6') // ticket price changing section
                        {
                            trainCheck = price();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist :";
                                getch();
                                continue;
                            }

                            prePrice = previousPrice(trainCheck);
                            gotoxy(20, 23);
                            cout << "The previous ticket price of this train is " << prePrice;
                            gotoxy(20, 24);
                            cout << "Enter the new ticket price for the train :";
                            cin >> currentPrice;
                            intFlag = isTrainPriceValid(currentPrice);
                            if (currentPrice == prePrice)
                            {
                                gotoxy(20, 31);
                                cout << "Previous Price must not match the new price";
                                getch();
                                continue;
                            }
                            else if (intFlag == -1)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid ticket price!!";
                                getch();
                                continue;
                            }

                            priceAssign(trainCheck, currentPrice);
                            gotoxy(20, 30);
                            cout << "Ticket price of the train has been updated successfully!!";
                            getch();
                        }
                        else if (check1 == '7') // number of compartments changing section
                        {
                            trainCheck = compartment();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist !";
                                getch();
                                continue;
                            }

                            preCompartment = previousCompartment(trainCheck);
                            gotoxy(20, 23);
                            cout << "The previous number of compartments of this train is " << preCompartment;
                            gotoxy(20, 24);
                            cout << "Enter the new number of compartments for the train :";
                            cin >> currentCompartment;
                            flag = isTrainCompartmentValid(currentCompartment);
                            if (currentCompartment == preCompartment)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid number for compartment !!";
                                gotoxy(20, 32);
                                cout << "New number of compartments must not match the previous number of compartments";
                                getch();
                                continue;
                            }
                            else if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid number for compartment !!";
                                getch();
                                continue;
                            }

                            compartmentAssign(trainCheck, currentCompartment);
                            gotoxy(20, 30);
                            cout << "Compartment numbers of the train has been updated successfully!!";
                            getch();
                        }
                        else if (check1 == '8') // luggage limit for applying tax changing section
                        {

                            trainCheck = luggage();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist !";
                                getch();
                                continue;
                            }

                            preLuggage = previousLuggage(trainCheck);
                            gotoxy(20, 30);
                            cout << "Minimum 1 kg and Maximum 30 kg";
                            gotoxy(20, 23);
                            cout << "The previous amount of luggage for applying tax of this train is " << preLuggage;
                            gotoxy(20, 24);
                            cout << "Enter the new amount of luggage for applying tax for the train :";
                            cin >> currentLuggage;
                            flag = isTrainLuggageValid(currentLuggage);
                            if (currentLuggage == preLuggage)
                            {
                                gotoxy(20, 31);
                                cout << "New amount of luggage for applying tax must not match the previous amount of luggage for applying tax!!";
                                getch();
                                continue;
                            }
                            else if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid number !!";
                                getch();
                                continue;
                            }

                            luggageAssign(trainCheck, currentLuggage);
                            gotoxy(20, 30);
                            cout << "Luggage amount for applying Tax of the train has been updated successfully!!";
                            getch();
                        }
                        else if (check1 == '9') // changing number of tickets to give discount section
                        {

                            trainCheck = discount();

                            intFlag = searchTrainValidity(trainCheck);
                            if (intFlag == -1)
                            {
                                gotoxy(20, 25);
                                cout << "The train you have entered doesn't exist :";
                                getch();
                                continue;
                            }

                            preDiscount = previousDiscount(trainCheck);
                            gotoxy(20, 32);
                            cout << "Minimum 1 and Maximum 9";
                            gotoxy(20, 23);
                            cout << "The previous number of tickets of this train to avail discount is " << preDiscount;
                            gotoxy(20, 24);
                            cout << "Enter the new number of tickets to avail discount for the train :";
                            cin >> currentDiscount;
                            flag = isTrainDiscountValid(currentDiscount);
                            if (currentDiscount == preDiscount)
                            {
                                gotoxy(20, 31);
                                cout << "New tickets number must not match the previous ticket numbers";
                                getch();
                                continue;
                            }
                            else if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << "Enter a valid number of tickets for availing discount !!";
                                getch();
                                continue;
                            }

                            discountAssign(trainCheck, preDiscount);
                            gotoxy(20, 30);
                            cout << "Number of tickets to avail discount of the train has been updated successfully!!";
                            getch();
                        }
                        else // travelling history view of all users
                        {
                            panel();
                            gotoxy(70, 18);
                            cout << "Travelling History";
                            gotoxy(0, 20);
                            displayUserTravelingHistory();
                        }
                    }
                    getch();
                }
                else
                {

                    while (true)
                    {
                        choice = user();

                        if (choice != "0" && choice != "1" && choice != "2")
                        {
                            gotoxy(20, 26);
                            cout << "Enter a valid choice!!";
                            getch();
                            continue;
                        }
                        if (choice == "0") // logout condition
                            break;
                        else if (choice == "2") // to view my own travelling history
                        {
                            panel();
                            gotoxy(70, 18);
                            cout << "Travelling History";
                            gotoxy(0, 20);
                            displaySpecificUserTravelingHistory(checkName);
                            continue;
                        }

                        startingInput = startingPoint();
                        flag = isTrainStartValid(startingInput);
                        if (flag == false)
                        {
                            gotoxy(20, 22);
                            cout << " Invalid input!!";
                            getch();
                            continue;
                        }

                        destinationInput = destinationPoint();
                        flag = isTrainEndValid(startingInput, destinationInput);
                        if (flag == false)
                        {
                            gotoxy(20, 30);
                            cout << " Invalid input!!";
                            gotoxy(20, 32);
                            cout << "Note: starting point and destination must not match";
                            getch();
                            continue;
                        }
                        gotoxy(20, 31);
                        cout << "                                                                                  ";

                        flag = availableTrains(startingInput, destinationInput);
                        if (flag == false)
                        {
                            gotoxy(20, 30);
                            cout << "Press Enter to return";
                            getch();
                            continue;
                        }

                        gotoxy(20, 23);
                        cout << "Enter the name of train in which you want to travel :";
                        cin >> trainCheck;
                        trainCheck = conversion(trainCheck);

                        flag = isSelectedTrainValid(trainCheck, startingInput, destinationInput);
                        if (flag == false)
                        {
                            gotoxy(20, 24);
                            cout << "The train you have entered is not available or exist!";
                            getch();
                            continue;
                        }

                        while (true)
                        {
                            bool check = 0;
                            panel();

                            gotoxy(70, 18);
                            cout << "*****Passener's Menu*****";

                            intFlag = currentTrainIndex(trainCheck);
                            gotoxy(20, 25);
                            cout << "Purchase " << ticketsDiscount[intFlag] << " tickets to get 30 percent discount";
                            gotoxy(20, 26);
                            cout << "Minimum 1 and Maximum 9 tickets can be purchased from 1 user account";
                            gotoxy(20, 27);
                            cout << "Enter 'return' to go back to the main screen of user panel";
                            gotoxy(20, 20);
                            cout << "Enter how many tickets you want to purchase :";
                            cin >> ticketsDiscountCheck;
                            flag = isTrainDiscountValid(ticketsDiscountCheck);
                            ticketsDiscountCheck = conversion(ticketsDiscountCheck);
                            if (ticketsDiscountCheck == "RETURN") // to go back to previous options
                                break;
                            if (flag == false)
                            {
                                gotoxy(20, 31);
                                cout << " Invalid input !!";
                                getch();
                                continue;
                            }
                            gotoxy(20, 32);
                            cout << "                                                                        ";
                            while (true)
                            {
                                panel();

                                gotoxy(70, 18);
                                cout << "*****Passener's Menu*****";

                                gotoxy(20, 26);
                                cout << "Your choice should not exceed total number of compartments of selected train!!";
                                gotoxy(20, 25);
                                cout << "Total compartments of the selected train are " << compartments[intFlag];
                                gotoxy(20, 27);
                                cout << "Enter 'return' to go back to previous screen";
                                gotoxy(20, 20);
                                cout << "Enter the compartment of the train in which you want to sit in :";
                                cin >> compartmentsCheck;
                                flag = isSelectedCompartmentValid(trainCheck, compartmentsCheck);
                                compartmentsCheck = conversion(compartmentsCheck);
                                if (compartmentsCheck == "RETURN") // to go back to previous options
                                    break;
                                if (flag == false)
                                {
                                    gotoxy(20, 30);
                                    cout << "Invalid compartment !!";
                                    getch();
                                    continue;
                                }
                                gotoxy(20, 30);
                                cout << "                                                          ";
                                gotoxy(20, 31);
                                cout << "                                                                                   ";

                                while (true)
                                {
                                    panel();

                                    gotoxy(70, 18);
                                    cout << "*****Passener's Menu*****";

                                    gotoxy(20, 25);
                                    cout << "if your luggage exceeds " << luggageTax[intFlag] << " kg, tax of 20% of total bill will be applied";
                                    gotoxy(20, 26);
                                    cout << "You can carry maximum 50 kg luggage with you";
                                    gotoxy(20, 27);
                                    cout << "Enter 'return' to go back to previous screen";
                                    gotoxy(20, 20);
                                    cout << "Enter the amount of luggage you want to carry with :";
                                    cin >> luggageTaxCheck;
                                    flag = isLuggageInNumbers(luggageTaxCheck);
                                    luggageTaxCheck = conversion(luggageTaxCheck);
                                    if (luggageTaxCheck == "RETURN") // to go back to previous options
                                        break;
                                    if (flag == false)
                                    {
                                        gotoxy(20, 30);
                                        cout << " Invalid luggage amount !!";
                                        getch();
                                        continue;
                                    }
                                    else if (stoi(luggageTaxCheck) > 50)
                                    {
                                        gotoxy(20, 30);
                                        cout << " You can't carry more than 50kg with you !!";
                                        getch();
                                        continue;
                                    }

                                    while (true)
                                    {
                                        panel();

                                        gotoxy(70, 18);
                                        cout << "*****Passenger's Menu*****";

                                        totalBill = bill(trainCheck, ticketsDiscountCheck, luggageTaxCheck, compartmentsCheck);
                                        check = 1;

                                        gotoxy(20, 29);
                                        cout << "Enter 'return' to go back to main screen of user panel";
                                        gotoxy(20, 27);
                                        cout << "Enter the amount : ";
                                        cin >> receivedAmount;
                                        receivedAmount = conversion(receivedAmount);
                                        flag = isReceivedAmountCorrect(receivedAmount);
                                        if (receivedAmount == "RETURN") // to go back to previous options
                                            break;

                                        if (flag == false)
                                        {
                                            gotoxy(20, 31);
                                            cout << " Invalid amount !";
                                            getch();
                                            continue;
                                        }
                                        else if (totalBill > stoi(receivedAmount))
                                        {
                                            gotoxy(20, 31);
                                            cout << " Your given amount is not enough !";
                                            getch();
                                            continue;
                                        }
                                        else
                                        {
                                            gotoxy(20, 28);
                                            cout << " your cashback is : " << stoi(receivedAmount) - totalBill;

                                            gotoxy(70, 33);
                                            cout << "Thank you!";
                                            getch();
                                            storeUserTravelingHistory(checkName, trainCheck, startingInput, destinationInput, ticketsDiscountCheck, compartmentsCheck, luggageTaxCheck, totalBill);
                                            break;
                                        }
                                    }
                                    if (check == 1)
                                        break;
                                }
                                if (check == 1)
                                    break;
                            }
                            if (check == 1)
                                break;
                        }
                    }
                    gotoxy(20, 30);
                    cout << "Press any key to return";
                    getch();
                }
            }
        }

        else if (option[0] == '2') // sign up options
        {
            checkName = signUp();

            flag = isUserNameValid(checkName);
            commaFlag = commaCheck(checkName);
            if (flag == false)
            {
                gotoxy(20, 24);
                cout << "User Already exists!";
                getch();
                continue;
            }
            else if (commaFlag == false)
            {
                gotoxy(20, 24);
                cout << "Comma can not be used in username!";
                getch();
                continue;
            }
            else if (checkName.length() < 5)
            {
                gotoxy(20, 24);
                cout << "username should atleast have length of 5!";
                getch();
                continue;
            }

            gotoxy(20, 21);
            cout << "Enter your password :";
            cin >> checkPassword;

            flag = passwordValidity(checkPassword);
            commaFlag = commaCheck(checkPassword);
            if (flag == false)
            {
                gotoxy(20, 24);
                cout << "Password should atleast have length of 8 !!";
                getch();
                continue;
            }
            else if (commaFlag == false)
            {
                gotoxy(20, 24);
                cout << "comma can not be used in password!!";
                getch();
                continue;
            }

            gotoxy(20, 22);
            cout << "Enter your role :";
            cin >> checkRole;
            checkRole = conversion(checkRole);

            if (checkRole != "ADMIN" && checkRole != "USER")
            {
                gotoxy(20, 24);
                cout << "Invalid role!!";
                gotoxy(20, 25);
                cout << "role should be admin or user!!";
                continue;
            }

            gotoxy(20, 26);
            cout << "User has been added successfully...";
            names[count] = checkName;
            passwords[count] = checkPassword;
            role[count] = checkRole;
            storeAccounts(checkName, checkPassword, checkRole);
            count++;
            getch();
        }
        else // program terminating condition
        {
            return 0;
        }
    }
}

///////////////////////////////////////other functions/////////////////////////////////////////////////////////
string menu()
{
    string option;
    gotoxy(75, 18);
    cout << "*****MENU*****";
    gotoxy(20, 20);
    cout << "Enter 1 to login ";
    gotoxy(20, 21);
    cout << "Enter 2 to SignUP ";
    gotoxy(20, 22);
    cout << "Enter 3 to exit program ";

    gotoxy(20, 24);
    cout << "Enter your choice : ";
    cin >> option;

    return option;
}
bool menuValidity(string option)
{
    bool flag = false;

    if (option == "1" || option == "2" || option == "3")
    {
        flag = true;
    }
    return flag;
}
string signUp()
{
    string checkName;
    panel();
    gotoxy(70, 18);
    cout << "*****SignUp Menu*****";

    gotoxy(20, 20);
    cout << "Enter your name :";
    cin >> checkName;

    return checkName;
}
bool isUserNameValid(string checkName)
{
    bool flag = true;
    for (int i = 0; i < total; i++)
    {
        if (checkName == names[i])
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

    if (leng < 8)
        flag = false;

    return flag;
}
int loginValidity(string checkName, string checkPassword)
{
    int flag;
    int COUNT = 0;
    for (int i = 0; i < total; i++)
    {
        if (checkName == names[i] && checkPassword == passwords[i])
        {
            if (role[i] == "ADMIN" || role[i] == "USER")
            {
                COUNT++;
                flag = i;
                break;
            }
        }
    }
    if (COUNT == 0)
        flag = -1;

    return flag;
}
string adminMenu()
{
    string option;
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
    cout << "Enter 0 to view the travelling history of users.";
    gotoxy(20, 31);
    cout << "Enter 'return' to logout from admin panel.";
    gotoxy(20, 32);
    cout << "Enter your choice :";
    cin >> option;

    return option;
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
        value = ',';
    }

    return value;
}
string addTrain()
{
    string trainCheck;

    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train adding section";

    gotoxy(20, 22);
    cout << "Enter the name of new train :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
bool isTrainNameValid(string trainCheck)
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
bool isTrainTypeValid(string trainType)
{
    bool flag = false;
    if (trainType == "BUSINESS" || trainType == "ECONOMICAL" || trainType == "FIRSTCLASS")
    {
        flag = true;
    }
    return flag;
}
bool compareClasses(string trainType, string preType)
{
    bool flag = false;
    if (((trainType == "BUSINESS" || trainType == "ECONOMICAL" || trainType == "FIRSTCLASS")) && (trainType != preType))
    {
        flag = true;
    }
    return flag;
}
int isTrainPriceValid(string trainPrice)
{
    int COUNT = 0;
    int check = -1;
    int leng = trainPrice.length();

    for (int j = 0; j < leng; j++)
    {
        for (char i = '0'; i <= '9'; i++)
        {
            if (i == trainPrice[j])
            {
                COUNT++;
            }
        }
    }
    if (COUNT == leng)
    {
        COUNT = stoi(trainPrice);
        if (COUNT >= 500 && COUNT <= 5000)
            check = 1;
    }
    else
    {
        check = -1;
    }
    return check;
}
bool isDepartureTimeValid(string trainDeparture)
{

    int COUNT = 0;
    int len = trainDeparture.length();

    if ((trainDeparture[0] >= '0' && trainDeparture[0] <= '9'))
    {
        if (trainDeparture[0] <= '2')
            COUNT++;
    }
    if ((trainDeparture[1] >= '0' && trainDeparture[1] <= '9'))
    {
        if (trainDeparture[0] == '2' && trainDeparture[1] <= '3')
            COUNT++;
        if (trainDeparture[0] != '2' && trainDeparture[1] <= '9')
            COUNT++;
    }
    if (trainDeparture[2] == ':')
    {
        COUNT++;
    }
    if ((trainDeparture[3] >= '0' && trainDeparture[3] <= '9'))
    {
        if (trainDeparture[3] <= '5')
            COUNT++;
    }
    if ((trainDeparture[4] >= '0' && trainDeparture[4] <= '9'))
    {
        COUNT++;
    }

    if (len != 5 || COUNT != 5)
        return false;
    else
        return true;
}
bool isTrainCompartmentValid(string trainCompartment)
{
    int COUNT = 0;
    bool flag = false;

    int leng = trainCompartment.length();

    for (int i = 0; i < 2; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (trainCompartment[i] == j)
                COUNT++;
        }
    }
    if (COUNT == leng )
    {
        COUNT = stoi(trainCompartment);
        if(COUNT > 9 && COUNT < 21)
        flag = true;
    }
        return flag;
}
bool isTrainDiscountValid(string trainDiscount)
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
bool isTrainLuggageValid(string trainLuggage)
{
    bool flag = false;
    int check = 0;
    int leng = trainLuggage.length();

    for (int i = 0; i < leng; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (trainLuggage[i] == j)
                check++;
        }
    }
    if (check == leng)
    {
        check = stoi(trainLuggage);
        if (check > 0 && check <= 30)
            flag = true;
    }

    return flag;
}
bool isTrainStartValid(string trainStart)
{
    bool flag = false;

    if (trainStart == "LAHORE" || trainStart == "KARACHI" || trainStart == "ISLAMABAD" || trainStart == "MULTAN" || trainStart == "PESHAWAR" || trainStart == "QUETTA" || trainStart == "GUJRANWALA" || trainStart == "HAIDERABAD" || trainStart == "SIALKOT")
    {
        flag = true;
    }
    return flag;
}
bool isTrainEndValid(string trainStart, string trainEnd)
{
    bool flag = false;

    if (trainEnd == "LAHORE" || trainEnd == "KARACHI" || trainEnd == "ISLAMABAD" || trainEnd == "MULTAN" || trainEnd == "PESHAWAR" || trainEnd == "QUETTA" || trainEnd == "GUJRANWALA" || trainEnd == "HAIDERABAD" || trainEnd == "SIALKOT")
    {

        if (trainStart != trainEnd)
            flag = true;
    }
    return flag;
}
string searchTrain()
{
    string trainCheck;
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to Searching Section ";

    gotoxy(20, 22);
    cout << "Enter the name of train you want to search :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
int searchTrainValidity(string trainCheck)
{
    int flag = -1;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            flag = i;
            break;
        }
    }
    return flag;
}
void DisplaySearchTrain(int trainIndex)
{
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to Searching Section ";
    gotoxy(20, 22);
    cout << "Required train is : " << train[trainIndex];
    gotoxy(20, 23);
    cout << "The class of this train is : " << type[trainIndex];
    gotoxy(20, 24);
    cout << "The time of departure of this train is : " << departureTime[trainIndex];
    gotoxy(20, 25);
    cout << "The number of compartments of this train is : " << compartments[trainIndex];
    gotoxy(20, 26);
    cout << "The price of ticket of this train is : " << ticketPrice[trainIndex];
    gotoxy(20, 27);
    cout << "The minimum number of tickets to avail discount are : " << ticketsDiscount[trainIndex];
    gotoxy(20, 28);
    cout << "The minimum amount of luggage to apply tax is  : " << luggageTax[trainIndex];
    gotoxy(20, 29);
    cout << "The starting point of the train is : " << starting[trainIndex];
    gotoxy(20, 30);
    cout << "The destination of the train is  : " << ending[trainIndex];
    getch();
}
string removeTrain()
{
    string trainCheck;
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train deleting section";

    gotoxy(20, 22);
    cout << "Enter the name of the train you want to delete :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
void removeTrainExecute(string trainCheck)
{
    int temp = 0;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
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
    cycle--;
    deleteTrainData();
}
string classTrain()
{
    string trainCheck;
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train class change section";

    gotoxy(20, 22);
    cout << "Enter the name of the train whose class you want to change :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
string previousClass(string trainCheck)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = type[i];
            break;
        }
    }
    return temp;
}
void classAssign(string trainCheck, string currentClass)
{
    int temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            type[i] = currentClass;
        }
    }
    updateInFile();
}
string departure()
{
    string trainCheck;

    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train departure time change section";

    gotoxy(20, 22);
    cout << "Enter the name of the train whose departure time you want to change :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
string previousTime(string trainCheck)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = departureTime[i];
            break;
        }
    }
    return temp;
}
void timeAssign(string trainCheck, string preTime)
{
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            departureTime[i] = preTime;
        }
    }
    updateInFile();
}
string price()
{
    string trainCheck;
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's ticket price change section";

    gotoxy(20, 32);
    cout << "Minimum 500 and maximum 5000!!";
    gotoxy(20, 22);
    cout << "Enter the name of the train whose ticket price you want to change :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
string previousPrice(string trainCheck)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = ticketPrice[i];
            break;
        }
    }
    return temp;
}
void priceAssign(string trainCheck, string prePrice)
{
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            ticketPrice[i] = prePrice;
        }
    }
    updateInFile();
}
string compartment()
{
    string trainCheck;
    system("cls");
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 32);
    cout << "Minimum 10 and Maximum 20";
    gotoxy(20, 20);
    cout << "Welcome to train's compartment changing section";
    gotoxy(20, 22);
    cout << "Enter the name of the train whose compartments you want to change :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
string previousCompartment(string trainCheck)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = compartments[i];
            break;
        }
    }
    return temp;
}
void compartmentAssign(string trainCheck, string preCompartment)
{
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            compartments[i] = preCompartment;
        }
    }
    updateInFile();
}
string luggage()
{
    string trainCheck;
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's applying tax changing section";
    gotoxy(20, 22);
    cout << "Enter the name of the train whose amount of luggage for applying tax you want to change :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
string previousLuggage(string trainCheck)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = luggageTax[i];
            break;
        }
    }
    return temp;
}
void luggageAssign(string trainCheck, string preLuggage)
{
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            luggageTax[i] = preLuggage;
        }
    }
    updateInFile();
}
string discount()
{
    string trainCheck;
    panel();

    gotoxy(70, 18);
    cout << "*****Manager's Menu*****";

    gotoxy(20, 20);
    cout << "Welcome to train's discount availing section";

    gotoxy(20, 22);
    cout << "Enter the name of the train whose discount availing tickets you want to change :";
    cin >> trainCheck;
    trainCheck = conversion(trainCheck);

    return trainCheck;
}
string previousDiscount(string trainCheck)
{
    string temp;
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = ticketsDiscount[i];
            break;
        }
    }
    return temp;
}
void discountAssign(string trainCheck, string preDiscount)
{
    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            ticketPrice[i] = preDiscount;
        }
    }
    updateInFile();
}

string user()
{
    string choice;
    panel();

    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";

    gotoxy(20, 20);
    cout << "Enter 1 for purchasing tickets and sheduling departure";
    gotoxy(20, 21);
    cout << "Enter 2 for viewing your travelling history";
    gotoxy(20, 22);
    cout << "Enter 0 to logout from user panel";
    gotoxy(20, 25);
    cout << "Enter your choice :";
    cin >> choice;

    return choice;
}
string startingPoint()
{
    string startingInput;
    panel();

    gotoxy(80, 24);
    cout << "Available Stations";
    gotoxy(20, 26);
    cout << "Lahore";
    gotoxy(50, 26);
    cout << "Karachi";
    gotoxy(80, 26);
    cout << "Islamabad";
    gotoxy(110, 26);
    cout << "Multan";
    gotoxy(140, 26);
    cout << "Quetta";
    gotoxy(20, 27);
    cout << "Sialkot";
    gotoxy(50, 27);
    cout << "Peshawar";
    gotoxy(80, 27);
    cout << "Haiderabad";
    gotoxy(110, 27);
    cout << "Gujranwala";
    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";

    gotoxy(20, 20);
    cout << "Enter your starting point :";
    cin >> startingInput;
    startingInput = conversion(startingInput);

    return startingInput;
}
string destinationPoint()
{
    string destinationInput;
    panel();

    gotoxy(80, 24);
    cout << "Available Stations";
    gotoxy(20, 26);
    cout << "Lahore";
    gotoxy(50, 26);
    cout << "Karachi";
    gotoxy(80, 26);
    cout << "Islamabad";
    gotoxy(110, 26);
    cout << "Multan";
    gotoxy(140, 26);
    cout << "Quetta";
    gotoxy(20, 27);
    cout << "Sialkot";
    gotoxy(50, 27);
    cout << "Peshawar";
    gotoxy(80, 27);
    cout << "Haiderabad";
    gotoxy(110, 27);
    cout << "Gujranwala";

    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";

    gotoxy(20, 20);
    cout << "Enter your destination :";
    cin >> destinationInput;
    destinationInput = conversion(destinationInput);

    return destinationInput;
}
void selectClass()
{
    panel();

    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";
    gotoxy(20, 20);
    cout << "BUSINESS , ECONOMICAL , FIRSTCLASS  ";
    gotoxy(20, 22);
}
bool availableTrains(string startingInput, string destinationInput)
{
    panel();
    gotoxy(70, 18);
    cout << "*****Passener's Menu*****";
    int COUNT = 0;

    sort();
    for (int i = 0; i < total; i++)
    {
        if (startingInput == starting[i] && destinationInput == ending[i])
        {
            gotoxy(20, COUNT + 28);
            cout << departureTime[i];
            gotoxy(38, COUNT + 28);
            cout << type[i];
            gotoxy(53, COUNT + 28);
            cout << ticketPrice[i];
            gotoxy(70, COUNT + 28);
            cout << starting[i];
            gotoxy(85, COUNT + 28);
            cout << ending[i];
            gotoxy(104, COUNT + 28);
            cout << train[i];
            COUNT++;
        }
    }

    if (COUNT != 0)
    {
        gotoxy(20, 26);
        cout << "DepartureTime       Type      TicketPrice        Starting        Destination        Train";
        return true;
    }
    else
    {
        gotoxy(20, 29);
        cout << "No such train available which fulfills your requirement!!";
        return false;
    }
}
bool isSelectedTrainValid(string trainName, string startingInput, string destinationInput)
{
    bool flag = false;

    for (int i = 0; i < total; i++)
    {
        if (trainName == train[i] && startingInput == starting[i] && destinationInput == ending[i])
        {
            flag = true;
        }
    }
    return flag;
}
int currentTrainIndex(string trainCheck)
{
    int temp = -1;
    for (int i = 0; i < total; i++)
    {
        if (train[i] == trainCheck)
        {
            temp = i;
            break;
        }
    }
    return temp;
}
bool isSelectedCompartmentValid(string trainCheck, string trainCompartment)
{
    int COUNT = 0;
    int temp;

    for (int i = 0; i < total; i++)
    {
        if (train[i] == trainCheck)
        {
            temp = i;
        }
    }

    int leng = trainCompartment.length();

    for (int i = 0; i < leng; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (trainCompartment[i] == j)
            {
                COUNT++;
            }
        }
    }

    if (leng <= 2 && COUNT == leng)
    {
        COUNT = stoi(trainCompartment);
        temp = stoi(compartments[temp]);

        if (COUNT <= temp && COUNT != 0)
            return true;
        else
            return false;
    }
    else
        return false;
}
bool isLuggageInNumbers(string luggageTaxCheck)
{
    int COUNT = 0;
    int leng = luggageTaxCheck.length();

    for (int i = 0; i < leng; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (luggageTaxCheck[i] == j)
            {
                COUNT++;
            }
        }
    }
    if (leng == COUNT)
        return true;
    else
        return false;
}
int bill(string trainCheck, string ticketsDiscountCheck, string luggageTaxCheck, string compartmentsCheck)
{
    int tic;
    int ticDis;
    int ticPrice;
    int lug;
    int lugDis;
    int temp;
    int result;

    for (int i = 0; i < total; i++)
    {
        if (trainCheck == train[i])
        {
            temp = i;
            break;
        }
    }

    ticPrice = stoi(ticketPrice[temp]);
    tic = stoi(ticketsDiscountCheck);
    lug = stoi(luggageTaxCheck);
    ticDis = stoi(ticketsDiscount[temp]);
    lugDis = stoi(luggageTax[temp]);

    ticPrice = ticPrice * tic;

    if (tic >= ticDis)
    {
        ticPrice = ticPrice - ticPrice * 0.3;
    }
    result = ticPrice;
    if (lug >= lugDis)
    {
        result = ticPrice + ticPrice * 0.2;
    }

    gotoxy(20, 20);
    cout << "Your total payable amount is :" << result;
    gotoxy(20, 21);
    cout << "Your train's name is :" << trainCheck;
    gotoxy(20, 22);
    cout << "The class of the train is :" << type[temp];
    gotoxy(20, 23);
    cout << "Your starting station is :" << starting[temp];
    gotoxy(20, 24);
    cout << "Your destination is :" << ending[temp];
    gotoxy(20, 25);
    cout << "Your selected compartment number is :" << compartmentsCheck;

    return result;
}
string conversion(string line)
{
    int len = line.length();

    for (int i = 0; i < len; i++)
    {
        for (char j = 'a'; j <= 'z'; j++)
        {
            if (line[i] == j)
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
bool commaCheck(string input)
{
    bool flag = true;
    int leng = input.length();
    for (int i = 0; i < leng; i++)
    {
        if (input[i] == ',')
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void storeAccounts(string userName, string password, string role)
{

    fstream file;
    file.open("accounts.txt", ios::app);
    file << userName << "," << password << "," << role << endl;
    file.close();
}
void storeTrainData(string trainCheck, string classCheck, string ticketPriceCheck, string departureTimeCheck, string compartmentsCheck, string ticketsDiscountCheck, string luggageTaxCheck, string startingCheck, string endingCheck)
{
    fstream file;
    file.open("adminData.txt", ios::app);
    file << trainCheck << "," << classCheck << "," << ticketPriceCheck << "," << departureTimeCheck << "," << compartmentsCheck
         << "," << ticketsDiscountCheck << "," << luggageTaxCheck << "," << startingCheck << "," << endingCheck << endl;
    file.close();
}
void deleteTrainData()
{
    fstream file;
    file.open("adminData.txt", ios::out);
    for (int i = 0; i < cycle-1; i++)
    {
        file << train[i] << "," << type[i] << "," << ticketPrice[i] << "," << departureTime[i] << "," << compartments[i]
             << "," << ticketsDiscount[i] << "," << luggageTax[i] << "," << starting[i] << "," << ending[i] << endl;
    }
    file.close();
}
void updateInFile()
{
    fstream file;
    file.open("adminData.txt", ios::out);
    for (int i = 0; i < cycle; i++)
    {
        file << train[i] << "," << type[i] << "," << ticketPrice[i] << "," << departureTime[i] << "," << compartments[i]
             << "," << ticketsDiscount[i] << "," << luggageTax[i] << "," << starting[i] << "," << ending[i] << endl;
    }
    file.close();
}

void loadingAccounts()
{
    fstream file;
    string word;
    file.open("accounts.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        names[count] = parsing(word, 1);
        passwords[count] = parsing(word, 2);
        role[count] = parsing(word, 3);
        count++;
    }
    file.close();
}
void loadingTrainData()
{
    fstream file;
    string word;
    file.open("adminData.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        train[cycle] = parsing(word, 1);
        type[cycle] = parsing(word, 2);
        ticketPrice[cycle] = parsing(word, 3);
        departureTime[cycle] = parsing(word, 4);
        compartments[cycle] = parsing(word, 5);
        ticketsDiscount[cycle] = parsing(word, 6);
        luggageTax[cycle] = parsing(word, 7);
        starting[cycle] = parsing(word, 8);
        ending[cycle] = parsing(word, 9);
        cycle++;
    }
    file.close();
}
void sort()
{
    string tempTrain;
    string tempType;
    string tempTicketPrice;
    string tempDepartureTime;
    string tempCompartments;
    string tempTicketsDiscount;
    string tempLuggageTax;
    string tempStarting;
    string tempEnding;

    int temp1;
    int temp2;

    for (int i = 0; i < cycle; i++)
    {
        for (int j = i + 1; j < cycle; j++)
        {
            temp1 = atoi(ticketPrice[i].c_str());
            temp2 = atoi(ticketPrice[j].c_str());

            if (temp1 > temp2)
            {
                tempTrain = train[i];
                tempType = type[i];
                tempTicketPrice = ticketPrice[i];
                tempDepartureTime = departureTime[i];
                tempCompartments = compartments[i];
                tempTicketsDiscount = ticketsDiscount[i];
                tempLuggageTax = luggageTax[i];
                tempStarting = starting[i];
                tempEnding = ending[i];

                train[i] = train[j];
                type[i] = type[j];
                ticketPrice[i] = ticketPrice[j];
                departureTime[i] = departureTime[j];
                compartments[i] = compartments[j];
                ticketsDiscount[i] = ticketsDiscount[j];
                luggageTax[i] = luggageTax[j];
                starting[i] = starting[j];
                ending[i] = ending[j];

                train[j] = tempTrain;
                type[j] = tempType;
                ticketPrice[j] = tempTicketPrice;
                departureTime[j] = tempDepartureTime;
                compartments[j] = tempCompartments;
                ticketsDiscount[j] = tempTicketsDiscount;
                luggageTax[j] = tempLuggageTax;
                starting[j] = tempStarting;
                ending[j] = tempEnding;
            }
        }
    }
}
void displayUserTravelingHistory()
{
    fstream file;
    string word;
    file.open("travellingHistory.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        if (word != "")
        {
            cout << parsing(word, 1) << " travelled from " << parsing(word, 3) << " to " << parsing(word, 4)
                 << " using " << parsing(word, 2) << "(train name). He purchased " << parsing(word, 5)
                 << " tickets and his total bill was " << parsing(word, 8) << endl;
        }
    }
    file.close();
    cout << "Enter any key to continue...";
    getch();
}
void displaySpecificUserTravelingHistory(string userName)
{
    fstream file;
    string word;
    file.open("travellingHistory.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        if (word != "" && parsing(word, 1) == userName)
        {
            cout << "You travelled from " << parsing(word, 3) << " to " << parsing(word, 4)
                 << " using " << parsing(word, 2) << "(train name). You purchased " << parsing(word, 5)
                 << " tickets and your total bill was " << parsing(word, 8) << endl;
        }
    }
    file.close();
    cout << "Enter any key to continue...";
    getch();
}
string parsing(string word, int location)
{
    int commaCount = 1;
    string item = "";
    for (int x = 0; x < word.length(); x++)
    {
        if (word[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == location)
        {
            item = item + word[x];
        }
    }
    return item;
}
bool isReceivedAmountCorrect(string receivedAmount)
{
    bool flag = false;
    int leng = receivedAmount.length();
    int COUNT = 0;

    for (int i = 0; i < leng; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (receivedAmount[i] == j)
                COUNT++;
        }
    }

    if (leng == COUNT)
        flag = true;

    return flag;
}
void storeUserTravelingHistory(string checkName, string trainCheck, string startingInput, string destinationInput, string ticketsDiscountCheck, string compartmentsCheck, string luggageTaxCheck, int totalBill)
{
    fstream file;
    file.open("travellingHistory.txt", ios::app);

    file << checkName << "," << trainCheck << "," << startingInput << "," << destinationInput << "," << ticketsDiscountCheck
         << "," << compartmentsCheck << "," << luggageTaxCheck << "," << totalBill << endl;

    file.close();
}
void panel()
{
    system("cls");
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