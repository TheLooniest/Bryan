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
