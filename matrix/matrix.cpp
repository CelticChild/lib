#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <new>
#include "matrix.h"

Matrix::Matrix(const int& r, const int& c) //constructor
{
	int i;
	row = r;
	col = c;
	array = new double*[row];
	for(i=0; i<row; i++){
		array[i] = new double[col];
		for(int j=0; j<col; j++)
			array[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix& rhs) //copy constructor
{
	row = rhs.row;
	col = rhs.col;
	array = new double*[row];
	for(int i=0; i<row; i++){ 
		array[i] = new double[col];
		for(int j=0; j<col; j++)
			array[i][j] = rhs.array[i][j];
	}
}

Matrix::~Matrix() //destructor
{
	for(int i=0; i<row; i++)
		delete[] array[i];
	delete[] array;
}

double* & Matrix::operator [](const int& idx) const
{
	return array[idx];
}

Matrix Matrix::operator =(const Matrix& rhs){
	int i, j;
	if(this != &rhs){
		if(row == rhs.row && col == rhs.col)
			for(i=0; i<row; i++){
				for(j=0; j<col; j++)
					array[i][j] = rhs.array[i][j];
		}
		else{
			for(i=0; i<row; i++)
				delete[] array[i];
			delete[] array;
			row = rhs.row;
			col = rhs.col;
			array = new double*[row];
			for(i=0; i<row; i++){
				array[i] = new double[col];
				for(int j=0; j<col; j++)
					array[i][j] = rhs.array[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator -() const
{
	Matrix M(*this);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			M.array[i][j] = -M.array[i][j];
	}
	return M;
}

Matrix Matrix::operator +() const
{
	return *this;
}

Matrix Matrix::operator -(const Matrix& rhs) const
{
	Matrix M(*this);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			M.array[i][j] -= rhs.array[i][j];
	}
	return M;
}

Matrix Matrix::operator +(const Matrix& rhs) const
{
	Matrix M(*this);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			M.array[i][j] += rhs.array[i][j];
	}
	return M;
}

Matrix Matrix::operator *(const Matrix& rhs) const
{
	Matrix M(row, rhs.col);
	for(int i=0; i<row; i++)
		for(int j=0; j<rhs.col; j++)
			for(int k=0; k<col; k++)
				M[i][j] += array[i][k] * rhs.array[k][j];
	return M;
}

Matrix Matrix::operator /(const Matrix rhs) const
{
	Matrix N(*this);
	double value=0;
	rhs.inverse();
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			for(int k=0; k<col; k++){
				value += array[i][k] * rhs.array[k][j];
			}
			N.array[i][j] = value;
			value =0;
		}
	}
	return N;
}

Matrix Matrix::inverse() const
{
	Matrix N(*this);
	double mul;
	int i, j, k;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(i==j)
				array[i][j]=1;
			else
				array[i][j]=0;
		}
	}
	for(i=0; i<row; i++){
		for(int m=0; m<row; m++){
			if(m != i){
				if(N.array[i][i]==0){ 
					N.checkZero(i);
				} 
				mul = N.array[m][i] / N.array[i][i];		
				for(int j=0; j<col; j++){
					N.array[m][j] -= N.array[i][j] * mul;
					array[m][j] -= array[i][j] * mul;
				} 
			}
		}
	}
	for(i=0; i<row; i++){
		for(j=0; j<row; j++){
			array[i][j] /= N.array[i][i];
		}
	}
	return *this;
} 

Matrix Matrix::checkZero(int i) const{
	double* tmp = new double[row];
	int ptr=0;
	while(array[ptr][i]==0)
		ptr++;
	for(int j=0; j<row; j++){
		tmp[j] = array[i][j];
		array[i][j] = array[ptr][j];
		array[ptr][j] = tmp[j];
	}
	delete [] tmp;
	return *this;
}

Matrix Matrix::swap(int row1, int row2) const{
	double* tmp = new double[row];
	for(int j=0; j<row; j++){
		tmp[j] = array[row1][j];
		array[row1][j] = array[row2][j];
		array[row2][j] = tmp[j];
	}
	delete [] tmp;
	return *this;
}


void Matrix::read(const char* fn)
{
	int r, c;
	FILE *fp = fopen(fn, "r");
	if(fp == NULL){
		printf("read file [%s] error\n", fn);
		exit(0);
	}
	fscanf(fp, "%d%d", &r, &c);
	Matrix tmp(r, c);
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++)
			fscanf(fp, "%lf", &tmp.array[i][j]);
	fclose(fp);
	*this = tmp;
}

void Matrix::write(const char* fn)
{
	FILE *fp = fopen(fn, "w");
	if(fp == NULL){
		printf("write file [%s] error\n", fn);
		exit(0);
	}
	fprintf(fp, "%d %d\n", row, col);
	for(int i = 0 ; i < row ; i++)
		for(int j = 0 ; j < col ; j++)
			fprintf(fp, "%lf%c", array[i][j], " \n"[j==col-1]);
	fclose(fp);
}

void Matrix::print() const
{
	for(int i = 0 ; i < row ; i++)
		for(int j = 0 ; j < col ; j++)
			printf("%lf%c", array[i][j], " \n"[j==col-1]);
}
