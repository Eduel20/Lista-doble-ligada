#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <iostream>

using namespace std;

template <class T>
class listadoble{
	
	struct Nodo{
		T dato;
		Nodo *sig;
		Nodo *ant;
		
		Nodo(const T &dato, Nodo *sig = nullptr, Nodo *ant = nullptr)
		:dato(dato), sig(sig), ant(ant){
		}
	};
	
	Nodo *head;
	Nodo *tail;
	size_t cont;
	
public: 
	listadoble();
	~listadoble();
	
	bool empty();
	
	void pushfront(const T &dato);
	void pushback(const T &dato);
	
	size_t size();
	
	void print();
	void printreverse();
	
	T* front();
	T* back();
	
	T* find(const T &dato);
	
	listadoble &operator<<(const T &dato){
		pushback(dato);
		
		return *this;
	}
	
};


template <class T>
listadoble<T>::listadoble(){
	cont = 0;
	head = nullptr;
	tail = nullptr;
}


template <class T>
listadoble<T>::~listadoble(){
	
}


template <class T>
bool listadoble<T>::empty(){
	return cont == 0;
}


template <class T>
void listadoble<T>::pushfront(const T &dato){
	Nodo *nodo = new Nodo(dato, head);
	if(cont == 0){
		head = nodo;
		tail = nodo;
	} else {
		head-> ant =nodo;
		head = nodo;
	}
	cont++;
}


template <class T>
void listadoble<T>::pushback(const T &dato){
	Nodo *nodo = new Nodo(dato, nullptr, tail);
	if(cont == 0){
		head = nodo;
		tail = nodo;
	}else{
		tail->sig = nodo;
		tail = nodo;
	}
	cont++;
}


template <class T>
size_t listadoble<T>::size(){
	return cont;
}


template <class T>
void listadoble<T>::print(){
	Nodo *temp = head;
	while (temp != nullptr){
		cout << temp -> dato << endl;
		temp = temp->sig;
	}
}


template <class T>
void listadoble<T>::printreverse(){
	Nodo *temp = tail;
	while (temp != nullptr){
		cout << temp -> dato << endl;
		temp = temp->ant;
	}
}


template <class T>
T* listadoble<T>::front(){
	if(empty()){
		return nullptr;
	}else{
		return &head->dato;
	}
}


template <class T>
T* listadoble<T>::back(){
	if(empty()){
		return nullptr;
	}else{
		return &tail->dato;
	}
}


template <class T>
T* listadoble<T>::find(const T &dato){
	Nodo *temp = head;
	while (temp != nullptr){
		if(temp->dato == dato){
			return &temp->dato;
		}
		temp = temp->sig;
	}
	return nullptr;
}










#endif
