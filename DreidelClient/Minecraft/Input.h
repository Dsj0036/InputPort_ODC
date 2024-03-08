#pragma once
#include "PS3/System.h"
#include "PS3/Dialog.h"
// 00C616B0 # CInput::Tick((void))
//00C62500 # CInput::GetJoypadStick_LY((int, bool))
namespace Input
{
	bool Patched = false;
	const uint ADDRESS = 0x00C62500;
	 void (**d)() = 0;
	int calls = 0;

	bool IsWorking() {
		return calls > 0;
	}
	uint __Asm(int a, bool b) {
		__nop();
		__nop();
		__nop();
		__nop();
		__nop();
	}
	uint __Addition(int a , bool b) {
		if (d) {
			if (*d)
			{
				(*d)();
			}
		}
		if (calls == 1) {
			dbgl("CInput::Tick((void)) Works !!");
			MessageDialog::Show("CInput::Tick((void)) Works !!", 5000);
		}
		calls++;
		return __Asm(a, b);
	}
	inline void Hook( void(*delegated)()) {
		d = &delegated; 
		MessageDialog::Show("Hooked!\n00C616B0 # CInput::Tick((void))");
		
		
		hookfunction(ADDRESS, fn(__Addition), fn(__Asm));
	}
	inline void Unhook() {
		calls = 0;
		UnHookFunctionStart(ADDRESS, fn(__Asm));
	}
}
