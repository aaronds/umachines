/**
 * Micro Machine
 *
 * Imagine actors but for ardunio.
 */

#include <UMessage.h>
#include <UMessageList.h>
#include <UMachineDispatch.h>

#ifndef __U_MACHINE
#define __U_MACHINE

extern "C" {
	#include <inttypes.h>
	#include <stdlib.h>
	#include <string.h>
}

class UMachine {

	public:
		UMachine();
		UMessageList queue;

		virtual UMessage *receive(UMessage *msg);
		void send(UMessage *msg,UMachine *to);
};

#endif
