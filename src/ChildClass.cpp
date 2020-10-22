#include "ChildClass.hpp"

BaseClass::BaseClass(void) :
    m_value(32),
    m_other(1.0f)
{
}

void BaseClass::calculate(void)
{
    m_value *= 2;
    m_other = (double)25.2223;
}

