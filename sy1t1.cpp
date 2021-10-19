/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-19 19:26:29
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-19 22:07:27
 * @FilePath: \cpp\sy1t1.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    cout << "Please input three numbers:";
    cin >> a >> b >> c;
    if (a + b > c || b + c > a || a + c > b)
    {
        cout << "it can become a triangle.";
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
            cout << "it can become a right triangle."<< endl;
        else
        {
            cout << "it can't become a right triangle."<< endl;
        }
    }
    else
        cout << "it can't become a triangle.";
    return 0;
}