#include "UMachineDispatch.h"
#include "UMachine.h"
#include "UMessage.h"
#include "UMessageList.h"
#include <WProgram.h>
#include <HardwareSerial.h>

/**
 * Process the next message.
 */

void UMachineDispatch::poll(){
	UMessage *currentMessage = __uMachineDispatchMessageList.shift();
	UMessage *returnMessage = NULL;
	UMachine *tmp;

	if(currentMessage){
		/* If a messages needs to be returned instantly in order not 
		 * to miss future event it can be "return"ed this should be
		 * avoided and _only_ used with Machines that expect it.
		 */

		returnMessage = currentMessage->to->receive(currentMessage);

		if(returnMessage && returnMessage->from){
			if(currentMessage == returnMessage){
				tmp = returnMessage->to;
				returnMessage->to = currentMessage->from;
				returnMessage->from = tmp;
				returnMessage->to->receive(returnMessage);
			}else{	
				returnMessage->from->receive(returnMessage);
			}
		}
	}
}

void UMachineDispatch::add(UMessage *msg){
	__uMachineDispatchMessageList.add(msg);
}

void loop(){
	MainDispatcher.poll();
}

UMachineDispatch MainDispatcher = UMachineDispatch();
UMessageList __uMachineDispatchMessageList;
