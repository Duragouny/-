#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
using namespace std;
const integer n = 15;
matrix<1,n, 1,n,integer> a;
integer i, j;
int main(int argc, const char* argv[])
{
  pio_initialize(argc, argv);
  output << "Enter matrix:" << NL;
  for( j = 1; j <= n; j ++) for( i = 1; i <= n; i ++)
    {
      output << "a[" << i << ", " << j << "] = ";
      input >> a[i][j] >> NL;
    }
  output << "Source matrix:" << NL;
  for( j = 1; j <= n; j ++)
    {
      for( i = 1; i <= n; i ++) output << format(a[i][j],8) << ' ';
      output << NL;
    }
  output << "Non-zero elements:" << NL;
    for( j = 1; j <= n; j ++) for( i = 1; i <= n; i ++) if (a[i][j] != 0)  output << '[' << i << ", " << j << ']' << NL;
  input >> NL;
  return EXIT_SUCCESS;
}
