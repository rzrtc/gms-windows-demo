#include "TestInvitation.h"
#include <sstream>
#include "ObjectMngr.h"
#include "DbyGmsObject.h"
#include "md5.h"

#define APPID "1824a0bff47e4f47bdce956c5e9025ad"
#define APPKEY "24f5595baa8645fd947051e75ffcdcc4"
#define USERID "2"
std::string lltoString(long long timestamp);
uint64_t getSign(std::string &appid, std::string &userid, std::string &strtoken);

TestInvitation::TestInvitation(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	init();
	//³õÊ¼»¯
	DbyGmsObject::Instance()->GetDbyGmsInstance();
	DbyGmsObject::Instance()->GetInvitationManagerInstance();
}

void TestInvitation::OnLogin()
{
	std::string uid = ui.lineEdit_userid->text().toStdString();
	std::string token;
	uint64_t timestamp = getSign(std::string(APPID), uid, token);
	DbyGmsObject::Instance()->GetDbyGmsInstance()->login(token.c_str(), uid.c_str(), timestamp);
}

void TestInvitation::OnLogout()
{
	DbyGmsObject::Instance()->GetDbyGmsInstance()->logout();
}

void TestInvitation::OnSend()
{
	
	InvitationManager* pInvitationManager = DbyGmsObject::Instance()->GetInvitationManagerInstance();
	/*if (m_pInvitation)
	{

	}*/
	std::string uid = ui.lineEdit_userid->text().toStdString();
	std::string invitee = ui.lineEdit_invitee->text().toStdString();
	std::string requestinfo = ui.lineEdit_request->text().toStdString();
	if (uid.empty() || invitee.empty())
	{
		updateStatusBar("param error");
		return;
	}
		
	m_pInvitation = pInvitationManager->create(uid.c_str(), invitee.c_str(), requestinfo.c_str());
	pInvitationManager->send(m_pInvitation);

	//
	/*int ret = pInvitationManager->destroy(m_pInvitation);
	std::cout << "ret = " << ret << std::endl;*/
}

void TestInvitation::OnAccept()
{
	if (!m_pInvitation)
		return;

	DbyGmsObject::Instance()->GetInvitationManagerInstance()->accept(m_pInvitation);
}

void TestInvitation::OnRefuse()
{
	if (!m_pInvitation)
		return;

	DbyGmsObject::Instance()->GetInvitationManagerInstance()->refuse(m_pInvitation);
}

void TestInvitation::OnCancel()
{
	if (!m_pInvitation)
		return;

	DbyGmsObject::Instance()->GetInvitationManagerInstance()->cancel(m_pInvitation);
}

void TestInvitation::OnLoginSuccess()
{
	updateStatusBar("login success");
}

void TestInvitation::OnLoginFailure(int code)
{
	updateStatusBar("login failed");
}

void TestInvitation::OnLogout(int code)
{
	QString str = QString("logout code = %1").arg(code);
	updateStatusBar(str);
}

void TestInvitation::OnConnectionStateChanged(int state, int reason)
{
	QString str = QString("state = %1, reason = %2").arg(state).arg(reason);
	updateStatusBar(str);
}

void TestInvitation::OnFailure(QString inviter, QString invitee, QString request, QString response, int state, int reason)
{
	QString str = QString("OnFailure: state = %1, reason = %2").arg(state).arg(reason);
	ui.textEdit->append(str);
}

void TestInvitation::OnArrived(QString inviter, QString invitee, QString request, QString response, int state)
{
	if (!m_pInvitation)
	{
		m_pInvitation = DbyGmsObject::Instance()->GetInvitationManagerInstance()->create(inviter.toLocal8Bit().constData(), invitee.toLocal8Bit().constData(), request.toLocal8Bit().constData());
	}

	/*m_pInvitation->setInviter(inviter.toLocal8Bit().constData());
	m_pInvitation->setInvitee(invitee.toLocal8Bit().constData());
	m_pInvitation->setRequestInfo(request.toLocal8Bit().constData());*/
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	//updateStatusBar("OnArrived");
	QString str = QString("OnArrived: state = %1").arg(state);
	ui.textEdit->append(str);
}

void TestInvitation::OnCanceled(QString inviter, QString invitee, QString request, QString response, int state)
{
	if (!m_pInvitation)
	{
		m_pInvitation = DbyGmsObject::Instance()->GetInvitationManagerInstance()->create(inviter.toLocal8Bit().constData(), invitee.toLocal8Bit().constData(), request.toLocal8Bit().constData());
	}

	/*m_pInvitation->setInviter(inviter.toLocal8Bit().constData());
	m_pInvitation->setInvitee(invitee.toLocal8Bit().constData());
	m_pInvitation->setRequestInfo(request.toLocal8Bit().constData());*/
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	QString str = QString("OnCanceled: state = %1").arg(state);
	ui.textEdit->append(str);
}

void TestInvitation::OnAccepted(QString inviter, QString invitee, QString request, QString response, int state)
{
	if (!m_pInvitation)
	{
		m_pInvitation = DbyGmsObject::Instance()->GetInvitationManagerInstance()->create(inviter.toLocal8Bit().constData(), invitee.toLocal8Bit().constData(), request.toLocal8Bit().constData());
	}

	/*m_pInvitation->setInviter(inviter.toLocal8Bit().constData());
	m_pInvitation->setInvitee(invitee.toLocal8Bit().constData());
	m_pInvitation->setRequestInfo(request.toLocal8Bit().constData());*/
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	QString str = QString("OnAccepted: state = %1").arg(state);
	ui.textEdit->append(str);
}

void TestInvitation::OnRefused(QString inviter, QString invitee, QString request, QString response, int state)
{
	if (!m_pInvitation)
	{
		m_pInvitation = DbyGmsObject::Instance()->GetInvitationManagerInstance()->create(inviter.toLocal8Bit().constData(), invitee.toLocal8Bit().constData(), request.toLocal8Bit().constData());
	}

	/*m_pInvitation->setInviter(inviter.toLocal8Bit().constData());
	m_pInvitation->setInvitee(invitee.toLocal8Bit().constData());
	m_pInvitation->setRequestInfo(request.toLocal8Bit().constData());*/
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	m_pInvitation->setResponseInfo(response.toLocal8Bit().constData());
	m_pInvitation->setState((INVITATION_STATE_TYPE)state);
	QString str = QString("OnRefused: state = %1").arg(state);
	ui.textEdit->append(str);
}

void TestInvitation::OnInvitationApiCallError(int errorcode)
{
	QString str = QString("OnInvitationApiCallError: errorcode = %1").arg(errorcode);
	ui.textEdit->append(str);
}

void TestInvitation::init()
{
	connect(ui.pushButton_login, SIGNAL(clicked()), this, SLOT(OnLogin()));
	connect(ui.pushButton_logout, SIGNAL(clicked()), this, SLOT(OnLogout()));
	connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(OnSend()));
	connect(ui.pushButton_accpet, SIGNAL(clicked()), this, SLOT(OnAccept()));
	connect(ui.pushButton_refuse, SIGNAL(clicked()), this, SLOT(OnRefuse()));
	connect(ui.pushButton_cancel, SIGNAL(clicked()), this, SLOT(OnCancel()));

	ObjectMngr* pObjMngr = ObjectMngr::GetObjectManager();
	connect(pObjMngr, SIGNAL(SigLogin()), this, SLOT(OnLoginSuccess()));
	connect(pObjMngr, SIGNAL(SigLoginFailure(int)), this, SLOT(OnLoginFailure(int)));
	connect(pObjMngr, SIGNAL(SigLogout(int)), this, SLOT(OnLogout(int)));
	connect(pObjMngr, SIGNAL(SigConnectionStateChanged(int, int)), this, SLOT(OnConnectionStateChanged(int, int)));

	connect(pObjMngr, SIGNAL(SigFailure(QString, QString, QString, QString, int, int)), this, SLOT(OnFailure(QString, QString, QString, QString, int, int)));

	connect(pObjMngr, SIGNAL(SigArrived(QString, QString, QString, QString, int)), this, SLOT(OnArrived(QString, QString, QString, QString, int)));
	connect(pObjMngr, SIGNAL(SigCanceled(QString, QString, QString, QString, int)), this, SLOT(OnCanceled(QString, QString, QString, QString, int)));
	connect(pObjMngr, SIGNAL(SigAccepted(QString, QString, QString, QString, int)), this, SLOT(OnAccepted(QString, QString, QString, QString, int)));
	connect(pObjMngr, SIGNAL(SigRefused(QString, QString, QString, QString, int)), this, SLOT(OnRefused(QString, QString, QString, QString, int)));
	connect(pObjMngr, SIGNAL(SigInvitationApiCallError(int)), this, SLOT(OnInvitationApiCallError(int)));
}

void TestInvitation::updateStatusBar(QString msg)
{
	statusBar()->showMessage(msg);
}

std::string lltoString(long long timestamp)
{
	std::string result;
	std::ostringstream ss;
	ss << timestamp;
	std::istringstream is(ss.str());
	is >> result;
	return result;
}

uint64_t getSign(std::string &appid, std::string &userid, std::string &strtoken)
{
	auto timeNow = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	std::map<std::string, std::string> strMap;
	strMap.insert(std::pair<std::string, std::string>("appId", appid));
	strMap.insert(std::pair<std::string, std::string>("userId", userid));
	strMap.insert(std::pair<std::string, std::string>("timestamp", lltoString(timeNow.count())));
	strtoken = md5(strMap, std::string(APPKEY));
	return timeNow.count();
}