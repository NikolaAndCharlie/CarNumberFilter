#include "qaxobject.h"
#include "qobject.h"



class NumberGenerator : public QObject
{
    Q_OBJECT
public:
    NumberGenerator();
    ~NumberGenerator();

    static NumberGenerator* Instane();
    void Destory();

private:
    static NumberGenerator* m_instance;
    QVector<QString> GenerateNumber();
    void OpenFile();
    void WriteDataInFile(const QVector<QString>&);
    void CloseFile();
public slots:
    void GenrateNumberExcel();
private:
    QAxObject* m_excel;
    QAxObject* m_workbook;
    QAxObject* m_sheet;
};