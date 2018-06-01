#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <string>

class Base {
    public:
        Base() {}
        virtual bool execute(int fd_in, int fd_out) = 0;
        virtual std::string to_string() = 0;
};

#endif // __COMPONENT_H__
