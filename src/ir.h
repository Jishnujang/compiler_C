#ifndef IR_H
#define IR_H

typedef enum {
    IR_GIVE
} IRType;

typedef struct {
    IRType type;
    int value;
} IRInstruction;

IRInstruction *ir_generate(int value);
void ir_print(IRInstruction *ir);
void ir_free(IRInstruction *ir);

#endif