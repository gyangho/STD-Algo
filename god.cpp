#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int count;
	cin >> count;
	cin.ignore();
	for (int i = 0; i < count; i++)
	{
		char* name = new char[101];
		char god[200] = "god";
		char* token;
		cin.getline(name, 101);
		token = strtok(name, " ");
		while (1)
		{
			token = strtok(NULL, " ");
			if (token == NULL)
				break;
			strcat(god, token);
		}
		cout << god << endl;
		delete[] name;
	}
}
