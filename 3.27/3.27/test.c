#include "heap.h"
int main()
{
	Hp ps;
	HpInit(&ps);
	HpPush(&ps, 25);
	HpPush(&ps, 100);
	HpPush(&ps, 255);
	HpPush(&ps, 74);
	HpPush(&ps, 3);
	HpPush(&ps, 26);
	HpPush(&ps, 97);
	HpPush(&ps, 20);
	HpPush(&ps, 78);
	HpPush(&ps, 35);

	return 0;
}