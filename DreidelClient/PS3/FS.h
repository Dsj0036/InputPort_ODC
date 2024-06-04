#pragma once
#include <cell/cell_fs.h>
bool create_directory(char* path) { return cellFsMkdir(path, CellFsMode(CELL_FS_O_RDWR) == CELL_OK); }
uint64_t get_fsize(char* path)
{
	struct CellFsStat s;
	if (cellFsStat(path, &s) == CELL_FS_SUCCEEDED) {
		if (s.st_size > 0) {
			return s.st_size;
		}
	}
	return -1;
}void changeExtension(char* path, const char* newExtension) {
	int length = 0;

	// Find the length of the path
	while (path[length] != '\0') {
		length++;
	}

	// Traverse the path backward to find the last '.'
	int i = length - 1;
	while (i >= 0 && path[i] != '.') {
		i--;
	}

	// If a dot was found, replace the extension
	if (i >= 0) {
		int j = 0;
		while (newExtension[j] != '\0') {
			path[i + 1 + j] = newExtension[j];
			j++;
		}

		// Set the null terminator at the end of the new path
		path[i + 1 + j] = '\0';
	}
}
int deleteFile(const char* filePath) {
	CellFsErrno fsErr;
	CellFsStat stat;

	// Check if the file exists
	if (cellFsStat(filePath, &stat) != 0) {
		// File doesn't exist
		return -1;
	}

	// Delete the file
	if (cellFsUnlink(filePath) != 0) {
		// Failed to delete the file
		return -1;
	}

	return 0; // File deleted successfully
}

void extractDirectory(const char* filename, char* directory) {
	int length = 0;

	// Find the length of the filename
	while (filename[length] != '\0') {
		length++;
	}

	// Traverse the filename backward to find the last '/'
	int i = length - 1;
	while (i >= 0 && filename[i] != '/') {
		i--;
	}

	// Copy the directory to the output buffer
	int j = 0;
	while (j <= i) {
		directory[j] = filename[j];
		j++;
	}

	// Add null terminator to the directory string
	directory[j] = '\0';
}

int dir_exists(const char* path, CellFsErrno* e)
{
	int fd;
	int errn;
	errn = cellFsOpendir(path, &fd);
	if (errn != 0) {
		errn = cellFsClosedir(fd);
		return false;
	}
	e = &errn;
	cellFsClosedir(fd);
	return true;
}

bool file_exists(const char* path)
{
	int fdl;
	CellFsErrno readLic;
	readLic = cellFsOpen(path, CELL_FS_O_RDONLY, &fdl, NULL, 0);
	cellFsClose(fdl);
	if (readLic == CELL_OK)
	{
		return true;
	}
	else return false;

}
char* read_file(char* File)
{
	char* Result;
	int fdl;
	char licStr[32];
	CellFsErrno readLic;
	uint64_t swl;

	readLic = cellFsOpen(File, CELL_FS_O_RDONLY, &fdl, NULL, 0);

	if (readLic == 0)
	{
		cellFsRead(fdl, licStr, sizeof(licStr), &swl);
		Result = licStr;
		cellFsClose(fdl);
	}
	return Result;
}
bool RenameFile(char* target, char* renameTo)
{
	return cellFsRename(target, renameTo) == 0;
}
bool DeleteDirectory(char* path)
{
	return cellFsRmdir(path) == 0;
}
void createFile(char* loc) {
	int fd;
	int ret;
	ret = cellFsOpen(loc, CELL_FS_O_CREAT | CELL_FS_O_RDWR | CELL_FS_O_TRUNC, &fd, NULL, 0);
	cellFsClose(fd);
	if (!ret) {
		cellFsClose(fd);
	}
}
void clearFile(char* loc) {
	int fd;
	int ret;
	ret = cellFsOpen(loc, CELL_FS_O_RDWR | CELL_FS_O_TRUNC, &fd, 0, 0);
	cellFsClose(fd);
	if (!ret) {
		cellFsClose(fd);
	}
}
void writeToFile(char* file, char buf[] = 0, int size = 0) {
	CellFsErrno err;
	int fd;
	uint64_t nrw;
	int ret;
	err = cellFsOpen(file, CELL_FS_O_RDWR | CELL_FS_O_CREAT, &fd, 0, 0);
	cellFsTruncate(file, 0);
	if (size != 0)
		err = cellFsWrite(fd, (const void*)buf, (uint64_t)size, &nrw);
	err = cellFsClose(fd);
}
void appendToFile(char* file, char buf[] = 0, int size = 0) {
	int err;
	int fd;
	uint64_t nrw;
	int ret;
	err = cellFsOpen(file, CELL_FS_O_RDWR | CELL_FS_O_APPEND | CELL_FS_O_CREAT, &fd, NULL, 0);
	if (size != 0)
		err = cellFsWrite(fd, (const void*)buf, (uint64_t)size, &nrw);
	err = cellFsClose(fd);
}
void appendToFile(int fd, char buff[] = 0) {

	uint64_t nrw;
	cellFsWrite(fd, (const void*)buff, (uint64_t)strlen(buff), &nrw);
}
void appendStringToFile(char* file, char buf[] = 0)
{
	appendToFile(file, buf, strlen(buf));
}
static const char* get_ext(const char* path)
{
	if (!path || !(*path)) return path;

	const int len = strlen(path);
	const char* ext = path + len - 1;
	const char* end = ext - ((*ext == ']') ? 13 : 6); // search limit 6 or 13 chars
	if (*ext == '0') ext--;
	while (--ext > path)
		if ((*ext == '.') || (ext <= end)) break;
	if (*ext != '.') ext = path + len;
	return ext;
}

static char* get_filename(const char* path)
{
	if (!path) return NULL; // sanity check

	char* filename = _sys_strchr((char*)path, '/'); if (!filename) return (char*)path;
	return filename; // return with slash
}

static char* remove_filename(const char* path)
{
	char* p = get_filename(path); if (p) *p = NULL; else p = (char*)path;
	return p;
}
static void truncateFile(const char* filename) {
	int foo;
	cellFsOpen(filename, CELL_FS_O_CREAT | CELL_FS_O_TRUNC, &foo, 0, 0);
	cellFsClose(foo);
}
size_t read_file_with_offset(char* file, char* data, const size_t size, int64_t offset)
{
	if (!file || !data) { return 0; }// sanity check

	int fd = 0; uint64_t read_e = 0;

	if (cellFsOpen(file, CELL_FS_O_RDONLY, &fd, NULL, 0) == CELL_FS_SUCCEEDED)
	{
		if (cellFsReadWithOffset(fd, offset, (void*)data, size, &read_e) != CELL_FS_SUCCEEDED) read_e = 0;
		cellFsClose(fd);
	}
	else
	{
		return -1;
	}
	return read_e;
}