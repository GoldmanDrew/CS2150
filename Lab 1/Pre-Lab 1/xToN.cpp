/*
Drew Goldman
dag5wd@virginia.edu
9/4/2020
xToN.cpp
 */
#include <iostream>
using namespace std;

int xton(int x, int n) {
   int tmp = n;
   while(tmp > 0) {
      return x * xton(x,tmp-1);
    }
    return 1;
  }

int main () {
  int a, b, c;
    cin >> a;
    cin >> b;
    c = xton(a, b);
    cout << c << endl;
    return 0;
}
