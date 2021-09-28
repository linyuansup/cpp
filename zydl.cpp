// Coding with Visual Studio Code, Mingw64 6.0 and CMake 3.20.2

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(NULL));
    int my_num[4], input_data, in_num[4], i, j, a_num, b_num, try_num = 1, num, temp, length = 0;
    string input_dat;
    for (i = 0; i <= 3; i++) {
        my_num[i] = (rand() % 9 + 1);
    }
    CHECK:
    for (i = 0; i <= 2; i++) {
        for (j = i + 1; j <= 3; j++) {
            if (my_num[i] == my_num[j]) {
                my_num[j] = rand() % 9 + 1;
                goto CHECK;
            }
        }
    }
    num = my_num[0] * 1000 + my_num[1] * 100 + my_num[2] * 10 + my_num[3];
    INPUT:
    a_num = 0;
    b_num = 0;
    if (try_num == 11) {
        cout << "You lose. The answer is " << num << endl;
        goto END;
    }
    cout << try_num << "/" << 10 << ". Input the number you guess:";
    cin >> input_dat;
    if (all_of(input_dat.begin(), input_dat.end(), ::isdigit)) {
        input_data = atoi(input_dat.c_str());
        temp = input_data;
        while (temp) {
            temp /= 10;
            length++;
        }
        if (length != 4) {
            cout << "You can only input a number with four digits Please retry." << endl;
            length = 0;
            goto INPUT;
        }
        in_num[3] = input_data / 1 % 10;
        in_num[2] = input_data / 10 % 10;
        in_num[1] = input_data / 100 % 10;
        in_num[0] = input_data / 1000 % 10;
        for (i = 0; i <= 3; i++) {
            if (in_num[i] == 0) {
                cout << "You cannot input data with 0. Please retry." << endl;
                goto INPUT;
            }
        }
        for (i = 0; i <= 2; i++) {
            for (j = i + 1; j <= 3; j++) {
                if (in_num[i] == in_num[j]) {
                    cout << "You cannot input data with same number. Please retry." << endl;
                    goto INPUT;
                }
            }
        }
        if (num == input_data) {
            cout << "You win" << endl;
            goto END;
        }
        for (i = 0; i <= 3; i++) {
            for (j = 0; j <= 3; j++) {
                if (in_num[i] == my_num[j]) {
                    if (i == j) {
                        a_num++;
                    } else {
                        b_num++;
                    }
                }
            }
        }
        cout << "A" << a_num << "B" << b_num << endl;
        try_num++;
        goto INPUT;
    } else {
        cout << "You can only input number. Please retry." << endl;
        goto INPUT;
    }
    END:
    return 0;
}