
#include "cell/pad.h"
#pragma comment(lib,"libhttp_stub.a")
#pragma comment(lib,"libhttp_util_stub.a")
#pragma comment(lib,"libnet_stub.a")
#pragma comment(lib,"netctl_stub")
#pragma comment(lib,"libsysutil_stub.a")
#pragma comment(lib,"libc.a")
#pragma comment(lib,"libstdc++.a")
#pragma comment(lib,"libstdc++_stub.a")
#pragma comment(lib,"libsn.a")
#pragma comment(lib,"libm.a")
#pragma comment(lib,"libio_stub.a")
#pragma comment(lib,"liblv2_stub.a")
#pragma comment(lib,"libfs_stub.a")
#pragma comment(lib,"libio_stub.a")
#pragma comment(lib,"libdbg_libio_stub.a")
#include <cell/pad.h>
#include <Cell/keyboard.h>
#include <Cell/mouse/libmouse.h>
#include <Cell/mouse/mouse_codes.h>
#include <Cell/mouse/error.h>
#include "PS3/Trace.h"
#pragma once
namespace Pad {
	int IsDS3ConnectedPort(int port) {
		CellPadInfo2 _in;
		int error = cellPadGetInfo2(&_in);
		if (error != 0)

		{
			return error;
		}
		else
		{
			return _in.port_status[port] ? 1 : 0;
		}
		return -99;
	}
	CellPadData GetPlayer(int& fd) {
		CellPadData _d;
		fd = cellPadGetData(0, &_d);

		return _d;
	}
	int GetConnectedMouseCount() {
		CellMouseInfo _inf;
		if (cellMouseGetInfo(&_inf) == CELL_OK) {
			return _inf.now_connect;
		}
		else return 0;
	}
	int GetConnectedKeyboardCount() {

		CellKbInfo _inf;
		int error = 0;
		if ((error = cellKbGetInfo(&_inf)) == CELL_OK) {
			return _inf.now_connect;
		}
		return error;
	}
	int GetConnectedMouse() {
		CellMouseInfo _inf;

		if (cellMouseGetInfo(&_inf)) {
			for (int i = 0; i < 7; i++) {
				if (_inf.status[i] == CELL_MOUSE_STATUS_CONNECTED) {
					return i;
					break;
				}
			}
			return -1;
		}
	}
	int GetConnected() {
		CellPadInfo2 inf2;
		int err = cellPadGetInfo2(&inf2);
		if (err == 0) {
			return inf2.now_connect;
		}
		else return -1;

	}
	int GetConnectedKeyboard() {

		CellKbInfo _inf;
		int error = -2;
		if ((error = cellKbGetInfo(&_inf)) == 0) {
			int id = -1;
			for (int i = 0; i < 7; i++) {
				int stat = _inf.status[i];
				//dbg::coutf("KB: [%i] %i\n", i, stat);
				if (stat == CELL_KB_STATUS_CONNECTED) {
					return id = i;
					break;
				}
			}
			return id;
		}
		return error;
	}
	int32_t Init() {
		cellMouseInit(4);
		cellKbInit(4);
	}
	int32_t Clear(uint32_t port) {
		cellMouseClearBuf(port);
		cellKbClearBuf(port);
	}
	int32_t GetData(uint32_t port, CellPadData* data) {

		return cellPadGetData(port, data);
	}
	int32_t GetMouseData(uint32_t port, CellMouseData* data) {
		return cellMouseGetData(port, data);
	}
	int32_t GetMouseButtonTest(int port) {
		CellMouseData data;
		if (GetConnectedMouseCount() > 0) {
			if (GetMouseData(port, &data) == 0) {
				return data.buttons;
			}
		}
		return -1;
	}
	bool IsUpdated(CellMouseData d) {
		return d.update == CELL_MOUSE_DATA_UPDATE && d.update != CELL_MOUSE_DATA_NON;
	}
	int32_t GetKeyboardData(uint32_t port, CellKbData* e) {
		int i = cellKbSetReadMode(port, CELL_KB_RMODE_INPUTCHAR);
		return i != 0 ? i : cellKbRead(port, e);
	}
}