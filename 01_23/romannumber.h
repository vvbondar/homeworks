#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class RomanNumber
{
    string m_r_number;
    static const map<char, size_t> RomanArabicMatches;
    string ComposeRomanRank(size_t digit, string left, string middle, string right) const;
    string ArabicToRoman(size_t value) const;
    size_t RomanToArabic(const string& value) const;
public:
    RomanNumber();
    RomanNumber(const string& str);
    RomanNumber(const size_t value);
    RomanNumber(const RomanNumber& other);

    // comparison operators

    bool operator ==(const RomanNumber& rhs) const;
    bool operator ==(const string& rhs) const;
    bool operator ==(const size_t rhs) const;

    bool operator !=(const RomanNumber& rhs) const;
    bool operator !=(const string& rhs) const;
    bool operator !=(const size_t rhs) const;

    bool operator <(const RomanNumber& rhs) const;
    bool operator <(const string& rhs) const;
    bool operator <(const size_t rhs) const;

    bool operator >=(const RomanNumber& rhs) const;
    bool operator >=(const string& rhs) const;
    bool operator >=(const size_t rhs) const;

    bool operator >(const RomanNumber& rhs) const;
    bool operator >(const string& rhs) const;
    bool operator >(const size_t rhs) const;

    bool operator <=(const RomanNumber& rhs) const;
    bool operator <=(const string& rhs) const;
    bool operator <=(const size_t rhs) const;

    // arithmetical operators

    RomanNumber& operator +=(const RomanNumber& rhs);
    RomanNumber& operator +=(const string& rhs);
    RomanNumber& operator +=(const size_t rhs);

    RomanNumber operator +(const RomanNumber& rhs) const;
    RomanNumber operator +(const string& rhs) const;
    RomanNumber operator +(const size_t rhs) const;

    RomanNumber& operator -=(const RomanNumber& rhs);
    RomanNumber& operator -=(const string& rhs);
    RomanNumber& operator -=(const size_t rhs);

    RomanNumber operator -(const RomanNumber& rhs) const;
    RomanNumber operator -(const string& rhs) const;
    RomanNumber operator -(const size_t rhs) const;

    RomanNumber& operator *=(const RomanNumber& rhs);
    RomanNumber& operator *=(const string& rhs);
    RomanNumber& operator *=(const size_t rhs);

    RomanNumber operator *(const RomanNumber& rhs) const;
    RomanNumber operator *(const string& rhs) const;
    RomanNumber operator *(const size_t rhs) const;

    RomanNumber& operator /=(const RomanNumber& rhs);
    RomanNumber& operator /=(const string& rhs);
    RomanNumber& operator /=(const size_t rhs);

    RomanNumber operator /(const RomanNumber& rhs) const;
    RomanNumber operator /(const string& rhs) const;
    RomanNumber operator /(const size_t rhs) const;

    RomanNumber& operator=(const RomanNumber& rhs);
    RomanNumber& operator=(const string& rhs);
    RomanNumber& operator=(const size_t rhs);

    RomanNumber& operator ++();
    RomanNumber operator ++(int);
    RomanNumber& operator --();
    RomanNumber operator --(int);

    size_t ToArabic() const;

    explicit operator int() const;
    explicit operator size_t() const;
    operator string() const;

    friend ostream& operator <<(ostream& os, const RomanNumber& obj);
    friend istream& operator >>(istream& is, RomanNumber& obj);

    ~RomanNumber();
};

bool CanBeARomanNumber(const string& str);
bool CanBeARomanNumber(const size_t num);

ostream& operator <<(ostream& os, const RomanNumber& obj);
istream& operator >>(istream& is, RomanNumber& obj);

bool operator ==(const string& lhs, const RomanNumber& rhs);
bool operator !=(const string& lhs, const RomanNumber& rhs);
bool operator <(const string& lhs, const RomanNumber& rhs);
bool operator >(const string& lhs, const RomanNumber& rhs);
bool operator >=(const string& lhs, const RomanNumber& rhs);
bool operator <=(const string& lhs, const RomanNumber& rhs);

bool operator ==(const size_t lhs, const RomanNumber& rhs);
bool operator !=(const size_t lhs, const RomanNumber& rhs);
bool operator <(const size_t lhs, const RomanNumber& rhs);
bool operator >(const size_t lhs, const RomanNumber& rhs);
bool operator >=(const size_t lhs, const RomanNumber& rhs);
bool operator <=(const size_t lhs, const RomanNumber& rhs);

string& operator +=(string& lhs, const RomanNumber& rhs);
string operator +(const string& lhs, const RomanNumber& rhs);
string& operator -=(string& lhs, const RomanNumber& rhs);
string operator -(const string& lhs, const RomanNumber& rhs);
string& operator *=(string& lhs, const RomanNumber& rhs);
string operator *(const string& lhs, const RomanNumber& rhs);
string& operator /=(string& lhs, const RomanNumber& rhs);
string operator /(const string& lhs, const RomanNumber& rhs);

size_t& operator +=(size_t& lhs, const RomanNumber& rhs);
size_t operator +(const size_t& lhs, const RomanNumber& rhs);
size_t& operator -=(size_t& lhs, const RomanNumber& rhs);
size_t operator -(const size_t& lhs, const RomanNumber& rhs);
size_t& operator *=(size_t& lhs, const RomanNumber& rhs);
size_t operator *(const size_t& lhs, const RomanNumber& rhs);
size_t& operator /=(size_t& lhs, const RomanNumber& rhs);
size_t operator /(const size_t& lhs, const RomanNumber& rhs);

#endif // ROMANNUMBER_H
