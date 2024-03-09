#pragma once

#include "tokenizer.h"
#include "stdio.h"


Token * flatten_token_list(Node * n , Length_tracker * lt){

  Token * tok_array = (Token * ) calloc(lt->token_list_len,
					sizeof(Token));

  for(int i = (lt->token_list_len - 1) ; i > -1 ; i-- , n = n->next){

    tok_array[i] = n->token;
  }
  
  return tok_array;
  
}
