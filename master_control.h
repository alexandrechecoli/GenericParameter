#ifndef MASTER_CONTROL_H
#define MASTER_CONTROL_H

#include <map>
#include "conteiner_object.h"
#include <string>
#include <iostream>


class master_control
{
public:

    enum en_solver
    {
        GR,
        GLPK
    };

    master_control();
    ~master_control();
    static void run_(en_solver solver);
    static std::map<std::string,conteiner_object *> obj_cash;
    static int a;

};


#endif // MASTER_CONTROL_H
