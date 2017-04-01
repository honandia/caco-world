#include "Elemento.h"
Elemento::Elemento(int x=0, int y=0): cordX(x), cordY(y)
{}
Elemento::~Elemento(void)
{}
void Elemento::SetX(int x)
{cordX = x;}
int Elemento::GetX(void)

{return cordX;}
void Elemento::SetY(int y)
{cordY = y;}
int Elemento::GetY(void)
{return cordY;}

