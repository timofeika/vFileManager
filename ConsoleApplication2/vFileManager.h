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
	unsigned long vfmHowMuchRead;
	unsigned int vfmWriteFile(void* Buffer, unsigned int howMuchWrite);
	unsigned int vfmHowMuchWrite;
};

