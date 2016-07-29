//---------------------------------------------------------------------------
#define Z_time 1000
#include <vcl.h>
#pragma hdrstop
#include <string.h>
#include <stdio.h>
#include "Unit1.h"
#include <time.h>
#include <math.h>
#include <dir.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
//static unsigned char BufT[2000];
unsigned short d_nom_kan,d_nom_kand,d_ckor,d_power,d_pprch;
unsigned short d_nom_kan2,d_nom_kand2,d_ckor2,d_power2,d_pprch2;
unsigned short d_nom_kan3,d_nom_kand3,d_ckor3,d_power3,d_pprch3;
unsigned char BufT[2000];
unsigned char buffer[2000];
unsigned char big_buffer[17000];
unsigned char B_client[1470];
char zag[4]={0,0,0,0}; //для сборки пакета
int buffer_size=0; //всего собрано байт в большом пакете
int n_packet=0,n_packet1=0;
int LenBufT;
unsigned short READY=0;
unsigned char * ptBufT;
unsigned char BufT1[2000];
AnsiString StrMemo ="";
unsigned short FLAG;
unsigned short CMD_NVP,CMD_NVP2,CMD_NVP3;
int K,M,ReadPort;     // свойство Connect
int LenBufread;
 AnsiString IPADR="194.1.1.4";

  FILE *TUNING;
  int PORT1,START;
  int Visible_Tuning=0;

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OUT_1Click(TObject *Sender)
{
	exit(0);        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B_frchClick(TObject *Sender)
{
	if (BLOCK ) {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
	Panel7->Color= clActiveBorder;//Подсветка панели
	GroupBox3 ->Color=clBtnFace;
	GroupBox15 ->Color=clBtnFace;
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;

	if (ck1200 -> Checked == true )  M_32.P2=1; //скорость 1-4
	if (ck2400 -> Checked == true )  M_32.P2=2;
	if (ck4800 -> Checked == true )  M_32.P2=3;
	if (ck16000 -> Checked == true ) M_32.P2=3;
	M_32.P1= RK -> Value; //номер канала 0-39
	M_32.P3=M_32.P4=M_32.P5=0;
	M_32.NP_com++;
	if (pprch->Checked==true) M_32.N_com=11; else M_32.N_com=10; //режим ППРЧ-ФРЧ
	OLD_NP_com= M_32.NP_com;
	OLD_N_com= M_32.N_com;
//N_frch = N_frch << 15;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B_prdClick(TObject *Sender)
{
 if (BLOCK )
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=1;
 Panel7->Color= clBtnFace;
 GroupBox3 ->Color=clBtnFace;

 GroupBox15 ->Color=clActiveBorder; //Подсветка панели


short Nprd = 25;
  if (off_prd -> Checked ==true) N_prd = 0;
else  N_prd =1;
 M_32.NP_com++;
 M_32.N_com = Nprd;
 M_32.P1= N_prd;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//N_prd=N_prd << 6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::on_999Click(TObject *Sender)
{
	//Включение-Выключение радиостанции
	if (BLOCK ) {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
	Panel7->Color= clBtnFace;
	GroupBox3 ->Color=clActiveBorder;  //Подсветка панели
	GroupBox15 ->Color=clBtnFace;
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;

	short Nondmw=4;
	if (off_dmw -> Checked == true) N_on_dmw =0;	else N_on_dmw = 1;

	M_32.NP_com++;
	M_32.N_com = Nondmw;
	M_32.P1= N_on_dmw;
	M_32.P2= N_ant;
	M_32.P3=M_32.P4=M_32.P5=0;
	OLD_NP_com= M_32.NP_com;
	OLD_N_com= M_32.N_com;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ControlClick(TObject *Sender)
{
	//Контроль радиостанции
   if (BLOCK ) {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
	Panel7->Color= clBtnFace;//Подсветка панели
	GroupBox3 ->Color=clBtnFace;
	GroupBox15 ->Color=clBtnFace;
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;

	OLD_NP_com = M_32.NP_com++;
	OLD_N_com = M_32.N_com = 80;
	M_32.P1= 2;
	M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) //Применить
{
	int i;
// Прописываем буфера и IP адреса нулями
	for (i=0;i<18;i++) uni.BUF[i]=0;
	for (i=0;i<16;i++) MYHOST.IP_adr[i]=0;
/////// запись\чтение  настройки адресата1
	TUNING=fopen("T_IP_PORT","wb");
	IPADR=Combo_IP->Text;
	memcpy((MYHOST.IP_adr),IPADR.c_str(),IPADR.Length());
	MYHOST.PORT=StrToInt(Combo_port->Text);
	fwrite (&MYHOST,sizeof(MYHOST),1,TUNING);
	fclose(TUNING);
///////////////////////////////////////////////////
	TUNING=fopen("T_IP_PORT","rb");
	fread (uni.BUF,sizeof(uni.BUF),1,TUNING);
	fclose(TUNING);
	Combo_IP-> Text=uni.MYHOST.IP_adr;
	Combo_port->Text= uni.MYHOST.PORT;
	PORT1= uni.MYHOST.PORT;
	Client->  Active=false;
	Client->Host=uni.MYHOST.IP_adr;
	Client->Port=uni.MYHOST.PORT;
	Client->  Active=true;  
///// запись\чтение  настройки адресата1
}


void __fastcall TForm1::udp1UDPRead(TObject *Sender, TStream *AData,
      TIdSocketHandle *ABinding)
{
  //приём данных
	int i;
	if ((AData->Size == 0) || (PORT1!=ABinding->PeerPort)) return;

	READY=1;
	FLAG=0;
	AData->Read(buffer,AData->Size);
	if (zag[1]!=buffer[1]) //изменился циклицеский номер сообщения
	{
		zag[1]=buffer[1];
		if (buffer[2]==1) //первый пакет
		{
			zag[0]=1; //начинаем сборку пакета с 1 части
			for(i=0;i<17000;i++) big_buffer[i]=0;
			for(i=4;i<AData->Size;i++) big_buffer[i-4]=buffer[i];
			buffer_size=AData->Size-4;
		}
		else
		{
			zag[0]++;//копим пакеты
			for(i=4;i<AData->Size;i++) big_buffer[buffer_size+i-4]=buffer[i];
			buffer_size+=AData->Size-4;
		}
		if (zag[0]==buffer[3]) //собрали весь пакет
		{
			for(i=0;i<buffer_size;i++) READ_COMMAND.BUF[i]=big_buffer[i];
			buffer_size=zag[0]=0;

			READY=1;

		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
	int i;
	M_32.res[0]=70;
	READY=0;
	START=1;
	BLOCK=0;
	T_10sec->Interval=0;
	
	off_dmw->Checked=true; 
	pprch ->  Checked =true;
	off_prd ->  Checked =true;
	ck1200 ->  Checked =true;
	
	FLAG=1;
	old_cr_com=old_cr_com2=old_cr_com3=0;
	M_32.NP_com=M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
	M_32.N_com=4; M_32.P1=1;F_RAB=1; //переход в режим работа
 // E_RAB->Text= "Paбота";
 //////Прописываем буфера и IP адреса нулями
	struct HOST MYHOST;

	for (i=0;i<18;i++) uni.BUF[i]=0;
	for (i=0;i<16;i++) MYHOST.IP_adr[i]=0;
	//---------------------------------------------------------------------
	BLOCK=1;
	Panel7->Color= clBtnFace;//Подсветка панели
	GroupBox3 ->Color=clBtnFace;
	GroupBox15 ->Color=clBtnFace;
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;
	E_frch->Text="";E_kan->Text="";E_ck->Text="";E_power->Text="";
	PageControl1->ActivePageIndex=0;
/////////////запись\чтение или чтение настройки адресата1
	if (( TUNING=fopen("T_IP_PORT","rb"))==NULL) //если нет файла настроек, то создадим его
	{
		TUNING=fopen("T_IP_PORT","wb");
		IPADR=Combo_IP->Text;
		memcpy((MYHOST.IP_adr),IPADR.c_str(),IPADR.Length());
		MYHOST.PORT=StrToInt(Combo_port->Text);
		fwrite (&MYHOST,sizeof(MYHOST),1,TUNING);
		fclose(TUNING);
	}
  
	TUNING=fopen("T_IP_PORT","rb");
	fread (uni.BUF,sizeof(uni.BUF),1,TUNING);
	fclose(TUNING);
	Combo_IP->Text=uni.MYHOST.IP_adr;
	Combo_port->Text= uni.MYHOST.PORT;
	Client->Host=uni.MYHOST.IP_adr;
	Client->Port=uni.MYHOST.PORT;
	PORT1= uni.MYHOST.PORT;
//автоматическая выдача команды на включение Р999 при создании формы
    OLD_NP_com = M_32.NP_com++;
    OLD_N_com = M_32.N_com = 4; //включение Р999
	M_32.P1 = 1;
	M_32.P2 = 2;
    M_32.P3=M_32.P4=M_32.P5=0;
}
//---------------------------------------------------------------------------

  void T5(void * pParams)
  {
 
	ptBufT= &(B_client[0]);
	K= Form1->Client->BufferSize ;
	LenBufread=Form1->Client-> ReceiveBuffer(ptBufT,K,-1);
	_endthread();
  }

void __fastcall TForm1::T_READYTimer(TObject *Sender)
{
/* Передача данных в ethernet */
	if (READY)
	{
		T_READY -> Interval=0;
		L_READY -> Color =clMoneyGreen; L_READY -> Caption= "Прибор готов";
		T_READY_BLANK->Enabled =false;
		T_READY_TEXT -> Enabled=false;
		P_com->Visible=true;
		DMW_send -> Visible =true;
		DMW_receive -> Visible = true;
		HW_receive -> Visible = true;
	}
	else  Client-> SendBuffer(&(M_32),24);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_READY_TEXTTimer(TObject *Sender)
{
 L_READY ->Color = clRed;
 T_READY_BLANK->  Enabled=true;
 T_READY_TEXT -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_READY_BLANKTimer(TObject *Sender)
{
	L_READY ->Color= clWhite;
	T_READY_BLANK->  Enabled=false;
	T_READY_TEXT -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_CLIENT_SENDTimer(TObject *Sender)
{
	int F1=0, i;
   
	if (FLAG)
	{
		E_cr_com->Text=" ";
		E_num_com->Text=" ";E_param->Text=" ";
		E_kzv->Text=" "; E_k_o->Text=" ";
		E_W_ITOG->Text="  УСОИ не готов";
		E_W_ITOG->Color=clWhite;
		E_W_ITOG->Color=clWhite;
		E_W_ITOG->Text="  УСОИ не готов";
		if(START)	{ E_W_ITOG->Text=""; E_W_ITOG->Text="";}  
		
		READY=0;
		T_READY->Enabled=true;
		T_READY->Interval=1000;T_READY_BLANK->Enabled =true;
		T_READY_TEXT -> Enabled=true;
		L_READY->Caption="Прибор не готов";L_READY->Color=clRed;
		PageControl1->Visible=true;P_com->Visible=true;
	}
	else 
	{
		L_READY->Color=clMoneyGreen;L_READY->Caption="Прибор готов";
		PageControl1->Visible=true;
	}
	
	Client-> SendBuffer(&(M_32),24);
	
	//for (i=0;i<1000;i++);
	//for (i=0;i<1000;i++);
	FLAG=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Combo_portKeyPress(TObject *Sender, char &Key)
{
/*Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {ShowMessage("Ошибочное число;повторите ввод");Key=0; }  */
 //      { Key=0;Beep();}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Combo_portChange(TObject *Sender)
{
 /* Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {ShowMessage("Ошибочное число;повторите ввод");Key=0; }  */
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
if(Visible_Tuning)  {Panel_Tuning->Visible=false;Visible_Tuning=0;}
else {Panel_Tuning->Visible=true;Visible_Tuning=1; }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_10secTimer(TObject *Sender)
{
	if(BLOCK)
	{
		E_W_ITOG->Text="  УСОИ не отвечает";
		E_cr_com->Text= " ";    E_num_com->Text= " ";
        E_param->Text=  " ";    E_kzv->Text=    " ";    E_k_o->Text=" ";
		BLOCK=0;
	}
	T_10sec->Interval=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::R_VvodClick(TObject *Sender)
{
	if (BLOCK )	{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
		
	BLOCK=1;
	Panel7->Color= clBtnFace;//Подсветка панели
	GroupBox3 ->Color=clBtnFace;
	GroupBox15 ->Color=clBtnFace;

	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;
	
	M_32.NP_com++;
	M_32.N_com = 4;// StrToInt(W_Enk ->Text);
	M_32.P1 = StrToInt(W_Ep1 ->Text);
	M_32.P2 = StrToInt(W_Ep2 ->Text);
	M_32.P3 = StrToInt(W_Ep3 ->Text);
	M_32.P4 = StrToInt(W_Ep2 ->Text);
	M_32.P5 = StrToInt(W_Ep2 ->Text);
 
	OLD_NP_com= M_32.NP_com;
	OLD_N_com= M_32.N_com;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
	
	Panel7->Color= clBtnFace;//Подсветка панели
	GroupBox3 ->Color=clBtnFace;
	GroupBox15 ->Color=clBtnFace;
	off_dmw->Checked=true;
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;
	
	/* //Убрал команды при переключении панелей
	BLOCK=1;
	if (PageControl1->ActivePage==HF_sheet) 
	{
		short FT=1;
		M_32.NP_com++;
		M_32.N_com = FT;
		M_32.P1= 10;
		M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
		OLD_NP_com= M_32.NP_com;
		OLD_N_com= M_32.N_com;
	}
	
	if (PageControl1->ActivePage==DMW_sheet)
	{	
		E_frch->Text="";E_kan->Text="";E_ck->Text="";E_power->Text="";
		short Nondmw=4;
		if (off_dmw -> Checked == true) N_on_dmw =0; else N_on_dmw = 1;
		M_32.NP_com++;
		M_32.N_com = Nondmw;
		M_32.P1= N_on_dmw;
		M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
		OLD_NP_com= M_32.NP_com;
		OLD_N_com= M_32.N_com;
   }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
		// анализ пакета ---------------------------------------------------
		if (READ_COMMAND.READ_COM.cr_com!=old_cr_com) 
		{
			E_cr_com->Text=IntToStr(READ_COMMAND.READ_COM.cr_com);
			E_num_com->Text=IntToStr(READ_COMMAND.READ_COM.num_com);
			E_param->Text=IntToStr(READ_COMMAND.READ_COM.param) ;
			E_kzv->Text=IntToStr(READ_COMMAND.READ_COM.kzv);
			E_k_o->Text=IntToStr(READ_COMMAND.READ_COM.k_o);		
		}
		
			if (READ_COMMAND.READ_COM.kzv!=0)
			{
				E_frch->Text="";E_kan->Text="";
				E_ck->Text="";E_power->Text="";
			}
			else
			{
				Label41->Caption=READ_COMMAND.READ_COM.word_sost_2;
				//------nomer kanala------------------------
				d_nom_kan= (READ_COMMAND.READ_COM.word_sost_2 & 0xff00)>>8;
				d_nom_kand=(d_nom_kan & 0xf0)>>4;
				d_nom_kan=d_nom_kand*10 + (d_nom_kan & 0x0f);
				E_kan->Text=IntToStr(d_nom_kan);
				//-------ckorost-----------------------------
				d_ckor=(READ_COMMAND.READ_COM.word_sost_2 & 0x30000)>>16;
				if(d_ckor==0) d_ckor=1200;
				if(d_ckor==1) d_ckor=2400;
				if(d_ckor==2) d_ckor=4800;
				if(d_ckor==3) d_ckor=16000;
				E_ck->Text= IntToStr(d_ckor);
				//------------power------------------
				d_power= (READ_COMMAND.READ_COM.word_sost_2 & 0x300000)>>20;
				E_power->Text= IntToStr(d_power);
				//------------rejim------------------
				d_pprch=(READ_COMMAND.READ_COM.word_sost_2 & 0x7e000000)>>25;
				E_frch->Text="";
				if (d_pprch==0x2) E_frch->Text="ФРЧ";
				if (d_pprch==0x4) E_frch->Text="ППРЧ";
			}

			if((READ_COMMAND.READ_COM.num_com==OLD_N_com)& (READ_COMMAND.READ_COM.cr_com!=old_cr_com) & (READ_COMMAND.READ_COM.kzv==0))
			{
				BLOCK=0; START=0;
				old_cr_com= READ_COMMAND.READ_COM.cr_com;
				E_W_ITOG->Text="               норма";
				E_W_ITOG->Color=clMoneyGreen;
			}

			if((READ_COMMAND.READ_COM.num_com==OLD_N_com)&(READ_COMMAND.READ_COM.cr_com!=old_cr_com) & (READ_COMMAND.READ_COM.kzv!=0))
			//(READ_COMMAND.READ_COM.cr_com>OLD_NP_com) & (READ_COMMAND.READ_COM.kzv!=0))
			{
				START=0;
				old_cr_com= READ_COMMAND.READ_COM.cr_com ;
				//E_itog->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
				//" не выполнена";
				E_W_ITOG->Text="           ненорма";
				E_W_ITOG->Color=clRed;BLOCK=0;
				E_frch->Text="";E_kan->Text="";
				E_ck->Text="";E_power->Text="";
			}

			if (START)
			{
				E_cr_com->Text=" ";		E_num_com->Text=" ";
				E_param->Text= " ";		E_kzv->Text=" ";		E_k_o->Text=" ";
			}
}
//---------------------------------------------------------------------------

