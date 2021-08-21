/* DFplayer.c
DFplayer再生用プログラム
huart1でDFplayerとUART通信

DFR_NEXT(); //次の曲を再生する関数
DFR_PAUSE(); //曲の再生を一時停止
DFR_STOP();	//曲の再生を停止
DFR_PLAY(); //曲の再生を再開
DFR_RAND();	//曲をランダムに再生
DFR_BACK();	//１つ前の曲を再生
DFR_VOL(volume);	//音量を設定
*/
//ヘッダファイルのインクルード
#include "DFPLAYER.h"
#include "main.h"
UART_HandleTypeDef huart1;

//定数定義
//FD：Function Deseription
static const int FD_NEXT = 0x01;  //次の曲の再生
static const int FD_PAUSE = 0x02; //曲の再生を一時停止
static const int FD_STOP = 0x16;  //曲の再生を停止
static const int FD_PLAY = 0x0D;  //曲の再生を開始
static const int FD_RAND = 0x18;  //曲をランダムに再生
static const int FD_BACK = 0x0D;  //前の曲を再生
static const int FD_VOL	 = 0x06;  //音量の設定

//Parameter
//NEXT,PAUSE,STOP,PALY,RAND
const int PARA = 0x00;


//関数の作成
//DFPlayerのデータ送信関数
void DFR_Send(int fd, int paraH,int paraL)
{

    //配列の宣言
    //uint8_t dataset[]={};  //UART送信データ格納用配列
    uint8_t dataset[] = {0x7E, 0xFF, 0x06, 0x00, 0x00, 0x00, 0x00, 0xEF};
    dataset[3] = fd;    //function deseription の値
    dataset[5] = paraH; //parameterのhigh data byteの値
    dataset[6] = paraL; //parameterのlow data byteの値
    //USARTデータ送信処理
    HAL_UART_Transmit(&huart1, dataset, sizeof(dataset), 100);
}

void DFR_NEXT()
{
    DFR_Send(FD_NEXT, PARA, PARA);
}

void DFR_PUSE()
{
	DFR_Send(FD_PAUSE,PARA,PARA);
}

void DFR_STOP()
{
	DFR_Send(FD_STOP,PARA,PARA);
}

void DFR_PLAY()
{
	DFR_Send(FD_PLAY,PARA,PARA);
}

void DFR_RAND()
{
	DFR_Send(FD_RAND,PARA,PARA);
}

void DFR_BACK()
{
	DFR_Send(FD_BACK,PARA,PARA);
}

void DFR_VOL(int volume)
{
    DFR_Send(FD_VOL, PARA, volume);
}
