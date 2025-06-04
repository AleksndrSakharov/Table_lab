#include<iostream>
#include "ArrayTable.h"
#include "DatValue.h"
#include "Marks.h"
#include "ScanTable.h"
#include "Table.h"
#include "TableTestKit.h"
#include "SortTable.h"
#include "TabRecord.h"
#include "TreeTable.h"

int main(){
    ScanTable table(10);  
    TableTestKit tester(table);
    tester.InitRandom();
    
    tester.FillTable(10);  

    std::cout << "Initial table:\n";
    tester.PrintTable();

    std::cout << "\nSearching for records:\n";
    tester.FindRecord();

    std::cout << "\nRemoving records:\n";
    tester.RemoveRecord();

    std::cout << "\nTable after removals:\n";
    tester.PrintTable();

    std::cout << "\nFinal table metrics:\n";
    tester.PrintMetrics();


    return 0;
}