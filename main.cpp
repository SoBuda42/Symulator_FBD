#include <QApplication>
#include "Okno_glowne.h"

int main(int argc, char *argv[])
{
    // Odpalamy system operacyjny okienek
    QApplication aplikacja(argc, argv);
    
    // Tworzymy nasze zespawane okno
    Okno_glowne okno;
    
    // Wysuwamy okno na wierzch
    okno.show();
    
    // Nieskończona pętla nasłuchująca (zasilanie)
    return aplikacja.exec();
}