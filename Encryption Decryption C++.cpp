//Final project 
#include <iostream>
#include <fstream>
using namespace std;

//readFile function
void readFile(ifstream& inFile, char in[], int size) {
	for (int i = 0; i < size; i++) {
		inFile >> in[i];
	}
}

//display function
void dispArray(char in[], int size) {
	for (int j = 0; j < size; j++) {
		cout << in[j] << " ";
	}
}

//Calulate the key function
int key(char in[], int size) {
	int count = 0;
	for (int k = 0; k < size; k++) {
		if (in[k] == 'A' || in[k] == 'E') {
			count++;
		}
	}
	return count;
}

//encrypting function
void encrypt(char in[], char cipher[], int size, int key) {
	for (int a = 0; a < size; a++) {
		cipher[a] = in[a] + key;
	}
}

//decrypting fuction
void decrypt(char cipher[], char decipher[], int size, int key) {
	for (int b = 0; b < size; b++) {
		decipher[b] = cipher[b] - key;
	}
}

//reverse function
void revArray(char in[], char rev[], int size) {
	for (int c = size - 1; c >= 0; c--) {
		rev[c] = in[c];
		cout << rev[c] << " ";
	}
}


int main()
{
	// Variables
	int const SIZE = 8;
	char in[SIZE];
	char cipher[SIZE];
	char decipher[SIZE];
	char rev[SIZE];
	int offsetKey;

	// File stream object
	ifstream inFile;

	// Open the file "in.txt"
	inFile.open("in.txt");

	// Test for errors.
	if (!inFile)
	{
		cout << "Error opening the file.\n";
		return 0;
	}
	// Read the letters into the array.
	readFile(inFile, in, SIZE);

	// Close the file.
	inFile.close();

	//displays the array
	dispArray(in, SIZE);

	//finds the value to offset the characters
	offsetKey = key(in, SIZE);
	cout << endl;
	cout << offsetKey;

	cout << endl;
	//adds the offsetkey to the letters
	encrypt(in, cipher, SIZE, offsetKey);
	//displays the encryption
	dispArray(cipher, SIZE);

	cout << endl;
	//subtracts the offsetKey to the letters
	decrypt(cipher, decipher, SIZE, offsetKey);
	//displays the decryption
	dispArray(decipher, SIZE);

	cout << endl;
	//reverses the array and displays it
	revArray(in, rev, SIZE);
	cout << endl;
	//deciphers the array
	dispArray(rev, SIZE);

	return 0;
}
