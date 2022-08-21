/*
---------------------------------------------
Developer:	Armas Emilio
Date:		13/08/2022
Subject:	Proyecto 2B
			Calculadora de Matrices
---------------------------------------------

*/
#include <iostream>
#include <conio.h>
#include "..\lib\utility.h"

using namespace std;

void header();
void headerMatrix();
void initMatrix();
int menu();
float inputA(int i, int j);
float inputB(int i, int j);
bool checkSqr(int i, int j);
void showMatrix(float M[][10], int m, int n);
void sum();
void subt1();
void subt2();
void prod1();
void prod2();
void dotProd();
void farewell();
void intro();

int m1, m2, n1, n2;

float A[10][10];
float B[10][10];
float C[10][10];

int main()
{
	system("cls");

	ingresar:
	system("cls");
	header();
	initMatrix();

	cout<<"Ingrese los valores de las matrices: "<<endl<<endl;

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
	showMatrix(A,m1,n1);

	cout<<endl;

	cout<<"B  = "<<'\t';
	showMatrix(B,m2,n2);
	
	do
	{
		system("cls");
		header();
		headerMatrix();
		switch(menu())
		{
			case SUM:
				system("cls");
				header();
				headerMatrix();
				sum();
				cout<<"Presione cualquier tecla para continuar..."; getch();
				system("cls");
				break;

			case SUBT1:
				system("cls");
				header();
				headerMatrix();
				subt1();
				cout<<"Presione cualquier tecla para continuar..."; getch();
				system("cls");
				break;

			case SUBT2:
				system("cls");
				header();
				headerMatrix();
				subt2();
				cout<<"Presione cualquier tecla para continuar..."; getch();
				system("cls");
				break;

			case PROD1:
				system("cls");
				header();
				headerMatrix();
				prod1();
				cout<<"Presione cualquier tecla para continuar..."; getch();
				system("cls");
				break;

			case PROD2:
				system("cls");
				header();
				headerMatrix();
				prod2();
				cout<<"Presione cualquier tecla para continuar..."; getch();
				system("cls");
				break;

			case DOT_PROD:
				system("cls");
				header();
				headerMatrix();
				dotProd();
				cout<<"Presione cualquier tecla para continuar..."; getch();
				system("cls");
				break;

			case REINPUT:
				system("cls");
				goto ingresar;
				break;

			case EXIT:
				system("cls");
				header();
				cout<<"Presione cualquier tecla para salir..."; getch();
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
		<<SUM<<". Suma de matrices (A+B)"<<endl
		<<SUBT1<<". Resta de matrices (A-B)"<<endl
		<<SUBT2<<". Resta de matrices (B-A)"<<endl
		<<PROD1<<". Producto de matrices (A*B)"<<endl
		<<PROD2<<". Producto de matrices (B*A)"<<endl
		<<DOT_PROD<<". Producto interno usual (Tr(A*B^T))"<<endl
		<<REINPUT<<". Reingresar matrices"<<endl
		<<EXIT<<". Salir"<<endl<<endl;
	cout<<"Opcion: "; getline(cin, in);
	fflush(stdin);

	if(in != "" && validarInt(in))
		opt = stoi(in);

	while(opt<0 || opt>REINPUT || !validarInt(in) || in == ""){
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
	cout<<"--------------------- CALCULADORA DE MATRICES --------------------"<<endl
		<<"|   Instrucciones:                                               |"<<endl
		<<"|    > Ingresa el orden y los elementos de las matrices.         |"<<endl
		<<"|    > Selecciona la opcion de que desees.                       |"<<endl
		<<"|    > De ser posible, se realizara la operacion.                |"<<endl
		<<"|    > Se pueden ingresar decimales y numeros negativos.         |"<<endl
		<<"|                                                                |"<<endl
		<<"------------------------------------------------------------------"<<endl<<endl;
}

void headerMatrix()
{
	
	cout<<"\nMatrices: "<<endl<<endl;
	
	cout<<"A  = "<<'\t';
	showMatrix(A,m1,n1);

	cout<<endl;

	cout<<"B  = "<<'\t';
	showMatrix(B,m2,n2);

	cout<<endl<<endl;

}

void initMatrix()
{	
	string rows, columns;
	cout<<"\nIngrese el numero de filas y columnas de la matriz A:"<<endl;
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
	
	cout<<"\nIngrese el numero de filas y columnas de la matriz B:"<<endl;
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
		cout<<"Columnas de B: "; getline(cin, columns);
		if(columns!="" && validarInt(columns))
			n2 = stoi(columns);
		fflush(stdin);
	}
	cout<<endl<<endl;
}

float inputA(int i, int j){
	float val;
	string input;
	
	cout<<"Ingrese el numero A["<<i+1<<"]["<<j+1<<"]: ";
	getline(cin, input);

	if(input!="" && validarNum(input))
		val = stof(input);

	while(!validarNum(input) || input == ""){
		cout<<"Opcion no valida, ingrese un numero valido"<<endl;
		cout<<"Ingrese el numero A["<<i+1<<"]["<<j+1<<"]: "; getline(cin, input);
		if(input!="" && validarNum(input))
			val = stof(input);
		fflush(stdin);
	}

	return val;
}

float inputB(int i, int j){

	float val;
	string input;
	
	cout<<"Ingrese el numero B["<<i+1<<"]["<<j+1<<"]: ";
	getline(cin, input);

	if(input!="" && validarNum(input))
		val = stof(input);

	while(!validarNum(input) || input == ""){
		cout<<"Opcion no valida, ingrese un numero valido"<<endl;
		cout<<"Ingrese el numero B["<<i+1<<"]["<<j+1<<"]: "; getline(cin, input);
		if(input!="" && validarNum(input))
			val = stof(input);
		fflush(stdin);
	}

	return val;
}

void showMatrix(float M[][10], int m, int n)
{
	for (int i = 0; i<m; i++){
			for (int j = 0; j<n; j++)
			{
				cout<<M[i][j]<<"\t";
			}
			cout<<endl<<'\t';
		}
		cout<<endl;
}

void sum()
{
	cout<<"SUMA DE MATRICES"<<endl<<endl;
	if(m1 == m2 && n1 == n2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n1; j++)
				C[i][j] = A[i][j]+B[i][j];

		cout<<"La suma de las matrices A y B es la matriz C de orden "<<m1<<"x"<<n1<<": "<<endl<<endl;
		cout<<"C  = "<<'\t';
		showMatrix(C,m1,n1);
		cout<<endl;
	}
	else
		cout<<"No se puede realizar suma entre matrices de diferente orden."<<endl<<endl;
}

void subt1()
{
	cout<<"RESTA DE MATRICES"<<endl<<endl;
	if(m1 == m2 && n1 == n2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n1; j++)
				C[i][j] = A[i][j]-B[i][j];

		cout<<"La resta de las matrices A y B es la matriz C de orden "<<m1<<"x"<<n1<<": "<<endl<<endl;
		cout<<"C  = "<<'\t';
		showMatrix(C,m1,n1);
		cout<<endl;
	}
	else
		cout<<"No se puede realizar resta entre matrices de diferente orden."<<endl<<endl;
}

void subt2()
{
	cout<<"RESTA DE MATRICES"<<endl<<endl;
	if(m1 == m2 && n1 == n2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n1; j++)
				C[i][j] = B[i][j]-A[i][j];

		cout<<"La resta de las matrices B y A es la matriz C de orden "<<m1<<"x"<<n1<<": "<<endl<<endl;
		cout<<"C  = "<<'\t';
		showMatrix(C,m1,n1);
		cout<<endl;
	}
	else
		cout<<"No se puede realizar resta entre matrices de diferente orden."<<endl<<endl;
}

void prod1()
{
	cout<<"MULTIPLICACION DE MATRICES"<<endl<<endl;
	if(n1 == m2)
	{
		for(int i = 0; i<m1; i++)
			for (int j = 0; j<n2; j++)
			{	
				C[i][j] = 0;

				for(int k = 0; k<n1; k++)
					C[i][j] += A[i][k]*B[k][j];
			}

		cout<<"El producto (A*B) de las matrices es la matriz C de orden "<<m1<<"x"<<n2<<": "<<endl<<endl;
		cout<<"C  = "<<'\t';
		showMatrix(C,m1,n2);
		cout<<endl;
	}
	else
		cout<<"No se puede realizar el producto entre estas matrices por su orden."<<endl
			<<"El numero de columnas de A debe ser igual al numero de filas de B."<<endl<<endl;

}

void prod2()
{
	cout<<"MULTIPLICACION DE MATRICES"<<endl<<endl;
	if(n2 == m1)
	{
		for(int i = 0; i<m2; i++)
			for (int j = 0; j<n1; j++)
			{	
				C[i][j] = 0;

				for(int k = 0; k<n2; k++)
					C[i][j] += B[i][k]*A[k][j];
			}

		cout<<"El producto (B*A) de las matrices es la matriz C de orden "<<m2<<"x"<<n1<<": "<<endl<<endl;
		cout<<"C  = "<<'\t';
		showMatrix(C,m2,n1);
		cout<<endl;
	}
	else
		cout<<"No se puede realizar el producto entre estas matrices por su orden."<<endl
			<<"El numero de columnas de A debe ser igual al numero de filas de B."<<endl<<endl;

}

void dotProd()
{
	cout<<"PRODUCTO INTERNO USUAL DE MATRICES"<<endl<<endl;
	if(m1 == m2 && n1 == n2)
	{
		float trace = 0;
		for(int i = 0; i<m1; i++)
		{	
			C[i][i] = 0;

			for(int k = 0; k<n1; k++)
				C[i][i] += A[i][k]*B[i][k];
		}

		for(int i = 0; i<m1; i++)
				trace += C[i][i];

		cout<<"El producto interno usual de las matrices A y B es: "<<endl
			<<trace<<endl;
	}	
	else
		cout<<"No se puede realizar el producto interno usual entre las matrices por su orden."<<endl
			<<"La matriz resultante de A*B^T debe ser cuadrada para obtener su traza."<<endl<<endl;
	
	cout<<endl;
}
