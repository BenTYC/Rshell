#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "connector.h"
#include "char_array.h"

using namespace std;

Connector::Connector(Base* left, Base* right): left(left), right(right) {}

Or::Or(Base* left, Base* right): Connector(left, right){}

And::And(Base* left, Base* right): Connector(left, right){}

Semicolon::Semicolon(Base* left, Base* right): Connector(left, right){}

Pipe::Pipe(Base* left, Base* right): Connector(left, right){}

OverwriteOut::OverwriteOut(Base* left, Base* right): Connector(left, right){}

AppendOut::AppendOut(Base* left, Base* right): Connector(left, right){}

ReadIn::ReadIn(Base* left, Base* right): Connector(left, right){}

std::string Or::to_string(){
    return left->to_string() + " || " + right->to_string();
}

std::string And::to_string(){
    return left->to_string() + " && " + right->to_string();
}

std::string Semicolon::to_string(){
    return left->to_string() + " ; " + right->to_string();
}

std::string Pipe::to_string(){
    return left->to_string() + " | " + right->to_string();
}

std::string OverwriteOut::to_string(){
    return left->to_string() + " > " + right->to_string();
}

std::string AppendOut::to_string(){
    return left->to_string() + " >> " + right->to_string();
}

std::string ReadIn::to_string(){
    return left->to_string() + " < " + right->to_string();
}

bool Or::execute(int fd_in, int fd_out) {
    if(left->execute(fd_in, fd_out)){
        return true;
    }else{
        if(right->execute(fd_in, fd_out))
            return true;
        else
            return false;
    }
}

bool And::execute(int fd_in, int fd_out) {
    if(left->execute(fd_in, fd_out)){
        if(right->execute(fd_in, fd_out))
            return true;
        else
            return false;
    }else{
        return false;
    }
}

bool Semicolon::execute(int fd_in, int fd_out) {
    left->execute(fd_in, fd_out);
    right->execute(fd_in, fd_out);
    return true;
}

bool Pipe::execute(int fd_in, int fd_out) {
    int pipe_fd[2];
    if(pipe(pipe_fd) == -1) {
        perror("Unable to create pipe");
        return false;
    }

    if(!left->execute(fd_in,pipe_fd[1])) 
        return false;
    close(pipe_fd[1]);

    if(!right->execute(pipe_fd[0],fd_out)) 
        return false;
    close(pipe_fd[0]);

    return true;
}

bool OverwriteOut::execute(int fd_in, int fd_out) {
    string outfile = right->to_string();
    fd_out = open(outfile.c_str(), O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    return left->execute(fd_in, fd_out);
}

bool AppendOut::execute(int fd_in, int fd_out) {
    string outfile = right->to_string();
    fd_out = open(outfile.c_str(), O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
    return left->execute(fd_in, fd_out);
}

bool ReadIn::execute(int fd_in, int fd_out) {
    string infile = right->to_string();
    fd_in = open(infile.c_str(), O_RDONLY);
    return left->execute(fd_in, fd_out);
}
