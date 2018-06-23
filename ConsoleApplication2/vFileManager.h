#pragma once
class vFileManager
{
public:
	vFileManager(char* vFileName);
	~vFileManager();
protected:
	// Main variable for functioning this class
	int vFileInstance;
	bool isOpen;
	char* vfmFileName;
	// Size of file
	unsigned int vfmLength;
public:
	unsigned int Length();
	virtual bool vfmIsOpen();
};

