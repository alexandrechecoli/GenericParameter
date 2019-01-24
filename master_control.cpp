#include "master_control.h"

int master_control::a;
std::map<std::string,conteiner_object *> obj_cash;


master_control::master_control()
{

}

master_control::~master_control()
{

}

void master_control::run_(master_control::en_solver solver)
{
    std::cout << "master_control_run_()";
}

