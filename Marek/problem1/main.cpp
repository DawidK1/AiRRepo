#include "strtype.h"

InType Allowed(std::string& inString);
bool Skip(std::string& inString);

int main()
{
	using namespace std;
	ifstream inFile; //plik zawierajacy operacje
	ifstream inData; //dane wejsciowe
	ofstream outFile; //plik wyjsciowy
	string inFileName;
	string outFileName;
	string inDataName;
	string outputLabel;
	string command;
	string skip;
	string allowed;
	StrType inputString;
	int numCommands;
}

InType Allowed(std::string& inString)
{
	if(inString == "ALPHA_NUM")
		return ALPHA_NUM;
	else if(inString == "ALPHA")
		return ALPHA;
	else if(inString == "NON_WHITE")
		return NON_WHITE;
	else return NOT_NEW;
}

bool Skip(std::string& inString)
{
	if(inString == "true")
		return true;
	else return false;
}
