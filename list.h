//Implementation of singly-linked list

#ifndef _LIST_H    // if the name LIST_H is not defined yet
#define _LIST_H   // define it

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
   void setNext(ListItem<T> *next);
   ListItem<T>* getNext() const;
   void setData(const T &data);
   T& getData();
   ListItem<T>& operator=(ListItem<T> arg);
};

//List itself
//   Usage:
//   List<int> myFirstList;
//   myFirstList.pushFront(5);
//   myFirstList.pushBack(6);
//   myFirstList.print(cout); //any other output stream could be used

template<class T>
class List
{
private:
   ListItem<T> *head; //points to the first element of a list
   int listSize;
public:
   List(); //initializes an empty list
   List(const T &item); //initializes a list with one element equal to "item"
   ~List(); //destryos a list
   void pushFront(const T &item); //adds element to the front of the list
   void pushAt(const T &item, int index); //adds element to the stated position
   void pushBack(const T &item); //adds element to the end of the list
   void popFront(); //removes the first element of a list
   void popAt(int index); //removes the element of a list on a stated position
   void popBack(); //removes the last element of a list
   void print(ostream& os) const; //prints a list to a specified output stream
   bool empty() const; //tells if a list is empty
   T& at(int index) const; //returns an element on index position
   int search(const T& item); //returns the position of the first occurence
                              //of an element or -1
   void sort(); //ascending
   int size();
};


template<class T>
List<T>::List()
{
   this->head = NULL;
   listSize = 0;
}

template<class T>
List<T>::List(const T &item)
{
   ListItem<T>* newItem = new ListItem<T>(item);
   this->head = newItem;
   listSize = 1;
}

template<class T>
List<T>::~List()
{
   while(head != NULL)
   {
      ListItem<T> *tmp = head;
      head = head->getNext();
      delete tmp;
   }
}

template<class T>
void List<T>::pushFront(const T &item)
{
   ListItem<T>* newItem = new ListItem<T>(item);
   newItem->setNext(this->head);
   this->head = newItem;
   listSize++;
}

template<class T>
void List<T>::pushAt(const T &item, int index)
{
   ListItem<T>* tmp = head;
   for(int i = 0; i < index; i++)
   {
      tmp = tmp->getNext();
   }
   ListItem<T>* newItem = new ListItem<T>(item); //newItem's next is NULL
   tmp->setNext(newItem);
   listSize++;
}


template<class T>
void List<T>::pushBack(const T &item)
{
   ListItem<T>* tail = head;
   while(tail->getNext() != NULL)
   {
      tail = tail->getNext();
   }
   ListItem<T>* newItem = new ListItem<T>(item); //newItem's next is NULL
   tail->setNext(newItem);
   listSize++;
}

template<class T>
void List<T>::popFront()
{
   if(listSize > 0)
   {
      ListItem<T>* tmp = head;
      head = head->getNext();
      delete tmp;
      listSize--;
   }
}

template<class T>
void List<T>::popAt(int index)
{
   if(listSize > 0 && index < listSize)
   {
      if(listSize == 1)
      {
         this->popFront();
      }
      else
      {
         ListItem<T>* last = head;
         ListItem<T>* secondLast = head;
         for(int i = 0; i < index - 1; i++)
         {
            secondLast = secondLast->getNext();
         }
         last = secondLast->getNext();
         secondLast->setNext(last->getNext());
         delete last;
      }
   }
}

template<class T>
void List<T>::popBack()
{
   if(listSize > 0)
   {
      if(listSize == 1)
      {
         ListItem<T>* last = head;
         head = NULL;
         delete last;
      }
      else
      {
         ListItem<T>* last = head;
         ListItem<T>* secondLast = head;
         while(secondLast->getNext()->getNext() != NULL)
         {
            secondLast = secondLast->getNext();
         }
         last = secondLast->getNext();
         secondLast->setNext(NULL);
         delete last;
      }
   }
}

template<class T>
void List<T>::print(ostream& os) const
{
   ListItem<T>* toPrint = head;
   while(toPrint != NULL)
   {
      os<<toPrint->getData()<<"\n"; //every item is printed on a new line
      toPrint = toPrint->getNext();
   }
}

template<class T>
bool List<T>::empty() const
{
   return listSize == 0;
}

template<class T>
T& List<T>::at(int index) const
{
   ListItem<T>* itemToReturn = head;
   for(int i = 0; i < index; i++)
   {
      itemToReturn = itemToReturn->getNext();
   }
   return itemToReturn->getData();
}

template<class T>
int List<T>::search(const T& item)
{
   ListItem<T>* toSearch = head;
   int occurence = 0;
   while(toSearch->getNext() != NULL)
   {
      if(toSearch->getData() == item)
      {
         return occurence;
      }
      occurence++;
      toSearch = toSearch->getNext();
   }
   return -1;
}

template<class T>
void List<T>::sort()
{
   if(listSize >= 2)
   {
      for(int i = 0; i < listSize; i++)
      {
         ListItem<T>* current = head;
         for(int j = 0; j < i; j++)
         {
            current = current->getNext();
         }
         T minElement = current->getData();
         ListItem<T>* minElementPosition = current;
         for(ListItem<T>* j = current->getNext();
            j != NULL && j->getNext() != NULL; j = j->getNext())
         {
            if(j->getData() < minElement)
            {
               minElement = j->getData();
               minElementPosition = j;
            }
         }
         T hold = minElement;
         minElementPosition->setData(current->getData());
         current->setData(hold);
      }
   }
}

template<class T>
int List<T>::size()
{
   return listSize;
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
ListItem<T>* ListItem<T>::getNext() const
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