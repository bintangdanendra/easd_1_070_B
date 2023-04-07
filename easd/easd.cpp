// 1. Karena dengan menggunakan Algoritma akan mempermudah seseorang dalam mengidentifikasi dan juga menyelesaikan masalah
// 2. Data structur dibagi menjadi 2 yaitu data structur quadratic dan juga data structur loglinear
// 3. Tingkat kesulitan program,bahasa yang digunakan, mudah digunakan, dan juga kesimpelan sebuah program
// 4. Selection sort yang dimana berfungsi untuk mengseleksi data dari yang terkecil hingga terbesar sehingga mempercepat pengurutan data
// 5. Contoh Algoritma yang masuk ke dalam quadratic yaitu bubblesort, insertionsort, selectionsort sedangkan yang masuk loglinear yaitu quicksort, mergesort, dan countingsort
// 6. Membuat program 

#include <iostream>
using namespace std;

int bin[90];
int cmp_count;
int mov_count;
int n;

void input() {
	while (true)
	{
		cout << "Masukkan Panjang Element Array :";
		cin >> n;

		if (n <= 90)
			break;
		else
			cout << "\nMasukkan Panjang Array adalah 90" << endl;

	} 
	cout << "\n--------------------------" << endl;
	cout << "\nMasukkan Element Array" << endl;
	cout << "\n--------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> bin[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = bin[x];
	bin[x] = bin[y];
	bin[y] = temp;
}
void q_short(int low, int high)
{
	int pivot, i, brtd;
	if (low > high)
		return;

	pivot = bin[low];

	i = low + 1;
	brtd = high;

	while (i <= brtd)
	{

		while ((bin[i] <= pivot) && (i <= high))
		{
			i++;
			cmp_count++;
		}
		cmp_count++;

		while ((bin[brtd] > pivot) && (brtd >= low))
		{
			brtd--;
			cmp_count++;
		}
		cmp_count;

		if (i < brtd)
		{
			swap(i, brtd);
			mov_count++;
		}
	}

	if (low < brtd)
	{
		swap(low, brtd);
		mov_count++;
	}

	q_short(low, brtd - 1);

	q_short(brtd + 1, high);

}

void display() {
	cout << "\n-----------------" << endl;
	cout << "\nSorted Array" << endl;
	cout << "\n-----------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << bin[i] << " ";
	}

	cout << "\n\nBanyaknya Perbandingan :" << cmp_count << endl;
	cout << "Jumlah Perpindahan Data :" << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}