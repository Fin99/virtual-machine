//
// Created by Fin on 04.11.2018.
//

#ifndef VM_INSTRUCTION_H

#define VM_INSTRUCTION_H

struct Frame;

typedef enum {
    ALOAD,
    ILOAD,

    ICONST,
    ISTORE,

    INVOKEVIRTUAL,

    IADD,

    RETURN,
    IRETURN
} TypeInstruction;


typedef struct {
    TypeInstruction type;
    int numberLine;
    int arg;
    struct Frame *frameArg;
} Instruction;

void execute(struct Frame*, Instruction*);

#endif //VM_INSTRUCTION_H