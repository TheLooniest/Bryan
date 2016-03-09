class App_Base
{
private:
	ifstream AppBase;
	ofstream output;
public:
	App_Base()
	{

	};

	void StartApp(string AppName)
	{
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
		output.open("AppBase.bb", std::ios::app);
		string Buffer;

		cout << "Enter the name: "; cin >> Buffer;
		output << Buffer << " ";
		cout << "Enter the URL: "; cin >> Buffer;
		output << Buffer << endl;

		output.close();
	}

	~App_Base()
	{

	}
};

App_Base AppBase;
