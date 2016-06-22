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
unsigned char B_client[1470];
int LenBufT;
unsigned short READY=0,READY1=0,READY2=0,READY3=0;
unsigned char * ptBufT;
unsigned char BufT1[2000];
AnsiString StrMemo ="";
unsigned short FLAG1,FLAG2,FLAG3;
unsigned short CMD_NVP,CMD_NVP2,CMD_NVP3;
int K,M,ReadPort;     // свойство Connect
int LenBufread;
 AnsiString IPADR="192.168.1.35";
 AnsiString IPADR2="192.168.1.35";
  AnsiString IPADR3="192.168.1.35";
  FILE *TUNING;
  FILE *TUNING2;
  FILE *TUNING3;
  int PORT1,PORT2,PORT3,START;
  int Visible_Tuning;

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

void __fastcall TForm1::B_HFClick(TObject *Sender)
{
F_MI=F_T=F_O=F_TKI=F_RAB=F_FK=F_MI=F_PRM=F_PPR=0;
//E_zapros1 -> Text = "      ";

//E_Os ->Text =3;


//RAB -> Checked =true;
//FK1 -> Checked =true;




/*
E_RT    ->Text ="   ";
E_O     ->Text ="   ";
E_RAB   ->Text ="   ";
E_FK    ->Text ="    ";
E_M     ->Text ="    ";
E_PPR_Z ->Text ="    ";
E_MI_Z  ->Text ="    ";
*/
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button24Click(TObject *Sender)
{


//Test -> Text="        ";

//------------ДМВ---------------------------------
N_on_corc = N_on_dmw = N_ant = N_prd =DMW_power= N_ck= N_frch = N_kan=0;
DMW_main=0x40000000;
//Test -> Text = "        ";
//DMW_power=3;
HF_main=0;
off_dmw -> Checked = true;
ekv     -> Checked = true;
pprch   -> Checked = true;
off_prd -> Checked = true;
ck1200  -> Checked = true;
//on_corc -> Checked = true;
RK       -> Value =10;
power   -> Value = 3;
/*
E_frch  -> Text="    " ;
E_kan   -> Text="     ";
E_power -> Text="     ";
E_ck    -> Text="     ";
*/
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Exit_dmwClick(TObject *Sender)
{


//Test -> Text="        ";
}
//---------------------------------------------------------------------------



void __fastcall TForm1::B_rab_kanClick(TObject *Sender)
{
 if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;

 
short Nkan = 0xD;
N_kan = RK -> Value;
E_kan -> Text = N_kan;

M_32.P1=N_kan;
M_32.NP_com++;
M_32.N_com=Nkan;
OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//N_kan = N_kan << 7;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_frchClick(TObject *Sender)
{
 if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 Panel7->Color= clActiveBorder;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 // GroupBox1->Color=clBtnFace;

 E_prm->Color =clWhite; E_prd->Color =clWhite;
 E_prm->Text =""; E_prd->Text ="";


 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;


short Nfrch = 10;
if(pprch->Checked==true)  Nfrch=11;
//else {E_frch -> Text = "ФРЧ" ;}
N_kan = RK -> Value;
//E_kan -> Text = N_kan;
if (ck1200 -> Checked == true )  N_ck=0;
if (ck2400 -> Checked == true )  N_ck=1;
if (ck4800 -> Checked == true )  N_ck=2;
if (ck16000 -> Checked == true ) N_ck=3;
DMW_power=StrToInt(power ->  Value);
// E_power -> Text = DMW_power;
M_32.P1=N_kan;
M_32.P2= N_ck;
M_32.P3=DMW_power;
M_32.P4=M_32.P5=0;
M_32.NP_com++;
M_32.N_com=Nfrch;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//N_frch = N_frch << 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_ckClick(TObject *Sender)
{
    if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;

short Nck=0xF;
if (ck1200 -> Checked == true ) {E_ck -> Text = 1200; N_ck=0;}
if (ck2400 -> Checked == true ) {E_ck -> Text = 2400; N_ck=1;}
if (ck4800 -> Checked == true ) {E_ck -> Text = 4800; N_ck=2;}
if (ck16000 -> Checked == true ) {E_ck -> Text = 16000; N_ck=3;}
 M_32.NP_com++;
 M_32.N_com = Nck;
 M_32.P1= N_ck;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//N_ck=N_ck << 4;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::B_powerClick(TObject *Sender)
{
   if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;

 
  short DMWpower=0x10;
  DMW_power=StrToInt(power ->  Value);
  M_32.NP_com++;
  M_32.N_com = DMWpower;
  M_32.P1= DMW_power;
  E_power -> Text = DMW_power;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_prdClick(TObject *Sender)
{
 if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 Panel7->Color= clBtnFace;
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clActiveBorder; //Подсветка панели
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 // GroupBox1->Color=clBtnFace;

 E_prm->Color =clWhite; E_prd->Color =clWhite;
 E_prm->Text =""; E_prd->Text ="";

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

void __fastcall TForm1::B_antClick(TObject *Sender)
{
 if (BLOCK)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}

 BLOCK=1;
 Panel7->Color= clBtnFace;
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clActiveBorder; //Подсветка панели
 GroupBox15 ->Color=clBtnFace;
// GroupBox16 ->Color=clBtnFace;
  GroupBox17 ->Color=clBtnFace;

 //  GroupBox1->Color=clBtnFace;



 T_10sec->Interval=Z_time;

short Nant=0xB;
if (ekv -> Checked == true) N_ant=0;
else N_ant=1;
M_32.NP_com++;
 M_32.N_com = Nant;
 M_32.P1= N_ant;
  M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
N_ant=N_ant << 16;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_onClick(TObject *Sender)
{
  if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 Panel7->Color= clBtnFace;
 GroupBox3 ->Color=clActiveBorder;  //Подсветка панели
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 //GroupBox1->Color=clBtnFace;

 E_prm->Color =clWhite; E_prd->Color =clWhite;
 E_prm->Text =""; E_prd->Text ="";

 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;

 
short Nondmw=4;
if (off_dmw -> Checked == true) N_on_dmw =0;
else N_on_dmw = 1;
if (ekv -> Checked == true) N_ant=0;
else N_ant=1;

 M_32.NP_com++;
 M_32.N_com = Nondmw;
 M_32.P1= N_on_dmw;
 M_32.P2= N_ant;
 M_32.P3=M_32.P4=M_32.P5=0;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//N_on_dmw= N_on_dmw << 18;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_dmwClick(TObject *Sender)
{
   if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
  T_10sec->Interval=Z_time;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
// GroupBox16 ->Color=clActiveBorder;
 GroupBox17 ->Color=clBtnFace;
 //GroupBox1->Color=clBtnFace;



short Noncorc=0x11;
//if (on_corc -> Checked == true ) N_on_corc = 0;
//else N_on_corc =1;
 M_32.NP_com++;
 M_32.N_com = Noncorc;
 M_32.P1= N_on_corc;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
N_on_corc = N_on_corc << 17;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ControlClick(TObject *Sender)
{

   if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clActiveBorder;

 // GroupBox1->Color=clBtnFace;

 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;

 
 M_32.NP_com++;
 M_32.N_com = 80;
 M_32.P1= 2;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_PRMClick(TObject *Sender)
{
  if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 //GroupBox1->Color=clBtnFace;

 //GroupBox1->Color=clBtnFace;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
// GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;

 T_10sec->Interval=Z_time;

 E_itog->Text="";E_itog->Color=clWhite;



short FPRM;

 M_32.NP_com++;
 M_32.N_com = FPRM;
 M_32.P1= F_PRM;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//F_PRM = F_PRM << 15;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B_rab_tClick(TObject *Sender)
{
 if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
// GroupBox1->Color=clActiveBorder;

 Panel7->Color= clBtnFace;
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;

  
short FT=5;
//if(PRM7 -> Checked == true) FT=7;

 M_32.NP_com++;
 M_32.N_com = FT;
 M_32.P1= F_T;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;



}
//---------------------------------------------------------------------------

void __fastcall TForm1::B_OClick(TObject *Sender)
{

 if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 //GroupBox1->Color=clBtnFace;


 //GroupBox1->Color=clBtnFace;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
// GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;


 T_10sec->Interval=Z_time;

 E_PRD_Z -> Color = clWhite; E_PRM_Z -> Color = clWhite;

 E_PRD_Z -> Text =""; E_PRM_Z -> Text ="";
 E_itog->Text="";E_itog->Color=clWhite;



short FO=30;

  M_32.NP_com++;
  M_32.N_com = FO;
  M_32.P1= F_O;
  M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
 // F_O =F_O << 3;
}


void __fastcall TForm1::B_rabClick(TObject *Sender)
{
  if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 // GroupBox1->Color=clBtnFace;

 //GroupBox1->Color=clBtnFace;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;

 T_10sec->Interval=Z_time;

 E_PRD_Z -> Color = clWhite; E_PRM_Z -> Color = clWhite;

 E_PRD_Z -> Text =""; E_PRM_Z -> Text ="";
 E_itog->Text="";E_itog->Color=clWhite;


short FRAB = 60;

//if (RAB -> Checked == true) {F_RAB=1;E_RAB ->Text = "РАБОТА";}
//else {F_RAB=0;E_RAB ->Text ="ФК";}
  M_32.NP_com++;
  M_32.N_com = FRAB;
  M_32.P1= F_RAB;
  M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
//F_RAB = F_RAB <<8;
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button2Click(TObject *Sender)
{
// Прописываем буфера и IP адреса нулями
 // struct HOST MYHOST2;
 //struct HOST MYHOST;
 // struct HOST MYHOST3;
 int i;
 for ( i=0;i<18;i++)
{uni.BUF[i]=0;uni2.BUF[i]=0;uni3.BUF[i]=0;}
 for (i=0;i<16;i++)
{MYHOST.IP_adr[i]=0;MYHOST2.IP_adr[i]=0;MYHOST3.IP_adr[i]=0;}
/////// запись\чтение  настройки адресата1
TUNING=fopen("T_IP_PORT","wb");
IPADR=Combo_IP->Text;
 memcpy((MYHOST.IP_adr),IPADR.c_str(),IPADR.Length());

// try
 //{
MYHOST.PORT=StrToInt(Combo_port->Text);
//  }
 /*  catch (EConvertError&)
   {
    ShowMessage("Ошибочный номер порта канала 1;повторите ввод");
     E_RAB2->Text="";E_PRD2_Z->Color=clWindow;E_PRM2_Z->Color=clWindow;
  E_PRM_Z2->Text="";  E_FK2-> Text="";
  E_M2-> Text=""; E_RT2 ->Text="";E_PPRZ2->Text="";
  E_MI_Z2->Text=""; E_CPP2_Z->Color=clWindow;E_O->Text="";
  E_prm->Text="";E_prm->Color=clWindow;
  E_prd->Text="";E_prd->Color=clWindow;
  E_frch->Text="";E_kan->Text="";
  E_ck->Text="";E_power->Text="";
  return;
    }  */
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
///// запись\чтение  настройки адресата2



  
}

void __fastcall TForm1::RKKeyPress(TObject *Sender, char &Key)
{
Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {Key=0;Beep();}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::powerKeyPress(TObject *Sender, char &Key)
{
 Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {Key=0;Beep();}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_PPRKeyPress(TObject *Sender, char &Key)
{
/*Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {Key=0;Beep();}  */
}
//---------------------------------------------------------------------------


void __fastcall TForm1::E_MIKeyPress(TObject *Sender, char &Key)
{
/*Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {Key=0;Beep();} */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E_OsKeyPress(TObject *Sender, char &Key)
{
 Set <char ,'0','9'> Dig;
Dig << '0' << '1' <<'2' << '3' << '4' << '5' << '6' <<'7'
        <<'8' << '9';
        if (! Dig.Contains(Key))
        {Key=0;Beep();}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::T_PPRTimer(TObject *Sender)
{

T_PPR2 -> Enabled =true;
T_PPR -> Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_PPR2Timer(TObject *Sender)
{

T_PPR ->Enabled = true;
T_PPR2 -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_MITimer(TObject *Sender)
{

 T_MI2 -> Enabled =true;
 T_MI -> Enabled = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_MI2Timer(TObject *Sender)
{

 T_MI -> Enabled =true;
 T_MI2 -> Enabled = false ;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B_controlClick(TObject *Sender)
{
/*
//Передача данных в ethernet
//AnsiString StrMemo ="";
AnsiString IP_adr_out = "";
unsigned int Port_out;
unsigned char BufT1[1472];
 StrMemo=Test->Text;
memcpy(BufT1,StrMemo.c_str(),StrMemo.Length());
 //Port_out=StrToInt(Combo_port->Items->Strings[Combo_port->ItemIndex]);
  Port_out=StrToInt(Combo_port->Text);
  IP_adr_out=Combo_IP->Text;
//BufT1[StrMemo.Length()]=0;
//----
int LnB=0; int i=0,j=0;int errB=0;
int LnStrMemo=StrMemo.Length();
for ( i=0,j=0;j<LnStrMemo;j++)
    {
     if (BufT1[j]==' ') continue;
     BufT[i]= (BufT1[j]-0x30);
     if (BufT1[j]>0x40) BufT[i]-=7;
     BufT[i]=BufT[i]<<4;
     j++;
     if ((BufT1[j]==' ')||(BufT1[j]==0)){errB=1;break;}
     BufT[i]+= ((BufT1[j]-0x30));
     if (BufT1[j]>0x40) BufT[i]-=7;
     LnB++;i++;
    }
if (errB)
 {ShowMessage("неверный формат строки"); return;}
//----
    ptBufT= &BufT[0];
    LenBufT= LnB;

//------------------------------
  udp1->SendBuffer(IP_adr_out.c_str(),Port_out,ptBufT,LnB) ;
//   udp1->SendBuffer("192.168.1.16",4000,ptBufT,LnB);
                       */
}
//---------------------------------------------------------------------------


void __fastcall TForm1::udp1UDPRead(TObject *Sender, TStream *AData,
      TIdSocketHandle *ABinding)
{

  //приём данных
AnsiString StrMemo="";
    if (AData->Size == 0) return;

    int pport= ABinding->PeerPort ;
    AnsiString IP;
    IP=ABinding->PeerIP;
    if (PORT1==pport)
    {READY1=1;FLAG1=0; READ_COMMAND.READ_COM.P999=0;
     AData->Read(READ_COMMAND.BUF,AData->Size);}
      E_cr_com->Text=IntToStr(READ_COMMAND.READ_COM.cr_com);
 E_num_com->Text=IntToStr(READ_COMMAND.READ_COM.num_com);
 E_param->Text=IntToStr(READ_COMMAND.READ_COM.param) ;
  E_kzv->Text=IntToStr(READ_COMMAND.READ_COM.kzv);
  E_k_o->Text=IntToStr(READ_COMMAND.READ_COM.k_o);

  if (READ_COMMAND.READ_COM.kzv!=0)
  {
  E_RAB2->Text="";E_PRD2_Z->Color=clWindow;E_PRM2_Z->Color=clWindow;
  E_PRM_Z2->Text="";  E_FK2-> Text="";
  E_M2-> Text=""; E_RT2 ->Text="";E_PPRZ2->Text="";

 // E_prm->Text="";E_prm->Color=clWindow;
 // E_prd->Text="";E_prd->Color=clWindow;
  E_frch->Text="";E_kan->Text="";
  E_ck->Text="";E_power->Text="";

  }
  else
  {
  
  E_PPRZ2->Text= IntToStr(READ_COMMAND.READ_COM.SS11);
  E_MI_Z2->Text=IntToStr(READ_COMMAND.READ_COM.SS12);
  if( READ_COMMAND.READ_COM.SS1==0) E_RAB2->Text="Работа";
  else  E_RAB2->Text="ФК";
  if   (READ_COMMAND.READ_COM.SS0 & 128) {E_PRD2_Z->Color=clMoneyGreen;
  E_PRD2_Z->Text="норма";}
  else {E_PRD2_Z->Color=clRed;E_PRD2_Z->Text=""; }
   if   (READ_COMMAND.READ_COM.SS0 & 64) {E_PRM2_Z->Color=clMoneyGreen;
   E_PRM2_Z->Text="норма";}
  else {E_PRM2_Z->Color=clRed; E_PRM2_Z->Text="";}

/*
AnsiString SSS;
  int m;
    m=  READ_COMMAND.READ_COM.P999;
    SSS=IntToHex(m,8);
  E_SS0->Text= SSS;   */

//------nomer kanala------------------------
d_nom_kan= (READ_COMMAND.READ_COM.P999 & 0xff00)>>8;
d_nom_kand=(d_nom_kan & 0xf0)>>4;
d_nom_kan=d_nom_kand*10 + (d_nom_kan & 0x0f);
E_kan->Text=IntToStr(d_nom_kan);
//-------ckorost-----------------------------
d_ckor=(READ_COMMAND.READ_COM.P999 & 0x30000)>>16;
if(d_ckor==0)d_ckor=1200;
if(d_ckor==1)d_ckor=2400;
if(d_ckor==2)d_ckor=4800;
if(d_ckor==3)d_ckor=16000;
E_ck->Text= IntToStr(d_ckor);
//------------power------------------
d_power= (READ_COMMAND.READ_COM.P999 & 0x300000)>>20;
E_power->Text= IntToStr(d_power);
//------------rejim------------------
d_pprch=(READ_COMMAND.READ_COM.P999 & 0x7e000000)>>25;
E_frch->Text="";
if (d_pprch==0x2)E_frch->Text="ФРЧ";
if (d_pprch==0x4)E_frch->Text="ППРЧ";
}
   if((READ_COMMAND.READ_COM.num_com==OLD_N_com)&
(READ_COMMAND.READ_COM.cr_com!=old_cr_com) & (READ_COMMAND.READ_COM.kzv==0))
{
 BLOCK=0; START=0;
old_cr_com= READ_COMMAND.READ_COM.cr_com;
//E_itog->Text="   команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";
 E_itog->Text="                   норма";
 // E_itog->Text="               ВЫПОЛНЕНО " ;
 E_itog->Color=clMoneyGreen;
// E_HF_ITOG->Text="    команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";

// E_HF_ITOG->Text="               ВЫПОЛНЕНО " ;

   //E_W_ITOG->Text="    команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";
    E_W_ITOG->Text="                 норма";
 E_W_ITOG->Color=clMoneyGreen;
 /*if(READ_COMMAND.READ_COM.num_com==77)  // если команда запрос
 { START=0;
 E_TKI->Color=clMoneyGreen; E_RLI->Color=clMoneyGreen;
 E_PRD_Z ->Color=clMoneyGreen; E_PRM_Z ->Color=clMoneyGreen;
 E_TKI->Text= " НОРМА ";  E_RLI->Text=" НОРМА";
 E_PRM_Z->Text= " НОРМА ";  E_PRD_Z->Text=" НОРМА";}  
 if(READ_COMMAND.READ_COM.num_com==78)              // если команда контроль
 {
 START=0;
 E_prd ->Color=clMoneyGreen; E_prm ->Color=clMoneyGreen;
 E_prm->Text= " НОРМА ";  E_prd->Text=" НОРМА";}  */
 }
 if((READ_COMMAND.READ_COM.num_com==OLD_N_com)&
//(READ_COMMAND.READ_COM.cr_com>OLD_NP_com) & (READ_COMMAND.READ_COM.kzv!=0))
 (READ_COMMAND.READ_COM.cr_com!=old_cr_com) & (READ_COMMAND.READ_COM.kzv!=0))
{
START=0;
old_cr_com= READ_COMMAND.READ_COM.cr_com ;
//E_itog->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
//" не выполнена";
E_itog->Text="           ненорма";
E_itog->Color=clRed;BLOCK=0;
//E_HF_ITOG->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
//" не выполнена";


//E_W_ITOG->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
//" не выполнена";
E_W_ITOG->Text="          ненорма";
E_W_ITOG->Color=clRed;//BLOCK=0;
E_RAB2->Text="";E_PRD2_Z->Color=clWindow;E_PRM2_Z->Color=clWindow;
  E_PRM_Z2->Text="";  E_FK2-> Text="";
  E_M2-> Text=""; E_RT2 ->Text="";E_PPRZ2->Text="";

 // E_prm->Text="";E_prm->Color=clWindow;
 // E_prd->Text="";E_prd->Color=clWindow;
  E_frch->Text="";E_kan->Text="";
  E_ck->Text="";E_power->Text="";

}
      if (START)
  { E_cr_com->Text=" ";
    E_num_com->Text=" ";
    E_param->Text= " ";
    E_kzv->Text=" ";
    E_k_o->Text=" ";  }
     READY=1;
      IPadress->Caption=IP ;
      IPadress_HF->Caption=IP ;

}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button1Click(TObject *Sender)
{
/*
 //Передача данных в ethernet
//AnsiString StrMemo ="";
AnsiString  IP_adr_out="";
int Port_out;
unsigned char BufT1[1472];

 StrMemo=E_zapros1->Text;
 // StrMemo="0000007";Label44->Caption=StrMemo ; Label45->Caption= StrMemo.Length();
memcpy(BufT1,StrMemo.c_str(),StrMemo.Length());
BufT1[StrMemo.Length()]=0;
Port_out=StrToInt(Combo_Port_HF ->Text);
IP_adr_out=Combo_IP_HF ->Text;

//BufT1[StrMemo.Length()]=0;
//----
int LnB=0; int i=0,j=0;int errB=0;
int LnStrMemo=StrMemo.Length();
for ( i=0,j=0;j<LnStrMemo;j++)
    {
     if (BufT1[j]==' ') continue;
     BufT[i]= (BufT1[j]-0x30);
     if (BufT1[j]>0x40) BufT[i]-=7;
     BufT[i]=BufT[i]<<4;
     j++;
     if ((BufT1[j]==' ')||(BufT1[j]==0)){errB=1;break;}
     BufT[i]+= ((BufT1[j]-0x30));
     if (BufT1[j]>0x40) BufT[i]-=7;
     LnB++;i++;
    }
if (errB)
 {ShowMessage("неверный формат строки"); return;}
//----
    ptBufT= &BufT[0];
    LenBufT= LnB;

//------------------------------
  udp1->SendBuffer(IP_adr_out.c_str(),Port_out,ptBufT,LnB) ;
   */
}
//--------------------------------------------

//---------------------------------------------------------------------------







void __fastcall TForm1::FormCreate(TObject *Sender)
{
  READY=0;
  START=1;
//Label65->Caption=sizeof(READ_COMMAND.READ_COM);
BLOCK=BLOCK2=BLOCK3=0;
T_10sec->Interval=0;
Combo_port -> ItemIndex = 3 ;
Combo_IP -> ItemIndex = 0;
P_com->Visible=false;
Visible_Tuning=0;
//Combo_Port_HF -> ItemIndex = 3 ;
//Combo_IP_HF -> ItemIndex =0;
GroupBox17->Visible=false;
//Test->Visible=false;
//PRM7-> Checked=true;


//RAB -> Checked =true;
//FK1 -> Checked =true;


 off_dmw->Checked=true;
 ekv ->  Checked =true;
 pprch ->  Checked =true;
 off_prd ->  Checked =true;
 ck1200 ->  Checked =true;
 FLAG1=FLAG2=FLAG3= 1;
 old_cr_com=old_cr_com2=old_cr_com3=0;
  M_32.NP_com=M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  M_32.N_com=4; M_32.P1=1;F_RAB=1; //переход в режим работа
 // E_RAB->Text= "Paбота";
 //////Прописываем буфера и IP адреса нулями
struct HOST MYHOST;
struct HOST MYHOST2;
struct HOST MYHOST3;

int i;
for ( i=0;i<18;i++)
{uni.BUF[i]=0;uni2.BUF[i]=0;uni3.BUF[i]=0;}
for (i=0;i<16;i++)
{MYHOST.IP_adr[i]=0;MYHOST2.IP_adr[i]=0;MYHOST3.IP_adr[i]=0;}
//---------------------------------------------------------------------
//  if (BLOCK || BLOCK2 || BLOCK3)
//{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 //GroupBox1->Color=clBtnFace;


 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;

 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;



  E_frch->Text="";E_kan->Text="";E_ck->Text="";E_power->Text="";

short FT=1;
 M_32.NP_com++;
 M_32.N_com = FT;
 M_32.P1= 1;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
 PageControl1->ActivePageIndex=0;


//----------------------------------------------------------------------

/////////////запись\чтение или чтение настройки адресата1
if (( TUNING=fopen("T_IP_PORT","rb"))==NULL)
  
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

}
//---------------------------------------------------------------------------

  void T5(void * pParams)
  {

  
   //ptBufT= &(BufT[0]);
   ptBufT= &(B_client[0]);
 //  Form1->Client->Active=false;
// LenBufread=Form1->Client->ReceiveBuffer(BufT,16,AAA,4003,100);
  K= Form1->Client->BufferSize ;

//Form1->Client->      Binding->Connect() ;

  LenBufread=Form1->Client-> ReceiveBuffer(ptBufT,K,-1);
 //if ( LenBufread) FLAG=1;

  _endthread();
  }

void __fastcall TForm1::T_READYTimer(TObject *Sender)
{
        /* Передача данных в ethernet */

//AnsiString StrMemo ="";
//AnsiString IP_adr_out = "";
//unsigned int Port_out;
//unsigned char BufT1[1472];
if (READY)
{T_READY -> Interval=0;
L_READY -> Color =clMoneyGreen; L_READY -> Caption= "Прибор готов";
T_READY_BLANK->Enabled =false;
T_READY_TEXT -> Enabled=false;
GroupBox17->Visible=true;
//Test->Visible=true;
// Test->Text="";
 P_com->Visible=true;
// E_zapros1->Text="";
 DMW_send -> Visible =true;
 DMW_receive -> Visible = true;
 HW_receive -> Visible = true;

}
else
{
//L_READY -> Color =clRed; L_READY -> Caption= "Прибор не готов";
 //StrMemo=Test->Text;
 // StrMemo="4800";
 /* memcpy(BufT1,StrMemo.c_str(),StrMemo.Length());

  Port_out=StrToInt(Combo_port->Text);
  IP_adr_out=Combo_IP->Text;
  BufT1[StrMemo.Length()]=0;
//----
int LnB=0; int i=0,j=0;int errB=0;
int LnStrMemo=StrMemo.Length();
for ( i=0,j=0;j<LnStrMemo;j++)
    {
     if (BufT1[j]==' ') continue;
     BufT[i]= (BufT1[j]-0x30);
     if (BufT1[j]>0x40) BufT[i]-=7;
     BufT[i]=BufT[i]<<4;
     j++;
     if ((BufT1[j]==' ')||(BufT1[j]==0)){errB=1;break;}
     BufT[i]+= ((BufT1[j]-0x30));
     if (BufT1[j]>0x40) BufT[i]-=7;
     LnB++;i++;
    }
if (errB)
 {ShowMessage("неверный формат строки"); return;}
//----
    ptBufT= &BufT[0];
    LenBufT= LnB;
                         */
//------------------------------
 //udp1->SendBuffer(IP_adr_out.c_str(),Port_out,ptBufT,LnB) ;
 //udp1->Send(IP_adr_out.c_str(),Port_out,"4800") ;
 // Client -> Send(StrMemo);
  Client-> SendBuffer(&(M_32),24);



  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_READY_TEXTTimer(TObject *Sender)
{
 //Test->Text=StrMemo;
 //E_zapros1->Text=StrMemo;
 L_READY ->Color = clRed;
 T_READY_BLANK->  Enabled=true;
 T_READY_TEXT -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_READY_BLANKTimer(TObject *Sender)
{
 //Test->Text="";
// E_zapros1->Text="";
 L_READY ->Color= clWhite;
 T_READY_BLANK->  Enabled=false;
 T_READY_TEXT -> Enabled = true;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::T_CLIENT_SENDTimer(TObject *Sender)
{
 int F1,F2,F3;
 int i;
 F1=F2=F3=0;

  L_port3->Caption=" "; L_port3_hf_itog->Caption="";
  L_port2->Caption=" ";  L_port2_hf_itog->Caption="";
   L_port1->Caption=" ";  L_port1_hf_itog->Caption="";
   L_port1_hf->Caption="";   L_port2_hf->Caption="";
   L_port3_hf->Caption="";
   //E_HF_ITOG->Text=""; E_HF_ITOG->Color=clWhite;
   // E_HF_ITOG2->Text=""; E_HF_ITOG2->Color=clWhite;
   // E_HF_ITOG3->Text="";E_HF_ITOG3->Color=clWhite;
    L_port3_itog->Caption="";   L_port3_dmw->Caption="";
    L_port2_itog->Caption="";  L_port2_dmw->Caption="";
    L_port1_itog->Caption="";L_port1_dmw->Caption="";
 
if (FLAG1){
                E_cr_com->Text=" ";
 E_num_com->Text=" ";E_param->Text=" ";
 E_kzv->Text=" "; E_k_o->Text=" ";
 E_itog->Text="  ЦВМ-А(O) не готов";
 E_itog->Color=clWhite;
 E_W_ITOG->Color=clWhite;
 E_W_ITOG->Text="  ЦВМ-А(O) не готов";


  E_RAB2->Text="";E_PRD2_Z->Color=clWindow;E_PRM2_Z->Color=clWindow;

  E_PRM_Z2->Text="";  E_FK2-> Text="";
  E_M2-> Text=""; E_RT2 ->Text="";E_PPRZ2->Text="";

 if(START){ E_itog->Text=""; E_W_ITOG->Text="";}   }
else  {
        F1=1;L_port1->Caption=PORT1;L_port1_hf_itog->Caption="ЦВС1";
        L_port1_hf->Caption="ЦПП1";
        L_port1_dmw->Caption="P999";
        L_port1_itog->Caption="ЦВС2";}
 if (FLAG2){

    E_RAB->Text="";E_RLI->Color=clWindow;E_PRD_Z->Color=clWindow;
   E_PRD_Z->Text="";
  E_PRM_Z->Text=""; E_RT->Text=""; E_FK->Text="" ;
  E_M->Text="" ; E_RT2 ->Text="";E_PPR_Z->Text="";
   E_MI_Z->Text=""; E_O2->Text="";
 }
 else {
        F2=1;L_port2->Caption=PORT2;L_port2_hf_itog->Caption="ЦВС2/1";
        L_port2_hf->Caption="ЦПП2";
        L_port2_dmw->Caption=PORT2;
        L_port2_itog->Caption=PORT2;}


   /*     if (F1)
        {
   if((READ_COMMAND.READ_COM.num_com==OLD_N_com)&
(READ_COMMAND.READ_COM.cr_com!=old_cr_com) & (READ_COMMAND.READ_COM.kzv==0))
{
 BLOCK=0;
old_cr_com= READ_COMMAND.READ_COM.cr_com;
E_itog->Text="   команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";
 // E_itog->Text="               ВЫПОЛНЕНО " ;
 E_itog->Color=clMoneyGreen;
 E_HF_ITOG->Text="    команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";
// E_HF_ITOG->Text="               ВЫПОЛНЕНО " ;
 E_HF_ITOG->Color=clMoneyGreen;
 if(READ_COMMAND.READ_COM.num_com==77)  // если команда запрос
 {E_TKI->Color=clMoneyGreen; E_RLI->Color=clMoneyGreen;
 E_PRD_Z ->Color=clMoneyGreen; E_PRM_Z ->Color=clMoneyGreen;
 E_TKI->Text= " НОРМА ";  E_RLI->Text=" НОРМА";
 E_PRM_Z->Text= " НОРМА ";  E_PRD_Z->Text=" НОРМА";}
 if(READ_COMMAND.READ_COM.num_com==78)              // если команда контроль
 {
 E_prd ->Color=clMoneyGreen; E_prm ->Color=clMoneyGreen;
 E_prm->Text= " НОРМА ";  E_prd->Text=" НОРМА";}
 }
 if((READ_COMMAND.READ_COM.num_com==OLD_N_com)&
//(READ_COMMAND.READ_COM.cr_com>OLD_NP_com) & (READ_COMMAND.READ_COM.kzv!=0))
 (READ_COMMAND.READ_COM.cr_com!=old_cr_com) & (READ_COMMAND.READ_COM.kzv!=0))
{
old_cr_com= READ_COMMAND.READ_COM.cr_com ;
E_itog->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
" не выполнена";E_itog->Color=clRed;
E_HF_ITOG->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
" не выполнена";E_HF_ITOG->Color=clRed;//BLOCK=0;
  if(READ_COMMAND.READ_COM.num_com==77)  // если команда запрос
 {E_TKI->Color=clRed; E_RLI->Color=clRed;
 E_PRD_Z ->Color=clRed; E_PRM_Z ->Color=clRed;
 E_TKI->Text= "НЕНОРМА";  E_RLI->Text="НЕНОРМА";
 E_PRM_Z->Text= "НЕНОРМА ";  E_PRD_Z->Text="НЕНОРМА";}
 if(READ_COMMAND.READ_COM.num_com==78)              // если команда контроль
 {
 E_prd ->Color=clRed; E_prm ->Color=clRed;
 E_prm->Text= "НЕНОРМА";  E_prd->Text="НЕНОРМА";}
}
  }   
  if (F2)
  {

   if((READ_COMMAND2.READ_COM.num_com==OLD_N_com)&
//(READ_COMMAND2.READ_COM.cr_com!=OLD_NP_com) & (READ_COMMAND2.READ_COM.kzv==0))
 (READ_COMMAND2.READ_COM.cr_com!=old_cr_com2) & (READ_COMMAND2.READ_COM.kzv==0))
{
BLOCK2=0;
old_cr_com2= READ_COMMAND2.READ_COM.cr_com;
E_itog2->Text="   команда " + IntToStr(READ_COMMAND2.READ_COM.num_com)+ " выполнена";
 // E_itog->Text="               ВЫПОЛНЕНО " ;
 E_itog2->Color=clMoneyGreen;
 E_HF_ITOG2->Text="   команда " + IntToStr(READ_COMMAND2.READ_COM.num_com)+ " выполнена";
 //E_HF_ITOG2->Text="               ВЫПОЛНЕНО " ;
 E_HF_ITOG2->Color=clMoneyGreen;
 if(READ_COMMAND.READ_COM.num_com==78)              // если команда контроль
 {
 E_prd2 ->Color=clMoneyGreen; E_prm2 ->Color=clMoneyGreen;
 E_prm2->Text= " НОРМА ";  E_prd2->Text=" НОРМА";}
 }
 if((READ_COMMAND2.READ_COM.num_com==OLD_N_com)&
//(READ_COMMAND2.READ_COM.cr_com>OLD_NP_com) & (READ_COMMAND2.READ_COM.kzv!=0))
(READ_COMMAND2.READ_COM.cr_com!=old_cr_com2) & (READ_COMMAND2.READ_COM.kzv!=0))
{
old_cr_com2= READ_COMMAND2.READ_COM.cr_com;
E_itog2->Text="   команда " + IntToStr(READ_COMMAND2.READ_COM.num_com)+
" не выполнена";E_itog2->Color=clRed;
E_HF_ITOG2->Text="    команда " + IntToStr(READ_COMMAND2.READ_COM.num_com)+
" не выполнена";E_HF_ITOG2->Color=clRed;//BLOCK=0;
  if(READ_COMMAND.READ_COM.num_com==78)              // если команда контроль
 {
 E_prd2 ->Color=clRed; E_prm2 ->Color=clRed;
 E_prm2->Text= "НЕНОРМА";  E_prd2->Text="НЕНОРМА";}
}
  }   
    if (F3)
  {

   if((READ_COMMAND3.READ_COM.num_com==OLD_N_com)&
//(READ_COM.cr_com!=OLD_NP_com) & (READ_COMMAND3.READ_COM.kzv==0))
 (READ_COMMAND3.READ_COM.cr_com!=old_cr_com3) & (READ_COMMAND3.READ_COM.kzv==0))
{
BLOCK3=0;
  old_cr_com3= READ_COMMAND3.READ_COM.cr_com;
E_itog3->Text="   команда " + IntToStr(READ_COMMAND3.READ_COM.num_com)+ " выполнена";
 // E_itog->Text="               ВЫПОЛНЕНО " ;
 E_itog3->Color=clMoneyGreen;
 E_HF_ITOG3->Text="   команда " + IntToStr(READ_COMMAND3.READ_COM.num_com)+ " выполнена";
 //E_HF_ITOG3->Text="               ВЫПОЛНЕНО " ;
 E_HF_ITOG3->Color=clMoneyGreen;
 }
 if((READ_COMMAND3.READ_COM.num_com==OLD_N_com)&
//(READ_COMMAND3.READ_COM.cr_com!=OLD_NP_com) & (READ_COMMAND3.READ_COM.kzv!=0))
 (READ_COMMAND3.READ_COM.cr_com!=old_cr_com3) & (READ_COMMAND3.READ_COM.kzv!=0))
{
 old_cr_com3= READ_COMMAND3.READ_COM.cr_com;
E_itog3->Text="  команда " + IntToStr(READ_COMMAND3.READ_COM.num_com)+
" не выполнена";E_itog3->Color=clRed;
E_HF_ITOG3->Text="  команда " + IntToStr(READ_COMMAND3.READ_COM.num_com)+
" не выполнена";E_HF_ITOG3->Color=clRed;//BLOCK=0;
}
  }  */
//////////////////////////////////////////////////////////////////////
if (FLAG1 & FLAG2 & FLAG3 ){READY=0;T_READY->Enabled=true;
T_READY->Interval=1000;T_READY_BLANK->Enabled =true;
T_READY_TEXT -> Enabled=true;L_READY->Caption="Прибор не готов";
PageControl1->Visible=true;P_com->Visible=true;}
else { L_READY->Color=clMoneyGreen;L_READY->Caption="Прибор готов";
PageControl1->Visible=true;}
Client-> SendBuffer(&(M_32),24);
for (i=0;i<1000;i++);


for (i=0;i<1000;i++);
FLAG1=FLAG2=FLAG3=1;

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
/* if((READ_COMMAND.READ_COM.num_com==OLD_N_com)&
(READ_COMMAND.READ_COM.cr_com>OLD_NP_com) & (READ_COMMAND.READ_COM.kzv==0))
{E_itog->Text="   команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";
 E_itog->Color=clMoneyGreen;
 E_HF_ITOG->Text="   команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+ " выполнена";
 E_HF_ITOG->Color=clMoneyGreen;BLOCK=0;
 }
 else
  {E_itog->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
" не выполнена";E_itog->Color=clRed;
E_HF_ITOG->Text="  команда " + IntToStr(READ_COMMAND.READ_COM.num_com)+
" не выполнена";E_HF_ITOG->Color=clRed;BLOCK=0;
}   */
if(BLOCK)
{E_itog->Text="  ЦВМ-А(О) не отвечает";
 E_W_ITOG->Text="    ЦВМ-А(О) не отвечает";
   E_cr_com->Text=" ";
 E_num_com->Text=" ";E_param->Text=" ";
 E_kzv->Text=" "; E_k_o->Text=" ";
 BLOCK=0;}

T_10sec->Interval=0;
}
//---------------------------------------------------------------------------

















void __fastcall TForm1::W_BClick(TObject *Sender)
{
if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 //if (FK->Checked==false)
// {ShowMessage("Перейдите в режим ФК");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
// GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 // GroupBox1->Color=clBtnFace;

 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;
 
 E_W_ITOG->Text="";E_W_ITOG->Color=clWhite;

 short nk;
 int P1,P2,P3,P4,P5;

 nk= StrToInt(W_Enk ->Text);
 P1= StrToInt(W_Ep1 ->Text);
 P2= StrToInt(W_Ep2 ->Text);
 P3= StrToInt(W_Ep3 ->Text);
 P4= StrToInt(W_Ep2 ->Text);
 P5= StrToInt(W_Ep2 ->Text);

  M_32.NP_com++;
  M_32.N_com = nk;
  M_32.P1= P1;
  M_32.P2= P2;
  M_32.P3= P3;
  M_32.P4= P4;
  M_32.P5= P5;
 
   OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;        
}
//---------------------------------------------------------------------------















void __fastcall TForm1::HF_sheetEnter(TObject *Sender)
{
/*if (BLOCK || BLOCK2 || BLOCK3)
 {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
// GroupBox1->Color=clActiveBorder;
 HF_points->Color=clBtnFace;
 HF_oslab->Color=clBtnFace;
 HF_data->Color=clBtnFace;
 HF_rabota->Color=clBtnFace;
 HF_fk->Color=clBtnFace;
 HF_m->Color=clBtnFace;
 HF_prm->Color=clBtnFace;
 GroupBox19->Color=clBtnFace ;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 E_PPR -> Color = clWhite;
 E_MI-> Color = clWhite;
 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;
 E_HF_ITOG->Text="";E_HF_ITOG->Color=clWhite;
   E_itog2->Text="";E_itog2->Color=clWhite;
 E_HF_ITOG2->Text="";E_HF_ITOG2->Color=clWhite;
   E_itog3->Text="";E_itog3->Color=clWhite;
 E_HF_ITOG3->Text="";E_HF_ITOG3->Color=clWhite;
short FT=1;     */
/*if(PRM7 -> Checked == true) FT=7;
if(T1_7 -> Checked == true) {F_T=0x1;E_RT -> Text= "1-7";}
if(T2_8 -> Checked == true) {F_T=0x2;E_RT -> Text= "2-8";}
if(T3_9 -> Checked == true) {F_T=0x3;E_RT -> Text= "3-9";}
if(T4_10 -> Checked == true) {F_T=0x4;E_RT -> Text= "4-10";}
if(T5_11 -> Checked == true) {F_T=0x5;E_RT -> Text= "5-11";}
if(T6_12 -> Checked == true) {F_T=0x6;E_RT -> Text= "6-12";}  */
 /*M_32.NP_com++;
 M_32.N_com = FT;
 M_32.P1= 0;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
  OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;   */

        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
if (PageControl1->ActivePage==HF_sheet)
{
//if (BLOCK || BLOCK2 || BLOCK3)
// {ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 //GroupBox1->Color=clBtnFace;


 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
 ekv->Checked=true;
 off_dmw->Checked=true;
 //GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 
 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;



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
  // if (BLOCK || BLOCK2 || BLOCK3)
 //{ShowMessage("Дождитесь выполнения предыдущей команды");return;}
 BLOCK=BLOCK2=BLOCK3=1;
 ekv->Checked=true;
 off_dmw->Checked=true;
 Panel7->Color= clBtnFace;//Подсветка панели
 GroupBox3 ->Color=clBtnFace;
 GroupBox4 ->Color=clBtnFace;
 GroupBox15 ->Color=clBtnFace;
//GroupBox16 ->Color=clBtnFace;
 GroupBox17 ->Color=clBtnFace;
 // GroupBox1->Color=clBtnFace;

 T_10sec->Interval=Z_time;
 E_itog->Text="";E_itog->Color=clWhite;



  E_frch->Text="";E_kan->Text="";E_ck->Text="";E_power->Text="";
 
   READ_COMMAND.READ_COM.P999=0;
   READ_COMMAND2.READ_COM.P999=0;
   READ_COMMAND3.READ_COM.P999=0;
short Nondmw=4;
if (off_dmw -> Checked == true) N_on_dmw =0;
else N_on_dmw = 1;

 M_32.NP_com++;
 M_32.N_com = Nondmw;
 M_32.P1= N_on_dmw;
 M_32.P2=M_32.P3=M_32.P4=M_32.P5=0;
 OLD_NP_com= M_32.NP_com;
 OLD_N_com= M_32.N_com;
   }
}
//---------------------------------------------------------------------------



