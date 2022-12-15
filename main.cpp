// C++ Final Project
// Restaraunt List
// By Ariel Gross

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> restList(0);

string AddRest(string restName) {
  restList.push_back(restName);
  cout << endl;
  cout << "Added " << restName << " to list." << endl;
  return restName;
}

string RandRest() {
  string restName;
  int randNum;
  randNum = rand() % restList.size();
  restName = restList.at(randNum);
  return restName;
}

int main() {
  ifstream inFS;
  ofstream outFS;

  int i;
  char userInput;
  string newRest;
  string str;

  do {

    // user menu
    cout << "|---------------------------|" << endl;
    cout << "| *  Restaurant Database  * |" << endl;
    cout << "| - l: List all restaurants |" << endl;
    cout << "| - r: Random restaurant    |" << endl;
    cout << "| - a: Add restaurant       |" << endl;
    cout << "| - u: Upload restaurants   |" << endl;
    cout << "| - p: Print restaurants    |" << endl;
    cout << "| - q: Quit program         |" << endl;
    cout << "|---------------------------|" << endl;

    cin >> userInput;

    // choose branch from input
    switch (userInput) {
    case 'l':
    case 'L':
      // list of all restaurants - output vector

      cout << endl;
      cout << "Restaurant List:" << endl;
      for (i = 0; i < restList.size(); ++i) {
        cout << restList.at(i) << endl;
      }
      cout << endl;
      break;

    case 'r':
    case 'R':
      // print a random restaurant - random vector element
      cout << endl;
      cout << "Your random restaurant is: ";
      cout << RandRest() << endl;
      cout << endl;

      break;

    case 'a':
    case 'A':
      // add restaurant to list - add to end of vector

      cout << endl;
      cout << "Enter new restaurant name (1 word, no spaces): ";
      cin.ignore();
      getline(cin, newRest);
      AddRest(newRest);
      cout << endl;
      break;

    case 'u':
    case 'U':
      // upload restaraunts - load from file

      cout << "Opening file RestarauntList.txt..." << endl;

      inFS.open("RestarauntList.txt");

      if (!inFS.is_open()) {
        cout << "Could not open RestarauntList.txt." << endl;
        break;
      }

      cout << "Reading list from file..." << endl;

      while (getline(inFS, str)) {
        restList.push_back(str);
      }

      cout << "Closing file..." << endl;
      inFS.close();

      break;

    case 'p':
    case 'P':
      // print restaraunts - output to file

      cout << "Opening file RestarauntList.txt..." << endl;

      outFS.open("RestarauntList.txt");

      if (!outFS.is_open()) {
        cout << "Could not open RestarauntList.txt." << endl;
        break;
      }

      cout << "Writing list to file..." << endl;
      for (i = 0; i < restList.size(); ++i) {
        outFS << restList.at(i) << endl;
      }

      cout << "Closing file..." << endl;
      outFS.close();

      break;

    case 'q':
    case 'Q':
      // quit program - break

      cout << "Goodbye" << endl;
      break;

    default:
      cout << "Error: please enter a character from the list." << endl;
      break;
    }

  } while (userInput != 'q');

  return 0;
}
