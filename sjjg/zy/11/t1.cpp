#include "tree.h"
int main()
{
	tree tree("A.BCD.EF.G.HIJ.K......"); // 就是 ppt 上那棵树
	cout << tree.get_high_a() << endl << tree.get_high_b() << endl;
	tree.add_tree("L");
	tree.add_tree("M.N."); // 就是 ppt 上那颗森林
	cout << tree.get_high_a() << endl << tree.get_high_b() << endl;
	return 0;
}