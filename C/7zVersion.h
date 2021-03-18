#define MY_VER_MAJOR 19
#define MY_VER_MINOR 00
#define MY_VER_BUILD 0
#define MY_VERSION_NUMBERS "19.00 ZS v1.4.9 R1"
#define MY_VERSION MY_VERSION_NUMBERS

//#ifdef MY_X64
//  #define MY_7ZIP_NAME "7-Zip [64-bit]"
//#else
//  #define MY_7ZIP_NAME "7-Zip [32-bit]"
//#endif

#define MY_7ZIP_NAME "7-Zip"

#ifdef MY_CPU_NAME
  #define MY_VERSION_CPU MY_VERSION " (" MY_CPU_NAME ")"
#else
  #define MY_VERSION_CPU MY_VERSION
#endif

#define MY_DATE "2021-03-17"
#undef MY_COPYRIGHT
#undef MY_VERSION_COPYRIGHT_DATE
#define MY_AUTHOR_NAME "Igor Pavlov, Tino Reichardt"
#define MY_COPYRIGHT_PD "Igor Pavlov : Public domain"
#define MY_COPYRIGHT_CR "Copyright (c) 1999-2019 Igor Pavlov, 2016-2021 Tino Reichardt"

#ifdef USE_COPYRIGHT_CR
  #define MY_COPYRIGHT MY_COPYRIGHT_CR
#else
  #define MY_COPYRIGHT MY_COPYRIGHT_PD
#endif

#define MY_COPYRIGHT_DATE MY_COPYRIGHT " : " MY_DATE
#define MY_VERSION_COPYRIGHT_DATE MY_VERSION_CPU " : " MY_COPYRIGHT " : " MY_DATE

#define MY_EASY7ZIP_VER_MAJOR 0
#define MY_EASY7ZIP_VER_MINOR 1

//#ifdef MY_X64
//  #define MY_EASY7ZIP_7ZIP "Easy 7-Zip [64-bit]"
//#else
//  #define MY_EASY7ZIP_7ZIP "Easy 7-Zip [32-bit]"
//#endif

#define MY_EASY7ZIP_7ZIP "Easy 7-Zip"

#define MY_EASY7ZIP_VERSION "0.1.6_1.4.9-Zstd"

//#ifdef MY_X64
//  #define MY_EASY7ZIP_7ZIP_VERSION "Easy 7-Zip v0.1.6 [64-bit]"
//#else
//  #define MY_EASY7ZIP_7ZIP_VERSION "Easy 7-Zip v0.1.6 [32-bit]"
//#endif
#define MY_EASY7ZIP_COPYRIGHT "Portions Copyright (C) 2013-2016 James Hoo, 2021 treysis"

#define MY_EASY7ZIP_AUTHOR "James Hoo"
#define MY_EASY7ZIP_HOMEPAGE "e7z.org"
#define MY_EASY7ZIP_SPECIAL_BUILD MY_EASY7ZIP_7ZIP_VERSION " (www." MY_EASY7ZIP_HOMEPAGE ") made by " MY_EASY7ZIP_AUTHOR
