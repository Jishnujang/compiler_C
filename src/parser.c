#include <stdio.h>

#include "parser.h"

ASTNode *parse_statement(const char *source, int *position)
{
    Token token;

    /* Expect GIVE */
    token = get_next_token(source, position);

    if (token.type != TOKEN_GIVE) {
        fprintf(stderr, "Parser error: expected 'give'\n");
        return NULL;
    }

    /* Expect NUMBER */
    token = get_next_token(source, position);

    if (token.type != TOKEN_NUMBER) {
        fprintf(stderr, "Parser error: expected number\n");
        return NULL;
    }

    int value = token.value;

    /* Expect SEMICOLON */
    token = get_next_token(source, position);

    if (token.type != TOKEN_SEMICOLON) {
        fprintf(stderr, "Parser error: expected ';'\n");
        return NULL;
    }

    /* Build AST */

    ASTNode *number_node = ast_create_number(value);

    if (number_node == NULL) {
        fprintf(stderr, "Error: could not create number node\n");
        return NULL;
    }

    ASTNode *give_node = ast_create_give(number_node);

    if (give_node == NULL) {
        ast_free(number_node);
        fprintf(stderr, "Error: could not create give node\n");
        return NULL;
    }

    return give_node;
}