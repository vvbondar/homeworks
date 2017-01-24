#include <iostream>
#include <string>
#include <cassert>
#include <Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class Device
{
protected:
    string m_type;
    string m_name;
    bool m_turned_on;
public:
    Device()
        :m_type("unknown_device")
        ,m_name("N/A")
        ,m_turned_on(false)
    {}

    Device(const string& type, const string& name)
        :m_type(type)
        ,m_name(name)
        ,m_turned_on(false)
    {}

    void TurnOn(){ m_turned_on = true; }
    void TurnOff(){ m_turned_on = false; }

    bool IsWorking(){ return m_turned_on; }

    virtual void GetStatus() const = 0;

    virtual ~Device(){}
};

class Printer : virtual public Device
{
public:
    Printer(const string& name)
        :Device("Prntr", name)
    {}

    virtual void GetStatus() const override
    {
        cout << "[" << m_type << "-" << m_name << "]";
        if(m_turned_on)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "[turned ON]";
            SetConsoleTextAttribute(hConsole, 15);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "[turned OFF]";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << "[USB\\046D&PID_C52E&REV_2300&MI_00]" << endl;
    }

    void Print()
    {
        if(m_turned_on)
        {
            cout << m_name << " is printing..." << endl;
        }
        else
        {
            cout << m_name << " is not working. Please, check the device." << endl;
        }
    }
};

class Scanner : virtual public Device
{
public:
    Scanner()
        :Device("Scnnr", "N/A]")
    {}

    Scanner(const string& name)
        :Device("Scnnr", name)
    {}

    virtual void GetStatus() const override
    {
        cout << "[" << m_type << "-" << m_name << "]";
        if(this->m_turned_on)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "[turned ON]";
            SetConsoleTextAttribute(hConsole, 15);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "[turned OFF]";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << "[USB\\VEN_PNP&DEV_0303]" << endl;
    }

    void Scan()
    {
        if(m_turned_on)
        {
            cout << m_name << " is scanning..." << endl;
        }
        else
        {
            cout << m_name << " is not working. Please, check the device." << endl;
        }
    }
};

class MFU : public Printer, public Scanner
{
public:
    MFU(const string& name)
        :Device("MFU", name)
        ,Printer(name)
        ,Scanner(name)
    {}

    virtual void GetStatus() const override
    {
        cout << "[" << m_type << "-" << m_name << "]";
        if(this->m_turned_on)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "[turned ON]";
            SetConsoleTextAttribute(hConsole, 15);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "[turned OFF]";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << "[USB\\VID_0A5C&PID_21B4&REV_0481]" << endl;
    }

};

int main()
{
    Printer p("Lexmark P1337");
    Scanner s("Siemens SX-42");
    MFU m("POBEDA-45");

    p.TurnOn();
    m.TurnOn();

    p.GetStatus();
    s.GetStatus();
    m.GetStatus();

    assert(p.IsWorking() && !s.IsWorking() && m.IsWorking());

    p.Print();
    s.Scan();
    m.Print();
    m.Scan();

    cout << "================" << endl;

    s.TurnOn();

    p.GetStatus();
    s.GetStatus();
    m.GetStatus();

    p.Print();
    s.Scan();
    m.Print();
    m.Scan();

    cout << "================" << endl;

    p.TurnOff();
    s.TurnOff();
    m.TurnOff();

    p.GetStatus();
    s.GetStatus();
    m.GetStatus();

    p.Print();
    s.Scan();
    m.Print();
    m.Scan();

    assert(!p.IsWorking() && !s.IsWorking() && !m.IsWorking());

    cout << "================" << endl;
    cout << "<ASSERTIONS PASSED>" << endl;

    return 0;
}
