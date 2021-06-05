#include<bits/stdc++.h>
using namespace std;

//��������
typedef struct
{
    int weight;
    int parent, lChild, rChild;
}HTNode, *HuffmanTree;

// �����������
typedef struct
{
    char** code;    // �����
    int n;          // ������
}HuffmanCode;

//ѡ��С���ڵ� 
void SelectMin(HuffmanTree hT, int n, int &s1, int &s2)
{
    s1 = s2 = 0;
    int i;
    for(i = 1; i < n; ++ i){
        if(0 == hT[i].parent){
            if(0 == s1){
                s1 = i;
            }
            else{
                s2 = i;
                break;
            }
        }
    }
    if(hT[s1].weight > hT[s2].weight){
        int t = s1;
        s1 = s2;
        s2 = t;
    }
    for(i += 1; i < n; ++ i){
        if(0 == hT[i].parent){
            if(hT[i].weight < hT[s1].weight){
                s2 = s1;
                s1 = i;
            }else if(hT[i].weight < hT[s2].weight){
                s2 = i;
            }
        }
    }
}

//������n���ӽڵ�Ĺ�������
void CreateHufmanTree(HuffmanTree &hT)
{
    int n, m;
    cout<<"������һ���м����㣺";
    cin >> n;
    m = 2*n - 1;//�ܽڵ���
    hT = new HTNode[m + 1]; 
    for(int i = 1; i <= m; ++ i){
        hT[i].parent = hT[i].lChild = hT[i].rChild = 0;
    } 
    cout<<"������������Ӧ��Ȩֵ��"<<endl;
    for(int i = 1; i <= n; ++ i){
        cin >> hT[i].weight;    // ����Ȩֵ
    }
    hT[0].weight = m;
    //��ʼ�����, ������������
    for(int i = n + 1; i <= m; ++ i){
        int s1, s2;
        SelectMin(hT, i, s1, s2);
        hT[s1].parent = hT[s2].parent = i;
        hT[i].lChild = s1;
		hT[i].rChild = s2;
        hT[i].weight = hT[s1].weight + hT[s2].weight;
    }
}

//���ݹ��������������������
void CreateHuffmanCode(HuffmanTree hT, HuffmanCode &hC)
{
    hC.n = (hT[0].weight + 1)/2;
    hC.code = new char*[hC.n + 1];
    char *cd = new char[hC.n];
    for(int i = 1; i <= hC.n; ++ i){
        // ÿ�δ�Ҷ�ӽڵ����ϻ��ݹ������
        int len = 0, child = i, parent = hT[i].parent;
        while(parent != 0){
            if(hT[parent].lChild == child){
                cd[len ++] = '0';
            }
            else{
                cd[len ++] = '1';
            }
            child = parent;
            parent = hT[parent].parent;
        }
        cd[len] = 0;
        reverse(cd, cd + len);
        hC.code[i] = new char[len];
        strcpy(hC.code[i], cd);
    }

}

//�����������
void PrintHuffmanCode(HuffmanCode &hC)
{
    for(int i = 1; i <= hC.n; ++ i){
        cout <<i<<":"<< hC.code[i] << endl;
    }
}

//����ƽ���볤 
void PrintAverageCodeLength(HuffmanTree hT, HuffmanCode &hC)
{
	double wpl=0;
    for(int i = 1; i <= hC.n; ++ i){
        wpl+=strlen(hC.code[i])*hT[i].weight;
    }
    cout<<"ƽ���볤Ϊ��"<< wpl/100 <<endl;
}

int main()
{
    HuffmanTree hT;
    CreateHufmanTree(hT);

    HuffmanCode hC;
    CreateHuffmanCode(hT, hC);
    PrintHuffmanCode(hC);
    PrintAverageCodeLength(hT,hC);

    return 0;
}
/*
8
5 5 10 10 10 15 20 25
*/

