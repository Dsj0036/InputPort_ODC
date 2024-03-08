#pragma once
#include "PS3/System.h"
#include "PS3/PadHelper.h"
#include "cell/pad/libpad_dbg.h"
namespace ICNV
{
	bool con[2]{false ,false};
	bool okn = false;
	bool ok = false;
	point interval(0,10);
	point interval_of(0,5);
	void WhenDisconnected()
	{

	}
	void Check() {
		bool a = con[0];
		bool b = con[1];
		if (!(a || b)) {
			a = Pad::GetConnectedMouseCount() >= 1;
			b = Pad::GetConnectedKeyboardCount() >= 1;
			// 1: mouse | 2: keyboard
			int trigger = a ? 1 : b ? 2 : 0;

			bool wasConnected = okn == true;
			ok = a && b;
			okn = wasConnected && ok;
			if (ok == false && wasConnected)
			{
				WhenDisconnected();
				okn = false;
			}

		}
		
		
	}
	void Tick()
	{
		bool readable = ok && okn;
		if ((++interval.x) > interval.y)
		{	
			// Normal tick
			interval.x = 0;
			if ((++interval_of.x) > interval_of.y)
			{
				// big tick
				interval_of.x = 0;
				Pad::Clear(0);
			}
		}
		if (readable) {
			
		}
	}
	void Init() {
		interval.x = 0;
		interval.y = 10;
		cellPadDbgLddRegisterController
		(CELL_PAD_CAPABILITY_PS3_CONFORMITY | CELL_PAD_CAPABILITY_HP_ANALOG_STICK |
			CELL_PAD_CAPABILITY_ACTUATOR | CELL_PAD_CAPABILITY_PRESS_MODE);
	}
}