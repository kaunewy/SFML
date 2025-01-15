#include "BlackHole.h"

BlackHole::BlackHole()
{
	blackHole = new Actor({ 90,90 }, "BH");
	blackHole->GetShape()->SetPosition({ 260, 300 });
}

BlackHole::~BlackHole()
{
	delete blackHole;
}
