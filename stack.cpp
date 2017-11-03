#include <iostream>
using namespace std;

#define ARRAYSIZE 10

class stack
{
    private:
    int Array[ARRAYSIZE];
    int count;
    public:
    stack(int INIT = 0)
    {
        for(int i = 0; i < ARRAYSIZE; i++)
        {
            Array[i] = INIT;
        }
        count = INIT;
    }
    void push(int data);
    void pop(void);
    void reverse(void);
    bool isEmpty(void);
    bool isFulss(void);
    void travel(void);
};

void stack::push(int data)
{
    if(data <= 0)
    {
        
    }
    else if(isFulss())
    {
        cout<<"该栈已满"<<endl;
    }
    else
    {
        for(int i = ARRAYSIZE - 1 - count; i >= 0; i--)
        {
            if(Array[i] != 0)
            continue;
            else
            {
                Array[i] = data;
                count++;
                break;
            }
        }
    }
}

void stack::pop(void)
{
    if(isEmpty())
    {
        cout<<"该栈已空"<<endl;
    }
    else
    {
        Array[ARRAYSIZE - count] = 0;
        count--;
    }
}

void stack::reverse(void)
{
    int i = (count - 1) / 2;
    int j = 0;
    for(; i > 0; i--, j++)
    {
        int temp;
        temp = Array[ARRAYSIZE - count + j];
        Array[ARRAYSIZE - count + j] = Array[ARRAYSIZE - 1 - j];
        Array[ARRAYSIZE - 1 - j] = temp;
    }
}

void stack::travel(void)
{
    cout<<"栈的元素个数: "<<count<<endl;
    cout<<"栈的遍历: ";
    for(int i = 0; i < 10; i++)
    {
        cout<<Array[i]<<'\t';
    }
    cout<<endl;
}

bool stack::isEmpty(void)
{
    if(Array[ARRAYSIZE - 1] == 0)
    return true;
    else
    return false;
}

bool stack::isFulss(void)
{
    if(Array[0] != 0)
    return true;
    else
    return false;
}

int main()
{
    stack a(0);
    a.push(10);
    a.push(20);
    a.push(50);
    a.push(0);
    a.reverse();
    a.travel();
    a.pop();
    a.travel();
    a.push(30);
    a.travel();
}