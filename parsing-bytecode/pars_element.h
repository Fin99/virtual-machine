//
// Created by fin on 29.01.19.
//

#ifndef VIRTUALMACHINE_PARS_ELEMENT_H
#define VIRTUALMACHINE_PARS_ELEMENT_H

enum type_parse_element {
    CLASS,
    FUNCTION
};
typedef enum type_parse_element type_parse_element_t;

struct arg {
    char *name_arg;
    char *value_arg;
};
typedef struct arg arg_t;

struct pars_element {
    type_parse_element_t type_parse_element;
    arg_t *pre_args;
    arg_t *args;
};
typedef struct pars_element pars_element_t;

pars_element_t *pars_text(char *text);

void destructor_pars_element(pars_element_t *pars_element);

#endif //VIRTUALMACHINE_PARS_ELEMENT_H
