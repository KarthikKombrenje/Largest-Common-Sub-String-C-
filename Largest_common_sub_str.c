
#include<stdio.h>
#include<conio.h>
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{

        char x[100],y[100];
        int m,n;
        printf("Enter the 2 strings X and Y\n");
        scanf("%s %s",&x,&y);
        m = strlen(x);
        n = strlen(y);
        printf("Length of LCS is %d \n",lcs(x,y,m,n));
        return 0;
}
