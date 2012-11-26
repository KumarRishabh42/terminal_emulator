#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/ptrace.h>
//#include<conio.h>
char arr[512][20];
int histx=0;
struct pidall{	
	char name[100];
	int procid;
};			
typedef struct pidall pall;
pall item[100];
int ir=0;
struct pidcurr{	
	char name[100];
	int procid;
	int flag;
};			
typedef struct pidcurr pcur;
pcur item1[100];

int ir1=0;

void sig_handler(int new){
//	printf("yaha bhi aaya ya nahi \n");
	int status;	
	pid_t pid;
	pid=waitpid(WAIT_ANY,&status,WNOHANG);
	int x;
	for(x=0;x<ir1;x++)
	{
		if(item1[x].procid==pid)
		{
			printf("%d exited normally\n",pid);

			item1[x].flag=0;
			break;
		}

	}
	fflush(stdout);
	signal(SIGCHLD,sig_handler);
	return;
}

/*

void sig_handler(int signum){
	int pid;

	pid = waitpid(WAIT_ANY, NULL, WNOHANG);
	if(pid != -1){
		printf("child Dead\n");
	}
	signal(SIGCHLD, sig_handler);
	return;
}*/
//	return 1;
	
//		printf("ir1 currently is %d\n",ir1);


void sig_h(int new){
		signal(SIGINT,sig_h);
		signal(SIGTERM, sig_h);
		signal(SIGQUIT, sig_h);
	//	signal(SIGCHLD,sig_handler);
		signal(SIGHUP,sig_h);
		signal(SIGTSTP,sig_h);


//	printf("caught signal\n");
}

int main(){
	char a[200],b;

//	printf("\n");
//	printf("%s\n",a);
	char hostname[1024];
	hostname[1023] = '\0';
	gethostname(hostname, 1023);
//	printf("Hostname %s\n",hostname);
	char *username;
	username=getenv("USER");
//	printf("%s\n",username);
	char *cwd;
	cwd=getcwd(0,0);
	char rootdir[100];
	strcpy(rootdir,cwd);
//	free(cwd);
//	printf("<%s@%s:%s>",hostname,username,"~");
	strcpy(a,"start");
///	wrkcpy[0]="initial";
//	wrkcpy[1]="initial";	
	int iniflag=1;


	///////////////signal handling initial
	
		signal(SIGINT,sig_h);
		signal(SIGTERM, sig_h);
		signal(SIGQUIT, sig_h);
		signal(SIGCHLD,sig_handler);
		signal(SIGHUP,sig_h);
		signal(SIGTSTP,sig_h);
		int iflag=0;
		int iiflag=1;


	///////////////signal handling initial ends
	while(1){
//			printf("Start of the loop\n");
			char wrkcpy[30][20];
		cwd=getcwd(0,0);	
		static int flag=0;
		static int flag1=0;

//////////////////////////////////////////////////////////signal handling begins


		signal(SIGINT,sig_h);
		signal(SIGTERM, sig_h);
		signal(SIGQUIT, sig_h);
		signal(SIGCHLD,sig_handler);
		signal(SIGHUP,sig_h);
		signal(SIGTSTP,sig_h);



/////////////////////////////////////////////////////////////signal handling ends

//		printf("cwd is %s rootdir is %s\n",cwd,rootdir);
//		printf("came here to sahi\n ");
//		printf("value of flag is %d\n",flag);
//		fflush(stdout);	
		if(strcmp(cwd,rootdir)==0){
			printf("<%s@%s:%s>",hostname,username,"~");
//			printf("coming here is ok but not second time\n");
		}
		else if(flag==1){
//			printf("should have reached here \n");
			printf("<%s@%s:%s>",hostname,username,cwd);
		//	flag=0;

		}
		//	iniflag=0;
		
//	printf("again as I said coming here again not ok\n");






//	if(iiflag==1 || iflag=1){
		char a[200];
//		printf("yaha ruka\n");
		scanf("%[^\n]",a);
//		int ch;
//		while((ch = getchar()) != '\n' && ch != EOF);
		strcpy(arr[histx++],a);
	//	printf("a is %s\n",a);	
		getchar();
//		printf("\n");
//		printf("string length is %d\n",strlen(a));
	//	scanf("%c",&b);
		char c[200];
		strcpy(c,a);
		char d[200];
		strcpy(d,c);
//		printf("c now is %s\n,",c);
		int xyz;
		int ppcnt=0;
		for(xyz=0;xyz<strlen(c);++xyz){
	//		printf("character is %c\n",c[xyz]);
			if(c[xyz]=='|'){
	//			printf("came here \n");
				ppcnt++;
			}

		}
		ppcnt++;
	//	printf("pipe count is %d\n",ppcnt);
		//char *cwd;
		char *new;
		
		// parsing starts here 
		int tempi=0;
		strcpy(wrkcpy[tempi++],strtok(c," "));
//		printf("tempi now is %d\n",tempi);
		if(strcmp(a,"quit")==0)
			break;

		if(wrkcpy[0][1]=='h' && wrkcpy[0][2]=='i' && wrkcpy[0][3]=='s' && wrkcpy[0][4]=='t' && wrkcpy[0][0]=='!' && strlen(wrkcpy[0])>4){
//				printf("got here atleast\n");
				int no=0;
				int it;
//				printf("strlen-4 is %d\n",strlen(wrkcpy[0]));
				for(it=1;it<=strlen(wrkcpy[0])-5;++it){
					int iti;
					int exp,expr;
					exp=1;
					expr=10;
//					printf("iter %d\n",it);
					if((it-1)==0){
						exp=1;
					}
					else{
						for(iti=1;iti<=it-1;++iti){
							exp*=expr;	
						}
					}
				//	printf("%d\n",pow(10,it-1));
//					printf("power of 10 is %d\n",exp);
						no+=exp*(wrkcpy[0][strlen(wrkcpy[0])-it]-48);
	
				}
				
			//	char d[200];
			//	strcpy(d,c);
	//			printf("no is %s\n",d);
				strcpy(c,arr[no-1]);
				int ij;
				int kk;

				for(ij=0;ij<strlen(d);++ij){
					if(d[ij]==' '){
						kk=ij;
						break;
					}
				}
	//			printf("space is at %d\n",kk);
	//			printf("c that came %s\n",c);

				int lenx=strlen(c);
	//			printf("len now is %d\n",lenx);
				int xx=0;
				int lm;
				lm=lenx;
				char e[200];
				int ijk;
				for(ijk=0;ijk<strlen(c);++ijk){
					e[ijk]=c[ijk];

				}
	//			printf("e now is %s \n",e);
				for(ij=kk;ij<strlen(d);++ij){
	//				printf("%d %d\n",ij,lm);
	//				printf("string ele to be accessed %c\n",d[ij]);
					
					c[lm]=d[ij];
					
	//				printf("c new addition is %c\n",c[lm]);
	//				printf("lenx is %d lm is %d and xx is %d\n",lenx,lm,xx);

					lm++;
				}
				c[lm]='\0';
			//		strcat(c,d);
//				printf("strlen(c) is %d\n",strlen(c));
		//		strlen(c)=strlen(c)+xx;
	//			printf("yada yada yada \n");
		//		printf("c now is %s bitch please \n",c); 
				strcpy(wrkcpy[0],strtok(c," "));


		}	




//		printf("REached here till now\n");
//		printf("i is %d\n",i);
//		printf("wrkcpy is %s\n",wrkcpy[i-1]);
//		printf("value is %d\n",strcmp(wrkcpy[i-1],NULL));
	//	printf("atleast reached here\n");
		int pipearr[10];
		int jj=0;
		int ii=0;
		char *res;
		while((res=strtok(NULL," "))!=NULL){
			ii++;
		//	printf("value of i is %d\n",i);
		//	printf("reached here\n");
		//	res=strtok(NULL," ");
			strcpy(wrkcpy[tempi++],res);
			if(strcmp(res,"|")==0){
				pipearr[jj++]=ii;
			}
		//	printf("wrkcpy[%d] is%s",i-1,wrkcpy[i-1]);
		}
		int nocom;
		if(jj==0){
			nocom=1;
		}
		else{
			nocom=jj+1;
		}

		for(xyz=jj-1;xyz>=0;--xyz){
				pipearr[xyz+1]=pipearr[xyz];

				
		}
		pipearr[0]=0;
		pipearr[jj+1]=(tempi);
//		for(xyz=0;xyz<jj+2;++xyz){
//
//			printf("%d\n",pipearr[xyz]);
//		}

		int status;

		int pipes[2*(jj)];
//		printf("no of pipes = %d\n",2*jj);
		int i;
		for(i = 0; i < (jj) ; i++){
			if(pipe(pipes + i*2) < 0) {
				perror("couldn't pipe");
				exit(EXIT_FAILURE);
			}
		}
		int llpid=getpid();
		int andstatus=0;


//		printf("tempi is %d\n",tempi);
//		printf("reached here atleast\n");
//		strcpy(wrkcpy[tempi],'\0');
//		printf("should have reached here atleast\n");
//		if(strcmp(new[0],"cd")==0){
//			cwd=
	

//		printf("%s\n",cwd);
//		static char wrkd[100];
//		wrkd=cwd;


//		printf("\n");

//		printf("first iteration\n");

//////////////////////////////////////////////////////////////neeche ka block
		///to be debugged
			
		
		
//		free(new);gives seg fault why?
		if(strcmp(wrkcpy[0],"cd")==0){
			flag=1;
//			printf("reached in cd portion\n");
			chdir(wrkcpy[1]);			
		
		}

		

		


	

		
		else if(tempi>1 && strcmp(wrkcpy[1],"&")==0){
			strcpy(item[ir].name,arr[histx-1]);
//			printf("hello there\n");
//			execvp(wrkcpy[0],wrkcpy);
//			printf("hello again\n");
			char **temp;
			temp=(char **)malloc(sizeof(char *)*10);
			int xx;
			for(xx=0;xx<10;++xx){
				temp[xx]=(char *)malloc(sizeof(char)*30);
				
			}
			for(xx=0;xx<tempi;++xx){
				strcpy(temp[xx],wrkcpy[xx]);
			}
			temp[tempi-1]=NULL;	
			temp[tempi]=NULL;
			
	//		printf("sahi ja raha hai\n ");
		//	strcpy(*temp,"ls");
//			strcpy(*(temp+1),NULL);
//			printf("sahi jate jate kya ho gaya reached here \n");
			 
			strcpy(item1[ir1].name,arr[histx-1]);

	//			printf("shouldnt reach here reached & part\n");
				pid_t  pid;
				int status;
				pid=fork();
//			printf("went here too\n");
				if (pid == 0) {  
					
					/* for the child process:         */
	//			printf("p - %d\n",getpid());		
	//			printf(" ir -- %d\n ",ir);
				//	execvp(*temp,temp);   
			//		pid_t pid1;int main(int argc, char *argv[])
				//		pid1=fork();
				//		if(pid1==0){
				if(			execvp(*temp,temp)<0){
				//	histx--;
					
				printf("Command not found\n");
				}   
				//	execvp(*temp,temp);   
						
					
				/* execute the command  */
//				printf("value of --- is %d \n",x);
	//			printf("reached here where it should have reached\n");	
						_exit(0);
							
						}
			     	else {   
					item1[ir1].procid=pid;
					item1[ir1++].flag=1;
				//	printf("ir1 currently is %d\n",ir1);
				     	item[ir++].procid=pid;
					int pcc;
					pcc=waitpid(WAIT_ANY,&status,WNOHANG);
//					printf("reached here\n");
						//			iniflag=1;
					signal(SIGCHLD,sig_handler);
					
					/* wait for completion  */
						                      
					}
				}
				
			
			else	{


			
		
			andstatus=1;
			int status;

		//		printf("hello there\n");
//			execvp(wrkcpy[0],wrkcpy);
//			printf("hello again\n");
			char **temp;
			temp=(char **)malloc(sizeof(char *)*20);
			int xx;
			for(xx=0;xx<20;++xx){
				temp[xx]=(char *)malloc(sizeof(char)*30);
				
			}
			for(xx=0;xx<tempi;++xx){
				strcpy(temp[xx],wrkcpy[xx]);
			}
			FILE * in;
			FILE * out;
			temp[tempi]=NULL;
//			printf("tempi right now is %d\n",tempi);
		//fclose(in);
			//fclose(out);
	//		printf("here here here here \n");
//			printf("tempi is %d \n",tempi);	

		//	temp[tempi++]=NULL;
//			printf("temp[0] is %s temp[1]is %s %s\n",temp[0],temp[1],temp[2]);
	//		printf("sahi ja raha hai\n ");
		//	strcpy(*temp,"ls");
//			strcpy(*(temp+1),NULL);
//			printf("sahi jate jate kya ho gaya reached here \n");
			 
			strcpy(item1[ir1].name,arr[histx-1]);


				int j=0;

//				printf("reached yaha not & part\n");
				pid_t  pid;
				int nn=0;
				while(nocom){
			//	int status;
			//		printf("no of commands %d \n",nocom);

					char **wrktemp;
					wrktemp=(char **)malloc(sizeof(char *)*10);
					int xx;
					for(xx=0;xx<20;++xx){
						wrktemp[xx]=(char *)malloc(sizeof(char)*20);
				
					}

					


					
					int kk;
					int ll=0;
					if(nn==0){
					for(kk=pipearr[nn];kk<pipearr[nn+1];++kk){
							strcpy(wrktemp[ll++],temp[kk]);
						
					}
					}
	
					else{
						for(kk=pipearr[nn]+1;kk<pipearr[nn+1];++kk){
							strcpy(wrktemp[ll++],temp[kk]);
						}	
					}

					int iii;
			//		for(iii=0;iii<ll;++iii){
			//			printf("%s \n",wrktemp[iii]);
			//		}





					wrktemp[ll]=NULL;
					
					nn++;



					//int xx;
					int xflagin=0;
					int xflagout=0;
					int xflag=0;
					int xxx;
					for(xx=0;xx<ll;++xx){
						if(strcmp(wrktemp[xx],"<")==0){
							xflagin=1;
							if(xflag==0){
								xflag=1;
								xxx=xx;
						
							}
			//			printf("xx right now is %d\n",xx);
				//		printf("xyz %s\n",wrktemp[xx+1]);
						in=fopen(temp[xx+1],"r");
			//			fprintf(in,"helloxxx\n");
				//		printf("xyz\n");
			//						printf("xyz again\n");
					}

						else if(strcmp(wrktemp[xx],">>")==0){
							xflagout=1;
							if(xflag==0){
								xflag=1;
								xxx=xx;
						
							}
			//			printf("xx right now is %d\n",xx);
				//		printf("xyz %s\n",wrktemp[xx+1]);
						out=fopen(temp[xx+1],"a");
			//			fprintf(in,"helloxxx\n");
				//		printf("xyz\n");
			//						printf("xyz again\n");
					}














						else if(strcmp(wrktemp[xx],">")==0){
			//			printf("reached hereright nw\n");
						out=fopen(wrktemp[xx+1],"w");
						xflagout=1;
			//			printf("%s\n",temp[xx+1]);
						if(xflag==0){
							xflag=1;
							xxx=xx;
						
						}
					}
	//				printf("reached here\n");

					}
					if(xflag==1){
				//		printf("xxx is %d\n",xxx);
						wrktemp[xxx]=NULL;
					}
		
				pid=fork();
				
//			printf("went here too\n");
				if (pid == 0) {
					int procflag=0;

					if(nocom!=1){
			//			printf("came here should come first \n");
						if(dup2(pipes[j+1],1)<0){
							perror("dup2");
							exit(EXIT_FAILURE);
							
					}}
					if(j!=0){
			//			printf("came here next !!!!!! should have happened \n");
						if(dup2(pipes[j-2],0)<0){
								perror("dup2");
								exit(EXIT_FAILURE);
					
						}


					}


			//		printf("came here too\n");
					if(xflagin==1){
					//	printf("inzone\n");
						dup2(fileno(in),fileno(stdin));

					}	
					if(xflagout==1){
					//	printf("outzone\n");
						dup2(fileno(out),fileno(stdout));


					}


					for(i=0;i<2*jj;++i){
						close(pipes[i]);

					}






/*
						if(wrkcpy[0][1]=='h' && wrkcpy[0][2]=='i' && wrkcpy[0][3]=='s' && wrkcpy[0][4]=='t' && wrkcpy[0][0]=='!' && strlen(wrkcpy[0])>4){
//				printf("got here atleast\n");
				int no=0;
				int it;
//				printf("strlen-4 is %d\n",strlen(wrkcpy[0]));
				for(it=1;it<=strlen(wrkcpy[0])-5;++it){
					int iti;
					int exp,expr;
					exp=1;
					expr=10;
//					printf("iter %d\n",it);
					if((it-1)==0){
						exp=1;
					}
					else{
						for(iti=1;iti<=it-1;++iti){
							exp*=expr;	
						}
					}
				//	printf("%d\n",pow(10,it-1));
//					printf("power of 10 is %d\n",exp);
						no+=exp*(wrkcpy[0][strlen(wrkcpy[0])-it]-48);
	
				}
		//		char c[20];
//				printf("no is %d\n",no);
				strcpy(c,arr[no-1]);
				strcpy(wrkcpy[0],strtok(c," "));

		}*/



//////////////////////////////

/*
			if(wrktemp[0][1]=='h' && wrktemp[0][2]=='i' && wrktemp[0][3]=='s' && wrktemp[0][4]=='t' && wrktemp[0][0]=='!' && strlen(wrktemp[0])>4){
//				printf("got here atleast\n");
				int no=0;
				int it;
//				printf("strlen-4 is %d\n",strlen(wrkcpy[0]));
				for(it=1;it<=strlen(wrktemp[0])-5;++it){
					int iti;
					int exp,expr;
					exp=1;
					expr=10;
//					printf("iter %d\n",it);
					if((it-1)==0){
						exp=1;
					}
					else{
						for(iti=1;iti<=it-1;++iti){
							exp*=expr;	
						}
					}
				//	printf("%d\n",pow(10,it-1));
//					printf("power of 10 is %d\n",exp);
						no+=exp*(wrktemp[0][strlen(wrktemp[0])-it]-48);
	
				}
		//		char c[20];
				printf("no caught is %d\n",no);
				strcpy(c,arr[no-1]);
				strcpy(wrkcpy[0],strtok(c," "));
				while((res=strtok(NULL," "))!=NULL){
				//	ii++;
		//	printf("value of i is %d\n",i);
		//	printf("reached here\n");
		//	res=strtok(NULL," ");
					strcpy(wrkcpy[tempi++],res);
					
				}


				






		//	printf("wrkcpy[%d] is%s",i-1,wrkcpy[i-1]);
			}
	
*/





			



















/*			printf("string now is %s\n ",wrktemp[0]);
			if(strcmp(wrktemp[0],"pid")==0){
				printf("yes yes \n");
					
			}


*/









				


					/* for the child process:         */
	//			printf("p - %d\n",getpid());		
	//			printf(" ir -- %d\n ",ir);
				
				
				if(strcmp(wrktemp[0],"pid")==0 && ll==1){
				//	printf("yaha aaya\n");
			//	long long int *pid;
			//	pid=(int *)malloc(sizeof(int)*10);
				//	pid=getpid();
		
					printf("command name: ./a.out process id:%d\n",llpid);
							procflag=1;

				}	
			
			
				else if(strcmp(wrktemp[0],"pid")==0 && strcmp(wrktemp[1],"current")==0){
					printf("List of currently executing processes spawned from this shell:\n");
					int xy1;
					for(xy1=0;xy1<ir1;++xy1){
						if(item1[xy1].flag==1){
							printf("command name:%s process id:%d\n",item1[xy1].name,item1[xy1].procid);
						}
					}
					procflag=1;
	
				}
				else if(strcmp(wrktemp[0],"pid")==0 && strcmp(wrktemp[1],"all")==0){
					printf("List of all processes spawned from this shell:\n");
					int xy;
					//			printf("ir is %d\n ",ir);
					for(xy=0;xy<ir;++xy){
						printf("command name:%s process id:%d\n",item[xy].name,item[xy].procid);
					}
					procflag=1;

				}

				else if(wrktemp[0][0]=='h' && wrktemp[0][1]=='i' && wrktemp[0][2]=='s' && wrktemp[0][3]=='t' && strlen(wrktemp[0])>4){
			int no=0;
//				printf("reached here\n");
				int it;
//				printf("strlen-4 is %d\n",strlen(wrkcpy[0]));
				for(it=1;it<=strlen(wrktemp[0])-4;++it){
					int iti;
					int exp,expr;
					exp=1;
					expr=10;
//					printf("iter %d\n",it);
					if((it-1)==0){
						exp=1;
					}
					else{
						for(iti=1;iti<=it-1;++iti){
							exp*=expr;	
						}
					}
				//	printf("%d\n",pow(10,it-1));
//					printf("power of 10 is %d\n",exp);
						no+=exp*(wrktemp[0][strlen(wrktemp[0])-it]-48);
	
				}
			//	printf("histx as of now is %d\n",histx);
			//	printf("no is %d\n",no);
				if(no<histx){
				//	printf("got into no<histx\n");

					int j;
		//			printf("init is is is %d and final is %d\n",strlen(wrkcpy[0])-no-1,strlen(wrkcpy[0])-1);
	//				printf("init %d and final %d\n",strlen(wrkcpy[0])-no-1,strlen(wrkcpy[0])-1);

					for(j=(histx-no-1);j<histx-1;++j)
				//		printf("j is %d\n",j);
						printf("%s\n",arr[j]);

				}
				else {	
					int j;
					for(j=0;j<histx-1;++j)
						printf("%s\n",arr[j]);


				}
				procflag=1;
		//		printf("no is %d\n",no);
		//	printf("got it\n");

		}






























				else if(strcmp(wrktemp[0],"hist")==0){
					int j;
					for(j=0;j<histx;++j)
					printf("%s\n",arr[j]);
					procflag=1;
				}	
				else	{
				//	printf("yaha nahi aana tha");
					
					if(	execvp(*wrktemp,wrktemp)<0 && procflag==0){
					//	histx--;
				//		ir--;
						printf("Command not found\n");	
					}
				}
//				printf("x shouldnt come %d\n",x);
				/* execute the command  */
//				printf("value of --- is %d \n",x);
	//			printf("reached here where it should have reached\n");	
					fflush(stdout);
				//	fclose(out);
				//	printf("ya yaha lagi\n");
				//	fclose(out);

					_exit(0);
							
						}
			     	else {   
				
				     	strcpy(item[ir].name,wrktemp[0]);

					item[ir++].procid=pid;
					fflush(stdout);
				///	fclose(out);
				//	printf("yaha lagi\n");
				//	fclose(out);

				//	fclose(in);
			        //	fclose(out);


		//			printf("yaha aa gaya");
				     /* for the parent:      */
//					printf("done with not & part\n");
				//		sleep(0.5);
//			printf("shouldnt reach here too soon\n");


				        	// wait(&status);
				//		 flag1=1;
						  /* wait for completion  */
						                      
					}
					nocom--;
					j+=2;
				
				}


//				printf("end of loop\n");
			}//	int i;	
			if(andstatus==1){
				for(i = 0; i < 2 * jj; i++){
						close(pipes[i]);
					}

					for(i = 0; i < jj + 1; i++)
						wait(&status);
			}
			//	dup2(fileno(stdin),fileno(stdin));
			//	dup2(fileno(stdout),fileno(stdout));
				flag1=1;
		//		printf("end of loop\n");
				//		free(cwd);
///		char *cwd;
//		printf("got here\n");
		cwd=getcwd(0,0);
//		printf("reached here \n");
	
//		printf("cwd is %s\n",cwd);
//	printf("got here too\n");
//		printf("a now is %s\n",a);

	//	scanf("%[^\n]",a);
	//	strcpy(arr[hist++],a);
	//	scanf("%c",&b);
	//	pirintf("j----------%d",j);
//		printf("%s\n",a);
	}
	return 0;
}
