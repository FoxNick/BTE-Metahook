//========= Copyright ?1996-2002, Valve LLC, All rights reserved. ============
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#include "CreateMultiplayerGameServerPage.h"

using namespace vgui;

#include <KeyValues.h>
#include <vgui_controls/ComboBox.h>
#include <vgui_controls/MessageBox.h>
#include <vgui_controls/RadioButton.h>
#include "FileSystem.h"
#include "EngineInterface.h"
#include "io.h"
#include "ModInfo.h"
//#include "Random.h"
#include "util.h"
#include "common.h"

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>

#define RANDOM_MAP "< Random Map >"

bool CaselessStringLessThan( const CUtlSymbol &lhs, const CUtlSymbol &rhs )
{
	if ( !lhs.IsValid() )
		return false;

	if ( !rhs.IsValid() )
		return true;

	return stricmp( lhs.String(), rhs.String() ) < 0;
}

//-----------------------------------------------------------------------------
// Purpose: Constructor
//-----------------------------------------------------------------------------
CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage(vgui::Panel *parent, const char *name) : PropertyPage(parent, name), m_MapNames( 0, 0, CaselessStringLessThan )
{
	// we can use this if we decide we want to put "listen server" at the end of the game name
//	static char szHostName[256];
//	_snprintf( szHostName, sizeof( szHostName ) - 1, "%s %s", ModInfo().GetGameDescription(), "Listen Server" );
//	szHostName[sizeof( szHostName ) - 1] = '\0';

	// we can use this if we decide we want to put "listen server" at the end of the game name
	m_pMapList = new ComboBox(this, "MapList", 12, false);
	m_pModeList = new ComboBox(this, "ModeList", 12, false);

	m_pBotQuotaCombo = new TextEntry( this, "BotQuotaCombo" );
	m_pEnableTutorCheck = new CCvarToggleCheckButton( this, "CheckButtonTutor", "#CStrike_Tutor_Enabled", "tutor_enable" );
	m_pEnableBotsCheck = new CheckButton( this, "EnableBotsCheck", "Enable bots" );

	LoadControlSettings("Resource/CreateMultiplayerGameServerPage.res");

	LoadModeList();
	LoadMapList();

	if ( stricmp( ModInfo().GetGameDescription(), "Condition Zero" ) )
		m_pEnableTutorCheck->SetVisible( false );

	m_szMapName[0]  = 0;
	m_szHostName[0] = 0;
	m_szPassword[0] = 0;
	m_iMaxPlayers = engine->GetMaxClients();

	// make sure this will be a multiplayer game
	if ( m_iMaxPlayers <= 1 )
	{
		m_iMaxPlayers = 20; // this was the default for the old launcher
	}

	// initialize hostname
	SetControlString("ServerNameEdit", ModInfo().GetGameDescription());//szHostName);

	// initialize password
	SetControlString("PasswordEdit", engine->pfnGetCvarString("sv_password"));


//	int maxPlayersEdit = atoi( GetControlString( "MaxPlayersEdit", "-1" ) );
//	if ( maxPlayersEdit <= 1 )
	{
		// initialize maxplayers
		char szBuffer[4];
		_snprintf(szBuffer, sizeof(szBuffer)-1, "%d", m_iMaxPlayers);
		szBuffer[sizeof(szBuffer)-1] = '\0';
		SetControlString("MaxPlayersEdit", szBuffer);
	}
}

//-----------------------------------------------------------------------------
// Purpose: Destructor
//-----------------------------------------------------------------------------
CCreateMultiplayerGameServerPage::~CCreateMultiplayerGameServerPage()
{
}

//-----------------------------------------------------------------------------
// Purpose: called to get the info from the dialog
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::OnApplyChanges()
{
	strncpy(m_szHostName, GetControlString("ServerNameEdit", "Half-Life"), DATA_STR_LENGTH);
	strncpy(m_szPassword, GetControlString("PasswordEdit", ""), DATA_STR_LENGTH);
	m_iMaxPlayers = atoi(GetControlString("MaxPlayersEdit", "8"));

	KeyValues *kv = m_pMapList->GetActiveItemUserData();
	strncpy(m_szMapName, kv->GetString("mapname", ""), DATA_STR_LENGTH);
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::SetBotQuota( int quota )
{
	char buf[32];
	sprintf( buf, "%d", quota );
	m_pBotQuotaCombo->SetText( buf );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::SetBotsEnabled( bool enabled )
{
	m_pEnableBotsCheck->SetSelected( enabled );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int CCreateMultiplayerGameServerPage::GetBotQuota( void )
{
	char buf[32];
	m_pBotQuotaCombo->GetText( buf, sizeof( buf ) );
	return atoi( buf );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
bool CCreateMultiplayerGameServerPage::GetBotsEnabled( void )
{
	return m_pEnableBotsCheck->IsSelected();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::LoadModeList()
{
	m_pModeList->DeleteAllItems();

	char szPlugin[128];
	char szName[128];

	for (int i = 0; i < MAX_GAMEMODES; i++)
	{
		GetPrivateProfileString(va("GameMode%d", i), "Plugin", "", szPlugin, 127, "cstrike\\gamemodes.ini");
		GetPrivateProfileString(va("GameMode%d", i), "Name", "", szName, 127, "cstrike\\gamemodes.ini");

		if (!szPlugin[0]|| !szName[0])
			continue;

		m_pModeList->AddItem(szName, NULL);

	}
}

void CCreateMultiplayerGameServerPage::UpdateMode()
{
	UpdateCurrentMode(m_pModeList->GetActiveItem());
}

void CCreateMultiplayerGameServerPage::UpdateCurrentMode(int i)
{
	char szMode[16], szPath[128], szFilename2[128];

	_finddata_t fileDir;
	long lfDir;
	if ((lfDir = _findfirst(".\\cstrike\\addons\\amxmodx\\configs\\plugins-*.ini", &fileDir)) != -1l)
	{
		do
		{
			if (sscanf(fileDir.name, "plugins-%s", szMode) == 1)
			{
				szMode[strlen(szMode) - 4] = '\0';
				sprintf(szPath, "cstrike\\addons\\amxmodx\\configs\\plugins-%s.ini", szMode);
				sprintf(szFilename2, "cstrike\\addons\\amxmodx\\configs\\disabled-%s.ini", szMode);
				rename(szPath, szFilename2);
			}

		} while (_findnext(lfDir, &fileDir) == 0);
	}
	_findclose(lfDir);

	char szPlugin[128];
	GetPrivateProfileString(va("GameMode%d", i), "Plugin", "", szPlugin, 127, "cstrike\\gamemodes.ini");

	sprintf(szPath, "cstrike\\addons\\amxmodx\\configs\\disabled-%s.ini", szPlugin);
	sprintf(szFilename2, "cstrike\\addons\\amxmodx\\configs\\plugins-%s.ini", szPlugin);
	rename(szPath, szFilename2);

	/*
	if (!szPlugin[0] || rename(szPath, szFilename2) != 0)
	{
		vgui::MessageBox *msgbox;
		msgbox = new vgui::MessageBox("", "#CSBTE_ModeSelection_Error", this);
		msgbox->SetOKButtonText("#GameUI_OK");
		msgbox->SetOKButtonVisible(true);
		msgbox->SetBounds(GetWide() / 2 - 150, GetTall() / 2 - 100, 300, 200);

		msgbox->Activate();
	}*/
}

const int CCreateMultiplayerGameServerPage::GetModeID()
{
	return m_pModeList->GetActiveItem();
}

void CCreateMultiplayerGameServerPage::SetMode(const int id)
{
	m_pModeList->ActivateItem(id);
}

//-----------------------------------------------------------------------------
// Purpose: loads the list of available maps into the map list
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::LoadMaps( const char *pszPathID )
{
	FileFindHandle_t findHandle = NULL;
	const char *pszMPFilter = ModInfo().GetMPFilter();
	if ( pszMPFilter && pszMPFilter[0] == 0 )
		pszMPFilter = NULL;

	const char *pszFilename = g_pFullFileSystem->FindFirst("maps/*.bsp", &findHandle, pszPathID);
	while (pszFilename)
	{
		// remove the text 'maps/' and '.bsp' from the file name to get the map name
		char mapname[256];
		
		char *str = (char *)strstr(pszFilename, "maps");
		if (str)
		{
			strncpy(mapname, str + 5, sizeof(mapname) - 1);	// maps + \\ = 5
		}
		else
		{
			strncpy(mapname, pszFilename, sizeof(mapname) - 1);
		}
		str = strstr(mapname, ".bsp");
		if (str)
		{
			*str = 0;
		}

		//!! hack: strip out single player HL maps
		// this needs to be specified in a seperate file
		if (!stricmp(ModInfo().GetGameDescription(), "Half-Life" ) && (mapname[0] == 'c' || mapname[0] == 't') && mapname[2] == 'a' && mapname[1] >= '0' && mapname[1] <= '5')
		{
			goto nextFile;
		}

		if (!stricmp(ModInfo().GetGameDescription(), "Opposing Force" ) && mapname[0] == 'o' && mapname[1] == 'f')
		{
			goto nextFile;
		}

		if ( pszMPFilter && strstr( mapname, pszMPFilter ) )
		{
			goto nextFile;
		}

		// add to the map list
		if ( m_MapNames.Find( mapname ) == m_MapNames.InvalidIndex() )
		{
			m_MapNames.Insert( mapname );
		}

		// get the next file
	nextFile:
		pszFilename = g_pFullFileSystem->FindNext(findHandle);
	}
	g_pFullFileSystem->FindClose(findHandle);
}



//-----------------------------------------------------------------------------
// Purpose: loads the list of available maps into the map list
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::LoadMapList()
{
	// clear the current list (if any)
	m_MapNames.RemoveAll();
	m_pMapList->DeleteAllItems();

	// add special "name" to represent loading a randomly selected map
	m_pMapList->AddItem( "#GameUI_RandomMap", new KeyValues( "data", "mapname", RANDOM_MAP ) );

	// iterate the filesystem getting the list of all the files
	// UNDONE: steam wants this done in a special way, need to support that
	const char *pathID = "GAME";
	if ( !stricmp(ModInfo().GetGameDescription(), "Half-Life" ) ) 
	{
		pathID = NULL; // hl is the base dir
	}

	// Load the GameDir maps
	LoadMaps( pathID ); 

	// If we're not the Valve directory and we're using a "fallback_dir" in gameinfo.txt then include those maps...
	// (pathID is NULL if we're "Half-Life")
	const char *pszFallback = ModInfo().GetFallbackDir();
	if ( pathID && pszFallback[0] )
	{
		LoadMaps( "GAME_FALLBACK" );
	}

	LoadMaps( "GAMEDOWNLOAD" );

	for ( int i = m_MapNames.FirstInorder(); i != m_MapNames.InvalidIndex(); i = m_MapNames.NextInorder( i ) )
	{
		//m_pMapList->AddItem( m_MapNames[i].String(), new KeyValues( "data", "mapname", m_MapNames[i].String() ) );
		const char *p_ = strchr(m_MapNames[i].String(), '_');
		wchar_t *wstrResult = nullptr;
		if (p_)
			wstrResult = vgui::localize()->Find(va("#CSO_%s_kr", p_+1));
		if (!wstrResult)
			wstrResult = vgui::localize()->Find(va("#MapName_%s", m_MapNames[i].String()));
		if (!wstrResult)
			wstrResult = UTF8ToUnicode(m_MapNames[i].String());
		
		m_pMapList->AddItem(wstrResult, new KeyValues("data", "mapname", m_MapNames[i].String()));
	}
	m_MapNames.RemoveAll();

	// set the first item to be selected
	m_pMapList->ActivateItem( 0 );
}

bool CCreateMultiplayerGameServerPage::IsRandomMapSelected()
{
	const char *mapname = m_pMapList->GetActiveItemUserData()->GetString("mapname");
	if (!stricmp( mapname, RANDOM_MAP ))
	{
		return true;
	}
	return false;
}

const char *CCreateMultiplayerGameServerPage::GetMapName()
{
	int count = m_pMapList->GetItemCount();

	// if there is only one entry it's the special "select random map" entry
	if( count <= 1 )
		return NULL;

	const char *mapname = m_pMapList->GetActiveItemUserData()->GetString("mapname");
	if (!strcmp( mapname, RANDOM_MAP ))
	{
		int which = engine->pfnRandomLong(1, count - 1);
		mapname = m_pMapList->GetItemUserData( which )->GetString("mapname");
	}

	return mapname;
}

void CCreateMultiplayerGameServerPage::SetMap(const char *mapName)
{
	for (int i = 0; i < m_pMapList->GetItemCount(); i++)
	{
		if (!m_pMapList->IsItemIDValid(i))
			continue;

		if (!stricmp(m_pMapList->GetItemUserData(i)->GetString("mapname"), mapName))
		{
			m_pMapList->ActivateItem(i);
			break;
		}
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CCreateMultiplayerGameServerPage::OnCheckButtonChecked()
{
	SetControlEnabled("SkillLevelExpert", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("SkillLevelHard", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("SkillLevelNormal", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("SkillLevelEasy", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("BotQuotaCombo", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("BotDifficultyLabel", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("BotLabel1", m_pEnableBotsCheck->IsSelected());
	SetControlEnabled("BotLabel2", m_pEnableBotsCheck->IsSelected());
}