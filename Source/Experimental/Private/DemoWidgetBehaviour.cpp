// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoWidgetBehaviour.h"

#include "ExperimentalUISettings.h"
#include "Components/Image.h"

void UDemoWidgetBehaviour::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	const UExperimentalUISettings* UIConfig = GetDefault<UExperimentalUISettings>();
	const auto NorthIconTexture = UIConfig->PlayStationIcons.FilterByPredicate([] (const FButtonIcon& Icon) {return Icon.Type == FaceNorth;})[0].IconTexture;
	//North->SetBrushFromTexture(NorthIconTexture.Get());
}
