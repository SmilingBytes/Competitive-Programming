/**
 *    author:  ismail
 *    created: 12.01.2020  17:08:47
 **/
#include <bits/stdc++.h>
#include <io.h>
using namespace std;

int main() {
  string dir;
  cout << "Enter CF Contest ID: ";
  cin >> dir;  // codeforces contest id
  cout.flush();
  mkdir(dir.c_str());
  string file = dir + "/";
  for (auto ch = 'A'; ch <= 'D'; ch++) {
    file.push_back(ch);
    file.append(".cpp");
    ofstream write(file.c_str());
    file = dir + "/";
  }
  system("code .");
  system("exit");
  string openFile = "code -r " + dir + "/A.cpp";
  system(openFile.c_str());
  system("exit");
  exit(1);
  return 0;
}