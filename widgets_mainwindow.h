#ifndef WIDGETS_MAINWINDOW_H
#define WIDGETS_MAINWINDOW_H

#include <QMainWindow>
#include "domain_escharsheet.h"
#include "types.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
} // namespace Ui
QT_END_NAMESPACE

class MainWindowData;

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

signals:
    void reqGenCharacterSignal();
    void reqCopyCharacterToClipboardSignal();
public slots:
    void onCharacterGenerated(Types::WeakPtr<Domain::EsCharSheet>);
private slots:
    void on_generateCharacterButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::MainWindow *ui_;
    QSharedDataPointer<MainWindowData> data_;
};
#endif // WIDGETS_MAINWINDOW_H
