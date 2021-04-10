#include "token.h"
#include <iostream> 
using namespace std; 

struct node
{
	token *t;
};

// not sure about implementation yet
struct grammar
{

};

// not sure about implementation yet
struct parseTable
{
    
};

// not sure about implementation yet
struct FF
{
    
};


struct parseTree
{
    node* n;

	int value;
	int rule;
	struct parsetree *right;
	struct parsetree *parent;
	struct parsetree *left;
	
};

