/* Author : Ravi Kalla
 * Email  : ravikalla@ravikalla.in
 */
/*LRU (replacement algorithms)*/
main()
{
	static int p[50],pn,pf,i,j,k,l,temp[3],f[3]={-1,-1,-1};
	printf("Enter no. of pages:-");
	scanf("%d",&pn);
	printf("Enter page address no.s:-");
	for(i=0;i<pn;i++)
		scanf("%d",&p[i]);
	for(i=0,j=0;i<pn&&j<3;i++)
	{	for(k=0;k<3;k++)
			if(p[i]==f[k])
				l=1;
		printf("page\t%d\t\t",p[i]);
		if(l!=1)
		{	f[j]=p[i];
			temp[j]=p[i];
			for(k=0;k<3;k++)
				printf("%d\t",f[k]);
			printf("\n");
			j++;pf++;
		}
		else
		{	for(k=0;k<3;k++)
				printf("%d\t",f[k]);
			printf("\tNOT COUNTED\n");
		}
		l=0;
	}
	for(;i<pn;i++)
	{	for(k=0;k<3;k++)
			if(p[i]==f[k])
				{	l=1;
					for(k=0;k<3;k++)
					{	if(temp[k]==p[i])
						{	if(k==1)
							{	temp[1]+=temp[2];
								temp[2]=temp[1]-temp[2];
								temp[1]=temp[1]-temp[2];
							}
							else if(k==0)
							{	temp[0]+=temp[1];
								temp[1]=temp[0]-temp[1];
								temp[0]=temp[0]-temp[1];
								temp[2]+=temp[1];
								temp[1]=temp[2]-temp[1];
								temp[2]=temp[2]-temp[1];
							}
							break;
						}
					}
					break;
				}
		printf("page\t%d\t\t",p[i]);
		if(l!=1)
		{	for(k=0;k<3;k++)
				if(f[k]==temp[0])
					break;
			f[k]=p[i];
			temp[0]=temp[1];temp[1]=temp[2];temp[2]=p[i];
			for(k=0;k<3;k++)
				printf("%d\t",f[k]);
			printf("\n");
			j++;pf++;
		}
		else
		{	for(k=0;k<3;k++)
				printf("%d\t",f[k]);
			printf("\tNOT COUNTED\n");
		}
		l=0;
	}
	printf("PAGE FAULT is %d",pf);
	getch();
}