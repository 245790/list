#include <iostream>
#include "knight.h"
#include "list.h"

using namespace std;

int main()
{
   knight k;
   k.setName("Karim");
   k.setBallads(30);
   k.setArmorWeight(2.401);
   k.setLadyLove(false);
   knight a;
   a.setName("Anthony");
   a.setBallads(1);
   a.setArmorWeight(6.74);
   a.setLadyLove(true);
   List<knight> myFirstList(k);
   myFirstList.pushFront(a);
   myFirstList.popFront();
   myFirstList.printList(cout);

   knight* p = new knight(k);
   delete p;
   p = &a;
   return 0;
}