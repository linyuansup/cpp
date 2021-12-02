#include <iostream>
#include <cstring>
using namespace std;
char *stringcat(char *str1, char *str2)
{
    int str1len = strlen(str1);
    int i;
    for (i = 0; str2[i]; i++)
        str1[str1len + i] = str2[i];
    str1[str1len + i] = '\0';
    return str1;
}
int main()
{
    char str1[100], str2[100];
    gets(str1);
    gets(str2);
    cout << stringcat(str1, str2);
    return 0;
}