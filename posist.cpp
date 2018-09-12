#include<bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
static int nn =0;
string hashvalfun(string name,float value,int id)
{
    stringstream stream,ss;
	stream << fixed << setprecision(2) << value;
	string valinstr = stream.str();
    ss << id;
    string idstr = ss.str();
	string hash=idstr+valinstr+name;
    return hash;
}
struct data{
    int ownerid;
	string ownername;
	float value;

};
struct Node{
	time_t dt;
	struct data d;
	int nodeNum;
	int nodeId;
	Node *refNodeId;
	vector<int> childNodeId;
	vector<Node*> ChildrefNodeId;
	string genesisRefNodeId;
	string hashval;

};
class user
{
    int userid;
	string uname;
    public:
    void adduser()
    {
        cout<<"Enter User Name :";
        cin>>uname;
        cout<<"Enter Id : ";
        cin>>userid;
   		cout<<endl;

    }
    void dun()
    {
        cout<<uname<<" ";
    }
    string urname()
    {
        return uname;
    }
    int uid()
    {
        return userid;
    }

};
Node* createnode()
    {return (Node*)malloc(sizeof(Node));}
void insertnode(user u,float val)
{
    Node *temp=createnode();
    temp->timestamp=time(0);
    temp->d.ownerid=u.uid();
    temp->d.ownername=u.urname();
    cout<<"enter value float";
    cin>>temp->d.value;
    temp->d.hashval=hashvalfun(temp->d.ownername,temp->d.value,temp->d.ownerid);
    temp->nodeNum=nn++;

}
void ownership(vector<Owner*> &owners,Owner *currOwner, vector<Node*> &v){
	cout<<"Enter nodeId and userId: "<<endl;
	int id,userId;
	cin>>id>>userId;
	bool f=false;
	for(int i=0;i<v.size();i++){
		if(v[i]->nodeId==id){
			if(query4(owners,currOwner,v)){


				Node *np=v[i];
				for(int k=0;k<owners.size();k++){
					if(owners[k]->ownerNum==userId){
						np->owner=owners[k];
						f=true;
						break;
					}
				}

			}else{
				cout<<"you are not the owner of this node"<<endl;
				return;
			}
			break;
		}
	}
	if(f){
		cout<<"node Owner changed"<<endl;
	}else{
		cout<<"node not found"<<endl;
	}
}
int main()
{
  	user su;
  	su.adduser();
  	vector<user> userlist;
  	user u;
  	int num=0,nOwners=0;
    vector<vector<Node*> > set;
    vector<Node*> v;
    int q;

    Owner *currOwner;
    bool f=false;
  	while(1)
{
    int ch;
    cout<<"1 Add User"<<endl;
    cout<<"2 change owner"<<endl;
    cout<<"Enter choice";
    cin>>ch;
     vector<user> ::iterator it;
    switch(ch)
    {


        case 1:
		{
		    cout << "Enter Details:  ";
			u.adduser();
			userlist.push_back(u);
			break;

		}
    }
}
