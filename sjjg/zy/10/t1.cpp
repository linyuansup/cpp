#include "list_btree.h"
using namespace std;
int main()
{
	list_btree tree("ABD.E..FG..H..C..");
	cout << tree.get_high_a() << endl << tree.get_high_b();
	return 0;
}