#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include "cmd.h"
#include "char_array.h"

using namespace std;

CMD::CMD(char* cmd): cmd(cmd){}

bool CMD::is_test_command(){
    if(cmd[0] == '[' && cmd[strlen(cmd) - 1] == ']')
        return true;
    if(strstr(cmd,"test") == cmd)
        return true;
    return false;
}

bool CMD::exe_test_command(){
    cmd = remove_bracket(cmd);

    //Split test command
    vector<char*> test;
    char* temp = strtok(cmd, " ");
    while(temp != NULL){
        test.push_back(temp);
        temp = strtok(NULL, " ");
    }
    
    //Get flag and path
    char flag = 'e';
    char* path;
    if(test.size() == 1){
        flag = 'e';
        path = test[0];
    }else if(test.size() == 2){
        flag = (*test[0] == '-')? *++test[0]:'e';
        path = test[1];
    }else if(test.size() == 3){
        flag = *++test[1];
        path = test[2];	
    }
    
    //Execute
    struct stat sb;
    int val = stat(path, &sb);
    
    if(val == -1)
        return false;
    
    //Match the flag
    switch (sb.st_mode & S_IFMT){
        case S_IFDIR:  
            if(flag == 'f')
                return false; 
            break;
        case S_IFREG:
            if(flag == 'd')
                return false;
            break;
    }
    return true;
}

bool CMD::execute(int fd_in, int fd_out) {
    if(strlen(cmd) == 0)
        return true;

    //Test Command
    if(is_test_command()){
        if(exe_test_command()){
            cout << "(True)" << endl;
            return true;
        }else{
            cout << "(False)" << endl;
            return false;
        }
     }

    //Parse to command and arguments
    vector<char*> args;
    char* prog = strtok(cmd, " ");
    char* tmp = prog;
    while(tmp != NULL){
        args.push_back(tmp);
        tmp = strtok(NULL, " ");
    }
    
    char** argv = new char*[args.size() + 1];
    for(int k = 0; k < (int)args.size(); k++)
        argv[k] = args[k];
    argv[args.size()] = NULL;

    //Exit if cmd == "exit"
    if(strcmp(prog, "exit") == 0)
        exit_all();

    //Execute
    pid_t pid;
    bool ret = true;
     
    if ((pid = fork()) < 0) {     /* fork a child process           */
        perror("fork");
        exit(1);
    }else if (pid == 0) {          /* for the child process:         */
        if(dup2(fd_in, STDIN_FILENO) == -1) {
            perror("dup2");
            return false;
        }
        if(dup2(fd_out, STDOUT_FILENO) == -1) {
            perror("dup2");
            return false;
        }
        if (execvp(*argv, argv) < 0) {     /* execute the command  */
            ret = false;
            perror("execvp");
            exit(1);
        }
    }else{                                  /* for the parent:      */
        int status;
        if(waitpid(pid,&status,0) == -1)  /* wait for completion  */
            perror("wait");
        
        if(WEXITSTATUS(status) == 1) 
            ret = false;
    }
  
    return ret;

}


void CMD::exit_all() {
    exit(0);
}

string CMD::to_string(){
    return cmd;
}


