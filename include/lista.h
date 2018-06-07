#ifndef ARIELSLIB_LIST_H
#define ARIELSLIB_LIST_H

#include <iostream>
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

template<typename T, typename Y>
class Iterator {
	private:
		 T ptr;
	public:
		Iterator(const T &ptr): ptr(ptr) {}
		Iterator() {}
		~Iterator() {}

		inline Iterator& operator= (const Iterator<T, Y> &it) {
			ptr = it.ptr;
			return *this;
		}

		inline bool operator!= (const Iterator<T, Y> &it) {return (it.ptr != ptr) ? true : false;}

		inline Iterator& operator+ (int i) {
				while (ptr->next && i) {
					ptr = ptr->next;
					i--;
				}
			return *this;
		}

		inline Iterator& operator++(int) {
			*this = *this+1;
			return *this;
		}

		inline Iterator& operator--(int) {
			this->ptr = ptr->previous;
			return *this;
		}

		inline Y& operator* () {
			return ptr->data;
		}

		friend ostream& operator<<(ostream &o, Iterator &_i) {
				o << *_i.ptr->data;

				return o;
			}

};

template<typename T>
	class Node {
		public:
			Node(T data): data(data) {}
			Node() {}
			~Node() {}
			T data;
			Node *next;
			Node *previous;
};

template <typename T>
class List {
	private:
		int size;

		void connect(Node<T> *inserted, Node<T> *sentry);
		void findNode(int index, Node<T> *&sentry);

		Node<T> *head;
		Node<T> *tail;
	public:
		typedef Iterator<Node<T>*, T> iterator;

		iterator getBegin() {return iterator(head->next);}
		iterator getEnd() {return iterator(tail);}

		List();
		~List();

		void insertOrdered(T data);

		void insertAtHead(T data);
		void insertAtTail(T data);
		bool insertAt(int index, T data);

		bool removeAtHead();
		bool removeAtTail();
		bool removeAt(int index);

		int getSize();

		T getData(int index);

		void deleteList();
};

template <typename T>
List<T>::List() {
	size = 0;
	head = new Node<T>();
	tail = new Node<T>();

	head->next = tail;
	tail->previous = head;
}
	
template <typename T>		
List<T>::~List() {
	deleteList();
}

template <typename T>
void List<T>::insertOrdered(T data) {
	Node<T> *inserted = new Node<T>(data);

	Node<T> *runner = head;

	bool continua = true;
	while (continua && runner != tail) {
		if (inserted->data > runner->data) {
			cout << "<><><>" << endl;
			runner = runner->next;
		} else {
			continua = false;
		}
	}
}
	
template <typename T>
void List<T>::insertAtHead(T data) {
	Node<T> *inserted = new Node<T>(data);
	inserted->next = NULL;
	inserted->previous = NULL;
	Node<T> *h = this->head;

	h->next->previous = inserted;
	inserted->next = h->next;

	h->next = inserted;
	inserted->previous = h;

	this->size++;
}

template <typename T>
void List<T>::insertAtTail(T data) {
	Node<T> *inserted = new Node<T>(data);
	inserted->next = NULL;
	inserted->previous = NULL;
	Node<T> *t = this->tail;

	t->previous->next = inserted;
	inserted->previous = t->previous;

	t->previous = inserted;
	inserted->next = t;

	this->size++;
}

template <typename T>
bool List<T>::insertAt(int index, T data) {
	if (index > size || index < 0) return false;

	Node<T> *inserted = new Node<T>(data);
	inserted->next = NULL;
	inserted->previous = NULL;
	Node<T> *sentry;

	findNode(index, sentry);
	connect(inserted, sentry);
	size++;

	return true;
}
	
template <typename T>
bool List<T>::removeAtHead() {
	if (head->next == tail) return false;

	Node<T> *tmp = head->next;
	head->next = tmp->next;
	tmp->next->previous = head;
	delete tmp;

	return true;
}
	
template <typename T>
bool List<T>::removeAtTail() {
	if (tail->previous == head) return false;

	Node<T> *tmp = tail->previous;
	tail->previous = tmp->previous;
	tmp->previous->next = tail;
	delete tmp;

	return true;
}

template <typename T>
bool List<T>::removeAt(int index) {
	if (index > size || index < 1) return false;

	Node<T> *sentry;

	findNode(index, sentry);
	Node<T> *tmp = sentry->next;
	tmp->previous = sentry->previous;
	tmp->previous->next = tmp;
	delete sentry;

	return true;
}

template <typename T>
int List<T>::getSize() {return size;}

template <typename T>
T List<T>::getData(int index) {
	Node<T> *sentry;
	if (index <= size || index > 0) {
		findNode(index, sentry);
		return sentry->data;
	} else {
		std::cout << "Impossível encontrar elemento. Posição fora da lista" << std::endl;
	}

	return sentry->data = 0;
}
	
template <typename T>
void List<T>::deleteList() {
	Node<T> *sentry = head->next;
	while (sentry->next) {
		sentry = sentry->next;
		delete sentry->previous;
	}
	delete head;
	delete tail;
}
	
template <typename T>
void List<T>::connect(Node<T> *inserted, Node<T> *sentry) {
	inserted->previous = sentry->previous;
	sentry->previous->next = inserted;
	inserted->next = sentry;
	sentry->previous = inserted;
}

template <typename T>
void List<T>::findNode(int index, Node<T> *&sentry) {
	if (index > size/2) {
		sentry = tail->previous;
		for (int count = size; count > index; count--) {
		sentry = sentry->previous;
		}
	} else {
		sentry = head->next;
		for (int count = size; count < index; count++) {
		sentry = sentry->next;
		}
	}
}

#endif
