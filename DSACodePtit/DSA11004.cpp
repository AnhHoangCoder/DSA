// Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo Level-order. Phép duyệt level-order trên cây là phép thăm node theo từng mức của cây. Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt level-order: 20  8  22  4  12  10  14.

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
// T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
// Output:

// Đưa ra kết quả phép duyệt level-order theo từng dòng.
//      Ví dụ:

// Input

// Output

// 2
// 2
// 1 2 R 1 3 L
// 4
// 10 20 L 10 30 R 20 40 L 20 60 R

// 1 3 2

// 10 20 30 40 60

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
	Node(int item){
		key = item;
		left = NULL;
		right = NULL;
	}
};

Node* Search(Node* T , int x){
	Node* p;
	if(T == NULL){
		return NULL;
	}
	if(T->key == x){
		return T;
	}
	
	p = Search(T->left , x);
	if(p == NULL){
		p = Search(T->right , x);
	}
	return p;
}

void Add_left(Node* T , int x , int y){
	Node *p , *q;
	p = Search(T , x);
	if(p == NULL){
		return;
	}
	else if((p->left) != NULL){
		return;
	}
	else{
		p->left = new Node(y);
	}
} 


void Add_right(Node* T , int x , int y){
	Node *p , *q;
	p = Search(T , x);
	if(p == NULL){
		return;
	}
	else if((p->right) != NULL){
		return;
	}
	else{
		p->right = new Node(y);
	}
} 

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* cur = q.front();
        q.pop();

        cout << cur->key << " ";

        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        Node* root = nullptr;

        while(n--){
            int x , y;
            char c;
            cin >> x >> y >> c;

            if(root == nullptr){
                root = new Node(x);
            }

            if(c == 'L'){
                Add_left(root , x , y);
            }
            else{
                Add_right(root , x , y);
            }
        }
        levelOrder(root);
        cout << endl;
    }
    return 0;
}