#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#define max_u 4
#define hash_size 100
#define url_lenght 1000
int num=0,num1=0,jj=0,pp=0,num2=1,kk=0,ii;
struct node{
char str[100];
int depth;

int key;
struct node *next;
};

struct hash{
struct node* head;
struct node* tail;
int count;
}h[50];
void headd(char link[100],int l){
int fg=0;
if(kk==0)
ii=l;
kk++;
h[l].count=h[l].count+1;
struct node *t;
struct node *tmp=(struct node*)malloc(sizeof(struct node));
h[ii].tail=h[ii].head;
strcpy(tmp->str,link);
tmp->key=l;
tmp->next=NULL;
if(h[ii].head==NULL){ 
h[ii].head=tmp;
return;
}

if(h[l].head==NULL){
h[l].head=tmp;
}
while(h[ii].tail->next!=NULL){
t=h[ii].tail;
h[ii].tail=h[ii].tail->next;
if(t->key==l  && h[ii].tail->key!=l)
{
fg=1;
break;
}
}
if(fg==1)
{
tmp->next=t->next;
t->next=tmp;
}else
h[ii].tail->next=tmp;
}

void print1(){
struct node *ptr;
for(int i=0;i<50;i++){
ptr=h[i].head;
if(ptr!=NULL)
printf("%d----*-*-*-*-%d\n",h[i].count,ptr->key);
}
ptr=h[ii].head;
while(ptr!=NULL){
printf("%s-----%d\n",ptr->str,ptr->key);
ptr=ptr->next;
}
}


void valid(char *u){
char ch[100]={0};
strcpy(ch,"wget --spider ");
strcat(ch,u);
if(!system(ch))
printf("url is valid \n");
else
printf("url is not not valid \n");
}



void testDir(char *dir)
{
  struct stat statbuf;
  if ( stat(dir, &statbuf) == -1 ) 
  {
    fprintf(stderr, "-----------------\n");
    fprintf(stderr, "Invalid directory\n");
    fprintf(stderr, "-----------------\n");
    exit(1);
  }

  //Both check if there's a directory and if it's writable
  if ( !S_ISDIR(statbuf.st_mode) ) 
  {
    fprintf(stderr, "-----------------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. Your input isn't a directory\n");
    fprintf(stderr, "-----------------------------------------------------\n");
    exit(1);
  }

  if ( (statbuf.st_mode & S_IWUSR) != S_IWUSR ) 
  {
    fprintf(stderr, "------------------------------------------\n");
    fprintf(stderr, "Invalid directory entry. It isn't writable\n");
    fprintf(stderr, "------------------------------------------\n");
    exit(1);
  }
}



void fetch(char *url,char *dir,char *d_r){
char cmd[500]={0},dg[100]={0},i[10];
num1++;
i[0]=num1+48;
i[1]='\0';
strcat(cmd,"wget --no-check-certificate -O ");
strcat(cmd,dir);


strcpy(dg,"/temp");
strcat(dg,i);
strcat(dg,".txt");
strcpy(d_r,dir);
strcat(d_r,dg);
strcat(dg," ");
strcat(cmd,dg);
strcat(cmd,url);
system(cmd);
}



int filesize(char *d){
struct stat st;
stat(d,&st);
int f=st.st_size;
return f;
}



void file(char **setlink,char *dir,char *d2,int s,char *url){

char* d,dd[100],h[2];
h[0]='/';
h[1]='\0';
int i=0,k=0,p=0,a=0,rep=0,j,g,flag=0,flag1=0;
char filepath[100]={0},*c;
c=(char *)malloc(s+1*(sizeof(char)));
strcat(filepath,d2);
FILE *fp=fopen(filepath,"r");

char nfile[100]={0},link[1000][url_lenght],f_n[100],dg[10];
num++;
dg[0]=num+48;
dg[1]='\0';
strcat(nfile,dir);

strcpy(f_n,"/f_name");
strcat(f_n,dg);
strcat(f_n,".txt");

strcat(nfile,f_n);
FILE *fp1=fopen(nfile,"w");
while(!feof(fp)){
fgets(c,s+1,fp);
d=strstr(c,"a href");

if(d){
j=0;
while(c[j]!='\0' && rep!=max_u){
flag1=0;
if(c[j]=='a' && c[j+2]=='h' && c[j+5]=='f'){
int r=j+8;
int n=0;

while(c[r]!='"'){
link[a][n]=c[r];
n++;
r++;
}
link[a][n]='\0';
p=0;

if(strcmp(link[a],url)!=0 && link[a][0]!='\0' && link[a][0]!='#' && link[a][0]!='/' ){
//printf("%s*++++++++++++++++++++++++++**%d\n",link[a],jj);
for(g=0;g<jj;g++){
strcpy(dd,setlink[g]);
strcat(dd,h);
if(strcmp(setlink[g],link[a])==0 || strcmp(dd,link[a])==0){
flag1=1;
//printf("%d++++++%s\n",g,setlink[g]);
}
}
if(flag1==0){
setlink[jj]=link[a];
printf("%s*****%s\n",url,setlink[jj]);
jj++;
rep++;
}
if(rep==max_u)
{
break;
}
}

a++;
}
j++;
}
}
fputs(c,fp1);

}


}


int main(int argc ,char** argv){
struct node* head;
struct node* tail;
int i=0,j=0,l=0,kl=0;
char ch[100]={0},a[1000],fl[1000],*d_r,*setlink[100000]={0};
d_r=(char *)malloc(100*(sizeof(char)));
if(argc<4)
printf("less argument");
else{
int dep=0,az=argv[3][0]-48;
kl=max_u;
for(i=1;i<az;i++){
dep=dep+kl;
kl=kl*max_u;
}i=0;
valid(argv[1]);
testDir(argv[2]);
fetch(argv[1],argv[2],d_r);

int g=filesize(d_r);

char dd[100],h[2];
h[0]='/';
h[1]='\0';
strcpy(dd,argv[1]);
strcat(dd,h);
i=0;
setlink[jj]=argv[1];
jj++;
file(setlink,argv[2],d_r,g,dd);
pp=0;
while(pp<jj){

valid(setlink[pp]);
fetch(setlink[pp],argv[2],d_r);
g=filesize(d_r);
file(setlink,argv[2],d_r,g,setlink[pp]);
pp++;
if(pp==dep)
break;
}
for(i=0;i<jj;i++){
l=strlen(setlink[i]);
l=l/5;
headd(setlink[i],l);
}
print1();
}
return 0;
}

