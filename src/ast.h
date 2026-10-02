#ifndef AST_H
#define AST_H

typedef enum {
    AST_GIVE,
    AST_NUMBER
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    int value;

    struct ASTNode *child;
} ASTNode;

ASTNode *ast_create_number(int value);
ASTNode *ast_create_give(ASTNode *child);

void ast_print(ASTNode *node, int depth);
void ast_free(ASTNode *node);

#endif