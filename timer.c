/******************
 *	simple timer  *
 ******************/
#include <stdio.h>
#include <stdlib.h>		// system()
#if defined(__APPLE__) || defined(__linux__)
#include <unistd.h>		// sleep()
#elif defined(WIN32) || defined(_WIN32)
#include <windows.h>	// Sleep()
#endif


void init(void);
void timer(void);
void display(void);
void delay_sec(int n);

int HH, HL, MH, ML, SH, SL;

int main(void)
{
	init();
	while(1) {
		display();
		timer();	
	}
}

void init(void)
{
	HH = HL = 0;
	MH = ML = 0;
	SH = SL = 0;
}

void timer(void)
{
	int C = 0;	// carry

	delay_sec(1);

	// SL
	if(SL == 9) {
		SL = 0;
		C = 1;
	}	
	else {
		SL += 1;
	}
	// SH
	if(C == 1) {
		if(SH == 5) {
			SH = 0;
			C = 1;
		}
		else {
			SH += 1;
			C = 0;
		}
	}
	// ML
	if(C == 1) {
		if(ML == 9) {
			ML = 0;
			C = 1;
		}
		else {
			ML += 1;
			C = 0;
		}
	}
	// MH
	if(C == 1) {
		if(MH == 5) {
			MH = 0;
			C = 1;
		}
		else {
			MH += 1;
			C = 0;
		}
	}
	// HL
	if(C == 1) {
		if(HL == 3 && HH == 2) {
			HL = 0;
			HH = 0;
			return;
		}
		if(HL == 9) {
			HL = 0;
			C = 1;
		}
		else {
			HL += 1;
			C = 0;
		}
	}
	// HH
	if(C == 1) {
		HH += 1;
	}
}

void display(void)
{
#if defined(__APPLE__) || defined(__linux__)
	system("clear");
#elif defined(WIN32) || defined(_WIN32)
	system("clr");
#endif
	printf("%d%d : %d%d : %d%d\n", HH, HL, MH, ML, SH, SL);	
}

void delay_sec(int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
#if defined(__APPLE__) || defined(__linux__)
		sleep(1);
#elif defined(WIN32) || defined(_WIN32)
		Sleep(1000);
#endif
	}
}