#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

class Budget {
    public:
        Budget();
        Budget(double a, double b);
        Budget(std::istream &is);
        void Rouding();
        void Difference();
        void Summa();
        void Multiplier();
        void Division();
        void Compare();
        void Print(std::ostream &os);
        ~Budget();

    private:
    double personal;
    double credit;

};
#endif