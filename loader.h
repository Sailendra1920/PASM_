#pragma once

#include "m_types.h"
#include "stdio.h"
#include "stdlib.h"
#include "tokens.h"
#include "string.h"

//Loader now tokenizes the source at load time
//welcome : )


bool ifspace(char c){
  if(c == ' ' || c == '\n' || c == '\t'){
    return true;
  }

  return false;
}


Node * loader(char * src , Length_tracker * lt){
  
  FILE * fp = fopen(src,"r");

  if(fp == NULL){
    printf("Failed to open file named %s\n",src);
    exit(EXIT_FAILURE);
  }

  Node *point = (Node *) malloc(sizeof(Node));
 
  int token_len=0;
  char c;
  while((c=getc(fp))!=EOF){
  
    if(!ifspace(c)){
       char * buffer = (char *) calloc(32, sizeof(char));

      for(int i = 0 ; i < 32 ; i++){
	if(ifspace(c)){
	  break;
	}
	buffer[i] = c;
	c = getc(fp);
      }
      
      Node * node = (Node *) malloc(sizeof(Node));
      node->next = NULL;
      node->token.name = buffer;

      node->next = point;
      point = node;
      token_len++;
    }
    else{}
  }
  lt->token_list_len = token_len;
  fclose(fp);

  return point;

}
