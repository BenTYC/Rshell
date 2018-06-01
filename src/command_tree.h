#ifndef __COMMAND_TREE_H__
#define __COMMAND_TREE_H__

#include "component.h"

class Command_tree: public Base{
    public:
        Command_tree(char* cmd);
        bool execute(int fd_in, int fd_out);
        std::string to_string();
    private:
        Base* root;
        Base* build_tree(char* cmd);
};

#endif
