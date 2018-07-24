//
// Created by zhucebiao on 2018/7/24.
//

int lcm(int a, int b) {
    int c = b, m = a * b;
    while (a % b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return m / c;
}

int mirrorReflection(int p, int q) {
    int l = lcm(p, q);
    int x = l / q;
    int y = l / p;
    if (x % 2 == 1 && y % 2 == 1)
        return 1;
    else if (x % 2 == 0 && y % 2 == 1)
        return 2;
    else if (x % 2 == 1 && y % 2 == 0)
        return 0;
    return -1;
}

int main() {
    int res = mirrorReflection(4, 3);
    return res;
}