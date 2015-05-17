#ifndef _DEQ_H    // if the name LIST_H is not defined yet
#define _DEQ_H   // define it

#include "list.h"
using namespace std;

template<class T>
class Deq
{
private:
   List<T> deq;
   int deqSize;
public:
   Deq();
   Deq(const T &item);
   void pushFront(const T &item);
   void pushBack(const T &item);
   int size() const;
   T popFront();
   T popBack();
   bool empty() const;
};

template<class T>
Deq<T>::Deq()
{
   deqSize = 0;
}

template<class T>
Deq<T>::Deq(const T &item)
{
   deqSize = 1;
   deq.pushFront(item);
}

template<class T>
void Deq<T>::pushFront(const T &item)
{
   deqSize++;
   deq.pushFront(item);
}

template<class T>
void Deq<T>::pushBack(const T &item)
{
   deqSize++;
   deq.pushBack(item);
}

template<class T>
int Deq<T>::size() const
{
   return deqSize;
}

template<class T>
T Deq<T>::popFront()
{
   if(deqSize > 0)
   {
      deqSize--;
      T data;
      data = deq.at(0);
      return data;
   }
   // return NULL;
}

template<class T>
T Deq<T>::popBack()
{
   if(deqSize > 0)
   {
      deqSize--;
      T data;
      data = deq.at(deqSize); //exactly last
      return data;
   }
   // return NULL;
}

template<class T>
bool Deq<T>::empty() const
{
   return deq.empty();
}

#endif