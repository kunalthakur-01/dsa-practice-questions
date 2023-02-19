#include<iostream>
using namespace std;

/*class complex
{
    int a, b;
public:

    complex(int x, int y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout<<"the value of a="<<a<<endl;
        cout<<"the value of b="<<b;
    }
};

int main()
{
    int x, y;
    cout<<"enter the value of x=";
    cin>>x;

    cout<<"enter the value of y=";
    cin>>y;

    complex c1(2,3);
    c1.display();
    complex c2 = complex(x,y);
    c2.display();

    return 0;
}*/

class base
{
private:
    int pvt;

protected:
    int ptd;

public:
    base()
    {
        pvt = 0;
        ptd = 0;
    }

    void mul(int a, int b)
    {
        int result = a * b * ptd;
        cout<<"mul of two variable is:"<<result;
    }

};

class derived : public base
{
public:
    void display()
    {
        mul(3,3);
    }
};

int main()
{
    base b;
    b.mul(4,4);
    derived d;
    d.display();
    d.mul(6,6);

    return 0;
}
