#include <iostream> //for cin and cout
#include <cstring>  //for strcpy, strlen and strcat

using namespace std;

// array of strings for numbers from 0 to 9
const char* const ones[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

// array of strings for numbers from 10 to 19
const char* const teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

// array of strings for numbers from 20 to 90
const char* const tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

// array of strings for numbers from 100 to 900
const char* const thousands[] = { "", "Thousand", "Million", "Billion" };


// This function converts a number to words up to billions.
void convert_num_to_words(char* words, int number)
{
    // If the number is 0, then print "Zero"
    if (number == 0)
    {
        strcpy(words, "Zero");
        return;
    }

    char temp[20];  // temporary string to hold the words for each 3-digit number
    int index = 0;  // index for thousands[] array

    do  // loop until number is not equal to 0
    {
        int n = number % 1000;  // extract the last 3 digits

        if (n != 0) // if the last 3 digits are not 0, then print the number in words
        {
            strcpy(temp, "");

            // Code path for numbers less than 10
            if (n < 10)
            {
                strcat(temp, ones[n]);
            }

            // Code path for numbers less than 20
            else if (n < 20)
            {
                strcat(temp, teens[n - 10]);
            }

            // Code path for numbers less than 100
            else if (n < 100)
            {
                strcat(temp, tens[n / 10]);

                // If the last digit is not 0, then print the number in words
                if ((n % 10) != 0)
                {
                    strcat(temp, " ");
                    strcat(temp, ones[n % 10]);
                }
            }

            else 
            {
                strcat(temp, ones[n / 100]);
                strcat(temp, " Hundred");

                if ((n % 100) != 0)
                {
                    strcat(temp, " and ");

                    if ((n % 100) < 10)
                    {
                        strcat(temp, ones[n % 100]);
                    }

                    else if ((n % 100) < 20)
                    {
                        strcat(temp, teens[(n % 100) - 10]);
                    }

                    else
                    {
                        strcat(temp, tens[(n % 100) / 10]);
                        if ((n % 10) != 0)
                        {
                            strcat(temp, " ");
                            strcat(temp, ones[n % 10]);
                        }
                    }
                }
            }

            strcat(temp, " ");  // add space after each 3-digit number
            strcat(temp, thousands[index]); // add thousands[] string after each 3-digit number
            strcat(temp, " ");
            strcat(words, temp);
        }

        // remove the last 3 digits from the number
        number /= 1000;

        index++;    // increment index

    } while (number > 0);   // loop until number is not equal to 0
}

int main()
{
    int number;
    cout << "Enter an integer number: ";
    cin >> number;

    char words[100];
    convert_num_to_words(words, number);

    cout << "In words: " << words << endl;

    return 0;
}
