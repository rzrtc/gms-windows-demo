#pragma once
#include "DbyGmsHandler.h"

class DbyGmsObject
{
private:
	DbyGmsObject() {}
	~DbyGmsObject() {}
	
public:
	static DbyGmsObject* Instance();
	static void Destroy();
	DbyGms* GetDbyGmsInstance();
	InvitationManager* GetInvitationManagerInstance();
private:
	static DbyGmsObject *m_pDbyGmsObject;
	DbyGms* m_pDbyGms = nullptr;
	InvitationManager* m_pInvitationManager = nullptr;
	DbyGmsInvitationHandler* m_pDbyGmsInvitationHandler = nullptr;
	DbyGmsPrivateHandler* m_pDbyGmsPrvHandler = nullptr;
};

