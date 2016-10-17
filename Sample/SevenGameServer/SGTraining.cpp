#include "StdAfx.h"
#include "SGTraining.h"

SGTraining::SGTraining(int mode)
: SFGameMode(mode)
{
}

SGTraining::~SGTraining(void)
{
}

//////////////////////////////////////////////////////
//Game Mode Initialization
//////////////////////////////////////////////////////
BOOL SGTraining::OnEnter( int gameMode )
{
	return TRUE;
}

//////////////////////////////////////////////////////
//Game End. Retrive allocated resources.
//////////////////////////////////////////////////////
BOOL SGTraining::Onleave()
{
	return TRUE;
}


//////////////////////////////////////////////////////
//Timer Event
//////////////////////////////////////////////////////
BOOL SGTraining::Update(DWORD timerId)
{
	return TRUE;
}

//////////////////////////////////////////////////////
//User Request
//////////////////////////////////////////////////////
BOOL SGTraining::ProcessUserRequest( SFPlayer* pPlayer, int msg )
{
	return TRUE;
}

BOOL SGTraining::ProcessUserRequest( SFPlayer* pPlayer, BasePacket* pPacket )
{
	return TRUE;
}