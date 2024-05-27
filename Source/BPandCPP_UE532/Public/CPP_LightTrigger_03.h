#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine/SpotLight.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Character.h" 
#include "Kismet/GameplayStatics.h" 
#include "CPP_LightTrigger_03.generated.h"

UCLASS()
class BPANDCPP_UE532_API ACPP_LightTrigger_03 : public AActor{
	GENERATED_BODY()
	
public:	
	ACPP_LightTrigger_03();

	// Box collision element in BP
	UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere)
	UBoxComponent* Frame_Box;

	UFUNCTION()
	void OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	
	bool LightsVisibility = true;
	ACharacter* CollisionCharacter = nullptr;	// Use for detect character in collision funtion
	TArray<AActor*> Lights;		// Arrays of lights on stage.
	void LightOperator();

};
