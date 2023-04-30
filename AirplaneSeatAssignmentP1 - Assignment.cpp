// Mark Bulmer - C++ Project 1 - Airplane Seat Assignment
//
//***       ***         ***         ***
//      I realize that this is a poor attempt and does not function as intended. 
//      I thought that I had a better understanding of the material and did not allow myself
//      enough time to ask questions and receive the feedback which I sorely needed. 
//***       ***         ***         ***

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cctype>

using namespace std;


///
/// Global variables
///
string seat_01A, seat_01B, seat_01C, seat_01D;
string seat_02A, seat_02B, seat_02C, seat_02D;
string seat_03A, seat_03B, seat_03C, seat_03D;
string seat_04A, seat_04B, seat_04C, seat_04D;


///
/// Global constants
///
const string EMPTY_SEAT = "<EMPTY>";
const int SEAT_STR_ROW_NUM_DIGITS = 2;
const int SEAT_STR_LETTER_NUM_CHARS = 1;
const int SEAT_STR_ROW_START_POS = 0;
const int SEAT_STR_LETTER_START_POS = 2;
const int SEAT_ROWS_START = 1;
const int SEAT_ROWS_END = 4;
const int NUM_SEAT_ROWS = SEAT_ROWS_END - SEAT_ROWS_START + 1;
const int NUM_SEAT_LETTERS = 4;
const char SEAT_TYPE_INDEX[NUM_SEAT_LETTERS]{ 'A', 'B', 'C', 'D' };

///
/// Used in displayFullMenu, displayShortMenu
///
const string CLEAR_SCREEN_MESSAGE = ". Clear Screen and Refresh Full Menu";
const string EXIT_PROGRAM_MESSAGE = ". Exit Program";
const string ENTER_CHOICE_MESSAGE = "Enter your choice: ";

///
/// Used in displayHeader, and as part of constant DASH_LENGTH
///
const string HEADER_TEXT = "Airline Seating Assignment Program";


///
/// Used in displayHeader, displayFullMenu
///
const size_t DASH_LENGTH = HEADER_TEXT.length();


///
/// Used in displayFullMenu
///
const string CREATE_MANIFEST_MESSAGE = ". Create Manifest";
const string CREATE_SEATING_CHART_MESSAGE = ". Create Seating Chart";
const string FIND_PASSENGER_MESSAGE = ". Find Passenger (by name)";
const string SHOW_OCCUPANT_MESSAGE = ". Show Seat Occupant (by seat)";
const string ASSIGN_SEAT_MESSAGE = ". Assign Seat (by name)";
const string REMOVE_PASSENGER_MESSAGE = ". Remove Passenger (by name)";


///
/// Used in main, displayFullMenu
///
const char MENU_CREATE_MANIFEST = '1';
const char MENU_CREATE_SEATING_CHART = '2';
const char MENU_FIND_PASSENGER = '3';
const char MENU_SHOW_OCCUPANT = '4';
const char MENU_ASSIGN_SEAT = '5';
const char MENU_REMOVE_PASSENGER = '6';


///
/// Used in main, displayFullMenu, displayShortMenu, getMenuChoice
///
const char MENU_EXIT_PROGRAM = '7';
const char MENU_CLEAR_SCREEN = 'C';


///
/// Used in createManifest
///
const int DISPLAY_WIDTH_CM = 15;
const int NUM_DISPLAY_COLS_CM = 2;
const string PASSENGER_HEADING = "Passenger";
const string SEAT_HEADING = "Seat";


///
/// Used in createSeatingChart
///
const int DISPLAY_WIDTH_CSC = 10;
const int NUM_DISPLAY_COLS_CSC = 5;
const string ROW_HEADING = "row ";
const string ROW_HEADING_SUFFIX = ":";


///
/// Used in dashLine 
///
const char REPEAT_CHAR = '-';


///
/// Used in isSeatValid
/// 
const string ERROR_MESSAGE_PREFIX = "***";
const string INVALID_SEAT_LENGTH_MESSAGE = "Invalid seat length";
const string INVALID_SEAT_ROW_NON_NUMERIC_MESSAGE = "Invalid seat row -- non-numeric";
const string INVALID_SEAT_ROW_OUT_OF_RANGE_LOWER_MESSAGE = "Invalid seat row -- out of range - less than ";
const string INVALID_SEAT_ROW_OUT_OF_RANGE_UPPER_MESSAGE = "Invalid seat row -- out of range - greater than ";
const string INVALID_SEAT_LETTER_NON_ALPHABETIC = "Invalid seat letter -- non-alphabetic";
const string INVALID_SEAT_LETTER_OUT_OF_RANGE = "Invalid seat letter - must be ";


///
/// Used in isPassengerNameValid
///
const string INVALID_PASSENGER_NAME_MESSAGE = "Invalid passenger name";


///
/// Function Prototypes
///
void displayHeader();
void displayShortMenu();
void displayFullMenu();
char getMenuChoice();

void createManifest();
void createSeatingChart();
string findPassenger(string passengerName);
string showOccupant(string seat);
bool assignSeat(string seat, string passengerName);
bool releaseSeat(string seat);

void dashLine(size_t lineLength);
string upperCase(string string2upper);
bool isSeatValid(string seat);
bool isPassengerNameValid(string passengerName);

int main()
{

    ///
    /// Constants used in main 
    ///
    const string CREATE_MANIFEST_LOG_TEXT = "Create Manifest";
    const string CREATE_SEATING_LOG_TEXT = "Create Seating Chart";
    const string FIND_PASSENGER_LOG_TEXT = "Find Passenger";
    const string SHOW_OCCUPANT_LOG_TEXT = "Show Seat Occupant";
    const string ASSIGN_SEAT_LOG_TEXT = "Assign Seat";
    const string REMOVE_PASSENGER_LOG_TEXT = "Remove Passenger";

    const string MANIFEST_MESSAGE = "Manifest was created. File name: ";
    const string SEATING_CHART_MESSAGE = "Seating chart was created. File name: ";
    const string FOUND_PASSENGER_MESSAGE = " is assigned seat ";
    const string NOT_FOUND_PASSENGER_MESSAGE = " does not have an assigned seat";
    const string FOUND_OCCUPANT_MESSAGE = " is occupied by ";
    const string NOT_FOUND_OCCUPANT_MESSAGE = " is empty";
    const string ASSIGNED_SEAT_TO_PASSENGER_MESSAGE = FOUND_PASSENGER_MESSAGE;
    const string NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE = " cannot be assigned seat ";
    const string REMOVED_PASSENGER_MESSAGE = " was removed from seat ";
    const string NOT_REMOVED_PASSENGER_MESSAGE = " was not removed from seat ";
    const string INVALID_CHOICE_ERROR_MESSAGE = "Please enter a valid choice: ";

    const char* WINDOWS_CLEAR_SCREEN = "cls";

    const string SEAT_PROMPT = "Please enter the seat number (format = NNA e.g. 02C): ";
    const string FIND_PASSENGER_PROMPT = "Please enter the passenger's name: ";

    bool exitProgram = false;

    char choice;

    string seat;

    string passengerName;

    seat_01A = EMPTY_SEAT;
    seat_01B = "Avery";
    seat_01C = "Daniel";
    seat_01D = "Luke";

    seat_02A = "Leo";
    seat_02B = "Abigail";
    seat_02C = EMPTY_SEAT;
    seat_02D = "Isabella";

    seat_03A = "Lillian";
    seat_03B = EMPTY_SEAT;
    seat_03C = "Isaac";
    seat_03D = "Ella";

    seat_04A = "Evelyn";
    seat_04B = "Aurora";
    seat_04C = "Noah";
    seat_04D = EMPTY_SEAT;

    displayFullMenu();

    do {
        choice = toupper(getMenuChoice());

        switch (choice) {

        case MENU_CREATE_MANIFEST:
            createManifest();

            displayShortMenu();

            break;

        case MENU_CREATE_SEATING_CHART:
            createSeatingChart();

            displayShortMenu();

            break;

        case MENU_FIND_PASSENGER:
            cout << FIND_PASSENGER_PROMPT;
            getline(cin, passengerName);

            seat = findPassenger(passengerName);

            cout << endl;

            if (seat != EMPTY_SEAT) {
                dashLine((passengerName + FOUND_PASSENGER_MESSAGE + seat).length());
                cout << passengerName << FOUND_PASSENGER_MESSAGE << seat << endl;
                dashLine((passengerName + FOUND_PASSENGER_MESSAGE + seat).length());
            }
            else {
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
                cout << passengerName << NOT_FOUND_PASSENGER_MESSAGE << endl;
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_SHOW_OCCUPANT:
            do {
                cout << SEAT_PROMPT;
                getline(cin, seat);
            } while (!isSeatValid(seat));

            passengerName = showOccupant(seat);

            cout << endl;

            if (passengerName != EMPTY_SEAT) {
                dashLine((upperCase(seat) + FOUND_OCCUPANT_MESSAGE + passengerName).length());
                cout << upperCase(seat) << FOUND_OCCUPANT_MESSAGE << passengerName << endl;
                dashLine((upperCase(seat) + FOUND_OCCUPANT_MESSAGE + passengerName).length());
            }
            else {
                dashLine((upperCase(seat) + NOT_FOUND_OCCUPANT_MESSAGE).length());
                cout << upperCase(seat) << NOT_FOUND_OCCUPANT_MESSAGE << endl;
                dashLine((upperCase(seat) + NOT_FOUND_OCCUPANT_MESSAGE).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_ASSIGN_SEAT:
            do {
                cout << SEAT_PROMPT;
                getline(cin, seat);
            } while (!isSeatValid(seat));

            do {
                cout << FIND_PASSENGER_PROMPT;
                getline(cin, passengerName);
            } while (!isPassengerNameValid(passengerName));

            cout << endl;

            if (assignSeat(seat, passengerName)) {
                dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                cout << passengerName << ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                dashLine((passengerName + ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
            }
            else {
                dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
                cout << passengerName << NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE << upperCase(seat) << endl;
                dashLine((passengerName + NOT_ASSIGNED_SEAT_TO_PASSENGER_MESSAGE + upperCase(seat)).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_REMOVE_PASSENGER:
            cout << FIND_PASSENGER_PROMPT;
            getline(cin, passengerName);

            seat = findPassenger(passengerName);

            if (seat != EMPTY_SEAT) {
                if (releaseSeat(seat)) {
                    dashLine((passengerName + REMOVED_PASSENGER_MESSAGE + seat).length());
                    cout << passengerName << REMOVED_PASSENGER_MESSAGE << seat << endl;
                    dashLine((passengerName + REMOVED_PASSENGER_MESSAGE + seat).length());
                }
                else {
                    dashLine((passengerName + NOT_REMOVED_PASSENGER_MESSAGE).length());
                    cout << passengerName << NOT_REMOVED_PASSENGER_MESSAGE << seat << endl;
                    dashLine((passengerName + NOT_REMOVED_PASSENGER_MESSAGE).length());
                }
            }
            else {
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
                cout << passengerName << NOT_FOUND_PASSENGER_MESSAGE << endl;
                dashLine((passengerName + NOT_FOUND_PASSENGER_MESSAGE).length());
            }

            cout << endl;

            displayShortMenu();

            break;

        case MENU_EXIT_PROGRAM:
            exitProgram = true;
            break;

        case MENU_CLEAR_SCREEN:
            system(WINDOWS_CLEAR_SCREEN);
            displayFullMenu();
            break;

        default:
            cout << INVALID_CHOICE_ERROR_MESSAGE;

        }
    } while (!exitProgram);
}


void displayHeader()
{
    cout << endl;

    dashLine(DASH_LENGTH);

    cout << HEADER_TEXT << endl;

    dashLine(DASH_LENGTH);
}


void displayShortMenu()
{
    displayHeader();

    cout << MENU_CLEAR_SCREEN << CLEAR_SCREEN_MESSAGE << endl;
    cout << MENU_EXIT_PROGRAM << EXIT_PROGRAM_MESSAGE << endl;
    cout << endl;
    cout << ENTER_CHOICE_MESSAGE;
}


void displayFullMenu()
{
    displayHeader();

    cout << MENU_CREATE_MANIFEST << CREATE_MANIFEST_MESSAGE << endl;
    cout << MENU_CREATE_SEATING_CHART << CREATE_SEATING_CHART_MESSAGE << endl;
    cout << MENU_FIND_PASSENGER << FIND_PASSENGER_MESSAGE << endl;
    cout << MENU_SHOW_OCCUPANT << SHOW_OCCUPANT_MESSAGE << endl;
    cout << MENU_ASSIGN_SEAT << ASSIGN_SEAT_MESSAGE << endl;
    cout << MENU_REMOVE_PASSENGER << REMOVE_PASSENGER_MESSAGE << endl;
    dashLine(DASH_LENGTH);
    cout << MENU_EXIT_PROGRAM << EXIT_PROGRAM_MESSAGE << endl;
    dashLine(DASH_LENGTH);
    cout << endl;
    cout << MENU_CLEAR_SCREEN << CLEAR_SCREEN_MESSAGE << endl;
    cout << endl;
    cout << ENTER_CHOICE_MESSAGE;
}


char getMenuChoice()
{
    char choice;

    cin >> choice;
    cin.ignore();

    cout << endl << endl;

    return choice;
}


void createManifest()
{
    cout << left;
    cout << setw(DISPLAY_WIDTH_CM) << PASSENGER_HEADING << setw(DISPLAY_WIDTH_CM) << SEAT_HEADING << endl;

    dashLine(DISPLAY_WIDTH_CM * NUM_DISPLAY_COLS_CM);

    cout << endl;

    if (seat_01A != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_01A << setw(DISPLAY_WIDTH_CM) << "01A" << endl;

    if (seat_01B != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_01B << setw(DISPLAY_WIDTH_CM) << "01B" << endl;

    if (seat_01C != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_01C << setw(DISPLAY_WIDTH_CM) << "01C" << endl;

    if (seat_01D != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_01D << setw(DISPLAY_WIDTH_CM) << "01D" << endl;


    if (seat_02A != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_02A << setw(DISPLAY_WIDTH_CM) << "02A" << endl;

    if (seat_02B != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_02B << setw(DISPLAY_WIDTH_CM) << "02B" << endl;

    if (seat_02C != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_02C << setw(DISPLAY_WIDTH_CM) << "02C" << endl;

    if (seat_02D != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_02D << setw(DISPLAY_WIDTH_CM) << "02D" << endl;


    if (seat_03A != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_03A << setw(DISPLAY_WIDTH_CM) << "03A" << endl;

    if (seat_03B != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_03B << setw(DISPLAY_WIDTH_CM) << "03B" << endl;

    if (seat_03C != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_03C << setw(DISPLAY_WIDTH_CM) << "03C" << endl;

    if (seat_03D != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_03D << setw(DISPLAY_WIDTH_CM) << "03D" << endl;


    if (seat_04A != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_04A << setw(DISPLAY_WIDTH_CM) << "04A" << endl;

    if (seat_04B != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_04B << setw(DISPLAY_WIDTH_CM) << "04B" << endl;

    if (seat_04C != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_04C << setw(DISPLAY_WIDTH_CM) << "04C" << endl;

    if (seat_04D != EMPTY_SEAT)
        cout << setw(DISPLAY_WIDTH_CM) << seat_04D << setw(DISPLAY_WIDTH_CM) << "04D" << endl;

    dashLine(DISPLAY_WIDTH_CM * NUM_DISPLAY_COLS_CM);
    cout << endl;
}


void createSeatingChart()
{
    cout << left;
    cout << setw(DISPLAY_WIDTH_CSC) << " ";
    cout << setw(DISPLAY_WIDTH_CSC) << "A";
    cout << setw(DISPLAY_WIDTH_CSC) << "B";
    cout << setw(DISPLAY_WIDTH_CSC) << "C";
    cout << setw(DISPLAY_WIDTH_CSC) << "D";

    cout << endl;

    dashLine(DISPLAY_WIDTH_CSC * NUM_DISPLAY_COLS_CSC);

    cout << endl;


    cout << setw(DISPLAY_WIDTH_CSC) << ROW_HEADING + "1" + ROW_HEADING_SUFFIX;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_01A;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_01B;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_01C;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_01D;
    cout << endl;

    cout << setw(DISPLAY_WIDTH_CSC) << ROW_HEADING + "2" + ROW_HEADING_SUFFIX;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_02A;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_02B;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_02C;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_02D;
    cout << endl;

    cout << setw(DISPLAY_WIDTH_CSC) << ROW_HEADING + "3" + ROW_HEADING_SUFFIX;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_03A;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_03B;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_03C;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_03D;
    cout << endl;

    cout << setw(DISPLAY_WIDTH_CSC) << ROW_HEADING + "4" + ROW_HEADING_SUFFIX;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_04A;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_04B;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_04C;
    cout << setw(DISPLAY_WIDTH_CSC) << seat_04D;
    cout << endl;

    dashLine(DISPLAY_WIDTH_CSC * NUM_DISPLAY_COLS_CSC);

    cout << endl;
}

//***
//*** Begin creating the function which will determine the
//*** seat occupied by a specific person defined by the user. 
//***
string findPassenger(string passengerName)
{   //***
    //*** Create a variable "seat" which is assigned the constant value of "EMPTY_SEAT".
    //***
    string seat = EMPTY_SEAT;
    //***
    //*** Make variable "passengerName" upper case. 
    //***
    //*** I wasn't positive whether to use the "upperCase" string
    //*** established earlier or "toupper", but I couldn't
    //*** get "toupper" to compile correctly. When I run it with toupper, 
    //*** it says there is no matching function for the call, even though I see it 
    //*** used elsewhere in this program. I don't think "passengerName" is responding 
    //*** accurately and I think that this might be the issue.
    //***  
    //*** The examples I found through google to remedy this issue were multiple lines of code,
    //*** which made me feel like I was on the wrong track. I failed to find
    //*** an elegant solution to this problem. 
    //***
    passengerName = upperCase(passengerName);
    //***
    //*** The program checks the passenger name against each individual seat
    //*** to see if that name has been assigned to each particular seat.
    //*** If there is a match, then the corresponding string is assigned. 
    //*** Otherwise, it cycles through the options until it reaches the
    //*** appropriate value. 
    //***
    if (passengerName == seat_01A)
        cout << upperCase(seat) << "01A" << endl;

    else if (passengerName == seat_01B)
        cout << upperCase(seat) << "01B" << endl;

    else if (passengerName == seat_01C)
        cout << upperCase(seat) << "01C" << endl;

    else if (passengerName == seat_01D)
        cout << upperCase(seat) << "01D" << endl;


    else if (passengerName == seat_02A)
        cout << upperCase(seat) << "02A" << endl;

    else if (passengerName == seat_02B)
        cout << upperCase(seat) << "02B" << endl;

    else if (passengerName == seat_02C)
        cout << upperCase(seat) << "02C" << endl;

    else if (passengerName == seat_02D)
        cout << upperCase(seat) << "02D" << endl;


    else if (passengerName == seat_03A)
        cout << upperCase(seat) << "03A" << endl;

    else if (passengerName == seat_03B)
        cout << upperCase(seat) << "03B" << endl;

    else if (passengerName == seat_03C)
        cout << upperCase(seat) << "03C" << endl;

    else if (passengerName == seat_03D)
        cout << upperCase(seat) << "03D" << endl;


    else if (passengerName == seat_04A)
        cout << upperCase(seat) << "04A" << endl;

    else if (passengerName == seat_04B)
        cout << upperCase(seat) << "04B" << endl;

    else if (passengerName == seat_04C)
        cout << upperCase(seat) << "04C" << endl;

    else if (passengerName == seat_04D)
        cout << upperCase(seat) << "04D" << endl;
    //***
    //*** Return the value of the seat that was determined in the previous if-else-if statement.
    //***
    return seat;
}


//***
//*** This creates the function which will display the name of
//*** the occupant of a specific seat prompted by the user. 
//*** 
//*** This is the only function I was somewhat succesful in getting
//*** to process, though it still doesn't display correctly. I tried to implement
//*** the constant strings such as "FOUND_OCCUPANT_MESSAGE" but was not succesful
//*** receiving the error that it was "not declared in this scope."
//***
//*** I was trying to troubleshoot and didn't know if I needed to re-state
//*** this information again somewhere in the function but couldn't really wrap
//*** my head around the information I found on stackoverflow.   
//***
string showOccupant(string seat)
{   //***
    //*** Creates a variable "passengerName" which is assigned the constant value "EMPTY_SEAT".
    //***
    string passengerName = EMPTY_SEAT;
    //***
    //*** Make the "seat" variable uppercase.
    //*** 
    seat = upperCase(seat);
    //***
    //*** The program cycles through each seat until it finds
    //*** the appropriate "seat" value which was input by the user.
    //*** It then compares this to its corresponding string, and the
    //*** value "passengerName" is pulled from this string which will
    //*** tell the user which individual occupies the chosen seat. 
    //***
   if (upperCase(seat) == "01A")
        cout << passengerName <<  seat_01A  << endl;

    else if (upperCase(seat) == "01B")
        cout << passengerName << seat_01B  << endl;

    else if (upperCase(seat) == "01C")
        cout << passengerName << seat_01C << endl;

    else if (upperCase(seat) == "01D")
        cout << passengerName << seat_01D << endl;


    else if (upperCase(seat) == "02A")
        cout << passengerName << seat_02A << endl;

    else if (upperCase(seat) == "02B")
        cout << passengerName << seat_02B << endl;

    else if (upperCase(seat) == "02C")
        cout << passengerName << seat_02C << endl;

    else if (upperCase(seat) == "02D")
        cout << passengerName << seat_02D << endl;


    else if (upperCase(seat) == "03A")
        cout << passengerName << seat_03A << endl;

    else if (upperCase(seat) == "03B")
        cout << passengerName << seat_03B << endl;

    else if (upperCase(seat) == "03C")
        cout << passengerName << seat_03C << endl;

    else if (upperCase(seat) == "03D")
        cout << passengerName << seat_03D << endl;


    else if (upperCase(seat) == "04A")
        cout << passengerName << seat_04A << endl;

    else if (upperCase(seat) == "04B")
        cout << passengerName << seat_04B << endl;

    else if (upperCase(seat) == "04C")
        cout << passengerName << seat_04C << endl;

    else if (upperCase(seat) == "04D")
        cout << passengerName << seat_04D << endl;


    //***
    //*** The name of the passenger is returned now that "passengerName"
    //*** has been assigned the value of the appropriate "seat" string.
    //***
    return passengerName;
}


//***
//*** Create the function to assign a seat to an individual
//*** chosen by the user.
//***
bool assignSeat(string seat, string passengerName)
{   //***
    //*** Creates the variable "assignSeatOK" which 
    //*** starts out as "false".
    //*** 
    bool assignSeatOK = 0;
    //***
    //*** Makes variable "seat" uppercase.
    //***
    seat = upperCase(seat);
    //***
    //*** The user enters a seat number and a passenger's name.
    //*** The program cycles through each seat to check if they are empty. If the
    //*** seat the user entered is indeed empty, then the program registers 
    //*** that it is okay to assign the seat, and assigns the string to the chosen
    //*** name. If the seat is taken, a message is displayed stating this.
    //***
    if (upperCase(seat) == "01A")
    {
        if (seat_01A == EMPTY_SEAT)
        {
            cout << seat_01A << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "01B")
    {
        if (seat_01B == EMPTY_SEAT)
        {
            cout << seat_01B << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "01C")
    {
        if (seat_01C == EMPTY_SEAT)
        {
            cout << seat_01C << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "01D")
    {
        if (seat_01D == EMPTY_SEAT)
        {
            cout << seat_01D << passengerName << endl;
            assignSeatOK = 1;
        }
    }



    else if (upperCase(seat) == "02A")
    {
        if (seat_02A == EMPTY_SEAT)
        {
            cout << seat_02A << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "02B")
    {
        if (seat_02B == EMPTY_SEAT)
        {
            cout << seat_02B << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "02C")
    {
        if (seat_02C == EMPTY_SEAT)
        {
            cout << seat_02C << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "01D")
    {
        if (seat_02D == EMPTY_SEAT)
        {
            cout << seat_02D << passengerName << endl;
            assignSeatOK = 1;
        }
    }



    else if (upperCase(seat) == "03A")
    {
        if (seat_03A == EMPTY_SEAT)
        {
            cout << seat_03A << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "03B")
    {
        if (seat_03B == EMPTY_SEAT)
        {
            cout << seat_03B << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "03C")
    {
        if (seat_03C == EMPTY_SEAT)
        {
            cout << seat_03C << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "03D")
    {
        if (seat_03D == EMPTY_SEAT)
        {
            cout << seat_03D << passengerName << endl;
            assignSeatOK = 1;
        }
    }


    else if (upperCase(seat) == "04A")
    {
        if (seat_04A == EMPTY_SEAT)
        {
            cout << seat_04A << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "04B")
    {
        if (seat_04B == EMPTY_SEAT)
        {
            cout << seat_04B << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "04C")
    {
        if (seat_04C == EMPTY_SEAT)
        {
            cout << seat_04C << passengerName << endl;
            assignSeatOK = 1;
        }
    }

    else if (upperCase(seat) == "04D")
    {
        if (seat_04D == EMPTY_SEAT)
        {
            cout << seat_04D << passengerName << endl;
            assignSeatOK = 1;
        }
    }
    //***
    //*** Return the variable which identifies if the seat has been properly assigned.
    //***
    return assignSeatOK;
}


//***
//*** This is the function which will remove a user from a specific seat.
//***
bool releaseSeat(string seat)
{   // It is always allowed for the user to clear the seat values.
    bool releaseSeatOK = true;

    //***
    //*** Make variable "seat" uppercase.
    //***
    seat = upperCase(seat);
    //***
    //*** The program cycles through each seat and then identifies 
    //*** the seat value chosen by the user,
    //*** assigning the value "EMPTY_SEAT" to the string which
    //*** corresponds with the chosen seat. This removes any previous
    //*** values given to that seat.  
    //***
    if (upperCase(seat) == "01A")
        cout << seat_01A << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "01B")
        cout << seat_01B << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "01C")
        cout << seat_01C << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "01D")
        cout << seat_01D << EMPTY_SEAT << endl;


    else if (upperCase(seat) == "02A")
        cout << seat_02A << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "02B")
        cout << seat_02B << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "02C")
        cout << seat_02C << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "02D")
        cout << seat_02D << EMPTY_SEAT << endl;


    else if (upperCase(seat) == "03A")
        cout << seat_03A << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "03B")
        cout << seat_03B << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "03C")
        cout << seat_03C << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "03D")
        cout << seat_03D << EMPTY_SEAT << endl;


    else if (upperCase(seat) == "04A")
        cout << seat_04A << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "04B")
        cout << seat_04B << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "04C")
        cout << seat_04C << EMPTY_SEAT << endl;

    else if (upperCase(seat) == "04D")
        cout << seat_04D << EMPTY_SEAT << endl;
    //***
    //*** Return the variable that states that the seat value can be removed.
    //***
    return releaseSeatOK;
}


void dashLine(size_t lineLength)
{
    for (size_t x = 0; x < lineLength; x++)
        cout << REPEAT_CHAR;

    cout << endl;
}


string upperCase(string string2Upper)
{
    string stringUpperCased;

    for (size_t x = 0; x < string2Upper.length(); x++) {
        stringUpperCased += toupper(string2Upper[x]);
    }

    return stringUpperCased;
}


bool isSeatValid(string seat)
{
    bool validSeat = true;

    if (seat.length() != (SEAT_STR_ROW_NUM_DIGITS + SEAT_STR_LETTER_NUM_CHARS)) {
        cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_LENGTH_MESSAGE << ERROR_MESSAGE_PREFIX << endl << endl;
        validSeat = false;
    }
    else {
        for (int x = 0; x < SEAT_STR_ROW_NUM_DIGITS; x++) {
            if (!isdigit(seat[x]))
                validSeat = false;
        }
        if (!validSeat) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_ROW_NON_NUMERIC_MESSAGE << ERROR_MESSAGE_PREFIX << endl << endl;
        }
    }

    string seatTypeIndexStr = string(SEAT_TYPE_INDEX);

    if (validSeat) {

        if (stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS - SEAT_STR_ROW_START_POS)) < SEAT_ROWS_START) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_ROW_OUT_OF_RANGE_LOWER_MESSAGE << SEAT_ROWS_START << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else if (stoi(seat.substr(SEAT_STR_ROW_START_POS, SEAT_STR_ROW_NUM_DIGITS - SEAT_STR_ROW_START_POS)) > NUM_SEAT_ROWS) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_ROW_OUT_OF_RANGE_UPPER_MESSAGE << NUM_SEAT_ROWS << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else if (!isalpha(seat[SEAT_STR_LETTER_START_POS])) {
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_LETTER_NON_ALPHABETIC << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else if (seatTypeIndexStr.find(toupper(seat[SEAT_STR_LETTER_START_POS])) == string::npos) {

            // Zero and one based indexing.
            cout << endl << ERROR_MESSAGE_PREFIX << INVALID_SEAT_LETTER_OUT_OF_RANGE << SEAT_TYPE_INDEX[0] << "-" << SEAT_TYPE_INDEX[NUM_SEAT_LETTERS - 1] \
                << ERROR_MESSAGE_PREFIX << endl << endl;
            validSeat = false;
        }
        else
            seat[SEAT_STR_LETTER_START_POS] = toupper(seat[SEAT_STR_LETTER_START_POS]);
    }
    
    return validSeat;
}

bool isPassengerNameValid(string passengerName) {

    bool validPassengerName = true;

    if (passengerName.find_first_not_of(" ") == passengerName.npos) {
        cout << endl << INVALID_PASSENGER_NAME_MESSAGE << endl << endl;
        validPassengerName = false;
    }

    return validPassengerName;
}