// Project Name: Exam2
// Name: Allysa Sewell
// Date: 6/14/18
// Class: CS 172

#ifndef RUNNER_H_
#define RUNNER_H_
#include <string>
using namespace std;

class Runner
{
public:
  Runner();
  Runner(string firstname, string lastname, int pace);
  string get_firstname();
  string get_lastname();
  int get_pace();

  //definition for << functions
  //useful for outputting runners in a file
  friend ostream& operator<<(ostream&, Runner&);
 
private:
  string firstname;
  string lastname;
  int pace;

};

//nonmember functions for overloading operators
//useful for sorting runners by comparing pace
bool operator<( Runner& runner1, Runner& runner2);
bool operator<=( Runner& runner1, Runner& runner2);
bool operator>( Runner& runner1, Runner& runner2);
bool operator>=( Runner& runner1, Runner& runner2);

#endif