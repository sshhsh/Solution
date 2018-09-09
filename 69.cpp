//
// Created by sshhsh on 2018/9/9.
//


int mySqrt(int x) {
    int i = 1, j = x;
    if (j > 46340)j = 46340;
    if (x >= 2147395600)return j;
    if (x == 0)return 0;
    while (j - i > 1) {
        int tmp = (i + j) / 2;
        long tmp2 = tmp * tmp;
        if (tmp2 == x)
            return tmp;
        else if (tmp2 < x)
            i = tmp;
        else
            j = tmp;
    }
    return i;
}

int main() {
    int a = mySqrt(2147395599);
    return 0;
}
