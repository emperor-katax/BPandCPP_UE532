#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Helper_basics.generated.h"

class tempClass_01;

UCLASS()
class BPANDCPP_UE532_API AHelper_basics : public AActor{
	GENERATED_BODY() 
	
public:	
	AHelper_basics();

	tempClass_01* object_A1;
	tempClass_01* object_A2;

	class tempClass_02* object_B1;
	class tempClass_02* object_B2;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// /// //// //// 

	bool bool_01;
	bool bool_02 = true;

	// check AItem_Actor() in cpp
	int value_01;
	int value_02;

	int value_03;
	int value_04 = 77;

	uint8 u_01;
	int32 int_32; // can`t transfer to blueprint
	int64 int_64; // can`t transfer to blueprint

	float float_01;
	float float_02 = 98;
	float float_03 = 98.f;
	float float_04 = 98.0;
	float float_05 = 98.0f;

	double dub_01; // 64 bit - can`t transfer to blueprint
	long double ddub_01; // 128 bit - can`t transfer to blueprint

	FVector vector_01;
	FVector vector_02 = FVector(12.0);					// vector_02 = (12.0, 12.0, 12.0);
	FVector vector_03 = FVector(12.0, 12.0, 12.0);		// vector_03 = (12.0, 12.0, 12.0);
	FVector vector_04 = FVector(FVector::ZeroVector);	// vector_04 = (0.0, 0.0, 0.0);
	FVector vector_05 = FVector(FVector::OneVector);	// vector_05 = (1.0, 1.0, 1.0);

	FRotator rotator_01;
	FRotator rotator_02 = FRotator(32.0); // degree
	// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FRotator/
	// https://forums.unrealengine.com/t/help-how-to-get-forwardvector-from-a-frotator-in-c/548597/4

	FTransform transform_01;
	FTransform transform_02 = FTransform(FTransform::Identity);				// set location & rotation to zero, scale to 1
	FTransform transform_03 = FTransform(rotator_02, vector_02, vector_05); // FTransform( rotator, vector, vector )
	FTransform transform_04 = FTransform(FRotator(32.0), FVector(0.0, 120.0, 42.0), FVector(2.25));

	FString string_01;
	FString string_02 = "String Variable";
	FString string_03 = TEXT("String Variable");

	FName name_01;
	FName name_02 = TEXT("The Magic");
	FName name_03 = NAME_None;
	// https://baemincheon.github.io/2020/01/17/unreal-fname-anatomy/ // quick access 


	AActor* actor_01;

	TArray<FString> arrString_01;
	TArray<AActor*> arrActor_01;
	// https://dev.epicgames.com/documentation/en-us/unreal-engine/array-containers-in-unreal-engine?application_version=5.3

	TSet<AActor*> setActor_01; // TSet uses the data value itself as the key.
	// https://dev.epicgames.com/documentation/en-us/unreal-engine/set-containers-in-unreal-engine?application_version=5.3
	TMap<FName, AActor*> mapActor; // stores data as key-value pairs (TPair<KeyType, ValueType>), using keys only for storage and retrieval.
	// https://dev.epicgames.com/documentation/en-us/unreal-engine/map-containers-in-unreal-engine?application_version=5.3

};

/*

() // Arguments
{} // Scope
[] // Array
<> // Template

TArray<int> mAR;
mAR[12]


.  // Accessor
:: // Scope Resolution  -  Access static data directly from class
-> // Pointer Accessor ( (*a).function )

* // Pointer
& // Reference

if () {}
else if () {}
else {}

while () {}

for (int i = 0; i < 10; i++) {}
for (AActor* Player : PlayerArray)
{
	//...location = Player->GetActorLocation();
}
*/