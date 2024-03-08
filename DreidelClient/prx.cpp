#pragma once
#include "cellstatus.h"
#include <sys/prx.h>
#include <Entry.h>

SYS_MODULE_INFO(InputPortForUDV, 0, 1, 0);
SYS_MODULE_START(sys_ps3_prx_entry);
SYS_MODULE_STOP(sys_ps3_prx_stop);
sys_ppu_thread_t t;
extern "C" int sys_ps3_prx_entry(void) {
	
	sys_ppu_thread_create(&t, main, 0, 1200, 30000, 0, "INPUT_PORT");

	
	return 0;
}
extern "C" int sys_ps3_prx_stop(void)
{
	return 0;
}
