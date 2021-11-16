#include <iostream>
#include "Grammar.h"
#include "Helper.h"
#include <assert.h>
#include "CustomTable.h"

int main()
{
    //Grammar* grammar = new Grammar("g1.in");
    Grammar* grammar = new Grammar("g2.in");
    grammar->readGrammar();
    if (grammar->getEncounteredError() != "") {
        std::cout << grammar->getEncounteredError();
        return 0;
    }
    grammar->displayNonTerminals();
    grammar->displayTerminals();
    grammar->displayProductions();
    grammar->displayStartingSymbol();
    std::cout << "Productions for S: \n";
    grammar->displayProductions(grammar->getProductionsForNonTerminal("S"));
    std::cout << "Productions for A: \n";
    grammar->displayProductions(grammar->getProductionsForNonTerminal("A"));
    std::cout << "Productions for B: \n";
    grammar->displayProductions(grammar->getProductionsForNonTerminal("B"));
    std::cout << "Productions for C: \n";
    grammar->displayProductions(grammar->getProductionsForNonTerminal("C"));

    std::cout << "Is CFG?\n";
    if (grammar->checkCFG()) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }

    /*
    // Table - addRow test
    CustomTable* ct1 = new CustomTable();
    ct1->addRow("S", 0, 0);
    ct1->addRow("a", 1, 0);
    ct1->addRow("S", 1, 2);
    ct1->addRow("b", 1, 3);
    ct1->addRow("S", 1, 4);
    ct1->addRow("c", 3, 0);
    ct1->addRow("c", 5, 0);
    ct1->displayTable();

    // Table - addProduction test
    std::vector<Production> productions = grammar->getProductions();
    CustomTable* ct2 = new CustomTable();
    ct2->addRow(grammar->getStartingSymbol(), 0, 0);
    ct2->addProduction(0, productions[0]);
    ct2->displayTable();
    */
    return 0;
}
