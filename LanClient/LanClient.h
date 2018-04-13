#ifndef __LANCLIENT__H__
#define __LANCLIENT__H__

class CLanClient
{
public :
	CLanClient();
	virtual ~CLanClient();

public :
	bool Connect(WCHAR wBindIP, DWORD dwWorkerThreadNum, bool bNagle);

	bool Disconnect();
	bool SendPacket(CNPacket *pPacket);

protected :
	virtual void OnEnterJoinServer() = 0;
	virtual void OnLeaveServer() = 0;

	virtual void OnRecv(CNPacket *pPacket);
	virtual void OnSend(CNPacket *pPacket);

	virtual void OnWorkerThreadBegin() = 0;
	virtual void OnWorkerThreadEnd() = 0;

	virtual void OnError(int iErrorcode, WCHAR *pMessage);

private :
	SOCKET _ClientSocket;

	bool _bNagle;

	int _iWorkerThreadNum;

	__int64 _iSessionID;


};

#endif