#include "mainwindow.h"
#include "services_charactersvc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Declare services
    Services::CharacterSvc characterSvc;

    // Declare window
    MainWindow w;

    // Link signals with slots
    QObject::connect(&w,
                     &MainWindow::reqGenCharacterSignal,
                     &characterSvc,
                     &Services::CharacterSvc::onReqGenCharacter);

    QObject::connect(&w,
                     &MainWindow::reqCopyCharacterToClipboardSignal,
                     &characterSvc,
                     &Services::CharacterSvc::onRequestCopyCharacterToClipboard);

    QObject::connect(&characterSvc,
                     &Services::CharacterSvc::characterGeneratedSignal,
                     &w,
                     &MainWindow::onCharacterGenerated);

    // Start application
    w.show();
    return a.exec();
}
