#pragma once 
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime> 
#include <chrono>
#include <iomanip>
#include "ArrayTable.h"
#include "DatValue.h"
#include "ScanTable.h"
#include "Table.h"
#include "SortTable.h"
#include "TabRecord.h"
#include "TreeTable.h"
#include "Marks.h"

class TableTestKit{
    private:
        Table& _table;
        int _eff;
    public:

        TableTestKit(Table& table): _table(table){}

        void InitRandom() {
            srand(static_cast<unsigned int>(time(NULL)));
        }

        std::vector<std::string> surnames = {
        "Ivanov", "Petrov", "Sidorov", "Smirnov", "Kuznetsov", "Popov", "Vasilyev", "Sokolov", "Mikhailov", "Fedorov",
        "Morozov", "Volkov", "Alekseev", "Lebedev", "Semenov", "Egorov", "Pavlov", "Kozlov", "Stepanov", "Nikolaev",
        "Orlov", "Andreev", "Makarov", "Nikitin", "Zhukov", "Solovyov", "Borisov", "Yakovlev", "Grigoryev", "Romanov",
        "Vorobyev", "Sergeev", "Karpov", "Gusev", "Titov", "Kiselev", "Maltsev", "Bykov", "Tikhonov", "Zaitsev",
        "Vinogradov", "Bogdanov", "Savelyev", "Mitin", "Chernov", "Kudryavtsev", "Baranov", "Danilov", "Kalinin", "Belov",
        "Komarov", "Krylov", "Korolev", "Efimov", "Sorokin", "Shubin", "Kabanov", "Markov", "Nikiforov", "Ignatov",
        "Maslov", "Konovalov", "Filatov", "Samoylov", "Gerasimov", "Frolov", "Ulyanov", "Drozdov", "Kulikov", "Belyaev",
        "Ponomarev", "Antipov", "Zverev", "Denisov", "Rodionov", "Anisimov", "Klimov", "Avdeev", "Gromov", "Korneev",
        "Babenko", "Loginov", "Kuzmin", "Fadeev", "Prokofiev", "Znamensky", "Belkin", "Polyakov", "Reshetnikov", "Panin",
        "Shcherbakov", "Bobrov", "Zolotov", "Timofeev", "Chistyakov", "Yashin", "Babkin", "Zadorozhny", "Troitsky", "Suvorov"
    };

    std::vector<std::string> names = {
        "Aleksandr", "Dmitry", "Maxim", "Sergey", "Andrey", "Alexey", "Ivan", "Nikolay", "Yuri", "Viktor",
        "Vladimir", "Artem", "Pavel", "Oleg", "Egor", "Vyacheslav", "Ilya", "Roman", "Kirill", "Stepan",
        "Anatoly", "Timur", "Denis", "Grigory", "Fedor", "Vasiliy", "Gennady", "Stanislav", "Konstantin", "Valery",
        "Boris", "Leonid", "Mikhail", "Arkady", "Valentin", "German", "Yaroslav", "Nazar", "Bogdan", "Savely",
        "Ruslan", "Semyon", "Artur", "Eduard", "Albert", "Ostap", "Anton", "Ignat", "Yan", "Mark",
        "Aleksey", "Vitaly", "Vsevolod", "Rodion", "Miron", "David", "Gleb", "Tikhon", "Lev", "Nikita",
        "Platon", "Andrian", "Arseny", "Demid", "Yakov", "Matvey", "Taras", "Timofey", "Stepan", "Vladislav",
        "Danila", "Zahar", "Frol", "German", "Arkhip", "Danil", "Saveliy", "Filipp", "Artyom", "Vadim",
        "Yevgeny", "Ignatiy", "Kir", "Lavr", "Makar", "Orest", "Rodion", "Severin", "Trofim", "Ustin",
        "Yulian", "Avgust", "Borislav", "Gavriil", "Innokentiy", "Klim", "Nazar", "Prokhor", "Rostislav", "Svyatoslav"
    };

    std::vector<std::string> patronymics = {
        "Aleksandrovich", "Dmitrievich", "Maximovich", "Sergeevich", "Andreevich", "Alexeevich", "Ivanovich", "Nikolaevich", "Yurievich", "Viktorovich",
        "Vladimirovich", "Artemovich", "Pavlovich", "Olegovich", "Egorovich", "Vyacheslavovich", "Ilyich", "Romanovich", "Kirillovich", "Stepanovich",
        "Anatolievich", "Timurovich", "Denisovich", "Grigoryevich", "Fedorovich", "Vasilevich", "Gennadievich", "Stanislavovich", "Konstantinovich", "Valerievich",
        "Borisovich", "Leonidovich", "Mikhailovich", "Arkadievich", "Valentinovich", "Germanovich", "Yaroslavovich", "Nazarovich", "Bogdanovich", "Savelievich",
        "Ruslanovich", "Semenovich", "Arturovich", "Eduardovich", "Albertovich", "Ostapovich", "Antonovich", "Ignatovich", "Yanovich", "Markovich",
        "Alekseevich", "Vitalievich", "Vsevolodovich", "Rodionovich", "Mironovich", "Davidovich", "Glebovich", "Tikhonovich", "Lvovich", "Nikitich",
        "Platonovich", "Andrianovich", "Arsenievich", "Demidovich", "Yakovlevich", "Matveevich", "Tarasovich", "Timofeevich", "Stepanovich", "Vladislavovich",
        "Danilovich", "Zaharovich", "Frolovich", "Germanovich", "Arkhipovich", "Danilovich", "Savelievich", "Filippovich", "Artyomovich", "Vadimovich",
        "Evgenievich", "Ignatievich", "Kirovich", "Lavrovich", "Makarovich", "Orestovich", "Rodionovich", "Severinovich", "Trofimovich", "Ustinovich",
        "Yulianovich", "Avgustovich", "Borislavovich", "Gavriilovich", "Innokentievich", "Klimovich", "Nazarovich", "Prokhorovich", "Rostislavovich", "Svyatoslavovich"
    };

        std::string GenerateRandomSurname() { 
            return surnames[rand() % surnames.size()];      
        }

        std::string GenerateRandomName() {
            return names[rand() % names.size()];      
        }

        std::string GenerateRandomPatronymic() { 
            return patronymics[rand() % patronymics.size()];      
        }

        uint8_t GenerateRandomGrade() {
            return 2 + rand() % 4;  
        }

        void GenerateData(size_t numRecords){
            for (size_t i = 0; i < numRecords; i++) {
                start:
                Key key = GenerateRandomSurname() + " " + GenerateRandomName() + " " + GenerateRandomPatronymic();
                PDataValue value = _table.FindRecord(key);
                if(value!=nullptr){
                    goto start;
                }

                uint8_t math = GenerateRandomGrade();
                uint8_t chem = GenerateRandomGrade();
                uint8_t zvo = GenerateRandomGrade();
                uint8_t difeq = GenerateRandomGrade();
                uint8_t ads = GenerateRandomGrade();
            
                PDataValue data = new Marks(math, chem, zvo, difeq, ads);
            
                _table.InsRecord(key, data);
            }
        }

        void PrintTable() {
            size_t wideFlag = 40;
            size_t flag = 10; 
        
            std::cout << "+";
            for (int i = 0; i < wideFlag; i++) std::cout << "-";
            for (int col = 0; col < 5; col++) {
                std::cout << "+";
                for (int i = 0; i < flag; i++) std::cout << "-";
            }
            std::cout << "+" << std::endl;
    
            std::cout << "|" << std::setw(wideFlag) << std::left << "Full name"
                      << "|" << std::setw(flag) << std::left << "Math"
                      << "|" << std::setw(flag) << std::left << "Chem"
                      << "|" << std::setw(flag) << std::left << "Zvo"
                      << "|" << std::setw(flag) << std::left << "Difeq"
                      << "|" << std::setw(flag) << std::left << "Ads"
                      << "|" << std::endl;
        
            std::cout << "+";
            for (int i = 0; i < wideFlag; i++) std::cout << "-";
            for (int col = 0; col < 5; col++) {
                std::cout << "+";
                for (int i = 0; i < flag; i++) std::cout << "-";
            }
            std::cout << "+" << std::endl;
        
            _table.Reset(); 
            while (!_table.IsTabEnded()) {
                std::string key = _table.GetKey();  
                PDataValue value = _table.GetValue();  
                if (value != nullptr) {
                    std::cout << "|" << std::setw(wideFlag) << std::left << key 
                            << *value;
                }

                _table.GoNext(); 
            }

            std::cout << "+";
            for (int i = 0; i < wideFlag; i++) std::cout << "-";
            for (int col = 0; col < 5; col++) {
                std::cout << "+";
                for (int i = 0; i < flag; i++) std::cout << "-";
            }
            std::cout << "+" << std::endl;
        }
        
        void FillTable(size_t numRecords){ 
                GenerateData(numRecords);
        }
        
        void RemoveRecord(){
            int k = 0;
            for (size_t i = 0; i < 100; ++i) {
                std::string key = GenerateRandomSurname() + " " + GenerateRandomName() + " " + GenerateRandomPatronymic(); 
                PDataValue value = _table.FindRecord(key);
                k += _table.GetEfficiency();
                if (value != nullptr) {
                    _table.DelRecotd(key);  
                    std::cout << "Record with key " << key << " removed successfully." << std::endl;
                } else {
                    std::cout << "Record with key " << key << " not found." << std::endl;
                }
            }
            _eff = k/100;
        }
        
        
        void FindRecord(){
            int k = 0;
            for (size_t i = 0; i < 100; ++i) {
        
                std::string key = GenerateRandomSurname() + " " + GenerateRandomName() + " " + GenerateRandomPatronymic(); 
                
                PDataValue value = _table.FindRecord(key);
                k += _table.GetEfficiency();
                if (value != nullptr) {
                    Marks* marks = dynamic_cast<Marks*>(value);  
                    std::cout << "Found record with surname " << key << ":\n"
                              << "Math: " << static_cast<int>(marks->GetMath()) << ", "
                              << "Chem: " << static_cast<int>(marks->GetChem()) << ", "
                              << "Zvo: " << static_cast<int>(marks->GetZvo()) << ", "
                              << "Difeq: " << static_cast<int>(marks->GetDifeq()) << ", "
                              << "Ads: " << static_cast<int>(marks->GetAds()) << "\n";
                } else {
                    std::cout << "Record with surname " << key << " not found.\n";
                }
            }
            _eff = k/100;
        }
        
        void PrintMetrics() {
        
            auto start = std::chrono::high_resolution_clock::now();
            FindRecord();
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> findTime = (end - start)/100;
        
            std::cout << "FindRecord: " << findTime.count() << " sec, " << "records checked: " << _eff << std::endl;
        
            start = std::chrono::high_resolution_clock::now();
            RemoveRecord();
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> delTime = (end - start)/100;
        
            std::cout << "DelRecord: " << delTime.count() << " sec, " << "records checked: " << _eff << std::endl;
        }
        
};