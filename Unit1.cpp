//---------------------------------------------------------------------------
#define Z_time 5000
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
unsigned short d_nom_kan,d_nom_kand,d_ckor,d_power,d_pprch;
unsigned short d_nom_kan2,d_nom_kand2,d_ckor2,d_power2,d_pprch2;
unsigned short d_nom_kan3,d_nom_kand3,d_ckor3,d_power3,d_pprch3;
unsigned char BufT[2000];
unsigned char buffer[2000];
unsigned char big_buffer[17000];
unsigned char B_client[1470];
unsigned int zag[4]={0,0,0,0}; //для сборки пакета
unsigned int buffer_size=0; //всего собрано байт в большом пакете
int n_packet=0,n_packet1=0;
int regim_priema=0;
int LenBufT;
unsigned short READY=0;
unsigned char * ptBufT;
unsigned short FLAG;
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
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;

	if (ck1200 -> Checked == true )  M_32.P2=1; //скорость 1-4
	if (ck2400 -> Checked == true )  M_32.P2=2;
	if (ck4800 -> Checked == true )  M_32.P2=3;
	if (ck16000 -> Checked == true ) M_32.P2=4;
	M_32.P1= RK -> Value; //номер канала 0-39
	M_32.P3=M_32.P4=M_32.P5=0;
	M_32.NP_com++;
	if (pprch->Checked==true) M_32.N_com=11; else M_32.N_com=10; //режим ППРЧ-ФРЧ
	OLD_NP_com= M_32.NP_com;
	OLD_N_com= M_32.N_com;
   // Edit1->Text=M_32.N_com;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ControlClick(TObject *Sender)
{
	//Контроль радиостанции
   if (BLOCK ) {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
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

//-------------  приём данных  ---------------------
void __fastcall TForm1::udp1UDPRead(TObject *Sender, TStream *AData,
      TIdSocketHandle *ABinding)
{
	int i;
	if ((AData->Size == 0) || (PORT1!=ABinding->PeerPort)) return;

	READY=1;
	FLAG=0;
	AData->Read(buffer,AData->Size);
	
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
		buffer_size=buffer_size+AData->Size-4;
	}
	if (zag[0]==buffer[3]) //собрали весь пакет
	{
		for(i=0;i<buffer_size;i++) READ_COMMAND.BUF[i]=big_buffer[i];
		buffer_size=0;
		READY=1;	
	}
	n_packet=buffer[1];
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
	frch ->  Checked =true;
	ck1200 ->  Checked =true;
	FLAG=1;
 //////Прописываем буфера и IP адреса нулями
	struct HOST MYHOST;
	for (i=0;i<18;i++) uni.BUF[i]=0;
	for (i=0;i<16;i++) MYHOST.IP_adr[i]=0;
	//---------------------------------------------------------------------
	//BLOCK=1;
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
    old_cr_com=0;
	//переход в режим работа
    
}
//---------------------------------------------------------------------------

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
	else  Client-> SendBuffer(&(M_32),sizeof(M_32));
    //Edit1->Text=sizeof(M_32);
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
	
	Client-> SendBuffer(&(M_32),sizeof(M_32));
	FLAG=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ADD_SETClick(TObject *Sender)
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
	T_10sec->Interval=Z_time;
	E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;
	
	M_32.NP_com++;
	M_32.N_com = StrToInt(W_Enk ->Text);
	M_32.P1 = StrToInt(W_Ep1 ->Text);
	M_32.P2 = StrToInt(W_Ep2 ->Text);
	M_32.P3 = StrToInt(W_Ep3 ->Text);
	M_32.P4 = StrToInt(W_Ep2 ->Text);
	M_32.P5 = StrToInt(W_Ep2 ->Text);
 
	OLD_NP_com = M_32.NP_com;
	OLD_N_com  = M_32.N_com;        
}

//--------------------анализ пакета в таймере 500мс -------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if (READ_COMMAND.READ_COM.cr_com!=old_cr_com) 
	{
		E_cr_com->Text=IntToStr(READ_COMMAND.READ_COM.cr_com);
		E_num_com->Text=IntToStr(READ_COMMAND.READ_COM.num_com);
		E_param->Text=IntToStr(READ_COMMAND.READ_COM.param) ;
		E_kzv->Text=IntToStr(READ_COMMAND.READ_COM.kzv);
		E_k_o->Text=IntToStr(READ_COMMAND.READ_COM.k_o);		
	
		//команда выполнена
		if((READ_COMMAND.READ_COM.num_com==OLD_N_com) && (READ_COMMAND.READ_COM.kzv==0))
		{
			BLOCK=START=0;
			Edit_link->Text="";
			old_cr_com= READ_COMMAND.READ_COM.cr_com;
			E_W_ITOG->Text="               норма";
			E_W_ITOG->Color=clMoneyGreen;
			//------состояние Р999
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
		//код завершения 1
		if((READ_COMMAND.READ_COM.num_com==OLD_N_com) && (READ_COMMAND.READ_COM.kzv!=0))
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
	}
	//изменился линк - выводим новое значение
	if (READ_COMMAND.READ_COM.link!=old_link)
	{
		old_link=READ_COMMAND.READ_COM.link;
		switch (READ_COMMAND.READ_COM.link)
		{
			case KRK_OK : case KRK_ERR : break;
			case KRK_LINK_ERR : Edit_link->Text="Связь не установлена";break;
			case KRK_SWITCH_RECV :	case KRK_DATA_NOT :	case KRK_MODE_REO : break;
			case KRK_DATA_OK : Edit_link->Text="Данные получены";break;
			case KRK_CMD_OK : Edit_link->Text="Команда выполнена";break;
			case KRK_LINK_OK : Edit_link->Text="Связь установлена";break;
			case KRK_SWITCH_TRANS :	case KRK_DATA_AND_TRANS : break;
			case KRK_SMS_OK :   Edit_link->Text="СМС доставлено";
                                Edit68->Color = clLime;
                                break;

		}
	}
	
	//Edit1->Text = READ_COMMAND.READ_COM.r999.cr;
	//Edit2->Text = READ_COMMAND.READ_COM.r999.sach18.kvi;
	
	//изменился счетчик данных Р999
	if (old_R999_cr!=READ_COMMAND.READ_COM.r999.cr)
	{
		old_R999_cr=READ_COMMAND.READ_COM.r999.cr;
		//Edit68->Text=READ_COMMAND.READ_COM.r999.sach18.kvi;
		if (READ_COMMAND.READ_COM.r999.sach18.kvi==15)
		{
            Label10->Caption = READ_COMMAND.READ_COM.r999.sach18.v3*1000+
            READ_COMMAND.READ_COM.r999.sach18.v2*100+READ_COMMAND.READ_COM.r999.sach18.v1*10+
            READ_COMMAND.READ_COM.r999.sach18.v0;
			AnsiString str1(READ_COMMAND.READ_COM.r999_sms.sms);
			Edit3->Text = str1;
			//Edit68->Text="!!!";//READ_COMMAND.READ_COM.r999_sms.sms;
		}
		else
		{
			//первый формуляр
			Edit_11->Text = IntToStr(READ_COMMAND.READ_COM.r999_cu2.form[0].num_out);
			Edit_12->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].num_in;
			int Time= READ_COMMAND.READ_COM.r999_cu2.form[0].time;
			Edit_13->Text = 
			IntToStr((Time % 86400) / 3600)+':'+IntToStr(((Time % 86400) % 3600) / 60);
			
			Edit_14->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].car_freq;
			Edit_15->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].imp_freq;
			Edit_16->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].inp_len;
			Edit_17->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].mod_type;
			Edit_18->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].scan_time;
			Edit_19->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].targ_bear*57.2958;
			Edit_110->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].bear_sko;
			Edit_111->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].targ_vip;
			Edit_112->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].D_NRLS; //new ???
			Edit_113->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].latitude;
			Edit_114->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].longitude;
			Edit_115->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].course;
			Edit_116->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].speed;
			Edit_117->Text = READ_COMMAND.READ_COM.r999_cu2.form[0].div_course;
			//второй формуляр
			Edit_21->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].num_out;
			Edit_22->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].num_in;
			Edit_23->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].time;
			Edit_24->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].car_freq;
			Edit_25->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].imp_freq;
			Edit_26->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].inp_len;
			Edit_27->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].mod_type;
			Edit_28->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].scan_time;
			Edit_29->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].targ_bear;
			Edit_210->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].bear_sko;
			Edit_211->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].targ_vip;
			Edit_212->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].D_NRLS; //new ???
			Edit_213->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].latitude;
			Edit_214->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].longitude;
			Edit_215->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].course;
			Edit_216->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].speed;
			Edit_217->Text = READ_COMMAND.READ_COM.r999_cu2.form[1].div_course;
			//третий формуляр
			Edit_31->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].num_out;
			Edit_32->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].num_in;
			Edit_33->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].time;
			Edit_34->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].car_freq;
			Edit_35->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].imp_freq;
			Edit_36->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].inp_len;
			Edit_37->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].mod_type;
			Edit_38->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].scan_time;
			Edit_39->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].targ_bear;
			Edit_310->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].bear_sko;
			Edit_311->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].targ_vip;
			Edit_312->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].D_NRLS; //new ???
			Edit_313->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].latitude;
			Edit_314->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].longitude;
			Edit_315->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].course;
			Edit_316->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].speed;
			Edit_317->Text = READ_COMMAND.READ_COM.r999_cu2.form[2].div_course;
		}
	}
	if (START)
	{
		E_cr_com->Text=" ";		E_num_com->Text=" ";
		E_param->Text= " ";		E_kzv->Text=" ";		E_k_o->Text=" ";
	}
}

//-----------------режим приема----------------------------------------------------------
void __fastcall TForm1::PriemClick(TObject *Sender)
{
	if (BLOCK )	{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
	T_10sec->Interval=Z_time;
	
	M_32.NP_com++;
	M_32.N_com = 18;
	M_32.P1 = 1;
	M_32.P2 = StrToInt(Svoy ->Text);
	M_32.P3 = M_32.P4 = M_32.P5 = 0;

	OLD_NP_com = M_32.NP_com;
	OLD_N_com  = M_32.N_com;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CMD93Click(TObject *Sender)
{
if (BLOCK )	{ShowMessage("Дождитесь выполнения предыдущей команды");return;}

	BLOCK=1;
	T_10sec->Interval=Z_time*2;

	M_32.NP_com++;
	M_32.N_com = 93;
	M_32.P1 = 2; // установить канал Р999
	const time_t timer = time(NULL);
    struct tm *tm1=localtime(&timer) ;

	M_32.P2 = tm1->tm_hour*3600+tm1->tm_min*60+tm1->tm_sec; // Время
	M_32.P3 = StrToInt(Kuda->Text); //Чужой
	M_32.P4 = StrToInt(Svoy->Text); //Свой
	M_32.P5 = 0;

	OLD_NP_com = M_32.NP_com;
	OLD_N_com  = M_32.N_com;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SMS_RDRClick(TObject *Sender)
{
    if (BLOCK )	{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
	T_10sec->Interval=Z_time;
    const time_t timer = time(NULL);
    struct tm *tm1=localtime(&timer) ;
    tm1->tm_hour*3600+tm1->tm_min*60+tm1->tm_sec; // Время
	M_32.NP_com++;
	M_32.N_com = 115;
	M_32.P1 = tm1->tm_hour*3600+tm1->tm_min*60+tm1->tm_sec;;      // Время
	M_32.P2 = StrToInt(Kuda->Text); //Чужой
    M_32.P3 = StrToInt(Svoy->Text); //Свой
	M_32.P4 = M_32.P5 = 0;

    Edit68->Color = clWindow;
	 AnsiString str=Edit68->Text;
     strcpy(M_32.sms,str.c_str());
     //AnsiString str1(M_32.sms);

     //Edit1->Text = str1;
	OLD_NP_com = M_32.NP_com;
	OLD_N_com  = M_32.N_com;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
    const time_t timer = time(NULL);
    struct tm *tm1=localtime(&timer) ;
    Edit_03->Text = IntToStr(tm1->tm_hour)+":"+IntToStr(tm1->tm_min)+":"+IntToStr(tm1->tm_sec);
}
//---------------------------------------------------------------------------
//-------------вывод пришедших формуляров

//копирование пришедшего в отправляемый
void __fastcall TForm1::Copy_formClick(TObject *Sender)
{
    M_32.form[0]=READ_COMMAND.READ_COM.r999_cu2.form[0];
	//первый формуляр
	Edit_01->Text  = Edit_12->Text;
	Edit_02->Text  = Edit_11->Text;
	Edit_03->Text  = Edit_13->Text;
	Edit_04->Text  = Edit_14->Text;
	Edit_05->Text  = Edit_15->Text;
	Edit_06->Text  = Edit_16->Text;
	Edit_07->Text  = Edit_17->Text;
	Edit_08->Text  = Edit_18->Text;
	Edit_09->Text  = Edit_19->Text;
	Edit_010->Text = Edit_110->Text;
	Edit_011->Text = Edit_111->Text;
	Edit_012->Text = Edit_112->Text; //new ???
	Edit_013->Text = Edit_113->Text;
	Edit_014->Text = Edit_114->Text;
	Edit_015->Text = Edit_115->Text;
	Edit_016->Text = Edit_116->Text;
	Edit_017->Text = Edit_117->Text;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CU2Click(TObject *Sender)
{
    if (BLOCK )	{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;
	T_10sec->Interval=Z_time*2;
    const time_t timer = time(NULL);
    struct tm *tm1=localtime(&timer) ;
    //первый формуляр
	M_32.form[0].num_out = StrToInt(Edit_01->Text);
	M_32.form[0].num_in = StrToInt(Edit_02->Text);
	//M_32.form[0].time = tm1->tm_hour*3600+tm1->tm_min*60+tm1->tm_sec; // Время
    M_32.form[0].time = READ_COMMAND.READ_COM.r999_cu2.form[0].time; // Время
	M_32.form[0].car_freq = StrToFloat(Edit_04->Text);
	M_32.form[0].imp_freq = StrToFloat(Edit_05->Text);
	M_32.form[0].inp_len = StrToFloat(Edit_06->Text);
	M_32.form[0].mod_type = StrToInt(Edit_07->Text);
	M_32.form[0].scan_time = StrToInt(Edit_08->Text);
	M_32.form[0].targ_bear = StrToFloat(Edit_09->Text)/57.2958;
	M_32.form[0].bear_sko = StrToFloat(Edit_010->Text);
	M_32.form[0].targ_vip = StrToFloat(Edit_011->Text);
	M_32.form[0].D_NRLS = StrToFloat(Edit_012->Text); 
	M_32.form[0].latitude = StrToFloat(Edit_013->Text);
	M_32.form[0].longitude = StrToFloat(Edit_014->Text);
	M_32.form[0].course = StrToFloat(Edit_015->Text);
	M_32.form[0].speed = StrToFloat(Edit_016->Text);
	M_32.form[0].div_course = StrToFloat(Edit_017->Text);
	M_32.nform=1;

	M_32.NP_com++;
	M_32.N_com = 104;

	M_32.P1 = tm1->tm_hour*3600+tm1->tm_min*60+tm1->tm_sec; // Время
	M_32.P2 = StrToInt(Kuda->Text); //Чужой
	M_32.P3 = StrToInt(Svoy->Text); //Свой
	M_32.P4 = M_32.P5 = 0;
	OLD_NP_com = M_32.NP_com;
	OLD_N_com  = M_32.N_com;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (BLOCK )	{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
	BLOCK=1;                  
	T_10sec->Interval=Z_time;

	M_32.NP_com++;
    OLD_N_com = M_32.N_com = 1;
	OLD_NP_com = M_32.NP_com;
     //включение Р999
	M_32.P1 = 1;
	M_32.P2 = 0; //!
    M_32.P3=M_32.P4=M_32.P5=0;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Edit68Click(TObject *Sender)
{
    Edit68->Color = clWindow;    
}
//---------------------------------------------------------------------------

