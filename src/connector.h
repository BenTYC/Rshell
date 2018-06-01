#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "component.h"

class Connector: public Base{
    public:
        Connector(Base* left, Base* right);
        virtual bool execute(int fd_in, int fd_out) = 0;
        virtual std::string to_string() = 0;
    protected:
        Base* left;
        Base* right;
};

class Or: public Connector{
    public:
        Or(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

class And: public Connector{
    public:
        And(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

class Semicolon: public Connector{
    public:
        Semicolon(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

class Pipe: public Connector{
    public:
        Pipe(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

class OverwriteOut: public Connector{
    public:
        OverwriteOut(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

class AppendOut: public Connector{
    public:
        AppendOut(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

class ReadIn: public Connector{
    public:
        ReadIn(Base* left, Base* right);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
};

#endif
