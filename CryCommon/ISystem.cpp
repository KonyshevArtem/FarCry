#include "ISystem.h"

ISystem* s_System;

ISystem* GetISystem()
{
    return s_System;
}

void SetISystem(ISystem* system)
{
    s_System = system;
}