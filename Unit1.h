//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include "CSPIN.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <IdUDPClient.hpp>
#include <process.h>    /* _beginthread, _endthread */

	#define KRK_OK 0
	#define KRK_ERR 1
	#define KRK_LINK_ERR 2
	#define KRK_SWITCH_RECV 3
	#define KRK_DATA_NOT 4
	#define KRK_MODE_REO 5
	#define KRK_DATA_OK 6
	#define KRK_CMD_OK 7
	#define KRK_LINK_OK 8
	#define KRK_SWITCH_TRANS 9
	#define KRK_DATA_AND_TRANS 10
	#define KRK_SMS_OK 15
//---------------------------------------------------------------------------
struct sac {
      unsigned short ps: 1;
      unsigned short vr: 1;
      unsigned short rez1: 1;
      unsigned short kvi: 4;
      unsigned short rez2: 1;
      unsigned short nf: 8;

      unsigned short a0: 4;
      unsigned short a1: 4;
      unsigned short a2: 4;
      unsigned short a3: 4;

      unsigned short a4: 4;
      unsigned short a5: 4;
      unsigned short p0: 4;
      unsigned short p1: 4;

      unsigned short p2: 4;
      unsigned short p3: 4;
      unsigned short p4: 4;
      unsigned short p5: 4;

      unsigned short r0: 4;
      unsigned short r1: 4;
      unsigned short r2: 4;
      unsigned short r3: 4;

      unsigned short v0: 4;
      unsigned short v1: 4;
      unsigned short v2: 4;
      unsigned short v3: 4;
   };
   
struct formrls {
      short num_out;
      short num_in;
      int time;
      float car_freq;
      float imp_freq;
      float inp_len;
      short mod_type;
      float scan_time;
      float targ_bear;
      float bear_sko;
      float targ_vip;
	  float D_NRLS; //new ???
      float latitude;
      float longitude;
      float course;
      float speed;
      float div_course;
   };
   
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *OUT_1;
        TPageControl *PageControl1;
        TTabSheet *HF_sheet;
        TGroupBox *HW_receive;
    TEdit *Edit_13;
        TTabSheet *DMW_sheet;
        TIdUDPServer *udp1;
        TTimer *T_READY;
        TLabel *L_READY;
        TTimer *T_READY_TEXT;
        TTimer *T_READY_BLANK;
        TIdUDPClient *Client;
        TTimer *T_READ;
        TTimer *T_CLIENT_SEND;
    TButton *ADD_SET;
        TPanel *Panel_Tuning;
        TLabel *Label1;
        TLabel *Label15;
        TComboBox *Combo_IP;
        TComboBox *Combo_port;
        TButton *Button2;
        TTimer *T_10sec;
        TPanel *P_com;
        TLabel *Label65;
        TLabel *Label66;
        TLabel *Label67;
        TLabel *Label68;
        TLabel *Label71;
        TLabel *Label78;
        TEdit *E_cr_com;
        TEdit *E_num_com;
        TEdit *E_param;
        TEdit *E_kzv;
        TEdit *E_k_o;
        TTabSheet *TabSheet1;
        TLabel *Label43;
        TEdit *W_Ep1;
        TEdit *W_Ep3;
        TEdit *W_Ep4;
        TEdit *W_Ep5;
    TButton *R_Vvod;
        TLabel *Label44;
        TLabel *Label53;
        TLabel *Label60;
        TLabel *Label61;
        TLabel *Label62;
        TEdit *W_Enk;
        TEdit *W_Ep2;
        TLabel *Label84;
        TPanel *DMW_send;
        TPanel *Panel7;
        TGroupBox *GroupBox5;
        TLabel *Label24;
        TLabel *Label25;
        TRadioButton *frch;
        TRadioButton *pprch;
        TButton *B_frch;
        TGroupBox *GroupBox6;
        TCSpinEdit *RK;
        TGroupBox *GroupBox7;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TRadioButton *ck1200;
        TRadioButton *ck2400;
        TRadioButton *RadioButton39;
        TRadioButton *ck4800;
        TRadioButton *ck16000;
    TEdit *Edit_03;
    TEdit *Edit_23;
    TButton *CMD93;
        TGroupBox *DMW_receive;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TLabel *Label40;
        TEdit *E_frch;
        TEdit *E_kan;
        TEdit *E_power;
        TEdit *E_ck;
        TButton *Control;
        TEdit *E_W_ITOG;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
    TEdit *Edit_01;
    TEdit *Edit_11;
    TEdit *Edit_21;
    TEdit *Edit_02;
    TEdit *Edit_12;
    TEdit *Edit_22;
    TEdit *Edit_24;
    TEdit *Edit_04;
    TEdit *Edit_14;
    TEdit *Edit_05;
    TEdit *Edit_06;
    TEdit *Edit_15;
    TEdit *Edit_16;
    TEdit *Edit_26;
    TEdit *Edit_25;
    TEdit *Edit_27;
    TEdit *Edit_07;
    TEdit *Edit_17;
    TEdit *Edit_08;
    TEdit *Edit_09;
    TEdit *Edit_18;
    TEdit *Edit_19;
    TEdit *Edit_29;
    TEdit *Edit_28;
    TEdit *Edit_210;
    TEdit *Edit_010;
    TEdit *Edit_110;
    TEdit *Edit_011;
    TEdit *Edit_012;
    TEdit *Edit_111;
    TEdit *Edit_112;
    TEdit *Edit_212;
    TEdit *Edit_211;
    TEdit *Edit_213;
    TEdit *Edit_013;
    TEdit *Edit_113;
    TEdit *Edit_014;
    TEdit *Edit_015;
    TEdit *Edit_114;
    TEdit *Edit_115;
    TEdit *Edit_215;
    TEdit *Edit_214;
    TEdit *Edit_016;
    TEdit *Edit_116;
    TEdit *Edit_216;
    TEdit *Edit_217;
    TEdit *Edit_117;
    TEdit *Edit_017;
    TEdit *Edit_33;
    TEdit *Edit_31;
    TEdit *Edit_32;
    TEdit *Edit_34;
    TEdit *Edit_35;
    TEdit *Edit_36;
    TEdit *Edit_37;
    TEdit *Edit_38;
    TEdit *Edit_39;
    TEdit *Edit_310;
    TEdit *Edit_311;
    TEdit *Edit_312;
    TEdit *Edit_313;
    TEdit *Edit_314;
    TEdit *Edit_315;
    TEdit *Edit_316;
    TEdit *Edit_317;
        TLabel *Label23;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
    TEdit *Svoy;
    TEdit *Kuda;
        TEdit *Edit68;
        TLabel *Label36;
    TButton *SMS_RDR;
    TTimer *Timer1;
    TTimer *Timer2;
    TButton *Copy_form;
    TButton *S101;
    TEdit *Edit_link;
    TButton *Button1;
    TEdit *Edit3;
    TLabel *Label9;
    TLabel *Label10;
    TButton *S102;
    TButton *Button4;
    TButton *Priem;
        void __fastcall OUT_1Click(TObject *Sender);
        void __fastcall B_frchClick(TObject *Sender);
        void __fastcall ControlClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
       void __fastcall udp1UDPRead(TObject *Sender, TStream *AData,
          TIdSocketHandle *ABinding);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall T_READYTimer(TObject *Sender);
        void __fastcall T_READY_TEXTTimer(TObject *Sender);
        void __fastcall T_READY_BLANKTimer(TObject *Sender);
        void __fastcall T_CLIENT_SENDTimer(TObject *Sender);
        void __fastcall ADD_SETClick(TObject *Sender);
        void __fastcall T_10secTimer(TObject *Sender);
        void __fastcall R_VvodClick(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall PriemClick(TObject *Sender);
    void __fastcall CMD93Click(TObject *Sender);
    void __fastcall SMS_RDRClick(TObject *Sender);
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall Copy_formClick(TObject *Sender);
    void __fastcall S101Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Edit68Click(TObject *Sender);
    void __fastcall S102Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
       
private:	// User declarations
public:		// User declarations
        int HF_main,HF2,BLOCK,BLOCK2,BLOCK3;
        int   DMW_main,N_on_dmw,N_ant,N_on_corc;
        unsigned short DMW_power,N_kan,N_frch,N_ck,N_prd,
        F_T,F_O,F_TKI,F_RAB,F_FK,F_M,F_PRM,F_PPR,F_MI ;
        short OLD_N_com;
        unsigned short OLD_NP_com;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
struct M32
  {
   unsigned char res[4];
   unsigned short   NP_com ;// порядковый номер посд выданной ком
   short            N_com ;  //номер последней выданной команды
   int              P1;      // 1-й параметр команды
   int              P2;      // 2-й
   int              P3;      // 3-й параметр команды
   int              P4;      // 4-й
   int              P5;      // 5-й
	short pr_bearing; //short int
	float p; //peleng
	float k; //kurs
	//float speed;
	//float	x; //koordinata
	//float	y; //koordinata
    short nform;
    struct formrls form[3];
	char sms[80];
  /* int              P_HK_AK ;
   float            Peleng;
   float            Kurs;
   short            N_form;
   unsigned char    Form_RLS1[62];
   unsigned char    Form_RLS2[62];
   unsigned char    Form_RLS3[62];   */
  } M_32;
		
		
	struct HOST
	{
		short PORT ;
		char IP_adr[16];
	}  MYHOST;
	
	union 
	{
		char BUF[500];
		struct HOST MYHOST;
	} uni;
	
	struct packusoi{
  // OBL1
      //char res[4];
      unsigned short cr_com;
      short num_com;
      int param;
      short kzv;
      int k_o;
      short ended_loop;
      short krk;
      short link;
	  
	  unsigned int word_sost_kasrt1_1;
      unsigned int word_sost_kasrt1_2;
      unsigned int word_sost_kasrt2_1;
      unsigned int word_sost_kasrt2_2;
      unsigned int word_sost_0;
      unsigned int word_sost_1;
      unsigned int word_sost_2;
      unsigned int word_sost_3;
      unsigned int word_sost_sec;
      unsigned int word_sost_time;
      unsigned int word_sost_date;
      unsigned int word_sost_rts_1;
      unsigned int word_sost_rts_2;

  //  OBL2----------------------------------------------
   
         struct {
            unsigned short cr; //nomer paketa
            short sach18[6];
            unsigned short nword;
            short word[4082];
         } svch1;
      
		struct {
            unsigned short cr; //nomer paketa
            short sach18[6];
            unsigned short nword;
            short word[4082];
         } svch2;
    // OBL3---------------------------------------------------

      union {
         struct {
            unsigned short cr;//nomer paketa
            struct sac sach18;
            unsigned short nword;
            short word[89];
         } r999;
         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            unsigned short nform; //kol-vo form6 po 12 slov
            short form3[9];
            short form2[3];
            short form6[48];
         } r999_no;
		 struct {
	        unsigned short cr;
            struct sac sach18;
            short nform;
            struct formrls form[3];
         } r999_cu2;
         struct {
            unsigned short cr;
            short sach18[6];
            unsigned short  nform; //kol-vo form8 po 20 slov
            short form3[9];
            short form4[80];
         } r999_reo;
         struct {
            unsigned short cr; //nomer paketa
            short sach18[6];
            short form3[8];
         } r999_vz;
		 struct {
            unsigned short cr;
            struct sac sach18;
            unsigned short nword;
            char sms[80];           
         } r999_sms;
      };
   } READ_COM;
   union {unsigned char BUF[19000];struct packusoi READ_COM;} READ_COMMAND;

    unsigned short old_cr_com,old_link=0, old_R999_cr=0;
