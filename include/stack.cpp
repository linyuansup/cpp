#include "Stack.h"
template <class T>
Stack<T>::Stack()
{
    count = 0;
}
template <class T>
bool Stack<T>::full() const
{
    return count == 99999;
}
template <class T>
bool Stack<T>::empty() const
{
    return count == 0;
}
template <class T>
e_code Stack<T>::get_top(T &x) const
{
    if (empty())
        return underflow;
    x = data[count - 1];
    return success;
}
template <class T>
e_code Stack<T>::push(const T x)
{
    if (full())
        return overflow;
    data[count++] = x;
    return success;
}
template <class T>
e_code Stack<T>::pop()
{
    if (empty())
        return underflow;
    count--;
    return success;
}
template class Stack<char>;
template class Stack<int>;