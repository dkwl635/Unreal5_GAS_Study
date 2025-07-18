

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

//health
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChageSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChageSignature, float, NewMaxHealth);
//Mana
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChageSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChageSignature, float, NewMaxMana);


/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	virtual  void BroadcastInitialValues() override;
	virtual  void BindCallbacksToDependencies() override;

	//Health
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChageSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChageSignature OnMaxHealthChanged;
	//Mana
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnManaChageSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxManaChageSignature OnMaxManaChanged;
	
	
protected:
	//Health
	void HealthChanged(const FOnAttributeChangeData& Data);
	void MaxHealthChanged(const FOnAttributeChangeData& Data);
	
	//Mana
	void ManaChange(const FOnAttributeChangeData& Data);
	void MaxManaChange(const FOnAttributeChangeData& Data);
	
	
	
};
