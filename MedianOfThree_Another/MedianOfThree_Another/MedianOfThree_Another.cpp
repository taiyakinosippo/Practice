//==========================================================
//	3’l‚Ì’†‰›’l@•Ê‰ğ‚Æ‘¬“x”äŠr
//==========================================================
#include <stdio.h>
#include <stdlib.h>  // srand(),rand()
#include <time.h>    // time()
//  ŠÖ”ƒvƒƒgƒ^ƒCƒv
int MedianOfThree(int a, int b, int c);
int MedianOfThree_Another1(int a, int b, int c);
int MedianOfThree_Another2(int a, int b, int c);
float MeasureTime(int count, int(*func)(int, int, int));

int main()
{
    const int COUNT = 20000000;
    srand(time(NULL));
    float time1 = MeasureTime(COUNT, MedianOfThree);
    float time2 = MeasureTime(COUNT, MedianOfThree_Another1);
    float time3 = MeasureTime(COUNT, MedianOfThree_Another2);

    printf("MedianOfThree()‚ÌŠÔ:%f•b\n", time1);
    printf("MedianOfThree_Another1()‚ÌŠÔ:%f•b\n", time2);
    printf("MedianOfThree_Another2()‚ÌŠÔ:%f•b\n", time3);
    return 0;
}

float MeasureTime(int count, int(*func)(int, int, int))
{
    clock_t start = clock();
    for (int i = 0; i < count; i++) {
        int a = rand() % 100;
        int b = rand() % 100;
        int c = rand() % 100;
        int ans = func(a, b, c);
    }
    clock_t end = clock();
    float time = (float)(end - start) / CLOCKS_PER_SEC;
    return time;
}
// ListC1-1 ‚Ì‚Ü‚Ü
int MedianOfThree(int a, int b, int c)
{
    if (a >= b) {
        if (b >= c) {
            return b; //yAzyBzyFzyGz
        }
        else if (a <= c) {
            return a; //yDzyEzyHz
        }
        else {
            return c; //yCz
        }
    }
    else if (a > c) {
        return a; //yIz
    }
    else if (b > c) {
        return c; //yJzyKz
    }
    else {
        return b; //yLzyMz
    }
}
// ‰‰K1-5 ‚Ì‚Ü‚Ü
int MedianOfThree_Another1(int a, int b, int c)
{
    if ((b >= a && c <= a) || (b <= a && c >= a)) {
        return a;
    }
    else if ((a > b && c < b) || (a < b && c > b)) {
        return b;
    }
    return c;
}
// ‰‰K1-5 ‚ğ”»‚è‚â‚·‚­C³
int MedianOfThree_Another2(int a, int b, int c)
{
    if ((b <= a && a <= c) || (c <= a && a <= b)) {
        // a‚ª^‚ñ’†‚É‚È‚éğŒ‚Í
        // b<=a<=c ‚Ü‚½‚Í c<=a<=b
        return a;
    }
    else if ((a <= b && b <= c) || (c <= b && b <= a)) {
        // b‚ª^‚ñ’†‚É‚È‚éğŒ‚Í
        // a<= b<=c ‚Ü‚½‚Í c<=b<=a
        return b;
    }
    // ‚»‚êˆÈŠO‚Íc
    return c;
}