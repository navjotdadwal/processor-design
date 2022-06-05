// Project made for computer architecture subject 
// A processor which can adopt any specifications according to the requirements 
// It is based on the harvard architecture
/*
program of special processor made in a project using the concepts of computer architecture
*/
#include <bits/stdc++.h>
using namespace std;  
typedef unsigned int BYTE; 
#define pb push_back
/* Opcodes */

#define OPCODE_LDA 0x00
#define OPCODE_JMP 0x01
#define OPCODE_STA 0x02
#define OPCODE_IN 0x03
#define OPCODE_OUT 0x04

/* Registers */

/* Following registers can be used as a 8-bit Registers */
BYTE   ProgramCounter; 
BYTE   TMP;
BYTE   RAM;
BYTE   IR;
BYTE   Acc;
BYTE   MAR;
BYTE   IN;
BYTE   OUT;

vector<pair<int,pair<int,int>>>  Memory;  // RAM for storage of programs
vector<vector<vector<int>>> ROM;   // ROM 
vector<int> mem; // RAM for the storage of data

/*
Mapping:
1 -> PC(E)
2-> PC(I)
3 -> MAR(E,L)
4 -> RAM(E)
5 -> IR(L)
6 -> TMP(L)
7 -> TMP(E) 
8 -> A(L)
9 -> RAM(L)
10 -> A(E)
11 -> PC(L)
12 -> IN(E)
13 -> OUT(L)
14 -> ALIN()
15 -> AEOUT()
*/


void incrementPCi()
{
  ProgramCounter++; 
  cout<<"PC(I) The program counter is incremented\n";
}

void enablePC()
{
  cout<<"PC(E) Program counter is enabled\n";
  MAR=Memory[ProgramCounter].first;
}

void MAREL()
{
  RAM=MAR;
  cout<<"MAR(E,L) value stored in RAM through MAR\n"; 
}

vector<vector<int>> IRL()
{
  IR=RAM;
  cout<<"IR(L)fetching the particular block in ROM\n";
  return ROM[IR];
}

void RAME()
{
  cout<<"RAM is enabled(RAM(E))\n";
}

void RAML()
{
  cout<<"RAM is loaded(RAM(L))\n";
}

void TMPL()
{
  cout<<"TMP(L) so fetching value from RAM\n";
  TMP=RAM;  
}

void TMPE()
{
  cout<<"TMP(E) temp is enabled\n";
  MAR=TMP;  
}

void PCL()
{
  cout<<"PC(L) program counter changed\n";
  ProgramCounter=TMP;  
}

void AL()
{
  cout<<"A(L) accumulator is loaded with value "<<mem[RAM]<<"\n";
  Acc=mem[RAM];  
}

void AE()
{
  cout<<"A(E) accumulator is enabled\n";
  RAM=Acc;  
}

void ALIN()
{
  cout<<"A(L) accumulator is loaded with value "<<IN<<"\n";
  Acc=IN;  
}

void AEOUT()
{
  cout<<"Output Port is loaded with Acc\n";
  OUT=Acc;  
}

void INE()
{
  cout<<"IN(E) operation\n";
}

void OUTL()
{
  cout<<"OUT(L) operation\n";
}

void func(int x)
{
  if(x==0)            
    cout<<"Empty clock cycle\n";
  else if(x==1)
    enablePC();
  else if(x==2)
    incrementPCi();
  else if(x==3)
    MAREL();
  else if(x==4)
    RAME();
  else if(x==6)
    TMPL();
  else if(x==7)
    TMPE();
  else if(x==8)
    AL();
  else if(x==9)
    RAML();
  else if(x==10)
    AE();
  else if(x==11)
    PCL();
  else if(x==12)
    INE();
  else if(x==13)
    OUTL();
  else if(x==14)
    ALIN();
  else if(x==15)
    AEOUT ();
}

vector<vector<int>> executeT0T1()
{
  func(1),func(3),func(4);
  return IRL();
}

int main()
{
  int sanity; // for iterating on the different lines of the program 

  printf("8 bit processor\n");

  /* Initialise Registers */

  ProgramCounter = 0; /* 8-bit Registers */
  TMP=0;
  RAM=0;
  IR=0;
  Acc=0;
  MAR=0;
  
  // Initializing ROM
  
  // 1. LDA adr
  vector<vector<int>> temp;
  vector<int> tp;
  // T0:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T1:
  tp.pb(2),tp.pb(4);
  temp.pb(tp);
  tp.clear();
  // T2:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T3: 
  tp.pb(2),tp.pb(4),tp.pb(6);
  temp.pb(tp);
  tp.clear();
  // T4:
  tp.pb(7),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T5:
  tp.pb(4),tp.pb(8);
  temp.pb(tp);
  tp.clear();
    
  ROM.pb(temp);
  temp.clear();

  // 2. JMP adr
  // T0:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T1:
  tp.pb(2),tp.pb(4);
  temp.pb(tp);
  tp.clear();
  // T2:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T3: 
  tp.pb(2),tp.pb(4),tp.pb(6);
  temp.pb(tp);
  tp.clear();
  // T4:
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T5:
  tp.pb(7),tp.pb(11);
  temp.pb(tp);
  tp.clear();
    
  ROM.pb(temp);
  temp.clear();

  // 3. STA adr
  // T0:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T1:
  tp.pb(2),tp.pb(4);
  temp.pb(tp);
  tp.clear();
  // T2:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T3: 
  tp.pb(2),tp.pb(4),tp.pb(6);
  temp.pb(tp);
  tp.clear();
  // T4:
  tp.pb(7),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T5:
  tp.pb(10),tp.pb(9);
  temp.pb(tp);
  tp.clear();
    
  ROM.pb(temp);
  temp.clear();

  // 4. IN
  // T0:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T1:
  tp.pb(2),tp.pb(4);
  temp.pb(tp);
  tp.clear();
  // T2:
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T3: 
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T4:
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T5:
  tp.pb(12),tp.pb(14);
  temp.pb(tp);
  tp.clear();
    
  ROM.pb(temp);
  temp.clear();

  // 5. OUT
  // T0:
  tp.pb(1),tp.pb(3);
  temp.pb(tp);
  tp.clear();
  // T1:
  tp.pb(2),tp.pb(4);
  temp.pb(tp);
  tp.clear();
  // T2:
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T3: 
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T4:
  tp.pb(0);
  temp.pb(tp);
  tp.clear();
  // T5:
  tp.pb(13),tp.pb(15);
  temp.pb(tp);
  tp.clear();
    
  ROM.pb(temp);
  temp.clear();
  
  // RAM for storing data 
  for(int i=0;i<20;i++)
    mem.pb(i);

  /* Main Fetch/Decode/Execute Loop */
  printf("Enter the number of operations\n");
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int ins;
    std::cin>> std::hex >> ins;
    int opc=(ins>>16);
    int op1=(ins>>8);
    op1^=((ins>>16)<<8);
    int op2=ins;
    op2^=((ins>>8)<<8);
    Memory.push_back({opc,{op1,op2}});
  }
  
  sanity = 0;

  while (sanity < Memory.size())
  {
    vector<vector<int>> block=executeT0T1();
    for(int i=2;i<block.size();i++)
    {
      for(int el: block[i])
        func(el);
    }
    cout<<"\n\n";
    sanity++;  
  }
   
    
}

