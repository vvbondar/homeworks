#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class HTMLElement
{
protected:
    size_t m_width;
    size_t m_height;
    bool m_hidden;
public:
    unsigned Width() const
    {
        return m_width;
    }

    unsigned Height() const
    {
        return m_height;
    }

    // m_hidden getter
    bool Hidden() const
    {
        return m_hidden;
    }

    // m_hidden setter
    void Hide(bool hidden)
    {
        m_hidden = hidden;
    }

    virtual string Render() = 0;
	
	// --TASK 3--
    virtual HTMLElement* Duplicate() = 0;

    virtual ~HTMLElement(){}
};

class HTMLButtonElement : public HTMLElement
{
    string m_title;
public:
    HTMLButtonElement(string title)
       : m_title(title)
    {
        m_height = 10;
        m_width = title.length() * 5 + 10;      // Title-depend button size
        m_hidden = false;
    }

    const string& Title() const
    {
        return m_title;
    }

    string Render() override
    {
        string res = "<button>" + Title() + "</button>";
        return res;
    }

    HTMLElement* Duplicate() override
    {
        return new HTMLButtonElement(*this);
    }
};

class HTMLImageElement : public HTMLElement
{
    string m_url;
public:
    HTMLImageElement(size_t height, size_t width, string url)
        : m_url(url)
    {
        m_height = height;
        m_width = width;
        m_hidden = false;
    }

    const string& Url() const
    {
        return m_url;
    }

    string Render() override
    {
        char temp_h[5];
        itoa(Height(), temp_h, 10);

        char temp_w[5];
        itoa(Width(), temp_w, 10);

        string res = "<img src=\"" + Url() + "\" height=\"" + temp_h + "\" width=\"" + temp_w + "\" >";
        return res;
    }

    HTMLElement* Duplicate() override
    {
        return new HTMLImageElement(*this);
    }
};

class HTMLTextAreaElement : public HTMLElement
{
    string m_content;
public:
    HTMLTextAreaElement(string content)
        : m_content(content)
    {
        m_height = 0;
        m_width = 0;
        m_hidden = false;
    }

    const string& Content() const
    {
        return m_content;
    }

    string Render() override
    {
        string res = "<textarea>\n    " + Content() + "\n</textarea>";
        return res;
    }

    HTMLElement* Duplicate() override
    {
        return new HTMLTextAreaElement(*this);
    }
};

// --TASK 4--
template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T&))
{
    for (size_t i = 0; i < length; ++i)
    {
        if (!p(arr[i]))
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T&))
{
    for (size_t i = 0; i < length; ++i)
    {
        if(p(arr[i]) == true)
        {
            return true;
        }
    }
    return false;
}

bool IsHidden(const HTMLElement& obj)
{
    return obj.Hidden();
}

// ----------

int main()
{
    size_t arr_size = 3;

    HTMLElement* elements[arr_size]
    {
        new HTMLButtonElement("PRETTY_BUTTON"),
        new HTMLImageElement(45, 60, "vk.com/foo.png"),
        new HTMLTextAreaElement("WHOOA, LE CONTENTO!")
    };

    HTMLElement* copied_elements[arr_size];

    for (int i = 0; i < 3; ++i)
    {
        copied_elements[i] = elements[i]->Duplicate();
        cout << copied_elements[i]->Render() << "\n(copied)" << endl << endl;

        // comparison check
        assert(copied_elements[i]->Height() == elements[i]->Height());
    }

    //Just doesn't work. Don't know why, my mind is blowed up, tried a lot of things

    //cout << "\nall of arr are hidden: " << all_of(*elements, 3, IsHidden) << endl;
    //cout << "any of arr is hidden:  " << any_of(*elements, 3, IsHidden) << endl;

    //elements[0]->Hide(true);
    //elements[1]->Hide(true);
    //elements[2]->Hide(true);

    //cout << "\nall of arr are hidden: " << all_of(*elements, 3, IsHidden) << endl;
    //cout << "any of arr is hidden:  " << any_of(*elements, 3, IsHidden) << endl;

    //elements[0]->Hide(false);
    //elements[1]->Hide(true);
    //elements[2]->Hide(true);

    //cout << "\nall of arr are hidden: " << all_of(*elements, 3, IsHidden) << endl;
    //cout << "any of arr is hidden:  " << any_of(*elements, 3, IsHidden) << endl;

    for (size_t i = 0; i < arr_size; ++i)
    {
        delete elements[i];
        delete copied_elements[i];
    }

    return 0;
}
