#include <iostream>
#include <vector>
#include <memory>
#include <Windows.h>
#include <utility>

#include "Figure.h"

typedef std::string(*LPGETPLUGGINFIGURENAME)();
typedef std::shared_ptr<Figure>(*LPGETPLUGINFIGURE)();

std::wstring DllsPath()
{
	TCHAR buffer[MAX_PATH]{ 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
	return ((std::wstring(buffer).substr(0, pos)).append(L"\\*.dll"));
}

std::vector<std::pair<int, HMODULE>> EnumeratePlugins()
{
	std::vector<std::pair<int, HMODULE>> result;
	int index = 1;
	WIN32_FIND_DATA wfd;
	HANDLE hSearchHandle;

	std::wstring searchTemplate = DllsPath();
	hSearchHandle = FindFirstFile(searchTemplate.c_str(), &wfd);
	if (hSearchHandle == INVALID_HANDLE_VALUE)
		return result;

	do
	{
		HMODULE dll = LoadLibrary(wfd.cFileName);
		if (dll == NULL)
			continue;

		if (GetProcAddress(dll, "GetPluginFigureName") != NULL)
		{
			result.push_back(std::make_pair(index, dll));
			index++;
		}
		else
		{
			FreeLibrary(dll);
		}
	} while (FindNextFile(hSearchHandle, &wfd) != 0);

	FindClose(hSearchHandle);

	return result;
}

int main()
{
	std::vector<std::shared_ptr<Figure>> figures;
	int num;
	bool doInput = true;

	std::vector<std::pair<int, HMODULE>> dlls = EnumeratePlugins();

	while (doInput == true)
	{
		for (auto pluginInfo : dlls)
		{
			LPGETPLUGGINFIGURENAME GetPluginFigureName = (LPGETPLUGGINFIGURENAME)GetProcAddress(pluginInfo.second, "GetPluginFigureName");
			if (GetPluginFigureName == NULL)
				continue;
			std::cout << pluginInfo.first << ". " << GetPluginFigureName() << std::endl;
		}
		
		std::cout << "0. Exit" << std::endl;

		std::cin >> num;

		if (num == 0)
		{
			doInput = false;
			continue;
		}

		HMODULE activeModule = NULL;

		for (auto pluginInfo : dlls)
		{
			if (pluginInfo.first == num)
			{
				activeModule = pluginInfo.second;
				break;
			}
		}

		if (activeModule == NULL)
		{
			std::cout << "Bad Figure number, try again!" << std::endl;
			continue;
		}

		LPGETPLUGINFIGURE GetPluginFigure = (LPGETPLUGINFIGURE)GetProcAddress(activeModule, "GetPluginFigure");
		if (GetPluginFigure == NULL)
		{
			std::cout << "Bad plugin, try again!" << std::endl;
			continue;
		}

		figures.push_back(GetPluginFigure());
	}

	for (auto f : figures)
	{
		std::cout << f->GetName() << " Square: " << f->GetSquare() << ", Perimeter: " << f->GetPerimeter() << std::endl;
	}

	figures.clear();

	for (auto dll : dlls)
	{
		FreeLibrary(dll.second);
	}

	return 0;
}