 #include <ncurses.h>
         #include <stdio.h>
         #include <stdlib.h>
         #include <string.h>
         #include <time.h>
         #define MAX_INPUT_LEN 80000
         int main() {
           initscr();
           int rows = 10;
          int cols = 20;
         int start_row = 0;
         int start_col = 0;
        start_color();
         init_pair(1, COLOR_RED, COLOR_BLACK); // for red text on black background
         init_pair(2, COLOR_YELLOW, COLOR_BLACK); // for green text on black background

         init_pair(3, COLOR_GREEN, COLOR_BLACK); // for green text on black background
         // define more color pairs if needed
         WINDOW *win = newwin(rows, cols, start_row, start_col);
      box(win,2,2); // create border around the main window
         attron(COLOR_PAIR(3));											
         printw("*****************************************************************************************************************\n");
	 printw("* Welcome to the DragonScribe terminal log application            --<type help to access the menu>--            *\n");
	 printw("* You must enable write permisions for this program to work - Visit: https://github.com/Kevin4Markey/Alien/wiki *\n");
         printw("*****************************************************************************************************************\n");   
  	 printw("\n");																	
	 attroff(COLOR_PAIR(3));
           printw("\n");
           printw("\n");
           printw("\n");
           
          //  printw("\n");
           attron(COLOR_PAIR(2));
           printw(" 	   MM           MM                                       SSSSSSSSSS                             \n");
           printw("	   MM MM     MM MM                                       SS      SS                             \n");
           printw("	   MM   MM MM   MM                                       SS                                     \n");
           printw("	   MM     M     MM                                       SSSSSSSSSS                     TM      \n");
           printw("	   MM           MM   AAAA   RR    KK  KK  EEEEE  Y   YY  SSSSSSSSSS  OOOOOO  FFFFF   TT         \n");
           printw("	   MM           MM  AA  A   RRRR  KK  K   E   E   Y YY           SS  OO   O  FF    TTTTTT       \n");
           printw("	   MM           MM  AA  A   RR    KK K    EEEE     YY    SS      SS  OO   O  FFFF    TT         \n");
           printw("	   MM           MM  AAAAAA  RR    KK  KK  EEEEEE  YY     SSSSSSSSSS  OOOOOO  FF      TTT        \n");
         attroff(COLOR_PAIR(2));
 		printw("\n");	  
        	printw("\n");	
		printw("\n"); 
         attron(COLOR_PAIR(3));
 //        printw("--markeysoft.com--\n");
         printw("*****************************************************************************************************************\n");
           printw("\n");

	 attroff(COLOR_PAIR(3));
         getch();
         char input[MAX_INPUT_LEN];
         int y = 11;
         // Create a new window for the help menu
         int help_rows = 8;
         int help_cols = 70;
         int help_start_row = (LINES - help_rows) / 4;
         int help_start_col = (COLS - help_cols) / 4;
         WINDOW *help_win = newwin(help_rows, help_cols, help_start_row, help_start_col);
         box(help_win, 0, 1);
         wattron(help_win, COLOR_PAIR(2));
         mvwprintw(help_win, 1, 2, "Help Menu:");
         mvwprintw(help_win, 2, 2, "--Type quit to close the terminal--");
         mvwprintw(help_win, 3, 2, "--Type display to show current log contents--");
         mvwprintw(help_win, 4, 2, "--All entry logs will be saved to the input.txt file");
         mvwprintw(help_win, 5, 2, "  created by this software--");
         wattroff(help_win, COLOR_PAIR(2));
             // Create a new window for displaying the file contents
     int file_rows = LINES - 10;
     int file_cols = COLS - 20;
     int file_start_row = 10;
     int file_start_col = 20;
     WINDOW *file_win = newwin(file_rows, file_cols, file_start_row, file_start_col);
    scrollok(file_win, true);
        // Create a new window for displaying the output
        int output_rows = LINES - 10;
        int output_cols = COLS - 20;
        int output_start_row = 10;
        int output_start_col = 20;
        WINDOW *output_win = newwin(output_rows, output_cols, output_start_row, output_start_col);
        scrollok(output_win, true);
      // printw("Welcome to the Terminal! --type help to access the menu--\n");  
   
   
      time_t current_time;
       struct tm *time_info;
   
   
     while (true) {
       time(&current_time);
      time_info = localtime(&current_time);
       attron(COLOR_PAIR(3));
       //mvprintw(1, 0, "[%02d:%02d:%02d] Log entry input: ", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
  
   
  
   
  
  
   
  
   
   
  
   
   
  
  
        time_t current_time;
   struct tm *time_info;
   char time_string[9]; // buffer to hold formatted time string
  
   time(&current_time); // get the current time
   time_info = localtime(&current_time); // convert to local time
  
   strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info); // format time as "HH:MM:SS"
  
   printw("Current time is %s", time_string); // display the formatted time
  
  
  
  
  
  
  
  
  
      attroff(COLOR_PAIR(3));
      //strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", localtime(&current_time));
      attron(COLOR_PAIR(3));
      mvprintw(5, 0, "[%02d:%02d:%02d] Log entry input:  ", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
      attroff(COLOR_PAIR(3));
     refresh();
  
       // time_t current_time;
     // char timestamp[20];
     // current_time = time(NULL);
     // strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", localtime(&current_time));
    // mvprintw(1, 0, "\n\nLog entry input %s: ", timestamp);
  
  
   getstr(input);
     wattron(help_win, COLOR_PAIR(3));
     if (strcmp(input, "display") == 0) {
     wattroff(help_win, COLOR_PAIR(3));
     // clear the file window
     werase(file_win);
    // print the log entries to the file window
  
    FILE *f = fopen("input.txt", "r");
     if (f != NULL) {
       char line[MAX_INPUT_LEN];
       while (fgets(line, sizeof(line), f)) {
         wprintw(file_win, "%s",line);
       // strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", localtime(&current_time));
      }
  
       fclose(f);
     } else {
       wprintw(file_win, "Error: Failed to open file.");
     }
  
  
    // refresh the file window
     wrefresh(file_win);
     // wait for user input before clearing the file window
      attron(COLOR_PAIR(3));
      mvprintw(LINES-1, 0, "Press any key to clear the display...");
      attroff(COLOR_PAIR(3));
     refresh();
     getch();
     werase(file_win);
     wrefresh(file_win);
   }
   if (strcmp(input, "quit") == 0) {
     break; // exit the loop
   }
     //
           FILE *fptr;
              char c;
  
    // Open the file in read mode
    attron(COLOR_PAIR(3));
              fptr = fopen("input.txt", "r");
    attroff(COLOR_PAIR(3));
            // If unable to open the file, print an error message and exit
             if (fptr == NULL) {
                 printf("Error opening the file.");
                 return 1;
             }
             // Read and print the contents of the file
             while ((c = fgetc(fptr)) != EOF) {
                attron(COLOR_PAIR(3));
  
  
  
  
  
                  printf("%c",c);
               attroff(COLOR_PAIR(3));
             }
  
             // Close the file
             fclose(fptr);
     move(4,0);
      clear(); // clear input field
      refresh();
      //  mvprintw(1, 0, "\n\nEnter your input (type quit to close the terminal): ");
      if (strcmp(input, "quit") == 0) {
        break;
     } else if (strcmp(input, "help") == 0) {
      // Display the help menu
        wclear(help_win);
       box(help_win, 0, 0);
       wattron(help_win, COLOR_PAIR(1));
       mvwprintw(help_win, 1, 2, "                           Help Menu:");
        mvwprintw(help_win, 2, 2,"");
        mvwprintw(help_win, 3, 2, "--Type quit to close the terminal--");
        mvwprintw(help_win, 4, 2, "--Type display to show current log contents--");
        mvwprintw(help_win, 5, 2, "--All entry logs will be saved to the input.txt file");
      mvwprintw(help_win, 6, 2, "  created by this software--");
      wrefresh(help_win);
        wattroff(help_win, COLOR_PAIR(1));
      } else {
  
       // Write the input to a file
        FILE *fp = fopen("input.txt", "a");
  
  
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        char buffer[80];
        strftime(buffer, 80, "%Y-%m-%d", t);
        // printf("Today's date is %s\n", buffer);
  
  
        fprintf(fp, "/*[%02d:%0d:%02d]--%s*/ %s\n",time_info->tm_hour, time_info->tm_min, time_info->tm_sec ,buffer ,input);
  
  
  
  
  
  
  
  
  
       fclose(fp);
  
           wattron(help_win, COLOR_PAIR(3));
          mvwprintw(output_win, y, 0, "[%02d:%0d:%02d] Generated output:  %s",time_info->tm_hour, time_info->tm_min, time_info->tm_sec ,input);
         wattron(help_win, COLOR_PAIR(3));
        y += 0;
        wrefresh(output_win);
      }
      refresh();
     getch();
           attron(COLOR_PAIR(3));
    

           printw("*****************************************************************************************************************\n");
           printw("* Welcome to the DragonScribe terminal log application            --<type help to access the menu>--            *\n");
           printw("* You must enable write permisions for this program to work - Visit: https://github.com/Kevin4Markey/Alien/wiki *\n");
           printw("*****************************************************************************************************************\n");
           printw("\n");
 


           

           attroff(COLOR_PAIR(3));
          printw("\n");
         printw("\n");
          printw("\n");
          printw("\n");
          printw("\n");
    attron(COLOR_PAIR(1));
          printw("\n");
	  printw("\n");



         
    








	  printw(" DDDDDD                                       SSSSSSSS                             \n");
          printw(" DD   DD                                      SS    SS                             \n");
          printw(" DD   DD                                      SS                      II               \n");
          printw(" DD   DD  RR                                  SSSSSSSS         RR         BB          TM      \n");
          printw(" DD   DD  RRRRR  AAAA   GGGGG  OOOOO  NN   N        SS  CCCCC  RRRRR  II  BB    EEEEE      \n");
          printw(" DD   DD  RRR   AA  A   GG GG  OO  O  NNN  N        SS  CC     RRR    II  BBBB  EE EE    \n");
          printw(" DD   DD  RR    AA  A       G  OO  O  NN N N  SS    SS  CC     RR     II  B  B  EE       \n");
          printw(" DDDDDD   RR     AAAAA  GGGGG  OOOOO  NN  NN  SSSSSSSS  CCCCC  RR     II  BBBB  EEEEE       \n");
    attroff(COLOR_PAIR(1));
          printw("\n");
           attron(COLOR_PAIR(3));
	printw("\n");        
        printw("*****************************************************************************************************************\n");
           printw("\n");
				
 printw("[markeysoft.com] ");
           attroff(COLOR_PAIR(3));
    }
  
      endwin();
      return 0;
   }
  												
