#include <stdio.h>

#include "semantic.h"

int semantic_check(ASTNode *node)
{
    if (node == NULL) {
        fprintf(stderr, "Semantic error: empty AST\n");
        return 0;
    }

    if (node->type != AST_GIVE) {
        fprintf(stderr, "Semantic error: expected GIVE node\n");
        return 0;
    }

    if (node->child == NULL) {
        fprintf(stderr, "Semantic error: GIVE has no value\n");
        return 0;
    }

    if (node->child->type != AST_NUMBER) {
        fprintf(stderr, "Semantic error: GIVE requires a number\n");
        return 0;
    }

    return 1;
}