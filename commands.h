void Enter (string A)
{
	for (int i=0;i!=A.size();i++)
	{
		if(A[i] == tolower(A[i]) && A[i] >= '9')
		{
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(toupper(A[i]), 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(toupper(A[i]), 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			while (HIBYTE(GetKeyState( VK_SHIFT )) );
		} else {
			keybd_event(A[i], 0,0,0);
			keybd_event(A[i], 0, KEYEVENTF_KEYUP, 0);
		}
		Sleep(100);
	}
	keybd_event('\r', 0,0,0);
	keybd_event('\r', 0, KEYEVENTF_KEYUP, 0);
};

void Write (string A)
{
	for (int i=0;i!=A.size();i++)
	{
		if(A[i] == tolower(A[i]) && A[i] >= '9')
		{
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(toupper(A[i]), 0, KEYEVENTF_EXTENDEDKEY, 0);
			keybd_event(toupper(A[i]), 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_LSHIFT, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
			while (HIBYTE(GetKeyState( VK_SHIFT )) );
		} else {
			keybd_event(A[i], 0,0,0);
			keybd_event(A[i], 0, KEYEVENTF_KEYUP, 0);
		}
		Sleep(100);
	}
};
