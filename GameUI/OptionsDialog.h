#pragma once

#include "vgui_controls/PropertyDialog.h"
#include "vgui_controls/KeyRepeat.h"

using namespace vgui;

class COptionsDialog : public vgui::PropertyDialog
{
	DECLARE_CLASS_SIMPLE(COptionsDialog, vgui::PropertyDialog);

public:
	COptionsDialog(vgui::Panel *parent);
	~COptionsDialog(void);

public:
	void Run(void);
	void Activate(void);

public:
	void OnClose(void);

public:
	MESSAGE_FUNC(OnGameUIHidden, "GameUIHidden");

private:
	class COptionsSubMultiplayer *m_pOptionsSubMultiplayer;
	class COptionsSubKeyboard *m_pOptionsSubKeyboard;
	class COptionsSubMouse *m_pOptionsSubMouse;
	class COptionsSubAudio *m_pOptionsSubAudio;
	class COptionsSubVideo *m_pOptionsSubVideo;
	class COptionsSubVoice *m_pOptionsSubVoice;
	class COptionsSubAdvanced *m_pOptionsSubAdvanced;
};