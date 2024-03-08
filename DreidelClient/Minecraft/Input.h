#pragma once
#include "PS3/System.h"
// 00C616B0 # CInput::Tick((void))
namespace Input
{
	bool Patched = false;
	const uint ADDRESS = 0x000C616B0;
	 void (*d)() = 0;
	int calls = 0;

	bool IsWorking() {
		return calls > 0;
	}
	uint __Asm() {
		__nop();
		__nop();
		__nop();
		__nop();
		__nop();
	}
	uint __Addition() {
		if (d) {
			d();
		}
		if (calls == 1) {
			dbgl("CInput::Tick((void)) Works !!");
		}
		calls++;
		__Asm();
	}
	inline void Hook( void(*delegated)()) {
		d = delegated; 
		hookfunction(ADDRESS, fn(__Addition), fn(__Asm));
	}
	inline void Unhook() {
		calls = 0;
		UnHookFunctionStart(ADDRESS, fn(__Asm));
	}
}
