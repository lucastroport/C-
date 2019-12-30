#include <iostream>
#include <stddef.h>
#include "String.h"
#include "String.cpp"



using namespace std;
int main ()
{


String str  ("Hello",false);
String str2 ("Hello",true);


if(str == str2) cout << "SAME";
else cout << "DIFFERENT";





return 0;

}