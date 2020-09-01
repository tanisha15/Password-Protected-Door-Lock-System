#include<reg51.h> //to access the hardware registers of the controller
sbit r1=P1^0;  // coonections for the 4x3 LCD DISPLAY(4 rows and 3 columns)
sbit r2=P1^1; 
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

sbit buzzer=P3^5; // connects the buzzer
sbit rs=P3^0; //lcd control lines
sbit rw=P3^1;
sbit en=P3^2;

sbit motp=P3^3; //motor connections
sbit motn=P3^4;

void lcdcmd(unsigned char); //user defined functions: for calling the commandregister
void lcddat(unsigned char); //for calling the dataregister
void lcddis(unsigned char *, unsigned char); //for displaying the password
void delay(); //to add delay
void check(); //for checking whether the password is correct or not
unsigned char pwd[10], x;//we give our mobile number as password
void main()
{
	lcdcmd(0x38); //lcd basic commands
	lcdcmd(0x01);
	lcdcmd(0x10);
	lcdcmd(0x0c);
	lcdcmd(0x80);
	lcddis("PASSWORD PROTECTION",19);
	lcdcmd(0xc0);
	lcddis("SYSTEM",7);
	lcdcmd(0x01);
	lcddis("ENTER PASSWORD",14);
	lcdcmd(0xc0);
	while(1)
	{
		r1=0;
		if(c1==0)
		{
			pwd[x]='1';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();delay(); delay();delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c2==0)
		{
			pwd[x]='2';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c3==0)
		{
			pwd[x]='3';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		r2=0; 
		r1=1;
		if (c1==0)
		{
			pwd[x]='4';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c2==0)
		{
			pwd[x]='5';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c3==0)
		{
			pwd[x]='6';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		r3=0; r2=1;
		if (c1==0)
		{
			pwd[x]='7';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();delay(); delay(); delay();delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c2==0)
		{
			pwd[x]='8';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c3==0)
		{
			pwd[x]='9';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		r4=0; r3=1;
		if (c1==0)
		{
			pwd[x]='*';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c2==0)
		{
			pwd[x]='0';
			delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay(); delay();
			lcddat('*'); 
			x=x+1;
		}
		if (c3==0)
		{
			check();
			delay(); delay();delay();delay(); delay(); delay();
			delay();
		}
		r4=1; 
	}
}
void check()
{
	if(pwd[0]=='6' && pwd[1]=='2' && pwd[2]=='9' && pwd[3]=='1' && pwd[4]=='7' && pwd[5]=='1' && pwd[6]=='1' && pwd[7]=='2' && pwd[8]=='6' && pwd[9]=='1')
	{
		buzzer=0; //if password is correct then no buzzer
		motp=1; //rotates the motor clockwise; door will open
		motn=0;
		lcdcmd(0x01);
		lcddis("PASSWORD MATCHED",16);
		delay();
	}
	else
	{
		buzzer=1; //if password is wrong then the buzzer activates
		lcdcmd(0x01);
		lcddis("PASSWORD WRONG",14);
	}
}

void lcdcmd(unsigned char val)
{
	P2=val; 
	rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void lcddat(unsigned char dat)
{
	P2=dat;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void  lcddis(unsigned char *s, unsigned char r)
{
	unsigned char w;
	for(w=0;w<r;w++)
	{
		lcddat(s[w]);
		delay();
	}
}
void delay()
{
	unsigned int i,j;
	for(i=0;i<4000;i++);
	for(j=0;j<100;j++);
}

		
			
		
			
			
			
			
			
			
			
			
	







