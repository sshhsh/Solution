//
// Created by zhucebiao on 2018/7/23.
//

stack<int> cache;
int rand10() {
    while (cache.size() == 0) generate();
    int res = cache.top(); cache.pop();
    return res;
}

void generate() {
    int n = 19;
    long cur = 0, range = long(pow(7, n));
    for (int i = 0; i < n; ++i) cur += long(pow(7, i)) * (rand7() - 1);
    while (cur < range / 10 * 10) {
        cache.push(cur % 10 + 1);
        cur /= 10;
        range /= 10;
    }
}