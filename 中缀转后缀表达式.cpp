#include <iostream>
#include <assert.h>
#include <string.h> //strlen
//const int stackIncrease = 25;
using namespace std;
//栈
struct Stack
{
    Stack(int sz = 25);
    ~Stack() { delete[]elements; }
    void Push(char& x);
    bool Pop(char& x);
    char getTop();
    bool isEmpty() { return (top == -1) ? 1 : 0; }
    //bool isFull()const { return (top == maxsize - 1 )? 1 : 0;}
    char* elements;
    int top;
    int maxsize;
    //void overflowProcess();

};

// 优先级
int priority(char c)
{
    switch (c)
    {
    case '*': case '/': return 2;
    case '+': case '-': return 1;
    default:return 0;
    }
    return 0;
}
// 构造函数
Stack::Stack(int sz)
{
    top = -1;
    maxsize = sz;
    elements = new char[maxsize];
    assert(elements != NULL);

}

// 溢出处理
/*
    void Stack::overflowProcess()
    {
        char* newArray = new char[maxsize + stackIncrease];
        if (newArray == NULL)
        {
            cerr << "存储分配失败！" << endl;
            exit(1);
        }
        for (int i = 0; i <= top; i++)
        {
            newArray[i] = elements[i];
        }
        maxsize = maxsize + stackIncrease;
        delete []elements;
        elements = newArray;

    }
*/

// 入栈
void Stack::Push(char& x)
{
    /*
    if (isFull() == 1)
    {
        overflowProcess;
    }
    */
    elements[++top] = x;
}
// 出栈
bool Stack::Pop(char& x)
{
    if (isEmpty() == 1)
    {
        return 0;
    }
    x = elements[top--];
    return 1;
}
// 获得栈顶元素
char Stack::getTop()
{

    return elements[top];
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
    {
        return false; // 否则返回false
    }


}
int main()
{
    Stack seqStack;
    char arr[25];   //存储中缀表达式
    char c = '0'; //储存从栈中取出的操作符
    cin.getline(arr, 25);
    int len, i = 0, num;
    len = (int)strlen(arr);
    while (i < len)
    {
        if (isdigit(arr[i]))
        {
            num = 0;
            do
            {
                num = num * 10 + (arr[i] - '0');
                i++;
            } while (isdigit(arr[i]));
            cout << num << " ";
        }
        else if (arr[i] == '(')
        {
            seqStack.Push(arr[i]);
            i++;
        }
        else if (arr[i] == ')')
        {
            while (seqStack.getTop() != '(')
            {
                seqStack.Pop(c);
                cout << c << ' ';
            }
            seqStack.Pop(c);
            i++;
        }
        else if (isOperator(arr[i]))
        {
            if (seqStack.isEmpty())
            {
                seqStack.Push(arr[i]);
                i++;
            }
            else
            {
                while (!seqStack.isEmpty())
                {
                    c = seqStack.getTop();
                    if (priority(arr[i]) > priority(c))
                    {
                        break;
                    }
                    else
                    {
                        cout << c << ' ';
                        seqStack.Pop(c);

                    }
                }seqStack.Push(arr[i]);
                i++;

            }
        }
        else
        {
            i++;
        }
    }
    while (!seqStack.isEmpty())
    {
        if (seqStack.top != 0)
        {
            cout << seqStack.getTop() << ' ';
            seqStack.Pop(c);
        }
        else
        {
            cout << seqStack.getTop();
            seqStack.Pop(c);
        }

    }

    return 0;
}