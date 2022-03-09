//
// Created by 93601 on 2022/3/9.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

enum e_code
{
    overflow,
    underflow,
    success
};

template <class T>
class Stack
{
private:
    int count;
    T data[99999];

public:
    e_code get_top(T &x) const;
    e_code push(const T x);
    e_code pop();
    bool full() const;
    bool empty() const;
    Stack();
};

#endif // UNTITLED_STACK_H
