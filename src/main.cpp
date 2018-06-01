#include <iostream>
#include <unistd.h>
#include "command_tree.h"
#include "char_array.h"

using namespace std;

int main(int argc, char**argv) {
 
    char input[BUFFER_SIZE];

    while(true){
        //take input
        cout << "$ ";
        cin.getline (input,BUFFER_SIZE);
        
        //remove everything after #
        remove_comments(input);
        
        //build 
        Command_tree* cmd_tree = new Command_tree(input);
        
        //test
        //cout << cmd_tree->to_string() << endl;
         
        //execute
        cmd_tree->execute(STDIN_FILENO, STDOUT_FILENO);
    }
}
