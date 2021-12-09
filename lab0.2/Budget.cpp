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

std::istream& operator >> (std::istream& is, Budget &object) {
    std:: cout << "Please enter your budget data: " << std:: endl;
    is >>  object.personal >> object.credit;
    if ((object.personal <= 0.0) || (object.credit <= 0.0)) {
        std:: cout << "Invalind input. Enter again!" << std:: endl;
        is >> object.personal >> object.credit;
    }
    std:: cout << "The budget has been created via istream" << std:: endl;
    return is;
}

Budget Budget::operator + (const Budget &other) {
    this->personal += other.personal;
    this->credit += other.credit;
    return *this;
}

Budget Budget::operator - (const Budget &other) {
    this->personal -= other.personal;
    this->credit -= other.credit;
    return *this;
}

void Budget::Rouding() {
    this->personal = round (this->personal * 100.0) / 100.0;
    this->credit = round (this->credit * 100.0) / 100.0;
    std:: cout << "Rouding: " << this->personal << " " << this->credit << std:: endl;
}

bool Budget::operator < (const Budget &other) {
    if ((personal < other.personal) || (personal == other.personal && credit < other.credit)) {
        return true;
    }
    else {
        return false;
    }
}

bool Budget::operator > (const Budget &other) {
    if ((personal > other.personal) || (personal == other.personal && credit > other.credit)) {
        return true;
    }
    else {
        return false;
    }
}

void Budget::Difference() {
    double differ = personal - credit;
    std:: cout << "Difference: " << differ << std:: endl;
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

std::ostream& operator << (std::ostream& os, Budget &object) {
    os << object.personal << ";" << object.credit<< std:: endl;
    return os;
}

bool Budget::operator == (const Budget &object) {
    if (personal == object.personal && credit == object.credit) {
        return true;
    }
    return false;
}

Budget::~Budget() {
    std:: cout << "FROM DESTRUCTOR: Your budget has been deleted" << std:: endl;
}