// Fill out your copyright notice in the Description page of Project Settings.


#include "TracedWidget.h"

#include "Components/Image.h"


void UTracedWidget::NativeConstruct()
{
	Super::NativeConstruct();
	SetColors();
}

void UTracedWidget::SetColors() const
{
	// TRACE_CPUPROFILER_EVENT_SCOPE(UTracedWidget::SetColors);	// 17.1 ms
	TRACE_CPUPROFILER_EVENT_SCOPE_ON_CHANNEL(UTracedWidget::SetColors, UIExperimentsChannel);
	for(int i = 0; i < 1000000; i++)
	{
		const FLinearColor Color = FLinearColor::MakeRandomColor();
		ColorImage->SetColorAndOpacity(Color);
	}
}
