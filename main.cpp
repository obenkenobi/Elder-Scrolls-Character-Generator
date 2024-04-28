#include "services_charactersvc.h"
#include "widgets_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Declare services
    const Services::EsCharacterSvc characterSvc;

    // Declare window
    MainWindow w;

    // Link signals with slots
    QObject::connect(&w,
                     &MainWindow::reqGenCharacterSignal,
                     &characterSvc,
                     &Services::EsCharacterSvc::onReqGenCharacter);

    QObject::connect(&w,
                     &MainWindow::reqCopyCharacterToClipboardSignal,
                     &characterSvc,
                     &Services::EsCharacterSvc::onRequestCopyCharacterToClipboard);

    QObject::connect(&characterSvc,
                     &Services::EsCharacterSvc::characterGeneratedSignal,
                     &w,
                     &MainWindow::onCharacterGenerated);

    // Start application
    w.show();
    return a.exec();
}
