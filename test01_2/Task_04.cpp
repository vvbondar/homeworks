#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

//digged some stuff
class StringMaker
{
    stringstream stream;
public:
    template<typename T>
    StringMaker& operator <<(const T& obj)
    {
        stream << obj;
        return *this;
    }

    operator string() const
    {
        return stream.str();
    }
};

template<typename T>
class BinaryTree
{
    T m_data;
    BinaryTree* m_ptr_left;
    BinaryTree* m_ptr_right;
public:
    BinaryTree(const T& value)
        : m_data(value)
        , m_ptr_left(nullptr)
        , m_ptr_right(nullptr)
    {}

    void AddLeft(BinaryTree<T>* left)
    {
        m_ptr_left = left;
    }

    void AddRight(BinaryTree<T>* right)
    {
        m_ptr_right = right;
    }

    string Serialize()
    {
        StringMaker mkstr;
        mkstr << m_data;

        if(m_ptr_left || m_ptr_right)
        {
            mkstr << '(';

            if(m_ptr_left)
            {
                mkstr << m_ptr_left->Serialize();
            }
            else
            {
                mkstr << ' ';
            }

            mkstr << ',';

            if(m_ptr_right)
            {
                mkstr << ' ' << m_ptr_right->Serialize();
            }
            else
            {
                mkstr << ' ';
            }

            mkstr << ')';
        }

        return (string)mkstr;
    }

    ostream& operator <<(ostream& os)
    {
        os << Serialize();
        return os;
    }
};

int main()
{
    BinaryTree<string> root("+");
    BinaryTree<string> left1("1");
    BinaryTree<string> right2("2");

    root.AddLeft(&left1);
    root.AddRight(&right2);

    assert(root.Serialize() == "+(1, 2)");

    cout << root.Serialize() << endl;

    BinaryTree<int> a(1);      //               a            //
    BinaryTree<int> b(2);      //             /  \           //
    BinaryTree<int> c(3);      //            b    c          //
    BinaryTree<int> d(4);      //           /                //
    BinaryTree<int> e(5);      //          d                 //
    BinaryTree<int> f(6);      //         / \                //
                               //        e   f               //
    a.AddLeft (&b);
    a.AddRight(&c);
    b.AddLeft (&d);
    d.AddLeft (&e);
    d.AddRight(&f);
    //c.AddLeft(&root);
    //c.AddRight(&root);
    //f.AddRight(&c);

    assert(a.Serialize() == "1(2(4(5, 6), ), 3)");
    cout << a.Serialize() << endl;

    cout << "<ASSERTIONS PASSED>" << endl;

    return 0;
}
