// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "HudScreenViewModel.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API UHudScreenViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter="SetHealth", Getter="GetHealth", meta=(AllowPrivateAccess))
	float HealthValue = 100.0f;

	void SetHealth(float Value);
	float GetHealth() const;

public:
	UFUNCTION(BlueprintCallable)
	void SetHealthValue(float NewHealthValue);
	
};
