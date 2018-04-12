
#ifndef COLOREDBUTTON_H
#define COLOREDBUTTON_H

#ifdef _WIN32
#pragma once
#endif

#include <VGUI/IBorder.h>
#include <VGUI/IScheme.h>
#include <KeyValues.h>

#include <vgui_controls/Button.h>
#include <vgui_controls/ImagePanel.h>

class ColoredButton : public vgui::Button
{
	DECLARE_CLASS_SIMPLE(ColoredButton, Button);

	Color _replaceColor;
public:
	ColoredButton(vgui::Panel *parent, const char *panelName, const char *text) :
		Button(parent, panelName, text) {}

	void SetTextColor(Color col)
	{
		_replaceColor = col;
	}

	virtual Color GetButtonFgColor() override
	{
		return _replaceColor;
	}
};

#endif