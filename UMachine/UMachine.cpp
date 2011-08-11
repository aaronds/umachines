#include "UMachine.h"
#include <WProgram.h>

UMachine::UMachine(){
}

/**
 * Default recive function, return to sender.
 */

UMessage *UMachine::receive(UMessage *msg){
	send(msg,msg->from);
	return NULL;
}

void UMachine::send(UMessage *msg,UMachine *to){
	msg->from = this;
	msg->to = to;
	MainDispatcher.add(msg);
}
