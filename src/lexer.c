#include <ctype.h>
#include <string.h>

#include "lexer.h"

Token get_next_token(const char *source, int *position)
{
    Token token;

    token.type = TOKEN_UNKNOWN;
    token.value = 0;

    /* Skip spaces */
    while (isspace(source[*position])) {
        (*position)++;
    }

    /* End of source */
    if (source[*position] == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

    /* Keyword: give */
    if (strncmp(&source[*position], "give", 4) == 0) {
        *position += 4;
        token.type = TOKEN_GIVE;
        return token;
    }

    /* Number */
    if (isdigit(source[*position])) {
        int value = 0;

        while (isdigit(source[*position])) {
            value = value * 10 + (source[*position] - '0');
            (*position)++;
        }

        token.type = TOKEN_NUMBER;
        token.value = value;

        return token;
    }

    /* Semicolon */
    if (source[*position] == ';') {
        (*position)++;
        token.type = TOKEN_SEMICOLON;
        return token;
    }

    /* Unknown character */
    (*position)++;

    return token;
}