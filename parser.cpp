#include "parser.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <fstream> 

using namespace std; 

vector <string> T;
const vector <string> NT = {"program", "functions", "function", "returnStatement", "argList", "arg", "type", "MAIN", "statements", "statement", "input", "output", "declaration", "varlist", "expression", "arithmeticOperator", "relationalOperator", "logicalOperator", "conditional", "loop", "NT1", "NT2", "NT3", "NT4", "NT5", "NT6"};

 // read input from a file and construct
grammar makeGrammar(string fname){
   
}

// read input from a file and construct
FF getFirstAndFollows(string fname){
    
}

// read input from a file and construct or use first and follows set depending on requirements
parseTable makeTable(FF F){
    
}

void makeParseTree(string lexerOutputFile, parseTable T, grammar G){
    
}

void PrintParseTree(parseTree* head){

}

int main(){
  int lexer = scan();
  T = {"boolean", "int", "float", "{", "}", "(", ")", "+", "-", "*", ">", "<", "==", "and", "or", "if", "while"};
  map <string, int> tokenAlreadyAdded;
  for(token t: listOfTokens){
    if(t.token_no == 200 and tokenAlreadyAdded[t.lexeme] == 0) {
      T.push_back(t.lexeme);
      tokenAlreadyAdded[t.lexeme] = 1;
      // cout << t.lexeme << " ";
    }
  }
  return 0;
}
