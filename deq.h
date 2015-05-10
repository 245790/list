#ifndef _DEQ_H    // if the name LIST_H is not defined yet
#define _DEQ_H   // define it
#include <iostream>
#include "list.h"
using namespace std;

template<class T>
class Deq
{
private:
   List<T> deq;
public:
   Deq();
   Deq(const T &item);
   void pushFront(const T &item);
   void pushBack(const T &item);
   T& popFront();
   T& popBack();
};

template<class T>
Deq::Deq()
{

}

Deq::Deq(const T &item)
{
   deq.pushFront(item);
}

template<class T>
void Deq::pushFront(const T &item)
{
   deq.pushFront(item);
}

template<class T>
void Deq::pushBack(const T &item)
{
   deq.pushBack(item);
}

template<class T>
T& Deq::popFront()
{
   return deq.popFront();
}

template<class T>
T& Deq::popBack()
{
   return deq.popBack();
}

#endif