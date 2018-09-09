//
// Created by sshhsh on 2018/9/9.
//
#include <set>
#include <map>

using namespace std;

class ExamRoom {
    int max;

    struct Blank {
        int start;
        int length;
        int end;

        Blank(int start, int end, int max) {
            this->start = start;
            this->end = end;
            if (start == 0 || end == max) {
                length = end - start - 1;
            } else {
                length = (end - start - 1) / 2;
            }
        }

        bool operator<(const struct Blank &right) const {
            return this->length > right.length;
        }
    };

    multiset<Blank> set;
    map<int, multiset<Blank>::iterator> start;
    map<int, multiset<Blank>::iterator> end;
public:
    ExamRoom(int N) {
        max = N;
        auto it = set.insert(Blank(0, N, max));
        start[0] = it;
        end[N] = it;
    }

    int seat() {
        int l = set.begin()->length;
        multiset<Blank>::iterator tmp;
        int s = max;
        for (auto it = set.begin(); it != set.end(); it++) {
            if (it->length < l)break;
            if (it->start < s) {
                s = it->start;
                tmp = it;
            }
        }

        int e = tmp->end;

        int sit;
        if (s == 0)
            sit = 0;
        else if (e == max)
            sit = max - 1;
        else
            sit = (s + e - 1) / 2;

        start.erase(s);
        end.erase(e);
        set.erase(tmp);

        if (sit - s > 0) {
            auto tmp1 = set.insert(Blank(s, sit, max));
            start[s] = tmp1;
            end[sit] = tmp1;
        }
        if (e - sit > 1) {
            auto tmp2 = set.insert(Blank(sit + 1, e, max));
            start[sit + 1] = tmp2;
            end[e] = tmp2;
        }
        return sit;
    }

    void leave(int p) {
        int s = 0, e = max - 1;
        if (start.count(p + 1)) {
            auto it1 = start[p + 1];
            start.erase(p + 1);
            e = it1->end;
            end.erase(e);
            set.erase(it1);
        } else {
            e = p + 1;
        }
        if (end.count(p)) {
            auto it2 = end[p];
            s = it2->start;
            start.erase(s);
            end.erase(p);
            set.erase(it2);
        } else {
            s = p;
        }

        auto it = set.insert(Blank(s, e, max));
        start[s] = it;
        end[e] = it;
    }
};

int main() {
    ExamRoom *obj = new ExamRoom(10);
    int res = obj->seat();
    res = obj->seat();
    res = obj->seat();
    res = obj->seat();
    obj->leave(4);
    res = obj->seat();
    return 0;
}