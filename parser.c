#pragma once

#include "loader.h"


bool isOpcode(char * s){
  if(strcasecmp(s,"MOV")==0)
  return true;
  else if(strcasecmp(s,"HLT")==0)
  return true;
  else if(strcasecmp(s,"ADD")==0)
  return true;
  else if(strcasecmp(s,"SUB")==0)
  return true;
  else if(strcasecmp(s,"MUL")==0)
  return true;
  else if(strcasecmp(s,"DIV")==0)
  return true;
  else if(strcasecmp(s,"MOD")==0)
  return true;
  else if(strcasecmp(s,"CALL")==0)
  return true;
  else if(strcasecmp(s,"RET")==0)
  return true ; 
  else if(strcasecmp(s,"CMP")==0)
  return true;
  else if(strcasecmp(s,"JE")==0)
  return true ; 
  else if(strcasecmp(s,"JNE")==0)
  return true;
  else if(strcasecmp(s,"JGE")==0)
  return true;
  else if(strcasecmp(s,"JLE")==0)
  return true;
  else if(strcasecmp(s,"PUSH")==0)
  return true;
  else if(strcasecmp(s,"POP")==0)
  return true;
  else if(strcasecmp(s,"PRINT")==0)
  return true;
  else
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


Token_type checker(char *s){

  if(isReg(s))
  return REG;
  else if(isAddress(s))
  return ADDR;
  else if(isDirective(s)) 
  return DIR;
  else if(isLabel(s))
  return LAB;
  else if(isOpcode(s))
  return OPCODE;
  else
  return DATA;
}

Node * parsing( Node *head){
  
  Node *node = (Node *) malloc(sizeof(Node));
  node=head;
  
  while(node->next != NULL){
    printf("token name: %s\n",node->token.name);
    node->token.type = checker(node->token.name);
    printf("Type of the token: %d \n", node->token.type);
    node=node->next;
  }
  node=head;
    
  return head;
}
