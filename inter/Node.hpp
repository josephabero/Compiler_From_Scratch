#pragma once

#include "../lexer/lexer.hpp"
#include <vector>

class Node
{
public:
	int lexline = 0;
	std::vector<Node*> children;
	Node() 
	{
		lexline = Lexer::line;
	}

	std::vector<Node*> getChildren() { return children; }

	virtual std::string getNodeStr() { return ""; };
};