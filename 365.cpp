//
// Created by zhucebiao on 2018/7/23.
//

int gcd(int x, int y) {
    if(x==0)
        return y;
    if(y==0)
        return x;
    int z = y;
    while (x % y != 0) {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

bool canMeasureWater(int x, int y, int z) {
    int g = gcd(x, y);
    if(g==0)
        return z==0;
    return z<=(x+y)&&z>=0&&z%g==0;
}

int main(){
    bool res = canMeasureWater(0,0,0);
    return 0;
}
