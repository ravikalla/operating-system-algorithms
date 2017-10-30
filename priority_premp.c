/* Author : Ravi Kalla
 * Email  : ravikalla@ravikalla.in
 */

struct priority_premp
{
	int burst_time,tmp,index,turn_around_time,arrival_time,start_time,end_time,priority;
}x[100],tmp1;

void main()
{
	static int i,j,k,tmp2,tmp3;
	static float awt;
	printf("Enter no. of processes:-");
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		printf("Enter BURST TIME:-");
		scanf("%d",&x[j].burst_time);
		x[j].tmp=x[j].burst_time;
		printf("Enter PRIORITY:-");
		scanf("%d",&x[j].priority);
		printf("Enter ARRIVAL TIME:-");
		scanf("%d",&x[j].arrival_time);
		x[j].start_time=-1;
		x[j].end_time=x[j].arrival_time;
		x[j].index=j;
	}
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(x[j].arrival_time>x[k].arrival_time)
			{
				tmp1=x[j];
				x[j]=x[k];
				x[k]=tmp1;
			}
			else if(x[j].burst_time>x[k].burst_time&&x[j].arrival_time==x[k].arrival_time)
			{
				tmp1=x[j];
				x[j]=x[k];
				x[k]=tmp1;
			}
			else if(x[j].priority>x[k].priority&&x[j].arrival_time==x[k].arrival_time&&x[j].burst_time==x[k].burst_time)
			{
				tmp1=x[j];
				x[j]=x[k];
				x[k]=tmp1;
			}
		}
	}
	for(j=0,k=0;j<i;)
	{
		for(tmp2=j;x[tmp2].arrival_time<=k&&tmp2<i;tmp2++)
		{
			for(tmp3=tmp2+1;x[tmp3].arrival_time<=k&&tmp3<i;tmp3++)
			{
				if(x[tmp2].priority>x[tmp3].priority)
				{
					tmp1=x[tmp2];
					x[tmp2]=x[tmp3];
					x[tmp3]=tmp1;
				}
				else if(x[tmp2].priority==x[tmp3].priority&&x[tmp2].tmp==x[tmp3].tmp)
				{
					tmp1=x[j];
					x[j]=x[k];
					x[k]=tmp1;
				}
			}
		}
		if(x[j].arrival_time<=k)
		{
			if(x[j].tmp>0)
			{
				if(x[j].start_time<0)
				{
					x[j].start_time=k;
				}
				awt+=k-x[j].end_time;
				x[j].tmp--;
				/*printf("-%d ||pro %d || ",k,x[j].index+1);*/
				k++;
				/*printf("%d",k);*/
				x[j].end_time=k;
			}
			else
			{
				j++;
			}
		}
		else
		{
			k++;
		}
	}
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(x[j].index>x[k].index)
			{
				tmp1=x[j];
				x[j]=x[k];
				x[k]=tmp1;
			}
		}
	}
	for(j=0;j<i;j++)
	{
		x[j].turn_around_time=x[j].end_time-x[j].arrival_time;
		printf("\nTURN AROUND TIME for %d process is %d",j+1,x[j].turn_around_time);
	}
	awt/=i;
	printf("\nAVERAGE WAITING TIME is %f",awt);
	getch();
}