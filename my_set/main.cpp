#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <exception>

using namespace std;
vector<double> x(10);
vector<double> y(10);
vector<vector<double>> a(10);


class my_set {
public:
    vector<string> elements;
    string name;
//    vector
public:
    //конструкторы и деструкторы
    my_set(string nn, vector<string> your_elements) {
        name = nn;
        elements = your_elements;
//        cout << "set was made" << endl;
    }

    my_set(string nn) {
        name = nn;
//        cout << "set was made" << endl;
    }

    ~my_set() {

    }

    //методы и свойства множества
    void get_power() {
        cout << "power of set = " << elements.size() << endl;
    }

    void append(string new_element) {
        for (auto element : elements)
            if (element == new_element) {
                cerr << "this element is already in the set" << endl;
                return;
            }
        elements.push_back(new_element);
        cout << "element append successfully " << endl;
    }

    void my_delete(string element) {
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] == element) {
                elements.erase(elements.begin() + i);
                cout << "element deleted successfully " << endl;
                return;
            }
        cerr << "element wasn't deleted" << endl;
    }


    bool check_element_in_set(string element) {
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] == element) {
                cout << "yes" << endl;
                return (true);
            }
        cout << "no" << endl;
        return (false);
    }

//операции над множествами
    //    объединение
    my_set union_sets(my_set apending_set) {

        int i = 0;
        int j = 0;
        vector<string> ans;
        while ((i != elements.size()) && (j != apending_set.elements.size())) {
            if (elements[i] == apending_set.elements[j]) {
                ans.push_back(elements[i]);
                i++;
                j++;
            } else if (elements[i] > apending_set.elements[j]) {
                ans.push_back(apending_set.elements[j]);
                j++;
            } else if (elements[i] < apending_set.elements[j]) {
                ans.push_back(elements[i]);
                i++;
            }
        }
        for (; i != elements.size(); i++) {
            ans.push_back(elements[i]);
        }
        for (; j != apending_set.elements.size(); j++) {
            ans.push_back(apending_set.elements[j]);
        }

//                    sort(ans.begin(), ans.begin() + ans.size());
        for (auto apending_element : ans) {
            cout << apending_element << " ";
        }
        my_set answer("(" + name + "+" + apending_set.name + ")", ans);

        cout << endl << "union successfully" << endl;
        return (answer);
    }

    //    • пересечение
    my_set intersection_sets(my_set apending_set) {

        int i = 0;
        int j = 0;
        vector<string> ans;
        while ((i != elements.size()) && (j != apending_set.elements.size())) {
            if (elements[i] == apending_set.elements[j]) {
                ans.push_back(elements[i]);
                i++;
                j++;
            } else if (elements[i] > apending_set.elements[j]) {

                j++;
            } else if (elements[i] < apending_set.elements[j]) {
                i++;
            }
        }
//        sort(ans.begin(), ans.begin() + ans.size());
        for (auto element : ans) {
            cout << element << " ";
        }
        my_set answer("(" + name + "|_|" + apending_set.name + ")", ans);
        cout << endl << "intersection successfully" << endl;
        return (answer);
    }

//    • разность
    my_set difference_sets(my_set difference_set) {

        int i = 0;
        int j = 0;
        vector<string> ans;
        while ((i != elements.size()) && (j != difference_set.elements.size())) {
            if (elements[i] == difference_set.elements[j]) {

                i++;
                j++;
            } else if (elements[i] > difference_set.elements[j]) {
                j++;
            } else if (elements[i] < difference_set.elements[j]) {
                ans.push_back(elements[i]);
                i++;
            }
        }
        for (; i != elements.size(); i++) {
            ans.push_back(elements[i]);
        }
        for (auto element : ans) {
            cout << element << " ";
        }
        my_set answer("(" + name + "-" + difference_set.name + ")", ans);
        cout << endl << "difference  successfully" << endl;
        return (answer);

    }

//    • симметрическая разность
    my_set xor_sets(my_set xor_set) {

        int i = 0;
        int j = 0;
        vector<string> ans;
        while ((i != elements.size()) && (j != xor_set.elements.size())) {
            if (elements[i] == xor_set.elements[j]) {

                i++;
                j++;
            } else if (elements[i] > xor_set.elements[j]) {
                ans.push_back(xor_set.elements[j]);
                j++;
            } else if (elements[i] < xor_set.elements[j]) {
                ans.push_back(elements[i]);
                i++;
            }
        }
        for (; i != elements.size(); i++) {
            ans.push_back(elements[i]);
        }
        for (; j != xor_set.elements.size(); j++) {
            ans.push_back(xor_set.elements[j]);
        }
        for (auto element : ans) {
            cout << element << " ";
        }
        my_set answer("(" + name + "_xor_" + xor_set.name + ")", ans);
        cout << endl << "xor successfully" << endl;
        return (answer);

    }

//    • проверка включения
    void inclusion_chek_sets(my_set chek_set) {
        int i = 0;
        int j = 0;
        vector<string> ans;
        while ((i != elements.size()) && (j != chek_set.elements.size())) {
            if (elements[i] == chek_set.elements[j]) {
                i++;
                j++;
            } else if (elements[i] > chek_set.elements[j]) {
                j++;
            } else if (elements[i] < chek_set.elements[j]) {
                i++;
            }
        }
        if (j == chek_set.elements.size()) {
            cout << " YES my set inclusion chek set" << endl;
        } else
            cout << " NO my set don't  inclusion chek set" << endl;

        return;
    }

//    • просмотр элементов существующего множества
    void show_set() {
        sort(elements.begin(), elements.begin() + elements.size());
        for (auto element : elements) {
            cout << "\"" << element << "\"" << endl;
        }
    }
};

struct sets {
    vector<my_set> set;
};
sets my_sets;

//    просмотр списка существующих множеств
int choose_set() {
    for (int i = 0; i < my_sets.set.size(); i++)
        cout << "press  " << i << " to choose " << my_sets.set[i].name << endl;
    int ans;
    string x;
    getline(cin, x);
    ans = int(x[0] - '0');
//    cerr()
    if (ans >= 0 && ans < my_sets.set.size()) {
        return (ans);
    } else {
        cout << " error try again choose" << endl;
        return (choose_set());
    }
}

int main() {
    string test;
    vector<string> simple123 = {"1", "2", "3"};
    vector<string> simple345 = {"3", "4", "5"};
    int nomber=0;
    my_set ss("simple123", simple123);
    my_set second("simple345", simple345);
    my_sets.set.push_back(ss);
    my_sets.set.push_back(second);
//    getline(cin,test);
//    cout<<test<<endl;
    cout << "press 0 append new set " << endl <<

         "press 1 get power" << endl <<
         "press 2 append element" << endl <<
         "press 3 delete element " << endl <<
         "press 4 check element in set" << endl <<
         "press 5 union sets " << endl <<
         "press 6 intersection sets" << endl <<
         "press 7 difference sets" << endl <<
         "press 8 xor sets " << endl <<
         "press 9 show set" << endl <<
         "press 10 choose set" << endl <<
         "press 11 inclusion check set" << endl <<
         "press 12 delete set" << endl <<
         "press 13 to see help" << endl <<
         "press 33 exit " << endl;

    string c;
    cout<<endl<<endl<<"currently selected <simple123> =['1', '2', '3']";
    while (true) {
//        if (c==100){
//
//        }
        getline(cin, c);
        if (my_sets.set.size() == 0) {
            string s;
            cout << "your haven't sets, enter name of new set, or enter <stop_it> to exit" << endl;
            getline(cin, s);
            if (s == "stop_it")
                break;
            my_sets.set.emplace_back(s);
            ss = my_sets.set[0];
            cout << "append successfully" << endl;
        }
        if (c == "0") {
            string s;
            cout << "enter name of new set" << endl;
            getline(cin, s);
            my_sets.set.emplace_back(s);
            cout << "append successfully" << endl;
        }
        if (c == "1") {
            ss.get_power();
        }
        if (c == "2") {
            cout << "enter element to append" << endl;
            string s;
            getline(cin, s);
            bool flag = false;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '\"' or (int(s[j])<=64)) {
                    flag = true;
                    break;
                }
            }
            if (s.size() > 80)
                cout << "error element length >80" << endl;
            else if (flag)
                cout << "error wrong element like \" or russian letters " << endl;
            else
                ss.append(s);

        }
        if (c == "3") {
            string s;
            cout << "enter element to delete" << endl;
            getline(cin, s);
            ss.my_delete(s);
        }
        if (c == "4") {
            string s;
            cout << "enter element to chek in set" << endl;
            getline(cin, s);
            bool res = ss.check_element_in_set(s);
        }
        if (c == "5") {
            cout << "choose set" << endl;
            second = my_sets.set[choose_set()];
            my_sets.set.emplace_back(ss.union_sets(second));

        }
        if (c == "6") {
            cout << "choose set" << endl;
            second = my_sets.set[choose_set()];
            my_sets.set.emplace_back(ss.intersection_sets(second));
        }
        if (c == "7") {
            cout << "choose set" << endl;
            second = my_sets.set[choose_set()];
            my_sets.set.emplace_back(ss.difference_sets(second));
        }
        if (c == "8") {
            cout << "choose set" << endl;
            second = my_sets.set[choose_set()];
            my_sets.set.emplace_back(ss.xor_sets(second));
        }
        if (c == "9") {
            ss.show_set();
        }
        if (c == "10") {
            my_sets.set[nomber]=ss;
            nomber = choose_set();
            ss=my_sets.set[nomber];
        }
        if (c == "11") {
            cout << "choose set" << endl;
            second = my_sets.set[choose_set()];
            ss.inclusion_chek_sets(second);
        }
        if (c == "12") {
            cout << "choose set" << endl;
            second = my_sets.set[choose_set()];
            for (int i = 0; i < my_sets.set.size(); i++)
                if (second.elements == my_sets.set[i].elements && second.name == my_sets.set[i].name) {
                    my_sets.set.erase(my_sets.set.begin() + i);
                    cout << "set deleted successfully " << endl;
                    break;
                }
//            cerr << "element wasn't deleted" << endl;
//            my_sets.set;
        }
        if (c == "13") {
            cout << "0 append new set добавляет новое пустое множество в список множеств " << endl << endl <<

                 "1 get power показывает количество элементов в выбраном множестве  " << endl << endl <<
                 "2 append element добавляет элемент в выбранное множество" << endl << endl <<
                 "3 delete element удаляет элемент из выбраного множества" << endl << endl <<
                 "4 check element in set проверяет наличие элемента в выбранном множестве" << endl << endl <<
                 "5 union sets выводит объединение выбраного множества с любым на выбор а также добавляет новое множество с результатом операции"
                 << endl << endl <<
                 "6 intersection sets выводит пересечение выбраного множества с любым на выбор а также добавляет новое множество с результатом операции"
                 << endl << endl <<
                 "7 difference sets выводит разность выбраного множества с любым на выбор а также добавляет новое множество с результатом операции"
                 << endl << endl <<
                 "8 xor sets выводит симметрическую разность выбраного множества с любым на выбор а также добавляет новое множество с результатом операции"
                 << endl << endl <<
                 "9 show set показывает элементы выбранного множества" << endl << endl <<
                 "10 choose set меняем выбранное множество" << endl << endl <<
                 "11 inclusion chek set проверка включения в выбранное множество множества на выбор" << endl << endl <<
                 "12 delete set удаление множества на выбор (после удаления всех множеств можно только ввести новое или завершить программу)"
                 << endl << endl <<
                 "13 to see help открывает таблицу с пояснениями " << endl << endl <<
                 "33 exit завершает програму" << endl << endl <<
                 "P.S.: для удобства проверки операций над множествами уже добавленны два исходных <simple123> и <simple345 > изначально выбрано <simple123> =['1', '2', '3']"
                 << endl;
        }
        if (c == "33") {
            break;
        }

    }

//    getline(cin,s);

//    cout << s<<endl;
    return 0;
}
