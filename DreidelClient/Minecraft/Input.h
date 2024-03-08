#pragma once
#include "PS3/System.h"

// 00C616B0 # CInput::Tick((void))
namespace Input
{
	bool Patched = false;
	const uint ADDRESS = 0x000C616B0;
	const void (*d)() = 0;
	int calls = 0;
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
		calls++;
		__Asm();
	}
	void Hook(const void(*delegated)()) {
		d = delegated; 
		hookfunction(ADDRESS, fn(__Addition), fn(__Asm));
		
	}
	void Unhook() {
		calls = 0;
		UnHookFunctionStart(ADDRESS, fn(__Asm));
	}
}