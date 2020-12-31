#include "RZGMSObject.h"
RZGMSObject *RZGMSObject::m_pRZGMSObject = nullptr;
RZGMSObject* RZGMSObject::Instance()
{
	if (!m_pRZGMSObject)
	{
		m_pRZGMSObject = new RZGMSObject;
	}

	return m_pRZGMSObject;
}

void RZGMSObject::Destroy()
{
	if (m_pRZGMSObject)
	{
		delete m_pRZGMSObject;
		m_pRZGMSObject = nullptr;
	}
}

RZGMS* RZGMSObject::GetRZGMSInstance()
{
	if (!m_pRZGMS)
	{
		m_pRZGMS = createRZGMSEngine();
		m_pRZGMSPrvHandler = new RZGMSPrivateHandler;
		m_pRZGMS->initialize("1824a0bff47e4f47bdce956c5e9025ad", m_pRZGMSPrvHandler);
	}
	return m_pRZGMS;
}

InvitationManager* RZGMSObject::GetInvitationManagerInstance()
{
	if (!m_pInvitationManager)
	{
		m_pRZGMSInvitationHandler = new RZGMSInvitationHandler;
		m_pInvitationManager = RZGMSObject::Instance()->GetRZGMSInstance()->getGMSInvitationManager(m_pRZGMSInvitationHandler);
	}

	return m_pInvitationManager;
}