#include "Sniper.h"
#include "UnitInfoWidget.h"

ASniper::ASniper()
{
	Health = 20;
	MaxMovement = 4;	// one more to consent correct movement
	AttackRange = 10;
	DamageMin = 4;
	DamageMax = 8;
}
