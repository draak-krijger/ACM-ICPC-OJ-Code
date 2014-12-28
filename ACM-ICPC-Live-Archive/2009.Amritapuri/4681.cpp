// CII 4681
// 2009 Amritapuri: Visible Lattice
#include <cstdio>
#include <cstring>
 
#define N 105
 
int gcd(int m, int n) {
    int r;
    while (n > 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}
 
int calc(int n) {
    int i, j, k, ans = 0;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            for (k = 0; k <= n; k++) {
                if (i == 0 && j == 0 && k == 0) continue;
                if (i && j && k) ans += gcd(gcd(i, j), k) == 1;
                else if (i && j) ans += gcd(i, j) == 1;
                else if (i && k)ans += gcd(i, k) == 1;
                else if (k && j)ans += gcd(k, j) == 1;
                else if (i)ans += i == 1;
                else if (j)ans += j == 1;
                else if (k)ans += k == 1;
            }
    return ans;
}
int a[105];
int main() {
    int T, x;
/*    for(int i=1;i<=100;i++)
    	a[i]=calc(i);*/
    a[1] = 7;
    a[2] = 19;
    a[3] = 49;
    a[4] = 91;
    a[5] = 175;
    a[6] = 253;
    a[7] = 415;
    a[8] = 571;
    a[9] = 805;
    a[10] = 1033;
    a[11] = 1423;
    a[12] = 1723;
    a[13] = 2263;
    a[14] = 2713;
    a[15] = 3313;
    a[16] = 3913;
    a[17] = 4825;
    a[18] = 5491;
    a[19] = 6625;
    a[20] = 7513;
    a[21] = 8701;
    a[22] = 9811;
    a[23] = 11461;
    a[24] = 12637;
    a[25] = 14497;
    a[26] = 16045;
    a[27] = 18043;
    a[28] = 19807;
    a[29] = 22411;
    a[30] = 24163;
    a[31] = 27133;
    a[32] = 29485;
    a[33] = 32425;
    a[34] = 35065;
    a[35] = 38593;
    a[36] = 41221;
    a[37] = 45433;
    a[38] = 48727;
    a[39] = 52831;
    a[40] = 56335;
    a[41] = 61495;
    a[42] = 64987;
    a[43] = 70657;
    a[44] = 75037;
    a[45] = 80293;
    a[46] = 85111;
    a[47] = 91873;
    a[48] = 96529;
    a[49] = 103711;
    a[50] = 109171;
    a[51] = 116179;
    a[52] = 122299;
    a[53] = 130879;
    a[54] = 136765;
    a[55] = 145525;
    a[56] = 152509;
    a[57] = 161257;
    a[58] = 168901;
    a[59] = 179515;
    a[60] = 186475;
    a[61] = 197815;
    a[62] = 206545;
    a[63] = 217021;
    a[64] = 226333;
    a[65] = 238573;
    a[66] = 247273;
    a[67] = 260935;
    a[68] = 271399;
    a[69] = 284203;
    a[70] = 294643;
    a[71] = 309973;
    a[72] = 320413;
    a[73] = 336613;
    a[74] = 349033;
    a[75] = 363553;
    a[76] = 376621;
    a[77] = 394081;
    a[78] = 406249;
    a[79] = 425203;
    a[80] = 439123;
    a[81] = 456781;
    a[82] = 472021;
    a[83] = 492931;
    a[84] = 506827;
    a[85] = 527755;
    a[86] = 544513;
    a[87] = 564841;
    a[88] = 582241;
    a[89] = 606265;
    a[90] = 621889;
    a[91] = 646297;
    a[92] = 665437;
    a[93] = 688657;
    a[94] = 708667;
    a[95] = 734803;
    a[96] = 753331;
    a[97] = 781843;
    a[98] = 803137;
    a[99] = 829237;
    a[100] = 850957;
 
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }
}
