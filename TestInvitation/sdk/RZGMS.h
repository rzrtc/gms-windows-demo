#pragma once
#include <stdint.h>
#include <stddef.h>
#include <iostream>
#include <vector>
#include <map>
#define RZAPI_EXPORT

#define RZ_CALL __cdecl

#if defined(RZAPI_EXPORT)
#define RZ_API extern "C" __declspec(dllexport)
#else
#define RZ_API extern "C" __declspec(dllimport)
#endif


#define RZGMS_SDK_VERSION "1.3.0"

namespace rz {
	namespace gms {
		class RZGMSEventHandler;

		enum LOGIN_ERR_CODE {
			LOGIN_ERR_OK = 0,
			LOGIN_ERR_UNKNOWN = 1,
			LOGIN_ERR_REJECTED = 2, // Occurs when not initialized or server reject
			LOGIN_ERR_INVALID_ARGUMENT = 3,
			LOGIN_ERR_INVALID_APP_ID = 4,
			LOGIN_ERR_INVALID_TOKEN = 5,
			LOGIN_ERR_TOKEN_EXPIRED = 6,
			LOGIN_ERR_NOT_AUTHORIZED = 7,
			LOGIN_ERR_ALREADY_LOGGED_IN = 8,
			LOGIN_ERR_TIMEOUT = 9,
			LOGIN_ERR_TOO_OFTEN = 10,
			LOGIN_ERR_NOT_INITIALIZED = 101,
		};

		enum LOGOUT_ERR_CODE {
			LOGOUT_ERR_OK = 0,
			LOGOUT_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum CONNECTION_STATE {
			CONNECTION_STATE_DISCONNECTED = 1,
			CONNECTION_STATE_CONNECTING = 2,
			CONNECTION_STATE_CONNECTED = 3,
			CONNECTION_STATE_RECONNECTING = 4,
			CONNECTION_STATE_ABORTED = 5,
		};

		enum CONNECTION_CHANGE_REASON {
			CONNECTION_CHANGE_REASON_LOGIN = 1,
			CONNECTION_CHANGE_REASON_LOGIN_SUCCESS = 2,
			CONNECTION_CHANGE_REASON_LOGIN_FAILURE = 3,
			CONNECTION_CHANGE_REASON_LOGIN_TIMEOUT = 4,
			CONNECTION_CHANGE_REASON_INTERRUPTED = 5,
			CONNECTION_CHANGE_REASON_LOGOUT = 6,
			CONNECTION_CHANGE_REASON_BANNED_BY_SERVER = 7,
			CONNECTION_CHANGE_REASON_REMOTE_LOGIN = 8
		};

		enum JOIN_CHANNEL_ERR {
			JOIN_CHANNEL_ERR_OK = 0,
			JOIN_CHANNEL_ERR_FAILURE = 1,
			JOIN_CHANNEL_ERR_REJECTED = 2, // Usually occurs when the user is already in the channel
			JOIN_CHANNEL_ERR_INVALID_ARGUMENT = 3,
			JOIN_CHANNEL_TIMEOUT = 4,
			JOIN_CHANNEL_ERR_EXCEED_LIMIT = 5,
			JOIN_CHANNEL_ERR_ALREADY_JOINED = 6,
			JOIN_CHANNEL_ERR_TOO_OFTEN = 7,
			JOIN_CHANNEL_ERR_JOIN_SAME_CHANNEL_TOO_OFTEN = 8,
			JOIN_CHANNEL_ERR_NOT_INITIALIZED = 101,
			JOIN_CHANNEL_ERR_USER_NOT_LOGGED_IN = 102
		};

		enum LEAVE_CHANNEL_ERR {
			LEAVE_CHANNEL_ERR_OK = 0,
			LEAVE_CHANNEL_ERR_FAILURE = 1,
			LEAVE_CHANNEL_ERR_REJECTED = 2,
			LEAVE_CHANNEL_ERR_INVALID_ARGUMENT = 3,
			LEAVE_CHANNEL_ERR_TIMEOUT = 4,
			LEAVE_CHANNEL_ERR_ALREADY_LEAVE = 6,
			LEAVE_CHANNEL_ERR_NOT_INITIALIZED = 101,
			LEAVE_CHANNEL_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum GET_CHANNEL_MEMBER_COUNT_ERR_CODE {
			GET_CHANNEL_MEMBER_COUNT_ERR_OK = 0,
			GET_CHANNEL_MEMBER_COUNT_ERR_FAILURE = 1,
			GET_CHANNEL_MEMBER_COUNT_ERR_INVALID_ARGUMENT = 2,
			GET_CHANNEL_MEMBER_COUNT_ERR_TOO_OFTEN = 3,
			GET_CHANNEL_MEMBER_COUNT_ERR_TIMEOUT = 4,
			GET_CHANNEL_MEMBER_COUNT_ERR_EXCEED_LIMIT = 5,
			GET_CHANNEL_MEMBER_COUNT_ERR_NOT_INITIALIZED = 101,
			GET_CHANNEL_MEMBER_COUNT_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum GET_CHANNEL_MEMBERS_ERR {
			GET_CHANNEL_MEMBERS_ERR_OK = 0,
			GET_CHANNEL_MEMBERS_ERR_FAILURE = 1,
			GET_CHANNEL_MEMBERS_ERR_INVALID_ARGUMENT = 2,
			GET_CHANNEL_MEMBERS_ERR_TIMEOUT = 3,
			GET_CHANNEL_MEMBERS_ERR_TOO_OFTEN = 4,
			GET_CHANNEL_MEMBERS_ERR_NOT_IN_CHANNEL = 5,
			GET_CHANNEL_MEMBERS_ERR_NOT_INITIALIZED = 101,
			GET_CHANNEL_MEMBERS_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum ATTRIBUTE_OPERATION_ERR {
			ATTRIBUTE_OPERATION_ERR_OK = 0,
			ATTRIBUTE_OPERATION_ERR_FAILURE = 2,
			ATTRIBUTE_OPERATION_ERR_INVALID_ARGUMENT = 3,
			ATTRIBUTE_OPERATION_ERR_SIZE_OVERFLOW = 4,
			ATTRIBUTE_OPERATION_ERR_TOO_OFTEN = 5,
			ATTRIBUTE_OPERATION_ERR_USER_NOT_FOUND = 6,
			ATTRIBUTE_OPERATION_ERR_TIMEOUT = 7,
			ATTRIBUTE_OPERATION_ERR_NOT_INITIALIZED = 101,
			ATTRIBUTE_OPERATION_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum CHANNEL_MESSAGE_ERR_CODE {
			CHANNEL_MESSAGE_ERR_OK = 0,
			CHANNEL_MESSAGE_ERR_FAILURE = 1,
			CHANNEL_MESSAGE_ERR_SENT_TIMEOUT = 2,
			CHANNEL_MESSAGE_ERR_TOO_OFTEN = 3,
			CHANNEL_MESSAGE_ERR_INVALID_MESSAGE = 4,
			CHANNEL_MESSAGE_ERR_NOT_IN_CHANNEL = 5,
			CHANNEL_MESSAGE_ERR_NOT_INITIALIZED = 101,
			CHANNEL_MESSAGE_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum QUERY_PEERS_ONLINE_STATUS_ERR {
			QUERY_PEERS_ONLINE_STATUS_ERR_OK = 0,
			QUERY_PEERS_ONLINE_STATUS_ERR_FAILURE = 1,
			QUERY_PEERS_ONLINE_STATUS_ERR_INVALID_ARGUMENT = 2,
			QUERY_PEERS_ONLINE_STATUS_ERR_TIMEOUT = 4,
			QUERY_PEERS_ONLINE_STATUS_ERR_TOO_OFTEN = 5,
			QUERY_PEERS_ONLINE_STATUS_ERR_NOT_INITIALIZED = 101,
			QUERY_PEERS_ONLINE_STATUS_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR {
			QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR_OK = 0,
			QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR_FAILURE = 1,
			QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR_TIMEOUT = 2,
			QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR_TOO_OFTEN = 3,
			QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR_NOT_INITIALIZED = 101,
			QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum PEER_SUBSCRIPTION_STATUS_ERR {
			PEER_SUBSCRIPTION_STATUS_ERR_OK = 0,
			PEER_SUBSCRIPTION_STATUS_ERR_FAILURE = 1,
			PEER_SUBSCRIPTION_STATUS_ERR_INVALID_ARGUMENT = 2,
			PEER_SUBSCRIPTION_STATUS_ERR_TIMEOUT = 4,
			PEER_SUBSCRIPTION_STATUS_ERR_TOO_OFTEN = 5,
			PEER_SUBSCRIPTION_STATUS_ERR_OVERFLOW = 6,
			PEER_SUBSCRIPTION_STATUS_ERR_NOT_INITIALIZED = 101,
			PEER_SUBSCRIPTION_STATUS_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum MESSAGE_TYPE {
			MESSAGE_TYPE_UNDEFINED = 0,
			MESSAGE_TYPE_TEXT = 1,
			MESSAGE_TYPE_RAW = 2,
			MESSAGE_TYPE_FILE = 3,
			MESSAGE_TYPE_IMAGE = 4,
		};

		enum PEER_MESSAGE_ERR_CODE {
			PEER_MESSAGE_ERR_OK = 0,
			PEER_MESSAGE_ERR_FAILURE = 1,
			PEER_MESSAGE_ERR_SENT_TIMEOUT = 2,
			PEER_MESSAGE_ERR_PEER_UNREACHABLE = 3,
			PEER_MESSAGE_ERR_CACHED_BY_SERVER = 4,
			PEER_MESSAGE_ERR_TOO_OFTEN = 5,
			PEER_MESSAGE_ERR_INVALID_USERID = 6,
			PEER_MESSAGE_ERR_INVALID_MESSAGE = 7,
			PEER_MESSAGE_ERR_NOT_INITIALIZED = 101,
			PEER_MESSAGE_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum PEER_SUBSCRIPTION_OPTION {
			PEER_SUBSCRIPTION_OPTION_ONLINE_STATUS = 0,
			PEER_SUBSCRIPTION_OPTION_USER_ATTRIBUTES = 1
		};

		enum PEER_ONLINE_STATE {
			PEER_ONLINE_STATE_ONLINE = 0,
			/*PEER_ONLINE_STATE_UNREACHABLE = 1,*/
			PEER_ONLINE_STATE_OFFLINE = 2,
		};

		enum RENEW_TOKEN_ERR_CODE {
			RENEW_TOKEN_ERR_OK = 0,
			RENEW_TOKEN_ERR_FAILURE = 1,
			RENEW_TOKEN_ERR_INVALID_ARGUMENT = 2,
			RENEW_TOKEN_ERR_REJECTED = 3,
			RENEW_TOKEN_ERR_TOO_OFTEN = 4,
			RENEW_TOKEN_ERR_TOKEN_EXPIRED = 5,
			RENEW_TOKEN_ERR_INVALID_TOKEN = 6,
			RENEW_TOKEN_ERR_NOT_INITIALIZED = 101,
			RENEW_TOKEN_ERR_USER_NOT_LOGGED_IN = 102,
		};

		enum INVITATION_STATE_TYPE {
			INVITATION_STATE_IDLE = 0,
			INVITATION_STATE_FAILURE,
			INVITATION_STATE_ARRIVED,
			INVITATION_STATE_CANCELED,
			INVITATION_STATE_ACCEPTED,
			INVITATION_STATE_REFUSED
		};

		enum INVITATION_API_CALL_ERR_CODE {
			INVITATION_API_CALL_ERR_OK = 0,
			INVITATION_API_CALL_ERR_FAILURE = 1,
			INVITATION_API_CALL_ERR_INVALID_ARGUMENT = 2,
			INVITATION_API_CALL_ERR_INVALID_STATE = 3,
			INVITATION_API_CALL_ERR_PEER_OFFLINE = 4,
			INVITATION_API_CALL_ERR_WRONG_IDENTITY = 5,
			INVITATION_API_CALL_ERR_USER_NOT_LOGGED_IN = 102
		};

		enum INVITATION_ERR_CODE {
			INVITATION_ERR_OK = 0,
			INVITATION_ERR_UNKNOWN, 
			INVITATION_ERR_INVITATION_EXPIRE,
			INVITATION_ERR_NOT_LOGGED_IN
		};

		struct EnvConfig
		{
			std::string* apiServer = nullptr;
		};

		struct RZGMSOptions
		{
			EnvConfig envConfig;
		};

		struct SendMessageOptions {
			bool enableOfflineMessaging;
			bool enableHistoricalMessaging;

			SendMessageOptions() : enableOfflineMessaging(false), enableHistoricalMessaging(false) {}
		};

		struct ChannelAttributeOptions {
			bool enableNotificationToChannelMembers;
			ChannelAttributeOptions() :enableNotificationToChannelMembers(true) {}
		};

		struct ChannelMemberCount
		{
			const char* channelId;
			int count;
		};
		struct IAttribute
		{
			const char* key;
			const char* value;
		};

		struct PeersUserAttributes {
			const char* userId;
			std::vector<IAttribute> attributes;
		};

		struct PeerOnlineStatus
		{
			const char* peerId;
			bool isOnline;
			PEER_ONLINE_STATE onlineState;
		};

		struct TavernSocketInfo
		{
			std::string apiServer ; // web端服务器地址
			std::string tavernServer ; // 当前连接的websocket服务器地址
			std::string connectionId; // 当前 socket.io 实例的 id 值
		};

		struct LoginArgumentsInfo
		{
			std::string userId; // 用户login时传入的userId值
			std::string token; // 用户login时传入的token值
			uint64_t timestamp; // 用户login时传入的timestamp值
		};

		typedef std::map<std::string, std::string> KeyValues;
		typedef std::map<std::string, KeyValues> PeersAttributesMap;

		struct DebugInfo
		{
			std::string sdkVersion  ; // SDK的版本号
			TavernSocketInfo tavernSocket;
			LoginArgumentsInfo loginArguments;
		};

		class IMessage
		{
		protected:
			virtual ~IMessage() {}
		public:
			virtual long long getMessageId() const  = 0;

			virtual MESSAGE_TYPE getMessageType() const = 0;

			virtual void setMessageType(MESSAGE_TYPE msgType) = 0;

			virtual void setText(const char *str) = 0;

			virtual const char *getText() const = 0;

			virtual const uint8_t *getRawMessageData() const = 0;

			virtual int getRawMessageLength() const = 0;

			virtual long long getServerReceivedTs() const = 0;

			virtual bool isOfflineMessage() const = 0;

			virtual void release() = 0;
		};

		class IChannelMember
		{
		protected:
			virtual ~IChannelMember() {}
		public:
			virtual const char * getUserId() const = 0;
			virtual const char * getChannelId() const = 0;
			virtual void release() = 0;
		};


		class IChannelAttribute
		{
		protected:
			virtual ~IChannelAttribute() {}
		public:
			virtual void setKey(const char *key) = 0;
			virtual const char *getKey() const = 0;
			virtual void setValue(const char *value) = 0;
			virtual const char *getValue() const = 0;
			virtual const char *getLastUpdateUserId() const = 0;
			virtual long long getLastUpdateTs() const = 0;
			virtual void release() = 0;
		};

		class Invitation
		{
		protected:
			virtual ~Invitation() {}
		public:
			virtual void setInviter(const char* inviter) = 0;
			virtual void setInvitee(const char* invitee) = 0;
			virtual void setRequestInfo(const char* requestInfo) = 0;
			virtual void setResponseInfo(const char* responseInfo) = 0;
			virtual void setState(INVITATION_STATE_TYPE state) = 0;
			virtual INVITATION_STATE_TYPE getState() = 0;
			virtual const char* getInviter() = 0;
			virtual const char* getInvitee() = 0;
			virtual const char* getRequestInfo() = 0;
			virtual const char* getResponseInfo() = 0;
		};

		class GMSInvitationEventListener
		{
		public:
			virtual ~GMSInvitationEventListener() {};
		public:
			virtual void onFailure(Invitation *invitation, INVITATION_ERR_CODE reason)
			{
				(void)invitation;
				(void)reason;
			}
			virtual void onArrived(Invitation *invitation)
			{
				(void)invitation;
			}
			virtual void onCanceled(Invitation *invitation)
			{
				(void)invitation;
			}
			virtual void onAccepted(Invitation *invitation)
			{
				(void)invitation;
			}
			virtual void onRefused(Invitation *invitation)
			{
				(void)invitation;
			}

			virtual void onInvitationApiCallError(INVITATION_API_CALL_ERR_CODE errorcode)
			{
				(void)errorcode;
			}
		};

		class InvitationManager
		{
		protected:
			virtual ~InvitationManager() {}
		public:
			virtual Invitation* create(const char* inviter, const char* invitee, const char* requestInfo) = 0;
			virtual	void send(Invitation* invitation) = 0;
			virtual	void cancel(Invitation* invitation) = 0;
			virtual	void accept(Invitation* invitation) = 0;
			virtual	void refuse(Invitation* invitation) = 0;
			virtual int destroy(Invitation* invitation) = 0;
		};

		class RZGMS
		{
		protected:
			virtual ~RZGMS() {}
		public:
			virtual int initialize(const char* appId, RZGMSEventHandler* eventHandler, RZGMSOptions* options = nullptr) = 0;
			virtual void login(const char* token, const char* userId, uint64_t timestamp) = 0;
			virtual void logout() = 0;
			virtual int renewToken(const char* token, uint64_t timestamp) = 0;
			//频道相关
			virtual void join(const char* channelId, long long requestid) = 0;
			virtual void leave(const char* channelid, long long requestid) = 0;
			virtual void getChannelMemberCount(const char* channelIds[], int numberOfchannelId, long long requestid) = 0;
			virtual void getChannelMembers(const char* channelId, long long requestid) = 0;

			//频道属性
			virtual IChannelAttribute* createChannelAttribute() = 0;
			virtual int destroyChannelAttribute(IChannelAttribute* attr) = 0;
			virtual void setChannelAttributes(const char* channelid, const IChannelAttribute** attr, int numberOfAttributes, const ChannelAttributeOptions& options, long long requestid) = 0;
			virtual void addOrUpdateChannelAttributes(const char* channelid, const IChannelAttribute** attr, int numberOfAttributes, const ChannelAttributeOptions& options, long long requestid) = 0;
			virtual void deleteChannelAttributesByKeys(const char* channelid, const char* attrkeys[], int numberOfKeys, const ChannelAttributeOptions& options, long long requestid) = 0;
			virtual void clearChannelAttributes(const char* channelid, const ChannelAttributeOptions& options, long long requestid) = 0;
			virtual void getChannelAttributes(const char* channelId, long long requestid) = 0;
			virtual void getChannelAttributesByKeys(const char* channelId, const char* attrkeys[], int numberOfKeys, long long requestid) = 0;
			
			//频道消息
			virtual void sendChannelMessage(const char* channelid, const IMessage* message, const SendMessageOptions& options, long long requestid) = 0;

			//用户属性
			virtual void setLocalUserAttributes(const IAttribute* attributes, int numberOfAttributes, long long requestid) = 0;
			virtual void addOrUpdateLocalUserAttributes(const IAttribute* attributes, int numberOfAttributes, long long requestid) = 0;
			virtual void deleteLocalUserAttributesByKeys(const char* attributesKeys[], int numberOfKeys, long long requestid) = 0;
			virtual void clearLocalUserAttributes(long long requestid) = 0;
			virtual void getUserAttributes(const char* userId, long long requestid) = 0;
			virtual void getUserAttributesByKeys(const char* userId, const char* attributesKeys[], int numberOfKeys, long long requestid) = 0;
			virtual void getPeersUserAttributes(const char** userId, int useridCount, long long requestid) = 0;
			virtual void getPeersUserAttributesByKeys(const char** userId, int useridCount, const char* attributesKeys[], int numberOfKeys, long long requestid) = 0;

			//查询和订阅用户在线状态
			virtual void queryPeersOnlineStatus(const char* userids[], int useridCount, long long requestId) = 0;
			virtual void queryPeersBySubscriptionOption(PEER_SUBSCRIPTION_OPTION option, long long requestId) = 0;
			virtual void subscribePeersOnlineStatus(const char* userids[], int useridCount, long long requestId) = 0;
			virtual void unsubscribePeersOnlineStatus(const char* userids[], int useridCount, long long requestId) = 0;
			virtual void subscribePeersUserAttributes(const char* userids[], int useridCount, long long requestId) = 0;
			virtual void unsubscribePeersUserAttributes(const char* userids[], int useridCount, long long requestId) = 0;
			
			//点对点
			virtual IMessage* createMessage() = 0;
			virtual IMessage* createMessage(const char* message) = 0;
			virtual IMessage* createMessage(const uint8_t* rawData, int length) = 0;
			virtual IMessage* createMessage(const uint8_t* rawData, int length, const char* description) = 0;
			virtual int destroyMessage(IMessage* msg) = 0;
			virtual void sendMessageToPeer(const char* peerId, const IMessage* message, const SendMessageOptions& options, long long requestid) = 0;

			//呼叫邀请
			virtual InvitationManager* getGMSInvitationManager(GMSInvitationEventListener* handler) = 0;

			//TESTtoken
			//virtual int getTokenParams(const char* appid, const char* userid, uint64_t timestamp, const char* appkey, char* token) = 0;
			virtual DebugInfo getDebugInfo() = 0;
		};

		class RZGMSEventHandler
		{
		public:
			virtual ~RZGMSEventHandler() {}

			virtual void onLoginSuccess() {}
			
			virtual void onLoginFailure(LOGIN_ERR_CODE errorCode) {
				(void)errorCode;
			}

			virtual void onLogout(LOGOUT_ERR_CODE errorcode) {
				(void)errorcode;
			}

			virtual void onTokenExpired()
			{

			}

			//DAIDING
			virtual void onConnectionStateChanged(CONNECTION_STATE state, CONNECTION_CHANGE_REASON reason) {
				(void)state;
				(void)reason;
			}
			//加入频道相关
			virtual void onJoin(JOIN_CHANNEL_ERR errorcode, long long requestid) {
				(void)errorcode;
				(void)requestid;
			}

			virtual void onLeave(LEAVE_CHANNEL_ERR errorcode, long long requestid) {
				(void)errorcode;
				(void)requestid;
			}
			//{}
			virtual void onGetChannelMemberCount(const ChannelMemberCount *channelMemberCounts, int channelCount, GET_CHANNEL_MEMBER_COUNT_ERR_CODE errorcode, long long requestid) {
				(void)channelMemberCounts;
				(void)channelCount;
				(void)errorcode;
				(void)requestid;
			}
			//
			virtual void onGetChannelMembers(IChannelMember** members, int 	userCount, GET_CHANNEL_MEMBERS_ERR errorcode, long long requestid) {
				(void)members;
				(void)userCount;
				(void)errorcode;
				(void)requestid;
			}

			virtual void onMemberJoined(const char* channnelId, const char* userId) {
				(void)channnelId;
				(void)userId;
			}

			//
			virtual void onMemberLeft(const char* channnelId, const char* userId) {
				(void)channnelId;
				(void)userId;
			}
			
			//频道属性
			virtual void onSetChannelAttributesResult(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onAddOrUpdateChannelAttributesResult(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}
			
			virtual void onDeleteChannelAttributesResult(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onClearChannelAttributesResult(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onGetChannelAttributesResult(const IChannelAttribute* attributes[], int numberOfAttributes, ATTRIBUTE_OPERATION_ERR code, long long requestid)
			{
				(void)attributes;
				(void)numberOfAttributes;
				(void)code;
				(void)requestid;
			}

			virtual void onGetChannelAttributesByKeys(const IChannelAttribute* attributes[], int numberOfAttributes, ATTRIBUTE_OPERATION_ERR code, long long requestid)
			{
				(void)attributes;
				(void)numberOfAttributes;
				(void)code;
				(void)requestid;
			}

			virtual void onChannelAttributesUpdated(const IChannelAttribute* attributes[], int numberOfAttributes)
			{
				(void)attributes;
				(void)numberOfAttributes;
			}
			
			//频道消息
			virtual void onSendChannelMessage(CHANNEL_MESSAGE_ERR_CODE code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onChannelMessageReceived(const char* channelid, const char* userid, const IMessage* msg) {
				(void)channelid;
				(void)userid;
				(void)msg;
			}

			//用户属性
			virtual void onSetLocalUserAttributes(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onAddOrUpdateLocalUserAttributes(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onDeleteLocalUserAttributesByKeys(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onClearLocalUserAttributes(ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}
			
			virtual void onGetUserAttributes(const IAttribute* attributes, int numberOfAttributes, ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)attributes;
				(void)numberOfAttributes;
				(void)code;
				(void)requestid;
			}

			virtual void onGetUserAttributesByKeys(const IAttribute* attributes, int numberOfAttributes, ATTRIBUTE_OPERATION_ERR code, long long requestid) {
				(void)attributes;
				(void)numberOfAttributes;
				(void)code;
				(void)requestid;
			}

			virtual void onGetPeersUserAttributes(ATTRIBUTE_OPERATION_ERR code, const PeersAttributesMap peerAttribute, long long requestid) {
				(void)code;
				(void)peerAttribute;
				(void)requestid;
			}

			virtual void onGetPeersUserAttributesByKeys(ATTRIBUTE_OPERATION_ERR code, const PeersAttributesMap peerAttribute, long long requestid) {
				(void)code;
				(void)peerAttribute;
				(void)requestid;
			}

			//查询和订阅用户
			virtual void onQueryPeersOnlineStatus(long long requestId, const PeerOnlineStatus* peersStatus, int peerCount, QUERY_PEERS_ONLINE_STATUS_ERR errorCode) {
				(void)requestId;
				(void)peersStatus;
				(void)peerCount;
				(void)errorCode;
			}

			virtual void onQueryPeersBySubscriptionOption(long long requestId, const char* peerIds[], int peerCount, QUERY_PEERS_BY_SUBSCRIPTION_OPTION_ERR errorCode) {
				(void)requestId;
				(void)peerIds;
				(void)peerCount;
				(void)errorCode;
			}

			virtual void onSubscribePeersOnlineStatus(PEER_SUBSCRIPTION_STATUS_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onUnsubscribePeersOnlineStatus(PEER_SUBSCRIPTION_STATUS_ERR code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onPeersOnlineStatusChanged(const PeerOnlineStatus *peersStatus, int peerCount) {
				(void)peersStatus;
				(void)peerCount;
			}

			virtual void onSubscribePeersUserAttributes(PEER_SUBSCRIPTION_STATUS_ERR code, const PeersUserAttributes* attributes, int idCount) {
				(void)code;
				(void)attributes;
				(void)idCount;
			}

			virtual void onUnsubscribePeersUserAttributes(PEER_SUBSCRIPTION_STATUS_ERR code, long long requestid) {
				(void)code;
			}

			//点对点消息
			virtual void onSendMessageToPeer(PEER_MESSAGE_ERR_CODE  code, long long requestid) {
				(void)code;
				(void)requestid;
			}

			virtual void onMessageReceivedFromPeer(const char* peerId, const IMessage* message) {
				(void)peerId;
				(void)message;
			}


		};


		RZ_API RZGMS* RZ_CALL createRZGMSEngine();
		RZ_API int RZ_CALL destroyRZGMSEngine(RZGMS* p);
	}
}
