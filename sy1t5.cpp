/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-19 20:32:02
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-19 20:41:28
 * @FilePath: \cpp\sy1t5.cpp
 */

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a, b, c,d;
    cout << "please input a b and c:";
    cin >> a >> b >> c;
    d = b*b-4*a*c;
    if (d < 0)
    cout<<"No answer";
    else if (d == 0)
    cout<<"x1=x2="<<-b/2/a;
    else{
        cout<<"x1="<<(-b+sqrt(d))/2/a<<endl;
        cout<<"x2="<<(-b-sqrt(d))/2/a<<endl;
    }
    return 0;
}