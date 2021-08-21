//dfplayerのヘッダファイル
//ファイル名：DFPLAYER.h
//多重インクルード防止
#ifndef DFPLAYER_H_INCLUDED
#define DFPLAYER_H_INCLUDED

//外部ヘッダファイルのインクルード
//なし

//関数のプロトタイプ宣言
void DFR_Send(int fd, int paraH, int paraL);
void DFR_NEXT();
void DFR_VOL(int vol);
//void MX_USART1_UART_Init();
//MX_USART1_UART_Init();

#endif
