#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>

class Budget {
    public:
        Budget();
        Budget(double a, double b);
        void Rouding();
        void Difference();
        void Multiplier();
        void Division();
        void Compare();
        Budget operator + (const Budget &object);
        Budget operator - (const Budget &object);
        bool operator == (const Budget &object);
        bool operator > (const Budget &other);
        bool operator < (const Budget &other);
        friend std::istream& operator >> (std::istream& is, Budget &object);
        friend std::ostream& operator << (std::ostream& os, Budget &object);
        ~Budget();

    private:
    double personal;
    double credit;

};
#endif