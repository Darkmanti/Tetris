#pragma once

WORD wVersion = 2; // ������������� ������ winsock-����������
WSADATA wsaData; // ���� ������������ ������ � ������
SOCKET hSock; // ��� ���������� ������

sockaddr_in addr = {};

int wsaError;

void InitNetSocket();
void CloseNetSocket();

void HostServer();
void HostClient();

void TalkServer();
void TalkClient();