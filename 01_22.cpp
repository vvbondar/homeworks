#include <iostream>
#include <cstring>
#include <memory>
#include <cassert>

class String
{
    std::shared_ptr<char> m_ptr;

    void Swap(String& other)
    {
        std::swap(other.m_ptr, (*this).m_ptr);
    }
public:
    String()
        :m_ptr(nullptr)
    {}

    String(const char* other)
        :m_ptr(new char[strlen(other) + 1], std::default_delete<char[]>())
        //std::array's second template argument cannot be initialized by a non-constant value
        //so I was not able to use it here
    {
        strcpy(m_ptr.get(), other);
    }

    String(const String& other)
        :m_ptr(other.m_ptr)
    {}

    String& operator =(const char* rhs)
    {
        String(rhs).Swap(*this);
        return *this;
    }

    String& operator =(const String& rhs)
    {
        if(this != &rhs)
        {
            String(rhs).Swap(*this);
        }
        return *this;
    }

    bool operator ==(const char* rhs)
    {
        return !strcmp(m_ptr.get(), rhs);
    }

    bool operator ==(const String& rhs)
    {
        return *this == rhs.m_ptr.get();
    }

    bool operator !=(const String& rhs)
    {
        return !(*this == rhs);
    }

    bool operator !=(const char* rhs)
    {
        return !(*this == rhs);
    }

    String& operator +=(const char* rhs)
    {
        char* tmp = new char[strlen(m_ptr.get()) + strlen(rhs) + 1];
        strcpy(tmp, m_ptr.get());
        strcat(tmp, rhs);

        String(tmp).Swap(*this);
        return *this;
    }

    String& operator +=(const String& rhs)
    {
        *this += rhs.m_ptr.get();
        return *this;
    }

    String operator +(const char* rhs)
    {
        String out(*this);
        return out += rhs;
    }

    String operator +(const String& rhs)
    {
        String out(*this);
        return out += rhs;
    }

    size_t GetCount()
    {
        return m_ptr.use_count();
    }

    const char& operator [](size_t index) const
    {
        return m_ptr.get()[index];
    }

    void SetElem(size_t index, char c)
    {
        String tmp(*this);
        //does not work w/o get()
        tmp.m_ptr.get()[index] = c;
        Swap(tmp);
    }

    friend std::ostream& operator <<(std::ostream& os, const String& rhs);
    friend std::istream& operator >>(std::istream& is, const String& rhs);
};

std::ostream& operator <<(std::ostream& os, const String& rhs)
{
    os << rhs.m_ptr;
    return os;
}

std::istream& operator >>(std::istream& is, String& rhs)
{
    char* temp_str = new char[80];
    is >> temp_str;

    rhs = String(temp_str);
    delete[] temp_str;

    return is;
}

int main()
{
    String s1;

    assert(s1.GetCount() == 0);

    s1 = "a";
    std::cout << s1 << std::endl;

    assert(s1.GetCount() == 1);

    s1 += "bc";
    std::cout << s1 << std::endl;
    assert(s1.GetCount() == 1);

    String s2(s1);
    String s3(s2);

    assert(s1.GetCount() == 3);

    s1 += s3;

    assert(s1.GetCount() == 1);

    std::cout << s1 << ' ' << s2 << std::endl;

    assert(s1 != s2);

    //s1[0] = 'd';

    s1 = "hello!";

    assert(s1 == "hello!");

    s2 = s1;
    s3 = s2;

    assert(s3 == s1);

    std::cout << s1[0] << std::endl;
    std::cout << s1 << ' ' << s1.GetCount() << std::endl;

    s1.SetElem(0, 'A');
    std::cout << s1 << ' ' << s1.GetCount() << std::endl;

    std::cout << "<ASSERTIONS PASSED>" << std::endl;

    return 0;
}
