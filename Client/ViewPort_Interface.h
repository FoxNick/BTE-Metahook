#pragma once

class CClientVGUI : public IClientVGUI
{
public:
	virtual void Initialize(CreateInterfaceFn *factories, int count);
	virtual void Start(void);
	virtual void SetParent(vgui::VPANEL parent);
	virtual bool UseVGUI1(void);
	virtual void HideScoreBoard(void);
	virtual void HideAllVGUIMenu(void);
	virtual void ActivateClientUI(void);
	virtual void HideClientUI(void);

public:
	void HideAllPanel(void);
	void HidePanel(const char *name);
};

extern IClientVGUI *g_pClientVGUI;

void ViewPort_InstallHook(cl_exportfuncs_t *pExportfuncs);