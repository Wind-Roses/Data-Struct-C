#define _CRT_SECURE_NO_WARNINGS 1

#include"Binary.h"

void test()
{
	TDataType* arr = "abdh###e##cf##g##";
	int idx = 0;
	TNode* root = NULL;

	root = BinaryTreeCreate(root, arr, &idx);

	printf("前序遍历：");
	PreorderTraversal(root);
	printf("中序遍历：");
	OrdinalTraversal(root);
	printf("后序遍历：");
	PostorderTraversal(root);
	printf("层序遍历：");
	SequenceTraversal(root);

	printf("是否是完全二叉树：%d\n", IsComplete(root));
}

int main()
{
	test();

	system("pause");
	return 0;
}