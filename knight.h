#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <vector>
using namespace std;

class knight
{
private:
   string name;
   int ballads;
   float armorWeight;
   bool ladyLove;
   vector<int> computePrefixFunction(const string &s);
public:
   knight(); //creates empty object
   knight(const knight &obj); //creates object equal to obj
   void setName(string _name); //accessors
   string getName() const;
   void setBallads(int _ballads);
   int getBallads() const;
   void setArmorWeight(float _weight);
   float getArmorWeight() const;
   void setLadyLove(bool _ladyLove);
   bool hasLadyLove() const;
   void randomData();
   int findInName(const string& s); //returns the number of the first occurence
                                    // of s in name
   bool practiceTask(); //returns true if letters on even position are all
                        //vowels and armor weight has 1 in the third sign
                        // after comma
   bool hasVowelsOnEvenPositions(); //true if all letters on
                                    //even positions are vowels
   friend ostream& operator<<(ostream& os, knight& obj);
   friend istream& operator>>(istream& is, knight& obj);
   bool operator==(const knight& obj);
   bool operator>(const knight& obj);
   bool operator<(const knight& obj);
};

#endif