#include <iostream>
#include <cassert>
#include "romannumber.h"

int main()
{
    // Sensei's test
    RomanNumber r1 = RomanNumber("MDIL");  //1549
    RomanNumber r2 ("MCDXLIX");            //1449

    assert(r1 != 5);
    assert(r1 + 1 == 1550);

    assert(r1 + r2 >= r2);
    assert(r2 + r2 == r2 * 2);
    assert(r1 > r2);
    assert(r1 != r2);
    //

    RomanNumber rn1(5);
    cout << "rn1: " << rn1 << endl;

    RomanNumber rn2(rn1 + rn1);
    cout << "rn2: " << rn2 << endl;

    assert (rn1 != rn2);

    cout << "rn2 + rn1 = " << rn2 + rn1 << endl;

    string x = "X";
    assert(rn2 == "X");
    assert(rn2 == x);
    assert(x == rn2);

    assert(static_cast<int>(rn2) == 10);
    assert(rn2 != rn1);
    assert(rn1 != "VII");

    assert(rn1 < rn2   &&
           rn1 <= rn2  &&
           rn2 >= rn1  &&
           rn2 > rn1   &&
           rn1 > "I"   &&
           "II" < rn2  &&
           rn1 < "XXX");

    assert(++rn1 == "VI");
    assert(rn1++ == "VI");
    assert(7 == rn1);

    assert((49 / rn1) == rn1);

    //    RomanNumber rn3;
    //    cout << "Enter rn3: ";
    //    cin >> rn3;
    //    cout << "rn3 = " << rn3 << endl;

    string roman_five = "V";
    size_t arabic_five = 5;
    RomanNumber roman_eleven = RomanNumber("XI");

    roman_five += roman_eleven;
    assert(roman_five == 16);

    roman_five -= roman_eleven;
    assert((roman_five + roman_eleven) == (arabic_five + roman_eleven));

    assert((arabic_five + roman_eleven) == 16);

    roman_eleven++;
    roman_eleven /= 3;

    assert((arabic_five /= roman_eleven) == arabic_five);

    roman_eleven--;

    arabic_five += (--roman_eleven);
    arabic_five /= 3;

    assert((arabic_five * roman_eleven) == 2);

    cout << "<ASSERTIONS PASSED>" << endl;

    return 0;
}
