#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char c;
    int data;
    Node *left;
    Node *right;
    Node(char temp, int d, Node *L = NULL, Node *R = NULL)
    {
        c = temp;
        data = d;
        left = L;
        right = R;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        if (a->data > b->data)
            return true;
        return false;
    }
};
void print_codes(Node *top, string ans)
{
    if (top == NULL)
        return;
    if (top->c != '*')
        cout << top->c << " : " << ans << endl;
    print_codes(top->left, ans + "0");
    print_codes(top->right, ans + "1");
}
void Huffman_Encoding(char arr[], int freq[], int n)
{
    Node *left, *right, *top;
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(arr[i], freq[i]));
    }
    for (int i = 1; i < n; i++)
    {
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        int data = left->data + right->data;
        top = new Node('*', data, left, right);
        pq.push(top);
    }
    print_codes(pq.top(), "");
}

int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    Huffman_Encoding(arr, freq, 6);
}