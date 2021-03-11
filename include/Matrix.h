#pragma once

#include <iostream>
#include <iomanip>
#include <string>

template<class T>
class Matrix {
private:
	T* v_;
	int rows_;
	int cols_;

public:
	Matrix (int rows);
	Matrix (int rows, int cols);

	~Matrix ();

	T& at (int i, int j);
	T at (int i, int j) const;

	T& operator() (int i, int j);
	T operator() (int i, int j) const;

	int rows () const;
	int cols () const;

	void write (std::ostream& os = std::cout) const;

private:
	int pos (int i, int j) const;

	void create_matrix ();
	void destroy_matrix ();
};

template<class T>
Matrix<T>::Matrix (int rows) {
	rows_ = rows;
	cols_ = rows;
	create_matrix();
}

template<class T>
Matrix<T>::Matrix (int rows, int cols) {
	rows_ = rows;
	cols_ = cols;
	create_matrix();
}

template <class T>
Matrix<T>::~Matrix () {
	destroy_matrix();
}

template <class T>
T& Matrix<T>::at (int i, int j) {
	return v_[pos(i, j)];
}

template <class T>
T Matrix<T>::at (int i, int j) const {
	return v_[pos(i, j)];
}

template <class T>
T& Matrix<T>::operator() (int i, int j) {
	return at(i, j);
}

template <class T>
T Matrix<T>::operator() (int i, int j) const {
	return at(i, j);
}

template <class T>
int Matrix<T>::rows () const {
	return rows_;
}

template <class T>
int Matrix<T>::cols () const {
	return cols_;
}

template <class T>
void Matrix<T>::write (std::ostream& os) const {
	for (int i = 0; i < rows_; i++) {
		os << "|";
		for (int j = 0; j < cols_; j++) {
			os << at(i, j);
			os << "|";
		}
		os << '\n';
	}
}

// Private methods

template<class T>
int Matrix<T>::pos (int i, int j) const {
	return i * cols_ + j;
}

template<class T>
void Matrix<T>::create_matrix () {
	v_ = new T [rows_ * cols_];
}

template<class T>
void Matrix<T>::destroy_matrix () {
	delete [] v_;
}