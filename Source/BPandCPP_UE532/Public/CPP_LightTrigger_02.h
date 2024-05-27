#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine/SpotLight.h"
#include "Components/SpotLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_LightTrigger_02.generated.h"

UCLASS()
class BPANDCPP_UE532_API ACPP_LightTrigger_02 : public AActor{
	GENERATED_BODY()
	
public:	
	ACPP_LightTrigger_02();

	// Box collision element in BP
	UPROPERTY(BlueprintReadWrite, Instanced, EditAnywhere)
	UBoxComponent* Frame_Box;

	// Arrays of "Pickable" lights on stage. Because we use SpotLight class, then (in editor) we can pick items on stage same as BP
	UPROPERTY(EditAnywhere)
	TArray<ASpotLight*> Lights;

	UFUNCTION()
	void OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:

	bool LightsVisibility = true;	// visibility boolean flag
	void LightOperator();			// function for manage light actors 

};
