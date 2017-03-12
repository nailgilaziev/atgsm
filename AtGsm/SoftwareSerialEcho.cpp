//
//  SoftwareSerial.cpp
//  AtGsm
//
//  Created by Nail on 09/03/2017.
//  Copyright © 2017 Nail. All rights reserved.
//

#include "SoftwareSerialEcho.hpp"

SoftwareSerial::SoftwareSerial(int a,int b){}

void SoftwareSerial::begin(int s){}


void SoftwareSerial::write(char c){
    buf[pos++]=c;
}



char SoftwareSerial::read(){
    if (pos==0) return -1;
    char c0 = buf[0];
    for (int i=1; i<pos; i++) {
        buf[i-1]=buf[i];
    }
    pos--;
    return c0;
}

byte SoftwareSerial::available(){
    return pos;
}

