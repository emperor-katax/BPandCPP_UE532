#include "CPP_LightTrigger_02.h"

ACPP_LightTrigger_02::ACPP_LightTrigger_02(){
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	RootComponent = Frame_Box;
	Frame_Box->bHiddenInGame = false;
	// bind functions to collision methods  
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_LightTrigger_02::OnEntering); 
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ACPP_LightTrigger_02::OnLeaving); 
}


void ACPP_LightTrigger_02::BeginPlay(){
	Super::BeginPlay();
	
}

void ACPP_LightTrigger_02::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ACPP_LightTrigger_02::LightOperator(){
	for (ASpotLight* LightObject : Lights) { 
		LightObject->SpotLightComponent->SetVisibility(LightsVisibility); 
	}
	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---")); 
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end 
}

void ACPP_LightTrigger_02::OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult){
	//UE_LOG(LogTemp, Warning, TEXT(" - iekt --- %s"), *(OtherActor->GetName())); 


	//// get all properties of OtherActor 
	//for (TFieldIterator<FProperty> PropIt(OtherActor->GetClass()); PropIt; ++PropIt) {  
	//// UProperty in ue4 is FProperty in ue 5.3
	//	FProperty* ItemProperty = *PropIt;  
	//	// print all public properties of other actor 
	//	UE_LOG(LogTemp, Warning, TEXT(" - PROPERTIES -- OtherActor --- %s"), *(ItemProperty->GetName()));  
	//}

	// check if character has a property called "Special" 
	FProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Flag_01")); 
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool 

		// use boolean pointer property, to make boolean varialbe
		if (ptrValue) {
			bool temp = *ptrValue;	// convert to normal boolean variable
			if (temp) {
				UE_LOG(LogTemp, Warning, TEXT(" - Flag_01 is exist with  %s"), *(OtherActor->GetName()));
			}
		}
	
		// use boolean pointer property, directly
		if (ptrValue) { 
			if (*ptrValue) LightOperator();
		}		
	}

}

void ACPP_LightTrigger_02::OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex){
	// UProperty in ue4 is FProperty in ue 5.3
	FProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Flag_01"));
	if (SpecialProperty) {
		bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool 
		if (ptrValue) {
			bool temp = *ptrValue;
			if (temp) {
				LightOperator();
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName())); 

}
