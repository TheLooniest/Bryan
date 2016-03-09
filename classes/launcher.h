struct account {
  string login;
  string password;
};

class launcher
{
private:
	account Account;
public:
	bool ON_OFF;
	string LName;
	HWND WINDOW;

	void _onoff()
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

		PROCESSENTRY32 pe;
		pe.dwSize = sizeof(PROCESSENTRY32);
		Process32First(hSnapshot, &pe);

		if(LName == "origin")
		{
			while(1)
			{
				if(strcmp(pe.szExeFile, "Origin.exe") == 0) {ON_OFF = true; break;}
				if(!Process32Next(hSnapshot, &pe)) {ON_OFF = false; break;}
			}
		}
		if(LName == "steam")
		{
			while(1)
			{
				if(strcmp(pe.szExeFile, "Steam.exe") == 0) {ON_OFF = true; break;}
				if(!Process32Next(hSnapshot, &pe)) {ON_OFF = false; break;}
			}
		}
	}

	launcher(string _Name)
	{
		_onoff();

		if (_Name == "steam")
			{Account.login = "GLOOM481";
			Account.password = "G132400G481";}

		if (_Name == "origin")
			{Account.login = "THELOONIEST";
			Account.password = "W553466354";}

		if (_Name == "skype")
			{Account.login = "SLIPPER.GLOOM";
			Account.password = "132400553466354W";}

		LName = _Name;
	}


	void Exit()
	{
		string REQUEST = "taskkill /f /im " + LName + ".exe";
		const char * SYS_REQUEST = REQUEST.c_str();
		system(SYS_REQUEST); Sleep(200);
		ON_OFF = false;
	}

	void Start(account Account)
	{
		_onoff();

		if (ON_OFF == true)
			Exit();

		if (ON_OFF == false)
		{
			StartApp(LName);
			Sleep(6000);
			WINDOW = GetForegroundWindow();

			keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			Sleep(100);

			while (HIBYTE(GetKeyState( VK_CONTROL )) || HIBYTE(GetKeyState( VK_SHIFT )) );

			keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event('A', 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_LCONTROL, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			while (HIBYTE(GetKeyState( VK_CONTROL )) || HIBYTE(GetKeyState( VK_SHIFT )) );

			Write(Account.login);

			Sleep(100);

			keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			Sleep(100);

			Write(Account.password);

			if (LName == "origin")
			{
				keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
				keybd_event('W', 0, KEYEVENTF_EXTENDEDKEY, 0);
				keybd_event('W', 0, KEYEVENTF_KEYUP, 0);
				keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			}

			keybd_event('\r', 0,0,0);
			keybd_event('\r', 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

			Sleep(2000);
		}
		ON_OFF = true;
	}
};
