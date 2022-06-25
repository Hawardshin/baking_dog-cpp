#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
	int tmp;
	tmp = nxt[addr];
	dat[unused] = num;
	nxt[addr] = unused;//전 노드 nxt
	nxt[unused] = tmp;//현재노드 nxt
	pre[unused] = addr; //현재노드 pre
	pre[tmp] = unused; // 다음노드 pre
	unused++;
}

//addr 은 배열상에서 몇번째인지 나타낸다.

void erase(int addr){
//	cout << "delete : data:::: " << dat[addr] << "\n";
//	cout << pre[addr] << "pre[addr]\n";
//	cout << nxt[addr] << "nxt[addr]\n";
//	cout << nxt[pre[addr]]  << "nxt[pre[addr]] \n";
//	cout << pre[nxt[addr]] << "pre[nxt[addr]] \n";
	nxt[pre[addr]] = nxt[addr];
	pre[nxt[addr]] = pre[addr];
//	cout << nxt[pre[addr]]  << "nxt[pre[addr]] \n";
//	cout << pre[nxt[addr]] << "pre[nxt[addr]] \n";
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}
