#pragma once
#include "FS.h"
#include "cell/rtc.h"
#include "Interop.h"
#include "Types.h"
namespace debug {
	
	char* fn = "/dev_hdd0/tmp/InputPort.log";
	void create()
	{
		truncateFile(fn);
		createFile(fn);
		appendStringToFile(fn, "Create trace\n");
	}
	int clear() {
		if (deleteFile(fn)) {
			truncateFile(fn);
		}

	}
	namespace out {
		char foofrm_mem[200];
		void write(char c) {
			char foo[1]{ c };
			appendToFile(fn, foo);
		}
		void write(char* strptr)
		{
			appendStringToFile(fn, strptr);
		}
		void writeL(char* strptr) {
			appendStringToFile(fn, strptr);
			write("\n");
		}
		void writeif(bool expr, char* outp) {
			if (expr) {
				write(outp);
			}
		}
		void writeN(char* strfrmptr, int i) {
			if (_sys_strlen(strfrmptr) > 199) {
				writeL("[snprintf writing error; Too long. PointlesS?]");
			}
			else
			{
				_sys_memset(foofrm_mem, 0, 200);
				_sys_sprintf(foofrm_mem, strfrmptr, i);
				write(foofrm_mem);
			}
		}
		void write_assert(uint err, char* name) {
			char c[50];
			snprintf(c,50, "%s: (%i) (0x%x)", name, err, err);
			writeL(c);
		}
	}
}

#define dbg debug::out::write
#define dbgl debug::out::writeL