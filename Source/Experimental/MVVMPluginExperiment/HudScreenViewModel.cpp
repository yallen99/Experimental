// Fill out your copyright notice in the Description page of Project Settings.


#include "HudScreenViewModel.h"

void UHudScreenViewModel::SetHealth(float Value)
{
	HealthValue = Value;
}

float UHudScreenViewModel::GetHealth() const
{
	return HealthValue;
}

void UHudScreenViewModel::SetHealthValue(const float NewHealthValue)
{
	// Checks if the new health value is different from the Health Value
	// if it is, it sets the Health value to new health value
	if(UE_MVVM_SET_PROPERTY_VALUE(HealthValue, NewHealthValue))
	{
		// If the health value changed, notify the widgets bound to this property
		// the need updating.
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(HealthValue);
	}
}
