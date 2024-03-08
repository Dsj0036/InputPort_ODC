#include "PS3/System.h"
#include "PS3/Trace.h"
#include "Minecraft/Input.h"
void new_tick() {

}

void main() {
	debug::create();
	dbgl("main();");
	Input::Hook(new_tick);
	
}
void stop() {
	dbgl("stop();");
	Input::Unhook();
}