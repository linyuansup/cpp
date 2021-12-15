#include "Mystring.h"
#include <string.h>
using namespace std;
Mystring::Mystring(char *p)
{
    len = strlen(p);
    this->p = new char[len + 1];
    strcpy(this->p, p);
}
Mystring::Mystring(Mystring &s)
{
    len = s.len;
    this->p = new char[len + 1];
    strcpy(this->p, s.p);
}
Mystring::~Mystring()
{
    delete[] this->p;
}
void Mystring::show()
{
    cout << this->p << endl;
}