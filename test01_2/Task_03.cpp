#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class ASTBinaryNode
{
    T m_left;
    T m_right;
public:
    ASTBinaryNode(const T& left, const T& right)
        : m_left(left)
        , m_right(right)
    {}

    const T& getLeft() const
    {
        return m_left;
    }

    const T& getRight() const
    {
        return m_right;
    }

    virtual T evaluate() const = 0;

    virtual ~ASTBinaryNode(){}
};

template<typename T>
class ASTBinaryNodePlus : public ASTBinaryNode<T>
{
public:
    ASTBinaryNodePlus(const T& left, const T& right)
        : ASTBinaryNode<T>(left, right)
    {}

    T evaluate() const override
    {
        return this->getLeft() + this->getRight();
    }
};

template<typename T>
class ASTBinaryNodeMinus : public ASTBinaryNode<T>
{
public:
    ASTBinaryNodeMinus(const T& left, const T& right)
        : ASTBinaryNode<T>(left, right)
    {}

    T evaluate() const override
    {
        return this->getLeft() - this->getRight();
    }
};

template<typename T>
class ASTBinaryNodeDivide : public ASTBinaryNode<T>
{
public:
    ASTBinaryNodeDivide(const T& left, const T& right)
        : ASTBinaryNode<T>(left, right)
    {}

    T evaluate() const override
    {
        return this->getLeft() / this->getRight();
    }
};

template<typename T>
class ASTBinaryNodeMultiply : public ASTBinaryNode<T>
{
public:
    ASTBinaryNodeMultiply(const T& left, const T& right)
        : ASTBinaryNode<T>(left, right)
    {}

    T evaluate() const override
    {
        return this->getLeft() * this->getRight();
    }
};

int main()
{
    int a = 18;
    int b = -91;

    ASTBinaryNode<float>* operations[] =
    {
        new ASTBinaryNodePlus<float>(a, b),
        new ASTBinaryNodeMinus<float>(a, b),
        new ASTBinaryNodeDivide<float>(a, b),
        new ASTBinaryNodeMultiply<float>(a, b)
    };

    assert(operations[0]->evaluate() == -73);
    assert(operations[1]->evaluate() == 109);
    assert(operations[2]->evaluate() < 1);
    assert(operations[3]->evaluate() == -1638);
	
	cout << "<ASSERTIONS PASSED>" << endl;

    cout << a << " + " << b << " = " << operations[0]->evaluate() << endl;
    cout << a << " - " << b << " = " << operations[1]->evaluate() << endl;
    cout << a << " / " << b << " = " << operations[2]->evaluate() << endl;
    cout << a << " * " << b << " = " << operations[3]->evaluate() << endl;

    delete operations[0];
    delete operations[1];
    delete operations[2];
    delete operations[3];

    return 0;
}
