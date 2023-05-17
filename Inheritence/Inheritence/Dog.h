#pragma once

#include "Animal.h"
#include<iostream>
using namespace std;

class Kurt {
public:
    virtual void a()
    {
        cout << "K A" << endl;
        c();
    }
    virtual void c()
    {
        cout << "K C" << endl;
    }
};

class Jerry : public Kurt {
public:
    virtual void a() {
        cout << "J A" << endl;
    }
    virtual void c() {
        cout << "J C" << endl;
        Kurt::c();
    }
};
class Eddie : public Kurt {
public:
    virtual void b() {
        a();
        cout << "E B" << endl;
    }
        virtual void c() {
        cout << "E C" << endl;
    }
};
class Chris : public Jerry {
public:
    virtual void b() {
        a();
        cout << "C B" << endl;
    }
    virtual void c() {
        cout << "C C" << endl;
        Jerry::c();
    }
    virtual void d() {
        cout << "C D" << endl;
        c();
    }
};
