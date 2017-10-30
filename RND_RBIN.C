/* Author : Ravi Kalla
 * Email  : ravikalla@ravikalla.in
 */

struct rnd_rbin
{
	int burst_time,tmp,turn_around_time,enter_time,start_time,end_time,index;
}x[100];

void main()
{
	static int i,j,k,p,q,tq,end,wait;
	static float awt;
	struct rnd_rbin tmp1;
	clrscr();
	printf("Enter time quantum:-");
	scanf("%d",&tq);
	printf("Enter no. of processes:-");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		printf("Enter BURST TIME of %d process:-",j+1);
		scanf("%d",&x[j].burst_time);
		x[j].tmp=x[j].burst_time;
		printf("Enter ARRIVAL TIME of %d process:-",j+1);
		scanf("%d",&x[j].enter_time);
		x[j].start_time=-1;
		x[j].end_time=x[j].enter_time;
		x[j].index=j;
	}
	for(p=0;p<i;p++)
	{
		for(q=p+1;q<i;q++)
		{
			if(x[p].enter_time>x[q].enter_time)
			{
				tmp1=x[p];
				x[p]=x[q];
				x[q]=tmp1;
			}
		}
	}
	for(j=0,k=0;end<i;j=(j+1)%i)
	{
		if(x[j].enter_time<=k)
		{
			if(x[j].tmp>0)
			{
				wait=0;
				if(x[j].start_time<0)
					x[j].start_time=k;
				if(x[j].tmp<=tq)
				{
					awt+=k-x[j].end_time;
					k+=x[j].tmp;
					x[j].tmp=0;
					x[j].end_time=k;
					end++;
				}
				else
				{
					awt+=k-x[j].end_time;
					k+=tq;
					x[j].tmp-=tq;
					x[j].end_time=k;
				}
			}
			else
				wait++;
		}
		else
			wait++;
		if(wait>=i)
		{
			wait=0;
			k++;
		}
	}/*end of FOR loop*/
	for(p=0;p<i;p++)
	{
		for(q=p+1;q<i;q++)
		{
			if(x[p].index>x[q].index)
			{
				tmp1=x[p];
				x[p]=x[q];
				x[q]=tmp1;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		x[j].turn_around_time=x[j].end_time-x[j].enter_time;
		printf("TURN AROUND TIME for %d process is %d\n",j+1,x[j].turn_around_time);
	}
	awt/=i;
	printf("AVERAGE WAITING TIME is %f",awt);
	getch();
}