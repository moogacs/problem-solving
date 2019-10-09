#include <stdio.h>
#include <string.h>

int main(){
	int k=1, i, f1[400]={0}, f2[400]={0};
	char s1[10000], s2[10000];
	scanf("%[^\n]",s1);
	scanf(" %[^\n]",s2);
	for(i=0;i<strlen(s1);i++){
		if(s1[i]>='A' && s1[i]<='Z'){
			s1[i] += 32;
		}
	}
	for(i=0;i<strlen(s2);i++){
		if(s2[i]>='A' && s2[i]<='Z'){
			s2[i] += 32;
		}
	}
	for(i=0;i<strlen(s1);i++){
		if(s1[i]!='.' && s1[i]!=',' && s1[i]!='!' && s1[i]!='?' && s1[i]!=' '){
			f1[s1[i]+94]++;
		}
	}
	for(i=0;i<strlen(s2);i++){
		if(s2[i]!='.' && s2[i]!=',' && s2[i]!='!' && s2[i]!='?' && s2[i]!=' '){
			f2[s2[i]+94]++;
		}
	}
	for(i=0;i<400;i++){
		if(f1[i]==f2[i] && k==1){
			k=1;
		}else{
			k=0;
		}
	}
	if(k==1) printf("True");
	else printf("False");
	return 0;
}
