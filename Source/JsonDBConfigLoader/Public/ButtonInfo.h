#pragma once

class JSONDBCONFIGLOADER_API FButtonInfo
{

public:
	FButtonInfo();
	FButtonInfo(TSharedPtr<SWidget> parent, TSharedPtr<SButton> button, TSharedPtr<SButton> deleteButton, TSharedPtr<SBox> box, TSharedPtr<SBorder> selectBar, TSharedPtr<STextBlock> unsaveIndicator);

	UPROPERTY()
	TSharedPtr<SWidget> Parent;

	UPROPERTY()
	TSharedPtr<SButton> Button;
	
	UPROPERTY()
	TSharedPtr<SButton> DeleteButton;
	
	UPROPERTY()
	TSharedPtr<SBox> Box;
	
	UPROPERTY()
	TSharedPtr<SBorder> SelectBar;
	
	UPROPERTY()
	TSharedPtr<STextBlock> UnsavedIndicator;
};
