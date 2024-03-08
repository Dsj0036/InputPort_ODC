#include "PS3/System.h"
#include "PS3/Trace.h"
#include "Minecraft/Input.h"
#include "InputConverter.h"

void main(uint64_t) {
	sleep(15000);
	debug::create();
	dbgl("main();"); 
	IConverter::Register();
	Input::Hook([]()->void {
		IConverter::Tick();
		});
	
}
void stop() {
	dbgl("stop();");
	Input::Unhook();
}