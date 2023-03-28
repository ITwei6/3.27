#include "heap.h"
void HpInit(Hp* ps)//堆的初始化
{
	assert(ps);
	ps->a = (HpDataType*)malloc(sizeof(HpDataType)*4);
	if (ps->a == NULL)
	{
		perror("malloc");
	}
	ps->capcity = 4;
	ps->size = 0;

}
void HpPush(Hp* ps, HpDataType x)//堆的插入
{
	assert(ps);
	//扩容
	if (ps->capcity == ps->size)
	{
		HpDataType* tmp = (HpDataType*)realloc(ps->a, sizeof(HpDataType) * ps->capcity * 2);
		if (tmp == NULL)
		{
			perror("realloc");
		}
		ps->a = tmp;
	}
	ps->a[ps->size] = x;
	ps->size++;
	AdjustUp(ps->a, ps->size-1);
}
void HpPop(Hp* ps)//堆的删除
{
	assert(ps);
	assert(!ps->size == 0);
	Swap(&ps->a[0], &ps->a[ps->size - 1]);
	ps->size--;
	AdjustDown(ps->a, ps->size, 0);
}
void HpDestroy(Hp* ps);//堆的销毁
void AdjustUp(HpDataType*a, int child)//向上调整
{
	assert(a);
	int parent = (child - 1) / 2;
	while (parent > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child],&a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void Swap(HpDataType* a, HpDataType* b)//交换数据
{
	HpDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(HpDataType*a, int n, int parent)//向下调整
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		
	     //假设child是较大的孩子
		if (child+1<n&&a[child] < a[child + 1])
		{
			++child;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	
		
	}

}
bool HpEmpty(Hp* ps)//判断是否为空
{
	assert(ps);
	return ps->size == 0;
	
}
HpDataType HpTop(Hp* ps)//获取堆顶元素
{
	assert(ps);
	return ps->a[0];
}
int HpSize(Hp* ps)//获取堆有效数据大小
{
	assert(ps);
	return ps->size;
}
//排升序--建大堆
//排降序--建小堆
//排序的思想是用堆删除思想，向下调整，不删除数据而言
//建堆和堆删除中都用到了向下调整。
//堆的创建，向上调整