#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HTMLElement
{
    size_t width;
    size_t height;
public:
    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;

    virtual string Render() = 0;
};

class HTMLButtonElement : public HTMLElement
{
    string m_title;
public:
    HTMLButtonElement(string title)
       : m_title(title)
    { }

    const string& Title() const
    {
        return m_title;
    }

    string Render()
    {
        string res = "<button>" + Title() + "</button>";
        return res;
    }
};

class HTMLImageElement : public HTMLElement
{
    size_t m_width;
    size_t m_height;
    string m_url;
public:
    HTMLImageElement(size_t width, size_t height, string url)
        : m_width(width)
        , m_height(height)
        , m_url(url)
    {}

    unsigned Height() const
    {
        return m_height;
    }

    unsigned Width() const
    {
        return m_width;
    }

    const string& Url() const
    {
        return m_url;
    }

    string Render()
    {
        char temp_h[3];
        itoa(Height(), temp_h, 10);

        char temp_w[3];
        itoa(Width(), temp_w, 10);

        string res = "<img src=" + Url() + " height=" + temp_h + " width=" + temp_w + ">";
        return res;
    }
};

class HTMLTextAreaElement : public HTMLElement
{
    string m_content;
public:
    HTMLTextAreaElement(string content)
        : m_content(content)
     { }

    const string& Content() const
    {
        return m_content;
    }

    string Render()
    {
        string res = "<textarea>\n    " + Content() + "\n</textarea>";
        return res;
    }
};

template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for (int i = 0; i < length; ++i)
    {
        if (!(p(arr[i])))
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem))
{
    for (int i = 0; i < length; ++i)
    {
        if(p(arr[i]))
        {
            return true;
        }
    }
}

int main(int argc, char *argv[])
{
    //vector<HTMLElement> elements(3);
    HTMLElement* elements[3] =
    {
        new HTMLButtonElement("PRETTY_BUTTON"),
        new HTMLImageElement(45, 60, "vk.com/foo.png"),
        new HTMLTextAreaElement("WHOOA, LE CONTENTO!")
    };

    for (int var = 0; var < 3; ++var)
    {
        cout << elements[var]->Render() << endl;
    }

//    HTMLElement* b = new HTMLButtonElement("PRETTY_BUTTON");
//    HTMLElement* i = new HTMLImageElement(45, 60, "vk.com/foo.png");
//    HTMLElement* a = new HTMLTextAreaElement("WHOOA, LE CONTENTO!");

//    cout << b->Render() << endl << endl;
//    cout << i->Render() << endl << endl;
//    cout << a->Render() << endl << endl;

    return 0;
}
