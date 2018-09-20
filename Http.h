/*************************************************************************************************/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*************************************************************************************************/
/* 
 * File:   Http.h
 * Author: phamh
 *
 * Created on September 20, 2018, 8:13 AM
 */
/*************************************************************************************************/
#ifndef HTTP_H
#define HTTP_H
/*************************************************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
/*************************************************************************************************/
using namespace std;
/*************************************************************************************************/
class Http {
public:
    Http();
    Http(const Http& orig);
    virtual ~Http();
    bool post(string host, string link, int port, string data);
private:
    
};
/*************************************************************************************************/
#endif /* HTTP_H */
/*************************************************************************************************/
