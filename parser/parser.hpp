#pragma once

#include "../lexer/lexer.hpp"
#include "../lexer/token.hpp"
#include "../inter/Prog.hpp"

class Parser
{
public:
	Parser(Lexer lexer) : lexer(lexer) 
	{
		move();
	}

	void error(std::string errorMessage);

	void move();
	void match(std::string t);
	
	Prog program();
	Block block();
	void decls();
	void type();

private:
	Lexer lexer;
	Token look;
};