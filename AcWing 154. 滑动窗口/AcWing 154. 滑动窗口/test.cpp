#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
using namespace std;
const int N = 1000100;
//��������һ����˫�˶��б�֤�䵥����
int a[N], q[N], n, k;
//��ͷ�Ͷ�β���ڶ�β���룬��ͷ��ȡ
int front = 0, tail = -1;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    //����ÿ�����ڵ���Сֵ
    for (int i = 0; i < n; i++) {
        //�����ǰ��ͷ��������±�С�ڵ�ǰ���ڵ���С�±꣬������ھͲ��������Ԫ������ô������ζ�Ҫ�޳���ͷ���Ԫ��
        //����Ҫ�ڶ�ͷɾ�����Ԫ��
        if (front <= tail && i - k + 1 > q[front]) front++;
        //��֤�����ԣ��ڶ�βɾ����ΪʲôҪ�ڶ�βɾ��������˵�ڶ�ͷɾ�����ܱ�֤����
        //����-3 5Ϊ��ǰ���У���ǰ��Ԫ��Ϊ3������ڶ�ͷ��������ô����a[i] <= a[q[front]����3 > -3����˲���ɾ������
        //���ǽ������ͳ��������ˣ�3��Ҫ����ˡ���ʱ���о���-3 5 3�������ϵ������ˣ�
        //������ڶ�β����������a[i] <= a[q[tail]����3 < 5����Ҫ��5����
        //֮��3��ӣ����о���-3 3�����㵥����
        while (front <= tail && a[i] <= a[q[tail]]) tail--;
        q[++tail] = i;
        //��ͷΪ���ڵ���Сֵ
        if (i >= k - 1) printf("%d ", a[q[front]]);
    }
    printf("\n");
    //��������ֵ��ͬ��
    front = 0, tail = -1;
    for (int i = 0; i < n; i++) {
        if (front <= tail && i - k + 1 > q[front]) front++;
        while (front <= tail && a[i] >= a[q[tail]]) tail--;
        q[++tail] = i;
        if (i >= k - 1) printf("%d ", a[q[front]]);
    }
}