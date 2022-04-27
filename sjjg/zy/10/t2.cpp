#include "order_btree.h"
using namespace std;
int main()
{
	order_btree tree("ABD.E..FG..H..C..");
	cout << tree.get_high() << endl;
	return 0;
}