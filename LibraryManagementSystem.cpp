#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
    Library l;
    int choice;
    bool loop = true;
    cout << "Welcome to Library management System :) " << endl;

    while (loop) {

        l.menu();
        cin >> choice;

        switch (choice) {

            case 1:
            {
                l.newBook();
                break;
            }
            case 2:
            {
                l.bookBorrow();
                break;
            }
            case 3:
            {
                l.bookReturn();
                break;
            }
            case 4:
            {
                l.showBorrowStatics();
                break;
            }
            case 5:
            {
                l.libraryInventory();
                break;
            }
            case 6: 
            {
                l.searchAboutBook();
                break;
            }
            case 7:
            {
                loop = false;
                break;
            }
            default: 
            {
                cout << "Error Input :( " << endl;
                break;
            }
        
        }
        
    }

    return 0;
}
