#pragma once
#include "Task.h"
class Proactor;
class Listener : Task
{
public :
	Listener(Proactor& iocp);
	virtual ~Listener();

	bool Initialize(USHORT port);

private :
	virtual void DoWork() override;

	HANDLE proactor_handle_;
	SOCKET server_socket_;
};