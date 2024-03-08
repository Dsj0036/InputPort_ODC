#pragma once
#include "cellstatus.h"
#include <sys/prx.h>
#include <Entry.h>

SYS_MODULE_INFO(InputPortForUDV, 0, 1, 0);
SYS_MODULE_START(sys_ps3_prx_entry);
SYS_MODULE_STOP(sys_ps3_prx_stop);

extern "C" int sys_ps3_prx_entry(void) {
	

	return 0;
}
extern "C" int sys_ps3_prx_stop(void)
{
	return 0;
}
