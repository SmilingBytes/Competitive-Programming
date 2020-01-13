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
  system("code .");
  system("exit");
  string s = "code -r " + dir + "/";
  string str = "start chrome https://codeforces.com/contest/" + dir;
  string str1 = str + "/submit/";
  string link, submit, fname;
  string A = "A";

  do {
    std::transform(A.begin(), A.end(), A.begin(), ::toupper);
    if (A == "Q") break;

    link = str + "/problem/" + A;
    submit = str1 + A;
    fname = s + A + ".cpp";
    file.append(A);
    file.append(".cpp");
    ofstream write(file.c_str());
    system(fname.c_str());  // open file
    file = dir + "/";
    system(submit.c_str());  // open submit page
    system(link.c_str());    // open problem statement page
    system("exit");
    cout << "Enter Problem Code: " << endl;
  } while (cin >> A);

  system("exit");
  exit(1);
  return 0;
}