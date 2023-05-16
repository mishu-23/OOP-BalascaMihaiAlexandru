#include <iostream>
using namespace std;
template<class T>
void QuickSort(T v[], int st, int dr)
{
	int  poz, i, j, mij;
	T pivot;
	if (st < dr)
	{
		mij = st + dr / 2;
		cout << st << ' ' << mij << ' ' << dr << endl; //m-a ajutat la (4)
		//(5) verifica cu pivot in stanga in loc de dreapta si de la jumatate incolo erau ordonate invers numerele
		//pivot = v[st]; 
		pivot = v[dr];
		poz = st - 1;

		//(1) asta era in plus
		//swap(st, mij);

		for (j = st; j < dr; j++) //(2) era j<=dr dar pozitia dr nu exista
			if (v[j] < pivot)
			{
				poz++;
				//(3) swap(v[st], v[j]);
				cout << "swap " << v[poz] << ' ' << v[j] << endl;
				swap(v[poz], v[j]);
			}
		swap(v[poz + 1], v[dr]);
		poz = poz + 1;

	}
	if (st < dr)
	{
		for (int i = 0; i <= 4; i++)
			cout << v[i] << ' ';
		cout << endl;
		QuickSort(v, st, poz - 1); //(4) am pus poz - 1 pentru ca am vazut ca imi lua dreapta cu o pozitie mai mult 
		QuickSort(v, poz + 1, dr);
	}

}
int main() {
	//int v[5] = { 5, 1, 1, 1, 1}; //test ca sa vad pana unde ajunge 5-ul. am observat ca se muta doar odata si am vazut ca in codul meu am swap(v[st], v[j]) in loc de swap(v[poz], v[j])
	int v[5] = { 4, 3, 6, 2, 7}; //verific pentru un sir oarecare si afiseaza initial 7, 2, 3, 6, 4
	QuickSort(v, 0, 4);
	for (int i = 0; i <= 4; i++)
		cout << v[i] << ' ';
	return 0;
}