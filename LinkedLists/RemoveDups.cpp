#include <iostream>
#include <unordered_set>
using namespace std;

template <class T>
struct Node {
	T data;
	Node<T> *next;

	Node(T data) {
		this->data = data;
		next = NULL;
	}

	void appendToTail(T data) {
		Node<T> n(data);
		Node<T> *iter = this;
		while (iter->next != NULL) 
			iter = iter->next;
		iter->next = &n;
	}
};

template <class T>
void removeNode(Node<T> &n) {
	Node<T> *tmp = n.next;
	if (tmp != NULL) {
		n.data = tmp->data;
		n.next = tmp->next;
		delete tmp;
	} else {
		n = NULL;
	}
}

template <class T>
void removeDups(Node<T> n) {
	Node<T> *iter = &n;
	unordered_set<T> hst;
	while (iter != NULL) {
		if (hst.find(iter->data) == hst.end())
			removeNode<T>(*iter);
		else {
			hst.insert(iter->data);
			iter = iter->next;
		}
	}
}

int main() {
	Node<int> linkedList(15);
	linkedList.appendToTail(2);
	linkedList.appendToTail(3);
	linkedList.appendToTail(6);
	linkedList.appendToTail(2);
	linkedList.appendToTail(12);
	linkedList.appendToTail(1);
	linkedList.appendToTail(0);
	linkedList.appendToTail(12);
	linkedList.appendToTail(2);
	linkedList.appendToTail(7);
	linkedList.appendToTail(15);
	Node<int> *tmp = &linkedList;
	cout << tmp << endl;

	while (tmp != NULL) {
		cout << "happended" << endl;
		cout << tmp->data << " -> ";
		tmp = tmp->next;
	}
	// removeDups<int>(linkedList);
	tmp = &linkedList;
	while (tmp != NULL) {
		cout << tmp->data << " -> ";
		tmp = tmp->next;
	}
}

