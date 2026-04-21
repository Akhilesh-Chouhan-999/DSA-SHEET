#include <bits/stdc++.h>
using namespace std;


/*
    POPCOUNT = number of set bits (1s) in binary representation
*/

/* ---------------------------------------------------
   1. Built-in Function (BEST & FASTEST)
--------------------------------------------------- */
void builtin_method() {
    int x = 13; // binary: 1101

    cout << "Builtin popcount (int): " << __builtin_popcount(x) << endl;
    cout << "Builtin popcount (long long): " << __builtin_popcountll(x) << endl;
}

/* ---------------------------------------------------
   2. Brian Kernighan’s Algorithm (MOST IMPORTANT)
   Removes one set bit at a time
--------------------------------------------------- */
int kernighan_method(int n) {
    int count = 0;

    while (n) {
        n = n & (n - 1); // removes rightmost set bit
        count++;
    }

    return count;
}

/* ---------------------------------------------------
   3. Simple Loop Method (Basic)
--------------------------------------------------- */
int simple_method(int n) {
    int count = 0;

    while (n) {
        count += (n & 1); // check last bit
        n >>= 1;          // shift right
    }

    return count;
}

/* ---------------------------------------------------
   4. Precomputation (DP)
   Useful for multiple queries
--------------------------------------------------- */
vector<int> dp(1000001);

void precompute() {
    for (int i = 1; i <= 1000000; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
}

/* ---------------------------------------------------
   5. Advanced Bit Hack (Divide & Conquer)
   Rarely asked but very fast
--------------------------------------------------- */
int advanced_method(int x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x3F;
}

int main() {

    int x = 10; // 1010 in binary
    int n = 1;

    // ------------------------------
    // 1. Set nth bit
    // ------------------------------
    // Sets bit at position n to 1
    cout << "Set nth bit: " << (x | (1 << n)) << endl;

    // ------------------------------
    // 2. Unset nth bit
    // ------------------------------
    // Sets bit at position n to 0
    cout << "Unset nth bit: " << (x & ~(1 << n)) << endl;

    // ------------------------------
    // 3. Toggle nth bit
    // ------------------------------
    // Flips the bit (0->1, 1->0)
    cout << "Toggle nth bit: " << (x ^ (1 << n)) << endl;

    // ------------------------------
    // 4. Check even or odd
    // ------------------------------
    cout << "Is Even: " << ((x & 1) == 0) << endl;
    cout << "Is Odd: " << ((x & 1) != 0) << endl;

    // ------------------------------
    // 5. Multiply / Divide by 2
    // ------------------------------
    cout << "Multiply by 2: " << (x << 1) << endl;
    cout << "Divide by 2: " << (x >> 1) << endl;

    // ------------------------------
    // 6. Check if power of 2
    // ------------------------------
    int p = 8;
    cout << "Is power of 2: " << (p > 0 && (p & (p - 1)) == 0) << endl;

    // ------------------------------
    // 7. Swap two numbers (XOR)
    // ------------------------------
    int a = 5, b = 7;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << "After swap: a=" << a << " b=" << b << endl;

    // ------------------------------
    // 8. Get absolute value
    // ------------------------------
    int val = -6;
    int absVal = (val ^ (val >> 31)) - (val >> 31);
    cout << "Absolute value: " << absVal << endl;

    // ------------------------------
    // 9. Get max and min
    // ------------------------------
    int A = 10, B = 20;

    int maxVal = B & ((A - B) >> 31) | A & (~(A - B) >> 31);
    int minVal = A & ((A - B) >> 31) | B & (~(A - B) >> 31);

    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;

    // ------------------------------
    // 10. Same sign check
    // ------------------------------
    int y = -3;
    cout << "Same sign: " << ((x ^ y) >= 0) << endl;

    // ------------------------------
    // 11. Flip sign
    // ------------------------------
    int num = 5;
    cout << "Flipped sign: " << (~num + 1) << endl;

    // ------------------------------
    // 12. Get mth bit
    // ------------------------------
    int m = 2;
    cout << "mth bit: " << ((x >> (m - 1)) & 1) << endl;

    // ------------------------------
    // 13. Check nth bit set
    // ------------------------------
    if (x & (1 << n))
        cout << "Bit is set\n";
    else
        cout << "Bit is not set\n";

    // ------------------------------
    // 14. Remove rightmost set bit
    // ------------------------------
    cout << "Remove rightmost 1: " << (x & (x - 1)) << endl;

    // ------------------------------
    // 15. Extract rightmost set bit
    // ------------------------------
    cout << "Rightmost set bit: " << (x & -x) << endl;

    // ------------------------------
    // 16. Set rightmost zero bit
    // ------------------------------
    cout << "Set rightmost 0: " << (x | (x + 1)) << endl;

    // ------------------------------
    // 17. Average of two numbers
    // ------------------------------
    cout << "Average: " << ((A + B) >> 1) << endl;

    // ------------------------------
    // 18. Equality check
    // ------------------------------
    cout << "Equal: " << ((A ^ B) == 0) << endl;

    // ------------------------------
    // 19. Modulo (power of 2)
    // ------------------------------
    int mod = 8;
    cout << "Modulo: " << (x & (mod - 1)) << endl;

    // ------------------------------
    // 20. Enumerate submasks
    // ------------------------------
    int mask = 7; // 111
    int s = mask;

    cout << "Submasks:\n";
    while (s > 0) {
        cout << s << endl;
        s = (s - 1) & mask;
    }

    // ------------------------------
    // 21. Character tricks
    // ------------------------------
    char ch = 'A';

    // Convert to lowercase
    cout << "Lowercase: " << char(ch | ' ') << endl;

    // Convert to uppercase
    cout << "Uppercase: " << char(ch & '_') << endl;

    // Toggle case
    cout << "Toggle case: " << char(ch ^ ' ') << endl;

    // Position in alphabet
    cout << "Position: " << (ch & 31) << endl;


    int x = 13; // binary: 1101 → answer = 3

    cout << "Input number: " << x << endl;

    // Method 1: Built-in
    builtin_method();

    // Method 2: Kernighan
    cout << "Kernighan method: " << kernighan_method(x) << endl;

    // Method 3: Simple loop
    cout << "Simple method: " << simple_method(x) << endl;

    // Method 4: Precompute
    precompute();
    cout << "DP precompute method: " << dp[x] << endl;

    // Method 5: Advanced
    cout << "Advanced bit hack: " << advanced_method(x) << endl;

    return 0;

    return 0;
}