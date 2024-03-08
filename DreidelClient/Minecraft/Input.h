#pragma once
#include "PS3/System.h"
#include "PS3/Dialog.h"
// 00C616B0 # CInput::Tick((void))
//00C62500 # CInput::GetJoypadStick_LY((int, bool))
namespace Input
{
	const uint ADDRESS = 0x00C619E0;
	 void (*d)() = 0;
	int calls = 0;

	bool IsWorking() {
		return calls > 0;
	}
	uint __Asm(uint, uint, uint) {
		__nop();
		__nop();
		__nop();
		__nop();
		__nop();
	}
	uint __Addition(uint a, uint b, uint c) {
		if (d) {
				(d)();	
		}
		if (calls == 1) {
			MessageDialog::Show("CInput::GetValue Works !!", 5000);
		}
		calls++;
		return __Asm(a,b,c);
	}
	inline void Hook( void(*delegated)()) {
		d = delegated; 
		MessageDialog::Show("Hooked!\n00C616B0 # CInput::GetValue())");
		
		hookfunction(ADDRESS, fn(__Addition), fn(__Asm));
	}
	inline void Unhook() {
		calls = 0;
		UnHookFunctionStart(ADDRESS, fn(__Asm));
	}
}
