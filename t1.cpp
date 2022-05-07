#include "list_btree.h"
using namespace std;
int main()
{
	tree tree("ABD.E..FG..H..C..");
	tree.convent();
	cout << tree.output();
	return 0;
}