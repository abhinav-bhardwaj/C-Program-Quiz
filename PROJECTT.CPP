#include<fstream.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
class contestant
{	char name[15],title[4];
	int age;
	char gender;
  public:
	contestant()
	{	strcpy(name,"Anonymous");
	}
	void getdata(int n);
	void titles();
	char* getname()
	{	return(name);
	}
	char* gettitle()
	{       return(title);
	}
	char getgender()
	{	return(gender);
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
	int mquiz();
	void mmquiz();
	int mcheck(int muans,char msol[],int randsv,int i)
	{       int flag=0;
		if(i!=14)
		{	if(muans==msol[randsv])
			{       flag=0;
				cout<<"\nCongrats... your answer is correct, you have won Rs.";
				amtwin(i);
				cout<<" !!";
				cout<<"\nYou can now proceed to question no. "<<i+2<<" for Rs.";
				amtwin(i+1);
				getch();
			}
			else
			{       flag=1;
				cout<<"\nOhh... sorry but thats wrong answer, the correct answer is "<<msol[randsv];
				getch();
			}
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
		cout<<"\nDon't Worry, there are some milestones on questions, like on ques 6,9 and 12.";
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
		if(mquiz()==0)
			mmquiz();

	}
	void amtwin(int k)
	{       long amtw[15];
		ifstream amt("amt.dat",ios::in|ios::binary);
		for(int j=0;j<15;j++)
			amt>>amtw[j];
		cout<<amtw[k];
	}
	void checkamt(int k)
	{       long amtw[15];
		ifstream amt("amt.dat",ios::in|ios::binary);
		for(int j=0;j<15;j++)
			amt>>amtw[j];
		if(k==0)
			cout<<"0";
		else if(k<6)
			cout<<amtw[0];
		else if(k>=6&&k<12)
			cout<<amtw[5];
		else if(k>=12)
			cout<<amtw[11];
	}
};
int wcontestant::mquiz()
{       int randsv[10],flag;
	char mask[35][300],msol[35],muans;
	ifstream mques("mques.txt",ios::in);
	ifstream mans("man.dat",ios::in|ios::binary);
	for(int i=0;i<35;i++)
	{	mques.getline(mask[i],300,'$');
	}
	for(i=0;i<35;i++)
	{	mans>>msol[i];
	}
	time_t r1;
	unsigned int seedvalue=(unsigned)time(&r1);
	srand(seedvalue);
	for(i=0;i<10;i++)
	{       clrscr();
		randsv[i]=rand()%34;
		if(i>0)
		{	for(int j=0;j<i;j++)
				if(randsv[i]==randsv[j])
					randsv[i]=rand()%34;
		}
		cout<<"\nHere is your question no. "<<i+1;
		cout<<"\n\n"<<mask[randsv[i]]<<endl;
		cout<<"\nANS> ";
		cin>>muans;
		if(muans>=97&&muans<=100)
			muans=muans-32;
		flag=mcheck(muans,msol,randsv[i],i);
		if(flag!=0)
		{       cout<<"\nWell Played...";
			cout<<"\nYou have won  Rs.";
			checkamt(i);
			cout<<", we hope that you will fulfill your motive with this amount.";
			getch();
			i=11;
		}
	}
	if(i!=11)
		return 0;
	else if(i==11)
		return 1;
}
void wcontestant::mmquiz()
{       int randsv[5];
	char mmask[40][300],mmsol[40],muans;
	ifstream mmques("mmques.txt",ios::in);
	ifstream mmans("mmans.dat",ios::in|ios::binary);
	for(int i=10;i<40;i++)
	{	mmques.getline(mmask[i],300,'$');
	}
	for(i=10;i<40;i++)
	{	mmans>>mmsol[i];
	}
	time_t r1;
	unsigned int seedval=(unsigned)time(&r1);
	srand(seedval);
	for(i=10;i<15;i++)
	{	clrscr();
		randsv[i]=(rand()%29)+11;
		if(i>10)
		{	for(int j=10;j<i;j++)
				if(randsv[i]==randsv[j])
					randsv[i]=(rand()%29)+11;
		}
		cout<<"\nHere is your question no. "<<i+1;
		cout<<"\n\n"<<mmask[randsv[i]]<<endl;
		cout<<"\nANS> ";
		cin>>muans;
		if(muans>=97&&muans<=100)
			muans=muans-32;
		int flag=mcheck(muans,mmsol,randsv[i],i);
		if(flag!=0)
		{       cout<<"\nWell Played...";
			cout<<"\nYou have won  Rs.";
			checkamt(i);
			cout<<", we hope that you will fulfill your motive with this amount.";
			getch();
			i=16;
		}
	}
	if(i==15)
	{	clrscr();
		cout<<"\n\t\tCONGRATULATIONS!!!";
		cout<<"\nYou have won the quiz and the amount of Rs.70000000";
		cout<<"\nNow you can do whatever you want to do with this amount.";
		getch();
	}
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
	cout<<"\n\n\bFor Example : ";
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
     {	if(islower(sol[i]));
		sol[i]=toupper(sol[i]);
     }
     if(strcmpi(sol,check[rands])==0)
     {	flag=0;
	cout<<"\nCorrect Answer!!";
     }
     else
     {	flag=-1;
	cout<<"\nOops!! Incorrect Answer\nThe Correct Answer is "<<check[rands]<<"\nBetter Luck Next Time";
     }
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
	int time[2],win,lose,check=0;
	char contname[2][10],t[2][4];
	cout<<"\a\t\tWELCOME TO THE QUIZ SHOW!!! (Press Enter to continue)";
	getch();
	cout<<"\nThis quiz is only for two contestants";
	cout<<"\nOk, so who are those two lucky persons?\n";
	contestant c[2];
	for(int i=0;i<2;i++)
	{	c[i].getdata(i);
		strcpy(contname[i],c[i].getname());
		strcpy(t[i],c[i].gettitle());
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
		{       check=1;
			cout<<"You both have taken same time in Test";
			cout<<", therefore it is a DRAW";
		}
		if(time[0]<time[1]||time[1]<time[0])
		{	cout<<contname[win]<<" had taken less time than "<<contname[lose];
			cout<<" therefore "<<contname[win]<<" has been promoted to main quiz";
		}
	}
	else if(time[0]==-1&&time[1]==-1)
	{       check=1;
		cout<<"You both have answered wrong answers, therefore none of you will be promoted";
	}
	else if(time[0]==-1||time[1]==-1)
	{	if(time[0]==-1)
		{	win=1;lose=0;
		}
		else if(time[1]==-1)
		{	win=0;lose=1;
		}
		cout<<contname[lose]<<" had given wrong answer, therefore "<<contname[win]<<" is automatically promoted to main quiz";
	}
	getch();
	clrscr();
	if((time[0]!=-1||time[1]!=-1)&&check==0)
	{	wcontestant wcont;
		wcont.wgetdata(contname[win],t[win]);
	}
	clrscr();
	cout<<"\n\n\t\tThanks for Playing";
	cout<<"\n\n\tCREDITS";
	cout<<"\n\n\tABHINAV DUBEY";
	getch();
}