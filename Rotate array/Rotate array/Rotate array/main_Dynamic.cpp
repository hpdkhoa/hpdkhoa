#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

void Swap(int &a, int &b){
	a += b;
	b = a - b;
	a = a - b;
}

void Random(int **arr, int width, int height){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++)
		{
			arr[i][j] = rand() % 1000 + 1;
		}
	}
}

void Increasement(int **arr, int width, int height){
	int num = 1;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++)
		{
			arr[i][j] = num++;
		}
	}
}

void PrintArray(int **arr, int width, int height){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void RotateMaxSquare(int **arr, int width, int height){
	int maxRec = (width <= height) ? width - 1 : height - 1;
	for (int i = 0; i < (maxRec + 1) / 2; i++)
	{
		for (int j = 0; j + i < maxRec - i; j++)
		{
			//Swap two corner with each other
			Swap(arr[i][i + j], arr[maxRec - i][maxRec - i - j]);
			Swap(arr[i + j][maxRec - i], arr[maxRec - i - j][i]);

			//Swap follow direction
				//Top-left <-> Top-right
				//Top-right <-> Bot-right
				//Bot-right <-> Bot-left
			Swap(arr[i][i + j], arr[i + j][maxRec - i]);
			Swap(arr[i + j][maxRec - i], arr[maxRec - i][maxRec - i - j]);
			Swap(arr[maxRec - i][maxRec - i - j], arr[maxRec - i - j][i]);
		}
	}
}

void RotateOuterSquare(int **arr, int &width, int &height){
	if (width < height)
	{
		int deltaLeng = height - width - 1;
		//Move the rotated max square to the outer left
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < width; j++)
			{
				arr[i][height - j - 1] = arr[i][width - j - 1];
			}
		}
		//Move the unrotated square back to formation
		for (int i = width; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				arr[j][deltaLeng - i + width] = arr[i][j];
			}
		}
		Swap(width, height);
	}
	else
	{
		//width > height
		//Move the unrotated square back to formation
		for (int i = height; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				arr[i][height - j - 1] = arr[j][i];
			}
		}
		Swap(width, height);
	}
}

void ProcessRotate(int **arr, int &width, int &height){
	RotateMaxSquare(arr, width, height);
	if (width != height)
	{
		RotateOuterSquare(arr, width, height);
	}
}

void ReverseMaxSquare(int **arr, int width, int height){
	int maxRec = (width <= height) ? width - 1 : height - 1;
	for (int i = 0; i < (maxRec + 1) / 2; i++)
	{
		for (int j = 0; j + i < maxRec - i; j++)
		{
			//Swap two corner with each other
			Swap(arr[i][i + j], arr[maxRec - i][maxRec - i - j]);
			Swap(arr[i + j][maxRec - i], arr[maxRec - i - j][i]);

			//Swap follow direction
				//Bot-right <-> Bot-left
				//Top-right <-> Bot-right
				//Top-left <-> Top-right
			Swap(arr[maxRec - i][maxRec - i - j], arr[maxRec - i - j][i]);
			Swap(arr[i + j][maxRec - i], arr[maxRec - i][maxRec - i - j]);
			Swap(arr[i][i + j], arr[i + j][maxRec - i]);
		}
	}
}

void ReverseOuterSquare(int **arr, int &width, int &height){
	if (width > height)
	{
		int deltaLeng = width - height - 1;
		//Move the rotated square down to the bottom
		for (int i = width - 1; i > deltaLeng; i--)
		{
			for (int j = 0; j < height; j++)
			{
				arr[i][j] = arr[i - deltaLeng - 1][j];
			}
		}
		//Move the unrotated square back to formation
		for (int i = deltaLeng; i >= 0; i--)
		{
			for (int j = 0; j < height; j++)
			{
				arr[i][j] = arr[j][deltaLeng - i + height];
			}
		}
		Swap(width, height);
	}
	else
	{
		//width < height
		//Move the unrotated square back to formation
		for (int i = width; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				arr[j][i] = arr[i][width - j - 1];
			}
		}
		Swap(width, height);
	}
}

void ProcessReverse(int **arr, int &width, int &height){
	ReverseMaxSquare(arr, width, height);
	if (width != height)
	{
		ReverseOuterSquare(arr, width, height);
	}
}

void main(){
	/*Initialize system variables*/
	srand(time(NULL));
	int isRandom = 0, isReverse = 0;
	int width, height;

	/*Setup Menu*/
repeatInput:

inputHeight:
	cout << "Input height of the array: ";
	cin >> height;
	//Check wrong input of height
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		system("CLS");
		goto inputHeight;
	}

inputWidth:
	cout << "Input width of the array: ";
	cin >> width;
	//Check wrong input of width
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		system("CLS");
		goto inputWidth;
	}

	//Check wrong conditional of height and width
	if (height <= 0 || width <= 0)
	{
		cout << "You have inputed wrong height or width!!!" << endl;
		cout << "Input 1 to input again." << endl << "Input else to exit." << endl;
		cout << "Your choice: ";
		int option;
		cin >> option;
		//If fail the goto end
		while (cin.fail()) {
			goto endOfCode;
		}
		if (option == 1)
			goto repeatInput;
		else
			goto endOfCode;
	}

//inputIsRandom
	cout << "Input 1 for random value of the array" << endl << "Input else for increasement value of the array" << endl << "Your choice: ";
	cin >> isRandom;
	//Catch else case wrong input
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		system("CLS");
		isRandom = 0;
	}
	//Catch else case correct input
	if (isRandom != 1)
	{
		isRandom = 0;
	}

//inputIsReverse
	cout << "Input 1 for rotate - 90 degrees" << endl << "Input else for rotate 90 degrees" << endl << "Your choice: ";
	cin >> isReverse;
	//Catch else case wrong input
	while (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		system("CLS");
		isReverse = 0;
	}
	//Catch else case correct input
	if (isReverse != 1)
	{
		isReverse = 0;
	}
	/*End of menu*/

	/*Allocate dynamic array*/
	int MaxSize = width > height ? width : height;
	int **MyArray = new int*[MaxSize];
	for (int i = 0; i < MaxSize; ++i)
		MyArray[i] = new int[MaxSize];

	//Initialize value of the array
	if (isRandom)
	{
		Random(MyArray, width, height);
	}
	else{
		Increasement(MyArray, width, height);
	}

	system("CLS"); // Clear screen

	/*Print the original array*/
	cout << "Original array:" << endl;
	PrintArray(MyArray, width, height);

	/*Process the array
	 *I will rotate the maximum square first.
	 * *Stop if the array is square.
	 * *Move the left unrotated if the array is rectangle.
	 *
	 *I rotate the maximum square due to the minimum length of heigth and width.
	 * *The method to rotate is rotate each element to rotate the layer then do it to all layer to rotate the matrix.
	*/
	if (isReverse)
		ProcessReverse(MyArray, width, height);
	else
		ProcessRotate(MyArray, width, height);

	/*Print the result array*/
	cout << "Result array:" << endl;
	PrintArray(MyArray, width, height);

endOfCode:;
}

