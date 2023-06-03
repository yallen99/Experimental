// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ExperimentalUISettings.generated.h"

UENUM()
enum EButtonIconType
{
	FaceNorth,
	FaceSouth,
	FaceEast,
	FaceWest,
	DpadUp,
	DpadDown,
	DpadRight,
	DpadLeft,
	LeftBumper,
	RightBumper,
	LeftTrigger,
	RightTrigger,
	TouchPad,
	OptionsBtn,
	ShareBtn,
};

USTRUCT(BlueprintType)
struct FButtonIcon
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EButtonIconType> Type;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> IconTexture;
};
	
UCLASS(Config=Game, defaultconfig, meta = (DisplayName="UI Settings"))
class EXPERIMENTAL_API UExperimentalUISettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Icon Mappings")
	TArray<FButtonIcon> PlayStationIcons;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "Icon Mappings")
	TArray<FButtonIcon> XboxIcons;
};
