#include "Budget.h"

unsigned long long operator "" _todollars(unsigned long long sum) {
   unsigned long long dollars = sum / 70;
   return dollars;
}

int main(){
   Budget a;
   std:: cin >> a;
   Budget b;
   std:: cin >> b;
   Budget c = a + b;
   std:: cout << c;
   Budget d;
   std:: cin >> d;
   Budget f;
   std:: cin >> f;
   Budget x = d - f;
   std:: cout << x;
   return 0;
}