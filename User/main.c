#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"

 #define  proport  	10000 //Tclk/(psc+1)=72000000/(7199+1)
 #define  L1       ((proport/131)-1)//低调　do 的周期根据Tout= ((arr+1)*(psc+1))/Tclk推出arr值就是本句define定义的值，Tout为音调频率131Hz的倒数，Tclk=72MHz
 #define  L2       ((proport/147)-1)//低调　re 的周期
 #define  L3       ((proport/165)-1)//低调　mi 的周期
 #define  L4       ((proport/176)-1)//低调　fa 的周期
 #define  L5       ((proport/196)-1)//低调　sol的周期
 #define  L6       ((proport/220)-1)//低调　la 的周期
 #define  L7       ((proport/247)-1)//低调　si 的周期

 #define  M1       ((proport/262)-1)//中调　do 的周期
 #define  M2       ((proport/296)-1)//中调　re 的周期
 #define  M3       ((proport/330)-1)//中调　mi 的周期 
 #define  M4       ((proport/349)-1)//中调　fa 的周期
 #define  M5       ((proport/392)-1)//中调　sol的周期
 #define  M6       ((proport/440)-1)//中调　la 的周期
 #define  M7       ((proport/494)-1)//中调　si 的周期

 #define  H1       ((proport/523)-1)//高调　do 的周期
 #define  H2       ((proport/587)-1)//高调　re 的周期
 #define  H3       ((proport/659)-1)//高调　mi 的周期
 #define  H4       ((proport/699)-1)//高调　fa 的周期
 #define  H5       ((proport/784)-1)//高调　sol的周期
 #define  H6       ((proport/880)-1)//高调　la 的周期
 #define  H7       ((proport/988)-1)//高调　si 的周期
//int music[]=  
//{  
//	M5,50,M5,25,M5,25,
//	M6,100,M5,100,H1,100,
//	M7,100,M7,100,M5,50,M5,25,M5,25,
//	M6,100,M5,100,H2,100,
//	H1,100,H1,100,M5,50,M5,25,M5,25,
//	H5,100,H3,100,H1,100,
//	M7,100,M6,100,H4,50,H4,25,H4,25,
//	H3,100,H1,100,H2,100,H1,100,H1,100
//};

//简谱C语言表示方法(M5,50)为(音调，音长) 100表示为一个音长(节拍)，50位半个音长(节拍)，25位四分之一音长  //25 代表一个四音符
// 一节 2节拍  
//4分符为一拍
int music[]={
 H1,100,H1,100, M5,100,M3,50,M2,50, M1,100,M5,100, M3,100,L1,100,
 H1,100,H1,100, M5,100,M3,50,M2,50, M1,100,M6,100, M5,100,L1,50,M3,50, H1,100,L1,50,M3,50, H1,100,M6,50,M5,50,
 M6,100,L1,50,M3,50,H1,100,M6,100,M5,100,M3,100,H1,150,M6,50,H1,100,H1,100,
//朝着法西斯
H1,100,M5,100,M3,75,M6,25,M5,50,M3,50,M2,100,M1,100,M3,100,L1,50,M3,50,
H1,100,M5,100, M6,75,H1,25,M6,50,M5,50,M3,100,M3,50,M1,50,M6,100,M6,100,M6,100,
H1,75,H1,25,M5,50,M5,50,M2,75,M3,25,M5,50,M5,50,M6,150,M5,50,M6,100,H2,100,H1,100,M6,50,M5,50,
H1,100.,M6,50,M5,50, M3,100,M3,100,M3,100, M3,100,M3,100,H1,100,H1,100,H1,100,
 	
};


int length = sizeof(music)/sizeof(music[0]);//计算数组长度
int main()
{
	int i=0;
	
	delay_init();//延时初始化
  //led_init();

    while(100)
	{
		for(i=0; i<(length/2); i++)  //取数组数据
		{  
			Timer4_Init(music[2*i]); //PWM波周期
			delay_ms(5*music[2*i+1]);//音长的时间都乘以5即一拍为500微秒，此值"5"可调整，只是播放的整个快慢而已，有点类似于视频快进和后退
		}
	}
}

