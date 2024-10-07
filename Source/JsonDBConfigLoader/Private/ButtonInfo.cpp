#include "ButtonInfo.h"

FButtonInfo::FButtonInfo()
{
}

FButtonInfo::FButtonInfo(TSharedPtr<SWidget> parent, TSharedPtr<SButton> button, TSharedPtr<SButton> deleteButton, TSharedPtr<SBox> box, TSharedPtr<SBorder> selectBar,
	TSharedPtr<STextBlock> unsaveIndicator)
{
	Parent = parent;
	Button = button;
	DeleteButton = deleteButton;
	Box = box;
	SelectBar = selectBar;
	UnsavedIndicator = unsaveIndicator;
}
