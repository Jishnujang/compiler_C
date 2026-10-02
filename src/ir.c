#include <stdio.h>
#include <stdlib.h>

#include "ir.h"

IRInstruction *ir_generate(int value)
{
    IRInstruction *ir = malloc(sizeof(IRInstruction));

    if (ir == NULL) {
        return NULL;
    }

    ir->type = IR_GIVE;
    ir->value = value;

    return ir;
}

void ir_print(IRInstruction *ir)
{
    if (ir == NULL) {
        return;
    }

    if (ir->type == IR_GIVE) {
        printf("IR_GIVE %d\n", ir->value);
    }
}

void ir_free(IRInstruction *ir)
{
    free(ir);
}