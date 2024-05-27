#include "CPP_LightTrigger_01.h"

ACPP_LightTrigger_01::ACPP_LightTrigger_01(){
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Collision Box"); 
	RootComponent = Frame_Box;
	Frame_Box->bHiddenInGame = false;
	// bind functions to collision methods  
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_LightTrigger_01::OnEntering); 
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ACPP_LightTrigger_01::OnLeaving); 

}

void ACPP_LightTrigger_01::BeginPlay(){
	Super::BeginPlay();
	
}

void ACPP_LightTrigger_01::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ACPP_LightTrigger_01::LightOperator(){
	for (ASpotLight* LightObject : Lights) { 

		LightObject->SpotLightComponent->SetVisibility(LightsVisibility);  
		/*
		check : http://api.unrealengine.com/INT/API/Runtime/Engine/Engine/ASpotLight/index.html
		SpotLightComponent is an actor component and has public methods and properties
		... try
		Actor->SpotLightComponent->SetIntensity(3000.0f);

		 and then try
		 --------- > for this value , try to set camera
		between player and spoptlights during play time.. it showes kind of art effect
		*/
		//if(LightsVisibility) LightObject->SpotLightComponent->SetIntensity(3000.0f);
		//if(LightsVisibility) LightObject->SpotLightComponent->SetIntensity(3000000.0f); 
	}	
	
	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---"));
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end
}

void ACPP_LightTrigger_01::OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){

	UE_LOG(LogTemp, Warning, TEXT(" - iekt --- %s"), *(OtherActor->GetName()));
	LightOperator();
}

void ACPP_LightTrigger_01::OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex){

	UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName()));
	LightOperator();
}



/*
UE_LOG 
https://unrealcpp.com/debug-logging/
*/