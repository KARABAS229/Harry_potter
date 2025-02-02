﻿// Harry_potter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include<set>
#include<vector>
#include <algorithm>
#include <cctype>
#include <string>

void printset(const std::set<std::string>& s) {
    for (const auto& iter : s) {
        std::cout << " [" << iter << "]" << "\n";
    }
    
}

int main()
{
    std::vector<std::string> dictionary;
    std::set<std::string> dictionary_set;

    std::ifstream book("Harry.txt");
    if (!book.is_open()) {
        std::cout << "Error\n";
    }
    else {
        while (!book.eof()) {
            std::string tmp;
            book >> tmp;
            std::transform(tmp.begin(), tmp.end(), tmp.begin(),
                [](unsigned char c) { return std::tolower(c); });
            /*auto res = std::find(tmp.begin(), tmp.end(), "\n");
            if (res != tmp.end()) {
                tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end()); 
            }*/
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end()); // спорно, но как сделать так, чтобы всё чётко работало я не смог понять
            tmp.erase(std::remove(tmp.begin(), tmp.end(), ','), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '.'), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '\"'), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '?'), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '!'), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '('), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), ')'), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), ':'), tmp.end());
            tmp.erase(std::remove(tmp.begin(), tmp.end(), ';'), tmp.end());

            dictionary.push_back(tmp);
            dictionary_set.insert(tmp);
        }
    }
    book.close();

    /*for (auto& el : dictionary)
    {
        std::transform(el.begin(), el.end(), el.begin(),
            [](unsigned char c) { return std::tolower(c); });
        el.erase(std::remove(el.begin(), el.end(), ','), el.end());
        el.erase(std::remove(el.begin(), el.end(), '.'), el.end());
        el.erase(std::remove(el .begin(), el.end(), '\"'), el.end());
        el.erase(std::remove(el.begin(), el.end(), '?'), el.end());
        el.erase(std::remove(el.begin(), el.end(), '!'), el.end());
        el.erase(std::remove(el.begin(), el.end(), '('), el.end());
        el.erase(std::remove(el.begin(), el.end(), ')'), el.end());
        el.erase(std::remove(el.begin(), el.end(), ':'), el.end());
        el.erase(std::remove(el.begin(), el.end(), ';'), el.end());
    }*/
    
    std::stable_sort(dictionary.begin(), dictionary.end());
    std::vector<std::string>::iterator it;
    it = unique(dictionary.begin(), dictionary.end());
    dictionary.resize(distance(dictionary.begin(), it));


    /*for (int i = 0; i < dictionary.size(); i++) {
        auto res = std::find(dictionary.begin(),dictionary.end(), dictionary[i]);
        if (res != result.end()) {
            auto res2 = std::find(result.begin(), result.end(), dictionary[i]);
            if (res2 == dictionary.end()) {
                result.push_back(*res);
            }

        }
    }*/
    printset(dictionary_set);

    for (int i = 0; i < dictionary.size(); i++)
    {
        std::cout << dictionary[i] << ", "<<  "\n";
    }
}


