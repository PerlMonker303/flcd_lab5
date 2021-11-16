#include "CustomTable.h"

void CustomTable::addRow(std::string information, int parent, int leftSibling) {
	Row row;
	row.index = this->currentIndex;
	row.information = information;
	row.parent = parent;
	row.leftSibling = leftSibling;
	this->currentIndex++;
	this->rows.push_back(row);
}

void CustomTable::addProduction(int parent, Production p) {
	int leftSibling = 0;
	for (int i = 0; i < p.RHS.size(); i++) {
		this->addRow(p.RHS[i], parent, leftSibling);
		leftSibling++;
	}
}

void CustomTable::displayTable() {
	std::cout << "[Table ...]\n";
	std::cout << "Id  Info  Parent  Left-Sibling\n";
	for (int i = 0; i < this->rows.size(); i++) {
		Row row = this->rows[i];
		std::cout << row.index << "  ";
		if (row.index <= 9) {
			std::cout << ' ';
		}
		std::cout << row.information << "  ";
		std::cout << row.parent << "  ";
		std::cout << row.leftSibling << '\n';
	}
	std::cout << "[... done]\n";
}
