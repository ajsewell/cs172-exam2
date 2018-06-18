//I affirm that all code given below was written solely by me, Allysa, 
//and that any help I received adhered to the rules stated for this exam.

// Project Name: Exam2
// Name: Allysa Sewell
// Date: 6/14/18
// Class: CS 172

#include "Runner.h"

//constructs a runner object with default values
Runner::Runner()
{
  firstname = "John";
  lastname = "Doe";
  pace = 500;
}

//constructs a runner object with the specified values
Runner::Runner(string firstname, string lastname, int pace)
{
  this->firstname = firstname;
  this->lastname = lastname;
  this->pace = pace;
}

//accesor function for firstname
string Runner::get_firstname()
{
  return firstname;
}

//accessor function for lastname
string Runner::get_lastname()
{
  return lastname;
}

//accessor function for pace
int Runner::get_pace()
{
  return pace;
}

//overloads << operator
ostream& operator<<(ostream& out, Runner& runner)
{
  out << runner.get_firstname() << " " << runner.get_lastname() << " "
  << runner.get_pace() << endl;
  return out;
}


//overloads < operator by comparing runners based on pace
bool operator<( Runner& runner1, Runner& runner2)
{
  return (runner1.get_pace() < runner2.get_pace());
}

//overloads <= operator 
bool operator<=(Runner& runner1, Runner& runner2)
{
  return (runner1.get_pace() <= runner2.get_pace());
}

//overloads > operator
bool operator>(Runner& runner1, Runner& runner2)
{
  return (runner1.get_pace() > runner2.get_pace());
}

//overloads >= operator
bool operator>=(Runner& runner1, Runner& runner2)
{
  return (runner1.get_pace() >= runner2.get_pace());
}



