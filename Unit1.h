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
//---------------------------------------------------------------------------

struct formrls {
      short num_out;
      short num_in;
      int time; //int double
      float car_freq;
      float imp_freq;
      float inp_len;
      short mod_type;
      float scan_time;
      float targ_bear;
      float bear_sko;
      float targ_vip;
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
        TEdit *E_RLI;
        TTabSheet *DMW_sheet;
        TTimer *T_PPR;
        TTimer *T_PPR2;
        TTimer *T_MI;
        TTimer *T_MI2;
        TIdUDPServer *udp1;
        TTimer *T_READY;
        TLabel *L_READY;
        TTimer *T_READY_TEXT;
        TTimer *T_READY_BLANK;
        TIdUDPClient *Client;
        TTimer *T_READ;
        TTimer *T_CLIENT_SEND;
        TLabel *Label48;
        TButton *Button3;
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
        TLabel *L_port1;
        TIdUDPServer *udp2;
        TIdUDPServer *udp3;
        TTabSheet *TabSheet1;
        TLabel *Label43;
        TEdit *W_Ep1;
        TEdit *W_Ep3;
        TEdit *W_Ep4;
        TEdit *W_Ep5;
        TButton *W_B;
        TLabel *Label44;
        TLabel *Label53;
        TLabel *Label60;
        TLabel *Label61;
        TLabel *Label62;
        TEdit *W_Enk;
        TEdit *W_Ep2;
        TLabel *Label84;
        TPanel *DMW_send;
        TGroupBox *GroupBox3;
        TLabel *Label9;
        TLabel *Label10;
        TRadioButton *on_dmw1;
        TRadioButton *off_dmw;
        TButton *B_on;
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
        TGroupBox *GroupBox15;
        TLabel *Label30;
        TLabel *Label31;
        TRadioButton *on_prd;
        TRadioButton *off_prd;
        TButton *B_prd;
        TCSpinEdit *power;
        TLabel *Label85;
        TEdit *E_PRD2_Z;
        TEdit *E_PRD3_Z;
        TButton *Button1;
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
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TEdit *Edit11;
        TEdit *Edit12;
        TEdit *Edit13;
        TEdit *Edit14;
        TEdit *Edit15;
        TEdit *Edit16;
        TEdit *Edit17;
        TEdit *Edit18;
        TEdit *Edit19;
        TEdit *Edit20;
        TEdit *Edit21;
        TEdit *Edit22;
        TEdit *Edit23;
        TEdit *Edit24;
        TEdit *Edit25;
        TEdit *Edit26;
        TEdit *Edit27;
        TEdit *Edit28;
        TEdit *Edit29;
        TEdit *Edit30;
        TEdit *Edit31;
        TEdit *Edit32;
        TEdit *Edit33;
        TEdit *Edit34;
        TEdit *Edit35;
        TEdit *Edit36;
        TEdit *Edit37;
        TEdit *Edit38;
        TEdit *Edit39;
        TEdit *Edit40;
        TEdit *Edit41;
        TEdit *Edit42;
        TEdit *Edit43;
        TEdit *Edit44;
        TEdit *Edit45;
        TEdit *Edit46;
        TEdit *Edit47;
        TEdit *Edit48;
        TEdit *Edit49;
        TEdit *Edit50;
        TEdit *Edit51;
        TEdit *Edit52;
        TEdit *Edit53;
        TEdit *Edit54;
        TEdit *Edit55;
        TEdit *Edit56;
        TEdit *Edit57;
        TEdit *Edit58;
        TEdit *Edit59;
        TEdit *Edit60;
        TEdit *Edit61;
        TEdit *Edit62;
        TEdit *Edit63;
        TEdit *Edit64;
        TEdit *Edit65;
        TLabel *Label23;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TEdit *Edit66;
        TEdit *Edit67;
        TEdit *Edit68;
        TLabel *Label36;
        TButton *Button4;
        void __fastcall OUT_1Click(TObject *Sender);
        void __fastcall B_HFClick(TObject *Sender);
        void __fastcall Button24Click(TObject *Sender);
        void __fastcall Exit_dmwClick(TObject *Sender);
        void __fastcall B_rab_kanClick(TObject *Sender);
        void __fastcall B_frchClick(TObject *Sender);
        void __fastcall B_ckClick(TObject *Sender);
        void __fastcall B_powerClick(TObject *Sender);
        void __fastcall B_prdClick(TObject *Sender);
        void __fastcall B_antClick(TObject *Sender);
        void __fastcall B_onClick(TObject *Sender);
        void __fastcall B_dmwClick(TObject *Sender);
        void __fastcall ControlClick(TObject *Sender);
        void __fastcall B_PRMClick(TObject *Sender);
        void __fastcall B_rab_tClick(TObject *Sender);
        void __fastcall B_OClick(TObject *Sender);
        
        void __fastcall B_rabClick(TObject *Sender);


        void __fastcall Button2Click(TObject *Sender);
       
        void __fastcall RKKeyPress(TObject *Sender, char &Key);
        void __fastcall powerKeyPress(TObject *Sender, char &Key);
        void __fastcall E_PPRKeyPress(TObject *Sender, char &Key);
        void __fastcall E_MIKeyPress(TObject *Sender, char &Key);
        void __fastcall E_OsKeyPress(TObject *Sender, char &Key);
        void __fastcall T_PPRTimer(TObject *Sender);
        void __fastcall T_PPR2Timer(TObject *Sender);
        void __fastcall T_MITimer(TObject *Sender);
        void __fastcall T_MI2Timer(TObject *Sender);
        void __fastcall B_controlClick(TObject *Sender);
        void __fastcall udp1UDPRead(TObject *Sender, TStream *AData,
          TIdSocketHandle *ABinding);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall T_READYTimer(TObject *Sender);
        void __fastcall T_READY_TEXTTimer(TObject *Sender);
        void __fastcall T_READY_BLANKTimer(TObject *Sender);
        void __fastcall T_CLIENT_SENDTimer(TObject *Sender);
        void __fastcall Combo_portKeyPress(TObject *Sender, char &Key);
        void __fastcall Combo_portChange(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall T_10secTimer(TObject *Sender);
        
        void __fastcall W_BClick(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
       
private:	// User declarations
public:		// User declarations
        int HF_main,HF2,BLOCK,BLOCK2,BLOCK3;
        int   DMW_main,N_on_dmw,N_ant,N_on_corc;
        unsigned short DMW_power,N_kan,N_frch,N_ck,N_prd,
        F_T,F_O,F_TKI,F_RAB,F_FK,F_M,F_PRM,F_PPR,F_MI ;
        short OLD_N_com;
        unsigned short OLD_NP_com ;
        __fastcall TForm1(TComponent* Owner);
};
       void T5(void * pParams );
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
struct M32
  {
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
	float speed;
	float	x; //koordinata
	float	y; //koordinata
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

  }  MYHOST,MYHOST2,MYHOST3;
  union {char BUF[500];struct HOST MYHOST;} uni,uni2,uni3;
  struct packusoi{
  // OBL1
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
    union {
         struct {
            unsigned short cr; //nomer paketa
            short sach18[6];
            unsigned short nword;
            short word[97];
         } svch1;
         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            unsigned short nform; //kol-vo form3 po 10 slov
            short form1[9]; //10 //nositel
            short form2[4]; //5
            short form3[80];//1100
         } svch1_no;

		  struct {
            unsigned short cr;
            short sach18[6];
            short form1[9]; //10
            short form3[10]; //5
         } svch1_nz;

         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            unsigned short nform; //kol-vo form4 po 11 slov
            short form1[9]; //10 //nositel
            short form4[88]; //pasport res
         } svch1_reo;

	     struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            short form1[9]; //10 //nositel
            short form4[11]; //pasport res
         } svch1_res;

		 struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            short form1[9]; //10 //nositel
            short form2[4]; //pasport res
         } svch1_vz;

      };

    // OBL3---------------------------------------------------

      union {
         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
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
      };
   } READ_COM;
   union {unsigned char BUF[500];struct packusoi READ_COM;} READ_COMMAND,

   READ_COMMAND2,READ_COMMAND3;

    unsigned short old_cr_com,old_cr_com2,old_cr_com3;

   /*
     typedef   struct  {
      unsigned short cr_com; //por9dkovii nomer
      short num_com; //nomer poslednei
      int lp2_param; //1 parametr komandi
      short kzv;
      int k_o; //kod owibki
      short fk; //kod FK
      short link; 

      unsigned int sost_kasrt[9];
      unsigned int sost_spiak[2];

      union {
         struct {
            unsigned short cr; //nomer paketa
            short sach18[6];
            unsigned short nword;
            short word[97];
        // } svch1;
         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            unsigned short nform; //kol-vo form3 po 10 slov
            short form1[9]; //10 //nositel
            short form2[4]; //5
            short form3[80];//1100
         } svch1_no;

		  struct {
            unsigned short cr;
            short sach18[6];
            short form1[9]; //10
            short form3[10]; //5
         } svch1_nz;

         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            unsigned short nform; //kol-vo form4 po 11 slov
            short form1[9]; //10 //nositel
            short form4[88]; //pasport res
         } svch1_reo;

	     struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            short form1[9]; //10 //nositel
            short form4[11]; //pasport res
         } svch1_res;

		 struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
            short form1[9]; //10 //nositel
            short form2[4]; //pasport res
         } svch1_vz;

      };



      union {
         struct {
            unsigned short cr;//nomer paketa
            short sach18[6];
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
      };
   } packusoi;      */

