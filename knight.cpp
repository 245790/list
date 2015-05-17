#include <cstdlib>
#include <istream>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>

#include "knight.h"
using namespace std;

knight::knight()
{

}

knight::knight(const knight &obj)
{
   setName(obj.getName());
   setBallads(obj.getBallads());
   setArmorWeight(obj.getArmorWeight());
   setLadyLove(obj.hasLadyLove());
}

void knight::setName(string _name)
{
   name = _name;
}

string knight::getName() const
{
   return name;
}

void knight::setBallads(int _ballads)
{
   ballads = _ballads;
}

int knight::getBallads() const
{
   return ballads;
}

void knight::setArmorWeight(float _weight)
{
   armorWeight = _weight;
}

float knight::getArmorWeight() const
{
   return armorWeight;
}

void knight::setLadyLove(bool _ladyLove)
{
   ladyLove = _ladyLove;
}

bool knight::hasLadyLove() const
{
   return ladyLove;
}

string randomString();

string randomString()
{
   int randomSize = 5 + rand() % 5;
   char randChar = 'A' + rand() % 26;
   string randStr;
   randStr += randChar;
   for(int i = 0; i < randomSize; i++)
   {
      randChar = 'a' + rand() % 26;
      randStr += randChar;
   }
   return randStr;
}

void knight::randomData()
{
   setName(randomString());
   setArmorWeight(10.0 + (rand() % 16) / 3.0);
   setBallads(rand() % 15);
   setLadyLove(rand() % 2 == 0 ? true : false);
}

int knight::findInName(const string &s)
{
   vector<int> pf = computePrefixFunction(s);

   const string t = name;

   int k = 0, j = 0;

   for (int i = 0, k = pf[0]; i < t.size();)
   {
      j = 0;
      while(i + j < t.size() && j + k < s.size() && t[i + j] == s[j + k])
      {
         j++;
      }
      if(j + k == s.size())
      {
         return i;
      }
      if(j == 0)
      {
         i ++;
         k = 0;
      }
      else
      {
         i += j;
         k = pf[j];
      }
   }
   return (-1);
}

bool knight::practiceTask()
{
   if(this->hasVowelsOnEvenPositions() && ((int)floor(this->getArmorWeight() * 1000) % 10) == 1)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool knight::hasVowelsOnEvenPositions()
{
   for(int i = 1; i < name.length(); i += 2)
   {
      if((name[i] != 'a') && (name[i] != 'e') && (name[i] != 'i') && (name[i] != 'o') && (name[i] != 'u'))
      {
         return false;
      }
   }
   return true;
}

ostream& operator<<(ostream& os, knight& obj)
{
   os<<obj.getName()<<"\n"<<obj.getBallads()<<"\n"<<obj.getArmorWeight()<<"\n"<<obj.hasLadyLove()<<"\n\n";
   return os;
}

istream& operator>>(istream& is, knight& obj)
{
   string n;
   int b;
   float a;
   bool l;
   is>>n>>b>>a>>l;
   obj.setName(n);
   obj.setBallads(b);
   obj.setArmorWeight(a);
   obj.setLadyLove(l);
   return is;
}

bool knight::operator==(const knight& obj)
{
   if(this->getName() == obj.getName() &&
      this->getBallads() == obj.getBallads() &&
      this->getArmorWeight() == obj.getArmorWeight() &&
      this->hasLadyLove() == obj.hasLadyLove())
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool knight::operator>(const knight& obj)
{
   if(this->getArmorWeight() > obj.getArmorWeight()) //i assume that armor
                                                     //is what really matters
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool knight::operator<(const knight& obj)
{
   if(this->getArmorWeight() < obj.getArmorWeight()) //i assume that armor
                                                     //is what really matters
   {
      return true;
   }
   else
   {
      return false;
   }
}

vector<int> knight::computePrefixFunction(const string &s)
{
   int len = s.size();
   vector<int> p(len); // значения префикс-функции
             // индекс вектора соответствует номеру последнего символа аргумента
   p[0] = 0; // для префикса из нуля и одного символа функция равна нулю

   int k = 0;
   for(int i = 1; i < len; i++)
   {
      while((k > 0) && (s[k] != s[i]))
      {
         k = p[k - 1]; 
      }
      if (s[k] == s[i])
      {
         k++;
      }
      p[i] = k;
   }
   return p;
}