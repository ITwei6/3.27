#include "heap.h"
void HpInit(Hp* ps)//�ѵĳ�ʼ��
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
void HpPush(Hp* ps, HpDataType x)//�ѵĲ���
{
	assert(ps);
	//����
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
void HpPop(Hp* ps)//�ѵ�ɾ��
{
	assert(ps);
	assert(!ps->size == 0);
	Swap(&ps->a[0], &ps->a[ps->size - 1]);
	ps->size--;
	AdjustDown(ps->a, ps->size, 0);
}
void HpDestroy(Hp* ps);//�ѵ�����
void AdjustUp(HpDataType*a, int child)//���ϵ���
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
void Swap(HpDataType* a, HpDataType* b)//��������
{
	HpDataType tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(HpDataType*a, int n, int parent)//���µ���
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		
	     //����child�ǽϴ�ĺ���
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
bool HpEmpty(Hp* ps)//�ж��Ƿ�Ϊ��
{
	assert(ps);
	return ps->size == 0;
	
}
HpDataType HpTop(Hp* ps)//��ȡ�Ѷ�Ԫ��
{
	assert(ps);
	return ps->a[0];
}
int HpSize(Hp* ps)//��ȡ����Ч���ݴ�С
{
	assert(ps);
	return ps->size;
}
//������--�����
//�Ž���--��С��
//�����˼�����ö�ɾ��˼�룬���µ�������ɾ�����ݶ���
//���ѺͶ�ɾ���ж��õ������µ�����
//�ѵĴ��������ϵ���