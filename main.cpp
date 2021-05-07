#include <iostream>
#include <ctime>
#include <iomanip>
#include<conio.h>

/* ejecute este programa usando el pausador de la consola o agregue su propio getch, sistema ("pausa") o bucle de entrada */

using namespace std;

//Prototipos
void mergeSort( int data [], int lenD );
void merge( int merged [], int lenD, int L [], int lenL, int R [], int lenR );
void selectionSort( int data [], int lenD );
void insertionSort( int data [], int lenD );
void bubbleSort( int data [], int lenD );
void mergeSort( int data [], int lenD ) {
	if (lenD > 1) {
		int middle = lenD / 2;
		int rem = lenD - middle;
		int* L = new int [ middle ];
		int* R = new int [ rem ];
		
		for ( int i = 0; i < lenD; i++) {
			if (i < middle) {
				L [ i ] = data [ i ]; 
			} else {
				R [ i - middle ] = data [ i ];
			}
		}
		
		mergeSort ( L, middle );
		mergeSort ( R, rem );
		merge ( data, lenD, L, middle, R, rem);
	}
}

void merge ( int merged [], int lenD, int L [], int lenL, int R [], int lenR) {
	int i = 0;
	int j = 0;
	while ( i < lenL || j < lenR ) {
		if ( i < lenL && j < lenR ) {
			if( L [ i ] <= R [ j ]) {
				merged [ i + j ] = L [ i ];
				i++;
			} else {
				merged [ i + j ] = R [ j ];
				j++;
			}
		} else if ( i < lenL ) {
			merged [ i + j ] = L [ i ];
			i++;
		} else if ( j < lenR ) {
			merged [ i+j ] = R [ j ];
			j++;
		}
	}
}

void selectionSort ( int data [], int lenD ) {
	int j = 0;
	int tmp = 0;
	for ( int i = 0; i < lenD; i++ ) {
		j = i;
		for ( int k = i; k < lenD; k++ ) {
			if ( data [ j ] > data [ k ] ) {
				j = k;
			}
		}
		tmp = data [ i ];
		data [ i ] = data [ j ];
		data [ j ] = tmp;
	}
}

void insertionSort ( int data [], int lenD ) {
	int key = 0;
	int i = 0;
	for ( int j = 1; j < lenD; j++ ) {
		key = data [ j ];
		i = j - 1;
		while ( i >= 0 && data [ i ] > key ) {
			data [ i + 1 ] = data [ i ];
			i = i - 1;
			data [ i + 1 ] = key;
		}
	}
}

void bubbleSort ( int data [], int lenD ) {
	int tmp = 0;
	for ( int i = 0; i < lenD; i++ ) {
		for ( int j = ( lenD - 1 ); j >= ( i + 1 ); j-- ) {
			if ( data [ j ] < data [ j - 1 ] ) {
				tmp = data [ j ];
				data [ j ] = data [ j - 1 ];
				data [ j - 1 ] = tmp;
			}
		}
	}
}

int main(int argc, char** argv) {
	int i = 0;
	int n ;

//	n = 5000;

	
	clock_t start;
	cout<<"+-----------------------------------------+\n";
	cout<<"|      Tiempo de Ordenamientos        	  |\n";//Titulo tema
	cout<<"+-----------------------------------------+\n";
	cout << "Inserte el valor a comparar: ";
	cin >> n;
	cout << "Insertion Sort" << endl; //Inicia Insertion Sort
	cout << "Numero de valores : " << " | " << "Tiempo de Execucion : " << endl;
	cout << "_________________" << endl;
	while ( i < 1 ) {
		int w = 1000;
		int a [ n ];
		for ( int q = 0; q < n; q++ ) { // Worst case is reserve case
			a [ q ] = w;
			w--;
		}
		start = clock();
		insertionSort ( a, n );
		start = clock() - start;
		
		cout << n   << setw(35) << (double)start / (double)CLOCKS_PER_SEC * 1000.0 << " ms " << endl;
		
	//	n = n * 5
		i++;
	}
	
	i = 0;
	
	cout << "_________________" << endl;
	cout << "Selection Sort" << endl; //Start Selection Sort
	cout << "Numero de valores : " << " | " << "Tiempo de Execucion : " << endl;
	cout << "_________________" << endl;
	while ( i < 1 ) {
		int w = 1000;
		int a [ n ];
		for ( int q = 0; q < n; q++ ) { // Worst case is sorted
			a [ q ] = w;
			w++;
		}
		start = clock();
		selectionSort ( a, n );
		start = clock() - start;
		
		cout << n << setw(35) << (double)start / (double)CLOCKS_PER_SEC * 1000.0 << " ms " << endl;
//		n = n * 10;
		i++;
	}

	i = 0;
//	n = 1000;
	
	cout << "_________________" << endl;
	cout << "Bubble Sort" << endl; 
	cout << "Numero de valores : " << " | " << "Tiempo de Execucion : " << endl;
	cout << "_________________" << endl;
	while ( i < 1 ) {
		int w = 1000;
		int a [ n ];
		for ( int q = 0; q < n; q++ ) { 
			a [ q ] = w;
			w--;
		}
		start = clock();
		bubbleSort ( a, n );
		start = clock() - start;
		
		cout << n << setw(35) << (double)start / (double)CLOCKS_PER_SEC * 1000.0 << " ms " << endl;
//		n = n * 5;
		i++;
	}
	
	i = 0;
	
	cout << "_________________" << endl;
	cout << "Merge Sort" << endl;
	cout << "Numero de valores : " << " | " << "Tiempo de Execucion : " << endl;
	cout << "_________________" << endl;
	while ( i < 1 ) {
		int w = 1000;
		int a [ n ];
		for ( int q = 0; q < n; q++ ) { 
			a [ q ] = w;
			w++;
		}
		start = clock();
		mergeSort ( a, n );
		start = clock() - start;
		
		cout << n << setw(35) << (double)start / (double)CLOCKS_PER_SEC * 1000.0 << " ms " << endl;
		i++;
	}
	
	system ("pause");
	return 0;
}
