#include <stdio.h>
#include <stdlib.h>

int bitAnd(int x, int y) {         
	int result;
	
	x = ~ x;
	y = ~ y;
	result = x | y;
	result = ~ result;
	return result;
}
	
int bitXor(const int x, const int y) {          
	const int not_x = ~ x, not_y = ~ y;
	int result;
	
	result = (~ (x & y)) & (~ (not_x & not_y));
	return result;
}

int thirdBits(void) {
	return 1227133513;      /*  2^30 + 2^27 + ... + 2^3 + 2^0  */
}

int fitsBits(int x, int n) {
	int x_temporary, result;
	
	x = x >> (n - 1);              /* ������ "-" ��।����� ��� + (-int) */
	x_temporary = !(x + 1);        /* � ��砥, �᫨ x ������� � n ���, � ���祭�� x ��᫥ ᤢ��� �㤥� ���� = 0, ���� = 1*/
	x = !x;
	result = x | x_temporary;
	return result;
}

int sign(int x) {                    
	const int not_zero = !(!x);     
	int result;
	
	x = x >> 31;      /* ��� ������⥫��� x १���� �㤥� = -1, ��� ������⥫��� = 0 */
	result = x | not_zero;        /* �� ����⥫쭮� �᫮ �� �����, � �᫨ x - ������⥫쭮�, � ���祭�� �⠭������ = 1 */
	return result;
}

int getByte(int x, int n) {
	int result;
	
	x = x >> (n + n + n + n + n + n + n + n);     /* ������ "*" �ᯮ�짮���� �����(, ���⮬� ������ ᤢ����� �㦭� ���� �� ���� 8 ��� */
	result = x & 0xFF;        /* ��६ ⮫쪮 ��᫥���� 8 ��� */
	return result;
}

int logicalShift(int x, int n) {
	int result;
	
	x = x >> 1;
	x = x & 2147483647;       /*  ==2^31 - 1   ����塞 31 ���, �⮡� ᤢ��� �뫨 �����᪨��*/
	result = x >> (n - 1);
	return result;
}

int addOK(long long x, long long y) {
	long long legal_cheat;                    /* ��� �� �㭪樨 fitsBits */
	int temporary_var, result;
	
	legal_cheat = x + y;
	legal_cheat = legal_cheat >> 32;          /* ��� �� �ਬ���, ��� ���� ⮫쪮 � ������⥫��� �᫠�. � ��砥 �ᯮ�짮����� ����⥫��� �ᥫ � ��� ���� �������� "32" �� "31" */
	temporary_var = !(legal_cheat + 1);
	legal_cheat = !legal_cheat;
	result = legal_cheat | temporary_var;
	return result;
}

int bang(int x) {
	x = x | (~x + 1);
	x = x >> 31;
	x++;
	return x;
}

int conditional(int x, int y, int z) {
	int result;
	int mask = !(!x);
	
	mask = ~mask + 1;
	result = (y & mask) | (z & ~mask);
	return result;
}

int isPower2(int x) {
	int result, not_zero, is_positive;
	
	is_positive = x >> 1;
	is_positive = is_positive & 2147483647;
	is_positive = !(is_positive >> 30);
	not_zero = !(!x);
	result = !(x & (x - 1)) & not_zero & is_positive;
	return result;
}



int main(void) {
	for (int i = INT_MIN; i < INT_MAX; i++) {
		if (i % 10000000 == 0) {
			printf("%d\n", i);
		}
		if (!i != bang(i)) {
			printf("Wrong! %d vs %d\n", i, bang(i));
		}
	}
	return 0;
}