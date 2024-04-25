#include "services_charactersvc.h"
#include "widgets_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Declare services
    Services::ESCharacterSvc characterSvc;

    // Declare window
    MainWindow w;

    // Link signals with slots
    QObject::connect(&w,
                     &MainWindow::reqGenCharacterSignal,
                     &characterSvc,
                     &Services::ESCharacterSvc::onReqGenCharacter);

    QObject::connect(&w,
                     &MainWindow::reqCopyCharacterToClipboardSignal,
                     &characterSvc,
                     &Services::ESCharacterSvc::onRequestCopyCharacterToClipboard);

    QObject::connect(&characterSvc,
                     &Services::ESCharacterSvc::characterGeneratedSignal,
                     &w,
                     &MainWindow::onCharacterGenerated);

    // Start application
    w.show();
    return a.exec();
}
