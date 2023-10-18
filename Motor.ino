void setup() {
  // put your setup code here, to run once:
  Serial.begin(1000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Init[12] = {2046, 2048, 2046, 2047, 2048, 2048, 2048, 2048, 1023, 1023, 2044, 2047};
  Driving_MX(Init,200);
}
void Driving_MX(int position[12], unsigned int spd){
  unsigned char i;
  int t = 0;
  
  unsigned char POS_L[12];
  for (int i = 0; i <12; i++)
  POS_L[i] = (unsigned char)(position[i] & 0xFF);
  
  unsigned char POS_H[12];
  for (int i = 0; i<12;i++)
  POS_H[i] = (unsigned char)(position[i] >> 8) & 0xFF;
  
  unsigned char Spd_L,Spd_L1;
  Spd_L = (unsigned char)(spd & 0xFF);
  Spd_L1 = (unsigned char)((spd*2) & 0xFF);
  unsigned char Spd_H,Spd_H1;
  Spd_H = (unsigned char)(spd >> 8) & 0xFF;
  Spd_H1 = (unsigned char)(((spd*2) >>8) & 0xFF);

  unsigned int txBuff[68];
  
  txBuff[0] = 0xFF;
  txBuff[1] = 0xFF;

  txBuff[2] = 0xFE;
  txBuff[3] = 0x40; //LENGTH
  
  txBuff[4] = 0x83;//0x03;
  
  txBuff[5] = 0x1E;
  
  txBuff[6] = 0x04; //갯수
  
  txBuff[7] = 0x07;
  txBuff[8] = POS_L[t];
  txBuff[9] = POS_H[t];
  txBuff[10] = Spd_L;
  txBuff[11] = Spd_H;
  t++;
  
  
  txBuff[12] = 0x08;
  txBuff[13] = POS_L[t];
  txBuff[14] = POS_H[t];
  txBuff[15] = Spd_L;
  txBuff[16] = Spd_H;
  t++;
  
  txBuff[17] = 0x09;
  txBuff[18] = POS_L[t];
  txBuff[19] = POS_H[t];
  txBuff[20] = Spd_L;
  txBuff[21] = Spd_H;
  t++;
  
  txBuff[22] = 0x0A;
  txBuff[23] = POS_L[t];
  txBuff[24] = POS_H[t];
  txBuff[25] = Spd_L;
  txBuff[26] = Spd_H;
  t++;
  
  txBuff[27] = 0x0B;
  txBuff[28] = POS_L[t];
  txBuff[29] = POS_H[t];
  txBuff[30] = Spd_L;
  txBuff[31] = Spd_H;
  t++;
  
  txBuff[32] = 0x0C;
  txBuff[33] = POS_L[t];
  txBuff[34] = POS_H[t];
  txBuff[35] = Spd_L;
  txBuff[36] = Spd_H;
  t++;
  
  txBuff[37] = 0x0D;
  txBuff[38] = POS_L[t];
  txBuff[39] = POS_H[t];
  txBuff[40] = Spd_L;
  txBuff[41] = Spd_H;
  t++;
  
  txBuff[42] = 0x0E;
  txBuff[43] = POS_L[t];
  txBuff[44] = POS_H[t];
  txBuff[45] = Spd_L;
  txBuff[46] = Spd_H;
  t++;
  
  txBuff[47] = 0x0F;
  txBuff[48] = POS_L[t];
  txBuff[49] = POS_H[t];
  txBuff[50] = Spd_L;
  txBuff[51] = Spd_H;
  t++;
  
  txBuff[52] = 0x10;
  txBuff[53] = POS_L[t];
  txBuff[54] = POS_H[t];
  txBuff[55] = Spd_L;
  txBuff[56] = Spd_H;
  t++;
  
  txBuff[57] = 0x11;
  txBuff[58] = POS_L[t];
  txBuff[59] = POS_H[t];
  txBuff[60] = Spd_L;
  txBuff[61] = Spd_H;
  t++;
  
  txBuff[62] = 0x12;
  txBuff[63] = POS_L[t];
  txBuff[64] = POS_H[t];
  txBuff[65] = Spd_L;
  txBuff[66] = Spd_H;

  txBuff[67] = 0;
  
  for (i = 2;i<67;i++)
  txBuff[67] += txBuff[i];
  
  txBuff[67] = ~txBuff[67];
  
  for (i=0;i<68;i++)
  {
    Serial.write(txBuff[i]);
    //Uart_Putch_1(txBuff[i]);
    _delay_ms(1);
  }
}
