//Implementation of singly-linked list

#ifndef _LIST_H    // if the name LIST_H is not defined yet
#define _LIST_H   // define it
#include <iostream>
using namespace std;

//An item of a list, auxiliary class for List<T>
//Should NEVER be used by anyone but List class; my fault

template<class T>
class ListItem
{
private:
   T data;
   ListItem<T> *next;
public:
   ListItem();
   ListItem(const T &item);
   // ListItem(const ListItem<T> &item);
   void setNext(ListItem<T> *next);
   ListItem<T>* getNext();
   void setData(const T &data);
   T& getData();
   ListItem<T>& operator=(ListItem<T> arg);
};

//List itself
//   Usage:
//   List<int> myFirstList;
//   myFirstList.pushFront(5);
//   myFirstList.pushBack(6);
//   myFirstList.printList(cout); //any other output stream could be used

template<class T>
class List
{
private:
   ListItem<T> *head; //points to the first element of a list
public:
   List(); //initializes an empty list
   List(const T &item); //initializes a list with one element equal to "item"
   void pushFront(const T &item); //adds element to the front of the list
   void pushBack(const T &item); //adds element to the end of the list
   T& popFront(); //removes the first element of a list and returns what was
                  //removed
   T& popBack(); //removes the last element of a list and returns what was
                 //removed
   void printList(ostream& os); //prints a list to a specified output stream
   bool empty(); //tells if a list is empty
};


template<class T>
List<T>::List()
{
   this->head = NULL;
}

template<class T>
List<T>::List(const T &item)
{
   ListItem<T>* newItem = new ListItem<T>(item);
   this->head = newItem;
}

template<class T>
void List<T>::pushFront(const T &item)
{
   ListItem<T>* newItem = new ListItem<T>(item);
   newItem->setNext(this->head);
   this->head = newItem;
}

template<class T>
void List<T>::pushBack(const T &item)
{
   ListItem<T>* newItem = new ListItem<T>(item);
   newItem->setNext(this->head);
   this->head = newItem;
}

template<class T>
T& List<T>::popFront()
{
   ListItem<T>* deletedItem = head;
   // delete head; //!!!
   head = deletedItem->getNext();
   return deletedItem->getData();
}

template<class T>
void List<T>::printList(ostream& os)
{
   ListItem<T>* toPrint = this->head;
   while(toPrint != NULL)
   {
      os<<toPrint->getData()<<"\n"; //every item is printed on a new line
      toPrint = toPrint->getNext();
   }
}

template<class T>
bool List<T>::empty()
{
   return this->head == NULL; //if the head is NULL, then the list is
                              //empty and the function returns true
}

template<class T>
ListItem<T>::ListItem()
{
   this->next = NULL;
}

template<class T>
ListItem<T>::ListItem(const T &item)
{
   this->data = item;
   this->setNext(NULL);
}

template<class T>
void ListItem<T>::setNext(ListItem<T> *next)
{
   this->next = next;
}

template<class T>
ListItem<T>* ListItem<T>::getNext()
{
   return this->next;
}

template<class T>
void ListItem<T>::setData(const T &data)
{
   this->data = data;
}

template<class T>
T& ListItem<T>::getData()
{
   return this->data;
}

template<class T>
ListItem<T>& ListItem<T>::operator=(ListItem<T> arg)
{
   this->data = arg.getData();
   return *this;
}

#endif