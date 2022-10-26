#include <iostream>
#include <assert.h>
#include <string.h> //strlen
#define maxSize 250
int nextt[maxSize];//next定义不明确可能和内部变量名冲突。so nextt。
//KMP...
using namespace std;
void getNext(int nextt[], string str)
{
    int j = 0;
    int k = -1; //j是主指针，k是用来回溯。
    int len = int(str.length());
    nextt[0] = -1;
    while (j < len)
    {
        if (k == -1 || str[j] == str[k])
        {
            j++;
            k++;
            nextt[j] = k;
        }
        else
        {
            k = nextt[k];
        }
    }
}
int Find_KMP(string T, string pat, int m)
{
    int posT = m, posP = -1;
    getNext(nextt, pat);//
    int lengthP = (int)pat.length();
    int lengthT = (int)T.length();

    while (posT < lengthT && posP < lengthP)
    {
        if (posP == -1 || T[posT] == pat[posP])
        {
            posT++;
            posP++;
        }
        else
        {
            posP = nextt[posP];
        }
    }
    if (posP < lengthP)
    {
        return  -100;
    }
    else return posT - lengthP;
}

int main()
{
    int pos = 0;
    string str1;
    string str2;

    int m;//从主串的下标m处开始匹配
    cin >> str1 >> str2 >> m;
    pos = Find_KMP(str1, str2, m);
    if (pos == -100)
    {
        cout << "匹配失败，" << str1 << "中不存在子串" << str2 << endl;
    }
    else {
        cout << "匹配成功，子串在主串中第一次匹配的下标位置是" << pos << endl;
        int lens = int(str2.length());
        for (int i = 0; i < lens; i++)
        {
            cout << nextt[i] << " ";
        }
    }


    return 0;
}