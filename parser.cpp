#include "parser.h"
#include "makeParseTable.h"
#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <map> 
#include <stack> 
#include <algorithm> 
#include <fstream> 

using namespace std; 

vector <string> T;
const vector <string> NT = {"program", "functions", "function", "returnStatement", "argList", "arg", "type", "MAIN", "statements", "statement", "input", "output", "declaration", "varlist", "expression", "arithmeticOperator", "relationalOperator", "logicalOperator", "conditional", "loop", "NT1", "NT2", "NT3", "NT4", "NT5", "NT6"};

 // read input from a file and construct
grammar makeGrammar(string fname){
   
}

void makeParseTree(string lexerOutputFile, parseTable T, grammar G){
    
}

void PrintParseTree(parseTree* head){

}

void printStackContents(stack<string> s){
  cout << "Stack contents:\n";
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

bool parseInput(vector<string> &input, map<pair<string, string>, string> &table){
  stack<string> s;
  s.push("S");
  input.push_back("$");
  int it = 0, end = input.size();
  while(it < end){
    if(input[it] == "ε"){
      it++;
      continue;
    }
    if(s.empty()){
      cout << "Syntax error: Stack got empty before full input is parsed.\n";
      cout << "Input left to be parsed:\n";
      for(int i=it; i<end; i++){
        cout << input[i] << " ";
      }
      cout << endl;
      return false;
    }
    if(s.top() == "ε")  s.pop();
    if(table.find({s.top(), input[it]}) == table.end()){
      cout << "Syntax error: Top of stack does not match with any NT\n";
      return false;
    }
    string line = table[{s.top(), input[it]}];
    int check=0;
    vector<string> rhs;
    string lhs;
    stringstream check1(line);
    string intermediate;
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
      check++;
      if(check==1){
        lhs = intermediate;
      }
      else if(check > 2)
        rhs.push_back(intermediate);
    }
    reverse(rhs.begin(), rhs.end());
    s.pop();
    for(string toPush: rhs){
      s.push(toPush);
    }
    printStackContents(s);
    while(s.top() == input[it]){
      if(!s.empty()){
        s.pop();
        cout << endl << input[it] << " matched.\n";
        it++;
      } else {
        cout << "Syntax error: Stack got empty before full input is parsed.\n";
        return false;
      }
    }
  }
  if(!s.empty()){
    cout << "Syntax error: Stack still has some elements though input is parsed.\n";
    printStackContents(s);
    return false;
  }
  return true;
}

int main(){
  int lexer = scan();
  map<pair<string, string>, string>   table = makeTable();
  T = {"boolean", "int", "float", "{", "}", "(", ")", "+", "-", "*", ">", "<", "==", "and", "or", "if", "while"};
  map <string, int> tokenAlreadyAdded;
  vector<string> input;
  for(token t: listOfTokens){
    input.push_back(t.lexeme);
    if((t.token_no == 200 or t.token_no == 102) and tokenAlreadyAdded[t.lexeme] == 0) {
      T.push_back(t.lexeme);
      tokenAlreadyAdded[t.lexeme] = 1;
      editTableForVariables(table, t.lexeme, t.token_no);
      // cout << t.lexeme << " ";
    }
  }

  cout << "\nInput to parser: ";
  for(string i: input){
    cout << i << " ";
  }
  cout << endl;
  if(!parseInput(input, table))
    cout << "\nParsing stopped due to syntax error.\n";
  return 0;
}
