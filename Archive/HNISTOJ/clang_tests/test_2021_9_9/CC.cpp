#include<iostream>
using namespace std;
struct NODE {
	int num = 0;
	struct NODE* next;
	struct NODE* last;
};
typedef struct NODE node;
int main() {
	node* head, * ramhead, * tail, * p;
	int amt,shu,k;
	while (cin>>amt>>shu)
	{
		if (amt <= 1) {
			cout << 1 << endl;
			continue;
		}
		k = 0;
		head = (node*)malloc(sizeof(node));
		ramhead = head;
		head->num = 1;
		for (int i = 2; i <=amt; i++)
		{
			tail = (node*)malloc(sizeof(node));
			head->next = tail;
			tail->last = head;
			tail->num = i;
			head = tail;
		}
		tail->next = ramhead;
		ramhead->last = tail;
		p = ramhead;
		while (1)
		{
			if (p->next == p) {
				cout << p->num << endl;
				free(p);
				break;
			}
			k++;
			if (k % shu == 0) {
				p->last->next = p->next;
				p->next->last = p->last;
				ramhead = p;
				p = p->next;
				free(ramhead);
				k = 0;
			}
			else {
				p = p->next;
			}
		}

	}
	return 0;
}