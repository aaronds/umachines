#include "UMessageList.h"
#include "UMessage.h"

#include <WProgram.h>

UMessageList::UMessageList(){
	start = NULL;
	end = NULL;
}

void UMessageList::add(UMessage *msg){
	UMessage *tmp;
	msg->next = NULL;
	if(end){
		end->next = msg;
		end = msg;
	}else{
		start = msg;
		end = msg;
	}
}

UMessage *UMessageList::shift(){
	UMessage *current = start;

	if(!current){
		end = NULL;
		return current;
	}

	if(current == end){
		end = NULL;
		start = NULL;
		current->next = NULL;
		return current;
	}

	if(current->next){
		start = current->next;
		current->next = NULL;
	}

	return current;
}

