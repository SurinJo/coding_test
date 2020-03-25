#include <stdio.h>
int main(){
	int a,q,r;
	char ans[600];
	scanf("%d",&a);
	q=a/2;
	r=a%2;
	if (r==1)
		ans[0]='7';
	else
		ans[0]='1';
	for (int i=1;i<q;i++){
		ans[i]='1';
	}
	ans[q]='\0';
	printf("%s\n",ans);
}
