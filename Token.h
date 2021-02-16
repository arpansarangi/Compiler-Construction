#include<bits/stdc++.h> 
using namespace std; 

struct token
{ 
    int token_no;
    string lexeme;
    int line_no;
};

token newToken(int a, string s, int line)
{
    token new_token;
    new_token.token_no = a;
    new_token.lexeme = s;
    new_token.line_no = line;
    return new_token;
}

void print_token(token temp)
{
    cout << "Token "<< temp.token_no <<", string "<< temp.lexeme <<", line number "<<temp.line_no << "\n";
}
