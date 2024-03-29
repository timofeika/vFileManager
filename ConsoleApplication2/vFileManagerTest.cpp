// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: ConsoleApplication2 <file>");
		return 1;
	}
	printf("arg = %s\n", argv[argc - 1]);
	vFileManager vm(argv[argc - 1]);
	if (vm.vfmIsDirectory() == true)
	{
		printf("%s is directory\n", argv[argc - 1]);
		return	1;
	}
	if (vm.vfmIsOpen() == true)
		printf("File size is: %d bytes\n", vm.Length());
	else
	{
		printf("Cannot open %s, error number: %d\n", argv[argc - 1], vm.err_num);
	}
	

	char str[80];

	strcpy_s(str, argv[argc - 1]);
	strcpy_s(str, "tst");

	if (vm.vfmCreateFile(str) == false)
	{
		printf("Cannot create file: %s", str);
		return 1;
	}

    return 0;
}

