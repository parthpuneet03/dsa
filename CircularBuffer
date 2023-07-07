#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <xstring>
#include<iostream>
using namespace std;

class CircularBuffer {
private:
	int* m_item, m_size, m_front, m_rear, m_filled;
public:
	CircularBuffer(int s) {
		m_front = -1;
		m_rear = -1;
		m_size = s;
		m_item = new int[s];
	}

	bool isFull(){
		if (m_front == 0 && m_rear == m_size - 1) {
			return true;
		}
		if ((m_rear + 1)%(m_size-1) == m_front) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isEmpty() {
		if (m_front == m_rear == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void enQueue(int val);
	int deQueue();
};
void CircularBuffer::enQueue(int val) {
	
	if (isFull) {
		cout << "\nQueue is Full";
	}
	
	//inserting first element
	else {

		if (m_front == -1) m_front = 0;
		m_rear = (m_rear + 1) % m_size;
		m_item[m_rear] = val;
		m_filled++;
		cout << "inserted value = " << val<<endl;
	}
}
int CircularBuffer::deQueue() {
	int El=-1;
	if (isEmpty()) {
		printf("\nQueue is Empty");
		return El;
	}
	else {
		El = m_item[m_front];
		m_filled--;
		if (m_front == m_rear) {
			m_front = -1;
			m_rear = -1;
		}
		else {
			m_front = (m_front + 1) % m_size;
		}
		return El;
	}
}
