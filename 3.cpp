#include "ptoc.h"


real a,f;
int main(int argc, const char* argv[])
{
pio_initialize(argc, argv);
output << "a=";input >> a >> NL;
if(a<-1) 
f=sqr(a);
else if ((a>=1) && (a<=2)) 
f=sqr(a);
else
f=4;
output << "f=" << format(f,5,2) << NL;
input >> NL;
return EXIT_SUCCESS;
}