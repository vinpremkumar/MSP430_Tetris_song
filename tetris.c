#include<msp430g2553.h>
unsigned int i;

void sound(int a,int d)	    //a is freq,d is delay
{
int i;
for(i=0;i<=d*2;i++)
{
	if(a==0)
		TACCR0 = 0;
	if(a!=0)
	{
		TACCR0 = 0x7A12/a;
		TACCR1 = 0x7A12/a;
	}
}
}

void main()
{
	int c =131*5;
	int c2 =138*5;
	int d =147*5;
	int d2=156*5;
	int e =165*5;
	int f =174*5;
	int f2=185*5;
	int g =196*5;
	int g2=208*5;
	int a =220*5;
	int a2=233*5;
	int a2 =233*5;

	WDTCTL = WDTPW + WDTHOLD;   // Stop watchdog timer
	TACTL = TAIE + MC_3 + ID_3 + TASSEL_2;
	TACCTL1= CCIE+CAP;
	P1DIR = 0X04;
	P1OUT &=0x00;
	_BIS_SR(GIE) ;     //global interrupt enable
	while(1)
	{
		//250=half note,500=1 count,750=1 and a half counts,1000=2 counts,1500=3 counts,2000=4 counts

		if((P1IN & 0x01) == 0x00)
		{
		sound(a,500);
		sound(e,250);
		sound(f,250);
		sound(g,500);
		sound(f,250);
		sound(e,250);
		sound(d,500);
		sound(d,250);
		sound(f,250);
		sound(a,500);
		sound(g,250);
		sound(f,250);
		sound(e,500);
		sound(e,250);
		sound(f,250);
		sound(g,500);
		sound(a,500);
		sound(f,500);
		sound(d,500);
		sound(d,1000);
		sound(0,250);
		sound(g,500);
		sound(a2,250);

		sound(d*2,250);
		sound(d*2,250);
		sound(c*2,250);
		sound(a2,250);
		sound(a,750);
		sound(f,250);
		sound(a,250);
		sound(a,250);
		sound(g,250);
		sound(f,250);
		sound(e,500);
		sound(e,250);
		sound(f,250);
		sound(g,500);
		sound(a,500);
		sound(f,500);
		sound(d,500);
		sound(d,1000);
		sound(0,1000);

		sound(f,1000);
		sound(d,1000);
		sound(c2,1000);
		sound(e,1000);
		sound(a,1000);
		sound(f,1000);
		sound(g,1000);
		sound(e,1000);
		sound(f,1000);
		sound(a,1000);

		sound(a,500);
		sound(e,250);
		sound(f,250);
		sound(g,500);
		sound(f,250);
		sound(e,250);
		sound(d,500);
		sound(d,250);
		sound(f,250);
		sound(a,500);
		sound(g,250);
		sound(f,250);
		sound(e,500);
		sound(e,250);
		sound(f,250);
		sound(g,500);
		sound(a,500);
		sound(f,500);
		sound(d,500);
		sound(d,1000);
		sound(0,1000);
		}

	}
}


#pragma vector = TIMER0_A1_VECTOR
__interrupt void timerainterr ()
{
	if(TAIV)   // interrupt control register...all timer interrupts are defined here
	   P1OUT ^= 0x04;
}
