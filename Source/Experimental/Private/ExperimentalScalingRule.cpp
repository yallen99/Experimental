// Fill out your copyright notice in the Description page of Project Settings.


#include "ExperimentalScalingRule.h"

float UExperimentalScalingRule::GetDPIScaleBasedOnSize(FIntPoint Size) const
{
	if(Size.X == 1920)
		return 1.0f;
	if(Size.X == 2160.0)
		return 2.0f;
	return Super::GetDPIScaleBasedOnSize(Size);
}
