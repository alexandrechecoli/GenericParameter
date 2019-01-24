#ifndef CONTEINER_OBJECT_H
#define CONTEINER_OBJECT_H
#include <map>

class conteiner_object
{
public:

    enum en_solution_type
    {
      GR,
      SLICE_AND_FILL
    };

    conteiner_object();
    virtual ~conteiner_object();
    virtual void run_action(en_solution_type s_type) = 0;

};

#endif // CONTEINER_OBJECT_H
