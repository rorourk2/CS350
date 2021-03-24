#include <stdio.h>

int main(void)
{
	int exit = 0;
	int ne=0;
	int ar=0;
	int blank = 0;
	int forw= 0;
	int backw=0;
	int i=0;
	char inp[1000];
	while(exit==0){
		ne=0;
		ar=0;
		blank = 0;
		forw= 0;
		backw=0;
		i=0;

		printf("\n");
		printf("cs-350-prog1> ");
		fgets(inp, 1000, stdin);
		if(inp[0]=='e' && inp[1]=='x' && inp[2]=='i' && inp[3]=='t'){
			exit = 1;
		}
		else{
			
			while(inp[i]!='\0'){
				
				if(forw==1 || backw==1){
					if(inp[i]!=' ' && inp[i]!='|' && inp[i]!='>' && inp[i]!='<' && inp[i]!='&' && inp[i]!=';' && inp[i]!='\n'){
						printf("%c", inp[i]);
					}else if(inp[i]!=' ' && inp[i]!='\n'){
						printf("\".");
						backw=0;
						forw=0;
					}
				}
				if(inp[i]=='>'){
					printf("\n... output of the above command will be redirected to file \"");
					forw=1;
					blank=0;

				}
				if(inp[i]=='<'){
					printf("\n... input of the above command will be redirected from file \"");
					backw=1;
					blank=0;

				}
				
				if(forw==0 && backw==0){
					if(ne==0){
						printf("COMMAND: ");
						ne=1;
						ar=0;
					}
					if(inp[i]!=' ' && inp[i]!='|' && inp[i]!='>' && inp[i]!='<' && inp[i]!='&' && inp[i]!=';'){
						if(ar==0){
							ar=1;
						}
						if(blank==1){
							printf(", ");
							printf("arg-%d: ", ar);
							ar=ar+1;
						}
						printf("%c", inp[i]);
						blank=0;
					}
					if(inp[i]=='|'){
					
						printf("\n... output of the above command will be redirected to serve as the input of the following command ... \n");
						blank=0;
						ne=0;
					}
					if(inp[i]==' ' && ar!=0){
					
						blank=1;
					}
					if(inp[i]=='&'){
					
						printf("\n... the above command will be executed in the background.");
						blank=0;
					}
					if(inp[i]==';'){
					
						printf("\n\n\n");
						blank=0;
						ne=0;
					}
				}
				i=i+1;
			}
			if(forw==1 || backw==1){
				printf("\".");
			}
		}
	}
	return 0;
}

