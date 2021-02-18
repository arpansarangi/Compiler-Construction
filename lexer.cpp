#include "Token.h"
#include <iostream> 
#include <string> 
#include <fstream> 

#define call(function) function(line, &pos, lineNumber); break

using namespace std; 

const string keywords[] = {"main", "void", "boolean", "int", "float", "string", "while", "if", "and", "or", "return", "in", "out"};

void error(char ch){
  cout << "Lexical Error: \"" << ch << "\" is not a part of the character set of the language, skipping..." << endl;
}

void error(string lexeme, string line, int *pos){
  cout << "Lexical Error: \"" << lexeme << "\" did not match any regular expression, skipping to the next whitespace..." << endl;
  while(line[(*pos)] and line[(*pos)]!=' ')  (*pos)++;
}

void getComment(string line, int *pos, int lineNumber){
  cout << "handling comment" << endl;
  while(line[(*pos)]) (*pos)++;
}

void getArithmeticOperator(string line, int *pos, int lineNumber){
  if(line[(*pos)] == '+') {
    printToken(newToken(101, "+", lineNumber));
  }
  (*pos)++;
}

void getRelationalOperator(string line, int *pos, int lineNumber){
//   cout << "handling relational operator" << endl;
  char ch =  line[*pos]; 
  token temp;
  if (ch == '<'){
    temp = newToken(123, "<", lineNumber);
  }
  else if (ch == '>'){
    temp = newToken(124, ">", lineNumber);
  }
  else if (ch == '='){
    (*pos)++;
    temp = newToken(125, "==", lineNumber);
  }
  (*pos)++;
  printToken(temp);
}

void getName(string line, int *pos, int lineNumber){
  cout << "handling name   ";
  (*pos)++;
}

void getNumber(string line, int *pos, int lineNumber){
  cout << "handling number" << endl;
  (*pos)++;
}

void getString(string line, int *pos, int lineNumber){
  cout << "handling string" << endl;
  (*pos)++;
}

void getAssignmentOperator(string line, int *pos, int lineNumber){
  cout << "handling assignment operator" << endl;
  (*pos)++;
}

void getDelimiter(string line, int *pos, int lineNumber){
  cout << "handling delimiter" << endl;
  (*pos)++;
}

int main(){
  ifstream fin;
  fin.open("tests/1in.txt");
  freopen("tests/1out-lexer.txt","w",stdout);
  string line;
  int lineNumber = 0;
  while (getline(fin, line)) { 
    lineNumber++;
    cout << "line" << lineNumber << endl;
    int pos = 0;
    while(line[pos]){
      if(line[pos]<='9' and line[pos]>='0'){
        getNumber(line, &pos, lineNumber);
      }
      else if((line[pos]>='a' and line[pos]<='z') or (line[pos]>='A' and line[pos]<='Z')){
        getName(line, &pos, lineNumber);     //variable name, function name etc
      }
      else{
        switch(line[pos]){
          case ' ':  
          case '\t': pos++; break;
          case '/':  call(getComment);
          case '+':
          case '*':  call(getArithmeticOperator);
          case '<':
          case '>':
          case '=':  call(getRelationalOperator);
          case ':':  call(getAssignmentOperator);
          case '"':  call(getString);
          case '(':
          case ')':
          case '{':
          case '}':
          case ',':  call(getDelimiter);
          //some other cases
          default:   error(line[pos]); pos++; break;  //error - character is invalid
        }
      }
    }
  }
  fin.close();
  return 0;
}
