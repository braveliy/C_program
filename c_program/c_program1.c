/************************************

 *  函数功能：  获取本月月底时间

 *  入参：  pin   -- 当前日期 <YYYYMM>

 *  出参：  pout  -- 当前日期的月底时间 <YYYYMMDD>

 *  返回值：0   -- 成功

 *      -1    -- 失败

 ************************************/

int getEndOfMonth(char *pin, char *pout)

{
  
  int tmp, tmp2;

    char tmpbuf[8+1], tmpbuf2[4+1];

  
  if( NULL == pin)

    {

        esbLog1(" 入参错误");

        return -1;

     }

     esbLog2("传入日期为[%s]", pin);


  
   memset(tmpbuf, 0x00, sizeof(tmpbuf));

     tmp = atoi(pin + 4);

     if(tmp == 12)

     {

         memset(tmpbuf2, 0x00, sizeof(tmpbuf2));

         strncpy(tmpbuf2, pin, 4);

         tmp2 = atoi(tmpbuf2);

         tmp2++;

         sprintf(tmpbuf, "%04d%s", tmp2, "0101");

     }

     else

    {

         tmp + = 1;

         strncpy(tmpbuf, pin, 4);

         sprintf(tmpbuf+4, "%02d%s", tmp, "01");

    }

  
  _FunDateAdd( tmpbuf, -1 );

    strncpy(pout, tmpbuf, 8);

    pout[8] = '\0';

    esbLog2("传出日期为[%s]", pout);

  
  return 0;

}


/****************************************

 *      功  能:  YYYYMMDD -> YYYY-MM-DD

 *      入参  :  len -- pDate所指内存长度

 ***************************************/

int DateTrans(char *pDate, int len)

{

  char buf[14+1];


  //esbLog2("DateTrans() is start");

  if(NULL == pDate || len == 0 || len > 14)

  {

     esbLog1("入参错误");

      return -1;

   }



   memset(buf, 0x00, sizeof(buf));

  //esbLog2("before DateTrans(): pDate is [%s]", pDate);

   strncpy(buf, pDate, 4);

   buf[4] = '-';

   strncpy(buf+5, pDate+4, 2);

   buf[7] = '-';

   strncpy(buf+8, pDate+6, 2);

  
 memset(pDate, 0x00, len);

   strcpy(pDate, buf);

   esbLog2("After DateTrans,pDate[%s]",pDate);


  //esbLog2("DateTrans() is end");

   return 0;

}

/****************************************

 *      功  能:  YYYY-MM-DD -> YYYYMMDD
 *    入参  :  len -- pDate所指内存长度

 ***************************************/

int DateTrans_(char *pDate, int len)

{

  char buf[14+1];


  //esbLog2("DateTrans() is start");

   
  if(NULL == pDate || len == 0 || len > 14)

  {

    esbLog1("入参错误");

     
    return -1;

  }

  
  
 
  memset(buf, 0x00, sizeof(buf));

  //esbLog2("before DateTrans_(): pDate is [%s]", pDate);

  strncpy(buf, pDate, 4);

  strncpy(buf+4, pDate+5, 2);

  strncpy(buf+6, pDate+8, 2);

  
memset(pDate, 0x00, len);

  strcpy(pDate, buf);

  esbLog2("After DateTrans,pDate[%s]",pDate);


  //esbLog2("DateTrans_() is end");

  return 0;

}

/****************************************

 *      功  能:  hhmmss -> hh.mm.ss      
 *      入参  :  len -- 长度

 ***************************************/

int TimeTrans(char *pTime, int len)

{

  char buf[14+1];


  //esbLog2("TimeTrans() is start");

  
if(NULL == pTime || len == 0 || len > 14)

  {

    esbLog1("入参错误");

    return -1;

  }

   
 

  memset(buf, 0x00, sizeof(buf));

  //esbLog2("before TimeTrans(): pTime is [%s]", pTime);

  
 
 
  strncpy(buf, pTime, 2);

  buf[2] = '.';

  strncpy(buf+3, pTime+2, 2);

  buf[5] = '.';

  strncpy(buf+6, pTime+4, 2);

  
  memset(pTime, 0x00, len);

  strcpy(pTime, buf);

  esbLog2("After TimeTrans,pTime[%s]",pTime);


  //esbLog2("TimeTrans() is end");

  return 0;

}

/****************************************

 *      功  能:  hhmmss -> hh:mm:ss      
 *      入参  :  len -- 长度

 ***************************************/

int TimeTrans_t(char *pTime, int len)

{

  char buf[14+1];


  //esbLog2("TimeTrans() is start");


  if(NULL == pTime || len == 0 || len > 14)

  {

    esbLog1("入参错误");

    return -1;

  }
   

  memset(buf, 0x00, sizeof(buf));

  //esbLog2("before TimeTrans(): pTime is [%s]", pTime);


  strncpy(buf, pTime, 2);

  buf[2] = ':';

  strncpy(buf+3, pTime+2, 2);

  buf[5] = ':';

  strncpy(buf+6, pTime+4, 2);

  
  memset(pTime, 0x00, len);

  strcpy(pTime, buf);

  esbLog2("After TimeTrans_t,pTime[%s]",pTime);


  //esbLog2("TimeTrans() is end");

  return 0;

}

/***********************************

 *  函数功能：16进制转为10进制

 *  返回值：  10进制数

 *  入参：    16进制数

 *  出参：      --

 **********************************/

long fun16to10(char*s)

{

  int i,t;
  
  long sum=0;
 
  for(i=0;s[i];i++)
 
  {

    s[i]=toupper(s[i]);

    if(s[i]<='9')

       t=s[i]-'0';

    else
 
       t=s[i]-'A'+10;
 
    sum=sum*16+t;
 
  }

  return sum;

}


/*   功能: 去除str开头处的空字符 */

void ltrim(char *str ) 
{

  char* s=str;

  while ( *s )

    if((*s == ' ')||(*s == '\t')||(*s == '\r')||(*s == '\n'))

      ++s;

    else

      break;


  if(s>str)

    strcpy(str, s);

}



/*  功能: 去除str结尾处的空字符 */

void rtrim(char *str) 
{

  char* s=str;

  while(*s)

    ++s;


  --s;

  while(s>=str)

    if((*s == ' ')||(*s == '\t')||(*s == '\r')||(*s == '\n') )

      --s;

    else

      break;


  *(s+1) = 0;

}


/****************************************************

* 功  能: 计算日期2与日期1之间相差天数

*     注：pDate2为NULL时与系统当前时间比较

*
             传入参数必须是mktime()支持的日期

* 参  数:

*   pDate1    -- YYYYMMDD

*   pDate2    -- YYYYMMDD

*   day     -- 相差天数

*

* 返回值:  int

*               0 -- 成功

*              非零 -- 失败

*               -9  --参数错误

****************************************************/

int CalDateDiff(char *pDate1, char *pDate2, int *day)

{

  struct tm date1, date2;

  time_t time1, time2;

  char buf[4+1];



  if (pDate1 == NULL || day == NULL )

  {

    return -1;

  }



  date1.tm_sec = 0;

  date1.tm_min = 0;

  date1.tm_hour = 0;

  strncpy(buf, pDate1+6, 2);

  buf[2] = '\0';

  date1.tm_mday = atoi(buf);

  strncpy(buf, pDate1+4, 2);

  buf[2] = '\0';

  date1.tm_mon = atoi(buf) - 1;

  strncpy(buf, pDate1, 4);

  buf[4] = '\0';

  date1.tm_year = atoi(buf) - 1900;

  date1.tm_wday = 0;

  date1.tm_yday = 0;

  date1.tm_isdst = 0;


  time1 = mktime(&date1);


  if (time1 == -1)

  {

    return -1;

  }

  
  if ( pDate2 == NULL )

  {

    time2 = time(NULL);

  }

  else

  {

    date2.tm_sec = 0;

    date2.tm_min = 0;

    date2.tm_hour = 0;

    strncpy(buf, pDate2+6, 2);

    buf[2] = '\0';

    date2.tm_mday = atoi(buf);

    strncpy(buf, pDate2+4, 2);

    buf[2] = '\0';

    date2.tm_mon = atoi(buf) - 1;

    strncpy(buf, pDate2, 4);

    buf[4] = '\0';

    date2.tm_year = atoi(buf) - 1900;

    date2.tm_wday = 0;

    date2.tm_yday = 0;

    date2.tm_isdst = 0;


    time2 = mktime(&date2);


    if (time2 == -1)

      return -1;

  }


  *day = (time2 - time1) / (60*60*24);

  return 0;

}

/***********************************
 *  函数功能：  获取ECC流水号

 *  返回值：    0 -- 处理成功

 *              1 -- 处理失败

 *  入参：      --

 *  出参：      --

 **********************************/

int _FunGetTraceNo(char *szTmp )

{

  union   semun

  {

    int val;

    struct  semid_ds  *buf;

    ushort  *array;

  };


  union   semun   sem_arg;

  struct  sembuf  op_p = { 0,-1,0 };      /* P操作 */

  struct  sembuf  op_v = { 0,1,0 };     /* V操作 */

  int pid;
  int semid;

  int i;

  int ret;

  FILE *fp;

  char seq[20];

  int  seqno;

  char fileName[512];

  key_t   key;


  memset(szTmp,0,sizeof(szTmp));

  memset(seq,0,sizeof(seq));

  memset(fileName,0,sizeof(fileName));


  sprintf(fileName, "%s/%s",getenv("HOME"), "etc/seq.cfg");

  key = ftok( fileName , 1 );  /* 根据文件seq.cfg获取key */

  if( key < 0 )
{

    esbLogerr( " create key err![%s]",strerror( errno ));

    return( -1 );

  }


  /*20130418删除
  esbLog2( "key is %d", key );*/


  /* 获取系统中的信号量值 */

  semid = semget( key, 1, 00600 );


  /* 不成功则创建信号量 */

  if( semid < 0 )
{
 
   semid = semget( key, 1, 00600 | IPC_CREAT |IPC_EXCL );

    if( semid < 0 )
{

      esbLogerr( "semctl err! msg[%s]\n", strerror( errno));

      return( -1 );

    }

    sem_arg.val = 1;

    /* 置信号量为"有资源" */

    if( semctl( semid, 0, SETVAL, sem_arg ) < 0 )
{

      esbLogerr( "semctl err! msg[%s]\n", strerror( errno));

      semctl( semid, 0, IPC_RMID, sem_arg );

      return( -1 );

    }

  }


  ret=semop( semid, &op_p, 1 );


  /*20130418删除
  esbLog2("Now lock");*/


  fp = fopen(fileName,"r+");

  if ( fp == NULL )
{

    fp = fopen(fileName,"w");

    seqno = 40000000;

  }
  else
{
 
   fscanf(fp,"%d",&seqno);

    rewind(fp);

  }


  if((seqno > 50000000)||(seqno<40000000))

    seqno=40000000;


  seqno++;


  esbLog2("new_trace_no[%d]",seqno);

  fprintf(fp,"%d",seqno);

  sprintf(szTmp,"%d",seqno);


  fclose(fp);


  ret = semop( semid, &op_v, 1 );

  if( ret < 0 )
{

   esbLogerr( "semop err! msg[%s]", strerror( errno));

   semctl( semid, 0, IPC_RMID, sem_arg );

   return( -1 );

  }

  return( 0 );


}


//左补零
int laddzero(char* ss,int len){
  int ilen=0;
  int i=0;
  ilen=strlen(ss);
  if(ilen>=len)   return 0;
  for(i=len-1;i>=0;i--){
    if(i<len-ilen)  ss[i]='0';
    else ss[i]=ss[i-len+ilen];
  }
  return 0;
}

/*从配置文件取参数*/
int GetParameter(char *File,char *Section,char *Keyword,char *Buffer,int Size)
{
    FILE *fp;
    char buf[400],tmpbuf[400];
    char Sec[400] ,Key[400];
    int SecFlag = 0;
    char *ptb , *psend ;
    int len ;

    if (!(fp = fopen(File , "r"))) {
        printf( "open file=[%s] error",File) ;
        return 1 ;
    }

    sprintf( Sec ,"[%s]",Section );
    sprintf( Key ,"%s",Keyword );

    while ( !feof( fp ) ) {
        memset( buf ,0x0 ,sizeof(buf ));
        fgets(buf,sizeof(buf),fp);
        if ( buf[ 0 ] == '#' )
            continue ;
        else if ( memcmp(buf ,Sec ,strlen(Sec)) == 0 ) {
            SecFlag = 1;
            continue;
        } else if (( buf[0] == '[' ) && SecFlag == 1 ) {
            break;
        } else
            if ( SecFlag == 1 ) {
                if (memcmp( buf  ,Key ,strlen(Key) ) == 0 ) {
                    memset( tmpbuf ,0x0 ,sizeof(tmpbuf));
                    memcpy( tmpbuf ,&buf[strlen(Key)] ,strlen(buf) - strlen(Key) );
                    len = strlen ( tmpbuf );
                    if ( tmpbuf[len-1] == '\n' )
                        tmpbuf[len-1 ] = 0x0 ;
                    len = strlen ( tmpbuf );

                    ptb = tmpbuf ;
                    while ( *ptb == ' ' || * ptb == '=' )
                        ptb ++ ;
                    if ( ptb - tmpbuf >= strlen(tmpbuf) )
                        break;

                    Size = len -( ptb - tmpbuf ) ;

                    memcpy( Buffer ,ptb ,Size );
                    SecFlag = 2;
                    break;
                }
                continue;
            }
    }

    fclose(fp);
    if (SecFlag == 1 || SecFlag == 0 )
        return 1 ;
    else
        return 0;
}


/****************************************************************
 *  功  能:  json报文去空格                                     *
 *  入参：   sPack -- json报文                                  *
 *                                                              *
 *  返回值:  int                                                *
 *           0  -- 成功                                         *
 *           非0  -- 失败                                       *
 *                                                              *
 ****************************************************************/
int hsm_trim_json(char *sPack)
{
    char *pTmp = sPack;

    while(*sPack != '\0')
    {
        if(!isspace(*sPack))
        {
            *pTmp++ = *sPack;
        }
        ++sPack;
    }

    *pTmp = '\0';

    return 0;
}