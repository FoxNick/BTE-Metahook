#include "base.h"
#include "hud.h"
#include "configs.h"
#include "CSBTEAboutDialog.h"
#include "EngineInterface.h"
#include <vgui_controls\PHandle.h>

#include "Client/HUD/hud_saytext.h"

void(*pfnUnknown)() = (void(*)())0x1960870;

/*
enum BTEVERSION
{
	APR_4,
	APR_4_FIX,
	APR_9,
	APR_11,
	APR_23,
	MAY_21,
	JUL_19,
	JUL_22,
	AUG_14,
	VER_NEXT,

	NUM_VERSIONS
};

#define NORMAL_COLOR Color(255, 255, 255, 255)
#define INCLUDE_COLOR Color(0, 255, 255, 200)
#define WARNING_COLOR Color(255, 0, 0, 200)
#define JOKE_COLOR Color(0, 255, 0, 255)

#define UDSETCOLOR(a) p->InsertColorChange(a)
#define UDINSERTSTR(a) p->InsertString(a)

#define CURRENT_VERSION VER_NEXT

void InsertUpdateDataEx(BTEVERSION iVersion, RichText *p)
{
	static int version = -1;

	if (version == iVersion)
		return;

	version = iVersion;

	p->SetText(L"");

	UDSETCOLOR(NORMAL_COLOR);

	if (Q_stricmp(gConfigs.szLanguage, "schinese"))
	{
		if (!Q_stricmp(gConfigs.szLanguage, "tchinese"))
			UDINSERTSTR(L"ֻ�����ں��w�����²鿴������\n");
		else
			UDINSERTSTR(L"You can only see what has been updated in Chinese Simplified.\n");

		return;
	}

	switch (iVersion)
	{
	case APR_4:
		UDINSERTSTR(L"+ sgdrill���һ���ӵ���ʱ������������Ҽ���������\n");
		UDINSERTSTR(L"+ railcannon�Ҽ�������������\n");
		UDINSERTSTR(L"+ @��ͷ����ͼ��textures���Ҳ���ʱ���ᱻ�滻\n");
		UDINSERTSTR(L"+ blockar(���������޷����ģ�����������͵�����VPWģ�ȶ��ǹ̶���\n");
		UDINSERTSTR(L"+ ����Ӧ�ò�����ֵڶ���û���򿪹���˵�\n");
		UDINSERTSTR(L"+ ��ͨģʽ������������ʱ�Զ��رչ���˵�\n");
		UDINSERTSTR(L"+ ������ѪҺ��ɫ�жϷ�ʽ������Ӧ�ò�����ʲôƫ����\n");
		UDINSERTSTR(L"+ ����ҹ������ɫ͸���ȼ���(��������\n");
		UDINSERTSTR(L"+ ��΢������ɫ��ҩλ��\n");
		UDINSERTSTR(L"+ ���˿�������ʱ���״�������ʾ����������(��ʵ����ʾ���ͻ���������\n");
		UDINSERTSTR(L"+ �ʺ�������׼�ǿ���������ܶ�ʱ���1.5��(֮ǰ����û������趨������ԭ����\n");
		UDINSERTSTR(L"+ û�д򿪲˵�ʱ����9�������");
		break;
	case APR_4_FIX:
		UDINSERTSTR(L"+ ��������ģ��\n");
		UDINSERTSTR(L"+ ����֮ǰ���µ�������������(�ֿ�༭����)\n");
		UDINSERTSTR(L"+ ����additive��ͼ���ᱻ�Զ�ʶ��(����֪�������ð������");
		break;
	case APR_9:
		UDINSERTSTR(L"+ stormgiant\n");
		UDINSERTSTR(L"+ supplybox����\n");
		UDINSERTSTR(L"+ ������tab�Ʒְ廹���״������Ӣ�۶�������ʾ��VIPͼ��\n");
		UDINSERTSTR(L"+ ��6ʱ������Ա�ͷ(�˺������Ϊ����2��������3��)������¾֮�С���������");
		break;
	case APR_11:
		UDINSERTSTR(L"+ buffak, buffm4\n");
		UDINSERTSTR(L"+ ����������E��ͼ���ʼ�հ��ղ�����λ�ü���\n");
		UDINSERTSTR(L"+ ����stormgiant��һ����������\n");
		UDINSERTSTR(L"+ ���˻�ͼ�󲿷ֶ���modelindex����\n");
		UDINSERTSTR(L"+ Ӧ������˫ǹ�����켣��ʼ�����\n");
		UDINSERTSTR(L"+ ZB3ʿ��ָ���жϸ���\n");
		UDINSERTSTR(L"+ Ӧ������FFF��ʱ��ɱ�������\n");
		UDINSERTSTR(L"+ HLDS�������ᱻģ��ˢ����ĳЩnative��������ʹ��");
		break;
	case APR_23:
		UDINSERTSTR(L"+ B�˵�����(��ESC�����˳�����ʱ����F5��ͼ��һЩλ�úʹ�С���������¹���)\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"˵����\n");
		UDINSERTSTR(L"cstrike\buymenu.ini[BUYMENUCONFIG]����B�˵���һЩ�趨\n");
		UDINSERTSTR(L"MonthWeapon = ��������\n");
		UDINSERTSTR(L"DefaultPrimaryWeapon = Ĭ��������\n");
		UDINSERTSTR(L"DefaultPistol = Ĭ����ǹ\n");
		UDINSERTSTR(L"DefaultMelee = Ĭ�ϵ�\n");
		UDINSERTSTR(L"��ֵ�������������������Ĭ��ֵ(û��, ak47, usp, knife)\n");
		UDINSERTSTR(L"Ĭ�ϵ�������ָ����˵�(�Ǿ��������顢��ս��ģʽ)�������ձ������\n");
		UDINSERTSTR(L"�������������û��������������Ĭ�����������ȵȡ�\n");
		UDINSERTSTR(L"Ĭ������ֻ���Ǹ߱����ס�(����û��DefaultGrenade�����ֵ)\n");
		UDINSERTSTR(L"\n");
		UDSETCOLOR(WARNING_COLOR);
		UDINSERTSTR(L"ע�⣺\n");
		UDINSERTSTR(L"�ұߵ����������װ����ֻ�ܵ���ԱߵĴ������ѵ�ǰ�������ĵ��߸��ƽ��������Ҽ���Ч\n");
		UDINSERTSTR(L"\n");
		UDSETCOLOR(JOKE_COLOR);
		UDINSERTSTR(L"�ŶӾ�ս��TeamSuit����������\n");
		UDINSERTSTR(L"�˴ι���˵���δ���ƣ���һ���м���˺���׼��Щ��������(ÿ��д��ô�ණ��̫�鷳��)��\n");
		UDINSERTSTR(L"����������㣬���ܻ�Ū����ѡ��˵���Ĭ�Ͻ�ʬѡ��˵���\n");
		UDINSERTSTR(L"\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"+ buffm4�ӳ��������һ��");
		break;
	case MAY_21:
		UDINSERTSTR(L"+ speargun����(Ŀǰ��speargun�޷�����ʹ�ã�����ĳЩʱ�����̨����ˢ������֪��ʲô���)\n");
		UDINSERTSTR(L"+ B�˵�����(�޷�������ߵ��Ǹ��Ի�����ʱ�����ƶ�)\n");
		UDINSERTSTR(L"+ bow(�˴�����ֱ�����˾ɰ棬�´λ���)\n");
		UDINSERTSTR(L"+ ����Alpha��GameStudioModelRenderer(�иĹ���Vģbug�ֳ��֣��Ժ��޸������⻹��һЩδ֪bug����֪bug���Ѿ��޸�)\n");
		UDSETCOLOR(WARNING_COLOR);
		UDINSERTSTR(L"ע�⣺��HDRʱ��Ч\n");
		UDINSERTSTR(L"����������Ժ�дguillotine�õ�(Ҳ����˵������㿪��HDR����ʱ��guillotine�᲻����)\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"+ speedup����Ĥ����˸\n");
		UDINSERTSTR(L"+ ����infinity�����Ҽ���������\n");
		UDINSERTSTR(L"+ B�˵� / �Ŷ���װһЩ��ť���Ը������������������\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"�����ڳ�������˵�ѡ��Ŀ�ݼ�\n");
		UDSETCOLOR(WARNING_COLOR);
		UDINSERTSTR(L"Ŀǰֻ֧����ĸ����֧��ͬʱ�����������\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"�÷�����&���������ĸ������ ���á����ԡ������ť��G����\n");
		UDINSERTSTR(L"��ô����\"����(&G)\"\n");
		UDINSERTSTR(L"��ĵĿ����Լ���cso_chn.txt�����Ѱ�������ԭ�е�����(����ȫ���ᵽ������\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"+ ���C4ͼ�껻��TGA");
		break;
	case JUL_19:
		UDINSERTSTR(L"+ gauss");
		break;
	case JUL_22:
		UDINSERTSTR(L"+ MVP���\n");
		UDINSERTSTR(L"+ ������ʾ(Ŀǰ��ûд����ģʽ�����ӷ�)\n");
		UDINSERTSTR(L"+ ����alarm\n");
		UDINSERTSTR(L"+ gauss�������˺�����\n");
		UDINSERTSTR(L"+ gauss����ģʽ�����ӵ�(ǰ��Clip > 0)\n");
		UDINSERTSTR(L"+ gauss����bug�޸�\n");
		UDINSERTSTR(L"+ deathinfo�ĸ���\n");
		UDINSERTSTR(L"+ ��ֹCBasePlayer::TabulateAmmo����ֹSetThink SetTouch SetUse��������\n");
		UDINSERTSTR(L"+ ʹ��������������@Diagonaler ��gaussͼƬ�Լ�TGA");
		break;
	case AUG_14:
		UDINSERTSTR(L"+ gauss�˺�������ͨ������\n");
		UDINSERTSTR(L"+ ��ֲ��VGUI\n");
		UDINSERTSTR(L"+ �����㿴�����������(���ڲ��������GameMenu.res)\n");
		UDINSERTSTR(L"+ ��Ϸ������ĸ���\n���޷�����ԭ��GameUI��ClientUI�Ľ�����ʽ\n");
		UDINSERTSTR(L"+ configs.ini�м��˼�������:\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"CSOLanguageName : ����ָ��CSO���������ƣ��Ӷ����cso_**.txt ��cstrike_**.txt��");
		UDINSERTSTR(L"����һ��Ϊchn�������cso_chn.txt �� cstrike_chn.txt\n");
		UDINSERTSTR(L"CustomFontName : ����ָ����Ϸ���������ƣ�");
		UDINSERTSTR(L"������Windows���������ƶ����������ļ���(��Ȼ����������ļ���������������), ");
		UDINSERTSTR(L"�����ֵ��������Scheme����������һ��(resource\\TrackerScheme.res & resource\\ClientScheme.res), ");
		UDINSERTSTR(L"�������������������resource\\font\\font.ttf ����������");
		UDINSERTSTR(L"�绪��Բ��W9����DFYuanW9-GB, ��������\"����Բ��W9\", ");
		UDINSERTSTR(L"��ô����뽫����res��DFYuanW9 - GBȫ���滻��\"����Բ��W9\"��");
		UDSETCOLOR(WARNING_COLOR);
		UDINSERTSTR(L"������Ϸ��������������\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"P.S. : ����㲻֪���������֣�����ֱ�Ӵ����壬�ҵ�\"��������\"������\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"������ʹ��˵��:\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"��������Ϸ�и�����HUD��״̬(���ܻ����bug������㷢���뷴��)\n");
		UDINSERTSTR(L"���θ������ú��´�������ϷҲ��������ã���Ϊд���ļ�\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"+ ģ����ͼ����(cstrike\\textures.ini)\n");
		UDSETCOLOR(WARNING_COLOR);
		UDINSERTSTR(L"���滻����ģ���е�ָ����ͼ����[All]��д���ݣ��滻ָ��ģ�����¼�����(����[v_awp]�͹��ˣ�����Ҫ.mdl\n)");
		UDINSERTSTR(L"��������ͼ��������\"%s\", ��ô\"%s\"�����滻Ϊԭ��ͼ��(ע��!!\"%s\"����д��\"%S\"������ԭ��ͼ��������չ��!)\n");
		UDINSERTSTR(L"textures.ini���Ѿ�д�˲�����ͼ(�ֱ���ͼ��balrog11��ɫ)��");
		UDINSERTSTR(L"Ŀǰ�汾�а���CSO��ֱ���滻��TGA�ֱ���ͼ��������Լ����Ÿģ�");
		UDINSERTSTR(L"����㲻���ã�����ɾ���Ǽ���\n");
		UDINSERTSTR(L"����ͼ·���б���ʹ��\"\\\"������\"/\"\n");
		UDINSERTSTR(L"����ͼ�������ִ�Сд���������к�׺��(bmpҲ�ܻ�TGA)\n");
		UDINSERTSTR(L"�����Ȳ��ұ�ģ������ָ������ͼ���Ҳ����ŻᵽAll����\n");
		UDSETCOLOR(INCLUDE_COLOR);
		UDINSERTSTR(L"����ʬ��������ͼ�滻�Ժ�����(�����Ҹ���һ��ķ�����");
		UDINSERTSTR(L"�����Ը�����һ����ͼһ����ͼ��д)\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"���˲ֿ�༭����airburster��������\n");
		UDINSERTSTR(L"����USAS12��B�˵����ֲ�����\n");
		UDINSERTSTR(L"buffm4ֻҪ��������������ӳ�6һ��\n");
		UDINSERTSTR(L"+ buffsg552");
		UDSETCOLOR(JOKE_COLOR);
		UDINSERTSTR(L"(vģ����򲻿���)\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"����ZB3����������ȴ��ɫ\n");
		UDINSERTSTR(L"���˼��ٷɱ����ܻغϽ���ʱʹ�ú���һ�ֿ�ʼ���ٶȺ���\n");
		UDINSERTSTR(L"����fff��ҩͼ�겻����");
		break;

	case VER_NEXT:
		UDINSERTSTR(L"����һЩ��֪��bug\n");
		UDINSERTSTR(L"������ԭ����GameStudioModelRenderer\n");
		UDINSERTSTR(L"$��ͷ����ͼ�����ܻ�������Ӱ��\n");
		UDINSERTSTR(L"����buffsg552����ͼ\n");
		UDINSERTSTR(L"Fake CSO��speargun\n");
		UDINSERTSTR(L"m950�������\n");
		UDINSERTSTR(L"balrog11ֻ�а���������Ų��ܳ���\n");
		UDINSERTSTR(L"BTE_Weapon2.amxx����ɾ���˺ܶ಻Ҫ�Ķ���\n");
		UDINSERTSTR(L"chainsaw��д\n");
		UDINSERTSTR(L"CSO������(ֻ��ģ�¸����), ���н�ʬ(Ĭ�Ͻ�ʬѡ��˵�����)\n");
		UDINSERTSTR(L"����ZB5����Ϸ�д���ͨ��Ϊ��HUDʱ��������\n");
		UDINSERTSTR(L"zombietrap�Զ�׷��\n");
		UDINSERTSTR(L"ZB3~5��֧�ֽ�ʬ��������ѡ��ʬ����\n");
		UDINSERTSTR(L"��֪���ǲ���������ģ�����˵�����ģʽ�������ⵯ�������ᵯ����ʾ�޷�����(�����ݲ��ܻ���)�����϶���������������У�");
		UDSETCOLOR(WARNING_COLOR);
		UDINSERTSTR(L"��fernando���ܹ���holybomb����blair���ܹ���lugers\n");
		UDSETCOLOR(NORMAL_COLOR);
		UDINSERTSTR(L"��ʬѡ��˵������ֺ���û��һ��\n");
		UDINSERTSTR(L"chainsaw/bow��סR���Ա�������/Ԥ��״̬����\n");
		UDINSERTSTR(L"stormgiant�����Ż�\n");
		UDINSERTSTR(L"railcannon���CSO����\n");
		UDINSERTSTR(L"��ʬѡ��˵����ݲ˵��ڽ�ʬ������������\n");
		UDINSERTSTR(L"��ʬѡ��˵�����˳����ݽ�ʬ�ڿͻ����Ѿ��趨������˷��͵�˳��ֻ��Ϊ�Ƿ���ѡ��ý�ʬ������\n");
		break;
	}
}

void CCSBTEAboutDialogComboBox::OnMenuItemSelected()
{
	BaseClass::OnMenuItemSelected();

	//InsertUpdateDataEx((BTEVERSION)GetActiveItem(), m_pText);
}
*/
CCSBTEAboutDialog::CCSBTEAboutDialog(Panel *parent, const char *panelName, bool showTaskbarIcon) : Frame(parent, panelName, showTaskbarIcon)
{
	int sw, sh;
	surface()->GetScreenSize(sw, sh);

	SetTitle("", false);

	SetBounds(sw / 2 - 200, sh / 2 - 150, 450, 200);
	SetSizeable(false);
	SetVisible(true);


	m_pLogo = new ImagePanel(this, "CSBTELogo");
	m_pLogo->SetImage(scheme()->GetImage("resource/game_menu_mouseover2", false));
	//m_pLogo->SetImage(scheme()->GetImage("announceribbon/announceicon/alarm_zombiebomb", false));
	
	m_pLogo->SetBounds(130, 25, 300, 40);


	/*
	m_pUpdateInfo = new RichText(this, "UpdateInfo");
	m_pUpdateInfo->SetBounds(10, 50, 430, 100);
	m_pUpdateInfo->InsertColorChange(Color(255, 255, 255, 255));
	
	m_pVersionSwitch = new CCSBTEAboutDialogComboBox(this, m_pUpdateInfo, "VersionSelection", NUM_VERSIONS, false);
	m_pVersionSwitch->SetBounds(!Q_stricmp(gConfigs.szLanguage, "english") ? 225 : 275, 25, 150, 20);
	m_pVersionSwitch->AddItem("Apr 4 2016", NULL);
	m_pVersionSwitch->AddItem("Apr 4 2016 Fix", NULL);
	m_pVersionSwitch->AddItem("Apr 9 2016", NULL);
	m_pVersionSwitch->AddItem("Apr 11 2016", NULL);
	m_pVersionSwitch->AddItem("Apr 23 2016", NULL);
	m_pVersionSwitch->AddItem("May 21 2016", NULL);
	m_pVersionSwitch->AddItem("Jul 19 2016", NULL);
	m_pVersionSwitch->AddItem("Jul 22 2016", NULL);
	m_pVersionSwitch->AddItem("Aug 14 2016", NULL);
	m_pVersionSwitch->AddItem("NEXT Version", NULL);

	if (CURRENT_VERSION < NUM_VERSIONS)
		m_pVersionSwitch->ActivateItem(CURRENT_VERSION);
	else
		m_pVersionSwitch->ActivateItem(NUM_VERSIONS - 1);
		*/

	m_pMoreInfoLabel = new Label(this, "MoreInfoLabel", "#CSBTE_About_MoreInformation");
	m_pMoreInfoLabel->SetPaintBackgroundEnabled(false);
	m_pMoreInfoLabel->SetBounds(10, 70, 200, 20);

	m_pCsoldjbURL = new URLLabel(this, "CsoldjbTiebaURL", "#CSBTE_About_DjbBar", "http://tieba.baidu.com/csoldjb");
	m_pCsoldjbURL->SetPaintBackgroundEnabled(false);
	if (Q_stricmp(gConfigs.szLanguage, "english"))
		m_pCsoldjbURL->SetBounds(180, 68, 150, 24);
	else
		m_pCsoldjbURL->SetBounds(200, 68, 150, 24);

	wchar_t *wstrSwitch[2] = { localize()->Find("#CSBTE_SwitchOn"), localize()->Find("#CSBTE_SwitchOff") };

	if (!wstrSwitch[0] || wstrSwitch[0][0] == L'#')
		wstrSwitch[0] = L"On";
	if (!wstrSwitch[1] || wstrSwitch[1][0] == L'#')
		wstrSwitch[1] = L"Off";

	m_pNewHUDSwitchLabel = new Label(this, "NewHUDSwitchLabel", "#CSBTE_NewHUDLabel");
	m_pNewHUDSwitchLabel->SetPaintBackgroundEnabled(false);
	m_pNewHUDSwitchLabel->SetBounds(10, 90, 100, 20);

	m_pNewHUDSwitch = new ComboBox(this, "NewHUDSwitch", 2, false);
	m_pNewHUDSwitch->AddItem(wstrSwitch[0], NULL);
	m_pNewHUDSwitch->AddItem(wstrSwitch[1], NULL);
	m_pNewHUDSwitch->ActivateItem(gConfigs.bEnableNewHud ? 0 : 1);
	m_pNewHUDSwitch->SetBounds(10, 120, 100, 24);

	m_pNewMuzzleflashSwitchLabel = new Label(this, "NewMuzzleFlashSwitchLabel", "#CSBTE_NewMuzzleFlashLabel");
	m_pNewMuzzleflashSwitchLabel->SetPaintBackgroundEnabled(false);
	m_pNewMuzzleflashSwitchLabel->SetBounds(120, 90, 100, 20);

	m_pNewMuzzleflashSwitch = new ComboBox(this, "NewMuzzleFlashSwitch", 2, false);
	m_pNewMuzzleflashSwitch->AddItem(wstrSwitch[0], NULL);
	m_pNewMuzzleflashSwitch->AddItem(wstrSwitch[1], NULL);
	m_pNewMuzzleflashSwitch->ActivateItem(gConfigs.bEnableNewMuzzle ? 0 : 1);
	m_pNewMuzzleflashSwitch->SetBounds(120, 120, 100, 24);

	m_pFireDlightSwitchLabel = new Label(this, "FireDlightSwitchLabel", "#CSBTE_FireDlightLabel");
	m_pFireDlightSwitchLabel->SetPaintBackgroundEnabled(false);
	m_pFireDlightSwitchLabel->SetBounds(230, 90, 100, 20);

	m_pFireDlightSwitch = new ComboBox(this, "FireDlightSwitch", 2, false);
	m_pFireDlightSwitch->AddItem(wstrSwitch[0], NULL);
	m_pFireDlightSwitch->AddItem(wstrSwitch[1], NULL);
	m_pFireDlightSwitch->ActivateItem(gConfigs.bEnableFireDlight ? 0 : 1);
	m_pFireDlightSwitch->SetBounds(230, 120, 100, 24);

	m_pBloodSwitchLabel = new Label(this, "BloodSwitchLabel", "#CSBTE_BloodLabel");
	m_pBloodSwitchLabel->SetPaintBackgroundEnabled(false);
	m_pBloodSwitchLabel->SetBounds(340, 90, 100, 20);

	m_pBloodSwitch = new ComboBox(this, "BloodSwitch", 2, false);
	m_pBloodSwitch->AddItem(wstrSwitch[0], NULL);
	m_pBloodSwitch->AddItem(wstrSwitch[1], NULL);
	m_pBloodSwitch->ActivateItem(gConfigs.bEnableBlood ? 0 : 1);
	m_pBloodSwitch->SetBounds(340, 120, 100, 24);

	m_pLanguageSelectionLabel = new Label(this, "LanguageSelectionLabel", "#CSBTE_LanguageLabel");
	m_pLanguageSelectionLabel->SetPaintBackgroundEnabled(false);
	m_pLanguageSelectionLabel->SetBounds(10, 150, 100, 24);

	m_pLanguageSelection = new ComboBox(this, "LanguageSelection", 3, false);
	if (Q_stricmp(gConfigs.szLanguage, "tchinese"))
	{
		m_pLanguageSelection->AddItem(L"��������", NULL);
		m_pLanguageSelection->AddItem(L"��������", NULL);
	}
	else
	{
		m_pLanguageSelection->AddItem(L"���w����", NULL);
		m_pLanguageSelection->AddItem(L"���w����", NULL);
	}

	m_pLanguageSelection->AddItem(L"English", NULL);
	m_pLanguageSelection->SetBounds(120, 150, 100, 24);

	if (!Q_stricmp(gConfigs.szLanguage, "schinese"))
		m_pLanguageSelection->ActivateItem(0);
	else if (!Q_stricmp(gConfigs.szLanguage, "tchinese"))
		m_pLanguageSelection->ActivateItem(1);
	else if (!Q_stricmp(gConfigs.szLanguage, "english"))
		m_pLanguageSelection->ActivateItem(2);
	else
	{
		m_pLanguageSelection->SetNumberOfEditLines(4);
		m_pLanguageSelection->AddItem(gConfigs.szLanguage, NULL);
		m_pLanguageSelection->ActivateItem(3);
	}

	m_pOKButton = new Button(this, "OKButton", "#GameUI_OK");
	m_pOKButton->SetBounds(230, 150, 100, 24);
	m_pOKButton->SetCommand("SaveConfigs");

	m_pCancelButton = new Button(this, "CancelButton", "#GameUI_Cancel");
	m_pCancelButton->SetBounds(340, 150, 100, 24);
	m_pCancelButton->SetCommand("vguicancel");
}


void CCSBTEAboutDialog::OnCommand(const char *command)
{
	if (!Q_stricmp(command, "SaveConfigs"))
	{
		if (!m_pNewHUDSwitch->GetActiveItem())
		{
			if (!gConfigs.bEnableNewHud)
				pfnUnknown();
			gConfigs.bEnableNewHud = 1;
		}
		else
		{
			if (gConfigs.bEnableNewHud)
			{
				line *pLine = HudSayText().head;
				while (pLine)
				{
					HudSayText().head = pLine;
					pLine = pLine->next;
					free(HudSayText().head);
					HudSayText().head = NULL;
				}
			}
			gConfigs.bEnableNewHud = 0;
		}

		if (!m_pNewMuzzleflashSwitch->GetActiveItem())
			gConfigs.bEnableNewMuzzle = 1;
		else
			gConfigs.bEnableNewMuzzle = 0;

		if (!m_pFireDlightSwitch->GetActiveItem())
			gConfigs.bEnableFireDlight = 1;
		else
			gConfigs.bEnableFireDlight = 0;

		if (!m_pBloodSwitch->GetActiveItem())
			gConfigs.bEnableBlood = 1;
		else
			gConfigs.bEnableBlood = 0;

		bool bClose = true;

		if (m_pLanguageSelection->GetActiveItem() != 3)
		{
			if (
				(m_pLanguageSelection->GetActiveItem() == 0 && Q_stricmp(gConfigs.szLanguage, "schinese")) ||
				(m_pLanguageSelection->GetActiveItem() == 1 && Q_stricmp(gConfigs.szLanguage, "tchinese")) ||
				(m_pLanguageSelection->GetActiveItem() == 2 && Q_stricmp(gConfigs.szLanguage, "english"))
				)
			{
				bClose = false;

				CCSBTEAboutDialogMessageBox *msgbox;
				msgbox = new CCSBTEAboutDialogMessageBox(L"Warning", L"The language is only changed when you next run the game.\n* Your Steam Language, the game launcher and weapon editor's language will also be changed here\n* The Localized String Table File for languages except Chinese Simplified may not be full.", this);
				msgbox->SetOKButtonText(L"Yes");
				msgbox->SetCancelButtonText(L"Cancel");
				msgbox->SetOKButtonVisible(true);
				msgbox->SetCancelButtonVisible(true);
				msgbox->SetBounds(GetWide() / 2 - 150, GetTall() / 2 - 100, 300, 200);

				msgbox->Activate();

				SetKeyBoardInputEnabled(false);
				SetMouseInputEnabled(false);
			}
		}

		Config_Save();
		if (bClose)
			Close();
	}
	else if (!Q_stricmp(command, "vguicancel"))
		Close();
	else if (!Q_stricmp(command, "OnOK"))
	{
		switch (m_pLanguageSelection->GetActiveItem())
		{
		case 0:
			//Q_strcpy(gConfigs.szLanguage, "schinese");
			system()->SetRegistryString("HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language", "schinese");
			break;
		case 1:
			//Q_strcpy(gConfigs.szLanguage, "tchinese");
			system()->SetRegistryString("HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language", "tchinese");
			break;
		case 2:
			//Q_strcpy(gConfigs.szLanguage, "english");
			system()->SetRegistryString("HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language", "english");
			break;
		}
		SetKeyBoardInputEnabled(true);
		SetMouseInputEnabled(true);
		Close();

		// Force restart of entire engine
		engine->pfnClientCmd("fmod stop\n");
		engine->pfnClientCmd("_restart\n");
	}
	else if (!Q_stricmp(command, "OnCancel"))
	{
		SetKeyBoardInputEnabled(true);
		SetMouseInputEnabled(true);
	}
	else
		BaseClass::OnCommand(command);
}