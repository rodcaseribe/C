#include <studio.h>
#include <windows.h>
using namespace std;
int main(){

	HKEY hkey;
	LONG regOpenResult;
	const char PATH[] = "C:\\random folder\\filename.exe"; /*This is
							     the path of
							     your program*/

	regOpenResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
				     "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
				     0,
				     KEY_ALL_ACCESS,
				     &hkey);

	RegSetValueEx(hkey,
		      "Random name", //This is the name that shows up in your registry
		      0,
		      REG_SZ,
		      (BYTE*)PATH,
		      strlen(PATH));

	RegCloseKey(hkey);

	return 0;
}
