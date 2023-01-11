#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
template<class T>
class NodeL
{
	T data;
	NodeL* next;
	NodeL* prev;
public:
	NodeL(T valu)
	{
		data = valu;
		next = NULL;
		prev = NULL;
	}

	NodeL()
	{
		next = NULL;
		prev = NULL;
	}
	T getData()
	{
		return data;
	}
	NodeL* getNext()
	{
		return next;
	}
	NodeL* getPrev()
	{
		return prev;
	}
	void setData(T valu)
	{
		data = valu;
	}
	void setNext(NodeL* x)
	{
		next = x;
	}
	void setPrev(NodeL* x)
	{
		prev = x;
	}

};
template<class T>
class LinkedList
{
	NodeL<T>* head = NULL;
	NodeL<T>* tail = NULL;
	NodeL<T>* newn = NULL;
	NodeL<T>* index;
	NodeL<T>* del;
public:
	void insert(T valu)
	{
		NodeL<T>* newn = new NodeL<T>;
		newn->setData(valu);
		if (head == NULL && tail == NULL)
		{
			head = newn;
			tail = newn;
		}
		else
		{
			tail->setNext(newn);
			newn->setPrev(tail);
			tail = newn;
		}
	}
	T getHead() {
		return head->getData();
	}
	NodeL<T>* getHeadP() {
		return head;
	}
	void insertAtHead(T valu)
	{
		NodeL<T>* newn = new NodeL<T>;
		newn->setData(valu);
		newn->setNext(head);
		head->setPrev(newn);
		head = newn;
	}
	void insertAtIndex(T valu, int x)
	{
		index = head;
		for (int i = 0; i < x; i++)
			index = index->getNext();

		NodeL<T>* newn = new NodeL<T>;
		newn->setData(valu);

		newn->setNext(index);
		del = index->getPrev();
		newn->setPrev(del);
		index->setPrev(newn);

		del->setNext(newn);
	}
	void print()
	{
		index = head;
		while (index != NULL)
		{
			cout << " ==> " << index->getData();
			index = index->getNext();
		}
		cout << endl;
	}
	T search(T valu)
	{
		index = head;
		while (index != NULL)
		{
			if (index->getData() == valu)
				return index->getData();
			index = index->getNext();
		}
		return NULL;
	}
	void update(T x, T valu)
	{
		index = head;
		while (index != NULL)
		{
			if (index->getData() == x)
			{
				index->setData(valu);
				break;
			}
			else
				index = index->getNext();

		}

	}
	void removehead()
	{
		index = head;
		del = index->getNext();
		if (index->getNext())
		{
			del->setPrev(index->getPrev());
		}
		head = head->getNext();
		delete index;
	}
	void remove(T x)
	{
		index = head;
		if (index->getData() == x)
		{
			head = head->getNext();
			head->setPrev(NULL);
			delete index;
		}
		else
		{
			while (index != NULL)
			{
				if (index->getData() == x)
					break;
				else
					index = index->getNext();
			}

			del = index->getPrev();

			del->setNext(index->getNext());

			del = index->getNext();
			if (index->getNext())
			{
				del->setPrev(index->getPrev());
			}delete index;
		}
	}
	bool empty()
	{
		if (head)
			return 0;
		else
			return 1;
	}

};
template<class T>
class HashT
{
	// size of the hash table
	int size;
	// Pointer to an array containing the keys
	LinkedList<string>* table;
public:
	// creating constructor of the above class containing all the methods
	// hash function to compute the index using table_size and key
	int hashFunction(T key) {
		return (key % size);
	}
	HashT(int ts)
	{
		this->size = ts;
		table = new LinkedList<string>[size];
	}
	// insert function to push the keys in hash table
	void insertElement(T key,string S)
	{
		int index = hashFunction(key);
		table[index].insert(S);
	}
	// delete function to delete the element from the hash table
	void deleteElement(T key,string S)
	{
		int index = hashFunction(key);
		table[index].remove(S);
		// finding the key at the computed index
	}
	// display function to showcase the whole hash table
	void displayHashTable() 
	{
		for (int i = 0; i < size; i++) 
		{
			cout << i;
			table[i].print();
		}
	}

};
template<class T,class T1>
class Node
{
public:
	T X;
	T1 Y;
	Node* next = NULL;
	Node(T x,T1 y)
	{
		X = x;
		Y = y;
//		cout << x << "," << y << endl;
	}
};
template<class T, class T1>
class Queue
{
	Node<T,T1>* front = NULL;
	Node<T,T1>* rare = NULL;
	Node<T,T1>* newn;
public:
	Node<T,T1>* getRear()
	{
		return rare;
	}
	void enqueue(T x,T1 y)
	{
		if (front == NULL)
		{
			newn = new Node<T,T1>(x,y);
			front = newn;
			rare = newn;
		}
		else
		{
			newn = new Node<T,T1>(x, y);
			rare->next = newn;
			rare = newn;
		}
	}
	T Front()
	{
		return front->getData();
	}
	Node<T,T1>* dequeue()
	{
		if (rare != NULL)
		{
			newn = front;
			front = front->next;
			return newn;
		}
	}
	bool check(T x, T1 y)
	{
		newn = front;
		while (newn)
		{
			if (newn->X == x&& newn->Y == y)
			{
				return true;
			}
			newn = newn->next;
		}

		return false;
	}
	bool isEmpty()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}
};
template<class T, class T1>
class stack {
private:
	Node<T,T1>* Top = NULL;
	Node<T, T1>* newn;
public:
	Node<T, T1>* Peek()
	{
		return Top;
	}
	void push(T x,T1 y)
	{
		if (Top == NULL)
		{
			newn = new Node<T, T1>(x,y);
			Top = newn;
		}
		else
		{
			newn = new Node<T, T1>(x,y);
			newn->next = Top;
			Top = newn;
		}
	}
	Node<T, T1>* pop()
	{
		if (Top != NULL)
		{
				newn = Top;
				Top = Top->next;
				return newn;
		}
		else
		{
			cout << "Stack is empty!";
			return NULL;
		}

	}
	int sizeofstack()
	{
		newn = Top;
		int N = 0;
		while (newn)
		{
			newn = newn->next;
			N++;
		}
		return N;
	}
	bool isEmpty()
	{
		if (Top == NULL)
			return true;
		else
			return false;
	}
	bool check(T x, T1 y)
	{
		newn = Top;
		while (newn)
		{
			if (newn->X == x && newn->Y == y)
			{
				return true;
			}
			newn = newn->next;
		}
		return false;
	}
	Node<T, T1>* dequeue()
	{
		stack<T, T1> S;
		while (!isEmpty())
		{
			newn = pop();
			S.push(newn->X, newn->Y);
		}
		Node<T, T1>* nwn=S.pop();
		while (!S.isEmpty())
		{
			newn = S.pop();
			push(newn->X, newn->Y);
		}
		return nwn;
	}
};
class IMG
{
public:
	int width;
	int height;
	int** Image;
	int mx;
	int Read(string S)
	{

		int row = 0, col = 0, r = 0, c = 0,Bn=0;
		stringstream ss;
		ifstream file(S, ios::binary);
		string inputLine = "";
		getline(file, inputLine);      // read the first line : P5
		if (inputLine[1] == '5')
			Bn = 0;
		else if (inputLine[1] == '2')
			Bn = 1;
		getline(file, inputLine);  // read the second line : comment
		if(Bn==0)
		getline(file, inputLine);  // read the second line : comment
		ss << file.rdbuf();   //read the third line : width and height
		ss >> c >> r;
		//cout << r << "," << c << endl;
		ss >> mx;
	    Image = new int* [r];
		for (int i = 0; i < r; ++i) {
			Image[i] = new int[c];
		}
		unsigned char pixel;
		int pix;
		if (Bn == 0)
		{
			for (row = 0; row < r; row++) {    //record the pixel values
			for (col = 0; col < c; col++) {
					ss >> pixel;
					Image[row][col] = pixel;
			}
			}
		}
		else if (Bn == 1)
		{
			for (row = 0; row < r; row++) {    //record the pixel values
			for (col = 0; col < c; col++) {
					ss >> pix;
					Image[row][col] = pix;
//					cout << pix;
				}
			}
		}
		width = c;
		height = r;
		return 0;
	}
	int Getpixel(int R, int C)
	{
		int x = 0;
		if (R >= 0 && R < height && C >= 0 && C < width)
		{
			x = Image[R][C];
			return x;
		}
		else
		{
			cout << "Wrong Input!\n";
		}
		return x;
	}
	int Setpixel(int R, int C,int x)
	{
		if (R >= 0 && R < height && C >= 0 && C < width)
		{
			Image[R][C]=x;
			return 1;
		}
		else
		{
			cout << "Wrong Input!\n";
		}
		return 0;
	}
	int ConvertToNegative(int R, int C)
	{
		if (R >= 0 && R < height && C >= 0 && C < width)
		{
			Image[R][C]= Image[R][C] -255;
			Image[R][C] = Image[R][C] *(-1);
			return 1;
		}
		else
		{
			cout << "Wrong Input!\n";
		}
		return 0;
	}
	void Meanpixelvalue()
	{
		int sum = 0;
		for (int row = 0; row < height; row++) {    //record the pixel values
			for (int col = 0; col < width; col++) {
				sum=sum+Image[row][col];
			}
		}
		sum = sum / (height * width);
		cout << "Avg. Mean Pixel Value :" << sum<<endl;
		return;
	}
	void NoBWpixels()
	{
		int B = 0;
		int W = 0;
		for (int row = 0; row < height; row++) {    //record the pixel values
			for (int col = 0; col < width; col++) 
			{
				if (Image[row][col])
					W++;
				else
					B++;
			}
		}
		cout << "Number of Black Pixels:" << B << endl;
		cout << "Number of White Pixels:" << W << endl;
		return;
	}
	void NoAvgBpixels()
	{
		int B = 0;
		int W = 0;
		for (int row = 0; row < height; row++) {    //record the pixel values
			for (int col = 0; col < width; col++)
			{
				if (!Image[row][col])
					B++;
			}
			W = B / width;
			cout << "Avg. Number of Black Pixels in row "<<row<<" :" << W << endl;
		}
		return;
	}
	void invertImage()
	{
		for (int row = 0; row < height; row++) {    //record the pixel values
			for (int col = 0; col < width; col++) 
			{
				Image[row][col] = Image[row][col] - 255;
				Image[row][col] = Image[row][col] * (-1);
			}
		}
		cout << "Image Inverted Succesfully!\n";
    }
	void save()
	{
		string filename,S;
		cout << "Enter File name:";
		cin>>filename;//"C:/Users/saadr/source/repos/datap/datap/Images/"+
		S = filename + ".PGM";
		ofstream fileOut(S.c_str(),ios_base::binary);
		fileOut << "P5\n" << "#" << filename << ".pgm\n" << "#converted PNM file\n"<<width<<" "<<height<<"\n" <<mx << "\n";
		unsigned char pixel;
		for (int row = 0; row < height; row++) { 
			for (int col = 0; col < width; col++) {
				pixel=char(Image[row][col]);
				fileOut << pixel;
			}
		}
		fileOut.close();
	}
	void ConvertToRLC()
	{
		string filename, S;
		cout << "Enter File name:";
		cin >> filename;//"C:/Users/saadr/source/repos/datap/datap/Images/"+
		S = filename + ".PGM";
		ofstream fileOut(S.c_str(), ios_base::binary);
		fileOut << width << " " << height << "\n";
		string pixel;
		LinkedList<int> L;
		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col < width; col++)
			{
				L.insert(Image[row][col]);
				//L.print();
			}
			L.insert(-1);
		}
		//L.print();
		int b = 0, w = 0,x=0;
		while (!L.empty())
		{
			//cout << x;
			int val = L.getHead();
			if (val == 255)
			{
				//cout << 1;
				x++;
				if (b == 1)
				{
					cout << x << " ";
					fileOut << x-1 << " ";
				}
				L.removehead();
				w = 1;
				b = 0;
			}
			else if (val == 0)
			{
				//cout << 0;
				int pv = 1;
				x++;
				if (b == 0)
				{
					cout << x << " ";
					fileOut <<x<< " ";
				}
				b = 1;
				w = 0;
				L.removehead();
			}
			else if (val == -1)
			{
				if (b == 1)
				{
					cout << x << " ";
					fileOut << x << " ";
				}
				cout << endl;
				b = 0;
				w = 0;
				x = 0;
				fileOut << "-1\n";
				L.removehead();
			}
		}
		fileOut.close();

	}
	void mkblack(int x,int y1, int y2)
	{
			for (int j = y1; j <= y2; j++)
			{
				Image[x][j] = 0;
			}
	}
	int reblack(int x1,int x2, int y1, int y2)
	{
        for(int i=x1;i<x2;i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				if(Image[i][j] == 255)
				return 0;
			}
		}
		return 1;
	}
	int rewhite(int x1, int x2, int y1, int y2)
	{
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				if (Image[i][j] == 0)
					return 0;
			}
		}
		return 1;
	}
	void ReadRLC(string S)
	{
		LinkedList<int> L;
		int row = 0, col = 0, r = 0, c = 0, Bn = 0;
		stringstream ss;
		ifstream file(S, ios::binary);
			Bn = 0;
		ss << file.rdbuf();   //read the third line : width and height
		ss >> c >> r;
		cout << r << "," << c << endl;
		mx=255;
		Image = new int* [r];
		for (int i = 0; i < r; ++i) 
		{
			Image[i] = new int[c];
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				Image[i][j] = 255;
			}
		}
		int pix;
			for (row = 0; row < r; row++){
				    do
					{
				    ss >> pix;
					L.insert(pix);
					//cout << pix<<" ";
					} while (pix != -1);
			}
			L.print();
			int x1 = 0;
			while (!L.empty())
			{
				int val = L.getHead();
				if (val !=-1 )
				{
					L.removehead();
					int y = L.getHead();
					L.removehead();
					mkblack(x1,val-1,y-1);
				}
				else if (val == -1)
				{
					L.removehead();
					x1++;
				}
			}



	    width = c;
		height = r;
	}
	long long int computekey()
	{
		int r = height,c = width;
		int* Ver= new int[c];
		int* Hor= new int[r];
			int B = 0;
			int W = 0;
			for (int row = 0; row < height; row++) {    //record the pixel values
				for (int col = 0; col < width; col++)
				{
					if (!Image[row][col])
						B++;
				}
				Hor[row] = B;
//				cout << B<<endl;
				B = 0;
			}
			for (int col = 0; col < width; col++)
			{
				for (int row = 0; row < height; row++) {    //record the pixel values
					if (!Image[row][col])
						B++;
				}
				Ver[col] = B;
				B = 0;
			}
			LinkedList<int> L;
			for (int col = 0; col < width; col++)
			{
				L.insert(Ver[col]);
			}
			for (int row = 0; row < height; row++)
			{  
				L.insert(Hor[row]);
			}
			long long int value=0;
			while (!L.empty())
			{
				int XX[4] = { 0 };
				string chck;
				XX[0] = L.getHead();
				L.removehead();
				XX[1] = L.getHead();
				L.removehead();
				XX[2] = L.getHead();
				L.removehead();
				XX[3] = L.getHead();
				L.removehead();

				chck = chck + to_string(XX[0]);
				chck = chck + to_string(XX[1]);
				chck = chck + to_string(XX[2]);
				chck = chck + to_string(XX[3]);
				stringstream ss;
				ss << chck;
				long long int Num;
				ss>>Num;
				value = value + Num;
				//cout << endl << value;
			}

			return value;
	}
};


class QuadTreeNode
{
public:
	QuadTreeNode* N[4];
	int* AX1;
	int* AX2;
	int* AY1;
	int* AY2;
	int X1, X2, Y1, Y2;
	int colour;
	QuadTreeNode()
	{
		colour = -1;

	}
	QuadTreeNode(int x1,int x2,int y1,int y2,int co)
	{
		colour = co;
		X1 = x1;
		X2 = x2;
		Y1 = y1;
		Y2 = y2;
		//cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
	}
	QuadTreeNode(int co)
	{
		colour = co;
		AX1 = new int[4];
		AX2 = new int[4];
		AY1 = new int[4];
		AY2 = new int[4];
	}
};
class QuadTree
{
public:
	QuadTreeNode* TreeRoot = NULL;
	void MakeTree(QuadTreeNode*& Root, IMG* A, int x1, int x2, int y1, int y2)
	{
		if (x1 == x2 && y1 == y2)
		{
			if(A->Image[x1][y1])
			Root->N[1] = new QuadTreeNode(x1,x2,y1,y2,1);
			else
				Root->N[1] = new QuadTreeNode(x1, x2, y1, y2, 2);
			return;
		}
		Root = new QuadTreeNode(3);
		int DiffX = (x1 - x2)/2;
		int DiffY = (y1 - y2)/2;
		DiffX = DiffX * -1;
		DiffY = DiffY * -1;
		cout << DiffX << " " << DiffX << endl;
		Root->AX1[0] = x1;
		Root->AX2[0] = x1+DiffX;
		Root->AY1[0] = y1;
		Root->AY2[0] = y1+DiffY;

		Root->AX1[1] = x1 + DiffX+1;
		Root->AX2[1] = x2;
		Root->AY1[1] = y1;
		Root->AY2[1] = y1 + DiffY;


		Root->AX1[2] = x1;
		Root->AX2[2] = x1 + DiffX;
		Root->AY1[2] = y1 + DiffY+1;
		Root->AY2[2] = y2;

		Root->AX1[3] = x1 + DiffX + 1;
		Root->AX2[3] = x2;
		Root->AY1[3] = y1 + DiffY + 1;
		Root->AY2[3] = y2;

		for (int i = 0; i < 4; i++)
		{

			int Bl = A->reblack(Root->AX1[i], Root->AX2[i], Root->AY1[i], Root->AY2[i]);
			int Wl = A->rewhite(Root->AX1[i], Root->AX2[i], Root->AY1[i], Root->AY2[i]);
			if (Bl == 0 && Wl == 0)
			{
			    Root->N[i] = new QuadTreeNode(3);
				MakeTree(Root->N[i], A, Root->AX1[i], Root->AX2[i], Root->AY1[i], Root->AY2[i]);
			}
			else if (Bl == 1)
			{
				Root->N[i] = new QuadTreeNode(Root->AX1[i], Root->AX2[i], Root->AY1[i], Root->AY2[i],2);
			}
			else if (Wl == 1)
			{
				Root->N[i] = new QuadTreeNode(Root->AX1[i], Root->AX2[i], Root->AY1[i], Root->AY2[i], 1);
			}

		}
	}
	int checkcolor(QuadTreeNode*& Root, int x,int y)
	{
		if (Root->colour == 1)
		{
			return 1;
		}
		else if (Root->colour == 2)
		{
			return 2;
		}
		else if (Root->colour == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << Root->AX1[i];
				cout << Root->AX2[i];
				cout << Root->AY1[i];
				cout << Root->AY2[i];
				if (Root->AX1[i] <= x && x <= Root->AX2[i] && Root->AY1[i] <= y && y <= Root->AY2[i])
				{
					cout << "hello";
					return checkcolor(Root->N[i], x, y);
				}
			}
		}
	}
	void TreeL(IMG* A, int x1, int x2, int y1, int y2)
	{
		MakeTree(TreeRoot, A, 0, A->width - 1, 0, A->height - 1);
	}
};
IMG* connectedclQ(IMG* img,IMG* img1)
{

	int X = img->height,Y=img->width;
	int x, y;
	chk1:
	cout << "Size:" << X << "," << Y << endl;
	cout << "Enter Row number:";
	cin >> x;
	cout << "Enter Column number:";
	cin >> y;
	Queue<int,int> Q,P;
	Node<int, int>* N;
	N = NULL;
	if (x > 0 && x < X - 1 && y>0 && y < Y - 1)
	{
		Q.enqueue(x, y);
		while (!Q.isEmpty())
		{
			N = Q.dequeue();
			x = N->X;
			y = N->Y;
			cout << x << "," << y<<endl;
			P.enqueue(x, y);
			img->Image[x][y] = 0;
			if (x > 0 && x < X - 1 && y>0 && y < Y - 1)
			{
				int vl = img1->Image[x][y];

				if (vl == img1->Image[x - 1][y])
				{
					if(!Q.check(x - 1, y)&&!P.check(x - 1, y)&&true)
					      Q.enqueue(x - 1, y);
				}
				if (vl == img1->Image[x - 1][y - 1])
				{
					if (!Q.check(x - 1, y - 1)&& !P.check(x - 1, y - 1))
						Q.enqueue(x - 1, y - 1);

				}
				if (vl == img1->Image[x - 1][y + 1])
				{
					if (!Q.check(x - 1, y + 1)&& !P.check(x - 1, y + 1))
						Q.enqueue(x - 1, y + 1);

				}
				if (vl == img1->Image[x][y - 1])
				{
					if (!Q.check(x, y - 1)&& !P.check(x, y - 1))
						Q.enqueue(x, y - 1);

				}
				if (vl == img1->Image[x][y + 1])
				{
					if (!Q.check(x, y + 1)&& !P.check(x, y + 1))
						Q.enqueue(x, y + 1);

				}
				if (vl == img1->Image[x + 1][y - 1])
				{
					if (!Q.check(x + 1, y - 1)&& !P.check(x + 1, y - 1))
						Q.enqueue(x + 1, y - 1);

				}
				if (vl == img1->Image[x + 1][y + 1])
				{
					if (!Q.check(x + 1, y + 1)&& !P.check(x + 1, y + 1))
						Q.enqueue(x + 1, y + 1);

				}
				if (vl == img1->Image[x + 1][y])
				{
					if (!Q.check(x + 1, y)&& !P.check(x + 1, y))
						Q.enqueue(x + 1, y);
				}

			}
		}
	}
	else
	{
		cout << "Input is out of range!.\n";
		goto chk1;
	}
	return img;
}
IMG* connectedclS(IMG* img, IMG* img1)
{

	int X = img->height, Y = img->width;
	int x, y;
chk1:
	cout << "Size:" << X << "," << Y << endl;
	cout << "Enter Row number:";
	cin >> x;
	cout << "Enter Column number:";
	cin >> y;
	stack<int, int> Q, P;
	Node<int, int>* N;
	N = NULL;
	if (x > 0 && x < X - 1 && y>0 && y < Y - 1)
	{
		Q.push(x, y);
		while (!Q.isEmpty())
		{
			N = Q.dequeue();
			x = N->X;
			y = N->Y;
			P.push(x, y);
			img->Image[x][y] = 0;
			if (x > 0 && x < X - 1 && y>0 && y < Y - 1)
			{
				int vl = img1->Image[x][y];

				if (vl == img1->Image[x - 1][y])
				{
					if (!Q.check(x - 1, y) && !P.check(x - 1, y))
						Q.push(x - 1, y);
				}
				if (vl == img1->Image[x - 1][y - 1])
				{
					if (!Q.check(x - 1, y - 1) && !P.check(x - 1, y - 1))
						Q.push(x - 1, y - 1);

				}
				if (vl == img1->Image[x - 1][y + 1])
				{
					if (!Q.check(x - 1, y + 1) && !P.check(x - 1, y + 1))
						Q.push(x - 1, y + 1);

				}
				if (vl == img1->Image[x][y - 1])
				{
					if (!Q.check(x, y - 1) && !P.check(x, y - 1))
						Q.push(x, y - 1);

				}
				if (vl == img1->Image[x][y + 1])
				{
					if (!Q.check(x, y + 1) && !P.check(x, y + 1))
						Q.push(x, y + 1);

				}
				if (vl == img1->Image[x + 1][y - 1])
				{
					if (!Q.check(x + 1, y - 1) && !P.check(x + 1, y - 1))
						Q.push(x + 1, y - 1);

				}
				if (vl == img1->Image[x + 1][y + 1])
				{
					if (!Q.check(x + 1, y + 1) && !P.check(x + 1, y + 1))
						Q.push(x + 1, y + 1);

				}
				if (vl == img1->Image[x + 1][y])
				{
					if (!Q.check(x + 1, y) && !P.check(x + 1, y))
						Q.push(x + 1, y);
				}

			}
		}
	}
	else
	{
		cout << "Input is out of range!.\n";
		goto chk1;
	}
	return img;
}
// Driver code
int main()
{
	string Path = "C:/Users/saadr/source/repos/datap/datap/Images/apple-18.PGM";
	string Path2 = "C:/Users/saadr/source/repos/datap/datap/Images/RRR.PGM";
	IMG* A=new IMG;
	A->Read(Path);
	int q1=1, q2=1;
	while (q1 != 0)
	{
	chck1:
		cout << "Press 1 to run solution of Q1.\nPress 2 to run solution of Q2.\nPress 3 to run solution of Q3.\nPress 4 to run solution of Q4.\nPress 5 to run solution of Q5.\nPress 6 to run solution of Q6.\nPress 0 to exit.\nChoice:";
		cin >> q1;
		if (q1 == 1)
		{
		chck2:
			cout << "Press 1 to run solution of Q1.a.\nPress 2 to run solution of Q1.b.\nPress 3 to run solution of Q1.c.\nPress 4 to run solution of Q1.d.\nPress 0 to exit.\nChoice:";
			cin >> q2;
			if (q2 == 1)
			{
				A->Meanpixelvalue();
				goto chck2;
			}
			else if (q2 == 2)
			{
				A->NoBWpixels();
				goto chck2;
			}
			else if (q2 == 3)
			{
				A->NoAvgBpixels();
				goto chck2;
			}
			else if (q2 == 4)
			{
				A->invertImage();
				goto chck2;
			}
			else if (q2 == 0)
			{
				goto chck1;
			}
			else
			{
				cout << "Wrong Input!\n";
				goto chck2;
			}

		}
		else if (q1 == 2)
		{
			IMG* B = new IMG;
			B->height = A->height;
			B->width = A->width;
			B->mx = A->mx;
			B->Image = new int* [B->height];
			for (int i = 0; i < B->height; ++i) {
				B->Image[i] = new int[B->width];
			}
			for (int row = 0; row < B->height; row++)
			{
				for (int col = 0; col < B->width; col++)
				{
					B->Image[row][col] = 255;
				}
			}
			B = connectedclQ(B, A);
			B->save();
		}
		else if (q1 == 3)
		{
			IMG* B = new IMG;
			B->height = A->height;
			B->width = A->width;
			B->mx = A->mx;
			B->Image = new int* [B->height];
			for (int i = 0; i < B->height; ++i) {
				B->Image[i] = new int[B->width];
			}
			for (int row = 0; row < B->height; row++)
			{
				for (int col = 0; col < B->width; col++)
				{
					B->Image[row][col] = 255;
				}
			}
			B = connectedclQ(B, A);
			B->save();
		}
		else if (q1 == 4)
		{
		chck3:
			cout << "Press 1 to run solution of Q4.a.\nPress 2 to run solution of Q4.b.\nPress 3 to run solution of Q4.c.\nPress 4 to run solution of Q4.d.\nPress 0 to exit.\nChoice:";
			cin >> q2;
			if (q2 == 1)
			{
				A->ConvertToRLC();
				goto chck3;
			}
			else if (q2 == 2)
			{
				IMG* B = new IMG;
				B->ReadRLC(Path2);
				B->save();
				goto chck3;
			}
			else if (q2 == 3)
			{
				IMG* B = new IMG;
				B->ReadRLC(Path2);
				B->NoBWpixels();
				goto chck3;
			}
			else if (q2 == 4)
			{
				IMG* B = new IMG;
				B->ReadRLC(Path2);
				B->invertImage();
				goto chck3;
			}
			else if (q2 == 0)
			{
				goto chck3;
			}
			else
			{
				cout << "Wrong Input!\n";
				goto chck3;
			}

		}
		else if (q1 == 5)
		{
		chck4:
			cout << "Press 1 to run solution of Q5.a.\nPress 2 to run solution of Q5.b.\nPress 3 to run solution of Q5.c.\nPress 4 to run solution of Q5.d.\nPress 0 to exit.\nChoice:";
			cin >> q2;
			if (q2 == 1)
			{
				QuadTree Q;
				Q.TreeL(A, 0, A->width - 1, 0, A->height - 1);
				int xx, yy;
				cout << "Enter value between 0-255.\n";
				cout << "X:";
				cin >> xx;
				cout << "Y:";
				cin >> yy;
				int col = Q.checkcolor(Q.TreeRoot, xx, yy);
				cout << "Colour:" << col << endl;
				goto chck4;
			}
			else if (q2 == 2)
			{
				IMG* B = new IMG;
				B->ReadRLC(Path2);
				B->save();
				goto chck4;
			}
			else if (q2 == 3)
			{
				IMG* B = new IMG;
				B->ReadRLC(Path2);
				B->NoBWpixels();
				goto chck4;
			}
			else if (q2 == 4)
			{
				IMG* B = new IMG;
				B->ReadRLC(Path2);
				B->invertImage();
				goto chck4;
			}
			else
			{
				cout << "Wrong Input!\n";
				goto chck4;
			}
		}
		else if (q1 == 6)
		{
			int Siz = 500;
			HashT<long long int> Tab(500);
			IMG* ARR = new IMG[Siz];
			string sarr[500];
			cout << "working....!\n";
			for (int i = 0; i < Siz; i++)
			{
				string P = "C:/Users/saadr/OneDrive/Desktop/Image database/";
				sarr[i] = sarr[i] + "image";
				if (i < 9)
				{
					string chck = to_string(i + 1);
					sarr[i] = sarr[i] + '0';
					sarr[i] = sarr[i] + '0';
					sarr[i] = sarr[i] + chck;
					sarr[i] = sarr[i] + ".PGM";
				}
				else if (i < 99)
				{
					string chck = to_string(i + 1);
					sarr[i] = sarr[i] + '0';
					sarr[i] = sarr[i] + chck;
					sarr[i] = sarr[i] + ".PGM";
				}
				else
				{
					string chck = to_string(i + 1);
					sarr[i] = sarr[i] + chck;
					sarr[i] = sarr[i] + ".PGM";
				}
				P = P + sarr[i];
				ARR[i].Read(P);
				Tab.insertElement(ARR[i].computekey(), sarr[i]);
			}
			Tab.displayHashTable();

			goto chck1;
		}
		else if (q1 == 0)
		{
			break;
		}
		else
		{
			cout << "Wrong Input!\n";
			goto chck3;
		}

	}
	return 0;



}