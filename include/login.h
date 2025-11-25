#pragma once
#ifndef LOGIN_H
#define LOGIN_H

struct credential {
    char name[20];
    int  password;
};

void sign_up(void);
void sign_in(void);
int admin(void);

#endif

