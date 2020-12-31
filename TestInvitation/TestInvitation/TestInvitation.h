#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestInvitation.h"
#include "RZGMSObject.h"

class TestInvitation : public QMainWindow
{
    Q_OBJECT

public:
    TestInvitation(QWidget *parent = Q_NULLPTR);
	
public slots:
	void OnLogin();
	void OnLogout();
	void OnSend();
	void OnAccept();
	void OnRefuse();
	void OnCancel();

	void OnLoginSuccess();
	void OnLoginFailure(int code);
	void OnLogout(int code);
	void OnConnectionStateChanged(int, int);


	void OnFailure(QString inviter, QString invitee, QString request, QString response, int state, int reason);
	void OnArrived(QString inviter, QString invitee, QString request, QString response, int state);
	void OnCanceled(QString inviter, QString invitee, QString request, QString response, int state);
	void OnAccepted(QString inviter, QString invitee, QString request, QString response, int state);
	void OnRefused(QString inviter, QString invitee, QString request, QString response, int state);
	void OnInvitationApiCallError(int errorcode);
private:
	void init();
	void updateStatusBar(QString msg);
	Invitation* m_pInvitation = nullptr;
private:
    Ui::TestInvitationClass ui;
};
