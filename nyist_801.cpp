/*****************************************************************************
 **	Author: C.H Wong
 **	Email: wchyumo2009@163.com
 **	Create time: 2015/3/30
 **	File name: nyist_801.cpp
 **	This program is created to build a huffman tree and than get the huffman 
 **	code. 
 *****************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define MAXN 1000

typedef bool huffman_tree_node_type;
const huffman_tree_node_type leaf = true;
const huffman_tree_node_type others = false;

/*****************************************************************************
 **	the structure of HuffmanTreeBase
 **	left for the left child
 **	right for the right child
 **	frequent for the weight of the node
 **	value for the value of the node
 **	huffman_code for the code after huffman coding
 **	leaf present whether the node is a leaf node
 *****************************************************************************/

typedef struct huffman_tree_base
{
    struct huffman_tree_base *left;
    struct huffman_tree_base *right;
    int frequent;
    char value;
    string huffman_code;
    huffman_tree_node_type leaf;

    /*bool operator<(const huffman_tree_base &htt)
    {
        return htt.frequent == frequent ? htt.value > value : htt.frequent > frequent;
    }*/

}HuffmanTreeBase;

/*compare method for priority_queue<HuffmanTreeBase >*/
bool operator<(HuffmanTreeBase htt1, HuffmanTreeBase htt2)
{
    return htt1.frequent == htt2.frequent ? htt1.value > htt2.value : htt1.frequent > htt2.frequent;
}

/*compare method for priority_queue<HuffmanTreeBase *>*/
class Compare
{
public:
    bool operator()(HuffmanTreeBase *htt1, HuffmanTreeBase *htt2)
    {
        return htt1->frequent == htt2->frequent ? htt1->value > htt2->value : htt1->frequent > htt2->frequent;
    }
};

HuffmanTreeBase pdata[MAXN];
int n;

/*the initiation for the native data*/
void init()
{
    char ch;
    int frequent;
    for (int i = 0; i < n; ++i){
        getchar();
        scanf ("%c%d", &ch, &frequent);
        pdata[i].leaf = leaf;
        pdata[i].frequent = frequent;
        pdata[i].value = ch;
        pdata[i].left = NULL;
        pdata[i].right = NULL;
        pdata[i].huffman_code = "";
        /*printf ("=====>%c %d\n", ch, frequent);*/
    }
}

/*****************************************************************************
 **	create huffman tree
 **	parameter: none
 **	return: HuffmanTreeBase* --the root of the builted huffman tree
 *****************************************************************************/
 
HuffmanTreeBase* buildHuffmanTree()
{
    priority_queue <HuffmanTreeBase*, vector<HuffmanTreeBase *>, Compare> PQ;
    HuffmanTreeBase *leftChild = NULL;
    HuffmanTreeBase *rightChild = NULL;
    for (int i = 0; i < n; ++i){
        PQ.push(&pdata[i]);
    }
    int index = n;
    while (!PQ.empty()){
        leftChild = PQ.top();
        PQ.pop();
        if (PQ.empty())break;
        rightChild = PQ.top();
        PQ.pop();
        pdata[index].leaf = others;
        pdata[index].left = leftChild;
        pdata[index].right = rightChild;
        pdata[index].value = leftChild->value;
        pdata[index].frequent = leftChild->frequent + rightChild->frequent;
        PQ.push(&pdata[index]);
        /*printf ("=====>%c %d\n", pdata[index].value, pdata[index].frequent);*/
        ++index;
    }
    return leftChild;
}

/*****************************************************************************
 **	get huffman code for each leaf node
 **	parameter: HuffmanTreeBase*, string
 **	the first parameter is the root of the huffman tree
 **	the second parameter is the huffman code to be used
 **	return: void
 *****************************************************************************/
 
void getCode(HuffmanTreeBase *root, string huffmancode)
{
    if (root->leaf == leaf){
        root->huffman_code = huffmancode;
        return ;
    }
    if (root->left){
        getCode(root->left, huffmancode + '0');
    }
    if (root->right){
        getCode(root->right, huffmancode + '1');
    }
}

/*print each charactor and its huffman code*/
void printHuffmanCode()
{
    for (int i = 0; i < n; ++i){
        cout << pdata[i].value << ":" << pdata[i].huffman_code << endl;
    }
}

int main()
{
    while (~scanf ("%d", &n)){
        init();
        HuffmanTreeBase *root = NULL;
        root = buildHuffmanTree();
        getCode(root, "");
        printHuffmanCode();
    }
    return 0;
}
