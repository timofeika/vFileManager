#pragma once
class vFileManager
{
public:
	vFileManager(char* vFileName);
	vFileManager();
	~vFileManager();
protected:
	int vFileInstance;			// Main variable for functioning this class
	bool isOpen;				// Is file open? true = yes, false = no
	char* vfmFileName;			// File name
	unsigned int vfmLength;		// Size of file

public:
	unsigned int Length();
	inline bool vfmIsOpen() { return vFileManager::isOpen; }
	unsigned int vfmReadFile(void* Buffer, unsigned int howMuchRead);
	unsigned int vfmWriteFile(void* Buffer, unsigned int howMuchWrite);
	inline bool vfmIsDirectory() { return vFileManager::vfmDirectory; }
	errno_t err_num;
protected:
	unsigned long vfmHowMuchRead;
	unsigned int vfmHowMuchWrite;
	bool vfmDirectory = false;	// Is name directory? true = yes, false = no
	bool vfmIsExists = true;	// Is file exists? true = yes, false = no
public:
	bool vfmCreateFile(char* vFileName);
};

