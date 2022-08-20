/*
---------------------------------------------
Developer:	Armas Emilio
Date:		13/08/2022
Subject:	Proyecto 2B
			Calculadora de Matrices
---------------------------------------------

*/
#include <iostream>
#include "..\lib\utility.h"

using namespace std;

void header();
void init();
int menu();
int inputA(int i, int j);
int inputB(int i, int j);
bool checkSum();
void subtract();
void matrixProduct();
void dotProduct();
void determinant();
void showMatrix();

int m1, m2, n1, n2;

int main()
{

	header();
	
	ingresar:
	init();

	int A[m1][n1];
	int B[m2][n2];


	cout<<"Ingrese los valores de las matrices: "<<endl;

	for (int i = 0; i<m1; i++)
		for (int j = 0; j<n1; j++)
		{
			A[i][j] = inputA(i, j);
		}

	cout<<endl;

	for (int i = 0; i<m2; i++)
		for (int j = 0; j<n2; j++)
		{
			B[i][j] = inputB(i, j);
		}

	cout<<"A  = "<<'\t';
	for (int i = 0; i<m1; i++){
		for (int j = 0; j<n1; j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl<<'\t';
	}

	cout<<endl;

	cout<<"B  = "<<'\t';
	for (int i = 0; i<m2; i++){
		for (int j = 0; j<n2; j++)
		{
			cout<<B[i][j]<<" ";
		}
		cout<<endl<<'\t';
	}
	cout<<endl;
	
	do
	{
	switch(menu())
	{
		case SUM:
			if(checkSum()){
				int C[m1][n1];
				for(int i = 0; i<m1; i++)
					for (int j = 0; j<n1; j++)
					{
						C[i][j] = A[i][j]+B[i][j];
					}

				cout<<"La suma de las matrices es: "<<endl<<endl;
				cout<<"C  = "<<'\t';
				for (int i = 0; i<m1; i++){
					for (int j = 0; j<n1; j++)
					{
						cout<<C[i][j]<<" ";
					}
					cout<<endl<<'\t';
				}
			}
			else
				cout<<"No se puede realizar suma entre matrices de diferente orden."<<endl;
			break;

		case SUBT:
			if(checkSum()){
				int C[m1][n1];
				for(int i = 0; i<m1; i++)
					for (int j = 0; j<n1; j++)
					{
						C[i][j] = A[i][j]-B[i][j];
					}

				cout<<"La resta de las matrices es: "<<endl<<endl;
				cout<<"C  = "<<'\t';
				for (int i = 0; i<m1; i++){
					for (int j = 0; j<n1; j++)
					{
						cout<<C[i][j]<<" ";
					}
					cout<<endl<<'\t';
				}
			}
			else
				cout<<"No se puede realizar resta entre matrices de diferente orden."<<endl;
			break;

		case PROD:
			break;

		case DOT_PROD:
			break;

		case REINPUT:
			goto ingresar;
			break;

		case EXIT:
			exit(EXIT_SUCCESS);
			break;

	}
	}while (true);

	
	return 0;
}

int menu()
{
	string in;
	int opt;
	cout<<"Ingresa una opcion:"<<endl<<endl
		<<SUM<<". Suma de matrices (A + B)"<<endl
		<<SUBT<<". Resta de matrices (A - B)"<<endl
		<<PROD<<". Producto de Matrices (A * B)"<<endl
		<<DETER<<". Determinante (det(A))"<<endl
		<<DOT_PROD<<". Producto Interno casual (Tr(A*B^T))"<<endl
		<<REINPUT<<". Reingresar matrices"<<endl
		<<EXIT<<". Salir"<<endl<<endl;
	cout<<"Opcion: "; getline(cin, in);
	fflush(stdin);

	if(in != "" && validarInt(in))
		opt = stoi(in);

	while(opt<0 || opt>6 || !validarInt(in) || in == ""){
		cout<<"Opcion no valida, ingrese la opcion nuevamente"<<endl;
		cout<<"Opcion: "; getline(cin, in);
		if(in != "" && validarInt(in))
			opt = stoi(in);
		fflush(stdin);
	}

	return opt;
}

void header()
{
	
}


void init()
{	
	string rows, columns;
	cout<<"Ingrese el numero de filas y columnas de la matriz A:"<<endl;
	cout<<"Filas de A: "; getline(cin, rows);
	
	if(rows!="" && validarInt(rows))
		m1 = stoi(rows);

	while(m1<1 || m1 >10 || !validarInt(rows) || rows == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Filas de A: "; getline(cin, rows);
		if(rows!="" && validarInt(rows))
			m1 = stoi(rows);
		fflush(stdin);
	}

	cout<<"Columnas de A: "; getline(cin, columns);
	
	if(columns!="" && validarInt(columns))
		n1 = stoi(columns);

	while(n1<1 || n1 >10 || !validarInt(columns) || columns == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Columnas de A: "; getline(cin, columns);
		if(columns!="" && validarInt(columns))
			n1 = stoi(columns);
		fflush(stdin);
	}
	
	cout<<"Ingrese el numero de filas y columnas de la matriz B:"<<endl;
	cout<<"Filas de B: "; getline(cin, rows);
	
	if(rows!="" && validarInt(rows))
		m2 = stoi(rows);

	while(m2<1 || m2 >10 || !validarInt(rows) || rows == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Filas de B: "; getline(cin, rows);
		if(rows!="" && validarInt(rows))
			m2 = stoi(rows);
		fflush(stdin);
	}

	cout<<"Columnas de B: "; getline(cin, columns);
	
	if(columns!="" && validarInt(columns))
		n2 = stoi(columns);

	while(n2<1 || n2 >10 || !validarInt(columns) || columns == ""){
		cout<<"Opcion no valida, ingrese un numero valido nuevamente"<<endl;
		cout<<"Columnas de A: "; getline(cin, columns);
		if(columns!="" && validarInt(columns))
			n2 = stoi(columns);
		fflush(stdin);
	}
}

int inputA(int i, int j){

	int val;
	string input;
	
	cout<<"Ingrese el numero A["<<i+1<<"]["<<j+1<<"]: ";
	getline(cin, input);

	if(input!="" && validarInt(input))
		val = stoi(input);

	while(!validarInt(input) || input == ""){
		cout<<"Opcion no valida, ingrese un numero valido"<<endl;
		cout<<"Ingrese el numero A["<<i+1<<"]["<<j+1<<"]: "; getline(cin, input);
		if(input!="" && validarInt(input))
			val = stoi(input);
		fflush(stdin);
	}

	return val;
}

int inputB(int i, int j){

	int val;
	string input;
	
	cout<<"Ingrese el numero B["<<i+1<<"]["<<j+1<<"]: ";
	getline(cin, input);

	if(input!="" && validarInt(input))
		val = stoi(input);

	while(!validarInt(input) || input == ""){
		cout<<"Opcion no valida, ingrese un numero valido"<<endl;
		cout<<"Ingrese el numero A["<<i+1<<"]["<<j+1<<"]: "; getline(cin, input);
		if(input!="" && validarInt(input))
			val = stoi(input);
		fflush(stdin);
	}

	return val;
}

bool checkSum()
{
	if(m1 == m2 && n1 == n2)
		return true;
	else
		return false;
}


void showMatrix();