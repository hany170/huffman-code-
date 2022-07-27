#include<iostream>
#include<stdio.h>
using namespace std;
class CTNode
{
public:
	int freq;
	char* sympol;
	CTNode* pLeft;
	CTNode* pRight;
};
class CNode2
{
public:
	int* info;
	char ch;
	int save_ct;
	CNode2* pnext2;
};

class CNode
{
public:
	int freq;
	char* sympol;
	CNode* pnext;
	CTNode* pDown;
};
class clist
{
public:
	CNode* pHead;
	CNode* ptail;
public:
	clist()
	{
		pHead = NULL;
		ptail = NULL;
	}
	void attach(CNode* pnn)
	{
		if (pHead == NULL)
		{
			pHead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	~clist()
	{
		CNode* ptrav = pHead;
		while (ptrav != NULL)
		{
			pHead = pHead->pnext;
			delete ptrav;
			ptrav = pHead;
		}
	}
};
class clist2
{
public:
	CNode2* pHead;
	CNode2* ptail;
public:
	clist2()
	{
		pHead = NULL;
		ptail = NULL;
	}
	void attach(CNode2* pnn)
	{
		if (pHead == NULL)
		{
			pHead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext2 = pnn;
			ptail = pnn;
		}
	}
	~clist2()
	{
		CNode2* ptrav = pHead;
		while (ptrav != NULL)
		{
			pHead = pHead->pnext2;
			delete ptrav;
			ptrav = pHead;
		}
	}
};
void sort(clist & L)
{
	clist L2;
	int ct2=0;
	int z = 0,f=0,i,E=0;
	int min = 99999,ct=0;
	CNode* ptrav=L.pHead, * pnn,*ptrav2=NULL,*pb=NULL,*ptemp=NULL,*pb2=NULL;
	ptrav = L.pHead;
	while (ptrav != NULL)
	{
		ct2++;
		pnn = new CNode;
		pnn->freq = ptrav->freq;
		for (i = 0; ptrav->sympol[i] != '\0'; i++)
		{
			ct++;
		}
		pnn->sympol = new char[ct];
		for (i = 0; ptrav->sympol[i] != '\0'; i++)
		{
			pnn->sympol[i] = ptrav->sympol[i];
		}
		pnn->sympol[i] = '\0';
		pnn->pnext = NULL;
		pnn->pDown = ptrav->pDown;
		if (L2.pHead == NULL)
		{
			L2.pHead = pnn;
			L2.ptail = pnn;
		}
		else
		{
			if (ct2 > 2)
			{
				
				if (pnn->freq < L2.pHead->freq)
				{
					pnn->pnext = L2.pHead;
					L2.pHead = pnn;
				}
				else
				{

					ptrav2 = L2.pHead->pnext;
					pb = L2.pHead;
					while (ptrav2 != NULL)
					{
						if (pnn->freq < ptrav2->freq)
						{
							pnn->pnext = ptrav2;
							pb->pnext = pnn;
							f = 1;
							break;
						}
						pb = ptrav2;
						ptrav2 = ptrav2->pnext;

					}
					if (f == 0)
					{
						L2.ptail->pnext = pnn;
						L2.ptail = pnn;
						L2.ptail->pnext = NULL;
					}
					f = 0;
				}
			}
			else
			{
				if (pnn->freq < L2.pHead->freq)
				{
					pnn->pnext = L2.pHead;
					
					L2.pHead = pnn;
					L2.ptail = pnn->pnext;
					L2.ptail->pnext = NULL;
					
				}
				if (pnn->freq > L2.pHead->freq && L2.pHead->pnext == NULL)
				{
					L2.pHead->pnext = pnn;
					L2.ptail = pnn;

				}
				
				//if (pnn->freq == L2.pHead->freq)
				{
					//L2.ptail->pnext = pnn;
					//L2.ptail = pnn;
					//L2.ptail->pnext = NULL;
				}
				//cout << "L2.next : " << L2.pHead->pnext->sympol << endl;
			}
		}
		ptrav2 = L2.pHead;
		while (ptrav2 != NULL)
		{
			//cout << "L2  " << ptrav2->sympol << endl;
			ptrav2 = ptrav2->pnext;
		}
		ptrav = ptrav->pnext;
	}
	L.pHead = NULL;
	L.pHead = L2.pHead;
	L.ptail = L2.ptail;
	L2.pHead = NULL;
	L2.ptail = NULL;

}
void leefL(clist& L, CTNode* temp)
{
	int i;
	CNode* ptrav=L.pHead;
	for (i = 0; ptrav->sympol[i] != '\0'; i++)
	{
		temp->pLeft->sympol[i] = ptrav->sympol[i];
	}
	temp->pLeft->sympol[i] = '\0';
	temp->pLeft->pLeft = NULL;
	temp->pLeft->pRight = NULL;
	temp->pLeft->freq = ptrav->freq;
}
void leefR(clist& L, CTNode* temp)
{
	int i;
	CNode* ptrav=L.pHead;
	for (i = 0; ptrav->pnext->sympol[i] != '\0'; i++)
	{
		temp->pRight->sympol[i] = ptrav->pnext->sympol[i];
	}
	temp->pRight->sympol[i] = '\0';
	temp->pRight->pLeft = NULL;
	temp->pRight->pRight = NULL;
	temp->pRight->freq = ptrav->pnext->freq;
}
void rootL(clist& L, CTNode* temp)
{
	temp->pLeft = new CTNode;
	CNode* ptrav = L.pHead;
	temp->pLeft = ptrav->pDown;
	
}
void rootR(clist& L, CTNode* temp)
{
	temp->pRight = new CTNode;
	CNode* ptrav = L.pHead->pnext;
	temp->pRight = ptrav->pDown;
	
}
void main()
{
	clist L;
	CNode* pnn, * ptrav;
	CTNode* temp = NULL;
	char* str;
	char* decomp;
	int n, i;
	cin >> n;
	str = new char[n];
	for (i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	str[i] = '\0';


	decomp = new char[n];
	char a;
	int ct = 0;
	for (i = 1; i < 128; i++)
	{
		char a = i;
		for (int k = 0; str[k] != '\0'; k++)
		{
			if (a == str[k])
			{
				ct++;
			}
		}
		if (ct > 0)
		{
			pnn = new CNode;
			pnn->freq = ct;
			pnn->sympol = new char[1];
			pnn->sympol[0] = a;
			pnn->sympol[1] = '\0';
			pnn->pnext = NULL;
			L.attach(pnn);
		}
		ct = 0;
	}
	clist2 L2;
	int z = 0, f = 0, ct2 = 0, ct3 = 0;
	int min = 99999;
	CNode* ptrav2 = NULL, * pb = NULL, * pb2 = NULL;
	
	
	sort(L);
	ptrav2 = L.pHead;
	while (ptrav2 != NULL)
	{
		cout << ptrav2->sympol << ' ' << ptrav2->freq << endl;
		ptrav2->pDown = NULL;
		ptrav2 = ptrav2->pnext;
	}
	
	while (L.pHead->pnext != NULL)
	{
		ptrav2 = L.pHead;
		//cout << "Ptrav2  " <<ptrav2->sympol<<endl;
		temp = new CTNode;
		temp->pLeft = new CTNode;
		temp->pRight = new CTNode;
		temp->freq = ptrav2->freq + ptrav2->pnext->freq;
		ct = 0;
		ct2 = 0;
		for (i = 0; ptrav2->sympol[i] != '\0'; i++)
		{
			ct++;
		}

		for (i = 0; ptrav2->pnext->sympol[i] != '\0'; i++)
		{
			ct2++;
		}
		//cout << "counts : " << ct << ' ' << ct2 << endl;
		ct3 = ct2 + ct;
		temp->sympol = new char[ct3];
		int k = 0;
		for (i = 0; ptrav2->sympol[i] != '\0'; i++)
		{
			temp->sympol[k] = ptrav2->sympol[i];
			k++;
		}
		for (i = 0; ptrav2->pnext->sympol[i] != '\0'; i++)
		{
			temp->sympol[k] = ptrav2->pnext->sympol[i];
			k++;
		}
		temp->sympol[k] = '\0';
		if (ct == 1)
		{
			temp->pLeft->sympol = new char[ct];
			leefL(L, temp);
		}
		else
		{
			rootL(L, temp);
		}

		if (ct2 == 1)
		{
			temp->pRight->sympol = new char[ct2];
			leefR(L, temp);
		}
		else
		{

			rootR(L, temp);
		}
		pnn = new CNode;
		pnn->freq = temp->freq;
		pnn->sympol = new char[ct3];
		for (i = 0; temp->sympol[i] != '\0'; i++)
		{
			pnn->sympol[i] = temp->sympol[i];
		}
		pnn->sympol[i] = '\0';
		pnn->pDown = new CTNode;
		pnn->pDown = temp;
		pnn->pnext = ptrav2->pnext->pnext;
		L.pHead = pnn;
		ptrav2->pnext->pnext = NULL;
		ptrav = L.pHead;
		//while (ptrav != NULL)
		//{
			//cout << "LAL " << ptrav->sympol << endl;
			//ptrav = ptrav->pnext;
		//}
		sort(L);
		ct = 0;
		ct2 = 0;
		
	}
	

	CTNode* Tptrav = L.pHead->pDown;
	ptrav2 = L.pHead;
	int F;
	CNode2* pT;
	for (i = 0; ptrav2->sympol[i] != '\0'; i++)
	{

		Tptrav = L.pHead->pDown;
		ct = 0;
		for (;;)
		{
			if (Tptrav->pLeft != NULL && Tptrav->pRight != NULL)
			{
				for (int k = 0; Tptrav->pLeft->sympol[k] != NULL; k++)
				{
					if (ptrav2->sympol[i] == Tptrav->pLeft->sympol[k])
					{
						F = 0;
					}
				}
				for (int k = 0; Tptrav->pRight->sympol[k] != NULL; k++)
				{
					if (ptrav2->sympol[i] == Tptrav->pRight->sympol[k])
					{
						F = 1;
					}
				}
				if (F == 0)
				{
					Tptrav = Tptrav->pLeft;
				}
				else
				{
					Tptrav = Tptrav->pRight;
				}
				ct++;
			}
			else
			{
				break;
			}
		}
		pT = new CNode2;
		pT->save_ct = ct;
		pT->info = new int[ct];
		pT->pnext2 = NULL;
		int j = 0;
		Tptrav = L.pHead->pDown;
		for (;;)
		{
			pT->ch = ptrav2->sympol[i];
			if (Tptrav->pLeft != NULL && Tptrav->pRight != NULL)
			{
				for (int k = 0; Tptrav->pLeft->sympol[k] != NULL; k++)
				{
					if (ptrav2->sympol[i] == Tptrav->pLeft->sympol[k])
					{
						F = 0;
					}
				}
				for (int k = 0; Tptrav->pRight->sympol[k] != NULL; k++)
				{
					if (ptrav2->sympol[i] == Tptrav->pRight->sympol[k])
					{
						F = 1;
					}
				}
				if (F == 0)
				{
					pT->info[j] = 0;
					j++;
					Tptrav = Tptrav->pLeft;
				}
				else
				{
					pT->info[j] = 1;
					j++;
					Tptrav = Tptrav->pRight;
				}

			}
			else
			{
				break;
			}
		}
		L2.attach(pT);
		F = 1;
	}
	pT = L2.pHead;
	while (pT != NULL)
	{
		cout << pT->ch << endl;
		for (i = 0; i < pT->save_ct; i++)
		{
			cout << pT->info[i] << '|';
		}
		cout << endl;
		pT = pT->pnext2;
	}


	//phase II
	char Temp2;
	char compressed[1000];
	int k = 0,ctC=0,ctm=0;
	char Temp = 0;
	char m=1;
	ct = 0;
	int ctcomp = 0;
	pT = L2.pHead;
	for (i = 0; str[i] != '\0'; i++)
	{
		pT = L2.pHead;
		while (pT != NULL)
		{
			if (str[i] == pT->ch)
			{
				break;
			}
			pT = pT->pnext2;
		}
		if (pT != NULL)
		{
			for (int j = 0; j < pT->save_ct; j++)
			{
				m = pT->info[j];
				Temp = Temp | (m << ct);
				ct++;
				if (ct == 8)
				{

					compressed[k] = Temp;
					ctcomp++;
					Temp = 0;
					ct = 0;
					k++;
					ctC++;
				}
			}
		}
		if (str[i + 1] == '\0' && ct > 0 && ct < 8)
		{
			compressed[k] = Temp;
			k++;
			ctcomp++;
			ctm = ct;
			ctC++;
		}
	
	}
	compressed[k] = '\0';
	cout << compressed<<endl;
	//Encode
	clist LE;
	m = 0;
	char G;
	ct = 0;
	F = 0;
	Temp = 1;
	int y = 0;
	for (i = 0; i < ctC; i++)
	{
		ct = 0;
		for (k = 0; k < 8; k++)
		{
			G = compressed[i] & (m << ct);
			m = 1;
			if (G != 0)
			{
				pnn = new CNode;
				pnn->freq = 1;
				pnn->pDown = NULL;
				pnn->pnext = NULL;
				pnn->sympol =NULL;
				LE.attach(pnn);
			}
			if(G == 0)
			{ 
				
				pnn = new CNode;
				pnn->freq = 0;
				pnn->pDown = NULL;
				pnn->pnext = NULL;
				pnn->sympol = NULL;
				LE.attach(pnn);
			}
			pT = L2.pHead;
			CNode* ptravE = LE.pHead;
			int j = 0;
			ct2 = 0;
			while (pT != NULL)
			{
				ptravE = LE.pHead;
				while (ptravE != NULL)
				{
					if (ptravE->freq == pT->info[j])
					{
						ct2++;
					}
					else
					{
						break;
					}
					j++;
					ptravE = ptravE->pnext;
				}
				if (ct2 == pT->save_ct)
				{
					decomp[y] = pT->ch;
					LE.pHead = NULL;
					y++;
					break;
				}
				ct2 = 0;
				pT = pT->pnext2;
				j = 0;
			}
			if (ctm != 0)
			{
				if (i + 1 == ctC && k == ctm)
				{
					break;
				}
			}
			ct++;
		}
	}
	decomp[y] = '\0';
	cout << endl;
	cout << "ctcomp : " << ctcomp << endl;
	cout << decomp;
}