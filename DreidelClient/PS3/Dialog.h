#include <sysutil/sysutil_msgdialog.h>
#include <sysutil/sysutil_oskdialog.h>
#include <sysutil/sysutil_oskdialog_ext.h>

#include <sys/prx.h>
#include <cellstatus.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <stdarg.h>
#include <assert.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/return_code.h>
#include <stddef.h>
#include <math.h>
#include <stdarg.h>
#include <cellstatus.h>
#include <typeinfo>
#include <vector>
#include <pthread.h>
#include <locale.h>
#include <cell/error.h>
#include <sys/paths.h> 
#include <sys/fs.h> 
#include <sys/fs_external.h> 
#include <cell/cell_fs.h>
#include <cell/fs/cell_fs_file_api.h>
#include <time.h>
#include <sys/return_code.h>
#include <sysutil/sysutil_oskdialog.h>
#include <sysutil/sysutil_msgdialog.h>
#include "Trace.h"
#pragma once
namespace MessageDialog
{
	void Show(char* message, float delayMs = 10000)
	{
		cellMsgDialogOpen(
			CELL_MSGDIALOG_TYPE_BUTTON_TYPE_OK |
			CELL_MSGDIALOG_TYPE_BG_VISIBLE
			, message, NULL, NULL, NULL);
		cellMsgDialogClose(delayMs);
	}
	void RequestReportProgress(unsigned int index, int value) {
		cellMsgDialogProgressBarInc(index, value);
	}
	void RequestSetMessage(int index, char* msg) {
		cellMsgDialogProgressBarSetMsg(index, msg);
	}
	void ShowProgressC(char* message, char* bottomMsg, int delayMs = 3500, int initialValue = 50)
	{
		unsigned int type =
			CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL | CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_NONE | CELL_MSGDIALOG_TYPE_BUTTON_TYPE_NONE | CELL_MSGDIALOG_TYPE_BG_VISIBLE | CELL_MSGDIALOG_TYPE_PROGRESSBAR_SINGLE;
		cellMsgDialogOpen2(type, message, NULL, NULL, NULL);
		cellMsgDialogProgressBarSetMsg(CELL_MSGDIALOG_PROGRESSBAR_INDEX_SINGLE, bottomMsg);
		RequestReportProgress(CELL_MSGDIALOG_PROGRESSBAR_INDEX_SINGLE, initialValue);
		cellMsgDialogClose(delayMs == 0 ? 3500 : delayMs);
	}
	void ShowProgress(char* message, char* bottomMsg, int initialValue = 50)
	{
		unsigned int type =
			CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL | CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_NONE | CELL_MSGDIALOG_TYPE_BUTTON_TYPE_NONE | CELL_MSGDIALOG_TYPE_BG_VISIBLE | CELL_MSGDIALOG_TYPE_PROGRESSBAR_SINGLE | CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON;
		cellMsgDialogOpen2(type, message, NULL, NULL, NULL);
		cellMsgDialogProgressBarSetMsg(CELL_MSGDIALOG_PROGRESSBAR_INDEX_SINGLE, bottomMsg);
		RequestReportProgress(CELL_MSGDIALOG_PROGRESSBAR_INDEX_SINGLE, initialValue);
	}
	void Show(char* message, int initialProgress, int delayMs = 10000)
	{
		cellMsgDialogOpen(
			CELL_MSGDIALOG_TYPE_PROGRESSBAR_SINGLE |
			CELL_MSGDIALOG_TYPE_BG_VISIBLE |
			CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_OFF,
			message, NULL, NULL, NULL);
		cellMsgDialogProgressBarInc(initialProgress, 1);
		cellMsgDialogClose(delayMs);
	}
	void ShowOk(char* message) {
		unsigned int type =
			CELL_MSGDIALOG_TYPE_BG_VISIBLE | CELL_MSGDIALOG_TYPE_BUTTON_TYPE_OK | CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_OK | CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON;
		cellMsgDialogOpen(type, message, NULL, NULL, NULL);
	}
	void Show(char* message, int progress, int delta, char* bottomText)
	{
		cellMsgDialogOpen(CELL_MSGDIALOG_TYPE_PROGRESSBAR_SINGLE |
			CELL_MSGDIALOG_TYPE_BG_VISIBLE |
			CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_OFF, message, NULL, NULL, NULL);

		cellMsgDialogProgressBarInc(progress, delta);
		cellMsgDialogProgressBarSetMsg(progress, bottomText);
	}

	void SetMessageActive(int index, char* bottomText)
	{
		cellMsgDialogProgressBarSetMsg(index, bottomText);
	}
	/*

	*/
#pragma once
}