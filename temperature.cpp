// File: temperature.cxx
// This program prints a table to convert numbers from one unit to another.
// The program illustrases some implementation techniques.

#include <iostream>    // Provides cout
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
using namespace std;   // Allows all standard library items to be used

double celsius_to_fahrenheit(double c)
// Precondition: c is a Celsius temperature no less than absolute
// zero (-273.16).
// Postcondition: The return value is the temperature c converted to Fahrenheit
// degrees.
{
    const double MINIMUM_CELSIUS = -273.16; // Absolute zero in Celsius degrees
    assert(c >= MINIMUM_CELSIUS);
    return (9.0 / 5.0) * c + 32;
}

void setup_cout_fractions(int fraction_digits)
// Precondition: fraction_digits is not negative.
// Postcondition: All double or float numbers printed to cout will now be
// rounded to the specified digits on the right of the decimal.
{
    assert(fraction_digits > 0);
    cout.precision(fraction_digits);
    cout.setf(ios::fixed, ios::floatfield);
    if (fraction_digits == 0)
        cout.unsetf(ios::showpoint);
    else
        cout.setf(ios::showpoint);
}

int main()
{
    const char   HEADING1[] = "   Celsius"; // Heading for table's 1st column
    const char   HEADING2[] = "Fahrenheit"; // Heading for table's 2nd column
    const char   LABEL1 = 'C'; // Label for numbers in 1st column
    const char   LABEL2 = 'F'; // Label for numbers in 2nd column
    const double TABLE_BEGIN = -50.0; // The table's first Celsius temp.
    const double TABLE_END = 50.0; // The table's final Celsius temp.
    const double TABLE_STEP = 10.0; // Increment between temperatures
    const int    WIDTH = 9; // Number chars in output numbers
    const int    DIGITS = 1; // Number digits right of decimal pt

    double value1;  // A value from the table's first column
    double value2;  // A value from the table's second column

    // Set up the output for fractions and print the table headings.
    setup_cout_fractions(DIGITS);
    cout << "CONVERSIONS from " << TABLE_BEGIN << " to " << TABLE_END << endl;
    cout << HEADING1 << "  " << HEADING2 << endl;

    // Each iteration of the loop prints one line of the table.
    for (value1 = TABLE_BEGIN; value1 <= TABLE_END; value1 += TABLE_STEP)
    {
        value2 = celsius_to_fahrenheit(value1);
        cout << setw(WIDTH) << value1 << LABEL1 << "  ";
        cout << setw(WIDTH) << value2 << LABEL2 << endl;
    }

    return EXIT_SUCCESS;
}
