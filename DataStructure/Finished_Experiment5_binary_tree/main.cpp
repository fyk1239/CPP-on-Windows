#include "binary_tree.h" // 二叉树类
#include "utility.h"	 // 实用程序软件包

int main()
{
	try // 用try封装可能出现异常的代码
	{
		BinTreeNode<int> *cur, *c, *f;
		cur = new BinTreeNode<int>(2);

		BinaryTree<int> bt(2); // 建立二叉树
		cur = bt.GetRoot();
		bt.InsertLeftChild(cur, 3);	 // 插入左孩子
		bt.InsertRightChild(cur, 4); // 插入右孩子

		cur = bt.LeftChild(cur);
		bt.InsertRightChild(cur, 5); // 插入右孩子

		cur = bt.GetRoot();
		cur = bt.RightChild(cur);
		bt.InsertLeftChild(cur, 6); // 插入左孩子
		c = cur;
		f = bt.Parent(c);
		cout << c->data << "双亲是" << f->data << endl;
		f = bt.LeftChild(bt.GetRoot());
		cout << bt.GetRoot()->data << "左孩子是" << f->data;
		f = bt.RightChild(bt.GetRoot());
		cout << ", 右孩子是" << f->data << endl;
		cout << "二叉树的高是" << bt.Height() << endl;

		cout << "原树:" << endl;
		DisplayBTWithTreeShape<int>(bt);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		BinaryTree<int> btNew(bt); // 复制构造新树
		cout << "复制构造新树:" << endl;
		DisplayBTWithTreeShape<int>(btNew);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		btNew = bt; // 赋值生成新树
		cout << "赋值生成新树:" << endl;
		DisplayBTWithTreeShape<int>(btNew);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		cout << "结点数:" << bt.NodeCount();
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		cout << "先序遍历:" << endl;
		bt.PreOrder(Write<int>);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		cout << "中序遍历:" << endl;
		bt.InOrder(Write<int>);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		cout << "后序遍历:" << endl;
		bt.PostOrder(Write<int>);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		cout << "层次遍历:" << endl;
		bt.LevelOrder(Write<int>);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		cur = bt.GetRoot();
		bt.DeleteRightChild(cur);
		cout << "删除根的右子树后:" << endl;
		DisplayBTWithTreeShape<int>(bt);
		cout << endl;
		system("PAUSE"); // 调用库函数system()

		bt.DeleteLeftChild(cur);
		cout << "删除根的左子树后:" << endl;
		DisplayBTWithTreeShape<int>(bt);
		cout << endl;

		int pre[] = {1, 2, 4, 5, 3, 7, 8}; // 先序序列
		int in[] = {4, 2, 5, 1, 7, 3, 8};  // 中序序列
		int n = 7;						   // 结点个数
		BinaryTree<int> preInbt;
		preInbt = CreateBinaryTree(pre, in, n); // 构造二叉树
		cout << "由pre[]={1,2,4,5,3,7,8},in[]={4,2,5,1,7,3,8}构造二叉树:" << endl;
		DisplayBTWithTreeShape<int>(preInbt);
		cout << endl;
	}
	catch (Error err) // 捕捉并处理异常
	{
		err.Show(); // 显示异常信息
	}

	system("PAUSE"); // 调用库函数system()
	return 0;		 // 返回值0, 返回操作系统
}