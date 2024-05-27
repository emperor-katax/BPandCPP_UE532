#include "CPP_LightTrigger_03.h"

ACPP_LightTrigger_03::ACPP_LightTrigger_03(){
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	RootComponent = Frame_Box;
	Frame_Box->bHiddenInGame = false;
	// bind functions to collision methods  
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_LightTrigger_03::OnEntering); 
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ACPP_LightTrigger_03::OnLeaving); 
}

void ACPP_LightTrigger_03::BeginPlay(){
	Super::BeginPlay();
	
	// get player character
	CollisionCharacter = UGameplayStatics::GetPlayerCharacter(this, 0); 

	// get lights from stage
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpotLight::StaticClass(), Lights); // get spot lights into an array 
	/*
	check: https://answers.unrealengine.com/questions/289453/get-all-actors-of-class-in-c.html
	and: https://answers.unrealengine.com/questions/605880/getworld-pointer-to-incomplete-class-type-is-not-a.html
	*/
}

void ACPP_LightTrigger_03::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ACPP_LightTrigger_03::LightOperator(){
	for (AActor* LightActor : Lights) { // Lights is array of "Actor*" 
		ASpotLight* s = Cast<ASpotLight>(LightActor); // cast spotlight as an actors from Lights array

		if (s != nullptr) s->SpotLightComponent->SetVisibility(LightsVisibility); 
		UE_LOG(LogTemp, Warning, TEXT(" -            light:  %s"), *(LightActor->GetName())); 
	}

	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---")); 
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end 


	/*
	check:
	HARRISON MCGUIRE - C++ Examples for UE
	https://unrealcpp.com/
	https://www.youtube.com/c/HarrisonMcGuire
	*/

}

void ACPP_LightTrigger_03::OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	//// get all properties of OtherActor, only if OtherActor is equal to player character
	//if (OtherActor == CollisionCharacter) { 
	//	for (TFieldIterator<FProperty> PropIt(OtherActor->GetClass()); PropIt; ++PropIt) { 
	//		FProperty* Property = *PropIt; 
	//		// print all public properties of other actor
	//		UE_LOG(LogTemp, Warning, TEXT(" - PROPERTIES -- OtherActor --- %s"), *(Property->GetName())); 
	//	}
	//}

	// check if character has a property called "Special" 
	FProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Flag_01"));
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool 		
		// use boolean pointer property, to make normal boolean
		if (ptrValue) {
			bool temp = *ptrValue;	// convert to normal boolean variable
			if (temp) {
				UE_LOG(LogTemp, Warning, TEXT(" - iekt --using normal bool- %s"), *(OtherActor->GetName()));
			}
		}
		

		// use boolean pointer property, directly
		if (ptrValue) {
			LightOperator();
		}
	}



}

void ACPP_LightTrigger_03::OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex){
	FProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Flag_01")); 
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool  
		if (ptrValue) {
			bool temp = *ptrValue;
			if (temp) {
				UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName())); 
				LightOperator(); 
			}
		}
	}

}



