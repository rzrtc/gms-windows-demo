#pragma once
#include "RZGMSHandler.h"

class RZGMSObject
{
private:
	RZGMSObject() {}
	~RZGMSObject() {}
	
public:
	static RZGMSObject* Instance();
	static void Destroy();
	RZGMS* GetRZGMSInstance();
	InvitationManager* GetInvitationManagerInstance();
private:
	static RZGMSObject *m_pRZGMSObject;
	RZGMS* m_pRZGMS = nullptr;
	InvitationManager* m_pInvitationManager = nullptr;
	RZGMSInvitationHandler* m_pRZGMSInvitationHandler = nullptr;
	RZGMSPrivateHandler* m_pRZGMSPrvHandler = nullptr;
};

