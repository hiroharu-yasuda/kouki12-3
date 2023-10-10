// kouki2-3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include <iostream>
#include<new>
using namespace std;

void syokika(int size, int* array) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 99 + 1;
	}
}
//降順
void DescendingSort(int size, int* array) {
	int numBox = 0;
	for (int i = 1; i < size; i++) {
		if (array[i - 1] < array[i]) {
			numBox = array[i - 1];
			array[i - 1] = array[i];
			array[i] = numBox;
		}

	}
	//for文のループを減らす
	if (size != 0) {
		size--;
		DescendingSort(size, array);
	}
}
//昇順
void AscendingSort(int size, int* array) {
	int numBox = 0;
	for (int i = 1; i < size; i++) {
		if (array[i - 1] > array[i]) {
			numBox = array[i];
			array[i] = array[i - 1];
			array[i - 1] = numBox;
		}

	}
	//for文のループを減らす

	if (size != 0) {
		size--;
		AscendingSort(size, array);
	}
}

void hyouzi(int size, int* array) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ",";
	}
	cout << endl;
}
int main()
{
	int* array;
	int size = 0, sentaku = 0, sort = 0, end = 0;
	cout << "値の数を入力してください>" << flush;
	cin >> size;
	array = new int[size];
	syokika(size, array);
	cout << "値を初期化しました" << endl;
	while (end != 1)
	{
		cout << "何をしますか？" << endl
			<< "1：値を初期化　2：値をソート　3：表示" << endl;
		do
		{
			cin >> sentaku;

		} while (sentaku <= 0 || sentaku >= 4);

		switch (sentaku)
		{
		case 1:
			syokika(size, array);
			break;
		case 2:
			cout << "どちらにしますか？" << endl
				<< "1:降順  2:昇順" << flush;
			do
			{
				cin >> sort;

			} while (sort <= 0 || sort >= 3);
			if (sort == 1)DescendingSort(size, array);
			else AscendingSort(size, array);
			break;
		case 3:
			hyouzi(size, array);

			cout << "終了しますか？1：終了>" << flush;
			cin >> end;
			break;
		default:
			break;
		}
	}
	if (array != NULL) {
		array = NULL;
	}
	delete[] array;

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
