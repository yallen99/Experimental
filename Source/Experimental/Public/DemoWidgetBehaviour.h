// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DemoWidgetBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API UDemoWidgetBehaviour : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(meta=(BindWidget))
	class UImage* North;
	
	virtual void SynchronizeProperties() override;
};
