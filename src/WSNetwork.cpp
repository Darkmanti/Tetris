#include "WSNetwork.h"

void InitNetSocket()
{
	wsaError = WSAStartup(wVersion, &wsaData); // init winsock

	if (wsaError != 0)
	{
		con::Out("Could not initialize winsock\n");
	}
	else
	{
		hSock = socket(PF_INET, SOCK_STREAM, 0);
		if (hSock == INVALID_SOCKET)
		{
			con::Out("Could not create a socket. Error code:  ");
			con::Out(WSAGetLastError());
			con::Out('\n');
		}
	}

	con::Out("The socket application is up and running\n");

	switch (WSAGetLastError())
	{
	case WSANOTINITIALISED:
		con::Out("WSA NOT INITIALISED\n");
		break;
	case WSAENETDOWN:
		con::Out("error in the network subsystem\n");
		break;
	case WSAEAFNOSUPPORT:
		con::Out("the specified domain is not supported\n");
		break;
	case WSAEINPROGRESS:
		con::Out("winsock 1.1 blocking call is in progress\n");
		break;
	case WSAEMFILE:
		con::Out("no free socket descriptors\n");
		break;
	case WSAENOBUFS:
		con::Out("no memory to hold buffers\n");
		break;
	case WSAEPROTONOSUPPORT:
		con::Out("the specified protocol is not supported\n");
		break;
	case WSAEPROTOTYPE:
		con::Out("specified protocol that does not match socket type\n");
		break;
	case WSAESOCKTNOSUPPORT:
		con::Out("this type of socket is not supported in the specified domain\n");
		break;
	default:
		break;
	}

}

void CloseNetSocket()
{
	wsaError = closesocket(hSock);
	if (wsaError == SOCKET_ERROR)
	{
		con::Out("Could not close the socket properly\n");
		wsaError = WSAGetLastError();
		switch (wsaError)
		{
		case WSANOTINITIALISED:
			con::Out("WSA NOT INITIALISED\n");
			break;
		case WSAENETDOWN:
			con::Out("error in the network subsystem\n");
			break;
		case WSAEINTR:
			con::Out("Interrupted function call.\n A blocking operation was interrupted by a call to\n");
			break;
		case WSAEINPROGRESS:
			con::Out("winsock 1.1 blocking call is in progress\n");
			break;
		case WSAENOTSOCK:
			con::Out("no socket descriptor was passed to closesocket()\n");
			break;
		case WSAEWOULDBLOCK:
			con::Out("WSAEWOULDBLOCK Resource temporarily unavailable.\n");
			break;
		default:
			break;
		}
	}

	wsaError = WSACleanup();
	if (wsaError == SOCKET_ERROR)
	{
		con::Out("WSAEWOULDBLOCK Resource temporarily unavailable.\n");
		wsaError = WSAGetLastError();
		switch (wsaError)
		{
		case WSANOTINITIALISED:
			con::Out("winsock 1.1 blocking call is in progress\n");
			break;
		case WSAENETDOWN:
			con::Out("error in the network subsystem\n");
			break;
		case WSAEINPROGRESS:
			con::Out("winsock 1.1 blocking call is in progress\n");
			break;
		default:
			break;
		}
	}
}

void HostServer()
{
	sockaddr_in addr = {};
	addr.sin_family = PF_INET;
	addr.sin_port = htons(10000);
	//addr.sin_addr.s_addr = inet_addr("192.168.0.1");//htonl(INADDR_ANY);

	bind(hSock, (LPSOCKADDR)&addr, sizeof(addr));

	listen(hSock, 10);
}

void HostClient()
{
	addr = {};
	addr.sin_family = PF_INET;
	addr.sin_port = htons(10000);
	//addr.sin_addr.s_addr = inet_addr("192.168.0.1");//htonl(INADDR_ANY);

	connect(hSock, (struct sockaddr*) &addr, sizeof(addr));
}

void TalkServer()
{
	accept(hSock, (struct sockaddr*) & addr, (int*)sizeof(struct sockaddr_in));
}

void TalkClient()
{

}