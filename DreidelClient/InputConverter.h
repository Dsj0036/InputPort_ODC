#pragma once
#include "PS3/System.h"
#include "PS3/PadHelper.h"
#include "cell/pad/libpad_dbg.h"
MAKE_FN(0x886798, void, ConsoleUIController_PlayUISFX, (uintptr_t consoleUIController, uintptr_t soundEvent));
#include "PS3/Dialog.h"
namespace IConverter
{

	void sfx(uint s) {
		ConsoleUIController_PlayUISFX(0x1558228, *(uintptr_t*)s);
	}
	bool con[2]{ false ,false };
	bool okn = false;
	bool ok = false;
	point interval(0, 10);
	point interval_of(0, 5);
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
	void Tick()
	{
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
		if (con[0]) {
			CellKbData kbdata;
			
			
			uint e = Pad::GetKeyboardData(0, &kbdata);
			if (e == 0 && kbdata.len > 0) {
				//char sample[50];
				//_sys_snprintf(sample, 50, "1: %i\n2: %i\n3: %i\n4: %i\n5: %i\n6: %i\n7: %i\n",
				//	kbdata.keycode[0],
				//	kbdata.keycode[1],
				//	kbdata.keycode[2],
				//	kbdata.keycode[3],
				//	kbdata.keycode[4],
				//	kbdata.keycode[5],
				//	kbdata.keycode[6]);
				//cellMsgDialogAbort();
				//MessageDialog::ShowOk(sample);
			}
		}
		if (con[1]) {

		}
	}
	void UpdateModes() {

		debug::out::write_assert(cellKbSetLEDStatus(0, CellKbLedMode::CELL_KB_LED_MODE_AUTO1), "cellKbSetLEDStatus");
		debug::out::write_assert(cellKbSetCodeType(0, CELL_KB_CODETYPE_RAW), "cellKbSetCodeType");
		debug::out::write_assert(cellKbSetReadMode(0, 1), "cellKbSetReadMode"); // Readmode: PACKET
		
		debug::out::writeL("Modes updated.");
	}
	void Register() {

		//uint r = cellPadDbgLddRegisterController(CELL_PAD_CAPABILITY_PS3_CONFORMITY | CELL_PAD_CAPABILITY_HP_ANALOG_STICK |	CELL_PAD_CAPABILITY_ACTUATOR | CELL_PAD_CAPABILITY_PRESS_MODE);
		Registered = true;//!CELL_STATUS_IS_FAILURE(r);
		//HANDLE = r;
		int kbe = cellKbInit(2);
		debug::out::writeN("cellKbInit: %x\n", kbe);
		Registered = Registered && kbe == 0 || kbe == CELL_KB_ERROR_ALREADY_INITIALIZED;

		MessageDialog::ShowOk("Registration OK!");
		debug::out::write("Registration OK\n");

		if (kbe != 0 && kbe != CELL_KB_ERROR_ALREADY_INITIALIZED) {
			char c[30];
			snprintf(c, 30, "KbInit: 0%x", kbe);
			MessageDialog::ShowOk(c);
		}
	}
	void UpdaterFunc_asm(uint, uint, uint) {
		__nop();
		__nop();
		__nop();
		__nop();
		__nop();
	}
	void UpdaterFunc(uint a, uint b, uint c) {

		//debug::out::writeL("00C63808 # CInput::UpdateJoypads((void));");
		bool oldA = con[0];
		bool oldB = con[1];

		bool newA = con[0] = Pad::GetConnectedKeyboardCount() > 0;
		bool newB = con[1] = Pad::GetConnectedMouseCount() > 0;
		if (oldA == false && newA == true)
		{
			sfx(0x14CA694);
			UpdateModes();
			MessageDialog::Show("Keyboard connected.", 3000);
		}

		else if (oldA == true && newA == false)
		{
			sfx(0x14CA684);
			MessageDialog::Show("Keyboard disconnected.", 2000);
		}

		UpdaterFunc_asm(a, b, c);
	}

	void Init() {
		interval.x = 0;
		interval.y = 10;
		interval.y = 10;
		Register();
	}
}