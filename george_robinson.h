#ifndef GEORGE_ROBINSON_H
#define GEORGE_ROBINSON_H
#include "conteiner_object.h"

class george_robinson:conteiner_object
{
public:
    george_robinson();
    ~george_robinson();
    void run_action(en_solution_type s_type);
};

#endif // GEORGE_ROBINSON_H
