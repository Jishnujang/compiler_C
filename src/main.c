
#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "ast.h"
#include "semantic.h"
#include "ir.h"

int main(int argc, char *argv[])
{
    /* Check command-line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }

    /* Open source file */
    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    /* Find file size */
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    /* Allocate memory for source */
    char *source = malloc(size + 1);

    if (source == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    /* Read source file */
    size_t bytes_read = fread(source, 1, size, fp);

    if (bytes_read != (size_t)size) {
        fprintf(stderr, "Error: could not read source file\n");
        free(source);
        fclose(fp);
        return 1;
    }

    source[size] = '\0';

    fclose(fp);

    /*
     * ------------------------------------------------
     * Stage 2/3: Lexer + Parser
     * ------------------------------------------------
     */

    int position = 0;

    ASTNode *root = parse_statement(source, &position);

    if (root == NULL) {
        printf("Parsing failed\n");

        free(source);
        return 1;
    }

    printf("Parsing successful\n");

    /*
     * ------------------------------------------------
     * Stage 4: AST
     * ------------------------------------------------
     */

    printf("\nAST:\n");
    ast_print(root, 0);

    /*
     * ------------------------------------------------
     * Stage 5: Semantic Analysis
     * ------------------------------------------------
     */

    printf("\nSemantic Analysis:\n");

    if (!semantic_check(root)) {
        printf("Semantic analysis failed\n");

        ast_free(root);
        free(source);

        return 1;
    }

    printf("Semantic analysis successful\n");

    /*
     * ------------------------------------------------
     * Stage 6: Intermediate Representation (IR)
     * ------------------------------------------------
     */

    printf("\nIR:\n");

    IRInstruction *ir = ir_generate(root->child->value);

    if (ir == NULL) {
        fprintf(stderr, "Error: could not generate IR\n");

        ast_free(root);
        free(source);

        return 1;
    }

    ir_print(ir);

    /*
     * ------------------------------------------------
     * Cleanup
     * ------------------------------------------------
     */

    ir_free(ir);
    ast_free(root);
    free(source);

    return 0;
}
