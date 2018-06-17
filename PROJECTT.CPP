#include<fstream.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
class contestant
{	char name[10],title[4];
	int age;
	char gender;
  public:
	void getdata(int n);
	void titles();
	char getname(int i)
	{	return(name[i]);
	}
	char gettitle(int k)
	{       return(title[k]);
	}
	char getgender()
	{	return gender;
	}
};
void contestant::titles()
{       switch(gender)
	{	case 'M' :
		case 'm' : strcpy(title,"Mr.");
			   break;
		case 'F' :
		case 'f' : strcpy(title,"Ms.");
			   break;
		case 'T' :
		case 't' : strcpy(title,"Mx.");
			   break;
		default  : strcpy(title," ");
	}
}
class wcontestant
{	char fname[20];
	char origin[20];
	char motive[50];
  public:
	void mquiz();
	int mcheck(int muans,char msol[],int randsv,int i)
	{       int flag=0;
		if(muans==msol[randsv])
		{       flag=0;
			cout<<"\nCongrats... your answer is correct, you have won "<<amtwin(i)<<" !!";
			cout<<"\nYou can now proceed to question no. "<<i+2;
			getch();
		}
		else
		{       flag=1;
			cout<<"\nOhh... sorry but thats wrong answer, the correct answer is "<<msol[randsv];
			getch();
		}
		return flag;
	}
	void mrules()
	{       cout<<"\nBut before that I shall tell you the rules and how to play the main quiz";
		getch();
		clrscr();
		cout<<"There will be total 15 questions, starting from amount 5000 to 7 crores.";
		cout<<"\nWith each question we will give 4 options and 30 seconds to think.";
		cout<<"\nYou have to choose one of the 4 options.";
		cout<<"\nEach correct answer will lead you to next step.";
		cout<<"\nAnd any wrong answer will eliminate you from the play!!.";
		cout<<"\nDon't Worry, there are some milestones on questions, like on ques 5,8 and 12.";
		cout<<"\nIf you pass them, then there is assurity that you will get that amount of money.";
		cout<<"\nNow you are aware of all rules, so we will begin our main quiz";
		getch();
		clrscr();
	}
	void wgetdata(char wname[],char wtitle[])
	{	cout<<"So, "<<wtitle<<wname;
		cout<<"\nWhats your full name?\n";
		gets(fname);
		cout<<"and from where do you belong?\n";
		gets(origin);
		cout<<"Very well, and what will you do with the amount you will win today?\n";
		gets(motive);
		cout<<"Thats such a nice thought.";
		cout<<"So, we will now begin our Main Quiz";
		mrules();
		mquiz();
	}
	char amtwin(int i)
	{       char amtw[35];
		ifstream amt("amt.dat",ios::in|ios::binary);
		for(int j=0;j<=15;j++)
			amt>>amtw[j];
		return amtw[i];
	}
};
void wcontestant::mquiz()
{       char mask[35][300],msol[35],muans;
	ifstream mques("mques.txt",ios::in);
	ifstream mans("mans.dat",ios::in|ios::binary);
	for(int i=0;i<35;i++)
	{	mques.getline(mask[i],300,'$');
	}
	for(i=0;i<35;i++)
	{	mans>>msol[i];
	}
	time_t r1;
	unsigned int seedvalue=(unsigned)time(&r1);
	srand(seedvalue);
	for(i=0;i<15;i++)
	{       clrscr();
		int randsv=rand()%34;
		cout<<"\nHere is your question no. "<<i+1;
		cout<<"\n\n"<<mask[randsv]<<endl;
		cout<<"\nANS> ";
		cin>>muans;
		if(muans>=97&&muans<=122)
			muans+=32;
		int flag=mcheck(muans,msol,randsv,i);
		if(flag!=0)
		{       cout<<"\nWell Played...";
			cout<<"\nYou have won "<<amtwin(i)<<", we hope that you will fulfill your motive with this amount.";
			getch();
			exit(0);
		}
	}
	getch();
}
void contestant::getdata(int n)
{	cout<<"\nEnter first name of contestant no. "<<n+1<<" : ";
	gets(name);
	cout<<"Enter age of "<<name<<" : ";
	cin>>age;
	cout<<"Enter gender (M,F,T) : ";
	cin>>gender;
	titles();
}
void rules()
{	cout<<"\n\nBefore we start playing FFF, let me explain the rules of it.";
	cout<<"\nPress Enter to see the rules";
	getch();
	cout<<"\n\n\t\tRULES";
	cout<<"\nAs the name suggests, this game is about the who gives the fastest answer.";
	cout<<"\nI will ask you both only one question and four options, and you have to arrange options in correct order by only using A, B, C and D.";
	cout<<"\nFor Example : ";
	cout<<"\nQ> Arrange the following human body parts in the order they come in human body from top to bottom : ";
	cout<<"\nA) Adam's Apple\t\tB) Retina\nC) Abdomen\t\tD) Ventricles";
	cout<<"\n\nANS> BADC";
	getch();
	clrscr();
	cout<<"\nAs soon as question is displayed on your screen, the time starts elapsing, see there is no time limit but";
	cout<<" we will compare your times and the one who will have less time, will win and will get promoted for main quiz.";
	cout<<"\n\tSo, BEST OF LUCK!!";
}
void fdback(time_t t[])
{       cout<<"\nYour time was "<<t[2]<<" seconds";
	getch();
}
int checkwin(char sol[],char check[10][5],int rands)
{    int flag=-1;
     for(int i=0;i<4;i++)
     {	if(sol[i]==check[rands][i])
		flag=0;
	else
		flag=-1;
     }
     if(flag==0)
	cout<<"\nCorrect Answer!!";
     else
	cout<<"\nOops!! Incorrect Answer\nBetter Luck Next Time";
     return flag;
}
int fffq()
{       int rands;
	char ask[10][200];
	char sol[5],check[10][5];
	ifstream ques("fffques.txt",ios::in);
	ifstream ans("ffans.dat",ios::in|ios::binary);
	for(int i=0;i<10;i++)
	{	ques.getline(ask[i],200,'.');
	}
	ans.read((char*)&check,sizeof(check));
	time_t r;
	unsigned int seedval=(unsigned)time(&r);
	srand(seedval);
	rands=rand()%9;
	cout<<ask[rands]<<endl;
	time_t t[3];
	time(&t[0]);
	cout<<"\nANS> ";
	cin>>sol;
	time(&t[1]);
	t[2]=t[1]-t[0];
	int flag=checkwin(sol,check,rands);
	fdback(t);
	if(flag==0)
		return(t[2]);
	else
		return flag;
}
int fff(char name[])
{       getch();
	clrscr();
	cout<<"So "<<name;
	cout<<"\n\tLets start FASTEST FINGER FIRST(FFF)!!!";
	cout<<"\nHere is your question!!\n";
	int time=fffq();
	return(time);
}
void main()
{       clrscr();
	int j=0,m=1,time[2],win,lose;
	char contname[2][10],g[2][1],t[2][4];
	cout<<"\a\t\tWELCOME TO THE QUIZ SHOW!!! (Press Enter to continue)";
	getch();
	cout<<"\nSo, this quiz is only for two contestants";
	cout<<"\nOk, so who are those two lucky persons?\n";
	contestant c[2];
	for(int i=0;i<2;i++)
	{	c[i].getdata(i);
		for(;j<m;j++)
		{       for(int k=0;k<10;k++)
				contname[j][k]=c[i].getname(k);
			for(int l=0;l<4;l++)
				t[j][l]=c[i].gettitle(l);
		}
		g[i][0]=c[i].getgender();
		m++;
	}
	clrscr();
	cout<<"\nFirst of all one of you have to pass FASTEST FINGER FIRST TEST";
	cout<<"\nWe will begin with our first contestant "<<t[0]<<contname[0];
	rules();
	time[0]=fff(contname[0]);
	clrscr();
	cout<<"Now we will play with our second contestant "<<t[1]<<contname[1];
	cout<<"\nYou already know the rules, therefore we will directly proceed to FFF TEST";
	time[1]=fff(contname[1]);
	clrscr();
	if(time[0]!=-1&&time[1]!=-1)
	{	if(time[0]<time[1])
		{	win=0,lose=1;
		}
		else if(time[1]<time[0])
		{	win=1,lose=0;
		}
		else if(time[0]==time[1])
		{	cout<<"You both have taken same time in Test";
			cout<<", therefore it is a DRAW";
		}
		if(time[0]<time[1]||time[1]<time[0])
		{	cout<<contname[win]<<" had taken less time than "<<contname[lose];
			cout<<" therefore "<<contname[win]<<" has been promoted to main quiz";
		}
	}
	else if(time[0]==-1&&time[1]==-1)
		cout<<"You both have answered wrong answers, therefore none of you will be promoted";
	else if(time[0]==-1||time[1]==-1)
	{	if(time[0]==-1)
			win=1;lose=0;
		if(time[1]==-1)
			win=0;lose=1;
		cout<<contname[lose]<<" had given wrong answer, therefore "<<contname[win]<<" is automatically promoted to main quiz";
	}
	getch();
	clrscr();
	if(!(time[0]==-1&&time[1]==-1))
	{	wcontestant wcont;
		wcont.wgetdata(contname[win],t[win]);
	}
	cout<<"\n\n\\t\t\bThanks for Playing";
	getch();
}