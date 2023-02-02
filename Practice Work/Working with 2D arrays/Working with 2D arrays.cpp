/*Keep track of drinks ordered at a drink stand
on different days of the week (Sunday, Monday, Tuesday, etc.) [rows]
drink types: Apple Cider, Hot Chocolate, Coffee, Tea, Lemonade [columns]


*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


const int NUM_DAYS = 7;   //Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
const int NUM_DRINKS = 5;  //Apple Cider, Hot Chocolate, Coffee, Tea, Lemonade


//function to print the day
void printDay (int day)
{
    switch (day)
    {
        case 0:
            cout << "SUN";
            break;
        case 1:
            cout << "MON";
            break;
        case 2:
            cout << "TUE";
            break;
        case 3:
            cout << "WED";
            break;
        case 4:
            cout << "THU";
            break;
        case 5:
            cout << "FRI";
            break;
        case 6:
            cout << "SAT";
            break;
    }
}



//function to print the array
void printArray (int drinkStand[NUM_DAYS] [NUM_DRINKS])
{
    cout << "Drink Stand Sales\n🍺🍷🍹🧉🍸🥤🍺🍷" << endl;
    cout << "     A  H  C  T  L" << endl;
    for (int row = 0; row < NUM_DAYS; row++)  //row = 0, 1, 2, 3, 4, 5, 6
    {
        printDay(row);
        for (int col = 0; col < NUM_DRINKS; col++)
        {
            cout << setw(3) << drinkStand[row][col];
        }
        cout << endl;
    }

    cout << endl;
}



int main ()
{
    int drinkStand[NUM_DAYS] [NUM_DRINKS] = {
                                           //A, H, C, T, L
                                            {0, 0, 0, 0, 0}, //Sunday = row 0
                                            {0, 0, 0, 0, 0}, //Monday = row 1
                                            {0, 0, 0, 0, 0}, //Tuesday = row 2
                                            {0, 0, 0, 0, 0}, //Wednesday = row 3
                                            {0, 0, 0, 0, 0}, //Thursday = row 4
                                            {0, 0, 0, 0, 0}, //Friday = row 5
                                            {0, 0, 0, 0, 0}  //Saturday = row 6
                                            };

    printArray(drinkStand);

    // //printing the array
    // cout << "Drink Stand Sales" << endl;
    // cout << "    A  H  C  T  L" << endl;
    // for (int row = 0; row < NUM_DAYS; row++)  //row = 0, 1, 2, 3, 4, 5, 6
    // {
    //     cout << row << " ";
    //     for (int col = 0; col < NUM_DRINKS; col++)
    //     {
    //         cout << setw(3) << drinkStand[row][col];
    //     }
    //     cout << endl;
    // }


    return 0;
}
