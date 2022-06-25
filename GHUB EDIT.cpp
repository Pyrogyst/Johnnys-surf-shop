// Nicholas Jessop, ITCS 2530 
// Small = 2.0 , $175.00
// Medium = 3.0 , $190.00
// Large = 4.0 , $200.00
// XXXS = $5.00

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

//Named Constants
#define XXXSmallSurfboard 5.00;
#define SmallSurfboard 175.00;
#define MediumSurfboard 190.00;
#define LargeSurfboard 200.00;

//---------------------------------- REQUIRED FUNCTIONS -----------------------------------------
//a function to show the user how to use the program
void ShowUsage();

//a function to sell surfboards
void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);

//function to show the number of surfboards of each size sold
void DisplayPurchase(const int iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);

//a function to show the total amount of money made
void DisplayTotal(const int iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);

//----------------------------------- END REQUIRED FUNCTIONS -------------------------------------

int main()

{
    //Basic Variables
    char choice = 0;
    char size = 0;
    int quantity = 0;
    int QuantityXXXSmall = 0;
    int QuantitySmall = 0;
    int QuantityMedium = 0;
    int QuantityLarge = 0;

    //HEADER
    cout << "************************************************************" << endl;
    cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << "************************************************************" << endl;
    cout << endl << endl;

    //MENU DISPLAY (ShowUsage Function shortcut :P)
    ShowUsage();

    //INPUT
    cout << "\nPlease enter selection: ";
    cin >> choice;

    //WHILE + IFS
    while (tolower(choice) != 'q')

    {
        //----------------------------------CHOICE S (reprint menu)
        if (tolower(choice) == 's')

        {
            ShowUsage();
        }

        //----------------------------------CHOICE P (Purchase)
        else if (tolower(choice) == 'p')

        {
            MakePurchase(QuantityXXXSmall, QuantitySmall, QuantityMedium, QuantityLarge);
            cout << endl;
        }

        //----------------------------------CHOICE C (Current Purchases)
        else if (tolower(choice) == 'c')

        {

            if (QuantityXXXSmall == 0)

            {
                cout << "No purchase made yet." << endl;
            }

            else

            {
                DisplayPurchase(QuantityXXXSmall, QuantitySmall, QuantityMedium, QuantityLarge);

            }

        }

        //-----------------------------------CHOICE T (Total Amount)
        else if (tolower(choice) == 't')

        {

            if (QuantityXXXSmall == 0)

            {
                cout << "No purchase made yet." << endl;
            }

            else

            {
                DisplayTotal(QuantityXXXSmall, QuantitySmall, QuantityMedium, QuantityLarge);
            }

        }

        //Final Else, Invalid
        else

        {
            cout << "Invalid choice!" << endl;
        }

        //Enter Selection Again (restart, sort of)
        cout << "\nPlease enter selection: ";
        cin >> choice;
    }
    cout << "Thank you" << endl;
}

// ------------------------------------------ FUNCTION DEFINES -------------------------------------------------------

//ShowUsage() (Menu Display)

void ShowUsage()

{
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchase press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
}

//MakePurchase() (Purchase)

void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)

{
    int quantity = 0;
    char size = '\0';

    //The Print
    cout << "Please enter the quantity and type ";
    cout << "(XXXS ONLY IN STOCK!) of ";
    cout << "surfboard you would like to purchase:";
    cin >> quantity >> size;

    //IF STATEMENTS 
    if (tolower(size) == 's')

    {
        iTotalSmall = iTotalSmall + quantity;
    }

    else if (tolower(size) == 'm')

    {
        iTotalMedium = iTotalMedium + quantity;
    }

    else if (tolower(size) == 'l')

    {
        iTotalLarge = iTotalLarge + quantity;
    }

    else if (tolower(size) == 'xxxs')

    {
        iTotalXXXSmall = iTotalXXXSmall + quantity;
    }

}

//DisplayPurchase (What You Bought)
void DisplayPurchase(const int iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)

{
    //IF STATEMENTS
    if (iTotalSmall > 0)

    {
        cout << "The total number of small ";
        cout << "surfboards is " << iTotalSmall;
        cout << endl;
    }

    if (iTotalMedium > 0)

    {
        cout << "The total number of medium ";
        cout << "surfboards is " << iTotalMedium;
        cout << endl;
    }

    if (iTotalLarge > 0)

    {
        cout << "The total number of large ";
        cout << "surfboards is " << iTotalLarge;
        cout << endl;
    }

    if (iTotalXXXSmall > 0)

    {
        cout << "The tota number of XXXS ";
        cout << "surfboards is " << iTotalXXXSmall;
        cout << endl;
    }
}

//DisplayTotal ($$ Amount)
void DisplayTotal(const int iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)

{

    double sSurfAmount, mSurfAmount, lSurfAmount, xxxsSurfAmount, tAmountDue;
    sSurfAmount = mSurfAmount = lSurfAmount = xxxsSurfAmount = tAmountDue = 0;

    //Set Decimal Amount :))
    cout << fixed << setprecision(2);

    //IF STATEMENTS
    if (iTotalSmall > 0)

    {

        sSurfAmount = iTotalSmall * SmallSurfboard;

        cout << "The total number of small surfboards is " << iTotalSmall;
        cout << " at a total of $" << sSurfAmount << endl;

        //MATH
        tAmountDue = tAmountDue + sSurfAmount;

    }

    if (iTotalMedium > 0)

    {

        mSurfAmount = iTotalMedium * MediumSurfboard;

        cout << "The total number of medium surfboards is " << iTotalMedium;
        cout << " at a total of $" << mSurfAmount << endl;

        //MATH
        tAmountDue = tAmountDue + mSurfAmount;

    }

    if (iTotalLarge > 0)

    {

        lSurfAmount = iTotalLarge * LargeSurfboard;

        cout << "The total number of large surfboards is " << iTotalLarge;
        cout << " at a total of $" << lSurfAmount << endl;

        //MATH
        tAmountDue = tAmountDue + lSurfAmount;

        if (iTotalXXXSmall > 0)

        {

            xxxsSurfAmount = iTotalXXXSmall * XXXSmallSurfboard;

            cout << "The total number of XXXS surfboards is " << iTotalLarge;
            cout << " at a total of $" << lSurfAmount << endl;

            //MATH
            tAmountDue = tAmountDue + xxxsSurfAmount;

        }
        // ----------------------------------------- END FUNCTION DEFINES -------------------------------------------------

        //Final Amount Display
        cout << "Amount due: $" << tAmountDue << endl;

    }

}
