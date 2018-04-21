#ifndef CSTRIKEBUYMOUSEOVERPANELBUTTON_H
#define CSTRIKEBUYMOUSEOVERPANELBUTTON_H

#ifdef _WIN32
#pragma once
#endif

#include <vgui/IScheme.h>
#include <vgui_controls/Button.h>
#include <vgui/KeyCode.h>
#include <filesystem.h>
#include "shared_util.h"

#include "WeaponManager.h"

#include "game_controls/mouseoverpanelbutton.h"
#include "buymouseoverpanelbutton.h"

class CSBuyMouseOverPanelButton : public BuyMouseOverPanelButton
{
private:
	typedef BuyMouseOverPanelButton BaseClass;
public:
	CSBuyMouseOverPanelButton(vgui::Panel *parent, const char *panelName, vgui::EditablePanel *panel);

	virtual void Paint() override;
	virtual void PerformLayout() override;

	using WeaponBuyTeam = CWeaponManager::WeaponBuyTeam;
	void SetTeam(WeaponBuyTeam team)
	{
		m_iTeam = team;
	}
	WeaponBuyTeam m_iTeam;
	void UpdateWeapon(const char *weapon = "");

	vgui::ImagePanel *m_pWeaponImage;
};

#endif