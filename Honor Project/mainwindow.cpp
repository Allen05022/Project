#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <QMessageBox>
using namespace std;

 vector<Patient>* list_of_people = new  vector<Patient>;

 string IllnessIntTostring(int value) {
     if (value == 0) return "blood";
     if (value == 1) return  "Cancer and Neoplasms";
     if (value == 2) return "Ear";
     if (value == 3) return "Eye";
     if (value == 4) return "Infection";
     if (value == 5) return "Skin";
     return  "";
 }

template<class InputIt, class T = typename iterator_traits<InputIt>::value_type>
T most_common(InputIt begin, InputIt end)
{
    map<T, int> counts;
    for (InputIt it = begin; it != end; ++it) {
        if (counts.find(*it) != counts.end()) {
            ++counts[*it];
        }
        else {
            counts[*it] = 1;
        }
    }
    return max_element(counts.begin(), counts.end(),
        [](const pair<T, int>& pair1, const pair<T, int>& pair2) {
            return pair1.second < pair2.second; })->first;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
      auto name = ui->lineEdit->text();
      auto family_name = ui->lineEdit_2->text();
      auto age = ui->spinBox->value();
      auto smocking =  ui->radioButton->isChecked();
      auto gender = ui->comboBox->currentText() == "Male";
      auto blood_problem = ui->checkBox_2->isChecked();
      auto infection_problem = ui->checkBox_5->isChecked();
      auto cancer_problem =  ui->checkBox_3->isChecked();
      auto ear_problem = ui->checkBox_4->isChecked();
      auto eye_problem = ui->checkBox_6->isChecked();
      auto skin_problem = ui->checkBox_7->isChecked();
      auto illness =   std::vector<IllnessCategory>();
      if (blood_problem){
          illness.push_back(blood);
      }
      if (infection_problem){
          illness.push_back(Infection);
      }
      if (cancer_problem){
          illness.push_back(cancer_and_neoplasms);
      }
      if (ear_problem){
           illness.push_back(Ear);
      }
      if (eye_problem){
            illness.push_back(Eye);
      }
      if (skin_problem){
            illness.push_back(Skin);
      }
      auto p = Patient(name.toStdString(), family_name.toStdString(),age, smocking,illness, gender? MALE : FEMALE );
      list_of_people->push_back(p);
      ui->label_7->setText("Gathered Information : "   + QString::fromStdString(to_string(list_of_people->size())));
      QMessageBox msgBox;
      msgBox.setText("Operation");
      msgBox.setInformativeText("Information added");
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.setDefaultButton(QMessageBox::Ok);
      msgBox.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    //elder illness
    auto all_illnesses = new vector<IllnessCategory>;
      for (size_t i = 0; i < list_of_people->size(); i++)
      {
          auto person = list_of_people->at(i);
          if (person.Age >= 40)
          {
              for (IllnessCategory illness : person.Illness)
              {
                  all_illnesses->push_back(illness);
              }
          }
      }
      auto result = IllnessIntTostring(most_common(all_illnesses->begin(), all_illnesses->end()));
      QMessageBox msgBox;
      msgBox.setText("Operation");
      msgBox.setInformativeText("Most common illness among elders (>= 40) is " +   QString::fromStdString (result));
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.setDefaultButton(QMessageBox::Ok);
      msgBox.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    // all ages
    auto all_illnesses = new vector<IllnessCategory>;
      for (size_t i = 0; i < list_of_people->size(); i++)
      {
          auto person = list_of_people->at(i);
              for (IllnessCategory illness : person.Illness)
              {
                  all_illnesses->push_back(illness);
              }
      }
      auto result = IllnessIntTostring(most_common(all_illnesses->begin(), all_illnesses->end()));
      QMessageBox msgBox;
      msgBox.setText("Operation");
      msgBox.setInformativeText("Most common illness among all students is " +   QString::fromStdString (result));
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.setDefaultButton(QMessageBox::Ok);
      msgBox.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
     int all_ages =0;
     int result = 0;
      for (size_t i = 0; i < list_of_people->size(); i++)
      {
          auto person = list_of_people->at(i);
           all_ages += person.Age;
      }
        if ( list_of_people->size() > 0) {

             result = all_ages/list_of_people->size();
        }
      QMessageBox msgBox;
      msgBox.setText("Operation");
      msgBox.setInformativeText("Age average of students is " +   QString::fromStdString ( to_string( result)));
      msgBox.setStandardButtons(QMessageBox::Ok);
      msgBox.setDefaultButton(QMessageBox::Ok);
      msgBox.exec();
}
