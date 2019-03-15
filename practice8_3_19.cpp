#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	//children
	Node*left;
	Node*right;

	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

class BiST{
	public:
	Node*root;
	BiST(){
		root=NULL;
	}

	void insert(int value){
		insertHelper(root,value);
	}
	void insertHelper(Node*curr, int value){
		//base case if curr is null, insert there
		if(root == NULL){
			root = new Node(value);
		}
		//else compare the curr data with value
		else if(value< curr->data){
		//if curr data > value -> 
		//if left is null, insert it
		//else move left and call insert
			if(curr->left == NULL) curr->left=new Node(value);
			else insertHelper(curr->left, value);
		}
		//else move right and call insertHelper
		else{
			if(curr->right == NULL) curr->right=new Node(value);
			else insertHelper(curr->right, value);
		}
	}
	
	void display(){display2(root);}
	void display2(Node*curr){
		//base condition
		if (curr==NULL) return;
		//display left
		else{
		display2(curr->left);
		//display current
		cout << curr->data << "," ;
		//display right
		display2(curr->right);
		}	
	}

	Node*search(int val){
		return search2(root, val);
	}

	Node*search2(Node*curr, int value){
		//if reached end of tree or value found
		if(curr == NULL || curr->data ==value) return curr;
		else if(value < curr->data) return search2(curr->left, value);
		else return search2(curr->right, value);
	}
};

int main(){
	BiST o1; int n;
	o1.insert(10);
	o1.insert(6);
	o1.insert(13);
	o1.insert(4);
	o1.insert(12);
	o1.insert(8);
	o1.insert(15);
	o1.display();
	cout<<endl;

	//using search
	cout<< "Enter the value you want to search in BiST" << endl;
	cin>>n;
	if(o1.search(n)!= NULL) cout<< n << " Found at " << o1.search(n) <<endl;
	else cout << n << " Not found in BiTS"<<endl;

	return 0;
}
