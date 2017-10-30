/* Author : Ravi Kalla
 * Email  : ravikalla@ravikalla.in
 */
/*FIFO (replacement algorithms)*/
main()
{	static int p[50],pn,pf,i,j,k,l,f[3]={-1,-1,-1};
	printf("Enter no. of page addresses:-");
	scanf("%d",&pn);
	printf("Enter page address no.s:-");
	for(i=0;i<pn;i++)
		scanf("%d",&p[i]);
	for(i=0,j=0;i<pn;i++)
	{	for(k=0;k<3;k++)
			if(p[i]==f[k])
				l=1;
		printf("page\t%d\t\t",p[i]);
		if(l!=1)
		{	f[j]=p[i];
			for(k=0;k<3;k++)
				printf("%d\t",f[k]);
			printf("\n");
			j=(++j)%3;
			pf++;
		}
		else
		{	for(k=0;k<3;k++)
				printf("%d\t",f[k]);
			printf("\tNOT COUNTED\n");
		}
		l=0;
	}
	printf("PAGE FAULT is %d",pf);
}