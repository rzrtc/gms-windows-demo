#include "DbyGmsObject.h"
DbyGmsObject *DbyGmsObject::m_pDbyGmsObject = nullptr;
DbyGmsObject* DbyGmsObject::Instance()
{
	if (!m_pDbyGmsObject)
	{
		m_pDbyGmsObject = new DbyGmsObject;
	}

	return m_pDbyGmsObject;
}

void DbyGmsObject::Destroy()
{
	if (m_pDbyGmsObject)
	{
		delete m_pDbyGmsObject;
		m_pDbyGmsObject = nullptr;
	}
}

DbyGms* DbyGmsObject::GetDbyGmsInstance()
{
	if (!m_pDbyGms)
	{
		m_pDbyGms = createDbyGmsEngine();
		m_pDbyGmsPrvHandler = new DbyGmsPrivateHandler;
		m_pDbyGms->initialize("1824a0bff47e4f47bdce956c5e9025ad", m_pDbyGmsPrvHandler);
	}
	return m_pDbyGms;
}

InvitationManager* DbyGmsObject::GetInvitationManagerInstance()
{
	if (!m_pInvitationManager)
	{
		m_pDbyGmsInvitationHandler = new DbyGmsInvitationHandler;
		m_pInvitationManager = DbyGmsObject::Instance()->GetDbyGmsInstance()->getGmsInvitationManager(m_pDbyGmsInvitationHandler);
	}

	return m_pInvitationManager;
}