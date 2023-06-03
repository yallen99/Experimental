// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetValidator_WidgetNaming.h"
#include "Framework/Application/SlateApplication.h"
#include "BaseWidgetBlueprint.h"
#include "Blueprint/WidgetTree.h"
#include "Internationalization/Regex.h"
#include "Misc/Paths.h"
#include "Widgets/SWidget.h"
#include "Templates/SharedPointer.h"
#include "Components/Overlay.h"

bool UAssetValidator_WidgetNaming::CanValidateAsset_Implementation(UObject* InAsset) const
{
	if(Cast<UBaseWidgetBlueprint>(InAsset))
	{
		return true;
	}
	return Super::CanValidateAsset_Implementation(InAsset);
}

EDataValidationResult UAssetValidator_WidgetNaming::ValidateLoadedAsset_Implementation(UObject* InAsset, TArray<FText>& ValidationErrors)
{
	// validate naming
	const FRegexPattern Pattern("^WBP_");
	const FString FileName = FPaths::GetCleanFilename(InAsset->GetPathName());
	FRegexMatcher Matcher(Pattern, FileName);
	if(!Matcher.FindNext())
	{
		AssetFails(InAsset, INVTEXT("Widget asset name is not valid. Widgets need to start with `WBP_`"), ValidationErrors);
		return EDataValidationResult::Invalid;
	}

	/*// validate canvas DPI set to 1 ---- That didn't work :(
	const UBaseWidgetBlueprint* AsWidget = Cast<UBaseWidgetBlueprint>(InAsset);
	UWidget* AsUWidget = AsWidget->WidgetTree->RootWidget.Get();
	const TSharedRef<SWidget> AsSWidget = AsUWidget->TakeWidget();
	const TSharedRef<SWidget>  focusedWidget = FSlateApplication::Get().GetKeyboardFocusedWidget().ToSharedRef();
	const SWindow* window = FSlateApplication::Get().FindWidgetWindow(focusedWidget).Get();
	if(window != nullptr)
	{
		const float Scale = window->GetDPIScaleFactor();
		if(Scale != 1)
		{
			AssetFails(InAsset, INVTEXT("Your windows is using a rescaled resolution. See (Windows) Display Settings > Display Resolution"), ValidationErrors);
			return EDataValidationResult::Invalid;
		}
	}*/
	AssetPasses(InAsset);
	return Super::ValidateLoadedAsset_Implementation(InAsset, ValidationErrors);
}
