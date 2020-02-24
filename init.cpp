/**
 *    author:  ismail
 *    created: 12.01.2020  17:08:47
 **/
#include <bits/stdc++.h>
#include <io.h>
using namespace std;

inline bool exist(const std::string& name) {
  return (access(name.c_str(), F_OK) != -1);
}

int main() {
  string contestID, problemID = "a", s;
  cout << "CF Contest ID: ";
  cin >> contestID;  // codeforces contest id
  cout.flush();
  s = "cf race " + contestID;
  system(s.c_str());
  s = contestID + "/" + problemID;
  chdir(s.c_str());
  s = problemID + ".cpp";
  if (!exist(s)) system("cf gen");
  s = "code -r " + problemID + ".cpp ";
  system(s.c_str());
  cout << "Command / Problem ID: " << endl;
  while (cin >> problemID) {
    if (problemID == "t") {
      system("cf test");
    } else if (problemID == "s") {
      system("cf submit");
    } else if (problemID == "q") {
      system("exit");
      exit(1);
    } else if (problemID == "watch") {
      system("cf watch");
    } else if (problemID == "ls") {
      system("cf list");
    } else if (problemID == "stand") {
      system("cf stand");
    } else {
      s = "../" + problemID + "/";
      chdir(s.c_str());
      s = problemID + ".cpp";
      if (!exist(s)) system("cf gen");
      s = "cf open " + contestID + " " + problemID;
      system(s.c_str());
      s = "code -r " + problemID + ".cpp";
      system(s.c_str());
    }
    system("exit");
    cout << "Command or Problem ID: " << endl;
  }
  system("exit");
  exit(1);
  return 0;
}