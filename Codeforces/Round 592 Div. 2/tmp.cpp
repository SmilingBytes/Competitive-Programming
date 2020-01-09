// C++ program to accept an amount
// and count number of notes
#include <bits/stdc++.h>
using namespace std;

// function to count and
// print currency notes
void countCurrency(int amount) {
  int notes[2] = {3, 2};
  int noteCounter[2] = {0};

  // count notes using Greedy approach
  for (int i = 0; i < 2; i++) {
    if (amount >= notes[i]) {
      noteCounter[i] = amount / notes[i];
      amount = amount - noteCounter[i] * notes[i];
    }
  }

  // Print notes
  cout << "Currency Count ->" << endl;
  for (int i = 0; i < 2; i++) {
    if (noteCounter[i] != 0) {
      cout << notes[i] << " : " << noteCounter[i] << endl;
    }
  }
}

// Driver function
int main() {
  int amount = 61;
  countCurrency(amount);
  return 0;
}
