#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

int main()
{
    char s[12];
    int n,tmpr[250],res[250],tmps[12],len;
    int pointflag,lenr,jinwei,lens;
    int i,j,k;
    bool flag=0;
    while(scanf("%s%d",s,&n)!=EOF)
    {
        pointflag=0;j=0;jinwei=0;flag=0;
        memset(tmps,0,sizeof(tmps));
        memset(tmpr,0,sizeof(tmpr));
        memset(res,0,sizeof(res));
        len=strlen(s);
        for(i=len-1;i>=0;i--)
        {
            if(s[i]!='.')
            {
                tmps[j++]=(int)(s[i]-'0');
                res[j-1]=tmps[j-1];
            }
        }
        if(j!=len)
        {
            for(i=len-1;i>=0;i--)
            {
                if(s[i]!='.')
                    pointflag++;
                else break;
            }
        }
        lens=j;
        lenr=j;
        for(i=0;i<5;i++)
        {
            if(tmps[i]!=0)break;
        }
        if(i>=5)printf("0");
        else if(n==0)printf("1");
        else{
            for(i=1;i<n;i++)
            {
                for(j=0;j<lens;j++)
                {
                    for(k=0;k<lenr;k++)
                    {
                        tmpr[j+k]+=tmps[j]*res[k];
                    }
                }
                lenr+=lens-1;
                for(j=0;j<lenr;j++)
                {
                    tmpr[j]+=jinwei;
                    jinwei=tmpr[j]/10;
                    tmpr[j]%=10;
                }
                while(jinwei!=0)
                {
                    tmpr[lenr]+=jinwei%10;
                    jinwei/=10;
                    lenr++;
                }
                for(j=0;j<lenr;j++)
                {
                    res[j]=tmpr[j];
                }
                memset(tmpr,0,sizeof(tmpr));
            }
            for(i=0;i<n*pointflag;i++)
            {
                if(res[i]!=0)
                {
                    k=i;
                    break;
                }
            }
            if(i>=n*pointflag)k=i;
            if(pointflag!=0)
            {
                for(i=lenr-1;i>=n*pointflag;i--)
                {
                    if(res[i]!=0)
                        flag=1;
                    if(flag)
                        printf("%d",res[i]);
                }
                if(k!=n*pointflag)
                {
                    printf(".");
                    for(i=n*pointflag-1;i>=k;i--)
                    {
                        printf("%d",res[i]);
                    }
                }
            }
            else
            {
                for(i=lenr-1;i>=0;i--)
                {
                    if(res[i]!=0)
                        flag=1;
                    if(flag)
                        printf("%d",res[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
