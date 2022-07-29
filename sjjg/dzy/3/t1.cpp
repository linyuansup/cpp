#include <bits/stdc++.h>
#include "HuffmanTree.h"
using namespace std;

double file_size(char* filename)
{
	FILE* fp = fopen(filename, "rb");
	int size;
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fclose(fp);
	return (double)size / 1000;
}

bool allSame(string s)
{
	for (int i = 1; i < s.length(); i++)
		if (s[i] != s[0])
			return false;
	return true;
}

// 2 * num
int twoMode(int num)
{
	int returnData = 1;
	for (int i = 0; i < num; i++)
		returnData *= 2;
	return returnData;
}

// a binary string (length 8) to char data
char stringToChar(string s)
{
	int returnData = 0;
	for (int i = 7; i >= 0; i--)
		returnData += twoMode(7 - i) * static_cast<int>(s[i] - '0');
	return static_cast<char>(returnData - 128);
}

// a char data to binary string (length 8)
string charToString(char s)
{
	int inData = static_cast<int>(s + 128);
	string returnData;
	while (inData != 0)
	{
		int ret = inData % 2;
		if (ret)
			returnData.insert(returnData.begin(), '1');
		else
			returnData.insert(returnData.begin(), '0');
		inData /= 2;
	}

	// add 0 for 8 length
	while (returnData.length() != 8)
		returnData.insert(returnData.begin(), '0');
	return returnData;
}

void zipFile(char* inFile, char* outFile)
{
	// get file data
	ifstream fileIn;
	list<char> inData; // all file data (char)
	fileIn.open(inFile, ios::in | ios::binary);
	cout << "Reading File...";
	char c;
	while (fileIn.get(c))
		inData.insert(inData.end(), c);
	fileIn.close();

	// prepare data's freq and node
	cout << "Done!" << endl << "Making tree...";
	int freq[256];
	memset(freq, 0, sizeof(freq));
	for (char& pos : inData)
		freq[static_cast<int>(pos) + 128]++;
	HuffmanTree tree;
	tree.insertData(freq);
	map<char, string> mapData = tree.getZipRelation(); // the relation of char (inData) to string (out binary data)

	// write the freq data with pos
	cout << "Done!" << endl << "Writing file...";
	ofstream fileOut;
	fileOut.open(outFile, ios::out | ios::binary);
	fileOut.write((char*)(freq), sizeof(freq));

	// prepare out file and write
	string outData;
	while (!inData.empty())
	{
		outData.append(mapData[*inData.begin()]);
		while (outData.length() > 8)
		{
			fileOut.put(stringToChar(outData.substr(0, 8)));
			outData = outData.substr(8);
		}
		inData.erase(inData.begin());
	}

	// construct for less than 8 length and equal to 8 length and write
	// set the last num to not the string's last num that could find the string's last num
	int needToAddNum = 8, addData = 0;
	if (outData.length() < 8)
		needToAddNum -= static_cast<int>(outData.length());
	if (outData[outData.length() - 1] == '0')
		addData = 1;
	for (int i = 0; i < needToAddNum; i++)
		outData += to_string(addData);
	while (!outData.empty())
	{
		fileOut.put(stringToChar(outData.substr(0, 8)));
		outData = outData.substr(8);
	}

	// finally
	fileOut.close();
	cout << "Done!" << endl << "All Done!" << endl << "In file size is " << file_size(inFile) << " kb" << endl
		 << "Out file size is " << file_size(outFile) << " kb" << endl
		 << "Compressibility " << (double)file_size(outFile) / file_size(inFile) * 100 << "%" << endl;
}

void unzipFile(char* inFile, char* outFile)
{
	ifstream fileIn;
	ofstream fileOut;
	list<char> inData;
	fileIn.open(inFile, ios::in | ios::binary);
	fileOut.open(outFile, ios::out | ios::binary);

	// read freq data from lip first
	int freq[256];
	fileIn.read((char*)(freq), sizeof(freq));

	// make tree according to data
	cout << "Reading Huffman Tree...";
	HuffmanTree tree;
	tree.insertData(freq);
	string outString;
	char c;

	// read data and find the char
	cout << "Done!" << endl << "Unzipping...";
	while (true)
	{
		if (fileIn.get(c))
			outString += charToString(c);
		else
			break;
		if (outString.length() > 256)
			fileOut.put(tree.findCorrChar(outString));
	}

	fileIn.close();

	// the last string data is no use, and the same data from back to the
	// last one is no use too
	while (!allSame(outString))
		fileOut.put(tree.findCorrChar(outString));
	cout << "Done!" << endl << "All Done!";
	fileOut.close();
}

int main(int args, char* argv[])
{
	if (args == 4)
	{
		if (strcmp(argv[1], "zip") == 0)
			zipFile(argv[2], argv[3]);
		else if (strcmp(argv[1], "unzip") == 0)
			unzipFile(argv[2], argv[3]);
		return EXIT_SUCCESS;
	}
	cout << "Usage: lip [zip/unzip] [inFilePath] [OutputPath]";
	return EXIT_FAILURE;
}