#pragma once
#include <DbyGms.h>
using namespace duobei;
using namespace gms;
class DbyGmsInvitationHandler : public GmsInvitationEventListener
{
public:
	DbyGmsInvitationHandler() {}
	virtual ~DbyGmsInvitationHandler() {}

	void onFailure(Invitation *invitation, INVITATION_ERR_CODE reason) override;
	void onArrived(Invitation *invitation) override;
	void onCanceled(Invitation *invitation) override;
	void onAccepted(Invitation *invitation) override;
	void onRefused(Invitation *invitation) override;
	void onInvitationApiCallError(INVITATION_API_CALL_ERR_CODE errorcode) override;

private:
	void InvokeData(const char* type, Invitation *invitation);
};

class DbyGmsPrivateHandler : public DbyGmsEventHandler
{
public:
	DbyGmsPrivateHandler() {}
	~DbyGmsPrivateHandler() {}

	void onLoginSuccess() override;
	void onLoginFailure(LOGIN_ERR_CODE errorCode) override;
	void onLogout(LOGOUT_ERR_CODE errorcode) override;
	void onConnectionStateChanged(CONNECTION_STATE state, CONNECTION_CHANGE_REASON reason) override;
};

