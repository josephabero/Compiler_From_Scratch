#pragma once

#include "Stmt.hpp"
#include "Id.hpp"
#include "Expr.hpp"
#include "../symbols/Type.hpp"
#include <assert.h>
using namespace std;

class Set : public Stmt
{
public:
	Set(Id *i, Expr *x): id(i), expr(x)
	{
		// assert(!(check(id->type, expr->type) == Type::Null()));
		// Type of id and expr should be numeric or boolean
		ASSERT(!(check(id->type, expr->type) == Type::Null()), "TYPE ERROR");

		cout << "push_back from Set" << endl;
		cout << "Set1: " << id->op.value << endl;
		cout << "Set2: " << expr->op.value << endl;
		children.push_back(id);
		children.push_back(expr);
	}

	std::string getNodeStr() { return "ASSIGN"; };

	Type check(Type p1, Type p2)
	{
		if(Type::numeric(p1) && Type::numeric(p2)) 			return p2;
		else if(p1 == Type::Bool() && p2 == Type::Bool())	return p2;
		else if(Type::numeric(p1) || p1 == Type::Bool()) return p1;
		else if(Type::numeric(p2) || p2 == Type::Bool()) return p2;
		else												return Type::Null();
	}

	Id *id;
	Expr *expr;
};