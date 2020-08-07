#include "ObjectMngr.h"
ObjectMngr* ObjectMngr::m_pObjMngr = nullptr;

ObjectMngr *ObjectMngr::GetObjectManager()
{
	if (!m_pObjMngr)
	{
		m_pObjMngr = new ObjectMngr;
	}

	return m_pObjMngr;
}