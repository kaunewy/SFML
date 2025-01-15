#pragma once
#include "Actor.h"
class BlackHole
{
	Actor* blackHole;

public:
	FORCEINLINE Actor* GetBlackHole() const
	{
		return blackHole;
	}
	
public:
	BlackHole();
	~BlackHole();

};

