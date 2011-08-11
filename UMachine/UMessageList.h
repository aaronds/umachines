/**
 * A list of messages
 */

#ifndef __U_MESSAGE_LIST 
#define __U_MESSAGE_LIST

class UMessage;

extern "C" {
	#include <inttypes.h>
	#include <stdlib.h>
	#include <string.h>
}

class UMessageList {

	public:
		UMessageList();
		UMessage *start;
		UMessage *end;

		void add(UMessage *msg);
		UMessage *shift();
};

#endif
