#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 16Áø¼ö -> ¼ıÀÚ 
int hexCharToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0; /* ì˜ëª»ëœ ë¬¸ìëŠ” 0ìœ¼ë¡œ ì²˜ë¦¬ */
}

// ¼ıÀÚ -> 16Áø¼ö 
char valToHexChar(int v) {
    if (v < 10) return (char)('0' + v);
    return (char)('A' + (v - 10));
}

// 1
int binaryStringToInt(const char *str) {
    int value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        value = value * 2 + (str[i] - '0');
    }
    return value;
}

// 2
unsigned int hexStringToInt(const char *str) {
    unsigned int value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        value = value * 16 + (unsigned int)hexCharToVal(str[i]);
    }
    return value;
}

// 3
char *intToBinaryString(int num) {
    unsigned int n = (unsigned int)num;
    char temp[33];
    temp[32] = '\0';

    for (int i = 31; i >= 0; i--) {
        temp[i] = (n % 2) + '0';
        n /= 2;
    }

    /* ë§¨ ì•ì˜ ë¶ˆí•„ìš”í•œ 0 ê±´ë„ˆë›°ê¸° (0 ìì²´ëŠ” ë‚¨ê²¨ë‘ ) */
    int start = 0;
    while (start < 31 && temp[start] == '0') start++;

    char *result = (char *)malloc(strlen(&temp[start]) + 1);
    strcpy(result, &temp[start]);
    return result;
}

// 4
char *intToHexString(int num) {
    unsigned int n = (unsigned int)num;
    char temp[9];
    temp[8] = '\0';

    for (int i = 7; i >= 0; i--) {
        temp[i] = valToHexChar(n % 16);
        n /= 16;
    }

    int start = 0;
    while (start < 7 && temp[start] == '0') start++;

    char *result = (char *)malloc(strlen(&temp[start]) + 1);
    strcpy(result, &temp[start]);
    return result;
}

// 5
char *addBaseStrings(const char *num1, const char *num2, int base) {
    int len1 = (int)strlen(num1);
    int len2 = (int)strlen(num2);
    int maxLen = (len1 > len2 ? len1 : len2) + 1;

    char *temp = (char *)malloc(maxLen + 1);
    temp[maxLen] = '\0';

    int i1 = len1 - 1, i2 = len2 - 1;
    int pos = maxLen - 1;
    int carry = 0;

    while (i1 >= 0 || i2 >= 0 || carry) {
        int d1 = (i1 >= 0) ? (num1[i1] - '0') : 0;
        int d2 = (i2 >= 0) ? (num2[i2] - '0') : 0;
        int sum = d1 + d2 + carry;

        temp[pos] = (sum % base) + '0';
        carry = sum / base;

        pos--; i1--; i2--;
    }

    int start = pos + 1;
    while (start < maxLen - 1 && temp[start] == '0') start++; /* ì•ì˜ 0 ì œê±° */

    char *result = (char *)malloc(strlen(&temp[start]) + 1);
    strcpy(result, &temp[start]);
    free(temp);
    return result;
}

// 6
char *addHexStrings(const char *hex1, const char *hex2) {
    int len1 = (int)strlen(hex1);
    int len2 = (int)strlen(hex2);
    int maxLen = (len1 > len2 ? len1 : len2) + 1;

    char *temp = (char *)malloc(maxLen + 1);
    temp[maxLen] = '\0';

    int i1 = len1 - 1, i2 = len2 - 1;
    int pos = maxLen - 1;
    int carry = 0;

    while (i1 >= 0 || i2 >= 0 || carry) {
        int d1 = (i1 >= 0) ? hexCharToVal(hex1[i1]) : 0;
        int d2 = (i2 >= 0) ? hexCharToVal(hex2[i2]) : 0;
        int sum = d1 + d2 + carry;

        temp[pos] = valToHexChar(sum % 16);
        carry = sum / 16;

        pos--; i1--; i2--;
    }

    int start = pos + 1;
    while (start < maxLen - 1 && temp[start] == '0') start++;

    char *result = (char *)malloc(strlen(&temp[start]) + 1);
    strcpy(result, &temp[start]);
    free(temp);
    return result;
}

// 7
char *multiplyHexByDigit(char digit, const char *hexStr) {
    int d = hexCharToVal(digit);
    int len = (int)strlen(hexStr);
    int maxLen = len + 1;

    char *temp = (char *)malloc(maxLen + 1);
    temp[maxLen] = '\0';

    int pos = maxLen - 1;
    int carry = 0;

    for (int i = len - 1; i >= 0; i--) {
        int val = hexCharToVal(hexStr[i]);
        int product = val * d + carry;

        temp[pos] = valToHexChar(product % 16);
        carry = product / 16;
        pos--;
    }
    if (carry > 0) {
        temp[pos] = valToHexChar(carry);
        pos--;
    }

    int start = pos + 1;
    while (start < maxLen - 1 && temp[start] == '0') start++;

    char *result = (char *)malloc(strlen(&temp[start]) + 1);
    strcpy(result, &temp[start]);
    free(temp);
    return result;
}

int main(void) {
    /* 1 */
    printf("1) \"1010101010101010\" -> %d\n", binaryStringToInt("1010101010101010"));

    /* 2 */
    printf("2) \"1A2B3C4D\" -> %u\n", hexStringToInt("1A2B3C4D"));

    /* 3 */
    char *bin = intToBinaryString(437);
    printf("3) 437 -> %s\n", bin);
    free(bin);

    /* 4 */
    char *hex = intToHexString(437);
    printf("4) 437 -> %s\n", hex);
    free(hex);

    /* 5 */
    char *sum5 = addBaseStrings("789", "654", 10);
    printf("5) 789 + 654 (base 10) -> %s\n", sum5);
    free(sum5);

    /* 6 */
    char *sum6 = addHexStrings("7C4", "3BE");
    printf("6) 7C4 + 3BE (hex) -> %s\n", sum6);
    free(sum6);

    /* 7 */
    char *prod7 = multiplyHexByDigit('A', "1F4");
    printf("7) A * 1F4 (hex) -> %s\n", prod7);
    free(prod7);

    return 0;
}
