#define _CRT_SECURE_NO_WARNINGS 1

#include"Binary.h"

void test()
{
	TDataType* arr = "abdh###e##cf##g##";
	int idx = 0;
	TNode* root = NULL;

	root = BinaryTreeCreate(root, arr, &idx);

	printf("ǰ�������");
	PreorderTraversal(root);
	printf("���������");
	OrdinalTraversal(root);
	printf("���������");
	PostorderTraversal(root);
	printf("���������");
	SequenceTraversal(root);

	printf("�Ƿ�����ȫ��������%d\n", IsComplete(root));
}

int main()
{
	test();

	system("pause");
	return 0;
}