#include<iostream>
using namespace std;
const int N = 100;
class bingchaji {
public:  

    int stack[N];
    int father[N], size[N];
    void build()
    {
        
        int i = 0;
        for ( i = 0; i <N; i++) {
            father[i] = i;
            size[i] = 1;

        }

    }
    bool issameset(int a, int b) {
        return (find(a)!=find(b));


    }

    void Union(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa == fb)
            return;
        else {
            if (size[fa] < size[fb])
            {
                father[fa]= fb;
                size[fb] += size[fa];
            }
            else {
                father[b] = fa;
                size[fa] += size[fb];
            }
        }
    }
    int find(int i) {
        int size = 0;
        while (i != father[i]) {
            stack[size++] = i;
            i = father[i];
        }
        while (size--) {
           father[ stack[size]] = i;
        }
        return i;
    }

   
}; 
int main() {
    bingchaji b;
    b.build();

    cout << "--- 初始状态检查 ---" << endl;
    cout << "1号和2号是同一个圈子的吗？" << (b.issameset(1, 2) ? "是" : "不是") << endl;

    cout << "\n--- 开始建立社交圈（执行 Union） ---" << endl;
    
    b.Union(1, 2);
    cout << "执行 Union(1, 2) 后，1号的父亲是: " << b.father[1] << ", 2号的父亲是: " << b.father[2] << endl;

   
    b.Union(3, 4);
   
    b.Union(2, 3);

    cout << "\n--- 大融合后的圈子检查 ---" << endl;
    cout << "1号和4号现在是同一个圈子的吗？ " << (b.issameset(1, 4) ? "是" : "不是") << endl;
    cout << "1号和5号现在是同一个圈子的吗？ " << (b.issameset(1, 5) ? "是" : "不是") << endl;

   
    cout << "查找4号的根节点之前，4号的直接父亲是: " << b.father[4] << endl;

   
    int root4 = b.find(4);

    cout << "通过 find(4) 找到的根节点是: " << root4 << endl;
    cout << "【路径压缩后】4号的直接父亲变成了: " << b.father[4] << " (直接挂在根节点下了！)" << endl;

    system("pause");
    return 0;
}
