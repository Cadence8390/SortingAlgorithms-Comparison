//*****************************************************************************************************
//
//		File:					driver.cpp
//
//		Student:				Cadence Seim
//
//		Assignment:				Assignmnt #9
//
//		Due:					11/17/2025		
//			
//*****************************************************************************************************

#include "sortedList.h"
#include "stock.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

//*****************************************************************************************************

int main()
{

    SortedList<Stock> stockList(10);

    ifstream fin("Stock.txt");
    if (!fin)
    {
        cout << "Error: Could not open stocks.txt\n";
        return 1;
    }

    Stock temp;
    while (fin >> temp)
        stockList.insert(temp);

    fin.close();



    cout << "\n================ ORIGINAL LIST ================\n";
    stockList.display();

    cout << "\n================ RANDOMISED LIST ================\n";
    stockList.randomise();
    stockList.display();

    cout << "\n================ SELECTION SORT ASCENDING ================\n";
    auto startSSA = high_resolution_clock::now();
    stockList.selectionSortA();
    auto stopSSA = high_resolution_clock::now();
    auto durationSSA = duration_cast<microseconds>(stopSSA - startSSA);
    stockList.display();
    cout << "Time spent: " << durationSSA.count() << " microseconds\n";


    cout << "\n================ RANDOMISED AGAIN ================\n";
    stockList.randomise();
    stockList.display();

    cout << "\n================ SELECTION SORT DESCENDING ================\n";
    auto startSSD = high_resolution_clock::now();
    stockList.selectionSortD();
    auto stopSSD = high_resolution_clock::now();
    auto durationSSD = duration_cast<microseconds>(stopSSD - startSSD);
    stockList.display();
    cout << "Time spent: " << durationSSD.count() << " microseconds\n";


    cout << "\n================ RANDOMISED AGAIN ================\n";
    stockList.randomise();
    stockList.display();

    cout << "\n================ QUICK SORT ASCENDING ================\n";
    auto startQSA = high_resolution_clock::now();
    stockList.quickSortA();
    auto stopQSA = high_resolution_clock::now();
    auto durationQSA = duration_cast<microseconds>(stopQSA - startQSA);
    stockList.display();
    cout << "Time spent: " << durationQSA.count() << " microseconds\n";


    cout << "\n================ RANDOMISED AGAIN ================\n";
    stockList.randomise();
    stockList.display();

    cout << "\n================ QUICK SORT DESCENDING ================\n";
    auto startQSD = high_resolution_clock::now();
    stockList.quickSortD();
    auto stopQSD = high_resolution_clock::now();
    auto durationQSD = duration_cast<microseconds>(stopQSD - startQSD);
    stockList.display();
    cout << "Time spent: " << durationQSD.count() << " microseconds\n";


    cout << "\n================ RANDOMISED AGAIN ================\n";
    stockList.randomise();
    stockList.display();

    cout << "\n================ HEAP SORT ASCENDING ================\n";
    auto startHSA = high_resolution_clock::now();
    stockList.heapSortA();
    auto stopHSA = high_resolution_clock::now();
    auto durationHSA = duration_cast<microseconds>(stopHSA - startHSA);
    stockList.display();
    cout << "Time spent: " << durationHSA.count() << " microseconds\n";


    cout << "\n================ RANDOMISED AGAIN ================\n";
    stockList.randomise();
    stockList.display();

    cout << "\n================ HEAP SORT DESCENDING ================\n";
    auto startHSD = high_resolution_clock::now();
    stockList.heapSortD();
    auto stopHSD = high_resolution_clock::now();
    auto durationHSD = duration_cast<microseconds>(stopHSD - startHSD);
    stockList.display();
    cout << "Time spent: " << durationHSD.count() << " microseconds\n";


    cout << "\n================ END ================\n";

    return 0;
}