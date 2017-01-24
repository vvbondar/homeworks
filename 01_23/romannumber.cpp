#include "romannumber.h"

// private section

string RomanNumber::ComposeRomanRank(size_t digit, string left, string middle, string right) const
{
    switch (digit)
    {
        case 1:
            return left;
        case 2:
            return left + left;
        case 3:
            return left + left + left;
        case 4:
            return left + middle;
        case 5:
            return middle;
        case 6:
            return middle + left;
        case 7:
            return middle + left + left;
        case 8:
            return middle + left + left + left;
        case 9:
            return left + right;
        default:
            return "";
    }
}

string RomanNumber::ArabicToRoman(size_t value) const
{
    if(value == 0)
    {
        return "nullus";
    }

    if(value >= 4000)
    {
        throw;
    }

    string res[] =
    {
        ComposeRomanRank( value / 1000,        "M", "M", "M"),
        ComposeRomanRank((value % 1000) / 100, "C", "D", "M"),
        ComposeRomanRank((value % 100) / 10,   "X", "L", "C"),
        ComposeRomanRank( value % 10,          "I", "V", "X")
    };

    return res[0] + res[1] + res[2] + res[3];
}

size_t RomanNumber::RomanToArabic(const string& value) const
{
    if (value.length() == 1)
    {
        return RomanArabicMatches.find(value[0])->second;
    }

    vector<size_t> arabic_arr;

    for (size_t i = 0; i < value.length(); ++i)
    {
        arabic_arr.push_back(RomanArabicMatches.find(value[i])->second);
    }

    size_t total = 0;

    for (size_t i = 0; i < value.length(); ++i)
    {
        if (arabic_arr[i] >= arabic_arr[i + 1] || i == value.length() - 1)
        {
            total += arabic_arr[i];
        }
        else
        {
            total += (arabic_arr[i + 1] - arabic_arr[i]);
            ++i;
        }
    }

    return total;
}

// public section

RomanNumber::RomanNumber()
{
    m_r_number = "nullus";
}

RomanNumber::RomanNumber(const string &str)
{
    //Double conversion to avoid passing wrong roman numbers.
    //For example, "IIIIVVVIIIII" will be converted to "XXII".
    size_t temp_a_number = RomanToArabic(str);
    m_r_number = ArabicToRoman(temp_a_number);
}

RomanNumber::RomanNumber(const size_t value)
{
    if(value >= 4000)
    {
        throw;
    }

    m_r_number = ArabicToRoman(value);
}

RomanNumber::RomanNumber(const RomanNumber &other)
{
    if(this != &other)
    {
        this->m_r_number = other.m_r_number;
    }
}

// --------OPERATORS OVERLOADING----------
// ========COMPARISON OPERATORS===========

bool RomanNumber::operator ==(const RomanNumber& rhs) const
{
    return ToArabic() == rhs.ToArabic();
}

bool RomanNumber::operator ==(const string& rhs) const
{
    return ToArabic() == RomanToArabic(rhs);
}

bool RomanNumber::operator ==(const size_t rhs) const
{
    return ToArabic() == rhs;
}

bool RomanNumber::operator !=(const RomanNumber& rhs) const
{
    return !(*this == rhs);
}

bool RomanNumber::operator !=(const string& rhs) const
{
    return !(*this == rhs);
}

bool RomanNumber::operator !=(const size_t rhs) const
{
    return !(*this == rhs);
}

bool RomanNumber::operator <(const RomanNumber& rhs) const
{
    return ToArabic() < rhs.ToArabic();
}

bool RomanNumber::operator <(const string& rhs) const
{
    return ToArabic() < RomanToArabic(rhs);
}

bool RomanNumber::operator <(const size_t rhs) const
{
    return ToArabic() < rhs;
}

bool RomanNumber::operator >=(const RomanNumber& rhs) const
{
    return !(*this < rhs);
}

bool RomanNumber::operator >=(const string& rhs) const
{
    return !(*this < rhs);
}

bool RomanNumber::operator >=(const size_t rhs) const
{
    return !(*this < rhs);
}

bool RomanNumber::operator >(const RomanNumber& rhs) const
{
    return rhs < *this;
}

bool RomanNumber::operator >(const string& rhs) const
{
    return RomanToArabic(rhs) < ToArabic();
}

bool RomanNumber::operator >(const size_t rhs) const
{
    return rhs < ToArabic();
}

bool RomanNumber::operator <=(const RomanNumber& rhs) const
{
    return rhs >= *this;
}

bool RomanNumber::operator <=(const string& rhs) const
{
    return RomanToArabic(rhs) >= ToArabic();
}

bool RomanNumber::operator <=(const size_t rhs) const
{
    return rhs >= ToArabic();
}

// =======ARITHMETICAL OPERATORS==========

RomanNumber& RomanNumber::operator +=(const RomanNumber& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() + rhs.ToArabic());
    return *this;
}

RomanNumber& RomanNumber::operator +=(const string& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() + RomanToArabic(rhs));
    return *this;
}

RomanNumber& RomanNumber::operator +=(const size_t rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() + rhs);
    return *this;
}

RomanNumber RomanNumber::operator +(const RomanNumber& rhs) const
{
    RomanNumber out(*this);
    return out += rhs;
}

RomanNumber RomanNumber::operator +(const string& rhs) const
{
    RomanNumber out(*this);
    return out += rhs;
}

RomanNumber RomanNumber::operator +(const size_t rhs) const
{
    RomanNumber out(*this);
    return out += rhs;
}

RomanNumber& RomanNumber::operator -=(const RomanNumber& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() - rhs.ToArabic());
    return *this;
}

RomanNumber& RomanNumber::operator -=(const string& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() - RomanToArabic(rhs));
    return *this;
}

RomanNumber& RomanNumber::operator -=(const size_t rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() - rhs);
    return *this;
}

RomanNumber RomanNumber::operator -(const RomanNumber& rhs) const
{
    RomanNumber out(*this);
    return out -= rhs;
}

RomanNumber RomanNumber::operator -(const string& rhs) const
{
    RomanNumber out(*this);
    return out -= rhs;
}

RomanNumber RomanNumber::operator -(const size_t rhs) const
{
    RomanNumber out(*this);
    return out -= rhs;
}

RomanNumber& RomanNumber::operator *=(const RomanNumber& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() * rhs.ToArabic());
    return *this;
}

RomanNumber& RomanNumber::operator *=(const string& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() * RomanToArabic(rhs));
    return *this;
}

RomanNumber& RomanNumber::operator *=(const size_t rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() * rhs);
    return *this;
}

RomanNumber RomanNumber::operator *(const RomanNumber& rhs) const
{
    RomanNumber out(*this);
    return out *= rhs;
}

RomanNumber RomanNumber::operator *(const string& rhs) const
{
    RomanNumber out(*this);
    return out *= rhs;
}

RomanNumber RomanNumber::operator *(const size_t rhs) const
{
    RomanNumber out(*this);
    return out *= rhs;
}

RomanNumber& RomanNumber::operator /=(const RomanNumber& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() / rhs.ToArabic());
    return *this;
}

RomanNumber& RomanNumber::operator /=(const string& rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() / RomanToArabic(rhs));
    return *this;
}

RomanNumber& RomanNumber::operator /=(const size_t rhs)
{
    this->m_r_number = ArabicToRoman(ToArabic() / rhs);
    return *this;
}

RomanNumber RomanNumber::operator /(const RomanNumber& rhs) const
{
    RomanNumber out(*this);
    return out /= rhs;
}

RomanNumber RomanNumber::operator /(const string& rhs) const
{
    RomanNumber out(*this);
    return out /= rhs;
}

RomanNumber RomanNumber::operator /(const size_t rhs) const
{
    RomanNumber out(*this);
    return out /= rhs;
}

// assignment

RomanNumber& RomanNumber::operator=(const RomanNumber& rhs)
{
    if(this != &rhs)
    {
        m_r_number = rhs.m_r_number;
    }
    return *this;
}

RomanNumber& RomanNumber::operator=(const string& rhs)
{
    size_t temp_a_number = RomanToArabic(rhs);
    m_r_number = ArabicToRoman(temp_a_number);
    return *this;
}

RomanNumber& RomanNumber::operator=(const size_t rhs)
{
    m_r_number = ArabicToRoman(rhs);
    return *this;
}

RomanNumber& RomanNumber::operator ++()
{
    m_r_number = ArabicToRoman(ToArabic() + 1);
    return *this;
}

RomanNumber RomanNumber::operator ++(int)
{
    RomanNumber out(*this);
    operator ++();
    return out;
}

RomanNumber& RomanNumber::operator --()
{
    m_r_number = ArabicToRoman(ToArabic() - 1);
    return *this;
}

RomanNumber RomanNumber::operator --(int)
{
    RomanNumber out(*this);
    operator --();
    return out;
}

size_t RomanNumber::ToArabic() const
{
    return RomanToArabic(m_r_number);
}

RomanNumber::operator int() const
{
    return RomanToArabic(m_r_number);
}

RomanNumber::operator size_t() const
{
    return static_cast<size_t>(*this);
}

RomanNumber::operator string() const
{
    return m_r_number;
}

RomanNumber::~RomanNumber(){}

const map<char, size_t> RomanNumber::RomanArabicMatches
{
    { 'I' , 1    },
    { 'V' , 5    },
    { 'X' , 10   },
    { 'L' , 50   },
    { 'C' , 100  },
    { 'D' , 500  },
    { 'M' , 1000 }
};

// ===========NON-MEMBERS============

bool CanBeARomanNumber(const string& str)
{
    return RomanNumber(str) != "nullus";
}

bool CanBeARomanNumber(const size_t num)
{
    return (num > 0 && num < 4000);
}

// streams

ostream& operator <<(ostream& os, const RomanNumber& obj)
{
    os << obj.m_r_number;
    return os;
}

istream& operator >>(istream& is, RomanNumber& obj)
    {
        string temp_r_number;
        is >> temp_r_number;

        size_t temp_a_number = obj.RomanNumber::RomanToArabic(temp_r_number);
        obj.m_r_number = obj.RomanNumber::ArabicToRoman(temp_a_number);

        return is;
    }

// string compares to RomanNumber

bool operator ==(const string& lhs, const RomanNumber& rhs)
{
    return RomanNumber(lhs) == rhs;
}

bool operator !=(const string& lhs, const RomanNumber& rhs)
{
    return !(lhs == rhs);
}

bool operator <(const string& lhs, const RomanNumber& rhs)
{
    return RomanNumber(lhs) < rhs;
}

bool operator >(const string& lhs, const RomanNumber& rhs)
{
    return rhs < lhs;
}

bool operator >=(const string& lhs, const RomanNumber& rhs)
{
    return !(lhs < rhs);
}

bool operator <=(const string& lhs, const RomanNumber& rhs)
{
    return rhs >= lhs;
}

// size_t compares to RomanNumber

bool operator ==(const size_t lhs, const RomanNumber& rhs)
{
    return RomanNumber(lhs) == rhs;
}

bool operator !=(const size_t lhs, const RomanNumber& rhs)
{
    return !(lhs == rhs);
}

bool operator <(const size_t lhs, const RomanNumber& rhs)
{
    return RomanNumber(lhs) < rhs;
}

bool operator >(const size_t lhs, const RomanNumber& rhs)
{
    return rhs < lhs;
}

bool operator >=(const size_t lhs, const RomanNumber& rhs)
{
    return !(lhs < rhs);
}

bool operator <=(const size_t lhs, const RomanNumber& rhs)
{
    return rhs >= lhs;
}

// arithmeticals with strings

string& operator +=(string& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs += rhs;
        lhs = static_cast<string>(temp_lhs);

        return lhs;
    }
    else throw;
}

string operator +(const string& lhs, const RomanNumber& rhs)
{
    string out = lhs;
    return out += rhs;
}

string& operator -=(string& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs -= rhs;
        lhs = static_cast<string>(temp_lhs);

        return lhs;
    }
    else throw;
}

string operator -(const string& lhs, const RomanNumber& rhs)
{
    string out = lhs;
    return out -= rhs;
}

string& operator *=(string& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs *= rhs;
        lhs = static_cast<string>(temp_lhs);

        return lhs;
    }
    else throw;
}

string operator *(const string& lhs, const RomanNumber& rhs)
{
    string out = lhs;
    return out *= rhs;
}

string& operator /=(string& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs /= rhs;
        lhs = static_cast<string>(temp_lhs);

        return lhs;
    }
    else throw;
}

string operator /(const string& lhs, const RomanNumber& rhs)
{
    string out = lhs;
    return out /= rhs;
}

// arithmeticals with size_t

size_t& operator +=(size_t& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs += rhs;
        lhs = temp_lhs.ToArabic();

        return lhs;
    }
    else throw;
}

size_t operator +(const size_t& lhs, const RomanNumber& rhs)
{
    size_t out = lhs;
    return out += rhs;
}

size_t& operator -=(size_t& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs -= rhs;
        lhs = temp_lhs.ToArabic();

        return lhs;
    }
    else throw;
}

size_t operator -(const size_t& lhs, const RomanNumber& rhs)
{
    size_t out = lhs;
    return out -= rhs;
}

size_t& operator *=(size_t& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs *= rhs;
        lhs = temp_lhs.ToArabic();

        return lhs;
    }
    else throw;
}

size_t operator *(const size_t& lhs, const RomanNumber& rhs)
{
    size_t out = lhs;
    return out *= rhs;
}

size_t& operator /=(size_t& lhs, const RomanNumber& rhs)
{
    if(CanBeARomanNumber(lhs))
    {
        RomanNumber temp_lhs(lhs);
        temp_lhs /= rhs;
        lhs = temp_lhs.ToArabic();

        return lhs;
    }
    else throw;
}

size_t operator /(const size_t& lhs, const RomanNumber& rhs)
{
    size_t out = lhs;
    return out /= rhs;
}
