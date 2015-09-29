#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isCorrectType(const string &type)
{
	return (type == "INTEGER" || type == "STRING" || type == "BOOLEAN" || type == "DOUBLE");
}

bool IsCorrectDecl(const string &line)
{
	string declString = "", idString = "", typeAssignString = "", typeString = "";

	istringstream iss(line);
	getline(iss, declString, ' ');
	getline(iss, idString, ' ');
	getline(iss, typeAssignString, ' ');
	getline(iss, typeString, ' ');

	return (declString == "VAR" && idString == "IDENTIFIER" && typeAssignString == "COLON" && isCorrectType(typeString));
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Not enough arguments" << endl;
		return 0;
	}

	ifstream fin(argv[1]);
	if (!fin)
	{
		cout << "No such file" << endl;
		return 0;
	}

	ofstream fout("result.txt");
	string line;
	while (getline(fin, line))
	{
		if (line != "")
		{
			fout << line << " - ";
			if (IsCorrectDecl(line))
			{
				fout << "correct";
			}
			else
			{
				fout <<	"incorrect";
			}

			fout << endl;
		}
	}

	return 0;
}