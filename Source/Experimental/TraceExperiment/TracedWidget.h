// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Trace/Trace.h"			// Must include TraceLog in private dependency modules
#include "TracedWidget.generated.h"

UE_TRACE_CHANNEL(UIExperimentsChannel);

class UImage;
/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API UTracedWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> ColorImage = nullptr;
	
	virtual void NativeConstruct() override;
	void SetColors() const;
};
