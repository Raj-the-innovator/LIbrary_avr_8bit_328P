/*
 * thermistor.c
 *
 * Created: 12/8/2017 4:20:15 PM
 *  Author: Administrator
 */ 

#include "lib.h"
#define Max 50

 const int temptable[Max][2];

 const int temptable[Max][2]= {
	 /*  adcv      Temp   */
	 {1,        938},
	 {31,       314},
	 {41,       290},
	 {51,       272},
	 {61,       258},
	 {71,       247},                //The Temperature table consists of 50 samples of ADC values and also with respect to them Temperature
	 {81,       237},
	 {91,       229},
	 {101,      221},
	 {111,      215},
	 {121,      209},
	 {131,      204},
	 {141,      199},
	 {151,      195},
	 {161,      190},
	 {171,      187},
	 {181,      183},
	 {191,      179},
	 {201,      176},
	 {221,      170},
	 {241,      165},
	 {261,      160},
	 {281,      155},
	 {301,      150},
	 {331,      144},
	 {361,      139},
	 {391,      133},
	 {421,      128},
	 {451,      123},
	 {491,      117},
	 {531,      111},
	 {571,      105},
	 {611,      100},
	 {641,      95},
	 {681,      90},
	 {711,      85},
	 {751,      79},
	 {791,      72},
	 {811,      69},
	 {831,      65},
	 {871,      57},
	 {881,      55},
	 {901,      51},
	 {921,      45},
	 {941,      39},
	 {971,      28},
	 {981,      23},
	 {991,      17},
	 {1001,     9},
	 {1021,     -27},

 };

unsigned int Fclose(const int (*p)[2],int adcv)
{                                           /*Receive base address (*p)(2) represents p is a pointer to an array*/
	int i,x1=0,y1=0,x2=0,y2=0;
	for(i=0;i<Max-1;i++) 
	{                 /* In loop continue the loop till the Temperature  ADC values is
		                                                 smaller than received ADC values*/
				if(p[i][0]<adcv)    
						continue;
				
			
			else  if(p[i][0]==adcv)       
				{
					// constantly will update Temperature value on 5th position of lcd 
					return (unsigned int) p[i][1];    /*if received ADC values matches the Temperature table values than display the values on lcd*/
					//break;
				}
				
				
			else
				{
					unsigned int Temp=0;
					x1=p[i][0];y1=p[i][1];x2=p[i+1][0];y2=p[i+1][1];     /* using two point form equation get the new 
																			Temperature value from respective ADC value*/
	
					Temp  =((double)(adcv-x1)*(y2-y1)/(x2-x1))+y1;     /*http://mathonweb.com/help_ebook/html/lines.htm */
					                                                     /*http://pcbheaven.com/drcalculus/index.php?calc=leastsquares */
					return Temp;
					
					      //display each ADC number  dividing it's PLACE and do MOD operation and add 48 to dispay ascii characters
							
				}
		}
}