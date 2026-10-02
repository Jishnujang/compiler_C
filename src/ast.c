#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

ASTNode *ast_create_number(int value)
{
    ASTNode *node = malloc(sizeof(ASTNode));

    if (node == NULL) {
        return NULL;
    }

    node->type = AST_NUMBER;
    node->value = value;
    node->child = NULL;

    return node;
}

ASTNode *ast_create_give(ASTNode *child)
{
    ASTNode *node = malloc(sizeof(ASTNode));

    if (node == NULL) {
        return NULL;
    }

    node->type = AST_GIVE;
    node->value = 0;
    node->child = child;

    return node;
}

void ast_print(ASTNode *node, int depth)
{
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    if (node->type == AST_GIVE) {
        printf("GIVE\n");
    }
    else if (node->type == AST_NUMBER) {
        printf("NUMBER: %d\n", node->value);
    }

    ast_print(node->child, depth + 1);
}

void ast_free(ASTNode *node)
{
    if (node == NULL) {
        return;
    }

    ast_free(node->child);
    free(node);
}