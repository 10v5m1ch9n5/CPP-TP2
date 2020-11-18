#include <iostream>
#include "trajet_simple.h"
int main()
{
    TrajetSimple ts("Paris", "Lyon", "TGV");
    ts.ToString();
    return 0;
}