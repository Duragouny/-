#include "ptoc.h"



integer n, i;
real a1, a2;


int main(int argc, const char* argv[])
{
  pio_initialize(argc, argv);
  output << "Введите N: ";
  input >> n >> NL;
  a1 = 2; \\ A[0]  for( i = 1; i <= n; i ++)
  {
    a2 = 2 + 1 / a1;
    a1 = a2;
    output << "[A" << i << "] = " << a2 << NL;
  }
  return EXIT_SUCCESS;
}