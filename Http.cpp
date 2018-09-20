/*************************************************************************************************/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*************************************************************************************************/
/* 
 * File:   Http.cpp
 * Author: phamh
 * 
 * Created on September 20, 2018, 8:13 AM
 */
/*************************************************************************************************/
#include "Http.h"
/*************************************************************************************************/
Http::Http() {
}
/*************************************************************************************************/
Http::Http(const Http& orig) {
}
/*************************************************************************************************/
Http::~Http() {
}
/*************************************************************************************************/
bool Http::post(string host, string link,int port, string data) {
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total, message_size;
    char *message, response[4096];
    /*********************************************************************************************/
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        return false;
    }
    /*********************************************************************************************/
    server = gethostbyname(host.c_str());
    if (server == NULL) {
        return false;
    }
    /*********************************************************************************************/
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        return false;
    }
    /*********************************************************************************************/
    char* http_request = new char[4096];
    int m_size = sprintf(http_request, "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %d\r\n\r\n%s\r\n\r\n",link.c_str(), host.c_str(),data.size(),data.c_str());
    int bytes_tranfer = write(sockfd,http_request,m_size);
    if(bytes_tranfer <= 0) {
        delete [] http_request;
        return false;
    }
    /*********************************************************************************************/
    char* http_return = new char[4096];
    bytes_tranfer = read(sockfd,http_return,4096);
    printf("HTTP - %s\n", http_return);
    return true;
}
/*************************************************************************************************/
