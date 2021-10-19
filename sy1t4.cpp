/*
 * @Author: 李天阳_linyuansup
 * @Date: 2021-10-19 20:22:48
 * @LastEditors: 李天阳_linyuansup
 * @LastEditTime: 2021-10-19 20:31:37
 * @FilePath: \cpp\sy1t4.cpp
 */

#include <iostream>
using namespace std;
int main()
{
    int source = 0,price;
    cout << "input source and price, 1 for No.1, 2 for No.2, 3 for No.3, 4 for youshengjiang:";
    cin >> source >> price;
    if (price == 1)
        source += 10;
    else if (price == 2)
        source += 8;
    else if (price == 3)
        source += 5;
    else if (price == 4)
        source += 2;
    else
        cout << "error" << endl;
    if (source <= 100)
        cout << source;
    else
        cout << "100";
    return 0;
}