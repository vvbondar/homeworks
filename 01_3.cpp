#include <iostream>

using namespace std;

int RankOf(int number)
{
    int rank = 1;
    for(int i = 10; number/i; i*=10)
       rank++;
    return rank;
}

//Predicate
bool ContainsDigit(int number, int digit)
{
    if(digit < 0 && digit > 9)
        return false;
    for(int i = RankOf(number)-1; i >= 0 ; i--)
        if(((number%(int)pow(10, i+1))/(int)pow(10, i)) == digit)
                return true;
    return false;
}

//Returns an index of digit was found in number. If not found, returns -1
int FindDigit(int number, int digit)
{
    if(digit < 0 && digit > 9)
        return -1;

    for(int i = RankOf(number)-1; i >= 0 ; i--)
        if(((number%(int)pow(10, i+1))/(int)pow(10, i)) == digit)
                return RankOf(number)-(i+1);
    return -1;
}

int main()
{
   for(int i = 0; i <= 1000; i++)
        if(ContainsDigit(i, 1) && ContainsDigit(i, 7))
            cout << i << endl;

    return 0;
}
