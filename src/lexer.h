#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_GIVE,
    TOKEN_NUMBER,
    TOKEN_SEMICOLON,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

Token get_next_token(const char *source, int *position);

#endif