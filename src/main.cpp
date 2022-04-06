#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <string>
#include <vector>

#include "input-output.h"
#include "new-data-types.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "en_US.UTF-8");
  std::vector<student> s;

  cout << "Įvesti studentų duomenis iš failo - 1\n";
  cout << "Įvesti studentų duomenis komandinėje eilutėje - 2\n";
  cout << "Sugeneruoti duomenų failą - 3\n";
  cout << "Testuoti programos veikimo greitį - 4\n";
  cout << "Sugeneruoti naujus failius testavimui - 5\n";

  int choice;
  cout << "Jūsų pasirinkimas: ";
  cin >> choice;
  switch (choice) {
    case 1:
      inputFromFile(s, true, "kursiokai.txt");
      output(s);
      break;
    case 2:
      input(s);
      output(s);
      break;
    case 3:
      int gradeCount, studentCount;
      cout << "Kiek pažymių turi studentai? ";
      while (!(cin >> gradeCount) || gradeCount < -1) {
        cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
        cin.clear();  // Clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      cout << "Kiek yra studentų? ";
      while (!(cin >> studentCount) || studentCount < -1) {
        cout << "Klaidingas kiekis, bandikyte įvesti dar kartą: ";
        cin.clear();  // Clear error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      generateStudents(gradeCount, studentCount);
      divideFile<vector<student>>(studentCount);
      break;
    case 4:
      for (int i = 1000; i <= 10000000; i *= 10) {
        cout << "Vector:\n";
        divideFile<vector<student>>(i);
        cout << "List:\n";
        divideFile<list<student>>(i);
        cout << "Deque:\n";
        divideFile<deque<student>>(i);
        cout << "\n\n";
      }
      break;
    case 5:
      for (int i = 1000; i <= 10000000; i *= 10) {
        generateStudents(10, i);
      }
      break;
    default:
      cout << "Neteisingas pasirinkimas!\n";
  }

  return 0;
}
