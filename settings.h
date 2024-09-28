#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")

HINTERNET hRequest;
HINTERNET hConnect;
HINTERNET hSession;


auto initHTTP() -> bool {
    hSession = WinHttpOpen(L"DiscordSession",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS,
        0);

    hConnect = WinHttpConnect(hSession,
        L"discordapp.com",
        INTERNET_DEFAULT_HTTPS_PORT,
        0);

    return true;
}
auto SendEmbedHK(std::string title = "", std::string desc = "", std::string text = "", std::string botname = "blackbot", std::string color = "65535") -> void {
    hRequest = WinHttpOpenRequest(hConnect,
        L"POST",
        L"/api/webhooks/YOUR-WEBHOOK", 
        NULL,
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE);

    std::string req = "{\"username\": \"" + botname + "\",\"content\": null,\"embeds\": [{\"title\": \"" + title + "\",\"description\": \"" + desc + "\",\"footer\": {\"text\": \"" + text + "\"},\"color\": " + color + " }], \"attachments\": []}";

    BOOL bResults = WinHttpSendRequest(hRequest,
        L"Content-Type: application/json\r\n",
        (DWORD)-1L,
        (LPVOID)req.c_str(),
        (DWORD)req.length(),
        (DWORD)req.length(),
        0);

    if (bResults) {
        WinHttpReceiveResponse(hRequest, NULL);
    }
}
auto SendMessageHK(std::string text, std::string botname = "blackbot") -> void {
    hRequest = WinHttpOpenRequest(hConnect,
        L"POST",
        L"/api/webhooks/YOUR-WEBHOOK", 
        NULL,
        WINHTTP_NO_REFERER,
        WINHTTP_DEFAULT_ACCEPT_TYPES,
        WINHTTP_FLAG_SECURE);

    std::string req = "{\"username\": \"" + botname + "\",\"content\": \"" + text + "\"}";

    BOOL bResults = WinHttpSendRequest(hRequest,
        L"Content-Type: application/json\r\n",
        (DWORD)-1L,
        (LPVOID)req.c_str(),
        (DWORD)req.length(),
        (DWORD)req.length(),
        0);

    if (bResults) {
        WinHttpReceiveResponse(hRequest, NULL);
    }
}
auto endHTTP(HINTERNET hRequest, HINTERNET hConnect, HINTERNET hSession) -> void {
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
}
