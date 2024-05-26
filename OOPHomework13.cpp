#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Directory {
private:
    string companyName;
    string owner;
    string phone;
    string address;
    string typeOfActivity;
    vector<std::string> records;

public:
    Directory() 
    {
        loadFromFile("directory.txt");
    }
    void setCompanyName(const string& name) 
    {
        companyName = name;
    }
    void setOwner(const string& owner_name) 
    {
        owner = owner_name;
    }
    void setPhone(const string& number) 
    {
        phone = number;
    }
    void setAddress(const string& addr)
    {
        address = addr;
    }
    void setTypeOfActivity(const string& type)
    {
        typeOfActivity = type;
    }
    void addRecord()
    {
        string record = companyName + ";" + owner + ";" + phone + ";" + address + ";" + typeOfActivity + "\n";
        records.push_back(record);
        saveToFile("directory.txt");
    }
    void searchByName(const string& name)
    {
        for (const auto& record : records) {
            if (record.find(name) != string::npos) {
                cout << record;
            }
        }
    }
    void searchByOwner(const string& owner_name)
    {
        for (const auto& record : records) 
        {
            if (record.find(owner_name) != string::npos)
            {
                cout << record;
            }
        }
    }
    void searchByPhone(const string& number) 
    {
        for (const auto& record : records)
        {
            if (record.find(number) != string::npos) 
            {
                cout << record;
            }
        }
    }
    void searchByType(const string& type) {
        for (const auto& record : records)
        {
            if (record.find(type) != string::npos) 
            {
                cout << record;
            }
        }
    }
    void printAllRecords() 
    {
        for (const auto& record : records)
        {
            cout << record;
        }
    }
private:
    void loadFromFile(const string& filename) 
    {
        ifstream file(filename);
        if (file.is_open()) 
        {
            std::string line;
            while (getline(file, line))
            {
                records.push_back(line);
            }
            file.close();
        }
    }
    void saveToFile(const string& filename) 
    {
        std::ofstream file(filename);
        if (file.is_open())
        {
            for (const auto& record : records) 
            {
                file << record;
            }
            file.close();
        }
    }
};
int main() {
    Directory directory;

    directory.setCompanyName("ABC Corp");
    directory.setOwner("John Doe");
    directory.setPhone("123456789");
    directory.setAddress("Main St 123");
    directory.setTypeOfActivity("IT");
    directory.addRecord();

    directory.searchByName("ABC");
    directory.searchByOwner("Doe");
    directory.searchByPhone("123456789");
    directory.searchByType("IT");

    directory.printAllRecords();

}