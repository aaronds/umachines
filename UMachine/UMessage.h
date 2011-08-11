/**
 * Micro machine message.
 */

#ifndef __U_MESSAGE
#define __U_MESSAGE

class UMachine;

class UMessage {
	public:
		UMachine *from;
		UMachine *to;
		UMessage *next;
};
#endif
