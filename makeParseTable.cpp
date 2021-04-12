#include <iostream> 
#include <string> 
#include <map> 

using namespace std;

map<pair<string, string>, string> makeTable(){

    map<pair<string, string>, string>   table;
    
    table[{"S", "boolean"}] = "S ::= program $";
    table[{"S", "int"}] = "S ::= program $";
    table[{"S", "float"}] = "S ::= program $";
    table[{"S", "main"}] = "S ::= program $";

    table[{"program", "boolean"}] = "program ::= functions MAIN";
    table[{"program", "int"}] = "program ::= functions MAIN";
    table[{"program", "float"}] = "program ::= functions MAIN";
    table[{"program", "main"}] = "program ::= MAIN";
    table[{"program", "main"}] = "program ::= MAIN";

    table[{"functions", "boolean"}] = "functions ::= function NT1";
    table[{"functions", "int"}] = "functions ::= function NT1";
    table[{"functions", "float"}] = "functions ::= function NT1";
    table[{"functions", "main"}] = "S ::= program $";

    table[{"NT1", "boolean"}] = "NT1 ::= functions";
    table[{"NT1", "int"}] = "NT1 ::= functions";
    table[{"NT1", "float"}] = "NT1 ::= functions";
    table[{"NT1", "main"}] = "NT1 ::= ε";

    table[{"function", "boolean"}] = "function ::= type functionName ( arglist ) { statements returnStatement }";
    table[{"function", "int"}] = "function ::= type functionName ( arglist ) { statements returnStatement }";
    table[{"function", "float"}] = "function ::= type functionName ( arglist ) { statements returnStatement }";
    
    table[{"returnStatement", "return"}] = "returnStatement ::= return variable";

    table[{"arglist", "boolean"}] = "arglist ::= arg NT2";
    table[{"arglist", "int"}] = "arglist ::= arg NT2";
    table[{"arglist", "float"}] = "arglist ::= arg NT2";

    table[{"NT2", ")"}] = "NT2 ::= ε";
    table[{"NT2", ","}] = "NT2 ::= , arglist";

    table[{"arg", "boolean"}] = "arg ::= type variable";
    table[{"arg", "int"}] = "arg ::= type variable";
    table[{"arg", "float"}] = "arg ::= type variable";

    table[{"type", "boolean"}] = "type ::= boolean";
    table[{"type", "int"}] = "type ::= int";
    table[{"type", "float"}] = "type ::= float";

    table[{"MAIN", "main"}] = "MAIN ::= main ( ) { statements }";

    table[{"statements", ")"}] = "statements ::= ε";
    table[{"statements", "return"}] = "statements ::= ε";
    table[{"statements", "boolean"}] = "statements ::= statement NT3";
    table[{"statements", "int"}] = "statements ::= statement NT3";
    table[{"statements", "float"}] = "statements ::= statement NT3";
    table[{"statements", "in"}] = "statements ::= statement NT3";
    table[{"statements", "out"}] = "statements ::= statement NT3";
    table[{"statements", "if"}] = "statements ::= statement NT3";
    table[{"statements", "while"}] = "statements ::= statement NT3";

    table[{"NT3", "}"}] = "NT3 ::= ε";
    table[{"NT3", "return"}] = "NT3 ::= ε";
    table[{"NT3", "blankLine"}] = "NT3 ::= blankLine statements";

    table[{"statement", "variable"}] = "statement ::= variable := NT6";
    table[{"statement", "boolean"}] = "statement ::= declaration";
    table[{"statement", "int"}] = "statement ::= declaration";
    table[{"statement", "float"}] = "statement ::= declaration";
    table[{"statement", "in"}] = "statement ::= input";
    table[{"statement", "out"}] = "statement ::= output";
    table[{"statement", "if"}] = "statement ::= conditional";
    table[{"statement", "while"}] = "statement ::= loop";
    

    table[{"NT6", "functionName"}] = "NT6 ::= functionName ( )";
    table[{"NT6", "variable"}] = "NT6 ::= expression";
    
    table[{"input", "in"}] = "input ::= in ( variable )";

    table[{"output", "out"}] = "output ::= out ( variable )";


    table[{"declaration", "boolean"}] = "declaration ::= type varlist";
    table[{"declaration", "int"}] = "declaration ::= type varlist";
    table[{"declaration", "float"}] = "declaration ::= type varlist";

    table[{"varlist", "variable"}] = "varlist ::= variable NT4";

    table[{"NT4", "}"}] = "NT3 ::= ε";
    table[{"NT4", "return"}] = "NT3 ::= ε";
    table[{"NT4", ","}] = "NT4 ::= , varlist";
    table[{"NT4", "blankLine"}] = "NT3 ::= ε";

    table[{"expression", "variable"}] = "expression ::= variable NT5";

    table[{"NT5", ")"}] = "NT5 ::= ε";
    table[{"NT5", "}"}] = "NT5 ::= ε";
    table[{"NT5", "blankLine"}] = "NT5 ::= ε";
    table[{"NT5", "blankLine"}] = "NT5 ::= ε";
    table[{"NT5", "+"}] = "NT5 ::= arithmeticOperator variable";
    table[{"NT5", "*"}] = "NT5 ::= arithmeticOperator variable";
    table[{"NT5", "<"}] = "NT5 ::= ε";
    table[{"NT5", ">"}] = "NT5 ::= ε";
    table[{"NT5", "=="}] = "NT5 ::= ε";
    table[{"NT5", "and"}] = "NT5 ::= logicalOperator variable";
    table[{"NT5", "or"}] = "NT5 ::= logicalOperator variable";

    table[{"arithmeticOperator", "+"}] = "arithmeticOperator ::= +";
    table[{"arithmeticOperator", "*"}] = "arithmeticOperator ::= *";
    
    table[{"relationalOperator", "<"}] = "relationalOperator ::= <";
    table[{"relationalOperator", ">"}] = "relationalOperator ::= >";
    table[{"relationalOperator", "=="}] = "relationalOperator ::= ==";

    table[{"logicalOperator", "and"}] = "logicalOperator ::= and";
    table[{"logicalOperator", "or"}] = "logicalOperator ::= or";

    table[{"conditional", "if"}] = "conditional ::= if ( expression relationalOperator expression ) { statements }";

    table[{"loop", "while"}] = "loop ::= while ( expression relationalOperator expression ) { statements }";

    return table;

}

//test
int main(int argc, char const *argv[])
{

    map<pair<string, string>, string>   table = makeTable();
    cout << table[{"loop", "while"}] << '\n';
    return 0;
}
