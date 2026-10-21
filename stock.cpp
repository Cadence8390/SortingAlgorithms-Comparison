//*****************************************************************************************************
//
//		File:					stock.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #9
//
//		Due:					11/17/2025		
//			
//*****************************************************************************************************

#include "stock.h"

//*****************************************************************************************************
Stock::Stock(const std::string& n, const std::string& s, double p)
{
    companyName = n;
    stockSymbol = s;
    price = p;
}

//*****************************************************************************************************
Stock::Stock(const Stock& s)
{
    companyName = s.companyName;
    stockSymbol = s.stockSymbol;
    price = s.price;
}

//*****************************************************************************************************

void Stock::display() const
{
    std::cout << *this;
}

//*****************************************************************************************************
std::string Stock::getName() const
{
    return companyName;
}

//*****************************************************************************************************
std::string Stock::getSymbol() const
{
    return stockSymbol;
}

//*****************************************************************************************************
double Stock::getPrice() const
{
    return price;
}

//*****************************************************************************************************
bool Stock::operator==(const Stock& rhs) const
{
    return (this->stockSymbol == rhs.stockSymbol);
}

//*****************************************************************************************************
bool Stock::operator!=(const Stock& rhs) const
{
    return !(this->stockSymbol == rhs.stockSymbol);
}

//*****************************************************************************************************
bool Stock:: operator>(const Stock& rhs) const
{
    return (this->stockSymbol > rhs.stockSymbol);
}

//*****************************************************************************************************
std::ostream& operator<<(std::ostream& os, const Stock& s)
{
    os << "Company: " << s.getName() << std::endl;
    os << "Stock Symbol: " << s.getSymbol() << std::endl;
    os << "Price: $" << s.getPrice() << std::endl;
    os << std::endl;

    return os;
}

//*****************************************************************************************************
bool Stock:: operator<(const Stock& rhs) const
{
    return (this->stockSymbol < rhs.stockSymbol);
}

//*****************************************************************************************************
int Stock::hash(int size)const
{
    int sum = 0;

    for (int i = 0; i < stockSymbol.size(); i++)
    {
        sum += stockSymbol[i];
    }

    return (sum % size);
}

//*****************************************************************************************************
std::istream& operator>>(std::istream& input, Stock& s)
{
    std::string name;
    std::string symbol;
    std::string skip;
    double price = 0.0;
    bool success = true;

    if (!std::getline(input, name))
        success = false;

    if (success && !std::getline(input, symbol))
        success = false;

    if (success && !(input >> price))
        success = false;

    std::getline(input, skip);

    if (success)
        s = Stock(name, symbol, price);

    return input;
}

//*****************************************************************************************************