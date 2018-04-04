#ifndef CSBUYSUBMENU_H
#define CSBUYSUBMENU_H
#ifdef _WIN32
#pragma once
#endif

#include "game_controls\buysubmenu.h"

using namespace vgui;

class CCSBuySubMenu : public CBuySubMenu
{
private:
	DECLARE_CLASS_SIMPLE(CCSBuySubMenu, CBuySubMenu);

public:
	CCSBuySubMenu(vgui::Panel *parent, const char *name = "BuySubMenu");

protected:
	virtual void OnCommand(const char *command);
	virtual void PerformLayout(void);
	virtual void OnSizeChanged(int newWide, int newTall);
	virtual void OnDisplay(void);

public:
	void UpdateLoadout(void);

protected:
	virtual MouseOverPanelButton *CreateNewMouseOverPanelButton(EditablePanel *panel);
	virtual CBuySubMenu *CreateNewSubMenu(const char *name = "BuySubMenu");

public:
	virtual void SetupNextSubPanel(const char *fileName);

private:
	vgui::Label *m_pMoney;
	int m_lastMoney;
};

#endif
