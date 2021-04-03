#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<bits/stdc++.h> 
using namespace std;
class goods;

string o;
int cities[100];
string dispatch[100];
int dd=0,citycount=0;
int good,good1;
//int ary[100][100],completed[100];
int n,dist=0,org;
//vector <string> city;
string s;
char a='y';
//void mindist();


class route
{
	int ary[100][100],completed[100];
	vector <string> point;
	public:
		void setRoute();
		void display();
		void shortroute(goods*);
		void mindist(int,goods*);
		int least(int);
		friend class goods;
};


class goods
{
	public:
	int flag1;
	string destination;
	int id;
	void setGoods(goods*);
	void findcount(goods g[100])
	{
		for(int l=0;l<dd;l++)
		{
			for(int j=0;j<good1;j++)
			{
				if(g[j].destination==dispatch[l])
				{
					cities[l]=cities[l]+1;
				}
			}
		}
	}
};
void route::setRoute()
{
	char a='y';
	int i,j;
	while(a=='y'||a=='Y')
	{
		citycount++;
		cout<<"ENTER THE CITY\t";
		cin>>s;
		point.push_back(s);
		
		
		
		cout<<"\nPress y to continue\t";
		cin>>a;
	}	
	n=point.size();
	
	cout<<"\nEnter the Distance between the cities\n";

	for(i=0;i <point.size();i++)
	{
		

		for( j=0;j < point.size();j++)
			
			if(i!=j)
			{
				if(i<j)
				{
				cout<<"\nEnter the distance between\t"<<point[i]<<"\tto\t"<<point[j]<<"\n";
				cin>>ary[i][j];
				}
				else
				{
					ary[i][j]=ary[j][i];
				}
			}
			else
			ary[i][j]=0;

		completed[i]=0;
		


}
}

void route::shortroute(goods g[100])
{
	
	int p,v;
	int i,j;
	
	
	
  	cout<<"ENTER THE ORIGIN";
  	cin>>o;
  	
  	cout<<"\n\nTHE DISTANCE BETWEEN THE CITIES:";


	cout<<"\n";
	for(int hg=0;hg<point.size();hg++)
		cout<<"\t"<<point[hg];
		cout<<"\n";
	for( i=0;i <point.size();i++)
	{
		
		cout<<point[i];

		for(j=0;j <point.size();j++)
			cout<<"\t"<<ary[i][j];
		cout<<"\n";
	}
	
	cout<<"\n\nTHE SHORTEST PATH IS:\n";
	
  	for(v=0;v<point.size();v++)
  	{
	  
  		if(point[v]==o)
  		{
		  
  		   p=v+1;
  		}
   }
  	org=p;
  	p=p-1;
	mindist(p,g);
	cout<<"\n\nTHE DISTANCE COVERED BY THE PATH IS "<<dist;
  //return 0;
}

void route:: mindist(int city,goods g[100])
{
	int i,j=0,ncity,co=0;

	completed[city]=1;
	//citi
	dispatch[dd]=point[city];
		dd++;
	cout<<point[city]<<"--->";
		
	ncity=least(city);

	if(ncity==90)
	{
		ncity=org;
		
		cout<<point[ncity-1];
		dist+=ary[city][ncity-1];
		//cout<<"number of goods dispatched:"<<good;
		
		

		return;
}

	mindist(ncity,g);
}
int route::least(int c)
{
	int i,nc=90;
	int min=90,kmin;

	for(i=0;i < point.size();i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=90)
		dist+=kmin;

	return nc;
}


void goods::setGoods(goods g[100])
{
	cout<<"\n\tENTER THE ID OF THE ITEM:";
	cin>>id;
	cout<<"ENTER THE DESTINATION ";
	cin>>destination;
	flag1=1;
}


int main()
{
	goods g[80];
	route r,r1;
	int countgoods[100];
	int choice=0;
	int i;
	ifstream infile;
	fstream f;
	for(int l=0;l<dd;l++)
		{
			cities[l]=0;
		}
	while(choice!=5)
	{
	cout<<"**\t\tFINDING THE SHORTEST PATH**";
	cout<<"\n\t1.SET ROUTE";
	cout<<"\n\t2.GET DISPATCHING DETAILS";
	cout<<"\n\t3.FIND THE SHORTEST PATH";
	cout<<"\n\t4.DISPATCHED ITEMS\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			r.setRoute();
					
                      f.open("route1059.dat",	ios::out|ios::app|ios::binary);
                      f.write( (char*)&r, sizeof(route) );
            		  f.close();
            break;
            
        case 2:
        	
        	cout<<"Enter the total number of goods:";
			cin>>good;
			good1=good;
			for(int b=0;b<good;b++)
			{
				g[b].setGoods(g);
			}
			break;
        case 3:
        infile.open("route1059.dat",ios::in|ios::binary);
	 	  while(infile)
           {
                   infile.read((char*)&r1,sizeof(route));
                    
            }
                //Num=i;
            infile.close();
	                 
		r1.shortroute(g);
		break;
		case 4:
			g[1].findcount(g);
			cout<<"CITY\tNO.OF DISPATCHED ITEMS\n";
			for(int l=0;l<dd;l++)
				cout<<dispatch[l]<<"\t"<<cities[l]<<"\n";
		break;
		case 5:
			exit(1);
			default:
				cout<<"\ninvalid option";
	}
	
	
	
	
}
	
		
       
	   
	
}
	
	
	

 
