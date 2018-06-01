#ifndef __CMD_H__
#define __CMD_H__

#include "component.h"

class CMD: public Base{
    public:
        CMD(char* cmd);
        bool execute(int fd_in, int fd_out);
        void exit_all();
        std::string to_string();
    private:
        char* cmd;
        bool is_test_command();
        bool exe_test_command();
};

#endif
