#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include "chargen_charactersheet.h"
#include "types.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
} // namespace Ui
QT_END_NAMESPACE

class MainWindowData;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void reqGenCharacterSignal();
    void reqCopyCharacterToClipboardSignal();
public slots:
    void onCharacterGenerated(Types::WeakPtr<CharGen::CharacterSheet>);
private slots:
    void on_generateCharacterButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::MainWindow *ui;
    QSharedDataPointer<MainWindowData> data;
};
#endif // MAINWINDOW_H
