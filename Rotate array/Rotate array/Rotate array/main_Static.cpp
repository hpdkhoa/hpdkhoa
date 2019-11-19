//#include <iostream>
//#include <iomanip>
//#include <cstdlib>
//#include <time.h>
//
//using namespace std;
//
//void Swap(int &a, int &b){
//	a += b;
//	b = a - b;
//	a = a - b;
//}
//
//void Random(int arr[], int len){
//	for (int i = 0; i < len; i++){
//		arr[i] = rand() % 1000 + 1;
//	}
//}
//
//void Increasement(int arr[], int len, int &num){
//	for (int i = 0; i < len; i++)
//	{
//		arr[i] = num++;
//	}
//}
//
//void main() {
//	srand(time(NULL));
//	bool isRandom = false;
//	int Arr[100][100];
//	int width, height;
//	cout << "Input height of the array: ";
//	cin >> height;
//	cout << "Input width of the array: ";
//	cin >> width;
//	cout << "Input 0 for increasement value of the array" << endl << "Input 1 for random value of the array" << endl << "Your choice: ";
//	cin >> isRandom;
//
//	//Initialize the array
//	if (isRandom)
//	{
//		for (int i = 0; i < height; i++)
//		{
//			Random(Arr[i], width);
//		}
//	}
//	else{
//		int increasement = 1;
//		for (int i = 0; i < height; i++)
//		{
//			Increasement(Arr[i], width, increasement);
//		}
//	}
//
//	system("CLS");
//	
//	/*Print the array*/
//	cout << "Original array:" << endl;
//	for (int i = 0; i < height; i++){
//		for (int j = 0; j < width; j++){
//			cout << Arr[i][j] << "\t";
//		}
//		cout << endl;
//	}
//
//	/*Process the rotate*/
//	int minRec = (width <= height) ? width - 1 : height - 1;
//	/*Process Layer*/
//	for (int i = 0; i < (minRec +1) / 2; i++)
//	{
//		/*Process Elements*/
//		
//		for (int j = 0; j + i < minRec - i; j++)
//		{
//			int top_left = Arr[i][i + j];
//			int top_right = Arr[i + j][minRec - i];
//			int bot_left = Arr[minRec - i - j][i];
//			int bot_rigth = Arr[minRec - i][minRec - i - j];
//
//			Swap(top_left, bot_rigth);
//			Swap(top_right, bot_left);
//			Swap(top_left, top_right);
//			Swap(top_right, bot_rigth);
//			Swap(bot_rigth, bot_left);
//
//			Arr[i][i + j] = top_left;
//			Arr[i + j][minRec - i] = top_right;
//			Arr[minRec - i - j][i] = bot_left;
//			Arr[minRec - i][minRec - i - j] = bot_rigth;
//		}
//
//	}
//	/*End process*/
//
//	/*Print the result*/
//	cout << endl << "Result array:" << endl;
//	for (int i = 0; i < height; i++){
//		for (int j = 0; j < width; j++){
//			cout << Arr[i][j] << "\t";
//		}
//		cout << endl;
//	}
//}