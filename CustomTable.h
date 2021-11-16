#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Grammar.h"

struct Row {
	int index;
	std::string information;
	int parent;
	int leftSibling;
};

class CustomTable
{
private:
	std::vector<Row> rows;
	int currentIndex = 1;
public:
	void addRow(std::string information, int parent, int leftSibling);
	void addProduction(int parent, Production p);
	void displayTable();
};

