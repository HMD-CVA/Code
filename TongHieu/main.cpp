#include<bits/stdc++.h>
using namespace std;
int main()
{
  unsigned long long a1, b1, c1, a2, b2, c2;
  unsigned long long  D, Dx, Dy, x, y;
  a1=1;
  b1=1;
  a2=1;
  b2=-1;
  cin >> c1 >> c2;
  D = a1 * b2 - a2 * b1;
  Dx = c1 * b2 - c2 * b1;
  Dy = a1 * c2 - a2 * c1;
  if (D == 0) {
    if (Dx + Dy == 0)
      return 1;
    else
     return 0;
    }
  else
    {
    x = Dx / D;
    y = Dy / D;
    cout << x << endl << y;
  }

}
