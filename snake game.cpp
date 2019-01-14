#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<fstream>
using namespace std;
char a[12][10]={' '};
struct food
{
	int a;
	int b;
	
};
struct poison
{
	int a;
	int b;
};
struct node
{
	int x;
	int y;
	char value;
	node *link;
};
struct node *head=NULL,*tail=NULL;
void snake()
{
	node *temp;
	int y=3;
	int m=4;
	while(m)
	{
    temp=new node;
	temp->x=y;
	temp->y=2;
	if(head==NULL)
	{
		temp->value='X';
		temp->link=NULL;
		head=temp;
		tail=temp;
		y++;
	}
	else
	{
		temp->value='#';
		temp->link=NULL;
		tail->link=temp;
		tail=temp;
		y++;
	}
	m--;
}
}
void move()
{
	struct node *temp,*ptr,*ptr1;
	int a,b,c,d;
	temp=head;
	ptr=temp;
	ptr1=temp->link;
	while(ptr1!=NULL)
	{
		if(ptr==temp)
		{
		a=ptr1->x;
		b=ptr1->y;
		ptr1->x=ptr->x;
		ptr1->y=ptr->y;
	 	ptr=ptr->link;
		ptr1=ptr->link;
		}
		else
		{
		c=ptr1->x;
		d=ptr1->y;
		ptr1->x=a;
		ptr1->y=b;
		a=c;
		b=d;
		ptr1=ptr1->link;
		}	
	}
}

void add(int f)
{
	node *temp1;
	temp1=new node;
	if(f==1)
	{
	temp1->x=tail->x-1;
	temp1->y=tail->y;
    }
    else
    {
	temp1->x=tail->x-1;
	temp1->y=tail->y;
	}
	temp1->value='$';
	tail->link=temp1;
	temp1->link=NULL;
	tail=temp1;
}
void sub()
{
	node *temp;
	temp=head;
	while(temp->link!=tail)
	{
		temp=temp->link;
	}
	temp->link=NULL;
	tail=temp;
}
void display(struct node *head,struct food *fi,struct poison *p)
{
	
	int i,j,c=0,d=0,z=0,g=0,f=0;
	struct node *t;
	for(i=0;i<12;i++)
	{
		for(j=0;j<10;j++)
		{
			if(i==0||j==0||i==11||j==9)
			{
				a[i][j]='*';
			}
			else
			{
				a[i][j]=' ';
			}
		}
	}
a[fi->a][fi->b]='F';
a[p->a][p->b]='P';
	t=head;
	while(t!=NULL)
	{
	a[t->x][t->y]=t->value;
	t=t->link;
    }
    for(i=0;i<12;i++)
    {
    	for(j=0;j<10;j++)
    	{
    		cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
		
}
void movement(struct node *head,struct food *fi,struct poison *p)
{
	char str;
	char a[12][10];
	struct node *t,*mark;
	int i,j,c=0,d=0,z=0,g=0,f=0;
cin>>str;
	while(str!='q')
	{
	f=0;
	t=head;	
	a[tail->x][tail->y]=' ';
    if(str=='u')
	{
		if(head->x==1)
		{
			move();
			head->x=10;
		}
		else
		{
		    move();
			head->x=head->x-1;
		}
		if((head->x)==fi->a && (head->y)==fi->b)
		{
			f=1;
			add(f);
			fi->a=rand()%(10-3)+1;
		    fi->b=rand()%(10-3)+1;
	        a[fi->a][fi->b]='F';
		}
		if((head->x)==p->a && (head->y)==p->b)
		{
			a[tail->x][tail->y]=' ';
			sub();
			p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
	        if(p->a==fi->a && p->b==fi->b)
	        {
	        p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
			}
			
		}
		while(t!=NULL)
		{
	   	a[t->x][t->y]=t->value;
		t=t->link;
		}
	}
    else if(str=='l')
	{
		if(head->y==1)
		{
			move();
			head->y=8;
			
		}
		else
		{
		    move();
			head->y=head->y-1;
		}
		if((head->x)==fi->a && (head->y)==fi->b)
		{
			f=1;
			add(f);
			fi->a=rand()%(10-3)+1;
	        fi->b=rand()%(10-3)+1;
	        a[fi->a][fi->b]='F';
     	}
		 if((head->x)==p->a && (head->y)==p->b)
		{
			a[tail->x][tail->y]=' ';
			sub();
			p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
	        if(p->a==fi->a && p->b==fi->b)
	        {
	        p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
			}
		}
		while(t!=NULL)
		{
	   	a[t->x][t->y]=t->value;
		t=t->link;
		}
	}
	else if(str=='r')
	{
		if(head->y==8)
		{
			move();
			head->y=1;
			
		}
		else
		{
		    move();
			head->y=head->y+1;
		}
		if((head->x)==fi->a && (head->y)==fi->b)
		{
			f=1;
			add(f);
			fi->a=rand()%(10-3)+1;
	        fi->b=rand()%(10-3)+1;
	        a[fi->a][fi->b]='F';
		}
		if((head->x)==p->a && (head->y)==p->b)
		{
			a[tail->x][tail->y]=' ';
			sub();
			p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
	        if(p->a==fi->a && p->b==fi->b)
	        {
	        p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
			}
		}
		while(t!=NULL)
		{
	   	a[t->x][t->y]=t->value;
		t=t->link;
		}
	}
	else if(str=='d')
	{
		if(head->x==10)
		{
			move();
			head->x=1;
		}
		else
		{
		    move();
			head->x=head->x+1;
		}
		if((head->x)==fi->a && (head->y)==fi->b)
		{
			f=2;
			add(f);
			fi->a=rand()%(10-3)+1;
	        fi->b=rand()%(10-3)+1;
	        a[fi->a][fi->b]='F';
		}
		if((head->x)==p->a && (head->y)==p->b)
		{
			a[tail->x][tail->y]=' ';
			sub();
			p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
	        if(p->a==fi->a && p->b==fi->b)
	        {
	        p->a=rand()%(10-3)+1;
	        p->b=rand()%(10-3)+1;
	        a[p->a][p->b]='P';
			}
		}
		while(t!=NULL)
		{
	   	a[t->x][t->y]=t->value;
		t=t->link;
		}
	}
	mark=head->link;
	while(mark!=NULL)
	{
	   if(head->x==mark->x && head->y==mark->y)
	   {
	   cout<<"game over"<<endl;
		return;
	   }
	   mark=mark->link;	
	}
    system("CLS");
    display(head,fi,p);
	cin>>str;
	}

	if(str=='q')
   {
   	cout<<"Press s to save and quit or q to quit without save"<<endl;
   	char ch;
		cin>>ch;
		if(ch=='s')
		{
		struct node* heads;heads=head;
		char data[100],i=-1,food1[100];
		ofstream outfile;
		outfile.open("snakesave.txt");
		itoa(fi->a,data,10);
		outfile<<data<<"-";
		itoa(fi->b,data,10);
		outfile<<data<<"#";
		while(heads->link!=NULL)
		{
			itoa(heads->x,data,10);
			outfile<<data<<"-";
			itoa(heads->y,data,10);
			outfile<<data<<"-";
			heads=heads->link;
		}
		itoa(heads->x,data,10);
		outfile<<data<<"-";
		itoa(heads->y,data,10);
		outfile<<data<<"";
		heads=heads->link;
		outfile.close();
		cout<<"Saved!"<<endl;
		exit(0);
	}
	else
	{
		exit(0);
	}
   }	
}
int main()
{
	char a[12][10];
	int i,j,c=0,d=0,z=0,g=0,f=0;
	char str,ch1;
	cout<<"Enter n for new and l for load"<<endl;
	cin>>ch1;
	srand(time(NULL));
	char loadata[500];
	if(ch1=='n')
	{
	struct node *t,*t1,*t2,*mark;
	struct food *fi;
	struct poison *p;
	
	snake();
	fi =new food;
	fi->a=rand()%(10-3)+1;
	fi->b=rand()%(10-3)+1;
	
	p=new poison;
	p->a=rand()%(10-3)+1;
	p->b=rand()%(10-3)+1;
	display(head,fi,p);
	movement(head,fi,p);
	 
  }
  else
  {
  	
  }	
}






