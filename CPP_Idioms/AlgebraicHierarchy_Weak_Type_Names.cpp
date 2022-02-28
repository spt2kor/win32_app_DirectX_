#include <iostream>
#include "Number.h"
using namespace std;


namespace std
{
template <>
void swap (Number & n1, Number & n2)
{
  n1.swap (n2);
}
}
int main (void)
{
	cout<<"\n ************************* Number n1 = Number::makeComplex (1, 2); ****************"<<endl;
  Number n1 = Number::makeComplex (1, 2);
  cout<<"\n ************************* Number n2 = Number::makeReal (10); ****************"<<endl;
  Number n2 = Number::makeReal (10);
  cout<<"\n ************************* Number n3 = n1 + n2; ****************"<<endl;
  Number n3 = n1 + n2;
  cout<<"\n ************************* Finished ****************"<<endl;
  cout << "Finished\n";
 
  n1 = Number::makeReal (10);
  n2 = Number::makeComplex (1, 2);

  Number n4 = n1 + n2;

  return 0;
}