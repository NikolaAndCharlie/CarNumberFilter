#include "qobject.h"
#include "qwidget.h"


class QLabel;
class QLineEdit;


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
private:
    void SetUi();
private slots:
    void ImportExcel();
    void OutPutExcel();
    void GenerateExcel();

};
