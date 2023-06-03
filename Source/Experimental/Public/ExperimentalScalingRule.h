// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DPICustomScalingRule.h"
#include "ExperimentalScalingRule.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API UExperimentalScalingRule : public UDPICustomScalingRule
{
	GENERATED_BODY()

	virtual float GetDPIScaleBasedOnSize(FIntPoint Size) const override;
};
