#ifndef TOKEN_H
#define TOKEN_H 
#include <iostream> 
#include <vector>
using namespace std; 

struct token
{ 
    int token_no;
    string lexeme;
    int line_no;
};

inline vector<token> listOfTokens;
int scan();

static token newToken(int a, string s, int line)
{
    token new_token;
    new_token.token_no = a;
    new_token.lexeme = s;
    new_token.line_no = line;
    return new_token;
}

#endif
