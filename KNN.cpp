#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAX 20
#define k 3

using namespace std;


enum category {SHORT, AVERAGE, TALL};

class data
{
	int x,y;
	category cat;
	public:
		void setd(int a, int b, category c)
		{
			x = a;
			y = b;
			cat = c;
		}

		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		category getCat()
		{
			return cat;
		}

};
	
int dis(data d1, data d2)
{
	return sqrt(pow((d2.getX()-d1.getX()),2)+pow((d2.getY()-d1.getY()),2));
}



int main()
{

	int p,q;
	int a[MAX];
	int b[k];
	int c[k];

	for(int i=0;i<k;i++)
	{
		b[i]=-1;
		c[i]=0;
	}

	data n;
	data d[MAX];

	cout<<"Enter x,y:"<<endl;
	cin>>p>>q;

	n.setd(p,q,SHORT);

	d[0].setd(1,1,SHORT);
	d[1].setd(1,2,SHORT);
	d[2].setd(1,3,SHORT);
	d[3].setd(1,4,SHORT);
	d[4].setd(1,5,SHORT);
	d[5].setd(1,6,SHORT);
	d[6].setd(1,7,SHORT);
	d[7].setd(2,1,SHORT);
	d[8].setd(2,2,SHORT);
	d[9].setd(2,3,AVERAGE);
	d[10].setd(2,4,AVERAGE);
	d[11].setd(2,5,AVERAGE);
	d[12].setd(2,6,AVERAGE);
	d[13].setd(2,7,AVERAGE);
	d[14].setd(5,1,TALL);
	d[15].setd(5,2,TALL);
	d[16].setd(5,3,TALL);
	d[17].setd(5,4,TALL);
	d[18].setd(5,5,TALL);
	d[19].setd(5,6,TALL);

	for(int i=0;i<MAX;i++)
	{
		a[i] = dis(n,d[i]);
		cout<<"Distance "<<i<<" : "<<a[i]<<endl;
	}
	int min=1000;
	for(int j=0;j<k;j++)
	{
		min=1000;
		for(int i=0;i<MAX;i++)
		{
			if(i!=b[0] && i!=b[1] && i!=b[2])
			{
				if(a[i]<=min)
				{
					min = a[i];
					b[j] = i;
				}
			}
		}
	cout<<"Min: "<<min<<endl;
	cout<<"Location: "<<b[j]<<endl;
	}

	for(int i=0;i<k;i++)
	{
		switch(d[b[i]].getCat())
		{
			case SHORT:
				c[0]++;
				break;
			case AVERAGE:
				c[1]++;
				break;
			case TALL:
				c[2]++;
				break;
		}
	}

	int maxi=-1000, loc;
	for(int i=0;i<k;i++)
	{
		if(c[i]>maxi)
		{
			maxi=c[i];
			loc=i;
		}
	}

	cout<<"Prediction: "<<endl;
	switch(loc)
	{
		case 0:
			cout<<"SHORT"<<endl;
			break;
		case 1:
			cout<<"AVERAGE"<<endl;
			break;
		case 2:
			cout<<"TALL"<<endl;
			break;
	}


	return 0;
}