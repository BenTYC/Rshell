#ifndef __CHAR_ARRAY_H__
#define __CHAR_ARRAY_H__

#include <iostream>

const size_t BUFFER_SIZE = 1024;
void remove_comments(char* input);
int last_symbol_pos(char* cmd, char c);
int last_symbol_pos(char* cmd, char c1, char c2);
int last_pos(char* cmd, char* s1, char c1, char c2);
int last_string_pos(char* cmd, char* s1, char* s2);
bool has_outmost_parenthesis(char* cmd);
char* clean_redundant_spaces(char* cmd);
char* split_one_con(char* str, int i);
char* split_two_con(char* str, int i);
char* char_in_parenthesis_to_X(char* cmd, char* refer);
char* remove_bracket(char* str);
char* remove_outmost_parenthesis(char* cmd);

#endif
