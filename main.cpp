#include <iostream>
#include "knight.h"
#include "list.h"
#include "deq.h"

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
   Deq<knight> myFirstDeq(k);
   myFirstDeq.pushBack(a);
   for(int i = 0; i < 100; i++)
   {
      a.randomData();
      myFirstDeq.pushFront(a);
   }
   Deq<knight> results;
   int myFirstDeqSize = myFirstDeq.size();
   int resultsSize = 0;
   for(int i = 0; i < myFirstDeqSize; i++)
   {
      a = myFirstDeq.popBack();
      if(a.practiceTask())
      {
         results.pushFront(a);
         resultsSize++;
      }
   }
   for(int i = 0; i < resultsSize; i++)
   {
      a = results.popBack();
      cout<<a;
   }
   return 0;
}