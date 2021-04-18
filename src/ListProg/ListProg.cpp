
#include <iostream>
using namespace std;
class globalsettings {
private:
	bool exit;
	int selection;
public:

	void SetSelection(int value)
	{
		selection = value;
	}
	int GetSelection()
	{
		return selection;
	}
	void SetExit(bool value) 
	{
		exit = value;
	}
	bool GetExit() 
	{
		return exit;
	}
};

class LinkList 
{
public:

};

int main()
{	
	globalsettings settings;
	int selection;
	
	cin >> selection;
	settings.SetSelection(selection);
	MenuSelection();
	do 
	{
	
	}
	while (exit);
}
void MenuSelection() 
{
	globalsettings settings;
	switch (settings.GetSelection()) 
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		settings.SetExit(false);
		break;
	}
}


