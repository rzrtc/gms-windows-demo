#pragma once
#include <QObject>
#include <QMetaObject>

class ObjectMngr : public QObject
{
	Q_OBJECT
public:
	static ObjectMngr *GetObjectManager();
	~ObjectMngr() {}

signals:
	void SigLogin();
signals:
	void SigLoginFailure(int code);
signals:
	void SigLogout(int code);
signals:
	void SigConnectionStateChanged(int, int);
signals:
	void SigFailure(QString, QString, QString, QString, int, int);
signals:
	void SigArrived(QString, QString, QString, QString, int);
signals:
	void SigCanceled(QString, QString, QString, QString, int);
signals:					
	void SigAccepted(QString, QString, QString, QString, int);
signals:					
	void SigRefused(QString , QString, QString, QString, int);
signals:
	void SigInvitationApiCallError(int);

private:
	static ObjectMngr* m_pObjMngr;
};
