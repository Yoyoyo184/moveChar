#include <ncurses.h>

int main(){
    initscr();
    curs_set(false);
    noecho();


    int height = 20;
    int width = 10;
    int starty = 0;
    int startx = 0;

    //getmaxyx(stdscr, height, width);
    WINDOW *win = newwin(height, width, starty, startx);
    keypad(win, TRUE);

    int delay = 100; //milliseconds
   // timeout(delay);

    //put the char in the middle of the window
    int y = height /2;
    int x = width /2;

    box(win, 0, 0);
    mvwprintw(win, y, x, "X");

    wrefresh(win);

    int ch;

    int maxy, maxx;
    getmaxyx(win, maxy, maxx);

    do{
        mvwprintw(win, y, x, " ");

        switch(ch){
            case KEY_UP:
                if(y > 1)
                    y--;
                break;
            case KEY_DOWN:
                if(y < maxy-2)
                    y++;
                break;
            case KEY_LEFT:
                if(x>1)
                    x--;
                break;
            case KEY_RIGHT:
                if(x<maxx-2)
                    x++;
                break;
            default:
                break;
        }
        mvwprintw(win, y, x, "X");

        wrefresh(win);

    }while((ch = wgetch(win)) != 'q');

    delwin(win);
    endwin();

    return 0;
}