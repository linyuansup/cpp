#include "list_btree.h"
using namespace std;
int main()
{
	tree tree("AB.CE.F..D...");
	tree.convent();
	cout << tree.output();
	return 0;
}