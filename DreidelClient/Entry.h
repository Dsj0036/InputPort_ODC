#include "PS3/System.h"
#include "PS3/Trace.h"
#include "Minecraft/Input.h"
#include "InputConverter.h"

void main(uint64_t) {
	sleep(15000);
	debug::create();
	IConverter::Init();
	Input::Hook([]()->void {
		IConverter::Tick();
	
});
	//00C612F0 # CInput::ReadAllPads((void))
	hookfunction(0x00C63808, fn(IConverter::UpdaterFunc), fn(IConverter::UpdaterFunc_asm));
	//hookfunction(00, fn(IConverter::UpdaterFunc2), fn(IConverter::UpdaterFunc_asm));


	MessageDialog::ShowOk("Loop begin");
	//for (;;) {
	//	IConverter::Tick();
	//}
	
}
void stop() {
	dbgl("stop();");
	Input::Unhook();
}