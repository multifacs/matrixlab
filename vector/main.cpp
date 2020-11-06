#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"

int main()
{
  Vector<int> a(3, 3);
  a[0] = 10;
  cout << a << "\nHi\n";

  a.~Vector();

  Matrix<int> b(3);
  Matrix<int> c(3);

  b[0][0] = 1;
  b[0][1] = 2;
  b[0][2] = 3;
  b[1][0] = 4;
  b[1][1] = 5;
  b[2][0] = 6;

  c[0][0] = 1;
  c[0][1] = 2;
  c[0][2] = 3;
  c[1][0] = 4;
  c[1][1] = 5;
  c[2][0] = 6;

  cout << b << c;
  cout << b * c;

  Matrix<int> d(4);
  Matrix<int> e(4);

  d[0][0] = 1;
  d[0][1] = 2;
  d[0][2] = 3;
  d[0][3] = 4;
  d[1][0] = 5;
  d[1][1] = 6;
  d[1][2] = 7;
  d[2][0] = 8;
  d[2][1] = 9;
  d[3][0] = 1;

  e[0][0] = 1;
  e[0][1] = 2;
  e[0][2] = 3;
  e[0][3] = 4;
  e[1][0] = 5;
  e[1][1] = 6;
  e[1][2] = 7;
  e[2][0] = 8;
  e[2][1] = 9;
  e[3][0] = 1;

  cout << d << e;
  cout << d * e << endl;

  cout << (d[0] == e[0]);
  
  return 0;
}
