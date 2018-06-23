#include "stdafx.h"
#include "vFileManager.h"


vFileManager::vFileManager(char* vFileName)
{
	vFileInstance = 0;
	isOpen = false;
	vfmLength = 0;
	int* tmpPtr = nullptr;

	vfmFileName = new char[FILENAME_MAX + 1];
	memset(vfmFileName, 0, FILENAME_MAX);
	memcpy_s(vfmFileName, FILENAME_MAX, vFileName, FILENAME_MAX);

	tmpPtr = &this->vFileInstance;
	_sopen_s(tmpPtr, vFileManager::vfmFileName, _O_RDWR, _SH_DENYNO, _S_IREAD | _S_IWRITE);
	if (vFileManager::vFileInstance != -1)
		vFileManager::isOpen = true;
}


vFileManager::~vFileManager()
{
	if (isOpen == true)
		_close(vFileInstance);
	isOpen = false;
	vfmLength = 0;
	vFileInstance = 0;
	delete[] vfmFileName;
}


unsigned int vFileManager::Length()
{
	// TODO: Добавьте сюда код реализации.
	_lseek(vFileManager::vFileInstance, 0L, SEEK_SET);
	vFileManager::vfmLength = _lseek(vFileManager::vFileInstance, 0L, SEEK_END);
	if (vFileManager::vfmLength != -1)
	{
		isOpen = true;
		return	_tell(vFileManager::vFileInstance);
	}
	isOpen = false;
	return 0;
}


bool vFileManager::vfmIsOpen()
{
	// TODO: Добавьте сюда код реализации.
	return isOpen;
}
