#include "queue.h"

int main(){
	queue<int> z;
	z.enqueue(1);
	z.enqueue(2);
	cout << z.front() << endl;
	//z.dequeue();
	cout << z.front() << endl;
	queue<int> z1 = z;
	cout << z1.front() << endl;
}
