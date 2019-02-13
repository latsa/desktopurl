// followdesktopurl.cpp : Defines the entry point for the console application.
//

#include <SDKDDKVer.h>

#include "stdio.h"
#include "string.h"
#include "Objbase.h"
#include "shellapi.h"

void main(int argc, char* argv[]) {
   FILE *infile;
   char line[1024];

   if (argc != 2)
      exit(1);

   CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

   infile = fopen(argv[1], "r");
   if (infile) {
      while (fgets(line, 1024, infile)) {
         if (!_strnicmp("URL=", line, 4)) {
            ShellExecuteA(0, 0, line + 4, 0, 0, SW_SHOWNORMAL);
            break;
         }
      }
      fclose(infile);
   }

   exit(0);
}

