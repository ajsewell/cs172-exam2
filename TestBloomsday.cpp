//I affirm that all code given below was written solely by me, Allysa, 
//and that any help I received adhered to the rules stated for this exam.

// Project Name: Exam2
// Name: Allysa Sewell
// Date: 6/14/18
// Class: CS 172

#include <iostream>
#include <fstream>
#include <vector>
#include "Runner.h"
using namespace std;

vector<Runner> getRunners(ifstream& input)
{
  string firstname, lastname, pace;
  vector<Runner> runners; //creates vector of runners
  while (!input.eof()) //inputs data until the file ends
  {
    getline(input, firstname, ' ');
    getline(input, lastname, ' ');
    getline(input, pace);

  //pace was input as a string so the getline function could
  //be used and must be converted to an integer for 
  //use in the constructor
  const char* pace1 = pace.c_str();
  Runner runner(firstname, lastname, atoi(pace1));
  //adds a runner object to the runners vector
  runners.push_back(runner);
  }
  return runners;
}

//can sort vectors of different types
//in this program it is used to sort runners based on pace
template <typename T>
vector<T> sortVector(vector<T>& vector)
{
  for (int j = vector.size(); j >= 0; j--)
    for (int i = 0; i < j; i++)
    {
      if (vector[i] > vector[j - 1])
      {
        T temp = vector[i];
        vector[i] = vector[j - 1];
        vector[j - 1] = temp;
      }
    }
  return vector;
}

//tells the user if the file didn't open
void outputFail(ofstream& output)
{
  if (output.fail())
    cout << "cannot open file" << endl;

}

//puts runners into different files based on pace
void organizeRunners(vector<Runner> runners)
{
  ofstream output("white.txt");
  outputFail(output);
  ofstream output2("yellow.txt");
  outputFail(output2);
  ofstream output3("green.txt");
  outputFail(output3);
  ofstream output4("orange.txt");
  outputFail(output4);
  ofstream output5("blue.txt");
  outputFail(output5);
  ofstream output6("lilac.txt");
  outputFail(output6);
  ofstream output7("red.txt");
  outputFail(output7);
  for (int i = 0; i < runners.size(); i++)
  {
    if (runners[i].get_pace() < 361)
      output << runners[i];

    else if (runners[i].get_pace() < 421)
      output2 << runners[i];

    else if (runners[i].get_pace() < 481)
      output3 << runners[i];

    else if (runners[i].get_pace() < 541)
      output4 << runners[i];

    else if (runners[i].get_pace() < 601)
      output5 << runners[i];

    else if (runners[i].get_pace() < 721)
      output6 << runners[i];

    else if (runners[i].get_pace() < 1201)
      output7 << runners[i];
  }
  output.close();
  output2.close();
  output3.close();
  output4.close();
  output5.close();
  output6.close();
  output7.close();
}

int main()
{

  //inputs a file with a list of runners
  ifstream input("runners.txt");
  if (input.fail())
  {
    cout << "Could not open file" << endl;
    return 0;
  }

  vector<Runner> runners = getRunners(input);
  //removes an extra object that was added to the vector
  runners.pop_back();
  sortVector(runners);
  organizeRunners(runners);
  return 0;
}
