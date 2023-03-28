#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int HpDataType;
typedef struct Heap
{
	HpDataType* a;
	int size;
	int capcity;
}Hp;//����һ����

void HpInit(Hp* ps);//�ѵĳ�ʼ��
void HpPush(Hp* ps,HpDataType x);//�ѵĲ���
void HpPop(Hp* ps);//�ѵ�ɾ��
void HpDestroy(Hp* ps);//�ѵ�����
void AdjustUp(HpDataType*a,int child);//���ϵ���
void Swap(HpDataType* a, HpDataType* b);//��������
void AdjustDown(HpDataType* a, int n, int parent);//���µ���
bool HpEmpty(Hp* ps);//�ж��Ƿ�Ϊ��
HpDataType HpTop(Hp* ps);//��ȡ�Ѷ�Ԫ��
int HpSize(Hp* ps);//��ȡ����Ч���ݴ�С

