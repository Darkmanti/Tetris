#pragma once

WORD wVersion = 2; // запрашиваема€ верси€ winsock-интерфейса
WSADATA wsaData; // сюда записываютс€ данные о сокете
SOCKET hSock; // наш дескриптор сокета

sockaddr_in addr = {};

int wsaError;

void InitNetSocket();
void CloseNetSocket();

void HostServer();
void HostClient();

void TalkServer();
void TalkClient();