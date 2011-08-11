/**
 * Dispatch messages.
 */

#ifndef __DISPATCH
#define __DISPATCH

#ifndef __U_MESSAGE_LIST
class UMessageList;
#endif

#ifndef __U_MESSAGE
class UMessage;
#endif

class UMachineDispatch {

	public:
		void add(UMessage *msg);
		void poll();
};

extern UMachineDispatch MainDispatcher;
extern UMessageList __uMachineDispatchMessageList;

extern "C" {
	void loop();
}

#endif
