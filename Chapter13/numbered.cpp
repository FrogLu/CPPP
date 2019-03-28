#include "pch.h"
#include "numbered.h"

int numbered::count = 0;

numbered::numbered()
{
    ++count;
    mysn=count;
}

numbered::numbered(const numbered& num)
{
    ++count;
    mysn = count;
}

numbered numbered::operator=(const numbered& rhs)
{
    ++count;
    mysn = count;

    return *this;
}




numbered::~numbered()
{
}
