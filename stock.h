//*****************************************************************************************************
//
//		File:					stock.h
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #9
//
//		Due:					11/17/2025	
//			
//*****************************************************************************************************
#ifndef STOCK_H
#define STOCK_H

#include<iostream>
#include<string>

//*****************************************************************************************************
class Stock
{
    private:
        std::string companyName;
        std::string stockSymbol;
        double price;

    public:
        Stock(const std::string& n = "", const std::string& s = "", double p = 0.0);
        Stock(const Stock& s);
        void display() const;
        std::string getName() const;
        std::string getSymbol() const;
        double getPrice() const;
        bool operator==(const Stock& rhs) const;
        bool operator!=(const Stock& rhs) const;
        bool operator>(const Stock& rhs) const;
        bool operator<(const Stock& rhs) const;
        int hash(int size) const;
};

std::ostream& operator<<(std::ostream& os, const Stock& s);
std::istream& operator>>(std::istream& input, Stock& s);

//*****************************************************************************************************
#endif