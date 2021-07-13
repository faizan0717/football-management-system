#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <vector>
using namespace std;
void topBar()
{
    system("CLS");
    cout << "*************  Football Management *************" << endl;
    cout << "exit:11                                  back:22" << endl;
    cout << "************************************************" << endl;
    cout << endl
         << endl;
}
int urChoice()
{
    int temp;
    cout << endl
         << endl
         << endl
         << "************************************************" << endl
         << "Enter yout choice : ";
    cin >> temp;
    return temp;
}
int validatePassword(string uName, string uPass)
{
    vector<string> temp;
    string t = "";
    int id = 1;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("user.txt");
    while (!indata.eof())
    {
        if (flag == 1)
        {
            temp.push_back(to_string(id));
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
        }
        else
        {
            t = t + value;
        }
        indata >> value;
    }
    for (int i = 0; i < temp.size(); i += 4)
    {
        if (uName == temp[i + 1])
        {
            cout << temp[i + 1] << endl;
            if (uPass == temp[i + 2])
            {
                if (temp[i + 3] == "a")
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void exitMsg()
{
    cout << endl
         << endl;
    cout << "\tThanks for wisiting";
}
void addUsers()
{
    topBar();
    string name, pass, type;
    cout << "\tNew user name :";
    cin >> name;
    cout << "\tNew user Password :";
    cin >> pass;
    cout << "\tNew user type (a/o) :";
    cin >> type;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        ofstream file;
        file.open("user.txt", ios::app);
        if (!file.is_open())
        {
            cout << "File not found,press enter to continue\n";
            getch();
            return;
        }
        file << name << "/" << pass << "/" << type << "*" << endl;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void deleteUser()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("user.txt");
    cout << "ID\tName\t\tPassword\ttype" << endl;
    indata >> value;
    while (!indata.eof())
    {
        if (flag == 1)
        {
            cout << id << "\t";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\t\t";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl;
        }
        else
        {
            t = t + value;
            cout << value;
        }
        indata >> value;
    }

    indata.close();
    cout << endl
         << endl
         << "Enter the id you want to delete:";
    cin >> id;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        int flag = 0;
        ofstream file;
        int tc = 0;
        for (int i = 0; i < temp.size(); i += 3)
        {

            if (tc == id)
            {
                // cout << temp[i] << endl;
                //  cout << temp[i + 1] << endl;
                // cout << temp[i + 2] << endl;
                temp.erase(temp.begin() + i, temp.begin() + (i + 3));
                //    temp.erase(temp.begin() + (i));
                //    temp.erase(temp.begin() + (i + 1));
                flag = 1;
                break;
                //
            }
            tc++;
        }
        if (flag)
        {
            file.open("user.txt");
            if (!file.is_open())
            {
                cout << "File not found,press enter to continue\n";
                getch();
                return;
            }
            for (int i = 0; i < temp.size(); i += 3)
            {
                file << temp[i] << "/" << temp[i + 1] << "/" << temp[i + 2] << "*" << endl;
            }
        }
        else
        {
            cout << endl
                 << "element not fount,press enter to continue" << endl;
            getch();
            return;
        }
        return;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void deleteMatches()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("match.txt");
    cout << "id=";
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            cout << id << "\n";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\n";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl
                 << endl
                 << "id=";
        }
        else
        {
            t = t + value;
            cout << value;
        }
    }
    cout << "end of data";
    indata.close();
    cout << endl
         << endl
         << "Enter the match id you want to delete:";
    cin >> id;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        int flag = 0;
        ofstream file;
        int tc = 0;
        for (int i = 0; i < temp.size(); i += 5)
        {

            if (tc == id)
            {
                // cout << temp[i] << endl;
                //  cout << temp[i + 1] << endl;
                // cout << temp[i + 2] << endl;
                temp.erase(temp.begin() + i, temp.begin() + (i + 5));
                //    temp.erase(temp.begin() + (i));
                //    temp.erase(temp.begin() + (i + 1));
                flag = 1;
                break;
                //
            }
            tc++;
        }
        if (flag)
        {
            file.open("match.txt");
            if (!file.is_open())
            {
                cout << "File not found,press enter to continue\n";
                getch();
                return;
            }
            for (int i = 0; i < temp.size(); i += 5)
            {
                file << temp[i] << "/" << temp[i + 1] << "/" << temp[i + 2] << "/" << temp[i + 3] << "/" << temp[i + 4] << "*" << endl;
            }
        }
        else
        {
            cout << endl
                 << "element not fount,press enter to continue" << endl;
            getch();
            return;
        }
        return;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void addMatches()
{
    topBar();
    string team1, team2, date, team1Score, team2Score;
    cout << "\tEnter date (DD-MM-YYYY) :";
    cin >> date;
    cout << "\tTeam 1 name :";
    cin >> team1;
    cout << "\tTeam 2 name :";
    cin >> team2;
    cout << "\tTeam 1 score name :";
    cin >> team1Score;
    cout << "\tTeam 2 score name :";
    cin >> team2Score;
    cout << endl
         << "\t Do you want to save changes (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        ofstream file;
        file.open("match.txt", ios::app);
        if (!file.is_open())
        {
            cout << "File not found,press enter to continue\n";
            getch();
            return;
        }
        file << date << "/" << team1 << "/" << team2 << "/" << team1Score << "/" << team2Score << "*" << endl;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void editMatches()
{
    vector<string> temp;
    string t = "";
    topBar();
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("match.txt");
    cout << "id=";
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            cout << id << "\n";
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            cout << "\n";
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
            cout << endl
                 << endl
                 << "id=";
        }
        else
        {
            t = t + value;
            cout << value;
        }
    }
    cout << "end of data";
    indata.close();
    cout << endl
         << endl
         << "Enter the match id you want to edit:";
    cin >> id;
    string team1, team2, date, team1Score, team2Score;
    cout << endl
         << "\t Do you want to continue (1/0)";
    int choice;
    choice = urChoice();
    if (choice == 1)
    {
        int flag = 0;
        ofstream file;
        int tc = 0;
        for (int i = 0; i < temp.size(); i += 5)
        {

            if (tc == id)
            {
                cout << endl;
                cout << endl;
                cout << "\told date (DD-MM-YYYY) :" << temp[i] << endl;
                cout << "\tnew date (DD-MM-YYYY) :";
                cin >> temp[i];
                cout << endl;
                cout << "\told Team 1 name :" << temp[i + 1] << endl;
                cout << "\tnew Team 1 name :";
                cin >> temp[i + 1];
                cout << endl;
                cout << "\told Team 2 name :" << temp[i + 2] << endl;
                cout << "\tnew Team 2 name :";
                cin >> temp[i + 2];
                cout << endl;
                cout << "\told Team 1 score name :" << temp[i + 3] << endl;
                cout << "\tnew Team 1 score name :";
                cin >> temp[i + 3];
                cout << endl;
                cout << "\told Team 2 score name :" << temp[i + 4] << endl;
                cout << "\told Team 2 score name :";
                cin >> temp[i + 4];
                flag = 1;
                break;
            }
            tc++;
        }
        if (flag)
        {
            file.open("match.txt");
            if (!file.is_open())
            {
                cout << "File not found,press enter to continue\n";
                getch();
                return;
            }
            for (int i = 0; i < temp.size(); i += 5)
            {
                file << temp[i] << "/" << temp[i + 1] << "/" << temp[i + 2] << "/" << temp[i + 3] << "/" << temp[i + 4] << "*" << endl;
            }
            cout << "record sucessfully updated,press enter to continue";
            getch();
        }
        else
        {
            cout << endl
                 << "element not fount,press enter to continue" << endl;
            getch();
            return;
        }
        return;
        file.close();
    }
    else if (choice == 11)
    {
        exitMsg();
        exit(0);
    }
    else
    {
        return;
    }
}
void adminHome(string uName)
{
    int invalidChoice = 0, choice;
    while (true)
    {
        cout << "admmin";
        topBar();
        if (invalidChoice)
        {
            cout << "\tInvalid choice\n"
                 << endl;
            invalidChoice = 0;
        }
        cout << "       ==================================       " << endl
             << "         1.Add Matches" << endl
             << "         2.Delete Matches" << endl
             << "         3.Edit Matches" << endl
             << "         4.Add Users" << endl
             << "         5.Delete Users" << endl
             << "         6.logout" << endl
             << "       ==================================       " << endl;
        choice = urChoice();
        if (choice == 11)
        {
            exitMsg();
            exit(0);
        }
        if (choice == 22)
        {
            return;
        }
        switch (choice)
        {
        case 1:
            addMatches();
            break;
        case 2:
            deleteMatches();
            break;
        case 3:
            editMatches();
            break;
        case 4:
            addUsers();
            break;
        case 5:
            deleteUser();
            break;
        case 6:
            return;
            break;
        default:
            invalidChoice = 1;
            break;
        }
    }
}
void todaymatch()
{
    topBar();
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string today = "";
    today += to_string(ltm->tm_mday);
    today += "-";
    today += to_string(1 + ltm->tm_mon);
    today += "-";
    today += to_string(1900 + ltm->tm_year);
    cout << "date : " << today << endl;
    vector<string> temp;
    string t = "";
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("match.txt");
    cout << endl
         << endl;
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
        }
        else
        {
            t = t + value;
        }
    }
    indata.close();
    int choice;
    choice = 1;
    if (choice == 1)
    {
        ofstream file;
        for (int i = 0; i < temp.size(); i += 5)
        {

            if (temp[i] == today)
            {
                cout << endl;
                cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                cout << temp[i + 2] << " : " << temp[i + 4];
                cout << endl;
                //
            }
        }
        cout << endl
             << endl
             << "press enter to continue";
        getch();
        return;
        file.close();
    }
    return;
}
void prevmatch()
{
    topBar();
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month;
    int day;
    int year;
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
    vector<string> temp;
    string t = "";
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("match.txt");
    cout << endl
         << endl;
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
        }
        else
        {
            t = t + value;
        }
    }
    indata.close();
    int choice;
    choice = 1;
    if (choice == 1)
    {

        ofstream file;
        for (int i = 0; i < temp.size(); i += 5)
        {
            int tempyear = 0, tempmonth = 0, tempday = 0;
            int c = 1;
            string str = temp[i];
            int a = 0;
            while (str[a] != '\0')
            {
                //cout << str[a] << endl;
                if (str[a] == '-')
                {
                    c++;
                }
                else if (c == 1)
                {
                    string s1 = to_string(tempday);
                    char s2 = str[a];
                    string s = s1 + s2;
                    tempday = stoi(s);
                }
                else if (c == 2)
                {
                    string s1 = to_string(tempmonth);
                    char s2 = str[a];
                    string s = s1 + s2;
                    tempmonth = stoi(s);
                }
                else if (c == 3)
                {
                    string s1 = to_string(tempyear);
                    char s2 = str[a];
                    string s = s1 + s2;
                    tempyear = stoi(s);
                }
                a++;
            }
            if (tempyear < year)
            {
                cout << tempday << "-" << tempmonth << "-" << tempyear;
                cout << endl;
                cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                cout << temp[i + 2] << " : " << temp[i + 4];
                cout << endl
                     << endl;
            }
            else if (tempyear == year)
            {
                //cout << tempyear << "a" << year;
                if (tempmonth < month)
                {
                    cout << tempday << "-" << tempmonth << "-" << tempyear;
                    cout << endl;
                    cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                    cout << temp[i + 2] << " : " << temp[i + 4];
                    cout << endl
                         << endl;
                }
                else if (tempmonth == month)
                {
                    if (tempday < day)
                    {
                        cout << tempday << "-" << tempmonth << "-" << tempyear;
                        cout << endl;
                        cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                        cout << temp[i + 2] << " : " << temp[i + 4];
                        cout << endl
                             << endl;
                    }
                }
            }
        }
        cout << endl
             << endl
             << "press enter to continue";
        getch();
        return;
        file.close();
    }
    return;
}
void upmatch()
{
    topBar();
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int month;
    int day;
    int year;
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
    vector<string> temp;
    string t = "";
    int id = 0;
    int flag = 1;
    char value;
    ifstream indata;
    indata.open("match.txt");
    cout << endl
         << endl;
    while (true)
    {
        indata >> value;
        if (indata.eof())
            break;
        if (flag == 1)
        {
            flag = 0;
            t = "";
        }
        if (value == '/')
        {
            temp.push_back(t);
            t = "";
        }
        else if (value == '*')
        {
            flag = 1;
            id++;
            temp.push_back(t);
            t = "";
        }
        else
        {
            t = t + value;
        }
    }
    indata.close();
    int choice;
    choice = 1;
    if (choice == 1)
    {
        ofstream file;
        for (int i = 0; i < temp.size(); i += 5)
        {
            int tempyear = 0, tempmonth = 0, tempday = 0;
            int c = 1;
            string str = temp[i];
            int a = 0;
            while (str[a] != '\0')
            {
                //cout << str[a] << endl;
                if (str[a] == '-')
                {
                    c++;
                }
                else if (c == 1)
                {
                    string s1 = to_string(tempday);
                    char s2 = str[a];
                    string s = s1 + s2;
                    tempday = stoi(s);
                }
                else if (c == 2)
                {
                    string s1 = to_string(tempmonth);
                    char s2 = str[a];
                    string s = s1 + s2;
                    tempmonth = stoi(s);
                }
                else if (c == 3)
                {
                    string s1 = to_string(tempyear);
                    char s2 = str[a];
                    string s = s1 + s2;
                    tempyear = stoi(s);
                }
                a++;
            }
            if (tempyear > year)
            {
                cout << tempday << "-" << tempmonth << "-" << tempyear;
                cout << endl;
                cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                cout << temp[i + 2] << " : " << temp[i + 4];
                cout << endl
                     << endl;
            }
            else if (tempyear == year)
            {
                //cout << tempyear << "a" << year;
                if (tempmonth > month)
                {
                    cout << tempday << "-" << tempmonth << "-" << tempyear;
                    cout << endl;
                    cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                    cout << temp[i + 2] << " : " << temp[i + 4];
                    cout << endl
                         << endl;
                }
                else if (tempmonth == month)
                {
                    if (tempday > day)
                    {
                        cout << tempday << "-" << tempmonth << "-" << tempyear;
                        cout << endl;
                        cout << temp[i + 1] << " : " << temp[i + 3] << endl;
                        cout << temp[i + 2] << " : " << temp[i + 4];
                        cout << endl
                             << endl;
                    }
                }
            }
        }
        cout << endl
             << endl
             << "press enter to continue";
        getch();
        return;
        file.close();
    }
    return;
}
void homePage(string uName)
{
    int invalidChoice = 0, choice;
    while (true)
    {
        topBar();
        if (invalidChoice)
        {
            cout << "\tInvalid choice\n"
                 << endl;
            invalidChoice = 0;
        }
        cout << "       ==================================       " << endl
             << "         1.Todays Matches" << endl
             << "         2.Previous Matches" << endl
             << "         3.Upcomming Matches" << endl
             << "         4.logout" << endl
             << "       ==================================       " << endl;
        choice = urChoice();
        if (choice == 11)
        {
            exitMsg();
            exit(0);
        }
        if (choice == 22)
        {
            return;
        }
        switch (choice)
        {
        case 1:
            todaymatch();
            break;
        case 2:
            prevmatch();
            break;
        case 3:
            upmatch();
            break;
        case 4:
            return;
            break;
        default:
            invalidChoice = 1;
            break;
        }
    }
}
void loginPage()
{
    int invalidIndicator = 0;
    string uName, uPass;
    while (true)
    {
        topBar();
        if (invalidIndicator)
        {
            cout << "   Username or password is incorrect Try again" << endl;
            invalidIndicator = 0;
        }
        cout << "\tUser Name : ";
        cin >> uName;
        if (uName == "11")
        {
            exitMsg();
            exit(0);
        }
        cout << "\tUser Password : ";
        cin >> uPass;
        invalidIndicator = validatePassword(uName, uPass);
        if (invalidIndicator == 0)
        {
            invalidIndicator = 1;
            continue;
        }
        else if (invalidIndicator == 2)
        {
            invalidIndicator = 0;
            adminHome(uName);
        }
        else
        {
            invalidIndicator = 0;
            homePage(uName);
        }
    }
}
int main()
{
    loginPage();
}