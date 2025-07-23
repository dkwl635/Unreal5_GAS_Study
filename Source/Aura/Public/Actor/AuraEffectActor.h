

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;
class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EffectApplicationPolicy : uint8
{
	//들어올때 반응
	ApplyOnOverlap,
	//나갈때 반은
	ApplyOnEndOverlap,
	//반응 X
	DoNotApply,
};

UENUM(BlueprintType)
enum class EffectRemovalPolicy : uint8
{

	//나갈때 반은
	RemoveOnEndOverlap,
	//반응 X
	DoNotRemove,
};


UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAuraEffectActor();
protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);
	
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	bool bDestroyOnEffectRemoval = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	EffectApplicationPolicy InstantEffectApplicationPolicy = EffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	EffectApplicationPolicy DurationEffectApplicationPolicy = EffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	EffectApplicationPolicy InfiniteEffectApplicationPolicy = EffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Applied Effects")
	EffectRemovalPolicy InfiniteEffectRemovalPolicy = EffectRemovalPolicy::RemoveOnEndOverlap;


	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;
};

