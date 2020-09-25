#include "DbyGmsHandler.h"
#include <QDebug>
#include "ObjectMngr.h"
void DbyGmsInvitationHandler::onFailure(Invitation *invitation, INVITATION_ERR_CODE reason)
{
	if (!invitation)
		return;
	QString inviter, invitee, requestInfo, responseInfo;
	int state;
	inviter = invitation->getInviter();
	invitee = invitation->getInvitee();
	requestInfo = invitation->getRequestInfo();
	responseInfo = invitation->getResponseInfo();
	state = (int)invitation->getState();
	int res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), "SigFailure", Q_ARG(QString, inviter), Q_ARG(QString, invitee), Q_ARG(QString, requestInfo), Q_ARG(QString, responseInfo), Q_ARG(int, state), Q_ARG(int, (int)reason));
}

void DbyGmsInvitationHandler::onArrived(Invitation *invitation)
{
	if (!invitation)
		return;
	InvokeData("SigArrived", invitation);
}

void DbyGmsInvitationHandler::onCanceled(Invitation *invitation)
{
	if (!invitation)
		return;
	InvokeData("SigCanceled", invitation);
}

void DbyGmsInvitationHandler::onAccepted(Invitation *invitation)
{
	if (!invitation)
		return;
	InvokeData("SigAccepted", invitation);
}

void DbyGmsInvitationHandler::onRefused(Invitation *invitation)
{
	if (!invitation)
		return;
	InvokeData("SigRefused", invitation);
}

void DbyGmsInvitationHandler::onInvitationApiCallError(INVITATION_API_CALL_ERR_CODE errorcode)
{
	int res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), "SigInvitationApiCallError", Q_ARG(int, (int)errorcode));
}

void DbyGmsInvitationHandler::InvokeData(const char* type, Invitation *invitation)
{
	if (!invitation || std::string(type).empty())
		return;
	QString inviter, invitee, requestInfo, responseInfo;
	int state;
	inviter = invitation->getInviter();
	invitee = invitation->getInvitee();
	requestInfo = invitation->getRequestInfo();
	responseInfo = invitation->getResponseInfo();
	state = (int)invitation->getState();
	bool res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), type, Qt::QueuedConnection, Q_ARG(QString, inviter), Q_ARG(QString, invitee), Q_ARG(QString, requestInfo), Q_ARG(QString, responseInfo), Q_ARG(int, state));
	qDebug() << "type = " << type << " res = " << res;
}

void DbyGmsPrivateHandler::onLoginSuccess()
{
	/*qDebug() << "onLoginSuccess";
	int res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), "SigLogin");
	qDebug() << "onLoginSuccess  " << res;*/
}

void DbyGmsPrivateHandler::onLoginFailure(LOGIN_ERR_CODE errorCode)
{
	int res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), "SigLoginFailure", Q_ARG(int, (int)errorCode));
	qDebug() << "onLoginFailure " << errorCode;
}

void DbyGmsPrivateHandler::onLogout(LOGOUT_ERR_CODE errorcode)
{
	int res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), "SigLogout", Q_ARG(int, (int)errorcode));
	qDebug() << "onLogout " << errorcode;
}

void DbyGmsPrivateHandler::onConnectionStateChanged(CONNECTION_STATE state, CONNECTION_CHANGE_REASON reason)
{
	int res = QMetaObject::invokeMethod(ObjectMngr::GetObjectManager(), "SigConnectionStateChanged", Q_ARG(int, (int)state), Q_ARG(int, (int)reason));
	qDebug() << "onConnectionStateChanged " << state << "  " << reason;
}