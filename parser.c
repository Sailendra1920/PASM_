#pragma once

#include "loader.h"

#define NO_OF_OPCODES 17

bool isOpcode(char * s, char **table, int len){
 for (int i = 0 ; i < len ; i++){
    if(!strcasecmp(s,table[i])){
      return true;
    }
  }
  return false;
}


bool isReg(char * s){

  if(s[0] == '%'){
    return true;
  }

  return false;
  
}

bool isAddress(char * s){

  if(s[0] == '&'){
    return true;
  }

  return false;
  
}


bool isDirective(char * s){

  if(s[0] == '.'){
    return true;
  }

  return false;
  
}

bool isLabel(char * s){

  if(s[0] == '_'){
    return true;
  }

  return false;
}


Token_type checker(char *s, char **table){

  if(isReg(s))
  return REG;
  else if(isAddress(s))
  return ADDR;
  else if(isDirective(s)) 
  return DIR;
  else if(isLabel(s))
  return LAB;
  else if(isOpcode(s,table, NO_OF_OPCODES))
  return OPCODE;
  else
  return DATA;
}

void init_optable(char **s)
{
    //says that the double pointer should point to char pointers
    s  = calloc(NO_OF_OPCODES,sizeof(char*));
  
  for(int i = 0 ; i < NO_OF_OPCODES ; i++){
    //allocates mem for the char 
    s[i] = calloc(32,sizeof(char));
  }
  
  s[0]= "MOV";
  s[1]="HLT";
  s[2]="PRINT";
  s[3]="POP";
  s[4]="PUSH";
  s[5]="ADD";
  s[6]="SUB";
  s[7]="MUL";
  s[8]="DIV";
  s[9]="CALL";
  s[10]="JE";
  s[11]="MOD";
  s[12]="RET";
  s[13]="CMP";
  s[14]="JNE";
  s[15]="JGE";
  s[16]="JLE";
}


Node * parsing( Node *head){
  
  Node *node = (Node *) malloc(sizeof(Node));
  node=head;
  
  char **opcode_table;
  init_optable(opcode_table);
  while(node->next != NULL){
    printf("token name: %s\n",node->token.name);
    node->token.type = checker(node->token.name, opcode_table);
    printf("Type of the token: %d \n", node->token.type);
    node=node->next;
  }
  node=head;
    
  return head;
}
