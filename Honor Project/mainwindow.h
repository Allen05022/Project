#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


enum IllnessCategory
{
    blood,
    cancer_and_neoplasms,
    Ear,
    Eye,
    Infection,
    Skin
};


enum Gender
{
    MALE,
    FEMALE
};

class Patient
{
public:
    Patient(string name,string family_name, int age, bool smocking,
        vector<IllnessCategory> illness, Gender gender)
        : Name(std::move(name)),
        FamilyName(std::move(family_name)),
        Age(age),
        Smocking(smocking),
        Illness(std::move(illness)),
        Gender(gender)
    {
    }
        string Name;
public: string FamilyName;
public: int Age{};
public: bool Smocking{};
public: vector<IllnessCategory > Illness;
public:  Gender Gender;
public  : static string IllnessIntTostring(int value) {
        if (value == 0) return "blood";


}
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
