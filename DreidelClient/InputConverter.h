#pragma once
#include "PS3/System.h"
#include "PS3/PadHelper.h"
#include "cell/pad/libpad_dbg.h"
#include "PS3/Dialog.h"
namespace IConverter
{
	bool con[2]{false ,false};
	bool okn = false;
	bool ok = false;
	point interval(0,10);
	point interval_of(0,5);
	bool Registered = false;
	uint HANDLE = -1;
	void WhenDisconnected()
	{
		ok = false;
		okn = false;
		MessageDialog::ShowOk("Disconnected");
	}
	void ForceDisconnect() {
		con[0] = false;
		con[1] = false;
		ok = false;
		okn = false;
	}
	void Work() {
		CellKbData kbdata;
		CellMouseData msdata;
		uint e = Pad::GetKeyboardData(0, &kbdata);
		uint ee = Pad::GetMouseData(0, &msdata);
		if ((e + ee) == 0 && Registered) {
			//CellPadData data;
			//kbdata.keycode
			if (kbdata.keycode[0] == (CELL_KEYC_SPACE | CELL_KB_RAWDAT)) {
				MessageDialog::ShowOk("U pressed SPACE.");
			}
			//data.len = 128;
		}
		else
		{
			WhenDisconnected();
		}
	}
	void Check() {
		bool a = (con[0] = Pad::GetConnectedMouseCount()	>= 1);
		bool b = (con[1] = Pad::GetConnectedKeyboardCount() >= 1);
		if (!(a || b)) {
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
		else
		{

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
		bool readable = ok && okn && Registered;
		if ((++interval.x) > interval.y)
		{	
			// Normal tick
			Check();
			interval.x = 0;
			if ((++interval_of.x) > interval_of.y)
			{
				// big tick
				interval_of.x = 0;
				Pad::Clear(0);

				if (Pad::IsDS3ConnectedPort(0)) {
					ForceDisconnect();
				}
			}
		}
		if (readable) {
			Work();
		}
	}
	void Register() {

		//uint r = cellPadDbgLddRegisterController(CELL_PAD_CAPABILITY_PS3_CONFORMITY | CELL_PAD_CAPABILITY_HP_ANALOG_STICK |	CELL_PAD_CAPABILITY_ACTUATOR | CELL_PAD_CAPABILITY_PRESS_MODE);
		Registered = true;//!CELL_STATUS_IS_FAILURE(r);
		//HANDLE = r;
		int kbe = cellKbInit(2);
		debug::out::writeif(kbe != 0, "CellKbInit Failed");
		Registered = Registered && kbe == 0;
		if (Registered) {
			cellKbSetLEDStatus(0, CellKbLedMode::CELL_KB_LED_MODE_AUTO1);
			cellKbSetCodeType(0, CELL_KB_CODETYPE_RAW);
			cellKbSetReadMode(0, 1); // Readmode: PACKET
				
			MessageDialog::ShowOk("Registration OK!");
		}
		if (kbe != 0) {
			char c[30];
			snprintf(c, 30, "KbInit: 0%x", kbe);
		}
	}
	void Init() {
		interval.x = 0;
		interval.y = 10;
		interval.y = 10;
		Register();
	}
}