


#include "Actors/AmmoPickup.h"
#include "Ipvmulti/IpvmultiCharacter.h"
#include "Net/UnrealNetwork.h"


AAmmoPickup::AAmmoPickup()
{
	AmmoRestoreAmount = 5;
	
}

void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}



void AAmmoPickup::OnPickedUp(AActor* OtherActor)
{
	AIpvmultiCharacter* Player = Cast<AIpvmultiCharacter>(OtherActor);
	if (Player && Player->HasAuthority()) 
		if (Player && Player->HasAuthority()) 
		{
			Player->AmmoCount = 5;
			Player->OnRep_Ammo();
        
			Player->bIsFiringWeapon = true; 

			Destroy();
		}


}

void AAmmoPickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAmmoPickup, bHasBeenPickedUp);
}


