#include "Student_assistant.h"
int main()
{
    Assistant ass("Ass", "15651", "Female", "HFUT", 5000.5);
    Student_assistant stuass("stuass", "5618498", "Male", "HFUT", 300.5, "SE", "3");
    ass.print_info();
    cout << endl;
    stuass.print_info();
    return 0;
}