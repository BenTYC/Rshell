#include <string.h>
#include "command_tree.h"
#include "connector.h"
#include "cmd.h"
#include "char_array.h"

//#include <iostream>
//using namespace std;

Command_tree::Command_tree(char* all_cmd){
    root = build_tree(all_cmd);
}

Base* Command_tree::build_tree(char* cmd){
    //Clean redundant spaces
    cmd = clean_redundant_spaces(cmd);

    //Remove outmost parenthesis
    if(has_outmost_parenthesis(cmd))
        cmd = remove_outmost_parenthesis(cmd);
    //cout << cmd << endl;
 
    //Create a reference cmd replace char inside parenthesis by 'X'
    char refer_buffer[BUFFER_SIZE];
    char* refer = char_in_parenthesis_to_X(cmd, refer_buffer);

    //SemiColon
    int semicolon_pos = last_symbol_pos(refer, ';');
    if(semicolon_pos != -1){
        //Cut cmd on semicolon
        char* right = split_one_con(cmd, semicolon_pos);
        return new Semicolon(build_tree(cmd), build_tree(right));
    }
    
    //And, Or
    int con_pos = last_string_pos(refer, (char *)"&&", (char *)"||");
    if(con_pos != -1){
        char con = cmd[con_pos];
        char* right = split_two_con(cmd, con_pos); //Cut cmd on connectors
        
        if(con == '&')
            return new And(build_tree(cmd), build_tree(right)); 
        else if(con == '|')
            return new Or(build_tree(cmd), build_tree(right));  
    }

    //Pipe
    int pipe_pos = last_symbol_pos(refer, '|'); 
    if(pipe_pos != -1){
        char* right = split_one_con(cmd, pipe_pos);
        return new Pipe(build_tree(cmd), build_tree(right));
    }

    //Redirector
    int redirector_pos = last_pos(refer, (char *)">>", '>', '<');
    if(redirector_pos != -1){
        char con = cmd[redirector_pos];
        char* right = split_one_con(cmd, redirector_pos); //Cut cmd on connectors

        if(con == '<'){
            return new ReadIn(build_tree(cmd), build_tree(right));
        }else{ //con == '>'
            if(cmd[strlen(cmd) - 1] == '>'){
                cmd[strlen(cmd) - 1] = '\0';
                return new AppendOut(build_tree(cmd), build_tree(right));
            }else{
                return new OverwriteOut(build_tree(cmd), build_tree(right));
            }
        }
    }
    
    //Only OP
    return new CMD(cmd);
}

bool Command_tree::execute(int fd_in, int fd_out){
    return root->execute(fd_in, fd_out);
}

std::string Command_tree::to_string(){
    return root->to_string();
}
