#include <string.h>

char* clean_redundant_spaces(char* str){
    while(*str == ' ')
        str++;
    while(str[strlen(str) - 1] == ' ')
        str[strlen(str) - 1] = '\0';
    return str;
}

char* remove_bracket(char* str){
    if(*str == '['){
        str++;
        str[strlen(str) - 1] = '\0';
        return clean_redundant_spaces(str);
    }
    return str;
}

bool has_outmost_parenthesis(char* cmd){
    if(*cmd == '('){
        int stack = 1, i;
        for(i = 1; i < (int)strlen(cmd); i++){
            if(cmd[i] == '(')
                stack++;
            if(cmd[i] == ')')
                stack--;
            if(stack == 0)
                break;
        }   
        if(i == (int)strlen(cmd) - 1)
            return true;
    }
    return false;
}

char* remove_outmost_parenthesis(char* cmd){
    cmd++;
    cmd[strlen(cmd) - 1] = '\0';
    return cmd;    
}

int last_symbol_pos(char* cmd, char c1, char c2){
    char *pch1, *pch2;
    pch1 = strrchr(cmd, c1);
    pch2 = strrchr(cmd, c2);
    
    if(pch1 == NULL && pch2 == NULL)
        return -1;
    else if(pch1 == NULL)
        return pch2 - cmd;
    else if(pch2 == NULL)
        return pch1 - cmd;

    if(pch1 > pch2)
        return pch1 - cmd;        
    else
        return pch2 - cmd;
}

int last_symbol_pos(char* cmd, char c){
    return last_symbol_pos(cmd, c, c);
}

int last_string_pos(char* string, char* find1, char* find2){
    size_t stringlen, findlen1, findlen2;
    char *cp;
    int pos1 = -1, pos2 = -1;

    findlen1 = strlen(find1);
    findlen2 = strlen(find2);
    stringlen = strlen(string);
    if (findlen1 > stringlen && findlen2)
        return -1;

    for (cp = string + stringlen - findlen1; cp >= string; cp--)
        if (strncmp(cp, find1, findlen1) == 0)
            pos1 = cp - string;
    
    for (cp = string + stringlen - findlen2; cp >= string; cp--)
        if (strncmp(cp, find2, findlen2) == 0)
            pos2 = cp - string;

    if(pos1 > pos2)
        return pos1;
    else
        return pos2;
}

int last_pos(char* string, char* s1, char c1, char c2){
    int last_1 = last_string_pos(string, s1, s1);
    int last_2 = last_symbol_pos(string, c1, c2);
    int last = ( last_1 < last_2 ) ? last_2 : last_1;
    return last;    
}

char* split_one_con(char* str, int i){
    char* right = str + i + 1;
    str[i] = '\0';
    return right;
}

char* split_two_con(char* str, int i){
    char* right = split_one_con(str, i);
    //str[strlen(str) - 1] = '\0';
    right[0] = ' ';
    return right;
}

void remove_comments(char* input){
    char* comment_start = input;
    comment_start = strchr(input, '#');
    if (comment_start != NULL)
        *comment_start = '\0';
}

char* char_in_parenthesis_to_X(char* cmd, char* refer){
    strcpy(refer, cmd);
    
    int stack = 0;
    for(int i = 0; i < (int)strlen(refer); i++){
        if(refer[i] == '(')
            stack++;
        if(refer[i] == ')')
            stack--;
        
        if(stack != 0 || refer[i] == ')')
            refer[i] = 'X';
    }

    return refer;
}

