#include <stdlib.h>
#include "frame.h"

struct frame *constructor_frame(int index_frame, char *name, enum type_frame type_frame, struct instruction **instructions,
                           int number_instructions, int number_args) {
    struct frame *frame = malloc(sizeof(struct frame));
    frame->index_frame = index_frame;
    frame->name = name;
    frame->type_frame = type_frame;
    frame->number_args = number_args;

    frame->work_stack = calloc(1, sizeof(var) * WORK_STACK_SIZE_MAX);
    frame->index_first_element_work_stack = -1;
    frame->is_work_stack_element_object = calloc(1, sizeof(bool) * WORK_STACK_SIZE_MAX);

    frame->local_pool = calloc(1, sizeof(var) * LOCAL_POOL_SIZE_MAX);
    frame->is_local_pool_element_object = calloc(1, sizeof(bool) * LOCAL_POOL_SIZE_MAX);

    frame->instructions = instructions;
    frame->number_instructions = number_instructions;

    return frame;
}

void destructor_frame(struct frame *frame) {
    free(frame->work_stack);
    free(frame->is_work_stack_element_object);
    free(frame->local_pool);
    free(frame->is_local_pool_element_object);
    free(frame->name);

    for (int i = 0; i < frame->number_instructions; ++i) {
        destructor_instruction(frame->instructions[i]);
    }
    free(frame->instructions);
    free(frame);
}

void execute_frame(struct frame *frame) {
    for (int i = 0; i < frame->number_instructions; ++i) {
        int *index_instruction = execute_instruction(*frame->instructions[i]);
        if (index_instruction != NULL) {
            i = *index_instruction - 1;
            free(index_instruction);
        }
    }
}