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
  cout << "Stack contents:\t";
  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

bool checkIfStackEmpty(stack<string> &s, vector<string> &input, int it){
  int end = input.size();
  if(s.empty()){
    cout << "Syntax error: Stack got empty before full input is parsed.\n";
    cout << "Input left to be parsed:\n";
    for(int i=it; i<end; i++){
      cout << input[i] << " ";
    }
    cout << endl;
    return true;
  }
}

bool parseInput(vector<string> &input, map<pair<string, string>, string> &table, map<pair<string, string>, vector<string> >  &otherEntries, map <string, int> &tokenAlreadyAdded){
  stack<string> s;
  s.push("S");
  input.push_back("$");
  int it = 0, end = input.size();

  while(it < end){
    if(checkIfStackEmpty(s, input, it)) return false;

    if(it == end-1){
      if(s.top() == "$" and input[it] == "$"){
        s.pop();
        it++;
        return true;
      }
    }
    if(input[it] == "`"){
      it++;
      continue;
    }


    if(s.top() == "`")  s.pop();
    if(checkIfStackEmpty(s, input, it)) return false;

    string line = "";
    if(table.find({s.top(), input[it]}) == table.end()){
      string nextVariable = "";
      for(int i=it; i<end; i++){
        if(tokenAlreadyAdded.find(input[i]) != tokenAlreadyAdded.end()){
          nextVariable = input[i];
          break;
        }
      }
      if(nextVariable == ""){
        cout << "Syntax error: No corresponding entry found in the parse table.\n";
        return false;
      }
      for(string i: otherEntries[{s.top(), input[it]}]){
        int n = nextVariable.length(), n1 = i.length();
        for(int j=0; j<n1-n-1; j++){
          if((i.substr(j, n+1) == " " + nextVariable) or (i.substr(j, n+1) == nextVariable + " ")){
        // for(int j=0; j<n1-n; j++){
        //     if(i.substr(j, n) == nextVariable){
            line = i;
            goto g;
          }
        }
      }
      g:{}
    }

    if(line == "")  line = table[{s.top(), input[it]}];
    if(line == "") {
      cout << "Syntax error: No corresponding entry found in the parse table.\n";
      return false;
    }
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
    if(checkIfStackEmpty(s, input, it)) return false;
    printStackContents(s);
    if(s.top() == "`")  s.pop();

    while(it < end and s.top() == input[it]){
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
  map<pair<string, string>, vector<string> >  otherEntries;
  T = {"boolean", "int", "float", "{", "}", "(", ")", "+", "-", "*", ">", "<", "==", "and", "or", "if", "while"};
  map <string, int> tokenAlreadyAdded;
  vector<string> input;
  for(token t: listOfTokens){
    input.push_back(t.lexeme);
    if((t.token_no == 200 or t.token_no == 102) and tokenAlreadyAdded[t.lexeme] == 0) {
      T.push_back(t.lexeme);
      tokenAlreadyAdded[t.lexeme] = 1;
      editTableForVariables(table, t.lexeme, t.token_no);
      addOtherEntries(otherEntries, t.lexeme, t.token_no);
      // cout << t.lexeme << " ";
    }
  }

  // for(auto i: tokenAlreadyAdded){
  //   cout<<i.first<<" ";
  // }
  // cout<<endl;
  cout << "\nInput to parser: ";
  for(string i: input){
    cout << i << " ";
  }
  cout << endl;
  if(!parseInput(input, table, otherEntries, tokenAlreadyAdded))
    cout << "\nParsing stopped due to syntax error.\n";
  return 0;
}
