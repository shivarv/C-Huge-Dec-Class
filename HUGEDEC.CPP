#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*
 int compstr(char *,char*)
 char *add(char *,char *)
 char * sub(char *,char *,int *)
 char * mul(char * ,char *)
 char * get()
 int validlen(char *)
 set (char *) //nt cr
 destructor//nt cr


*/

class HugeInt
{
  char *v,*dv;
  int l,dl,neg;
  public:
  HugeInt()
  {                                 //try to stop 0 at const level becoz it
    neg=0;				   //complicates in additon,mul etc

    v=NULL;
    l=0;
    dv=NULL;
    dl=0;
    // cout<<"in cons empt::\n";
  }
   HugeInt(float f)
  {
  //  cout<<"in cons float::";
     if(f<0)
    {
      neg=1;
      f=-f;
    }
    else
     neg=0;
    float temp=f,dps;
    long int mv=f;

    dps=f-mv;
    dl=0;
    long int j=mv;
       l=0;
    while(j>0)
   {
     j/=10;
     l++;
   }
   if(!l)
   {
     v=new char[2];
     v[0]='0';
     l++;
   }
   else
   {	    //if l=0 set v='0' && l=1
		       //j becomes 0
     v=new char[l+1];//check fr i==0
     while(mv>0)
     {
       long int d=mv%10;
       v[j++]=d+'0';
       mv/=10;
     }
     v[j]='\0';
     strrev(v);
   }
  // cout<<"v over ::"<<v<<"----now dv::"<<endl;
  // cout<<"f::"<<f<<"::dps:"<<dps<<"\n";
   int i=0;                         //using float mdiff creates som
   while(i<6)    //   unknown error at the last 6th decim dig
   {
      dps*=10;
      i++;

   }
   dl=6;
   long int dj=(long int) dps;
 //  cout<<"\n::dj::"<<dj<<":::";
   j=0;
   dv=new char[dl+1];//check fr i==0
   while(j<6)
    {
	long int d=dj%10;
	dv[j++]=d+'0';
	dj/=10;
    }
    dv[j]='\0';
    strrev(dv);
  //  cout<<"obj creatd  "<<v<<"\t::d::"<<dv<<endl;
 //   cout<<"l::"<<l<<":::dl::"<<dl<<endl;

  }
   HugeInt(double f)
  {
  //  cout<<"in cons float::";
     if(f<0)
    {
      neg=1;
      f=-f;
    }
    else
     neg=0;
    double temp=f,dps;
    long int mv=f;

    dps=f-mv;
    dl=0;
    long int j=mv;
       l=0;
    while(j>0)
   {
     j/=10;
     l++;
   }
   if(!l)
   {
     v=new char[2];
     v[0]='0';
     l++;
   }
   else
   {	    //if l=0 set v='0' && l=1
		       //j becomes 0
     v=new char[l+1];//check fr i==0
     while(mv>0)
     {
       long int d=mv%10;
       v[j++]=d+'0';
       mv/=10;
     }
     v[j]='\0';
     strrev(v);
   }
  // cout<<"v over ::"<<v<<"----now dv::"<<endl;
  // cout<<"f::"<<f<<"::dps:"<<dps<<"\n";
   int i=0;                         //using float mdiff creates som
   while(i<6)    //   unknown error at the last 6th decim dig
   {
      dps*=10;
      i++;

   }
   dl=6;
   long int dj=(long int) dps;
 //  cout<<"\n::dj::"<<dj<<":::";
   j=0;
   dv=new char[dl+1];//check fr i==0
   while(j<6)
    {
	long int d=dj%10;
	dv[j++]=d+'0';
	dj/=10;
    }
    dv[j]='\0';
    strrev(dv);
  //  cout<<"obj creatd  "<<v<<"\t::d::"<<dv<<endl;
 //   cout<<"l::"<<l<<":::dl::"<<dl<<endl;

  }


  HugeInt(char a)
  {
   // cout<<"in cons char::";
    int i=0;
    neg=0;  //neg bit
    v=NULL;
    if(a!='\o')
    {
      v=new char[2];
      v[i++]=a;
      v[i]='\0';
    }
     l=1;
     dv=NULL;
     dl=0;
       // cout<<"obj creatd"<<v<<"\t";
  }

   HugeInt(long int i)
  {
   long int j;
   //cout<<"in cons lnint:: i:"<<i<<"::";
   if(i<0)
   {
    neg=1;
    j=-i;
   }
   else
   {
    j=i;
    neg=0;
   }
   l=0;
    while(j>0)
   {
   j/=10;
   l++;
   }
   if(!l)
   {
    v=new char[2];
    v[l]='0';
    v[++l]='\0';
   }
   else
   {
     if(neg)
       i=-i;                  //j becomes 0
     v=new char[l+1];//check fr i==0
     while(i>0)
     {
       long int d=i%10;
       v[j++]=d+'0';
       i/=10;
     }
     v[j]='\0';
     strrev(v);
   }
    v=trim(v);
   l=strlen(v);
     dv=NULL;
     dl=0;
   cout<<"obj creatd"<<v<<"\t";
  }
  HugeInt(int i)
  {
   cout<<":in cons int:: i::"<<i<<"::";
   int j;
   if(i<0)
    {
     j=-i;
     neg=1;
    }
    else
    {
     j=i;
     neg=0;
  }
   l=0;
    while(j>0)
   {
   j/=10;
   l++;
   }                  //j becomes 0
   v=new char[l+1];
   if(neg)
     i=-i;
   while(i>0)
   {
    int d=i%10;
    v[j++]=d+'0';
    i/=10;
   }
   v[j]='\0';
   strrev(v);
   v=trim(v);
   l=strlen(v);
   dv=NULL;
   dl=0;
  cout<<"constr:i:"<<v<<"\t";
   }
   HugeInt(HugeInt &o)
   {
      int ml,mdl,mneg;
      char *mv=NULL,*mdv=NULL;
      ml=o.l;
      mdl=o.dl;
      mneg=o.neg;
      if(o.v!=NULL)
      {
	mv=new char[o.l+1];
	strcpy(mv,o.v);
      }
      if(o.dv!=NULL)
      {
       mdv=new char[o.dl+1];
       strcpy(mdv,o.dv);
      }
      if(v!=NULL)
       delete []v;
      v=mv;
      if(dv!=NULL)
	delete []dv;
      dv=mdv;
      l=ml;
      dl=mdl;
      neg=mneg;

      cout<<"in copy cons:v:"<<o.v<<":l:"<<o.l<<":"<<endl;

   }

  HugeInt(char *p)
  {
    //cout<<"cons sting::"<<p<<"--";
    l=strlen(p);

    neg=0;
    if(p[0]=='-')
    {
     //  cout<<":in neg:";
       neg=1;
       v=new char[l];   //reduce it to neg bit form
       strrev(p);
       strncpy(v,p,l-1);
       v[l-1]='\0';
       strrev(v);
       l--;
       strrev(p);
       if(deci(v))
       {
      //	 cout<<":in deci:";
	 char *ms;
	 ms=new char[l+1];
	 strcpy(ms,v);
       //	 cout<<"::ms::"<<ms;
	 delete[]v;
	 v=NULL;
	 seperator(ms);
	 delete []ms;
       }
       else
       {
	 dv=NULL;
	 dl=0;
       }
    }
    else
    {
      if(deci(p))
      {
	seperator(p);
      }
      else
      {
	v=new char[l+1];
	strcpy(v,p);
	dv=NULL;
	dl=0;
      }
    }
   v=trim(v);
   l=strlen(v);
   if(dv!=NULL)
   {
     dv=decitrim(dv);
     dl=strlen(dv);
   }
  cout<<"char*cons end:l::"<<l<<"::dl::"<<dl<<"::v::"<<v<<".."<<dv<<"}}"<<endl;
  }

   int deci(char *s)
  {
    int ll=strlen(s)-1;
    for(int i=0;s[i];i++)
      {
	if(s[i]=='.')
	{
	  if(i==ll)
	 {
	    s[i]='\0'; //check where it happens to mak the change
	    return 0;  //the sit whre lst dig is '.'
	    //it affects other codes
	  }

	  return 1;
	}
      }
   return 0;
  }
  char * trim(char *s)
  {
   char *cpy;
   strrev(s);
  // cout<<"in trim||";
   int ml=strlen(s);
   if(ml==1)
   {
     cpy=new char[2];
     cpy[0]=s[0];
     cpy[1]='\0';
     delete [] s;
     return cpy;

   }
   ml--;


   while(s[ml]=='0')
   {
     ml--;
   }
   if(ml<=0)   //shuld be l==0 also check fr -1
     {
      cpy=new char[2];
      cpy[0]=s[0];
      cpy[1]='\0';
      delete []s;
      return cpy;
     }
   s[++ml]='\0';
   strrev(s);
   //cout<<s<<"|| " ;
   cpy=new char[ml+1];
   for(int i=0;s[i];i++)
       cpy[i]=s[i];
       cpy[i]='\0';
     //  cout<<cpy<<"::";
   delete []s;
   return cpy;



  }

  char * decitrim(char *s)            //needs to be changed
  {
    char *cpy;
    int ml=strlen(s);
    if(ml==1)
   {

     cpy=new char[2];
     cpy[0]=s[0];
     cpy[1]='\0';
     delete [] s;
     return cpy;

   }
   int i=1;
   while(s[ml-i]=='0')
     i++;
    if(i>=ml)
     {
	cpy=new char[2];
	cpy[0]=s[0];
	cpy[1]='\0';
	delete [] s;
	return cpy;

     }
   s[ml-i+1]='\0';
   cpy=new char[ml-i+2];
   for(i=0;s[i];i++)
       cpy[i]=s[i];
       cpy[i]='\0';
    // cout<<"bef del:::"<<cpy<<"::";
   delete []s;
  // cout<<":deci trim :"<<cpy;
   return cpy;



  }
   void deciequaliser(char **s,char **t) //mak sure it is nt passd wit null
  {
     // cout<<"::::in dci:equalser::";
      char *ss,*tt,*tmp;
      int i=0;
      ss=decitrim(*s);    //carefl nw (*ss is delted);
      //(*s)=decitrim(*s);
      tt=decitrim(*t);
    // cout<<"ss::"<<ss<<"::tt::"<<tt<<endl;
      if(strlen(ss)<strlen(tt))
      {
	 tmp=ss;
	 ss=new char[strlen(tt)+1];
	  for(i=0;tmp[i];i++)
	     ss[i]=tmp[i];
	  for(;i<strlen(tt);i++)
	    ss[i] ='0';
	  ss[i]='\0';
	  delete [] tmp;
       //	cout<<":ss::"<<ss<<":::tt::"<<tt<<endl;
      }
      else if(strlen(ss)> strlen(tt))
      {
	  tmp=tt;
	  tt=new char[strlen(ss)+1];
	  for(i=0;tmp[i];i++)
	     tt[i]=tmp[i];
	  for(;i<strlen(ss);i++)
	    tt[i] ='0';
	  tt[i]='\0';
	  delete [] tmp;
	 // cout<<":ss::"<<ss<<":::tt::"<<tt<<endl;
      }
      else;

       (*s)=ss;
       (*t)=tt;


      cout<<":in deciequl::(*s):::"<<(*s)<<"::(*t):::"<<(*t)<<endl;

  }




  void seperator(char *s)
  {
//     cout<<"in sep---  s::"<<s<<endl;
      int ml,i;
      HugeInt o3;
      ml=strlen(s);
      //if(s[strlen(s)-1]=='.')
     // {

      // o3.v=new char[strlen(s)+1];
     //  strcpy(o3.v,s);
      // o3.dv=new char(

    //  }
     // cout<<":s"<<s<<":ml:"<<ml<<endl;
      if(v!=NULL)
	{
	  delete[] v;
	  v=NULL;
	}
      if(dv!=NULL)
	{
	  delete[]dv;
	  dv=NULL;
	}
  //    cout<<"aft del---"<<s<<endl;
     // if(v==NULL && dv==NULL)
      //	 cout<<"both null"<<endl;
     // cout<<":ml::"<<ml<<endl;
      for(i=0;s[i]!='.';i++);
      v=new char[i+1];
      for(i=0;s[i]!='.';i++)
	    v[i]=s[i];
      v[i]='\0';
      v=o3.trim(v);
      l=i;
    // cout<<"::v::"<<v<<"::i::"<<i<<"::ml::"<<ml<<"::l::"<<l<<"::ml-i::"<<ml-i<<"::"<<endl;
      dl=ml-i-1;
      if(ml-i==1)
      {
       dv=new char[2];
       dv[0]='0';
       dv[1]='\0';
      }
      else
     {
       dv=new char[ml-i];// +1 nt needed becoz '.' space s freed
       i++;
    //  cout<<"::i::"<<i<<endl;
       int kl=0;
    //  cout<<"in seperator s::"<<s<<endl;
       for(;i<ml;i++)
	  {
	    dv[kl++]=s[i];
      //	   cout<<":i:"<<i<<":l::"<<kl-1<<":v:"<<dv[kl-1]<<"|";
	  }
	  dv[kl]='\0';
      // dl=kl;
      }
	cout<<"::in sep::v:"<<v<<":l:"<<l<<":dv:"<<dv<<":dl:"<<dl<<endl;


  }
  void decishift(int n) //pos rite shift else left shift
  {
     if(n==0)
     {
       return ;
     }
     char *s;
     int i=0;
    // cout<<"n::"<<n<<":l::"<<l<<":dl::"<<dl<<endl;
     if(n<0 && (-n)>=l)
       {
	 s=new char[dl-n+3]; // 0. \0 (3) + dl+n
     //	 cout<<":::all mem::"<<(dl-n+2)<<"block1:"<<endl;
       }
     else if(n>0 && n>=dl)
       {
	 s=new char[l+n+3];
     //	 cout<<"all mem::"<<l+n+3<<"block2:"<<endl;
       }
	// 1 fr null,'.',extra 0
     else
       {
	 s=new char[dl+l+2];
    //	 cout<<"all mem::"<<dl+l+2<<"block3:"<<endl;
       }

     int fil=0;
     if(n<=0)
	{
       //	   cout<<"::ins 1st block::"<<n<<endl;
	   n=-n;
	   if((n-l)>=0)
	      {
		int i=0;
		s[0]='0';
		s[1]='.';
		for(;i<(n-l);i++)
		  s[i+2]='0';
		  int j=i;      //keep tis 2
		for(i=0;i<l;i++)
		  s[j+i+2]=v[i];
		j=j+i;
		for(i=0;i<dl;i++)
		    s[j+i+2]=dv[i];
		s[j+i+2]='\0';

	      }
	    else
	    {
	 //     cout<<"ins dec\n";
	      for(i=0;i<l;i++)
	      {
		if(i==(l-n))
		  {
		     s[i+fil]='.';
	   //	     cout<<".:";
		     fil++;
		     s[i+fil]=v[i];
	    //	     cout<<s[i+fil]<<":";
		  }
		else
		  {
		     s[i+fil]=v[i];
	      //	     cout<<s[i+fil]<<":";
		  }
	      }
	       int k=i+fil;    //now k points aft '.' wit the fil
	       for(i=0;i<dl;i++)
	       {
		  s[k+i]=dv[i];
	    //	  cout<<s[k+i]<<":";
	       }
	       s[k+i]='\0';
	    }
      }
      else            // n greater than 0
      {
	for(i=0;i<l;i++)
	{
	  s[i]=v[i];
      //	  cout<<s[i]<<":";
	}
	int k=i,fil=0;
       //	cout<<"k::"<<k<<endl;
	for(i=0;i<dl;i++)      //code fr shift greaterr than deci digit
	{
	  if(i==n)
	   {
		s[k+i+fil]='.';
      //		cout<<".:";
		fil++;
		s[k+i+fil]=dv[i];
      //		cout<<s[k+i+fil]<<":";
	   }
	  else
	  {
	    s[k+i+fil]=dv[i];
  //	    cout<<s[k+i+fil]<<":";
	  }
	}
	int j;
	for(j=0;j<(n-dl);j++)
	{
	   s[k+i+fil+j]='0';
   //	   cout<<"0:";
	}
	if(n>=dl)
	{
	  s[k+i+fil+j++]='.';
	  s[k+i+fil+j++]='0';
   //	  cout<<"0:";      //check it
	  s[k+i+fil+j]='\0';
	}
	else
	{
   //	  cout<<"en::";
	  s[k+i+fil]='\0';
   //	  cout<<s<<"::";
	}



     }
 //    cout<<"\n---:"<<s<<"----:";
     this->seperator(s);
     delete[]s;

  }

  char * decimovepoint(char *ss,int n) //pos rite shift else left shift
  {
     cout<<"((in movpoint))";
     if(n==0)
     {

       return ss;
     }
     if(!deci(ss))
       return ss;
     char *s;
     int i=0,ml=strlen(ss),dl,il;
     for(;i<ml;i++)
     {
      if(ss[i]=='.')
       {
	il=i;
	break;
       }
     }

     dl=ml-il-1;
     cout<<"ml::"<<ml<<":l::"<<il<<":dl::"<<dl<<endl;
     if(n<0 && (-n)>=il)
       {

	 //n=-n;       n-il
	 s=new char[ml-n-il+3];//+2 1 fr \0 nd other fr xtra 0's
	 strcpy(s,ss);
	 strrev(s);

	  cout<<"\in -n blck\\(-n-il+1)="<<(-n-il+1)<"\\\\\\";
	  int til=il;
	 for(i=0;i<(-n-til+1);i++) //xtra 1 0 is usd so tht . is nt the 1st char
	   {
	     strcat(s,"0");
	     cout<<"in  loop:::"<<s<<"|||:";
	     il++;  //il contradicts so til is used
	   }

	 strrev(s);
	 cout<<"\\ans::"<<s<<"\\";
	 cout<<"{{all mem::"<<ml-n-il+3<<"::}}";
      }
     else if(n>0 && n>=dl)
       {
	 cout<<"\in +n blck\\(n-dl)="<<(n-dl)<<"\\\\\\";
	 s=new char[ml+n-dl+2];//+2 1 fr \0 nd other fr xtra 0's
	 cout<<"{{all mem::ml:"<<ml<<":n:"<<n<<":dl:"<<dl<<"::totmem::"<<(ml+n-dl+3)<<":block2:}}";
	 strcpy(s,ss);
	 int til=dl;
	 for(i=0;i<(n-til+1);i++) //xtra 1 0 is usd so tht . is nt the 1st char
	  {
	   strcat(s,"0");
	   dl++;       //here too til is used
	  }
	 cout<<s<<"\\";

       }
	// 1 fr null,'.',extra 0
     else
       {
	 cout<<"in n bet dl nd l block|||}";
	 s=new char[ml+1];
	 strcpy(s,ss);
	 cout<<"{{all mem::"<<ml+1<<":block3:}}";
       }

     int fil=0,j=0;
     if(n<=0)
	{
	   cout<<"::ins 1st block::-n::"<<n<<"__pos-n::";
	   n=-n;
	   int pos=il;
	   cout<<pos-n<<"::"<<"pos::"<<pos<<"|||";
	   for(i=pos;i>pos-n;i--)
	       s[i]=s[i-1];
	   s[pos-n]='.';
	   cout<<"(("<<s<<"))";//here almost tht . and 0 are already done


      }
      else            // n greater than 0
      {
	cout<<"::ins 2st block:::+n::"<<n<<"||";
	int pos=il;
	for(i=pos;i<pos+n;i++)
	       s[i]=s[i+1];
	   s[pos+n]='.';


     }
    cout<<"\---aft movpoit:"<<s<<"----:";
    delete []ss;
     return s;

  }


   char *add(char *s,char *t)             //change to char form
  {
     HugeInt o5;
     int len,i=0,val1=0,val2=0,val=0,c=0;
     int l1=strlen(s),l2=strlen(t);
     char *cpy,*cpy1,*cpy2;
     cpy1=new char[l1+1];
     cpy2=new char[l2+1];
     strcpy(cpy1,s);
     strcpy(cpy2,t);
     len=l1;
     if(l1>l2)
       {
	 // cout<<"inside block l1>l2::::";	  //change o2.l to o1.l length
	  len=l1;
	  cpy=new char[len+1];
	  strcpy(cpy,cpy2);
	  i=strlen(cpy);
	  strrev(cpy);       //must rev the str bef addng 0
	  while(i<len)
	     cpy[i++]='0';
	   cpy[i]='\0';
   //	   cout<<cpy<<endl;
	  l2=len;
	  delete []cpy2;
	  cpy2=new char[l1+1];
	  strcpy(cpy2,cpy);
	  delete []cpy;
	  strrev(cpy1);
       //	 cout<<"1st--"<<cpy1<<"2nd--"<<cpy2<<"--"; //o1 nd o2 r reversed
       }
     else if(l2>l1)
       {
	//  cout<<"inside l2>l1 block::";
	  len=l2;
	  cpy=new char[len+1];
	  strcpy(cpy,cpy1);
	  i=strlen(cpy);
	  strrev(cpy); // must rev bef overload wit o's
	  while(i<len)
	     cpy[i++]='0';
	   cpy[i]='\0';
     //	  cout<<cpy<<endl;
	  l1=len;            //so nw o1 cont rev val
	  delete []cpy1;
	  cpy1=new char[l1+1];
	  strcpy(cpy1,cpy);
	  delete []cpy;
	  strrev(cpy2);
	//  cout<<"1st--"<<cpy1<<"2nd--"<<cpy2<<"--";

       }
     else
       {
	// cout<<"inside l1==l2 block---";
	 strrev(cpy1);
	 strrev(cpy2);
       }
       // o3.v=new char[o1.l+2];//1 fr extra increment in addtion
      //  cout<<"aft 3 blocks{{}";
      // cout<<"cpy1::"<<cpy1<<"::cpy2::"<<cpy2<<";;";
      cpy=new char[len+2];
     // o3.l=o1.l+2;
     //cout<<"ouside loop"<<endl;
     for(i=0;i<l1;i++)
    {
      //   cout<<"c:"<<c<<":";
      val1=cpy1[i]-'0';
      //  cout<<"v1:"<<val1<<":";
      val2=cpy2[i]-'0';
      // cout<<"v2:"<<val2<<":";
      val=val1+val2+c;
      c=val/10;
      val%=10;
      cpy[i]=val+'0';
      //  cout<<"a:"<<cpy[i]<<":::";
    }
   // cout<<"c:"<<c;
   cpy[i++]=c+'0';
   cpy[i]='\0';
   strrev(cpy);
  // strcpy(o3.v,cpy);//strcpy(t,s)
 //   cout<<"cpy::"<<cpy<<":";
   delete []cpy1;
   delete []cpy2;
   cpy=o5.trim(cpy);
   return cpy;
  }
 HugeInt friend operator+(HugeInt &o1,HugeInt &o2) //withut ref cpy constr is called
 {
   cout<<"----inside addoverload fn----";
   char *ans,*ds=NULL,*dt=NULL;
   HugeInt o3;
   char *ians=NULL;
   char *dans=NULL;
   int nb=0,dnb=0;
   if(o1.dv==NULL && o2.dv==NULL)
   {
   }
   else
   {
     if(o1.dv==NULL && o2.dv!=NULL)
     {
	ds=new char[2];
	ds[0]='0';
	ds[1]='\0';
	dt=new char[(o2.dl +1)];
	strcpy(dt,o2.dv);
     }
     else if(o1.dv!=NULL && o2.dv==NULL)
     {
       dt=new char[2];
       dt[0]='0';
       dt[1]='\0';
       ds=new char[(o1.dl +1)];
       strcpy(ds,o1.dv);
     }
     else if(o1.dv!=NULL && o2.dv!=NULL)
     {
       ds=new char[(o1.dl +1)];
       strcpy(ds,o1.dv);
       dt=new char[(o2.dl +1)];
       strcpy(dt,o2.dv);
     }
       o3.deciequaliser(&ds,&dt);
   }
   cout<<"in op+:dv1:"<<o1.dv<<":dv2:"<<o2.dv<<"----";


   if((o1.neg==0) && (o2.neg==0) || ((o1.neg==1) && (o2.neg==1)))//(neg bit)
      {
	if(o1.neg==1)
	  cout<<"in bth neg::";
	else
	 cout<<"in bth pos:::";
	nb=o1.neg;
	ians=o3.add(o1.v,o2.v);
	if(ds!=NULL) //thn dv!=null
	  {
	     dans=o3.add(ds,dt);
	     if((strlen(dans)>strlen(ds)) && (dans[0]=='1'))
	      {
		  char *t=ians;
		  ians=o3.inc(ians);
		  //delete []t;
		  cout<<"::dans::"<<dans<<endl;
		  char *temp=new char[strlen(dans)+1];
		  strrev(dans);
		  strncpy(temp,dans,strlen(dans)-1);
		  temp[strlen(dans)-1]='\0';
		  strrev(temp);
		  cout<<"temp==::"<<temp<<endl;
		  delete [] dans;
		  dans=new char[strlen(temp)+1];
		  strcpy(dans,temp);
		  delete [] temp;

	      }
	      else
	      {



	      }
	     cout<<"ians::"<<ians<<"::dans."<<dans<<endl;
	     delete []ds;
	     delete []dt;
	     ans=new char[strlen(ians)+strlen(dans)+2]; //1 fr . nd \0
	     strcpy(ans,ians);
	     strcat(ans,".");
	     strcat(ans,dans);
	     delete []ians;
	     delete []dans;
	     cout<<":::ans::"<<ans<<"//"<<endl;
	   }
	   else
	   {
	      ans=ians;
	   }
			       //
      }
   else if(((o1.neg==0) && (o2.neg==1) )||((o1.neg=1) && (o2.neg==0)))//(neg bit)
      {
	 cout<<":in pos nd neg::";
	 ians=o3.sub(o1.v,o2.v,&nb);
	 if(ds==NULL)
	 {
	   ans=ians;
	   ians=NULL;
	   if(o1.neg==1 && o2.neg==0)
	     nb=!nb;
	 }
	 else
	 {
	    if(o3.compstr(o1.v,o2.v) > 0)   //he ians must atlest be 0
	     {
		 cout<<"in v1>v2::";
		 if(o3.decicompstr(ds,dt)<0)
		 {
		   cout<<"in dv1<dv2:::";
		   char *ns=new char[strlen(ds)+2];
		   char *nt=new char[strlen(dt)+2];
		   ns[0]='1';
		   ns[1]='\0';
		   strcat(ns,ds);
		   delete []ds;
		   nt[0]='0';
		   nt[1]='\0';
		   strcat(nt,dt);
		   delete [] dt;
		   dt=nt;
		   ds=ns;
		   cout<<"ds:"<<ds<<":dt:"<<dt<<"::::";
		   ians=o3.dec(ians,&dnb);  //here dnb is nt needed
		   char *mans=o3.sub(ds,dt,&dnb); //ds,dt
		   dans=new char[strlen(mans)];//cpy last n-1 digits
		   for(int m=1;m<strlen(mans);m++)
		      dans[m-1]=mans[m];
		     dans[m-1]='\0';
		   delete []mans;
		   cout<<"\n:ians:"<<ians<<":dans:"<<dans<<"::";
	       }
	       else if(o3.decicompstr(ds,dt)>0)
	       {
		 cout<<"in dv1>dv2:::\n";
		 dans=o3.sub(ds,dt,&dnb);
	       }
	       else
	       {
		  cout<<"in dv1==dv2::\n";
		  dans=new char[2];
		  dans[0]='0';
		  dans[1]='\0';
	       }
	    }
	    else if(o3.compstr(o1.v,o2.v)==0)
	    {
		cout<<"in v1==v2::";
		if(o3.decicompstr(ds,dt)<0) //thn dt -ds
		{
		   cout<<"in dv1<dv2:::";
		   nb=1;
		   char *ns=new char[strlen(ds)+1];
		   char *nt=new char[strlen(dt)+1];
		   strcpy(ns,ds);
		   delete []ds;
		   strcpy(nt,dt);
		   delete [] dt;
		   dt=nt;
		   ds=ns;
		   cout<<":ds:"<<ds<<":dt:"<<dt<<":::";
		   ians=o3.dec(ians,&dnb);  //here dnb is nt needed
		   char *mans=o3.sub(dt,ds,&dnb); //here dt,ds rite
		   dans=new char[strlen(mans)];//cpy last n-1 digits
		   for(int m=1;m<strlen(mans);m++)
		     dans[m-1]=mans[m];
		     dans[m-1]='\0';
		   delete []mans;
		   cout<<":ians:"<<ians<<":dans:"<<dans<<endl;

	       }
	       else if(o3.decicompstr(ds,dt)>0)
	       {
		  cout<<"in dv1>dv2:::\n";
		  char *ns=new char[strlen(ds)+1];
		  char *nt=new char[strlen(dt)+1];
		  strcpy(ns,ds);
		  delete []ds;
		  strcpy(nt,dt);
		  delete [] dt;
		  dt=nt;
		  ds=ns;
		  cout<<":"<<ds<<":"<<dt<<":\n";
		  ians=o3.dec(ians,&dnb);  //here dnb is nt needed
		  dans=o3.sub(ds,dt,&dnb); //chngd dt nd ds in sub
		  cout<<":i:"<<ians<<":d:"<<dans<<endl;
	       }
	       else
	       {
		 nb=0;
		 cout<<"in dv1==dv2::\n";
		 dans=new char[2];
		 dans[0]='0';
		 dans[1]='\0';
	       }
	  }
	  else if(o3.compstr(o1.v,o2.v) < 0) //here reverse everythng
	  {
					//since nw the sub is b/w o2 nd o1
		cout<<"in v1<2::";
		if(o3.decicompstr(dt,ds)<0)
		{
		   cout<<"in dv1<dv2:::\n";
		   char *ns=new char[strlen(ds)+2];
		   char *nt=new char[strlen(dt)+2];
		   ns[0]='0';
		   ns[1]='\0';
		   strcat(ns,ds);
		   nt[0]='1';
		   nt[1]='\0';
		   strcat(nt,dt);
		   delete []ds;
		   delete [] dt;
		   dt=nt;
		   ds=ns;
		   cout<<":"<<ds<<":"<<dt<<":\n";
		   ians=o3.dec(ians,&dnb);  //here dt ,ds sub
		   char *mans=o3.sub(dt,ds,&dnb);
		   dans=new char[strlen(mans)];//cpy last n-1 digits
		   for(int m=1;m<strlen(mans);m++)
		     dans[m-1]=mans[m];
		     dans[m-1]='\0';
		   delete []mans;
		    //needed oly in o1,o2.v equal to 0
		   cout<<":i:"<<ians<<":d:"<<dans<<endl;

	       }
	       else if(o3.decicompstr(dt,ds)>0)
	       {
		 cout<<"in dv1>dv2:::\n";
		 dans=o3.sub(dt,ds,&dnb); //here too dt,ds r reversed
	       }
	       else
	       {
		cout<<"in dv1==dv2::\n";
		dans=new char[2];
		dans[0]='0';
		dans[1]='\0';
	       }
	  }
	  ans=new char[strlen(ians)+strlen(dans)+2];
	  strcpy(ans,ians);
	  strcat(ans,".");
	  strcat(ans,dans);
	  cout<<":: ans::"<<ans<<endl;
	}
	if(o1.neg==1 && o2.neg==0)
	  nb=!(nb);

      }

   cout<<"ans ::" <<ans<<"::--";
   //ans=o3.trim(ans);     since ans has point in it
   //cout<<ans<<endl;
   if(o3.deci(ans)) //since its a friend fn
   {
     cout<<"cme in deci true::::";
     cout<<ans<<"::";
     o3.seperator(ans);
   }
   else
   {
     cout<<"bef set"<<o3.l<<"::dl::"<<o3.dl;
     o3.set(ans);
     cout<<"in + overload ::dl::"<<o3.dl<<"::::";
   }
   o3.neg=nb;
   o3.v=o3.trim(o3.v);
   cout<<"\nin +overfn ::v::"<<o3.v<<"::l::"<<o3.l<<"::dv::"<<o3.dv<<":dl::"<<o3.dl<<endl;
   cout<<"using cout   "<<o3<<endl;
   delete[] ans;
   cout<<"aft ans del::"<<o3<<endl;
   cout<<"bef ret in +over\n";
   return o3;

 }







  HugeInt friend operator-(HugeInt &o1,HugeInt &o2)
  {
   char *ans,*ians=NULL,*dans=NULL,*ds=NULL,*dt=NULL;
   int nb=0,dnb=0;//(neg bit)  dnb is nt needed
   HugeInt o3;
   if(o1.dv==NULL && o2.dv==NULL)
   {

   }
   else
   {
    if(o1.dv==NULL && o2.dv!=NULL)
   {
     ds=new char[2];
     ds[0]='0';
     ds[1]='\0';
     dt=new char[(o2.dl +1)];
     strcpy(dt,o2.dv);
     //o1.dl=1;
   }
   else if(o1.dv!=NULL && o2.dv==NULL)
   {
     dt=new char[2];
     dt[0]='0';
     dt[1]='\0';
     ds=new char[(o1.dl +1)];
     strcpy(ds,o1.dv);
     //o2.dl=1;
   }
   else if(o1.dv!=NULL && o2.dv!=NULL)
   {

     ds=new char[(o1.dl +1)];
     strcpy(ds,o1.dv);
     dt=new char[(o2.dl +1)];
     strcpy(dt,o2.dv);
   }
    o3.deciequaliser(&ds,&dt);
     cout<<":dv1:"<<o1.dv<<":dv2:"<<o2.dv<<endl;
   }


   if(((o1.neg==0) && (o2.neg==0)) ||((o1.neg==1) && (o2.neg==1)))
    {
       cout<<":in pos nd neg::";
       ians=o3.sub(o1.v,o2.v,&nb);
       if(ds==NULL)
       {
	 ans=ians;
	 ians=NULL;
	 if(o1.neg==1 && o2.neg==1)
	   nb=!nb;
       }
       else
       {
	  if(o3.compstr(o1.v,o2.v) > 0)   //he ians must atlest be 0
	  {
	       cout<<"in v1>v2::";
	       if(o3.decicompstr(ds,dt)<0)
	       {
		 cout<<"in dv1<dv2:::\n";
		 char *ns=new char[strlen(ds)+2];
		 char *nt=new char[strlen(dt)+2];
		 ns[0]='1';
		 ns[1]='\0';
		 strcat(ns,ds);
		 delete []ds;
		 ns[0]='0';
		 ns[1]='\0';
		 strcat(nt,dt);
		 delete [] dt;
		 dt=nt;
		 ds=ns;
		 cout<<":"<<ds<<":"<<dt<<":\n";
		 ians=o3.dec(ians,&dnb);  //here dnb is nt needed
		 char *mans=o3.sub(ds,dt,&dnb); //ds,dt
		 dans=new char[strlen(mans)];//cpy last n-1 digits
		 for(int m=1;m<strlen(mans);m++)
		     dans[m-1]=mans[m];
		     dans[m-1]='\0';
		 delete []mans;
		 cout<<":i:"<<ians<<":d:"<<dans<<endl;
		 /*ans=new char[strlen(ians)+strlen(dans)+2];
		 strcpy(ans,ians);
		 strcat(ans,".");
		 strcat(ans,dans);
		 delete []ians;
		 delete []dans;
		 cout<<":: ans::"<<ans;

		*/
	       }
	       else if(o3.decicompstr(ds,dt)>0)
	       {
		 cout<<"in dv1>dv2:::\n";
		 dans=o3.sub(ds,dt,&dnb);
	       }
	       else
	       {
		cout<<"in dv1==dv2::\n";
		dans=new char[2];
		dans[0]='0';
		dans[1]='\0';
	       }
	  }
	  else if(o3.compstr(o1.v,o2.v)==0)
	  {
	       cout<<"in v1==v2::";
	       if(o3.decicompstr(ds,dt)<0) //thn dt -ds
	       {
		 cout<<"in dv1<dv2:::\n";
		 nb=1;
		 char *ns=new char[strlen(ds)+1];
		 char *nt=new char[strlen(dt)+1];
		 strcpy(ns,ds);
		 delete []ds;
		 strcpy(nt,dt);
		 delete [] dt;
		 dt=nt;
		 ds=ns;
		 cout<<":"<<ds<<":"<<dt<<":\n";
		 ians=o3.dec(ians,&dnb);  //here dnb is nt needed
		 char *mans=o3.sub(dt,ds,&dnb); //here dt,ds rite
		 dans=new char[strlen(mans)];//cpy last n-1 digits
		 for(int m=1;m<strlen(mans);m++)
		     dans[m-1]=mans[m];
		     dans[m-1]='\0';
		 delete []mans;
		 cout<<":i:"<<ians<<":d:"<<dans<<endl;

	       }
	       else if(o3.decicompstr(ds,dt)>0)
	       {
		 cout<<"in dv1>dv2:::\n";
		 //nb=0;               //hence positive
		 char *ns=new char[strlen(ds)+1];
		 char *nt=new char[strlen(dt)+1];
		 strcpy(ns,ds);
		 delete []ds;
		 strcpy(nt,dt);
		 delete [] dt;
		 dt=nt;
		 ds=ns;
		 cout<<":"<<ds<<":"<<dt<<":\n";
		 ians=o3.dec(ians,&dnb);  //here dnb is nt needed
		 dans=o3.sub(ds,dt,&dnb); //chngd dt nd ds in sub
		 cout<<":i:"<<ians<<":d:"<<dans<<endl;
	       }
	       else
	       {
		 nb=0;
		 cout<<"in dv1==dv2::\n";
		 dans=new char[2];
		 dans[0]='0';
		 dans[1]='\0';
	       }
	  }
	 else if(o3.compstr(o1.v,o2.v) < 0) //here reverse everythng
	 {
					//since nw the sub is b/w o2 nd o1
		cout<<"in v1<2::";
		if(o3.decicompstr(dt,ds)<0)
		{
		   cout<<"in dv1<dv2:::\n";
		   char *ns=new char[strlen(ds)+2];
		   char *nt=new char[strlen(dt)+2];
		   ns[0]='0';
		   ns[1]='\0';
		   strcat(ns,ds);
		   nt[0]='1';
		   nt[1]='\0';
		   strcat(nt,dt);
		   delete []ds;
		   delete [] dt;
		   dt=nt;
		   ds=ns;
		   cout<<":"<<ds<<":"<<dt<<":\n";
		   ians=o3.dec(ians,&dnb);  //here dt ,ds sub
		   char *mans=o3.sub(dt,ds,&dnb);
		   dans=new char[strlen(mans)];//cpy last n-1 digits
		   for(int m=1;m<strlen(mans);m++)
		     dans[m-1]=mans[m];
		     dans[m-1]='\0';
		   delete []mans;
		    //needed oly in o1,o2.v equal to 0
		   cout<<":i:"<<ians<<":d:"<<dans<<endl;

	       }
	       else if(o3.decicompstr(dt,ds)>0)
	       {
		 cout<<"in dv1>dv2:::\n";
		 dans=o3.sub(dt,ds,&dnb); //here too dt,ds r reversed
	       }
	       else
	       {
		cout<<"in dv1==dv2::\n";
		dans=new char[2];
		dans[0]='0';
		dans[1]='\0';
	       }
	 }
	       ans=new char[strlen(ians)+strlen(dans)+2];
	       strcpy(ans,ians);
	       strcat(ans,".");
	       strcat(ans,dans);
	       cout<<":: ans::"<<ans;
      }
    if(o1.neg==1 && o2.neg==1)
    {
	 nb=!nb;
    }
  }


   else if((o1.neg==0 && o2.neg==1) || (o1.neg==1 && o2.neg==0))   // bth pos
   {
       nb=o1.neg;
       ians=o3.add(o1.v,o2.v);
       if(ds!=NULL) //thn dv!=null
	{
	     dans=o3.add(ds,dt);
	     if((strlen(dans)>strlen(ds)) && (dans[0]=='1'))
	      {
		  char *t=ians;
		  ians=o3.inc(ians);
		  //delete []t;
		  cout<<"dans::"<<dans<<endl;
		  char *temp=new char[strlen(dans)+1];
		  strrev(dans);
		  strncpy(temp,dans,strlen(dans)-1);
		  temp[strlen(dans)-1]='\0';
		  strrev(temp);
		  cout<<"temp==::"<<temp<<endl;
		  delete [] dans;
		  dans=new char[strlen(temp)+1];
		  strcpy(dans,temp);
		  delete [] temp;

	      }
	      else
	      {



	      }
	      cout<<"i::"<<ians<<"."<<dans<<endl;
	     delete []ds;
	     delete []dt;
	     ans=new char[strlen(ians)+strlen(dans)+2]; //1 fr . nd \0
	     strcpy(ans,ians);
	     strcat(ans,".");
	     strcat(ans,dans);
	     delete []ians;
	     delete []dans;
	     cout<<"//ans::"<<ans<<"//"<<endl;
	 }
	 else
	  {
	      ans=ians;
	  }
	 cout<<"::::ans sign::::"<<nb<<"++++";
   }

   cout<<"ans ::" <<ans<<"::";
   //ans=o3.trim(ans);     since ans has point in it
   //cout<<ans<<endl;
   if(o3.deci(ans)) //since its a friend fn
   {
     cout<<"cme in deci true\n";
     cout<<ans;
     o3.seperator(ans);
   }
   else
   {
     cout<<"bef set"<<o3.l<<"::dl::"<<o3.dl;
     o3.set(ans);
     cout<<"in + overload ::dl::"<<o3.dl;
   }
   o3.neg=nb;
   o3.v=o3.trim(o3.v);
   cout<<"\nin +overfn ::v::"<<o3.v<<"::l::"<<o3.l<<"::dv::"<<o3.dv<<":dl::"<<o3.dl<<endl;
   cout<<"using cout   "<<o3<<endl;
   delete[] ans;
   cout<<"aft ans del::"<<o3<<endl;
   cout<<"bef ret in +over\n";
   return o3;

  }

   char *sub(char * s,char *t,int *nb)
  {
    HugeInt o5;
    int l1=strlen(s); // chnge it to strlen
    int l2=strlen(t); //
    int len,i=0,bor=0,nbf=0;
    char *cpy,*cpy1,*cpy2;
    cpy1=new char[l1+1];
    cpy2=new char[l2+1];
    strcpy(cpy1,s);
    strcpy(cpy2,t);
   // cout<<"s:"<<cpy1<<"::t:"<<cpy2<<"::";
   // cout<<"calcmp fn::";
   // int lk=compstr(s,t);
   // cout<<"lk:"<<lk;
    if(compstr(s,t)==1)
     {
	 // cout<<"::aft 1st mainbl::";
	  nbf=0;

	  if(l1>l2)   //change cpy2 to cpy1 length
	  {        //try fr org leng inst of valid len
    //	    cout<<"1st sub..l1>l2::";
	    len=l1;
	    cpy=new char[l1+1];
	    strcpy(cpy,cpy2);
	    i=strlen(cpy);
	    strrev(cpy);       //must rev the str bef addng 0
	    while(i<len)
	      cpy[i++]='0';
	    cpy[i]='\0';
	    l1=len;
	    delete []cpy2;
	    cpy2=new char[len+1];
	    strcpy(cpy2,cpy);
	    delete []cpy;
	    strrev(cpy1); //o1 nd o2 r reversed
	 }
	 else
	 {
     //	   cout<<"2nd subbl::";
	   strrev(cpy1);
	   strrev(cpy2);
	 }

       }
    else if(compstr(s,t)== -1)
     {
       //	cout<<"in 2nd main bl::";
	 nbf=1;
	 if(l2>l1)
	  {
	//    cout<<"1st sbb l2>l1::";
	    len=l2;
	    cpy=new char[len+1];
	    strcpy(cpy,cpy1);
	    i=strlen(cpy);
	    strrev(cpy); // must rev bef overload wit o's
	    while(i<len)
	       cpy[i++]='0';
	    cpy[i]='\0';
	    cout<<cpy<<endl;
	    l1=len;            //so nw o1 cont rev val
	    delete []cpy1;
	    cpy1=new char[len+1];
	    strcpy(cpy1,cpy);
	    delete []cpy;
	    strrev(cpy2);

	 }
	else
	 {
	  //  cout<<"in 2sb.. l1==l2:::";
	    strrev(cpy1);
	    strrev(cpy2);
	 }
     }
    else
    {

  //    cout<<"in main 3rd block";
      cpy=new char[l1+1];
      for(i=0;i<l1;i++)   //set 0 nd return
	cpy[i]='0';
      cpy[i]='\0';
      *nb=0;
      cpy=o5.trim(cpy);
      delete []cpy1;
      delete []cpy2;
      cout<<"in sub::"<<s<<"::-::"<<t<<"::"<<cpy<<":__";
      return cpy;

    }
  // o3.v=new char[o1.l+2];//1 fr extra increment in addtion
   cpy=new char[l1+1];
  if(nbf) //nbf=1
  {
    strcpy(cpy,cpy1);   //chngng 1  nd 2nd
    strcpy(cpy1,cpy2);
    strcpy(cpy2,cpy);
    delete []cpy;

  }
  cpy=new char[l1+1];
  int d1,d2,d;
   for(i=0;i<l1;i++)
   {
    //  cout<<"b:"<<bor<<":";
      d1=cpy1[i]-'0';
    //  cout<<"v1:"<<d1<<":";
      d2=cpy2[i]-'0';
    //  cout<<"v2:"<<d2<<":";
      if(bor)
      {
       d1--;
       //if(d1<0)
       bor=0;
      }
      if(d1<d2)
	{
	  d1+=10;
	  bor=1;
	}
      d=d1-d2;
      cpy[i]=d+'0';
     // cout<<"v:"<<cpy[i]<<":::";
   }
  // cout<<"c:"<<bor;
   cpy[i]='\0'; //no cary
   //cpy[i]='\0';
   strrev(cpy);
  // strcpy(o3.v,cpy);//strcpy(t,s)
  //  cout<<"cpy::"<<cpy<<":";
    *nb=nbf;
   delete []cpy1;
   delete []cpy2;
  // cout<<"in sub::"<<s<<"::-::"<<t<<"::"<<cpy<<":__";
   return cpy;
  }

  HugeInt friend operator%(HugeInt &o1,HugeInt &o2)
  {
    char *rem,*ans;
    HugeInt o3;
    int nb=o1.neg;
    ans=o3.div(o1.v,o2.v,0);
    ans=o3.trim(ans);
    o3.set(ans);
    o3.neg=nb;

    //o3.r=new char[strlen(rem)+1];
    //strcpy(o3.r,rem);
     return o3;		    //since remainder address gona be chand
				   //inside fn


  }


  HugeInt friend operator/(HugeInt &o1,HugeInt &o2)
  {
    char *ans,*s=NULL,*t=NULL;
    HugeInt o3;
    int nb=0,k=0;
    if(o1.neg==o2.neg)
      nb=0;

    else
      nb=1;
    if(o1.dv==NULL && o2.dv==NULL)	                   //assign tis 1 as a bit quo r reminder to return
    {
      ans=o3.div(o1.v,o2.v,1);
      ans=o3.trim(ans);
      o3.set(ans);
      o3.neg=nb;
    }
    else
    {
     if(o1.dv==NULL)
     {
      o1.dv=new char[2];
      strcpy(o1.dv,"0");
      o1.dl=1;
     }
     if(o2.dv==NULL)
     {
      o2.dv=new char[2];
      strcpy(o2.dv,"0");
      o2.dl=1;
     }
     int ll=0,noz=0,tl=0;
     if(o1.dl>o2.dl)          //tis is removing decipoint temprarily
      {
	   ll=o1.dl;
	   noz=o1.dl-o2.dl;
      }
      else
       {
	 ll=o2.dl;
	 noz=o2.dl-o1.dl;
       }
       tl=2*ll;
       s=new char[o1.l+ ll+1];
       t=new char[o2.l+ll+1];
       strcpy(s,o1.v);
       strcat(s,o1.dv);
       strcpy(t,o2.v);
       strcat(t,o2.dv);
       if(o1.dl<o2.dl)
       {
	    for(;k<noz;k++)
	     s[o1.l+o1.dl+k]='0';
	    s[o1.l+o1.dl+k]='\0';
       }
       else
       {
	    for(;k<noz;k++)
	       t[o2.l+o2.dl+k]='0';
	     t[o2.l+o2.dl+k]='\0';
       }
      ans=o3.decidivide(s,t,6);
      cout<<"::aft decidivide:::" <<ans<<"||";
      //char *temp=ans;
      //ans=o3.decimovepoint(ans,-tl);  // decimovepoint deletes ans
      //delete []temp;
      o3.seperator(ans);
      o3.neg=nb;

    }
    delete []t;
    delete []s;
    delete []ans;
    o3.v=o3.trim(o3.v);
    if(o3.dv!=NULL)
      o3.dv=o3.decitrim(o3.dv);
    return o3;		    //since remainder address gona be chand
				   //inside fn


  }                                      //no of decimals
  char * decidivide(char *s,char * t,int nod)
  {
     cout<<"in dec divid::"<<s<<"::t:"<<t<<endl;
     HugeInt o3;
     char *ds,*dt,*ans,*ians,*dans,*dtemp;
     int k=0,ml=0,sim=0;;
     dtemp=new char[2];
     if(strlen(s)>strlen(t))
	   ds=new char[strlen(s) + 2];
     else
	   ds=new char[strlen(t)+2];
     dt=new char[strlen(t)+1];
     strcpy(ds,s);
     strcpy(dt,t);
     ians=new char[2];
     strcpy(ians,"0");
     dans=new char[nod+1];          // one fr .
     //ans=new char[strlen(ds)+1 + nod +1];
    // strcpy(ans,"0");
     if(o3.compstr(ds,dt)==0)
      {
		strcpy(ians,"0");

      }
      else
      {
       while(o3.compstr(ds,dt)>=0)
       {
	 char *temp=ds;
	 ds=o3.sub(ds,dt,&sim);
	 ds=o3.trim(ds);
	 delete []temp;
	 ians=o3.inc(ians);
       }
      }
      cout<<":ds:"<<ds<<":dt:"<<dt<<":a:"<<ians<<"____";
    //  strcat(ans,".");
      strcat(ds,"0");
      cout<<":ds:"<<ds<<":dt:"<<dt<<":a:"<<ians<<"____nw deci____\n";

    for(int i=0;i<nod;i++)
     {
	 if(o3.compstr(ds,"0")==0)
	{
	 if(i==0)
	  strcpy(dans,"0");
	 else
	  strcat(dans,"0");
	 break;
	}
	if(o3.compstr(ds,dt)==0)
	{
	 if(i==0)
	  strcpy(dans,"1");
	 else
	  strcat(dans,"1");
	 break;
	}
	strcpy(dtemp,"0");
	while(o3.compstr(ds,dt)>=0)
	{
	    char *temp=ds;


	    ds=o3.sub(ds,dt,&sim);
	    ds=o3.trim(ds);
	    if(i==3)
	     cout<<"<"<<ds<<">::";
	    delete []temp;
	    dtemp=o3.inc(dtemp);

	    dtemp=o3.trim(dtemp);
	    cout<<"<dt:"<<dtemp<<">:";
       }
       if(i==3)
	cout<<"\n";
	 if(i==0)
	  strcpy(dans,dtemp);
	 else
	  strcat(dans,dtemp);
	 cout<<":ds:"<<ds<<":dt:"<<dt<<":dtmp:"<<dtemp<<"_||";
	 cout<<"{{dan::"<<dans<<"}}";
	 strcat(ds,"0");
	 cout<<"::ds::"<<ds<<":::";
	 //cout<<":ds:"<<ds<<":dt:"<<dt<<":a:"<<dans<<"_\n";
	 // strcpy(dtemp,"0");
     }


     //dans=o3.decitrim(dans);
     ans=new char[strlen(ians)+strlen(dans)+2];
     strcpy(ans,ians);
     strcat(ans,".");
     strcat(ans,dans);

     delete []ds;
     delete []dt;
     delete []dans;
     delete []ians;
     delete []dtemp;
     cout<<":ans::"<<ans<<"::";
     return ans;


  }
   char * div(char *s,char *t,int choice)
  {
    HugeInt o5;
    int l1=strlen(s); //return valid  str len
    int l2=strlen(t);   //chnge it to normal strn
    int len,i=0,bor=0,nbf=0;
    char *cpy,*cpy1,*cpy2,*rem;
    cpy1=new char[l1+1];
    cpy2=new char[l2+1];
    strcpy(cpy1,s);
    strcpy(cpy2,t);
    // cout<<"s:"<<cpy1<<"::t:"<<cpy2<<"::";
    // cout<<"calcmp fn::";
    // int lk=compstr(s,t);
    // cout<<"lk:"<<lk;
    if(compstr(s,"0")==0)
      {
	cpy=new char[2];
	cpy[0]='0';
	cpy[1]='\0';
	rem=new char[2];
	rem[0]='0';
	rem[1]='\0';

	delete[] cpy1;
	delete[] cpy2;
	if(choice)
	{
	  delete[] rem;
	  return cpy;
	}
	else
	{
	 delete[]cpy;
	 return rem;
	}
      }
    if(compstr(t,"0")==0)
    {
      // cpy=new char[2];
      //	cpy[0]='0';
       //	cpy[1]='\0';
	delete[] cpy1;
	delete[] cpy2;
	cerr<<"dividebyzeroexception"<<endl;
	exit(0);
	return "1";
       //	exit(1);

    }
    if(compstr(t,"1")==0)
      {
	cpy=new char[l1+1];
	strcpy(cpy,s);
	rem=new char[2];
	rem[0]='0';
	rem[1]='\0';

	delete[] cpy1;
	delete[] cpy2;
	if(choice)
	{
	  delete[] rem;
	  return cpy;
	}
	else
	{
	 delete[]cpy;
	 return rem;
	}
      }
    if(compstr(s,t)==1)
     {
	 // cout<<"::aft 1st mainbl s1> s2::\n";
	//  nbf=0;

	  if(l1>l2)   //change cpy2 to cpy1 length
	  {
	  //  cout<<"1st sub..l1>l2::\n";
	    len=l1;
	    cpy=new char[l1+1];
	    strcpy(cpy,cpy2);
	    i=strlen(cpy);
	    strrev(cpy);       //must rev the str bef addng 0
	    while(i<len)
	      cpy[i++]='0';
	    cpy[i]='\0';
	    //strrev(cpy);
	    //cout<<cpy<<endl;
	    l1=len;
	    delete []cpy2;
	    cpy2=new char[len+1];
	    strcpy(cpy2,cpy);
	    delete []cpy;
	    strrev(cpy2);
	    //cpy2=o5.trim(cpy2);
       //	    cout<<"copy2::"<<cpy2<<endl; //cpy1 nd cpy 2 nt reversed fr div
	   // strrev(cpy1); //o1 nd o2 r reversed
	 }
	 else
	 {
	//  cout<<"l1==l2 2nd sub block ::";
	  //strrev(cpy1);
	 // strrev(cpy2);
	 }


    }
     else if(compstr(s,t)==0)
     {
     //	cout<<"inside 2nd block: s1== s2\n"<<endl;
	cpy=new char[2];
	cpy[0]='1';
	cpy[1]='\0';   //use trim
	if(choice)
	return cpy;
	else
	{
	    delete []cpy;
	    rem=new char[2];
	    rem[0]='0';
	    rem[1]='\0';
	    return rem;
	}
     }
     else
     {
   //	cout<<"inside 2nd block: s1< s2\n"<<endl;
	cpy1=new char[l1+1];
	for(int i=0;i<l1;i++)
	    cpy[i]='0';
	cpy[i]='\0';
	cpy=o5.trim(cpy);//try to del the cpy mem wastage   //use trim
	if(choice)
	   return cpy;
	else
	{
	    delete []cpy;
	    rem=new char[l1+1];
	    strcpy(rem,s);
	    return rem;
	}
     }
   //  cout<<"inside code\n";
     rem=new char[l1+1];
     strcpy(rem,cpy1);
   //  cout<<"rem::"<<rem<<"::cpy::"<<cpy2<<endl;
    // delete[] cpy;
     cpy=new char[2];
     cpy[0]='0';
     cpy[1]='\0';
   //  cout<<"rem::"<<rem<<"::cpy::"<<cpy2;
   //  cout<<"cmp::"<<(o5.compstr(rem,cpy2))<<endl;
     while(o5.compstr(rem,cpy2)>=0) // since val can be equal r more
     {
      // cout<<"inside comp:::";
       char *tmp; // fr mem efficiency
       int sim=0;
       tmp=rem;//   //nt needed since 1st chek
       rem=o5.sub(rem,cpy2,&sim);
       delete[] tmp;
       rem=o5.trim(rem);  // trim deletes [] actual val
       //cout<<":r:"<<rem<<":";
       //tmp1=cpy;
       cpy=o5.inc(cpy);
       cpy=o5.trim(cpy);
      // cout<<"q:"<<cpy;
     }
    delete[] cpy1;
    delete[] cpy2;

   // cout<<"rem::"<<rem<<"::quo::"<<cpy<<endl;
    if(choice)
    {
     delete[] rem;
     return cpy;
    }
    else
    {
    delete[] cpy;
    return rem;
  }
  }

  void set(char *v1)  //later mst check fr -neg
  {
  //  cout<<":in set:";
    if(v1==NULL)
      return;
    if(v!=NULL)
    {
     delete[]v;
    }
    l=strlen(v1);
     v=new char[l+1];
     strcpy(v,v1);
    dl=0;
    if(dv!=NULL)
      delete []dv;
    dv=NULL;

     cout<<"in set v::"<<v<<":l:"<<l<<"::dl::"<<dl<<endl;
  }



  int validlen(char *s)
  {
    int v1=0,i=0;
    int l=strlen(s);
    while(s[i++]=='0')
       v1++;
   // cout<<"lv::"<<l<<"v1::"<<v1<<endl;
    return l-v1;

  }



  friend istream&  operator>>(istream &in,HugeInt &o)
  {
    //cout<<"ins read dir"<<endl;
    int len,i;
    char *p;
    cout<<"enter length   ";
    in>>len;
     cout<<"enter a no  ";
    p=new char[len+1];
    if(o.v!=NULL)
      {
      delete[]o.v;
      o.l=0;
      o.neg=0;
     // o.r=o.inc=NULL;
      }
    in>>p;

    if(p[0]=='-')
    {
       o.l=strlen(p)-1;
       o.v=new char[o.l+1];
       o.neg=1;
       strrev(p);
       strncpy(o.v,p,o.l);
       o.v[o.l]='\0';
       strrev(o.v);
       if(o.deci(o.v))
       {
	// cout<<"caled deci true ::"<<endl;
	 char *ms;
	 ms=new char[o.l+1];
	 strcpy(ms,o.v);
  //	 cout<<"::ms::"<<ms;
	 delete[]o.v;
	 o.v=NULL;
	 o.seperator(ms);
	 delete []ms;
       }

    }
    else
    {
       o.l=strlen(p)-1;
       o.v=new char[o.l+1];
       o.neg=0;
       strcpy(o.v,p);
       if(o.deci(o.v))
       {
	// cout<<"caled deci true ::"<<endl;
	 char *ms;
	 ms=new char[o.l+1];
	 strcpy(ms,o.v);
  //	 cout<<"::ms::"<<ms;
	 delete[]o.v;
	 o.v=NULL;
	 o.seperator(ms);
	 delete []ms;
       }
    }     //des,source
    delete  []p;
   cout<<"in istr :::"<<o.v<<"."<<o.dv<<endl;
    return in;
  }
  friend ostream&  operator<< (ostream &out,HugeInt &o)
  {
     //out<<"val is ###";
     if(o.neg)
      cout<<"-";
     out<<o.v;
     if(o.dv==NULL);
     else
       out<<"."<<o.dv;
     out<<":l:"<<o.l<<":dl:"<<o.dl<<endl;
     return out;
  }
  int getl()
  {
    return l;
  }
  int getdl()
  {
    return dl;
  }


 int comp(HugeInt &o)   //==
   {
      HugeInt o3;
      int k,dk=-2;
      char *s=NULL,*t=NULL;
      cout<<"in comp ::\n";
	      // check bth dv nd o.dv exists
      if(dv!=NULL && o.dv==NULL)
      {

	s=new char[dl+1];
	strcpy(s,dv);
	t=new char[2];
	t[0]='0';
	t[1]='\0';
	o3.deciequaliser(&s,&t);
	cout<<"in comp::s:"<<s<<":t:"<<t<<endl;// rechange the code
      }
      else if(o.dv!=NULL && dv==NULL)
      {
	t=new char[dl+1];
	strcpy(t,dv);
	s=new char[2];
	s[0]='0';
	s[1]='\0';
	o3.deciequaliser(&s,&t);
	cout<<"in comp:s:"<<s<<":t:"<<t<<endl;
      }
      else if(dv!=NULL && o.dv!=NULL)
      {
	s=new char[dl+1];
	strcpy(s,dv);
	t=new char[o.dl+1];
	strcpy(t,o.dv);
	o3.deciequaliser(&s,&t);
	cout<<"in comp:s:"<<s<<":t:"<<t<<endl;
      }
      else
      {
       s=t=NULL;
      };

       if((neg==0) && (o.neg==1))
	{
	  if(s!=NULL)
	    delete []s;
	  if(t!=NULL)
	    delete []t;
	  return 1;

	}
       else if(neg==1 && o.neg==0)
       {
	 if(s!=NULL)
	    delete []s;
	 if(t!=NULL)
	    delete []t;
	 return -1;
       }
       else if(neg==1 && o.neg==1)
	  {
	    k=o3.compstr(v,o.v);
	    k=-k;
	    if(k==0)
	    {
	      dk=o3.decicompstr(s,t);
	      if(dk)
	       dk=-dk;
	      cout<<":"<<k<<":"<<dk<<":";
	      k=dk;
	    }
	    if(s!=NULL)
	     delete []s;
	    if(t!=NULL)
	     delete []t;
	    return k;

	  }
       else
       {
	    k=o3.compstr(v,o.v);
	    if(k==0)
	    {
	      dk=o3.decicompstr(s,t);
	      cout<<":"<<k<<":"<<dk<<":";
	      k=dk;
	    }
	    if(s!=NULL)
	     delete []s;
	    if(t!=NULL)
	     delete []t;
	    return k;
       }

  }
   int decicompstr(char *s,char *t)
   {
     cout<<":::in decicompstr:::";
     char *ss,*tt;
     if(s==NULL)
     {
      ss=new char[2];
      ss[0]=='0';
      ss[1]='\0';
     }
     else
     {
	ss=new char[strlen(s)+1];
	strcpy(ss,s);
     }
     if(t==NULL)
     {
      tt=new char[2];
      tt[0]=='0';
      tt[1]='\0';
     }
     else
     {
	tt=new char[strlen(t)+1];
	strcpy(tt,t);
     }

     HugeInt o3;
     ss=o3.decitrim(ss);
     tt=o3.decitrim(tt);
     cout<<"::::aft decitrim::ss::"<<ss<<"::tt::"<<tt<<endl;
     o3.deciequaliser(&ss,&tt);
  //    cout<<"::aft equaliser::ss::"<<ss<<"::tt::"<<tt<<endl;
     int ll=strlen(ss);
      for(int i=0;i<ll;i++)
     {
	if(ss[i]==tt[i])
	  continue;
	else  if(ss[i]>tt[i])
	  {
	    delete []ss;
	    delete []tt;
	    return 1;
	 }
	else
	{
	   delete []ss;
	   delete []tt;
	   return -1;
	}
    }
    delete []ss;
    delete []tt;
    return 0;

   }
  int compstr(char *s,char *t)
  {
     //cout<<"in comstrpfn::?";
     int l1=strlen(s),l2=strlen(t);
     int i=0,j;
     int vl1=0,vl2=0;
     //cout<<"l1::"<<l1<<"::l2::"<<l2<<"::";
     //cout<<s<<"::"<<t<<"::";
     while(s[i++]=='0')  // tis is to ensure 001 nt great to 01 etc
	   vl1++;
	   i=0;
    // cout<<"vl1:"<<vl1<<"::";
     while(t[i++]=='0')
	  vl2++;
     //cout<<"vl2:"<<vl2<<"::";

     if((l1-vl1) > (l2-vl2))
     {
     //  cout<<"in 1st\n";
	return 1;
     }
     else if( (l1-vl1) < (l2-vl2))
       {
      //	cout<<"in 2nd\n";
	return -1;
       }
     else
     {
      // cout<<"in 3rd\n";
       for(i=vl1,j=vl2;s[i];i++,j++)
       {
  //	  cout<<'.'<<s[i];
	  if(s[i]>t[j])
	    return 1;
	  else if(s[i]<t[j])
	    return -1;
	  else ;
       }
    }
     return 0;
  }


   int friend operator>(HugeInt &o1,HugeInt &o2)
   {
      int k=o1.comp(o2);
      if(k==1)
       return 1;
      else
       return 0;
   }
   int friend operator<(HugeInt &o1,HugeInt &o2)
   {
      int k=o1.comp(o2);
      if(k==-1)
       return 1;
      else
       return 0;
   }
   int friend operator<=(HugeInt &o1,HugeInt &o2)
   {
      int k=o1.comp(o2);
      if(k==-1|| k==0)
       return 1;
      else
       return 0;
   }
   int friend operator>=(HugeInt &o1,HugeInt &o2)
   {
      int k=o1.comp(o2);
      if(k==1||k==0)
       return 1;
      else
       return 0;
   }

   int friend operator==(HugeInt &o1,HugeInt &o2)
   {
      int k=o1.comp(o2);
      if(k==0 && (o1.neg== o2.neg))
       return 1;
      else
       return 0;
   }
   int friend operator!=(HugeInt &o1,HugeInt &o2)
   {
      int k=o1.comp(o2);
      if(k==0 && (o1.neg== o2.neg)) //same
       return 0;
      else
       return 1;
   }




    int check()
    {
      int i=0;
      for(i=0;i<l;i++)
      {
	if(v[0]=='-')
	   neg=1;
	else if(v[i]>='0' && v[i]<='9');
	else
	  return 1;
      }
      return 0;
    }
    char * get()
    {
      char *mv;
      mv=new char[l+1];
      strcpy(mv,v);
      return mv;
    }

    HugeInt& operator=(HugeInt &o)
    {
       int m;
       if(o.dv==NULL)
	 o.dl=0;
       else                     ///// dono why did tis went wrong
       {
	      o.dl=strlen(o.dv);
       }
      cout<<"in =start :v:"<<o.v<<":l:"<<o.l<<endl;
      int ml,mdl,mneg;
      char *mv=NULL,*mdv=NULL;
      ml=o.l;
      mdl=o.dl;
      mneg=o.neg;
      if(o.v!=NULL)
      {
	mv=new char[o.l+1];
	strcpy(mv,o.v);
      }
      if(o.dv!=NULL)
      {
       mdv=new char[o.dl+1];
       strcpy(mdv,o.dv);
      }
      if(v!=NULL)
       delete []v;
      v=mv;
      if(dv!=NULL)
	delete []dv;
      dv=mdv;
      l=ml;
      dl=mdl;
      neg=mneg;
      cout<<"in over= :v:"<<v<<":l:"<<l<<":dv:"<<dv<<":dl:"<<dl;
       cout<<":o.v:"<<o.v<<":o.l:"<<o.l<<":o.dv:"<<o.dv<<":dl:"<<o.dl<<endl;
      return (*this);

  }
      int operator[](int i)   // here i is the exact index value
    {
      if(i<0)
      {
	i=-i;
	return (v[i-1] - '0');
      }
      else
      return (v[i-1] -'0');

    }
	
    char* mul(char *s,char *t)    //change it char form
  {
    //cout<<endl<<"inside * fun__";
    char **sum,*ans;
    HugeInt o5;
    int c=0,i=0,k=0,j,l2,l1;
    l1=strlen(s);
    l2=strlen(t);
    char *cpy1,*cpy2;
    cpy1=new char[l1+1];
    cpy2=new char[l2+1];
    strcpy(cpy1,s);
    strcpy(cpy2,t);//start frm kth digit in 2nd iteration so to get 0 at begin
    ans=new char[l1+l2+2];    // if 999 * 999 thn 6 dig + 1 fr '\0'

       sum=new char*[l2];
       for(i=0;i<l2;i++)
	sum[i]=new char[l1+l2+1];
       strrev(cpy1);
       strrev(cpy2);
   //    cout<<"aft reveersed  "<<cpy1<<"\t"<<cpy2<<endl;

       for( i=0;cpy2[i];i++)
       {
	 c=0;
	 //cout<<"l"<<i+1<<"::";
	  int val1=cpy2[i]-'0';
	 for(j=0;cpy1[j];j++)
	 {

       //	  cout<<"c:"<<c;
     //	  cout<<"v1:"<<val1;
	   int val2=cpy1[j]-'0';
   //	 cout<<"v2:"<<val2;
	   int val=val1*val2+c;
	   c=val/10;
	   val%=10;
	  // int m=j+k;                //her fist k digits r skipd of val so
	   sum[i][j+k]=val+'0';
	   if(j==0)
	   {
	     for(int m=0;k>m;m++)
	      sum[i][m]='0';
 //	    cout<<"k:"<<k<<";";
     //	    cout<<"i"<<i+1<<"||";
	   }
	  //initial initialisation
	 //  cout<<"s:"<<sum[i][j+k]<<" ";   //print j+k

	 }
	 sum[i][k+j++]=c+'0';
       //	 cout<<"|c|"<<sum[i][k+j-1]<<":::";
	 while( k+j<l1+l2)
	  sum[i][k+j++]='0'; //j++ here
	   sum[i][k+j]='\0';
       //	  cout<<"::"<<i+1<<":"<<sum[i];
	 k++;
       }
      // cout<<endl<<"1st add"<<endl;
       c=0;
      for(i=0;i<l1+l2;i++)
       {
	  int val=0;
	  for(j=0;j<l2;j++)
	  {
	  int d=sum[j][i] -'0';

	 // cout<<sum[j][i]<<"::";
	  val+=d;
	  }

	  val+=c;//carry missing
	  c=val/10;
	  val%=10;
	  ans[i]=val+'0';
       //	cout<<"a:"<<ans[i]<<":"<<"c"<<c<<":";


       }
       ans[i]=c+'0';
       ans[++i]='\0';

   //  }
   for(int mmm=0;mmm<l2;mmm++)
      delete []sum[mmm];
       strrev(ans);
       delete []cpy1;
       delete []cpy2;
     //  cout<<"\nthe output is "<<ans<<"\\"<<endl;
       ans=o5.trim(ans);
       return ans;
  }


  friend HugeInt operator*(HugeInt &o1,HugeInt &o2)
  {
    HugeInt o3;
    cout<<"&&&in *ovrlod&&&&";
    char *s=NULL,*t=NULL;
    int nb=0,ll=0,ml;
    s=new char[o1.l+o1.dl+1];
    strcpy(s,o1.v);
    s=o3.trim(s);

    if(o1.dv!=NULL)
     {
	strcat(s,o1.dv);
	s=o3.decitrim(s);
	ll+=strlen(s);
     }
     t=new char[o2.l+o2.dl+1];
     strcpy(t,o2.v);
     t=o3.trim(t);
     if(o2.dv!=NULL)
      {


	strcat(t,o2.dv);
	t=o3.decitrim(t);
		ll+=strlen(t);
      }
     if((o1.neg==0 && o2.neg==0) || (o1.neg==1 && o2.neg==1))
	nb=o1.neg;
     else
      nb=1;
    cout<<":s::"<<s<<":t:"<<t<<":";
    char *ans=o3.mul(s,t);
    cout<<"---mul ans::"<<ans<<"---";
    ml=strlen(ans);
    o3.v=new char[ml-ll+1];
    cout<<":dl:"<<ll<<":tl"<<ml<<":il:"<<ml-ll<<"::--";
    if(ll)
    {
       int k;
       for(k=0;k<(ml-ll);k++)
	     o3.v[k]=ans[k];
	o3.v[k]='\0';

	cout<<":v::"<<o3.v<<"::";
	o3.dv=new char[ll+1];
       for(k=0;k<ll;k++)
	o3.dv[k]=ans[ml-ll+k];
	 o3.dv[k]='\0';

       cout<<"bef trim::"<<o3.v<<"::";
       o3.v=o3.trim(o3.v);
       cout<<"::aft trim::"<<o3.v<<"::";
       cout<<"::aft decitrim::"<<o3.dv<<"::";
       o3.dv=o3.decitrim(o3.dv);
       cout<<":aft trim:"<<o3.dv<<"::";
       o3.l=strlen(o3.v);
       o3.dl=strlen(o3.dv);
       cout<<"obj value::l:"<<o3.l<<":dl:"<<o3.dl<<":::";

    }
   else
     {
	o3.set(ans);
	o3.v=o3.trim(o3.v);
     }
    o3.neg=nb;
    if(s!=NULL)
      delete []s;
    if(t!=NULL)
      delete []t;
    t=s=NULL;
    delete []ans;
    return o3;
  }


  char *power(char *s,char *t)
  {
     HugeInt o3;
     char *cpy,*cpy1,*cpy2;
     int l1=strlen(s),l2=strlen(t),sim=0;
     cpy1=new char [l1+1];
     cpy2=new char[l2+1];
     strcpy(cpy1,s);
     strcpy(cpy2,t);
     if(o3.compstr(cpy2,"1")==0)
     {
	cpy=new char[l1+1];
	strcpy(cpy,cpy1);
     }
     else if(o3.compstr(cpy2,"0")==0)
       {
	 cout<<endl<<"str 0::";
	 cpy=new char[2];
	 cpy[0]='1';
	 cpy[1]='\0';
       }
     else
       {
	 cpy=new char[l1+1];
	 strcpy(cpy,cpy1);
	 //cout<<cpy<<"::"<<cpy1<<"::"<<cpy2;
	 cout<<endl<<"nt0::" ;
	 while(o3.compstr(cpy2,"1")==1)
	  {
	     cout<<"||in|";

	     char *temp=NULL;

	     cpy2=o3.dec(cpy2,&sim);
	     cout<<"|p|"<<cpy2<<"|";
	     temp=cpy;
	     cpy=o3.mul(cpy,cpy1);
	     delete [] temp;
	     cout<<"|a|"<<cpy;
	  }
  }
  delete[]cpy1;
  delete[]cpy2;
  return cpy;
  }
  friend HugeInt operator^(HugeInt o1,HugeInt o2)
  {
     if(o2.neg)
      {
	cout<<"errror"<<endl;
	exit(0);
      }
     HugeInt o3;
     int ml=0,ll;
     char *ans,*s,*t;
     s=new char[o1.l+o1.dl+1];
     strcpy(s,o1.v);
     if(o1.dv!=NULL)
       strcat(s,o1.dv);
     t=new char[o2.l+o2.dl+1];
     strcpy(t,o2.v);
     if(o2.dv!=NULL)
       strcat(t,o2.dv);
     ml=atoi(o2.v) *o1.dl;
     cout<<"|ml:|"<<ml<<":|";
     ans=o3.power(s,t);
     if(ml==0)
       {
	  o3.set(ans);
       }
     else
     {
	cout<<"|in decimal|";
	ll=strlen(ans);
	int i=0;
	o3.v=new char[ll-ml+1];
	for(;i<ll-ml;i++)
	  o3.v[i]=ans[i];
	o3.v[i]='\0';
	o3.l=i;
	cout<<"|v|"<<o3.v<<"|:l:"<<o3.l<<"|";
	o3.dv=new char[ml+1];
	for(;i<ll;i++)      //here i <= ll
	  o3.dv[i-o3.l]=ans[i];
	o3.dv[i-o3.l]='\0';
	o3.dl=ml;
	cout<<"|dv|"<<o3.dv<<"||dl"<<o3.dl<<"|";
     }
     if(o1.neg==1)
     {
       if((o2.v[0]=='0') || (o2.v[0]=='2') || (o2.v[0]=='4')|| (o2.v[0]=='6')|| (o2.v[0]=='8'))
	   o3.neg=0;
       else
	 o3.neg=1;
     }
     delete []ans;
     delete []s;
     delete []t;
     return o3;
  }



  char *inc(char *s)
  {
    int ml=strlen(s);
    char *cpy=new char[ml+1];
    strcpy(cpy,s);
    strrev(cpy);
    for(int i=0;i<ml;i++)
    {
       if(cpy[i]!='9')
	break;
       else
	cpy[i]='0';

    }
    //cout<<":nof 9:"<<i<<":"<<endl;
    if(i==ml)
    {
    // cout<<"ins no9==l\n";
     delete []cpy;
     cpy=new char[ml+2];
     cpy[0]='1';
     for(int j=1;j<ml+1;j++)
	    cpy[j]='0';
     cpy[j]='\0';
     delete [] s;
     return cpy;
    }
    cpy[i]+=1;
    strrev(cpy);
    delete []s;
    return cpy;


  }
    HugeInt operator++()
  {
     HugeInt o5;
     char *ans;
     int nb=neg;
     //char *ans=o5.add(v,"1");
     if(nb==0)
      ans=o5.inc(v);
     else
      ans=o5.dec(v,&nb);
     ans=o5.trim(ans);
    // delete[]v;  already deleted
     l=strlen(ans);
     v=new char[l+1];
     strcpy(v,ans);
     neg=nb;
     o5.set(ans);
     o5.neg=nb;
     if(dv!=NULL)
     {
      o5.dv=new char[dl+1];
      strcpy(o5.dv,dv);
      o5.dl=dl;
     }
     delete[] ans;
    // cout<<"in ++over::"<<v<<":l:"<<l<<endl;
     return o5;      //dnt retrn *this it causes destrctor

  }
  HugeInt operator--()
  {
     HugeInt o5;
     int nb=this->neg;
     char *ans;
     //char *ans=o5.sub(v,"1",&nb);
     if(nb==0)
      ans=o5.dec(v,&nb);
     else
      ans=o5.inc(v);
     ans=o5.trim(ans);
     neg=nb;
     l=strlen(ans);
     v=new char[l+1];
     strcpy(v,ans);

     delete[] ans;
     return *this;

  }
  char *dec(char *s,int *nbf)
  {
     HugeInt o5;
     int ml=strlen(s);
     char *cpy=new char[ml+1];
     strcpy(cpy,s);
     strrev(cpy);
     if(o5.compstr(s,"0")==0 )
     {
	 *nbf=1;
	 delete[] cpy;
	 cpy=new char[2];
	 cpy[0]='1';
	 cpy[1]='\0';
	 delete [] s;
	 return cpy;
     }
     for(int i=0;i<ml;i++)
	 {
	   if(cpy[i]!='0')
		break;
	   else
	    cpy[i]='9';

	 }
	 cpy[i]-=1;
	 strrev(cpy);
	 delete []s;
	 return cpy;
  }

 char  replacechar(char *s)
 {
   char a;
   if(strlen(s)==1)
   {
     a=s[0];
   }
   else if(s[0]=='1')
   {
     switch(s[1])
     {
       case '0' :
	 a='a';
	 break;
      case '1' :
	 a='b';
	 break;
       case '2' :
	 a='c';
	 break;
       case '3' :
	 a='d';
	 break;
	case '4' :
	 a='e';
	 break;
       case '5' :
	 a='f';
	 break;
   }
   }
   return a;
   }

 char* hex(char *s)
  {
     cout<<"||in hex fn||";
     char *cpy1,*rem=NULL,*ans,*val;
     HugeInt o3;
     int l1=strlen(s),k=0,i=0;
     cpy1=new char[l1+1];
     val=new char[3];
     strcpy(val,"16");
     strcpy(cpy1,s);
     ans=new char[l1+1];
     //cout<<"cpy1::"<<cpy1<<"rem::"<<rem<<endl;
     while(o3.compstr(cpy1,val)>0)
     {
       i++;
       char *temp;
       temp=rem;
       rem=o3.div(cpy1,val,0);
       rem=o3.trim(rem);
      // cout<<":r:"<<rem<<"::";
       if(temp!=NULL)
       delete []temp;
     //  cout<<":r:"<<rem<<"::";
       temp=cpy1;
	cpy1=o3.div(cpy1,val,1);
	cpy1=o3.trim(cpy1);
       delete []temp;
     //  cout<<":a:"<<cpy1<<"\t";
       char c=o3.replacechar(rem);
       ans[k++]=c;
       ans[k]='\0';
       if(i==l1)
       {
	 char *tt=ans;
	 l1=l1+3;
	 ans=new char[l1+1];
	 strcpy(ans,tt);
	 delete []tt;

       }
     }
     ans[k++]=o3.replacechar(cpy1);
     ans[k]='\0';
     delete []cpy1;
     delete []rem;
     strrev(ans);
     return ans;

 }
 char * replacestring(char a)
 {
   char *ans=new char[5];
   switch(a)
   {
     case 'a':
	  ans[0]='1';
	  ans[1]='0';
	  ans[2]='1';
	  ans[3]='0';
	  break;
     case 'b':
	  ans[0]='1';
	  ans[1]='0';
	  ans[2]='1';
	  ans[3]='1';
	  break;

      case 'c':
	  ans[0]='1';
	  ans[1]='1';
	  ans[2]='0';
	  ans[3]='0';
	  break;
      case 'd':
	  ans[0]='1';
	  ans[1]='1';
	  ans[2]='0';
	  ans[3]='1';
	  break;
     case 'e':
	  ans[0]='1';
	  ans[1]='1';
	  ans[2]='1';
	  ans[3]='0';
	  break;
     case 'f':
	  ans[0]='1';
	  ans[1]='1';
	  ans[2]='1';
	  ans[3]='1';
	  break;
     case '0':
	  ans[0]='0';
	  ans[1]='0';
	  ans[2]='0';
	  ans[3]='0';
	  break;
      case '1':
	  ans[0]='0';
	  ans[1]='0';
	  ans[2]='0';
	  ans[3]='1';
	  break;
     case '2':
	  ans[0]='0';
	  ans[1]='0';
	  ans[2]='1';
	  ans[3]='0';
	  break;
       case '3':
	  ans[0]='0';
	  ans[1]='0';
	  ans[2]='1';
	  ans[3]='1';
	  break;
	case '4':
	  ans[0]='0';
	  ans[1]='1';
	  ans[2]='0';
	  ans[3]='0';
	  break;
       case '5':
	  ans[0]='0';
	  ans[1]='1';
	  ans[2]='0';
	  ans[3]='1';
	  break;
	case '6':
	  ans[0]='0';
	  ans[1]='1';
	  ans[2]='1';
	  ans[3]='0';
	  break;
	 case '7':
	    ans[0]='0';
	    ans[1]='1';
	    ans[2]='1';
	    ans[3]='1';
	    break;
	  case '8':
	    ans[0]='1';
	    ans[1]='0';
	    ans[2]='0';
	    ans[3]='0';
	    break;
	  case '9':
	    ans[0]='1';
	    ans[1]='0';
	    ans[2]='0';
	    ans[3]='1';
	    break;
	    default:
	     cout<<"error\n";
   }
   ans[4]='\0';
   return ans;



 }
 char *oct(char *s)
 {
     char *cpy1,*rem=NULL,*ans,*val;
     HugeInt o5;
     int l1=strlen(s),k=0;
     cpy1=new char[l1+1];
     val=new char[3];
     strcpy(val,"8");
     strcpy(cpy1,s);
     ans=new char[l1+1];
     //cout<<"cpy1::"<<cpy1<<"rem::"<<rem<<endl;
     while(compstr(cpy1,val)>0)
     {
       char *temp;
       temp=rem;
       rem=o5.div(cpy1,val,0);
       rem=o5.trim(rem);
      // cout<<":r:"<<rem<<"::";
      if(temp!=NULL)
       delete []temp;
     //  cout<<":r:"<<rem<<"::";
       temp=cpy1;
	cpy1=o5.div(cpy1,val,1);
	cpy1=o5.trim(cpy1);
       delete []temp;
     //  cout<<":a:"<<cpy1<<"\t";
       char c=o5.replacechar(rem);
       ans[k++]=c;
     }
     ans[k++]=o5.replacechar(cpy1);
     ans[k]='\0';
     delete []cpy1;
     delete []rem;
     cpy1=rem=NULL;
     strrev(ans);
     ans=o3.trim(ans);
     return ans;
 }

 char* bin(char *s)
 {
     HugeInt o3;
     cout<<"||in bin fn||";
     char *cpy=o3.hex(s),*ans;
     int l1=strlen(cpy);
     cout<<"hex::"<<cpy<<"::";
     ans=new char(4*l1 +1);

     for(int i=0,k=0;i<l1;i++)
     {
	char *v=o3.replacestring(cpy[i]);
       //	cout<<":v:"<<v<<"||";
	if(!i)
	 strcpy(ans,v);
	else
	 strcat(ans,v);
	/*for(int j=0;j<4;j++)
	    ans[k++]=v[j];
	*/
	delete[]v;

     }
      //ans[k]='\0';
      ans=o3.trim(ans);
      return ans;
  }
  char *decibin(char *ss)
  {
    HugeInt o3;
   // cout<<"        deibin::::\n";
    int i,ll=strlen(ss),chfz=0;//to mak sure bin is nt zero
    char *sans=new char[ll+2],*ans=new char[ll+1];
    if(ss==NULL || ans==NULL)
     {
       cout<<"empty allocation\n";
       exit(0);
     }
    strcpy(sans,ss);
   // cout<<"||"<<sans<<"|||";
    if(o3.compstr(ss,"0")==0)
    {
       delete []ans;
       ans=new char[2];
       delete []sans;
       strcpy(ans,"0");
       return ans;
    }

    for(i=0;i<ll || chfz;i++)
    {
      //	  cout<<"{lop}"<<":"<<i+1<<"bef trim:"<<sans<<"}}";
	  int ml,zshift=0,tempi=0;
	  while(sans[zshift++]=='0');
	  zshift--;
	  sans=o3.trim(sans);
	//  cout<<"||aft trim::"<<sans<<"||zs::"<<zshift<<"__";
	  ml=strlen(sans);
	 // strcpy(nw,"0");
	  char *t=sans;

	  sans=o3.mul(sans,"2");
	//  cout<<";aft mul::;"<<sans<<";;";
	  delete []t;
	  if(strlen(sans)==ml)
	    {
	      ans[i]='0';
	      ans[i+1]='\0';
	      tempi=1;
	    }
	  else
	  {
	    if(zshift)
	       {
		 ans[i]='0';
		 zshift--;
		 tempi=1;
	       }
	    else
	       ans[i]='1';
	    ans[i+1]='\0';
	 }

	    t=new char[strlen(sans)+ zshift];//1 les to sans
	    for(int j=1;(j-tempi)<=strlen(sans);j++)
	      t[j-1]=sans[j-tempi];
	   //   cout<<"P"<<t<<"P";
	      strrev(t);    //'\0' is already i goes to t
	      for(j=0;j<zshift;j++)
		strcat(t,"0");
	      strrev(t);
	    delete []sans;
	    sans=t;
	   // cout<<"aftshift sans;;["<<sans<<"]::ans::"<<ans<<"::";
	    if(o3.compstr(sans,"0")==0)
	     {
	       //	ans[i]='0';
		break;
	     }

	 if((o3.compstr(ans,"0")==0))
	    {
	      chfz=1;
	      char *t=ans;
	      if(i+1>ll)
		{
		   ans=new char[i+3];      //size enlagemnt aft limit ll
		   strcpy(ans,t);
		   delete []t;


		}
	    }
	   else
	    chfz=0;


     }

	  delete []sans;
	  cout<<"||ans||" <<ans<"||";
	  return ans;
    }

  void decinormequaliser(char **s,char **t,int v)//v=0 norm else deci
  {
    cout<<"(in norfn :s:)"<<(*s)<<"::t::"<<(*t)<<"|||";
    char *ms=(*s),*mt=(*t),*ans1,*ans2;
    int l1=strlen(ms),l2=strlen(mt),i=0;
    if(v==0)
    {
       if(l1>l2)
       {
	 ans2=new char[l1+1] ;
	 strcpy(ans2,mt);
	 strrev(ans2);
	 for(;i<l1-l2;i++)
	   strcat(ans2,"0");
	 strrev(ans2);
	 ans1=new char[l1+1];
	 strcpy(ans1,ms);

       }
	else  if(l2>l1)
       {
	 ans1=new char[l2+1] ;
	 strcpy(ans1,ms);
	 strrev(ans1);
	 for(;i<l2-l1;i++)
	   strcat(ans1,"0");
	 strrev(ans1);
	 ans2=new char[l2+1];
	 strcpy(ans2,mt);
       }
       else
       {
	ans1=new char[l1+1];
	strcpy(ans1,ms);
	ans2=new char[l2+1];
	strcpy(ans2,mt);
       }

    }
    else
    {

       if(l1>l2)
       {
	 ans2=new char[l1+1] ;
	 strcpy(ans2,mt);
	 for(;i<l1-l2;i++)
	   strcat(ans2,"0");
	 ans1=new char[l1+1];
	 strcpy(ans1,ms);


       }
	else  if(l2>l1)
       {
	 ans1=new char[l2+1] ;
	 strcpy(ans1,ms);
	 for(;i<l2-l1;i++)
	   strcat(ans1,"0");
	 ans2=new char[l2+1];
	 strcpy(ans2,mt);
       }
       else
       {
	 ans1=new char[l1+1];
	 strcpy(ans1,ms);
	 ans2=new char[l2+1];
	 strcpy(ans2,mt);

       }

    }
    ms=NULL;
    mt=NULL;
   // cout<<"in end aft::"<<ans1<<"::"<<ans2<<"::";
    delete [] (*s);
    delete [] (*t);

    *s=ans1;
    *t=ans2;
    cout<<"in end (*s)::"<<(*s)<<"(*t)"<<(*t)<<"||";

 }

  HugeInt friend operator& (HugeInt &o1,HugeInt &o2)
  {
     HugeInt o3;
     cout<<"in operator &\n";
     if(o1.v==NULL || o2.v==NULL)
     {
       cout<<"null value\n";
       exit(0);
     }
     char *val1,*val2,*dval1,*dval2;
     char *bin1,*bin2,*decibin1,*decibin2,*ans1,*ans2,*ans;
     val1=new char[o1.l+1];
     val2=new char[o2.l+1];
     strcpy(val1,o1.v);
     strcpy(val2,o2.v);
   //  cout<<"dv1::"<<o1.dv<<":dv2:"<<o2.dv<<endl;
     if(o1.dv!=NULL || o2.dv!=NULL)
    {
      // cout<<"in bth nt null\n";
       if(o1.dv!=NULL)
	{
	  dval1=new char[o1.dl+1];
	  strcpy(dval1,o1.dv);
       //	  cout<<"dv1"<<decibin1<"||";
	}
       else
	{
	  dval1=new char[2];
	  strcpy(dval1,"0");

	}

       if(o2.dv!=NULL)
	{
	  dval2=new char[o2.dl+1];
	  strcpy(dval2,o2.dv);
      //	  cout<<"dv2::"<<decibin2<<"||";
	}
       else
	{
	  dval2=new char[2];
	  strcpy(dval2,"0");
	}

    }
     cout<<":v:"<<val1<<":dv1:"<<dval1<<":v2:"<<val2<<":dv2:"<<dval2<<"||";
     bin1=o3.bin(val1);
     bin2=o3.bin(val2);
     decibin1=o3.decibin(dval1);
     decibin2=o3.decibin(dval2);
      cout<<"bef equalser::)";
      cout<<"bin1::"<<bin1<<":::decbin1:::"<<decibin1<<"|||";
     cout<<"bin2::"<<bin2<<":::decbin2:::"<<decibin2<<endl;


     o3.decinormequaliser(&bin1,&bin2,0);        //0 fr norm
     o3.decinormequaliser(&decibin1,&decibin2,1);

     cout<<"aft equaliser fn::"<<bin1<<"::"<<bin2<<"nwdec:::"<<decibin1<<"::"<<decibin2<<endl; //1 fr decieq
     int l1=strlen(bin1),l2=strlen(decibin1),i=0;
     ans1=new char[l1+1];
     ans2=new char[l2+1];
     for(;i<l1;i++)
     {
       if(bin1[i]=='1' && bin2[i]=='1')
	ans1[i]='1';
       else
	ans1[i]='0';

     }
     ans1[i]='\0';
     cout<<"_a1:_"<<ans1<<"|";
      for(i=0;i<l2;i++)
     {
       if(decibin1[i]=='1' && decibin2[i]=='1')
	ans2[i]='1';
       else
	ans2[i]='0';

     }
     ans2[i]='\0';
     cout<<"_a2:_"<<ans2<<"|";
     ans1=o3.trim(ans1);
     ans2=o2.decitrim(ans2);
     ans=new char[strlen(ans1) + strlen(ans2)+2];
     strcpy(ans,ans1);
     strcat(ans,".");
     strcat(ans,ans2);
     cout<<"|ttlans:|"<<ans<<"|";
     o3.seperator(ans);
     o3.neg=0;
     cout<<"||in fn|| "<<o3.v<<"::"<<o3.dv<<"::"<<endl;
     delete []val1;
     delete []dval1;
     delete []val2;
     delete []dval2;
     delete []bin1;
     delete []bin2;
     delete []decibin1;
     delete []decibin2;
     delete []ans1;
     delete []ans2;

     return o3;

  }

   HugeInt friend operator| (HugeInt &o1,HugeInt &o2)
  {
     HugeInt o3;
     cout<<"in operator |\n";
     if(o1.v==NULL || o2.v==NULL)
     {
       cout<<"null value\n";
       exit(0);
     }
     char *val1,*val2,*dval1,*dval2;
     char *bin1,*bin2,*decibin1,*decibin2,*ans1,*ans2,*ans;
     val1=new char[o1.l+1];
     val2=new char[o2.l+1];
     strcpy(val1,o1.v);
     strcpy(val2,o2.v);
   //  cout<<"dv1::"<<o1.dv<<":dv2:"<<o2.dv<<endl;
     if(o1.dv!=NULL || o2.dv!=NULL)
    {
      // cout<<"in bth nt null\n";
       if(o1.dv!=NULL)
	{
	  dval1=new char[o1.dl+1];
	  strcpy(dval1,o1.dv);
       //	  cout<<"dv1"<<decibin1<"||";
	}
       else
	{
	  dval1=new char[2];
	  strcpy(dval1,"0");

	}

       if(o2.dv!=NULL)
	{
	  dval2=new char[o2.dl+1];
	  strcpy(dval2,o2.dv);
      //	  cout<<"dv2::"<<decibin2<<"||";
	}
       else
	{
	  dval2=new char[2];
	  strcpy(dval2,"0");
	}

    }
     cout<<":v:"<<val1<<":dv1:"<<dval1<<":v2:"<<val2<<":dv2:"<<dval2<<"||";
     bin1=o3.bin(val1);
     bin2=o3.bin(val2);
     decibin1=o3.decibin(dval1);
     decibin2=o3.decibin(dval2);
      cout<<"bef equalser::)";
      cout<<"bin1::"<<bin1<<":::decbin1:::"<<decibin1<<"|||";
     cout<<"bin2::"<<bin2<<":::decbin2:::"<<decibin2<<endl;


     o3.decinormequaliser(&bin1,&bin2,0);        //0 fr norm
     o3.decinormequaliser(&decibin1,&decibin2,1);

     cout<<"aft equaliser fn::"<<bin1<<"::"<<bin2<<"nwdec:::"<<decibin1<<"::"<<decibin2<<endl; //1 fr decieq
     int l1=strlen(bin1),l2=strlen(decibin1),i=0;
     ans1=new char[l1+1];
     ans2=new char[l2+1];
     for(;i<l1;i++)
     {
       if(bin1[i]=='0' && bin2[i]=='0')
	ans1[i]='0';
       else
	ans1[i]='1';

     }
     ans1[i]='\0';
     cout<<"_a1:_"<<ans1<<"|";
      for(i=0;i<l2;i++)
     {
       if(decibin1[i]=='0' && decibin2[i]=='0')
	ans2[i]='0';
       else
	ans2[i]='1';

     }
     ans2[i]='\0';
     cout<<"_a2:_"<<ans2<<"|";
     ans1=o3.trim(ans1);
     ans2=o2.decitrim(ans2);
     ans=new char[strlen(ans1) + strlen(ans2)+2];
     strcpy(ans,ans1);
     strcat(ans,".");
     strcat(ans,ans2);
     cout<<"|ttlans:|"<<ans<<"|";
     o3.seperator(ans);
     o3.neg=0;
     cout<<"||in fn|| "<<o3.v<<"::"<<o3.dv<<"::"<<endl;
     delete []val1;
     delete []dval1;
     delete []val2;
     delete []dval2;
     delete []bin1;
     delete []bin2;
     delete []decibin1;
     delete []decibin2;
     delete []ans1;
     delete []ans2;

     return o3;

  }



 ~HugeInt()
  {
    //cout<<"destr cald::"<<v<<"::\n";
    if(v!=NULL)
     delete[]v;
    v=NULL;
    if(dv!=NULL)
       delete[] dv;
      dv=NULL;
  }




};
  /*                  useful fr setting value
     char &operator[](int i)
     {
       return (v[i-1]);      //here it needs  '1' to set
     }

  */


 int main()
  {
     clrscr();
    // HugeInt o;
   // HugeInt o1("1.333"),o2("1.2333"),o3;

   //char *s=o3.decidivide("9","93",14);
  // cout<<"1234.56768912112\n";
   //char *t=o3.decimovepoint("1234.56768912112",8);
  //  o3=o1/o2;
    //cout<<o3;
    char *t="00667",*s;
    HugeInt o3,o1("58.555"),o2("56.523");
    cout<<"in main bef cal decibin:\n";
   /* s=o3.bin("52");
    cout<<"norm::"<<s;
    delete []s;
    s=o3.decibin("00667");
    cout<<"::dcvi::"<<s<<endl;
   */
    o3=o1|o2;
    cout<<"::main::"<<o3<<endl;
    getch();
    return 0;
}
