void StartApp(string AppName)
{
	ifstream AppBase;
	AppBase.open("AppBase.bb");

	string URL = " ";
	bool SUCCESS = false;

	while (!AppBase.eof() && URL == " ")
	{
		string NameBuffer, URLBuffer;
		AppBase >> NameBuffer; AppBase >> URLBuffer;
		if (NameBuffer == AppName)
			{URL = URLBuffer; SUCCESS = true;}
	}

	if (SUCCESS)
	{
		string REQUEST = "start " + URL;
		const char * SYS_REQUEST = REQUEST.c_str();
		system(SYS_REQUEST); Sleep(200);
	} else {
		cout << "I do not know that app, Sir" << endl;
		Sleep(1500); system("cls");
	}

	AppBase.close();
}

void AddAppInBase()
{
	ofstream AppBase;
	AppBase.open("AppBase.bb", std::ios::app);
	string Buffer;

	cout << "Enter the name: "; cin >> Buffer;
	AppBase << Buffer << " ";
	cout << "Enter the URL: "; cin >> Buffer;
	AppBase << Buffer << endl;

	AppBase.close();
}

void Enter (string A)
{
	for (int i=0;i!=A.size();i++)
	{
		keybd_event(A[i], 0,0,0);
		keybd_event(A[i], 0, KEYEVENTF_KEYUP, 0);
		Sleep(100);
	}
	keybd_event('\r', 0,0,0);
	keybd_event('\r', 0, KEYEVENTF_KEYUP, 0);
};

void Write (string A)
{
	for (int i=0;i!=A.size();i++)
	{
		keybd_event(A[i], 0,0,0);
		keybd_event(A[i], 0, KEYEVENTF_KEYUP, 0);
		Sleep(100);
	}
};
