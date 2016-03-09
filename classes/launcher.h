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

		string ProccesName = LName + ".exe";
		ProccesName[0] = toupper(ProccesName[0]);

		while(1)
		{
			if(strcmp(pe.szExeFile, ProccesName.c_str()) == 0) {ON_OFF = true; break;}
			if(!Process32Next(hSnapshot, &pe)) {ON_OFF = false; break;}
		}
	}

	launcher(string _Name)
	{
		_onoff();

		if (_Name == "steam")
			{Account.login = STEAM_LOGIN;
			Account.password = STEAM_PASSWORD;}

		if (_Name == "origin")
			{Account.login = ORIGIN_LOGIN;
			Account.password = ORIGIN_PASSWORD;}

		if (_Name == "skype")
			{Account.login = SKYPE_LOGIN;
			Account.password = SKYPE_PASSWORD;}

		LName = _Name;
	}

	void Exit()
	{
		string REQUEST = "taskkill /f /im " + LName + ".exe";
		const char * SYS_REQUEST = REQUEST.c_str();
		system(SYS_REQUEST); Sleep(200);
		ON_OFF = false;
	}

	void Start()
	{
		_onoff();

		if (ON_OFF == true)
			Exit();

		if (ON_OFF == false)
		{
			AppBase.StartApp(LName);
			Sleep(6000);
			WINDOW = GetForegroundWindow();

			if (LName != "skype")
			{
				keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
				keybd_event(VK_TAB, 0, KEYEVENTF_EXTENDEDKEY, 0);
				keybd_event(VK_TAB, 0, KEYEVENTF_KEYUP, 0);
				keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			}

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
