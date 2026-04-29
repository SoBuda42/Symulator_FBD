#include "Okno_glowne.h"
#include <QWidget>       // Narzędzie do tworzenia płaskich powierzchni (blatów)
#include <QVBoxLayout>   // Niewidzialna miarka pionowa do układania elementów
#include <QPushButton>   // Narzędzie do tworzenia przycisków
#include <QTextEdit>     // Narzędzie do tworzenia ekranu tekstowego     
#include <QLabel>
#include <QLineEdit>

Okno_glowne::Okno_glowne(QWidget *parent) : QMainWindow(parent) 
{
    // 1. Tworzymy nowy, pusty blat roboczy. Słówko 'this' oznacza, 
    // że ten blat należy do naszego Głównego Okna.
    QWidget *blat_roboczy = new QWidget(this);

    // 2. Mówimy okienku: "Użyj tego blatu jako swojego centrum".
    setCentralWidget(blat_roboczy);

    // 3. Tworzymy pionowy układ (niewidzialną rurę) i kładziemy go na blacie
    QVBoxLayout *uklad_pionowy = new QVBoxLayout(blat_roboczy);

    pole_plik_wejsciowy = new QLineEdit("wejscie.txt", this);
    uklad_pionowy->addWidget(new QLabel("Plik z danymi (Odczyt): "));
    uklad_pionowy->addWidget(pole_plik_wejsciowy);


    pole_plik_wyjsciowy = new QLineEdit("wyjscie.txt", this);
    uklad_pionowy->addWidget(new QLabel("Plik na wyniki (Zapis):"));
    uklad_pionowy->addWidget(pole_plik_wyjsciowy);

    pole_amp_gen = new QDoubleSpinBox(this);
    pole_amp_gen->setRange(0.1, 1000);
    pole_amp_gen->setValue(5);
    uklad_pionowy->addWidget(new QLabel("Wartosc poczatkowa amplitudy:"));
    uklad_pionowy->addWidget(pole_amp_gen);

    pole_okres_gen = new QSpinBox(this);
    pole_okres_gen->setRange(1, 1000);
    pole_okres_gen->setValue(20);
    uklad_pionowy->addWidget(new QLabel("Wartosc poczatkowa okresu:"));
    uklad_pionowy->addWidget(pole_okres_gen);

    pole_wartosci_stalej = new QDoubleSpinBox(this);
    pole_wartosci_stalej->setRange(-1000, 1000);
    pole_wartosci_stalej->setValue(1);
    uklad_pionowy->addWidget(new QLabel("Wartosc poczatkowa stalej:"));
    uklad_pionowy->addWidget(pole_wartosci_stalej);

    pole_znaki_addsub = new QLineEdit("-+++", this);
    pole_znaki_addsub->setMaxLength(4);
    uklad_pionowy->addWidget(new QLabel("Kolejnosc znakow AddSub:"));
    uklad_pionowy->addWidget(pole_znaki_addsub);

    pole_wzmocnienie = new QDoubleSpinBox(this);
    pole_wzmocnienie->setRange(-1000, 1000);
    pole_wzmocnienie->setValue(0.1);
    uklad_pionowy->addWidget(new QLabel("Wartosc poczatkowa wzmocnienia:"));
    uklad_pionowy->addWidget(pole_wzmocnienie);

    przycisk_buduj = new QPushButton("1. PRZYGOTUJ FABRYKE", this);
    uklad_pionowy->addWidget(przycisk_buduj);

    // 4. Tworzymy fizyczne elementy (Widgety). 
    // Przekazujemy 'this' (Główne Okno) jako Właściciela, żeby dbał o pamięć!
    przycisk_start = new QPushButton("URUCHOM FABRYKE", this);
    przycisk_pauza = new QPushButton("ZATRZYMAJ TASME", this);
    konsola_logow = new QTextEdit(this);
    
    // Blokujemy ekran tekstowy, żeby operator z zewnątrz nie mógł tam pisać na klawiaturze
    konsola_logow->setReadOnly(true); 

    // 5. Mamy luźne przyciski i pusty układ pionowy. Czas wrzucić maszyny do rury!
    uklad_pionowy->addWidget(przycisk_start);
    uklad_pionowy->addWidget(przycisk_pauza);
    uklad_pionowy->addWidget(konsola_logow);

    // 6. Kosmetyka końcowa maszyny (wymiary i tytuł)
    setWindowTitle("Panel Sterowania - Zadanie 4");
    resize(400, 500); // 400px szerokości, 500px wysokości

    // Wytapiamy główny silnik!
    menadzer_symulacji = new Aplikacja_symulatora();

    // --- LUTOWANIE KABLI (Sygnał -> Slot) ---
    // connect(NADAJNIK, SYGNAŁ, ODBIORNIK, SLOT/FUNKCJA);
    connect(przycisk_start, &QPushButton::clicked, this, &Okno_glowne::kliknieto_start);
    connect(przycisk_pauza, &QPushButton::clicked, this, &Okno_glowne::kliknieto_pauza);
    connect(przycisk_buduj, &QPushButton::clicked, this, &Okno_glowne::kliknieto_buduj);

    connect(menadzer_symulacji, &Aplikacja_symulatora::przeslij_na_ekran, konsola_logow, &QTextEdit::append);
}

Okno_glowne::~Okno_glowne() {}

void Okno_glowne::kliknieto_start() 
{
    konsola_logow->append(">> Inicjalizacja fabryki... Tasiemka ruszyla!");
    menadzer_symulacji->uruchom();
}

void Okno_glowne::kliknieto_pauza() 
{
    konsola_logow->append(">> UWAGA: Zatrzymanie awaryjne. Wstrzymano symulacje.");
    menadzer_symulacji->zatrzymaj();
}

void Okno_glowne::kliknieto_buduj()
{
    QString wej = pole_plik_wejsciowy->text();
    QString wyj = pole_plik_wyjsciowy->text();
    double amp = pole_amp_gen->value();
    int okres = pole_okres_gen->value();
    double stala = pole_wartosci_stalej->value();
    QString znaki_addsub = pole_znaki_addsub->text();
    if(znaki_addsub.size() != 4)
    {
        konsola_logow->append(">> BLAD KRYTYCZNY: Pole AddSub musi miec DOKLADNIE 4 znaki (np. -+++)!");
        return;
    }
    double wzmocnienie = pole_wzmocnienie->value();

    konsola_logow->append(">> Rozpoczynam budowe. Plik odczytu: " + wej + ", Plik zapisu: " + wyj +
         ", Amplituda: " + QString::number(amp) + ", Okres: " + QString::number(okres) +
         ", Stala: " + QString::number(stala) + "Znaki addsub: " + znaki_addsub + ", Wzmocnienie: " + QString::number(wzmocnienie));
    
    menadzer_symulacji->wartosci_poczatkowe_fabryki(wej, wyj, amp, okres, stala, znaki_addsub, wzmocnienie);
}