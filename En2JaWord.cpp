#include <iostream>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>

using namespace std;
void inputWord(string& word)
{
	cout << "‰p’PŒê‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(¬•¶Žš)  \"Exit\":I—¹,  \"Print\":output.txt‚É‹L˜^" << endl;
	cin >> word;
}
bool findMap(unordered_map<string, string>& map, const string& word)
{
	if (map.find(word) != map.end())
	{
		cout << map[word];
		return true;
	}
	return false;
}

void init(string&, string&, unordered_map<string, string>&);

int main(int argc, char** argv)
{
	string key{};
	string value{};
	unordered_map<std::string, std::string> map;
	vector<string> keyBuffer;
	ofstream ofs("C:/En2Ja/output.txt", ios_base::app | ios_base::out);
	if (ofs.bad())
	{
		cout << "Error" << endl;
	}
	init(key, value, map);

	string word;
	if (argc < 2)
		inputWord(word);
	else
		word = string(argv[1]);
	if (word == "Exit")return 0;
	if (word == "Print") cout << "‚Ü‚¾‰½‚à“ü—Í‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ." << endl;
	else if (findMap(map, word))
	{
		keyBuffer.push_back(word);
	}
	else
		cout << "Œ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
	cout << endl;
	for (int i = 2; i < argc; i++)
	{
		word = string(argv[i]);
		if (word == "Exit")
			return 0;
		if (word == "Print")
		{
			for (auto& i : keyBuffer)
			{
				ofs << i << ":" << "\n";
				ofs << map[i];
				ofs << "\n";
			}
		}
		else if (findMap(map, word))
		{
			keyBuffer.push_back(word);
		}
		else
			cout << "Œ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
		cout << endl;
	}
	while (true)
	{
		inputWord(word);
		if (word == "Exit")
			break;
		if (word == "Print")
		{
			for (auto& i : keyBuffer)
			{
				ofs << i << ":" << "\n";
				ofs << map[i];
				ofs << "\n";
			}
		}
		else if (findMap(map, word))
		{
			keyBuffer.push_back(word);
		}
		else
			cout << "Œ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
		cout << endl;
	}
	ofs.close();
	return 0;
}

void init(string& key, string& value, unordered_map<string, string>& map)
{
	ifstream istr{};
	istr.open("C:/En2Ja/ejdict-hand-utf8.txt");
	if (istr.fail())
	{
		cout << "error" << endl;
		std::exit(-1);
	}
	while (true)
	{
		char c = 0;
		while (c != '	')
		{
			c = istr.get();
			key.push_back(c);
		}
		key.pop_back();
		while (c != '\n')
		{
			c = istr.get();
			value.push_back(c);
			if (c == '/')
				value.push_back('\n');
		}
		map.emplace(key, value);
		key.clear();
		value.clear();
		key.shrink_to_fit();
		value.clear();
		value.shrink_to_fit();
		c = istr.peek();
		if (c == EOF)
			break;
	}
}

