#include "stdafx.h"
#include "vFileManager.h"

vFileManager::vFileManager(char* vFileName)
{
	vFileInstance = 0;
	isOpen = false;
	vfmLength = 0;
	int* tmpPtr = nullptr;
	vfmFileName = nullptr;
	vfmHowMuchRead = 0;
	vfmHowMuchWrite = 0;
	

	if ((std::filesystem::is_directory(vFileName)) == true)
	{
		vfmDirectory = true;
		return;
	}
		
	if ((std::filesystem::exists(vFileName)) == false)
		return;

	vfmFileName = new char[FILENAME_MAX + 1];
	memset(vfmFileName, 0, FILENAME_MAX);
	memcpy_s(vfmFileName, FILENAME_MAX, vFileName, FILENAME_MAX);

	tmpPtr = &this->vFileInstance;
	err_num = _sopen_s(tmpPtr, vFileManager::vfmFileName, _O_RDWR | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
	if (vFileManager::vFileInstance != -1)
		vFileManager::isOpen = true;
}

vFileManager::vFileManager()
{
	vfmFileName = NULL;
	vFileInstance = 0;
	isOpen = false;
	vfmLength = 0;
	vfmHowMuchRead = 0;
	vfmHowMuchWrite = 0;
}

vFileManager::~vFileManager()
{
	if (isOpen == true)
		_close(vFileInstance);
	isOpen = false;
	vfmLength = 0;
	vFileInstance = 0;
	if (vfmFileName != nullptr)
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

unsigned int vFileManager::vfmReadFile(void* Buffer, unsigned int howMuchRead)
{
	// TODO: Добавьте сюда код реализации.
	return (unsigned int)_read(vFileManager::vFileInstance, Buffer, howMuchRead);
}


unsigned int vFileManager::vfmWriteFile(void* Buffer, unsigned int howMuchWrite)
{
	// TODO: Добавьте сюда код реализации.
	return (unsigned int)_write(vFileManager::vFileInstance, Buffer, howMuchWrite);
}

bool vFileManager::vfmCreateFile(char* vFileName)
{

	vFileInstance = 0;
	isOpen = false;
	vfmLength = 0;
	int* tmpPtr = nullptr;
	vfmFileName = nullptr;
	vfmHowMuchRead = 0;
	vfmHowMuchWrite = 0;

	if ((std::filesystem::is_directory(vFileName)) == true)
	{
		vfmDirectory = true;
		return false;
	}

	if ((std::filesystem::exists(vFileName)) == true)
	{
		return false;
	}

	vfmFileName = new char[FILENAME_MAX + 1];
	memset(vfmFileName, 0, FILENAME_MAX);
	memcpy_s(vfmFileName, FILENAME_MAX, vFileName, FILENAME_MAX);

	tmpPtr = &this->vFileInstance;
	err_num = _sopen_s(tmpPtr, vFileManager::vfmFileName, _O_CREAT | _O_BINARY, _SH_DENYNO, _S_IREAD | _S_IWRITE);
	if (vFileManager::vFileInstance != -1)
		vFileManager::isOpen = true;

	return false;
}
