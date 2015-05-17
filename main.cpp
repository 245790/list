#include <cstdlib>
#include <iostream>
#include <time.h>

#include "knight.h"
#include "list.h"
#include "deq.h"

using namespace std;

int main()
{
   srand(time(NULL));
   knight k;
   k.setName("Karim");
   k.setBallads(30);
   k.setArmorWeight(2.401);
   k.setLadyLove(false);
   knight t;
   t.setName("Anthony");
   t.setBallads(1);
   t.setArmorWeight(6.74);
   t.setLadyLove(true);
   knight a;
   List<knight> myFirstList(k);
   // cout<<myFirstList.search(k)<<"\n\n";
   for(int i = 0; i < 5; i++)
   {
      a.randomData();
      if(i % 2 == 0)
      {
         myFirstList.pushBack(a);
      }
      else
      {
         myFirstList.pushFront(a);
      }
   }
   myFirstList.print(cout);
   myFirstList.sort();
   cout<<"\n\n\n\n";
   myFirstList.print(cout);
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
   // for(int i = 0; i < resultsSize; i++)
   // {
   //    a = results.popBack();
   //    cout<<a;
   // }
   return 0;
}