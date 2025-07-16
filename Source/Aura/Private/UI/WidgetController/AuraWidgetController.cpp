


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCPParams)
{
	PlayerController = WCPParams.PlayerController;
	PlayerState = WCPParams.PlayerState;
	AbilitySystemComponent = WCPParams.AbilitySystemComponent;
	AttributeSet = WCPParams.AttributeSet;
}
