#include "Budget.h"
#include <cmath>

Budget::Budget() {
    personal = 0.0;
    credit = 0.0;
    std:: cout << "Start: " << std:: endl;
}

Budget::Budget(double a, double b) {
    if (a > 0.0 && b > 0.0){
        personal = a;
        credit = b;
    }
    else {
        std:: cout << "Please enter positive numbers!" << std:: endl;
    }
    std:: cout << "The budget according to your parameters has been created" << std:: endl;
}
Budget::Budget(std::istream &is) {
    std:: cout << "Please enter your budget data: " << std:: endl;
    is >>  personal >> credit;
    if ((personal <= 0.0) || (credit <= 0.0)) {
        std:: cout << "Invalind input. Enter again!" << std:: endl;
        is >> personal >> credit;
    }
    std:: cout << "The budget has been created via istream" << std:: endl;
}

void Budget::Rouding() {
    this->personal = round (this->personal * 100.0) / 100.0;
    this->credit = round (this->credit * 100.0) / 100.0;
    std:: cout << "Rouding: " << this->personal << " " << this->credit << std:: endl;
}

void Budget::Difference() {
    double differ = personal - credit;
    std:: cout << "Difference: " << differ << std:: endl;
}

void Budget::Summa() {
    double budget = personal + credit;
    std:: cout << "Total budget: " << budget << std:: endl;    
}

void Budget::Multiplier(){
    double mult = personal * credit;
    std:: cout << "Multiplier: " << mult << std:: endl;
}

void Budget::Division(){
    double div = personal / credit;
    std:: cout << " Division: " << div << std:: endl;    
}

void Budget::Compare(){
     if (personal > credit){
        std:: cout << "The personal is more that credit!" << std:: endl;
    }
    else if (personal == credit) {
        std:: cout << "Budget are equal!" << std:: endl;
    }
    else {
        std:: cout << "The credit is more that personal!" << std:: endl;
    }    
}

void Budget::Print(std::ostream& os) {
    os << "Your budget is: " << personal << "," << credit << std:: endl;
}

Budget::~Budget() {
    std:: cout << "FROM DESTRUCTOR: Your budget has been deleted" << std:: endl;
}